#include <LiquidCrystal.h>
LiquidCrystal lcd(13,10,6,5,4,3);
byte floor1[] = {B11111,B11111,B01101,B00000,B00000,B01111,B11111,B11111};
byte botdown[] = {B00000,B01111,B11111,B11111,B11111,B11111,B01111,B00000};
byte botup[] = {B00000,B00000,B10000,B11100,B11100,B10000,B00000,B00000};
byte floor2[] = {B11111,B11111,B00110,B01010,B01010,B01100,B11111,B11111};
byte floor3[] = {B11111,B11111,B01010,B01010,B01010,B10101,B11111,B11111};
byte botmid[] = {B00000,B11111,B11111,B11111,B11111,B11111,B11111,B00000};
bool J1=0,K1=0,D=0,B=0;
bool J0=0,K0=0,C=0,A=0;
bool S0=0,S1=0,S2=0,E=0;
int i=0,j=0,k=0,t=291,l=t,r=18,c=0,p=0;
unsigned long auxtime;

void setup() {
 lcd.begin(16, 2);
 lcd.createChar(0, floor1);
 lcd.createChar(1, botdown);
 lcd.createChar(2, botup);
 lcd.createChar(3, floor2);
 lcd.createChar(6, floor3);
 lcd.createChar(5, botmid);
 pinMode(12,INPUT_PULLUP);
 pinMode(9,INPUT_PULLUP);
 pinMode(8,INPUT_PULLUP);
 pinMode(7,INPUT_PULLUP);
 lcd.setCursor(2,0);
 lcd.write(byte(0));
 lcd.setCursor(7,0);
 lcd.write(byte(3));
 lcd.setCursor(12,0);
 lcd.write(byte(6)); }


void loop() {
  coin();sel();checkE();
  eqff();eqout();ff0();ff1();   
  if(S0==1){coindec();p=0;i=0;clrbot();
    for (k=0;k<=(5*i)+3;k++){bot();delay(t);t=t-r;}clrout();}    
  else{i=0;j=0;k=0;bot();}  
  if(S1==1){coindec();p=0;i=1;clrbot();
    for (k=0;k<=(5*i)+3;k++){bot();delay(t);t=t-r;}clrout();}
  else{i=1;j=0;k=0;bot();}  
  if(S2==1){coindec();p=0;i=2;clrbot();
    for (k=0;k<=(5*i)+3;k++){bot();delay(t);t=t-r;}clrout();}
  else{i=2;j=0;k=0;bot();}}

void ff0(){
  if (J0==0 && K0==0){C=C;}
  if (J0==0 && K0==1){C=0;}
  if (J0==1 && K0==0){C=1;}
  if (J0==1 && K0==1){C=!C;}}
void ff1(){
  if (J1==0 && K1==0){D=D;}
  if (J1==0 && K1==1){D=0;}
  if (J1==1 && K1==0){D=1;}
  if (J1==1 && K1==1){D=!D;}}
void eqff(){
  J1=E&&B&&!C;
  K1=1;
  J0=E&&A&&!D;
  K0=1;}
void eqout(){
  S0=A&&!B&&!C&&!D&&E;
  S1=!A&&B&&!C&&!D&&E;
  S2=A&&B&&!C&&!D&&E;}
void sel(){  
    if(digitalRead(9)==0){B=0;A=1;delay(t);p=1;}
    else if(digitalRead(8)==0){B=1;A=0;delay(t);p=2;}
    else if(digitalRead(7)==0){B=1;A=1;delay(t);p=3;}
    else {B=0;A=0;}}    
void clrbot(){
  lcd.setCursor(5*i+3,0);
  lcd.print("   ");j++;}
void clrout(){lcd.setCursor(0,1);
  lcd.write(byte(5));
  lcd.write(byte(2));
  lcd.print(" "); delay(t);
  lcd.setCursor(0,1);
  lcd.write(byte(2));
  lcd.print(" "); t=l;delay(t);
  lcd.setCursor(0,1);
  lcd.print(" ");delay(t);}
void bot(){  
  lcd.setCursor(5*i+3-k,j);  
  lcd.write(byte(1));
  lcd.write(byte(5));
  lcd.write(byte(2));
  lcd.print(" ");}
void coin(){
  if(digitalRead(12)==0 && c<9){c++;delay(t);}
  lcd.setCursor(0,0);lcd.print(c);}
void coindec(){c=c-p;lcd.setCursor(0,0);lcd.print(c);}
void checkE(){if(c>=p){E=1;}
  else{E=0;}}
