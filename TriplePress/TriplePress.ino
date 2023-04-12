int outport = 13;
int inport = 12;

int presses = 0;

int timebetweenpresses = 0;

int maxtimebetweenpresses = 3000;

bool down = false;

void setup() 
{
  // put your setup code here, to run once:

  pinMode(2, INPUT);
  Serial.begin(9600);
  pinMode(outport, OUTPUT);
  pinMode(inport, INPUT_PULLUP);

  if(digitalRead(2) == LOW){
    Serial.println("JUMPER CABLE!");
    return;
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:

  while(digitalRead(2) == HIGH){

    if(timebetweenpresses != maxtimebetweenpresses){
      timebetweenpresses++;
    }
    else{
      presses = 0;
    }


    if(digitalRead(inport) == HIGH && down == false){
      if(timebetweenpresses <= maxtimebetweenpresses){
        presses++;
      }
      timebetweenpresses = 0;

      down = true;
    }
    else if(digitalRead(inport) == LOW){
      down = false;
    }

    Serial.println(presses);

    if(presses >= 3){
     digitalWrite(outport, HIGH);
     delay(3000);
      digitalWrite(outport, LOW);
      presses = 0;
    }
  }
}