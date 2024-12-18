
const int motor_1 = 5;
const int motor_2 = 9;


//right forward --> arduino 5 motor 1
//left forward --> arduino 9 motor 4

void setup() {
  Serial.begin(9600);  // put your setup code here, to run once:
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  digitalWrite(motor_1, LOW);  
  digitalWrite(motor_2, LOW);   
}

void loop() {
  // put your main code here, to run repeatedly:
  //Front movement
  digitalWrite(motor_1, HIGH);  
  digitalWrite(motor_2, HIGH);   

  delay(3000);
  //Right Movement
  digitalWrite(motor_1, LOW);  
  digitalWrite(motor_2, HIGH);   
  delay(3000);
  //Left movement
  digitalWrite(motor_1, HIGH);  
  digitalWrite(motor_2, LOW);   
  delay(3000);
  //Stop Movement
  digitalWrite(motor_1, LOW);  
  digitalWrite(motor_2, LOW);   
  delay(3000);
  
}
