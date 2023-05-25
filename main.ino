
//Included Libraries

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);



#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  A2

#define Ap 3  // A+ line
#define An 2  // A- line
#define Bp 1   //  .
#define Bn 0   //  .

void setup() {
  // put your setup code here, to run once:
  pinMode(VERT_PIN, INPUT);
  pinMode(HORZ_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);
  
  pinMode(Ap, OUTPUT);
  pinMode(An, OUTPUT);
  pinMode(Bp, OUTPUT);
  pinMode(Bn, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Hello, Wokwi!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int vert = analogRead(VERT_PIN);
  int horz = analogRead(HORZ_PIN);
  bool selPressed = digitalRead(SEL_PIN) == LOW;

  vert = map(vert, 0, 1023, -100, 100);
  horz = map(horz, 0, 1023, 100, -100);
  analogWrite(HORZ_PIN,horz);
  analogWrite(VERT_PIN,vert);

  

  if (vert > 0 || horz > 0) {
    digitalWrite(Ap,LOW) ;  digitalWrite(Bn,HIGH);
    delay(5);
    
    digitalWrite(Bn,LOW) ;  digitalWrite(An,HIGH);
    delay(5);
    
    digitalWrite(An,LOW) ;  digitalWrite(Bp,HIGH);
    delay(5);
    
    digitalWrite(Bp,LOW) ;  digitalWrite(Ap,HIGH);
    delay(5);
  } else if (horz < 0 || vert < 0) {
    digitalWrite(Ap,LOW) ;  digitalWrite(Bp,HIGH);
    delay(5);
    digitalWrite(Bp,LOW) ;  digitalWrite(An,HIGH);
    delay(5);
    digitalWrite(An,LOW) ;  digitalWrite(Bn,HIGH);
    delay(5);
    digitalWrite(Bn,LOW) ;  digitalWrite(Ap,HIGH);
    delay(5);
  }



  lcd.setCursor(7, 1);
  lcd.print(vert);

  lcd.setCursor(7, 2);
  lcd.print(horz);
  lcd.setCursor(8, 3);
  lcd.print(selPressed);


  if (digitalRead(SEL_PIN) == LOW){
    lcd.setCursor(7,2);
    lcd.print("pudim");
  }
}
