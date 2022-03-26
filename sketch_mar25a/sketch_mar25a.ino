#define WIFI_SSID "  "        //To connect to wifi with ssid
#define WIFI_PASSWORD "  "    //To connect to wifi with password
#include<Servo.h>             //To connect to Servo
  Servo servo1;               //Fingers of arm
  Servo servo2;               //Wrist of arm
  Servo servo3;               //Elbow of arm
  Servo servo4;               //Shoulder of arm
                              //The position of servo
int pos1;                     //The position of Fingers
int pos2;                     //The position of Wrist
int pos3;                     //The position of Elbow
int pos4;                     //The position of Shoulder
                              //Data from camera
String material;
String plastic=plastic;
String metal=metal;
String glass=glass;
String paper=paper;

void setup() {
    Serial.begin(9600);
    WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
    servo1.attach(0);
    servo2.attach(1);
    servo3.attach(2);
    servo4.attach(3);

}

void check(){
      if(Wifi.status()!=WL_CONNECTED) //chek wifi conection status
   {
    Serial.print("Attempting to connect to SSID : ");
    Serial.println(WIFI_SSID);
   }
 while(Wifi.status()!=WL_CONNECTED) 
    WiFi.mbegin(WIFI_SSID,WIFI_PASSWORD);
    Serial.print(".");
    delay(5000);
   }
  Serial.println("/nconnected.");

  }
 void starting_point(){
  pos1=45;
  pos2=90;
  pos3=90;
  pos4=0;
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
    }
void catch(){
  pos1=10;
  pos2=175;
  pos3=175;
  pos4=0;
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
    }
void plastic_go(){
  pos3=120;
  pos4=60;
  pos1=45;
  servo3.write(pos3);
  servo4.write(pos4);
  servo1.write(pos1);
    }
void metal_go(){
  pos3=120;
  pos4=120;
  pos1=45;
  servo3.write(pos3);
  servo4.write(pos4);
  servo1.write(pos1);
    }
void glass_go(){
  pos3=120;
  pos4=180;
  pos1=45;
  servo3.write(pos3);
  servo4.write(pos4);
  servo1.write(pos1);
    }
void paper_go(){
  pos3=120;
  pos4=240;
  pos1=45;
  servo3.write(pos3);
  servo4.write(pos4);
  servo1.write(pos1);
    }
void organic materials(){
  pos3=120;
  pos4=300;
  pos1=45;
  servo3.write(pos3);
  servo4.write(pos4);
  servo1.write(pos1);
    }
void loop() {
  check();
  catch();
  if(material.equalsIgnoreCase(plastic)){
    plastic_go();
    }
    else if(material.equalsIgnoreCase(metal)){
      metal_go();
      }
    else if(material.equalsIgnoreCase(glass)){
      glass_go();
      }
    else if(material.equalsIgnoreCase(paper)){
      paper_go();
      }
    else{
      organic materials();
      }
  starting_point();
  delay(1000);
 
}
