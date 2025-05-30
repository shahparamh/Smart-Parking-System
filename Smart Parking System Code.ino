#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Initialize LCD at address 0x27 (change to 0x3F if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servo motor
Servo gate;

// Ultrasonic sensor pins
const int slotTrig[3] = {2, 4, 6}; // Slots 1, 2, 3
const int slotEcho[3] = {3, 5, 7};

const int entryTrig = 8;
const int entryEcho = 10;

const int exitTrig = 11;
const int exitEcho = 12;

// Distance threshold in cm
int distanceThreshold = 10;

int freeSlots = 3;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" Smart Parking ");
  lcd.setCursor(0, 1);
  lcd.print(" Initializing...");
  delay(3000);
  lcd.clear();

  // Setup pin modes
  for (int i = 0; i < 3; i++) {
    pinMode(slotTrig[i], OUTPUT);
    pinMode(slotEcho[i], INPUT);
  }

  pinMode(entryTrig, OUTPUT);
  pinMode(entryEcho, INPUT);
  pinMode(exitTrig, OUTPUT);
  pinMode(exitEcho, INPUT);

  // Attach servo and initialize gate position
  gate.attach(9);
  gate.write(0); // closed position
}

// Function to measure distance from ultrasonic sensor
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

// Update the number of free slots
void updateSlotStatus() {
  freeSlots = 0;
  for (int i = 0; i < 3; i++) {
    long distance = getDistance(slotTrig[i], slotEcho[i]);
    if (distance > distanceThreshold || distance == 0) {
      freeSlots++;
    }
  }
}

// Open the gate
void openGate() {
  gate.write(90); // open
  delay(2000);
  gate.write(0); // close
}

void loop() {
  updateSlotStatus();

  lcd.setCursor(0, 0);
  lcd.print("Free Slots: ");
  lcd.print(freeSlots);
  lcd.print("   "); // Clear trailing characters

  // ENTRY detection
  long entryDist = getDistance(entryTrig, entryEcho);
  if (entryDist < 15 && freeSlots > 0) {
    lcd.setCursor(0, 1);
    lcd.print("Car Entering... ");
    openGate();
    delay(3000); // Wait for car to move in
    lcd.clear();
  }

  // EXIT detection
  long exitDist = getDistance(exitTrig, exitEcho);
  if (exitDist < 15) {
    lcd.setCursor(0, 1);
    lcd.print("Car Exiting...  ");
    openGate();
    delay(3000); // Wait for car to exit
  }
  lcd.setCursor(0, 1);
  lcd.print("				")
  delay(500); // Loop delay
}
