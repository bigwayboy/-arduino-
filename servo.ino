#include <Servo.h>

Servo myservo6;  // 定义Servo对象来控制
Servo myservo7;  // 定义Servo对象来控制
Servo myservo8;  // 定义Servo对象来控制
Servo myservo9;  // 定义Servo对象来控制
int pos6 = 90;    // 角度存储变量
int pos7 = 90;    // 角度存储变量
int pos8 = 90;    // 角度存储变量
int pos9 = 90;    // 角度存储变量
int a1=31;
int a2=30;
int speedpin=12;
int Speed=50;
int serialData;
void setup() {
  Serial.begin(9600);//波特率
  Serial1.begin(9600);//波特率
  myservo9.attach(9);  // 控制线连接数字9
  myservo8.attach(8);  // 控制线连接数字9
  myservo7.attach(7);  // 控制线连接数字9
  myservo6.attach(6);  // 控制线连接数字9
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.print("启动");
}

void loop() {
  if( Serial1.available()>0 ){ 
    
    serialData =  Serial1.read();   
    
    if (serialData == '2' ) {  //接收到点亮LED指令
        digitalWrite(a1,HIGH);
        digitalWrite(a2,LOW);
        normal();
        accelerate();
    }
    if (serialData == '4' ) {  //接收到点亮LED指令
        lift();
    }
    if (serialData == '6' ) {  //接收到点亮LED指令
        right();
    }
    if (serialData == '8' ) {  //接收到点亮LED指令
        normal();
        slow();
    }
    if (serialData == '1' ) {  //接收到点亮LED指令
        up();
    }
    if (serialData == '7' ) {  //接收到点亮LED指令
        down();
    }
    if (serialData == '5' ) {  //接收到点亮LED指令
        normal();
        Stop();
    }
    if (serialData == '0' ) {  //接收到点亮LED指令
        Stop();delay(1000);
        digitalWrite(a1,LOW);
        digitalWrite(a2,HIGH);
        analogWrite(speedpin,Speed);  
    }
  }   
}
void normal(){
      pos6=90;pos7=90;pos8=90;pos9=90;
      myservo6.write(pos6);              // 舵机角度写入
      delay(2);                       // 等待转动到指定角度
      myservo7.write(pos7);              // 舵机角度写入
      delay(2);                       // 等待转动到指定角度
      myservo8.write(pos8);              // 舵机角度写入
      delay(2);                       // 等待转动到指定角度
      myservo9.write(pos9);              // 舵机角度写入
      delay(2); 
  }
void lift(){
      pos8++;pos9--;
      if(pos8>178){pos8=178;}
      if(pos9<1){pos9=1;}
      myservo8.write(pos8);              // 舵机角度写入
      delay(2);
      myservo9.write(pos9);              // 舵机角度写入
      delay(20);
  }
void right(){
      pos9++;pos8--;
      if(pos9>178){pos9=178;}
      if(pos8<1){pos8=1;}
      myservo8.write(pos8);              // 舵机角度写入
      delay(2);
      myservo9.write(pos9);              // 舵机角度写入
      delay(20);
  }
void up(){
      pos6--;pos7++;
      if(pos6<1){pos6=1;}
      if(pos7>179){pos7=179;}
      myservo6.write(pos6);              // 舵机角度写入
      delay(2);
      myservo7.write(pos7);              // 舵机角度写入
      delay(20);
  }
void down(){
      pos6++;pos7--;
      if(pos6>178){pos6=178;}
      if(pos7<1){pos7=1;}
      myservo6.write(pos6);              // 舵机角度写入
      delay(2);
      myservo7.write(pos7);              // 舵机角度写入
      delay(20);
  }
void accelerate(){
  analogWrite(speedpin,Speed);
  Speed++;
  delay(20);
  }
void slow(){
  analogWrite(speedpin,Speed);
  Speed--;
  delay(20);
  }
void Stop(){
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);
  }
