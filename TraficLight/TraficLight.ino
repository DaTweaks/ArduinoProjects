int i = 0;

enum inputPins{
  buttonPin = 7
};

// Input button bools
bool button = false;

enum outputPins{
  redTrafficlightPin = 2,
  yellowTrafficlightPin = 3,
  greenTrafficlightPin = 4,
  redPedestrianlightPin = 5,
  greenPedestrianlightPin = 6
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // setup output pins
  pinMode(redTrafficlightPin, OUTPUT);
  pinMode(yellowTrafficlightPin, OUTPUT);
  pinMode(greenTrafficlightPin, OUTPUT);
  pinMode(redPedestrianlightPin, OUTPUT);
  pinMode(greenPedestrianlightPin, OUTPUT);

  // setup input pins
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, FALLING);

  // for debug purposes
  digitalWrite(redTrafficlightPin, HIGH);
  digitalWrite(yellowTrafficlightPin, HIGH);
  digitalWrite(greenTrafficlightPin, HIGH);

  digitalWrite(redPedestrianlightPin, HIGH);
  digitalWrite(greenPedestrianlightPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  // because interrupts don't allow Delays i have to do this solution
  if(button){
    buttonPressed();
    button = false;
  }
  Delay(100); // Hopefully this will account for debounce delay.
}

void buttonInterrupt(){
  button = true;
}

void buttonPressed(){
  Serial.print("LOL! ");
  Serial.print(i++);
  Serial.println();
}