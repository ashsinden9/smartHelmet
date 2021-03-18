#include<LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
int buzzer=2;
int relay=8;
int RxPin1=6;
int RxPinState1=0;
int k=0,j;
void setup()
{

 pinMode(RxPin1,INPUT);
 pinMode(relay,OUTPUT);
 pinMode(buzzer,OUTPUT);
 lcd.begin(16,2);
 for(int i=0;i<10;i++)
{
 lcd.setCursor(0, 0);
 lcd.print(" ****BIKER****");
 lcd.setCursor(0, 1);
 lcd.print(" SAFETY SYSTEM ");
 delay(500);
}
}
void loop()
{
RxPinState1=digitalRead(RxPin1);

if(RxPinState1== LOW && k==0)
 {
 lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("              ");
  lcd.setCursor(0, 1);
  lcd.print("-->PLEASE WEAR HELMET<---");
  digitalWrite(relay, LOW);
  digitalWrite(buzzer, HIGH);
  
 }
if(RxPinState1== HIGH) 
{ lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("              ");
  lcd.setCursor(0, 1);
  lcd.print("-> RIDE SAFE <-");
  digitalWrite(relay, HIGH);
  digitalWrite(buzzer, LOW);
  k++;
 }
if(RxPinState1== LOW && k>=1)
{ 
  for(j=10;j>=1;j--)
  {
  RxPinState1=digitalRead(RxPin1);
  if(RxPinState1== HIGH)
  break;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("-->PLEASE WEAR HELMET<-");
  lcd.setCursor(0, 1);    
  lcd.print(j);
  delay(1000);
  }
  digitalWrite(relay, LOW);
  digitalWrite(buzzer, HIGH); 
}
}
