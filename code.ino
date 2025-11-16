// ======================================================
// SMART TRAFFIC LIGHT CONTROL WITH EMERGENCY VEHICLE DETECTION
// Lead Author: Niroj Koirala
// ======================================================

#include <Servo.h>

// ------------------- Pin Configuration -------------------
#define SOUND_SENSOR A0         // Sound sensor input for siren detection
#define TRIG1 2                 // Ultrasonic Sensor 1 Trigger
#define ECHO1 3                 // Ultrasonic Sensor 1 Echo
#define TRIG2 4
#define ECHO2 5
#define TRIG3 6
#define ECHO3 7
#define TRIG4 8
#define ECHO4 9

#define RED1 10
#define YELLOW1 11
#define GREEN1 12
#define RED2 13
#define YELLOW2 A1
#define GREEN2 A2

#define SERVO_PIN A3
#define BLUETOOTH_RX 0          // Optional Bluetooth input (manual override)

// ------------------- Global Variables -------------------
Servo barrierServo;
bool emergencyDetected = false;
unsigned long greenExtensionTime = 6000; // Extend green by 6 seconds
int soundThreshold = 520;                // Threshold for siren detection

// ------------------- Setup -------------------
void setup() {
  Serial.begin(9600);
  pinMode(SOUND_SENSOR, INPUT);

  pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT); pinMode(ECHO3, INPUT);
  pinMode(TRIG4, OUTPUT); pinMode(ECHO4, INPUT);

  pinMode(RED1, OUTPUT); pinMode(YELLOW1, OUTPUT); pinMode(GREEN1, OUTPUT);
  pinMode(RED2, OUTPUT); pinMode(YELLOW2, OUTPUT); pinMode(GREEN2, OUTPUT);

  barrierServo.attach(SERVO_PIN);
  barrierServo.write(90); // Barrier closed
  Serial.println("System Initialized: Smart Traffic Light Ready");
}

// ------------------- Distance Measurement -------------------
long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2; // Distance in cm
}

// ------------------- Sound Detection -------------------
bool detectEmergency() {
  int soundValue = analogRead(SOUND_SENSOR);
  if (soundValue > soundThreshold) {
    Serial.println("Emergency Siren Detected!");
    return true;
  }
  return false;
}

// ------------------- Boom Barrier Control -------------------
void openBarrier() {
  Serial.println("Opening Barrier...");
  barrierServo.write(0); // Open position
  delay(1000);
}

void closeBarrier() {
  Serial.println("Closing Barrier...");
  barrierServo.write(90); // Closed position
  delay(1000);
}

// ------------------- Light Control -------------------
void lightControl(int r, int y, int g, unsigned long duration) {
  digitalWrite(r, LOW);
  digitalWrite(y, LOW);
  digitalWrite(g, HIGH);
  delay(duration);
  digitalWrite(g, LOW);
  digitalWrite(y, HIGH);
  delay(2000);
  digitalWrite(y, LOW);
  digitalWrite(r, HIGH);
}

// ------------------- Loop -------------------
void loop() {
  // 1️⃣ Emergency Detection
  emergencyDetected = detectEmergency();
  if (emergencyDetected) {
    Serial.println("Emergency Priority: Extending Green Signal...");
    openBarrier();
    lightControl(RED1, YELLOW1, GREEN1, greenExtensionTime);
    closeBarrier();
    emergencyDetected = false;
    return;
  }

  // 2️⃣ Density Measurement
  long d1 = getDistance(TRIG1, ECHO1);
  long d2 = getDistance(TRIG2, ECHO2);
  long d3 = getDistance(TRIG3, ECHO3);
  long d4 = getDistance(TRIG4, ECHO4);

  Serial.print("Distances: "); Serial.print(d1); Serial.print(" "); Serial.print(d2);
  Serial.print(" "); Serial.print(d3); Serial.print(" "); Serial.println(d4);

  int maxLane = 1;
  long maxDistance = d1;

  if (d2 > maxDistance) { maxLane = 2; maxDistance = d2; }
  if (d3 > maxDistance) { maxLane = 3; maxDistance = d3; }
  if (d4 > maxDistance) { maxLane = 4; maxDistance = d4; }

  Serial.print("Prioritizing Lane: "); Serial.println(maxLane);

  // 3️⃣ Signal Logic
  switch (maxLane) {
    case 1: lightControl(RED1, YELLOW1, GREEN1, 5000); break;
    case 2: lightControl(RED2, YELLOW2, GREEN2, 5000); break;
    default: lightControl(RED1, YELLOW1, GREEN1, 5000);
  }

  // 4️⃣ Bluetooth Manual Override (optional)
  if (Serial.available()) {
    char command = Serial.read();
    if (command == 'O' || command == 'o') openBarrier();
    else if (command == 'C' || command == 'c') closeBarrier();
  }

  delay(1000);
}
