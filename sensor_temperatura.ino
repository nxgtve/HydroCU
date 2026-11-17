const int trigPin = 9;
const int echoPin = 10;
const float LIMITE_CM = 50.0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH, 30000);

  if (duracao == 0) {
    Serial.println("Sem leitura");
  } else {
    float distancia = duracao * 0.0343 / 2;
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.print(" cm");

    if (distancia <= LIMITE_CM) {
      Serial.print("  -> DENTRO do limite");
    }
    Serial.println();
  }

  delay(200);
}