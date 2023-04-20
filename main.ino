
//Included Libraries

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);



#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  2

#define Ap 3  // A+ line
#define An 2  // A- line
#define Bp 1   //  .
#define Bn 0   //  .

void setup() {
  // put your setup code here, to run once:
  pinMode(VERT_PIN, INPUT);
  pinMode(HORZ_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);

  pinMode(Ap, OUTPUT)
  pinMode(An, OUTPUT)
  pinMode(Bp, OUTPUT)
  pinMode(Bn, OUTPUT)

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

  lcd.setCursor(7, 1);
  lcd.print(vert);

  lcd.setCursor(7, 2);
  lcd.print(horz);
}
