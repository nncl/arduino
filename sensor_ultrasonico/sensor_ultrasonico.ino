int ledVermelho = 9;
int ledVerde = 10;

//Carrega a biblioteca do sensor ultrassônico
#include <Ultrasonic.h>
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
void setup()
{
 Serial.begin(9600);
 Serial.println("Lendo dados do sensor...");
 pinMode(ledVermelho, OUTPUT);
 pinMode(ledVerde, OUTPUT);
}
void loop()
{
 //Le as informacoes do sensor, em cm e pol
 float cmMsec, inMsec;
 long microsec = ultrasonic.timing();
 cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
 inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
 //Exibe informacoes no serial monitor
 Serial.print("Distancia em cm: ");
 Serial.print(cmMsec);
 Serial.print(" - Distancia em polegadas: ");
 Serial.println(inMsec);
 delay(1000);

  if (cmMsec > 5) {
    // acende verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    // acende vermelho
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
 
}
