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
int time=100;

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
 for(int pin=0;pin<1;pin++)
 {
  for(int i=0;i<10;i++)//抓10次平均
  {
    val[pin]=analogRead(sensor[pin]);//讀值
    val[pin]=val[pin]/i;
  }
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
     digitalWrite(led[pin],HIGH);
     tone(speaker,523);//宮523
     delay(time);
     noTone(speaker);
     delay(time/5);
     break;
    case 1:
     digitalWrite(led[pin],HIGH);
     tone(speaker,587);//商587
     delay(time);
     noTone(speaker);
     delay(time/5);
     break;
    case 2:
     digitalWrite(led[pin],HIGH);
     tone(speaker,659);//角659
     delay(time);
     noTone(speaker);
     delay(time/5);     
     break;
    case 3:
     digitalWrite(led[pin],HIGH);
     tone(speaker,1567);//徵1567
     delay(time);
     noTone(speaker);
     delay(time/5);     
     break;
    case 4:
     digitalWrite(led[pin],HIGH);
     tone(speaker,1760);//羽1760
     delay(time);
     noTone(speaker);
     delay(time/5);     
     break;
    default:
     digitalWrite(led[pin],LOW);
     noTone(speaker);
   }
  }
  else
  {
    digitalWrite(led[pin],LOW);
  }
 }
 
/*馬達調速*/
 int speedval=analogRead(motorspeed);
 analogWrite(motor,map(speedval,0,1023,0,255));
}
