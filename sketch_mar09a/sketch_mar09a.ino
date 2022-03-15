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
//스위치
#define SWITCH 22

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

  return distance;
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
  pinMode(SWITCH,INPUT_PULLUP);
}

int switching = 0;

void loop() {
  // 0 : R, 1 : F, 2 : L
  int right_distance = ultrasonic(TRIG_RIGHT, ECHO_RIGHT, 0);
  int front_distance = ultrasonic(TRIG_FRONT, ECHO_FRONT, 1);
  int left_distance = ultrasonic(TRIG_LEFT, ECHO_LEFT, 2);
  int look_distance = 8;
  
  if(front_distance<look_distance){
    Stop();
    if(right_distance>=look_distance && left_distance<look_distance){
      turnRight();
      Serial.println("turn_right");
      delay(1000);
    }
    else if(right_distance<look_distance && left_distance>=look_distance){
      Serial.println("turn_left");
      turnLeft();
      delay(1000);
    }
    else if(right_distance>=look_distance && left_distance>=look_distance){
      Serial.println("All OK");
      turnRight();
      delay(1000);
    }
    else{
      Serial.println("U-turn");
      turnRight();
      delay(1000);
    }
  }
  else{
    go();
    Serial.println("go");
    delay(1000);
  }
}
 
//모터A,B 정회전
void go()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A,B Stop
void Stop()
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
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A 정회전, 모터B 역회전
void turnRight()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}
