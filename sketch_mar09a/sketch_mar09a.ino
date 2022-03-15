//모터A 컨트롤
int IN1=7;
int IN2=6;
//모터B 컨트롤
int IN3=5;
int IN4=4;
//초음파 센서
#define TRIG_RIGHT 8
#define ECHO_RIGHT 9
#define TRIG_FRONT 12
#define ECHO_FRONT 13
#define TRIG_LEFT 10
#define ECHO_LEFT 11

int ultrasonic(int a, int b, int c){
  long duration,distance;

  digitalWrite(a,LOW);
  delayMicroseconds(2);
  digitalWrite(a,HIGH);
  delayMicroseconds(10);
  digitalWrite(a,LOW);

  duration=pulseIn(b,HIGH);
  distance=duration*17/1000;
  if(c==2)
    Serial.print("\nLeft Distance:");
  else if(c==0)
    Serial.print("\nRight Distance:");
  else if(c==1)
    Serial.print("\nFront Distance:");
  Serial.print(distance);
  Serial.println(" Cm");
}
 
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_LEFT,OUTPUT);
  pinMode(ECHO_LEFT,INPUT);
  pinMode(TRIG_FRONT,OUTPUT);
  pinMode(ECHO_FRONT,INPUT);
  pinMode(TRIG_RIGHT,OUTPUT);
  pinMode(ECHO_RIGHT,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  // 0 : R, 1 : F, 2 : L
  ultrasonic(TRIG_RIGHT, ECHO_RIGHT, 0);
  ultrasonic(TRIG_FRONT, ECHO_FRONT, 1);
  ultrasonic(TRIG_LEFT, ECHO_LEFT, 2);
  
  bothMotorStart();
}
 
//모터A,B 정회전
void bothMotorStart()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A,B Stop
void stopAllMotor()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A 역회전, 모터B 정회전
void turnLeft()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A 정회전, 모터B 역회전
void turnRight()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}
 
//모터A 정회전, 모터B Stop
void motorA_Rotation()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A Stop, 모터B 정회전
void motorB_Rotation()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A 역회전, 모터B Stop
void motorA_Reverse()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A Stop, 모터B 역회전
void motorB_Reverse()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}
