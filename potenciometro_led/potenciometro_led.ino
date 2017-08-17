#define potPin 0
#define ledPin 6

int valPot = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valPot = analogRead(potPin);
  valPot = map(valPot,0,1023,0,255);
  analogWrite(ledPin, valPot);
}
