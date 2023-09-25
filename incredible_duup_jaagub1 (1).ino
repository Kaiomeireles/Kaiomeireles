const int LDRPin = A0;
const int greenLEDPin = 8;
const int yellowLEDPin = 9;
const int redLEDPin = 10;
const int buzzerPin = 7;

int luminosityValue;
int alertThreshold = 200; // Ajuste esse valor de acordo com suas necessidades
bool alertActive = false;

void setup() {
  pinMode(greenLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  luminosityValue = analogRead(LDRPin);

  if (luminosityValue < alertThreshold) {
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);

    if (!alertActive) {
      tone(buzzerPin, 1000); // Ativa o buzzer
      alertActive = true;
    }
  } else {
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, LOW);

    noTone(buzzerPin); // Desliga o buzzer
    alertActive = false;
  }

  Serial.print("Luminosidade: ");
  Serial.println(luminosityValue);

  delay(1000); // Aguarde um segundo antes de fazer a próxima leitura
}

