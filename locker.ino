#include <Servo.h>

// Pinos do Arduino
int soundDigitalPin = 7;  // Interface digital do KY-037
int soundAnalogPin = A0;  // Interface analógica do KY-037
int motionPin = 2;        // Pino do sensor de movimento HCSR501
int servoPin = 9;         // Pino do servo motor (substituindo o LED)

// Variáveis para leitura
int soundDigitalVal;
int motionVal;
int clapCount = 0;
int motionCount = 0;
unsigned long lastClapTime = 0;
const int clapInterval = 10000;
const int threshold = 389;

Servo servo;

void setup() {
  pinMode(soundDigitalPin, INPUT); 
  pinMode(soundAnalogPin, INPUT);
  pinMode(motionPin, INPUT);

  servo.attach(servoPin); // Conecta o servo ao pino
  servo.write(0);         // Define posição inicial (fechado)

  Serial.begin(9600);
}

void loop() {
  int soundAnalogValue = analogRead(soundAnalogPin);
  soundDigitalVal = digitalRead(soundDigitalPin);
  motionVal = digitalRead(motionPin);

  if (motionVal == HIGH) {
    motionCount++;
  }

  if (motionCount > 0) {
    if (soundAnalogValue > threshold) {
      unsigned long currentTime = millis();
      clapCount++;

    if (clapCount == 2) {
        Serial.println("Duas palmas e presença detectadas! Movendo servo.");

        servo.write(45);
        delay(5000);
        motionCount = 0;
      }
    if (clapCount == 5) {
        servo.write(0);
        
        clapCount = 0;
        lastClapTime = 0;
        motionCount = 0;
      } 
    else if ((currentTime - lastClapTime) <= clapInterval) {
        lastClapTime = currentTime;
        Serial.print("Palma detectada! Contagem: ");
        Serial.println(clapCount);
      }
    }
  }
 
  Serial.print("Som Analógico: ");
  Serial.println(soundAnalogValue);
  Serial.print("Presença: ");
  Serial.println(motionCount);
}
