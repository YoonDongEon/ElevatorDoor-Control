#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Stepper.h>
#include <LiquidCrystal.h> //lcd관련 헤더

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define trigPin 4 // trigPin을 4로 설정
#define echoPin 5 // echoPin을 5로 설정
int RX=3;
int TX=2;
int stepsmotor = 830;
int motorNum1,motorNum2,sensorNum1,sensorNum2;
int count1=0;
int count2=0;
int count3=0;
int count4=0;
int count5=0;

SoftwareSerial BTSerial(RX, TX); // (RX, TX)
Stepper myStepper(stepsmotor, 8, 10, 9, 11);

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
  Serial.println("START\n");
  myStepper.setSpeed(30);
  lcd.begin();
  lcd.backlight();
  pinMode(trigPin, OUTPUT); // Sensor Trig Pin
  pinMode(echoPin, INPUT);  // Sensor Echo Pin
}

void loop() {
  if(BTSerial.available()) {
  char cmd =(char)BTSerial.read();
    Serial.write(BTSerial.read());
    if(cmd=='1'){
      stepsmotor = 830;
      lcd.setCursor(0, 0);
      lcd.println("<A Door Opens>!!");
      lcd.setCursor(0, 1);
      lcd.println("SmartButton Open");
      for(motorNum1=0;motorNum1<2;motorNum1++){     
        myStepper.step(-stepsmotor);
      }
        if(motorNum1==2)
        {
          stepsmotor = 850;
          delay(3000);
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.println("<A Door Closes>!");
          lcd.setCursor(0, 1);
          lcd.println("SmartButton Exit");
          for(motorNum2=2;motorNum2>0;motorNum2--){
          myStepper.step(stepsmotor);
          }
        }
             if(motorNum1==2 && motorNum2==0){
             delay(1000);
             lcd.clear();      // LCD를 모두 지운다.
        }
      }
      else if(cmd=='2'){
        stepsmotor = 1660;
        lcd.setCursor(0, 0);
        lcd.println("<A Door Opens>!!");
        lcd.setCursor(0, 1);
        lcd.println("SmartButton Open");
        myStepper.step(-stepsmotor);
        delay(3000);
        myStepper.step(830);
        delay(5000);
        myStepper.step(830);
      }
  }
  if(Serial.available()){
  BTSerial.write(Serial.read());
  }
  digitalWrite(trigPin, HIGH);  // 센서에 Trig 신호 입력
  delayMicroseconds(10);        // 10us 정도 유지
  digitalWrite(trigPin, LOW);   // Trig 신호 off
 
  long duration = pulseIn(echoPin, HIGH);// Echo pin: HIGH->Low 간격을 측정
  long distance = duration / 29 / 2;     // 거리(cm)로 변환
  char buf[20];
  
  if(distance==6&&count1==0)
  {
      delay(5500);
      stepsmotor = 830;
      lcd.setCursor(0, 0);
      lcd.println("<A Door Opens>!!");
      snprintf(buf, sizeof(buf), "-Distance : %dcm", distance);
      lcd.setCursor(0, 1);
      lcd.println(buf);
      for(sensorNum1=0;sensorNum1<2;sensorNum1++){     
        myStepper.step(-stepsmotor);
      }
        if(sensorNum1==2)
        {
          lcd.clear();
          delay(4000);
          lcd.setCursor(0, 0);
          lcd.println("<A Door Closes>!");
          snprintf(buf, sizeof(buf), "-Distance : %dcm ", distance);
          lcd.setCursor(0, 1);
          lcd.println(buf);
          stepsmotor = 850;
          for(sensorNum2=sensorNum1;sensorNum2>0;sensorNum2--){
          myStepper.step(stepsmotor);
          }
        }
        if(sensorNum1==2 && sensorNum2==0){
             delay(700);
             lcd.clear();      // LCD를 모두 지운다.
        }
        count1=1;
  }
  else if(distance==17&&count2==0)
  {
      delay(4700);
      stepsmotor = 830;
      lcd.setCursor(0, 0);
      lcd.println("<A Door Opens>!!");
      snprintf(buf, sizeof(buf), "-Distance : %dcm", distance);
      lcd.setCursor(0, 1);
      lcd.println(buf);
      for(sensorNum1=0;sensorNum1<2;sensorNum1++){     
        myStepper.step(-stepsmotor);
      }
        if(sensorNum1==2)
        {
          lcd.clear();
          delay(3500);
          lcd.setCursor(0, 0);
          lcd.println("<A Door Closes>!");
          snprintf(buf, sizeof(buf), "-Distance : %dcm ", distance);
          lcd.setCursor(0, 1);
          lcd.println(buf);
          stepsmotor = 850;
          for(sensorNum2=sensorNum1;sensorNum2>0;sensorNum2--){
          myStepper.step(stepsmotor);
          }
        }
        if(sensorNum1==2 && sensorNum2==0){
             delay(700);
             lcd.clear();      // LCD를 모두 지운다.
        }
        count2=1;
  }
  else if(distance==32&&count3==0)
  {
      delay(4700);
      stepsmotor = 830;
      lcd.setCursor(0, 0);
      lcd.println("<A Door Opens>!!");
      snprintf(buf, sizeof(buf), "-Distance : %dcm", distance);
      lcd.setCursor(0, 1);
      lcd.println(buf);
      for(sensorNum1=0;sensorNum1<2;sensorNum1++){     
        myStepper.step(-stepsmotor);
      }
        if(sensorNum1==2)
        {
          lcd.clear();
          delay(3500);
          lcd.setCursor(0, 0);
          lcd.println("<A Door Closes>!");
          snprintf(buf, sizeof(buf), "-Distance : %dcm ", distance);
          lcd.setCursor(0, 1);
          lcd.println(buf);
          stepsmotor = 850;
          for(sensorNum2=sensorNum1;sensorNum2>0;sensorNum2--){
          myStepper.step(stepsmotor);
          }
        }
        if(sensorNum1==2 && sensorNum2==0){
             delay(700);
             lcd.clear();      // LCD를 모두 지운다.
        }
        count3=1;
  }
  else if(distance==45&&count4==0)
  {
      delay(4700);
      stepsmotor = 830;
      lcd.setCursor(0, 0);
      lcd.println("<A Door Opens>!!");
      snprintf(buf, sizeof(buf), "-Distance : %dcm", distance);
      lcd.setCursor(0, 1);
      lcd.println(buf);
      for(sensorNum1=0;sensorNum1<2;sensorNum1++){     
        myStepper.step(-stepsmotor);
      }
        if(sensorNum1==2)
        {
          lcd.clear();
          delay(3500);
          lcd.setCursor(0, 0);
          lcd.println("<A Door Closes>!");
          snprintf(buf, sizeof(buf), "-Distance : %dcm ", distance);
          lcd.setCursor(0, 1);
          lcd.println(buf);
          stepsmotor = 850;
          for(sensorNum2=sensorNum1;sensorNum2>0;sensorNum2--){
          myStepper.step(stepsmotor);
          }
        }
        if(sensorNum1==2 && sensorNum2==0){
             delay(700);
             lcd.clear();      // LCD를 모두 지운다.
        }
        count4=1;
  }
  else if(distance==76&&count5==0)
  {
      delay(4700);
      stepsmotor = 830;
      lcd.setCursor(0, 0);
      lcd.println("<A Door Opens>!!");
      snprintf(buf, sizeof(buf), "-Distance : %dcm", distance);
      lcd.setCursor(0, 1);
      lcd.println(buf);
      for(sensorNum1=0;sensorNum1<2;sensorNum1++){     
        myStepper.step(-stepsmotor);
      }
        if(sensorNum1==2)
        {
          lcd.clear();
          delay(3500);
          lcd.setCursor(0, 0);
          lcd.println("<A Door Closes>!");
          snprintf(buf, sizeof(buf), "- Distance : %dcm ", distance);
          lcd.setCursor(0, 1);
          lcd.println(buf);
          stepsmotor = 850;
          for(sensorNum2=sensorNum1;sensorNum2>0;sensorNum2--){
          myStepper.step(stepsmotor);
          }
        }
        if(sensorNum1==2 && sensorNum2==0){
             delay(700);
             lcd.clear();      // LCD를 모두 지운다.
        }
        count5=1;
  }
  else
  {
    
  }

  Serial.print(distance);
  Serial.print("cm ");
  Serial.print("count1=");
  Serial.print(count1);
  Serial.print(", count2=");
  Serial.print(count2);
  Serial.print(", count3=");
  Serial.print(count3);
  Serial.print(", count4=");
  Serial.print(count4);
  Serial.print(", count5=");
  Serial.println(count5);
  delay(300);
  }
