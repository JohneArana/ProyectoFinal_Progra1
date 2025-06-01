// Pines del sensor ultrasónico
#define trigPin 13 //amarillo
#define echoPin 12 //verde
#define led 2 //cable naranja

// Pines del motor
const int ENA = A5; //verde 
const int IN1 = A4; //amarillo
const int IN2 = A3; //naranja

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {
  long duracion, distancia;

  // Enviar pulso ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Medir duración del eco
  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion / 2 / 29.1; // Convertir a cm

  Serial.println(String(distancia) + " cm.");

  int Limite = 10; // Distancia mínima en cm

  if (distancia < Limite) {
    digitalWrite(led, HIGH);      // Encender LED
    digitalWrite(IN1, LOW);       // Detener motor
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
  } else {
    digitalWrite(led, LOW);       // Apagar LED
    digitalWrite(IN1, HIGH);      // Encender motor
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 200);        // Velocidad media
  }

  delay(500); // Espera medio segundo
}

