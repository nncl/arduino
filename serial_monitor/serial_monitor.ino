#define LED 13 // Pin 13 onde esta conectado o LED
char rxChar= 0; // RXcHAR holds the received command.
//Funcao com menu
void printMenu(){
 Serial.println("--- Serial Monitor ---");
 Serial.println("a -> Ligar o LED");
 Serial.println("d -> Desligar o LED");
 Serial.println("s -> Status do LED");
 }
void setup(){
 Serial.begin(9600); // Open serial port (9600 bauds).
 pinMode(LED, OUTPUT); // Sets pin 13 as OUTPUT.
 Serial.flush(); // Clear receive buffer.
 printMenu(); // Print the command list.
}

void loop(){
 if (Serial.available() >0){ // Verifica se recebeu alguma coisa no buffer
 rxChar = Serial.read(); // Salva o caracter lido
 Serial.flush(); // Limpa o buffer

 switch (rxChar) {

 case 'a':
 case 'A':
 if (digitalRead(LED) == LOW){
 digitalWrite(LED,HIGH);
 Serial.println("LED Ligado");
 } else
 Serial.println("LED ja esta ligado");
 break;
 case 'd':
 case 'D':
 if (digitalRead(LED) == HIGH){
 digitalWrite(LED,LOW);
 Serial.println("LED desligado");
 }
 else Serial.println("LED ja esta desligado");
 break;

 case 's':
 case 'S':
 if (digitalRead(LED) == HIGH)
 Serial.println("LED status: Ligado");
 else
 Serial.println("LED status: Desligado");
 break;

 default:
 Serial.print("'");
 Serial.print((char)rxChar);
 Serial.println("' nao eh um comando valido!");
 }
 }
}
