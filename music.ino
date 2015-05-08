/*
宮、商、角、徵、羽
do, re, mi, so, la
 1 , 2 , 3 , 5 , 6
低261,293,329,391,440
中523,587,659,783,880
高1046,1174,1318,1567,1760
*/
int motorspeed = A0;//馬達調速器
int sensor[] = {A1,A2,A3,A4,A5};//紅外線感應器
int led[] = {3,4,5,6,7};//LED
int speaker = 11;//喇叭
int motor = 10;//馬達
int val[]={1,2,3,4,5};//紅外線感應器值
int base=30;//基礎值
int time=10;

void setup() 
{
 Serial.begin(9600);
 for(int x=0;x<5;x++)
 {
   pinMode(led[x],OUTPUT);
 } 
 pinMode(speaker,OUTPUT);
 pinMode(motor,OUTPUT);
}

void loop() 
{
 for(int pin=0;pin<5;pin++)
 {
  val[pin]=analogRead(sensor[pin]);//讀值
  Serial.print("sensor");
  Serial.print((pin+1));
  Serial.print("=");
  Serial.println(val[pin]);
  delay(100);
  if(val[pin]>base)//sensor讀值大於基礎值時執行
  {
   switch(pin)
   {
    case 0:
     analogWrite(speaker,261);//宮
     digitalWrite(led[pin],HIGH);
     delay(time);
     Serial.println("LED0");
     break;
    case 1:
     analogWrite(speaker,293);//商
     digitalWrite(led[pin],HIGH);
     delay(time);
     Serial.println("LED1");
     break;
    case 2:
     analogWrite(speaker,329);//角
     digitalWrite(led[pin],HIGH);
     delay(time);
     Serial.println("LED2");
     break;
    case 3:
     analogWrite(speaker,391);//徵
     digitalWrite(led[pin],HIGH);
     delay(time);
     Serial.println("LED3");
     break;
    case 4:
     analogWrite(speaker,440);//羽
     digitalWrite(led[pin],HIGH);
     delay(time);
     Serial.println("LED4");
     break;
    default:
     digitalWrite(led[pin],LOW);
   }
  }
 }
 
/*馬達調速*/
 int speedval=analogRead(motorspeed);
 analogWrite(motor,map(speedval,0,1023,0,255));
}
