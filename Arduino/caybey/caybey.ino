


#include <Servo.h>

Servo myservo1; 
Servo myservo2;
Servo myservo3; 

int servodelay = 30;
int pos1 = 0;
int pos2 = 70;
int pos3 = 0; 
int coef1 = 70; 
int coef2 = 80; 
int coef22 = 120;
int coef3 = 90; 


 void caydemle();
 void sekker();
 void teadelay();

void setup() {

  
  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);
  myservo1.write(20); 
  myservo2.write(30); 
  myservo3.write(0);  
  delay(3000);

  
}

void loop() {
  
    delay(3000);
    caydemle();
    teadelay();
    sekker();
    delay(3000);  
    teadelay();           
}


void caydemle(){


           for (pos2 = 0; pos2 <= coef2; pos2++) { 
      myservo2.write(pos2);            
      delay(servodelay);   
      if(pos2 >= coef2) break;  
          }
          
        for (pos3 = 0; pos3 <= coef3; pos3++) { 
      myservo3.write(pos3);              
      delay(servodelay);   
      if(pos3 >= coef3) break;  
       }
  
 
  
  
        for (pos1 = 0; pos1 <= coef1; pos1++) { 
      myservo1.write(pos1);              
      delay(servodelay);
      if(pos1 >= coef1) break;   
       }

       for (pos2 = coef2; pos2 <= coef22; pos2++) { 
          myservo2.write(pos2);            
          delay(servodelay);   
          if(pos2 >= coef22) break;  
       }

  }

void sekker(){

      for (pos1 = coef2; pos1 >= 20; pos1--) { 
      myservo1.write(pos1);              
      delay(servodelay);
      if(pos1 <= 0) break;   
       }
       

            for (pos2 = coef2; pos2 >= 30; pos2--) { 
      myservo2.write(pos2);            
      delay(servodelay);   
      if(pos2 <= 0) break;  
          }


        for (pos3 = coef3; pos3 >= 0; pos3--) { 
      myservo3.write(pos3);              
      delay(servodelay);   
      if(pos3 <= 0) break;  
       }
  

  
  


  }
  
void teadelay(){

  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);
    delay(2000);
  delay(2000);
  delay(2000);
  delay(2000);

  
  
  
  
  
  }
