/*
 Test LCD + MODE Select button
 
 */

 
#include <LiquidCrystal.h>
#include <math.h>
#include <SPI.h>

int button_pin = 2;
int back_light = 10;
int v100 = 9;
int v30 = 8;
int v10 = 7;
int curr_mode = 13;
int MODE = 0;
int brightness = 0;   
int fadeAmount = 5; 
int curr_value = 0;
int acc_value = 0;
float disp_res;
float supply = 4.91;
float coeff_v100 = 1.01;
float coeff_v30 = 1.011;
float coeff_v10 = 1.018;
float coeff_A_gain = 0.992174;
float coeff_A_res = 0.98315;
float opamp_offset = 0.000767;

volatile unsigned long last_millis = 0;


LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup()  { 
  pinMode(button_pin, INPUT); 
  pinMode(back_light, OUTPUT); 
  pinMode(v100, OUTPUT);  
  pinMode(v30, OUTPUT);   
  pinMode(v10, OUTPUT);  
  pinMode(curr_mode, OUTPUT); 
  attachInterrupt(0, button_pressed, RISING);
  analogWrite(back_light, brightness);
  digitalWrite(v100, LOW);
  digitalWrite(v30, LOW);
  digitalWrite(v10, LOW);
  digitalWrite(curr_mode, LOW);
  lcd.begin(16, 2);
  lcd.print("DIGITAL MULTIMER *** DIGITAL MULTIMER");
  lcd.setCursor(0, 1);
  lcd.print("Press \"MODE\" key to select a function");
  Serial.begin(9600);
  Serial.println("*******************************************************"); 
  Serial.println("*                 DIGITAL MULTIMETER                  *");
  Serial.println("*   Press the \"MODE\" key to select a function         *"); 
  Serial.println("*******************************************************");
  delay (1000);  
    delay (1000); 
      delay (1000); 
        delay (1000); 
          delay (1000); 
} 


void loop()  { 
  digitalWrite(v100, LOW);
  digitalWrite(v30, LOW);
  digitalWrite(v10, LOW); 
  digitalWrite(curr_mode, LOW); 
  brightness = 0;
  analogWrite(back_light, brightness); 
  delay(20);
   if (MODE>0) {
  lcd.clear();
  lcd.print("MODE");
  lcd.setCursor(0, 1);   
     switch (MODE) {            
             case 1: 
             V_100();  // Voltmeter mode with range 0-100V
               break;             
             case 2:
             V_30();   // Voltmeter mode with range 0-30V
               break;  
             case 3:
             V_10();   // Voltmeter mode with range 0-10V
               break;  
             case 4:
             A_500();  // Amperemeter mode with range 0-500mA
               break;             
             case 5:
             R_250();  // Ohmmeter mode with range 0-250KOhm
               break;  
             case 6:
             R_1000();  // Ohmmeter mode with range 0-1000R
               break;             
             case 7:
             D_LED_CONN(); //Check Vforward of diodes, LEDs and connectivity with 10uA
               break;             
             case 8:
             LED_FUNC(); // LED function check
               break;  
             case 9:
             BETA(); // NPN BETA meter - max 1000
               break;             
          } 
 }
  else {
  for (int positionCounter = 0; positionCounter < 21; positionCounter++) {
    lcd.scrollDisplayLeft(); 
    delay(150);
  }
  delay (1000);
  delay (1000);  
  for (int positionCounter = 0; positionCounter < 21; positionCounter++) {
    lcd.scrollDisplayRight(); 
    delay(150);
  }
  delay (1000);
  delay (1000);  
  }   
}


void button_pressed() {
  long current_Time = millis();  
  if ((current_Time - last_millis) > 150) {
  last_millis = current_Time; 
  
  if (MODE == 9)   {
    MODE = 1; 
   }   
  else {
    MODE = MODE++;   
   } 
  }
 }     

void V_100() {
  digitalWrite(v100, HIGH);
  lcd.clear();
  lcd.print("V-meter V=<100V");
  Serial.println("*        Voltmeter mode - Range 0 - 100 V             *");
  lcd.setCursor(0, 1); 
  voltage_meas();
 }     
void V_30() {
  digitalWrite(v30, HIGH);
  lcd.clear();
  lcd.print("V-meter V=< 30V");
  Serial.println("*        Voltmeter mode - Range 0 - 30 V              *");
  lcd.setCursor(0, 1); 
  voltage_meas();   
 }
void V_10() {
  digitalWrite(v10, HIGH);
  lcd.clear();
  lcd.print("V-meter V=< 10V");
  Serial.println("*        Voltmeter mode - Range 0 - 10 V              *");
  lcd.setCursor(0, 1); 
  voltage_meas();
 }
void A_500() {
  lcd.clear();
  lcd.print("A-meter I=<500mA");
  Serial.println("*      Amperemeter mode - Range 0 - 500mA             *");
  lcd.setCursor(0, 1); 
  acc_value = 0; 
  for (int i=0; i <= 15; i++){
  curr_value = analogRead(A1);   
  acc_value = acc_value + curr_value; 
  }      
  curr_value =  int(acc_value/16);
  if (curr_value == 1023) {
    meas_overflow(); }
  else {
    disp_res = (((curr_value*supply )/1024 - 10*opamp_offset)/coeff_A_gain)/coeff_A_res*100;  
    lcd.print("   I = ");   
    lcd.print(disp_res, 1);  
    lcd.print(" mA");
    Serial.print("*                      I = "); 
    Serial.print(disp_res, 1); 
    Serial.println(" mA");

    delay(250);
  }
 } 
void R_250() {
  lcd.clear();
  lcd.print("Ohmmeter R=<250K");
  Serial.println("*      Ohmmeter mode - Range 0 - 250 KOhm             *");
  lcd.setCursor(0, 1); 
  acc_value = 0; 
  for (int i=0; i <= 15; i++){
  curr_value = analogRead(A2);   
  acc_value = acc_value + curr_value; 
  }      
  curr_value =  int(acc_value/16);
  if (curr_value >= 512) {
    meas_overflow(); }
  else {
    disp_res = ( curr_value*supply )/1024*100;  
    lcd.print(" R = ");   
    lcd.print(disp_res, 1);  
    lcd.print(" KOhm");
    Serial.print("*                      R = "); 
    Serial.print(disp_res, 1); 
    Serial.println(" KOhm");

    delay(250);
  }
 } 
void R_1000() {
  digitalWrite(curr_mode, HIGH); 
  delay(20);
  lcd.clear();
  lcd.print("Ohmmeter R=<1000");
  Serial.println("*      Ohmmeter mode - Range 0 - 1000 Ohm             *");
  lcd.setCursor(0, 1); 
  acc_value = 0; 
  for (int i=0; i <= 15; i++){
  curr_value = analogRead(A2);   
  acc_value = acc_value + curr_value; 
  }      
  curr_value =  int(acc_value/16);
  if (curr_value >= 512) {
    meas_overflow(); }  
  else {
    disp_res = ( curr_value*supply )/1024*400;  
    lcd.print(" R = ");   
    lcd.print(disp_res, 1);  
    lcd.print(" Ohm");
    Serial.print("*                      R = "); 
    Serial.print(disp_res, 1); 
    Serial.println(" Ohm");

    delay(250);
  }

 }
void D_LED_CONN() {
  lcd.clear();
  lcd.print("Vf:Dio/LED; CONN");
  Serial.println("* Vforward of diode/LED ; Connectivity check - 10uA   *");  
  lcd.setCursor(0, 1); 
  acc_value = 0; 
  for (int i=0; i <= 15; i++){
  curr_value = analogRead(A2);   
  acc_value = acc_value + curr_value; 
  }      
  curr_value =  int(acc_value/16);
  if (curr_value >= 560) {
    meas_overflow(); }
  else if (curr_value <= 1) {
    zero_res(); }
  else {
    disp_res = ( curr_value*supply )/1024*1000;  
    lcd.print("   V = ");   
    lcd.print(disp_res,0);  
    lcd.print(" mV");
    delay(250);
    Serial.print("*                      V = "); 
    Serial.print(disp_res, 0); 
    Serial.println(" mV");

  }
 }
void LED_FUNC() {
  digitalWrite(curr_mode, HIGH);
  lcd.clear();
  lcd.print("LED function chk"); 
  Serial.println("*               LED functionality check               *");  
  lcd.setCursor(0, 1); 
    acc_value = 0; 
  for (int i=0; i <= 15; i++){
  curr_value = analogRead(A2);   
  acc_value = acc_value + curr_value; 
  }      
  curr_value =  int(acc_value/16);
  if (curr_value >= 560) {
    LED_tst(); }
  else if (curr_value <= 1) {
    zero_res(); }
  else {
    disp_res = ( curr_value*supply )/1024*1000;  
    lcd.print(" V = ");   
    lcd.print(disp_res,0);  
    lcd.print(" mV");
    Serial.print("*                      V = "); 
    Serial.print(disp_res, 0); 
    Serial.println(" mV");

    delay(250);
  }
 }
void BETA() {
  lcd.clear();
  lcd.print("NPN BETA meter");  
  Serial.println("*               NPN BJT BETA measurement              *"); 
  lcd.setCursor(0, 1); 
  acc_value = 0; 
  for (int i=0; i <= 15; i++){
  curr_value = analogRead(A3);   
  acc_value = acc_value + curr_value; 
  }      
  curr_value =  int(acc_value/16);
  curr_value =  1023 - curr_value;
  disp_res = ( curr_value*supply )/1024*333.33; 
  if (disp_res >=10){
  lcd.print(" BETA = ");   
  lcd.print(disp_res,0); 
    Serial.print("*                    Beta = "); 
    Serial.print(disp_res, 0); }
  else {
  LED_tst(); }   
  delay(250);
 }
 
void meas_overflow() {
  lcd.setCursor(0, 1);
  lcd.print("   OVERFLOW!!!  ");  
  Serial.println("*                     OVERFLOW!!!                     *"); 
  lcd.setCursor(0, 1); 
  for (int i=0; i <= 101; i++){
  analogWrite(back_light, brightness);    
  brightness = brightness + fadeAmount;
  if (brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }      
  delay(15); 
  }  
 }
 
 void zero_res() {
  lcd.setCursor(0, 1);
  lcd.print("Zero resistance!");  
  Serial.println("*           Short circuit - zero resistance           *"); 
  delay(250);
  brightness = 255;
  analogWrite(back_light, brightness);
  delay(250);
  brightness = 0;
  analogWrite(back_light, brightness);  
 }
 
 void voltage_meas() {
  acc_value = 0; 
  for (int i=0; i <= 15; i++){
  curr_value = analogRead(A0);   
  acc_value = acc_value + curr_value; 
  }      
  curr_value =  int(acc_value/16);
  if (curr_value == 1023) {
    meas_overflow(); }
  else {
 switch (MODE) {            
             case 1: 
    disp_res = ( curr_value*supply*20)/1024*coeff_v100 ;
               break;             
             case 2:
    disp_res = ( curr_value*supply*6)/1024*coeff_v30;
               break;  
             case 3:
    disp_res = ( curr_value*supply*2)/1024*coeff_v10;
               break;  }    
    lcd.print("   V = ");   
    lcd.print(disp_res, 2);   
    lcd.print(" V");
    Serial.print("*                      V = "); 
    Serial.print(disp_res, 2); 
    Serial.println(" V");
    delay(250);
  }    
}

void LED_tst() {
  lcd.setCursor(0, 1);
  if (MODE == 8) {
  lcd.print(" Swap the pins "); 
  Serial.println("* Try to swap the LED pins. White LED could not glow  *"); }
  else {
  lcd.print("Check the NPN tr");  
  Serial.println("*    Check if the BJT is NPN. Check the pin order     *"); }
  delay (500);
  lcd.noDisplay();
  delay (200);
  lcd.display();  
 }
