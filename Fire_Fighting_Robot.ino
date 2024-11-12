#include <Servo.h>

const int motor_1 = 4;
const int motor_2 = 5;
const int motor_3 = 6;
const int motor_4 = 7;

const int left_sensor = 8; 
const int middle_sensor = 9; 
const int right_sensor = 10; 
const int servo_pin = 11;
const int water_pump = 12;
int l1, c1, r1;

Servo myservo;
int pos = 0; 

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate

  pinMode(water_pump, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(motor_3, OUTPUT);
  pinMode(motor_4, OUTPUT);
  pinMode(left_sensor, INPUT);
  pinMode(middle_sensor, INPUT);
  pinMode(right_sensor, INPUT);
  
  myservo.write(90);    
  digitalWrite(motor_1, LOW);  
  digitalWrite(motor_2, LOW);   
  digitalWrite(motor_3, LOW);  
  digitalWrite(motor_4, LOW);
  digitalWrite(water_pump, HIGH); //Active-Low Logic for pump and Active-High for Motors
}

void loop() {
  l1 = digitalRead(left_sensor);
  c1 = digitalRead(middle_sensor);
  r1 = digitalRead(right_sensor);

  // Print sensor values to Serial Monitor
  Serial.print("Left Sensor: ");
  Serial.print(l1);
  Serial.print("\tMiddle Sensor: ");
  Serial.print(c1);
  Serial.print("\tRight Sensor: ");
  Serial.println(r1);
  
  delay(500);  // Delay to avoid spamming Serial Monitor

  // Rest of the main code here...
  
  if (c1 == HIGH) {
    // Fire detected in front
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, HIGH);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, HIGH);  
    delay(3000);
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, LOW); 
    delay(15);
    digitalWrite(water_pump, LOW);
    delay(15);  
    myservo.attach(servo_pin); 
    for(int j = 0 ; j < 4; j++) {
      for (pos = 90; pos <= 180; pos += 1) { 
        myservo.write(pos); 
        delay(15);
      }
      for (pos = 180; pos >= 90; pos -= 1) { 
        myservo.write(pos);
        delay(15);
      }
    }
    myservo.detach();
  }
  else if (l1 == HIGH) {
    // Fire detected to the left
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, HIGH);   
    digitalWrite(motor_3, HIGH);  
    digitalWrite(motor_4, LOW);  
    delay(2000);
    delay(15);
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, LOW);  
    delay(1000);
    digitalWrite(water_pump, LOW);
    delay(15);  
    myservo.attach(servo_pin); 
    for(int j = 0 ; j < 4; j++) {
      for (pos = 90; pos <= 180; pos += 1) { 
        myservo.write(pos); 
        delay(15);
      }
      for (pos = 180; pos >= 90; pos -= 1) { 
        myservo.write(pos); 
        delay(15);
      }
    }
    myservo.detach();
  }
  else if (r1 == HIGH) {
    // Fire detected to the right
    digitalWrite(motor_1, HIGH);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, HIGH);  
    delay(2000);
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, LOW);  
    delay(1000);
    delay(15);
    digitalWrite(water_pump, LOW);
    delay(15);  
    myservo.attach(servo_pin); 
    for(int j = 0 ; j < 4; j++) {
      for (pos = 90; pos <= 180; pos += 1) { 
        myservo.write(pos); 
        delay(15);
      }
      for (pos = 180; pos >= 90; pos -= 1) { 
        myservo.write(pos); 
        delay(15);
      }
    }
    myservo.detach();
  }
  
  // Ensure motors and pump are off when no fire is detected
  digitalWrite(motor_1, LOW);  
  digitalWrite(motor_2, LOW);   
  digitalWrite(motor_3, LOW);  
  digitalWrite(motor_4, LOW);
  digitalWrite(water_pump, HIGH);  
}
