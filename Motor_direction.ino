const int motor_1 =4;
const int motor_2 =5;
const int motor_3 =6;
const int motor_4 =7;


void setup() {
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(motor_3, OUTPUT);
  pinMode(motor_4, OUTPUT);
  digitalWrite(motor_1, LOW);  
  digitalWrite(motor_2, LOW);   
  digitalWrite(motor_3, LOW);  
  digitalWrite(motor_4, LOW);
}
void loop() {

    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, HIGH);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, HIGH);  
    delay(3000);
    digitalWrite(motor_1, LOW);  
    digitalWrite(motor_2, HIGH);   
    digitalWrite(motor_3, HIGH);  
    digitalWrite(motor_4, LOW);  
    delay(3000);
    digitalWrite(motor_1, HIGH);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, LOW);  
    digitalWrite(motor_4, HIGH);  
    delay(3000);
    digitalWrite(motor_1, HIGH);  
    digitalWrite(motor_2, LOW);   
    digitalWrite(motor_3, HIGH);  
    digitalWrite(motor_4, LOW);   
    delay(3000);
}
