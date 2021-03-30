#include <Wire.h>

#include <LiquidCrystal_I2C.h>

const int BUTTON_PIN = 7;

int S = 59; // count seconds
int M = 24; // count minutes
int fiveS = 59;
int fiveM = 4;
int fifteenS = 59;
int fifteenM = 14;
int cycle = 1;
int lastState = HIGH; // the previous state from the input pin
int currentState;    // the current reading from the input pin

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void pomodoro() {
  lcd.setCursor(4, 0);
  lcd.print ("Pomodoro");
  lcd.setCursor(7, 1);
  lcd.print(":");
  
  S--;
  delay(1000);

  if (S < 0)
  {
    M--;
    S = 59;
  }


  if (M > 9)
  {
    lcd.setCursor(5, 1);
    lcd.print(M);
  }
  else
  {
    lcd.setCursor(5, 1);
    lcd.print("0");
    lcd.setCursor(6, 1);
    lcd.print(M);
    lcd.setCursor(7, 1);
    lcd.print(":");
  }

  if (S > 9)
  {
    lcd.setCursor(8, 1);
    lcd.print(S);
  }
  else
  {
    lcd.setCursor(8, 1);
    lcd.print("0");
    lcd.setCursor(9, 1);
    lcd.print(S);
    lcd.setCursor(10, 1);
    lcd.print(" ");
  }


  if (M < 9)
  {
    lcd.setCursor(6, 1);
    lcd.print(M);

  }
}

void fiveMinutes() {

  lcd.setCursor(2, 0);
  lcd.print("Short Break!");
  lcd.setCursor(7, 1);
  lcd.print(":");

  fiveS--;
  delay(1000);

  if (fiveS < 0)
  {
    fiveM--;
    fiveS = 59;
  }


  if (fiveM > 9)
  {
    lcd.setCursor(5, 1);
    lcd.print(fiveM);
  }
  else
  {
    lcd.setCursor(5, 1);
    lcd.print("0");
    lcd.setCursor(6, 1);
    lcd.print(fiveM);
    lcd.setCursor(7, 1);
    lcd.print(":");
  }

  if (fiveS > 9)
  {
    lcd.setCursor(8, 1);
    lcd.print(fiveS);
  }
  else
  {
    lcd.setCursor(8, 1);
    lcd.print("0");
    lcd.setCursor(9, 1);
    lcd.print(fiveS);
    lcd.setCursor(10, 1);
    lcd.print(" ");
  }

  if (fiveM < 9)
  {
    lcd.setCursor(6, 1);
    lcd.print(fiveM);
  }
}

void fifteenMinutes() {
  lcd.setCursor(2, 0);
  lcd.print("Long Break!");
  lcd.setCursor(7, 1);
  lcd.print(":");

  fifteenS--;
  delay(1000);

  if (fifteenS < 0)
  {
    fifteenM--;
    fifteenS = 59;
  }


  if (fifteenM > 9)
  {
    lcd.setCursor(5, 1);
    lcd.print(fifteenM);
  }
  else
  {
    lcd.setCursor(5, 1);
    lcd.print("0");
    lcd.setCursor(6, 1);
    lcd.print(fifteenM);
    lcd.setCursor(7, 1);
    lcd.print(":");
  }

  if (fifteenS > 9)
  {
    lcd.setCursor(8, 1);
    lcd.print(fifteenS);
  }
  else
  {
    lcd.setCursor(8, 1);
    lcd.print("0");
    lcd.setCursor(9, 1);
    lcd.print(fifteenS);
    lcd.setCursor(10, 1);
    lcd.print(" ");
  }

  if (fifteenM < 9)
  {
    lcd.setCursor(6, 1);
    lcd.print(fifteenM);
  }
}


void loop() {
  currentState = digitalRead(BUTTON_PIN);
  
  
  if(lastState == LOW && currentState == HIGH) {
    Serial.println("The state changed from LOW to HIGH");
    lcd.clear();
    cycle+=1;
  }

  if (cycle == 1){
    pomodoro();
  }
  else if (cycle == 2){
    fiveMinutes();
  }
  else if(cycle == 3){
    fifteenMinutes();
  }
  else {
    cycle=1;
    }
  lastState = currentState;


  
}
