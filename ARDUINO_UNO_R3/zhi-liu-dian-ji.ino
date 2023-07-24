/**
 * 直流电机电风扇实验
 * 分四档 0档-停止 1档-150转 2档-200转 3档-250转
 * 使用按钮控制档位的变化,按一次按钮加一档,加到4档时归0,
 * 如此循环
 */

const int buttonPin = 2; // 按钮状态输入引脚 只有两个值 按下:1-HIGH,松开0-LOW
const int ledPin = 13;
const int motorIn1 = 9; // 电机信号输出引脚1-电机驱动引脚IN2
const int motorIn2 = 10;// 电机信号输出引脚2-电机驱动引脚IN3

#define rank1 150
#define rank2 200
#define rank3 250

int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
int stat = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 从按钮读取值,一般是按下时为1(HIGH),释放时为0(LOG)
  // 但如果按钮的正负极接反,就会相反
  int reading = digitalRead(buttonPin); 

  // 如果本次读取的按钮值与上一次读取的不一样,则记录状态变化的时间
  if(reading != lastButtonState){
    lastDebounceTime = millis();
  }

  // 本次循环的时间 - 上次状态变化的时间 > 50
  // 如果是按钮状态变化的那一次循环,是不会进入这个if的,因为这个相减的结果不会 > 50
  // 大概率是循环多次后才会符合这个条件,因为循环很快(整个loop没有delay),
  // 所以以人按按钮的灵敏度来说,按下按钮的时间已经够程序循环几十甚至上百次了
  // 所以在按下按钮这个时间内基本都会有一次循环是会进入这个if里的
  if(millis() - lastDebounceTime > debounceDelay){
    // 本次读取的按钮值与上次记录的按钮状态不一致时才进入这个判断
    // 比如第一交按下按钮时 读取到的值reading=1 而 buttonState初始值是0
    // 所以会进入这个if,而且把buttonState变=1, 一松开按钮又会进入这个if
    // 并且把buttonState变为0
    if(reading != buttonState){ 
      buttonState = reading;
      if(buttonState == HIGH){
        stat = stat + 1;
        Serial.print("stat:");
        Serial.println(stat);
        digitalWrite(ledPin, HIGH);
        if(stat > 3){
          stat = 0;
        }
      } else {
        digitalWrite(ledPin, LOW);
      }
    }  
  }
  lastButtonState = reading;

  switch(stat){
   case 1:
    clockwise(rank1);
    break;
   case 2:
    clockwise(rank2);
    break; 
   case 3:
    clockwise(rank3);
    break;
   default:
     clockwise(0);
  }
}

void clockwise(int Speed) {
//  Serial.println(Speed);
  analogWrite(motorIn1, 0);
  analogWrite(motorIn2, Speed);
}
