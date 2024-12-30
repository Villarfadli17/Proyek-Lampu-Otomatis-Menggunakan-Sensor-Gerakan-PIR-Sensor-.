// Mendeklarasikan pin untuk sensor PIR dan LED
int pirPin = 7;       // Pin untuk sensor PIR
int ledPin = 13;      // Pin untuk LED (atau bisa menggunakan relay untuk lampu AC)

// Variabel untuk menyimpan status deteksi gerakan
int motionDetected = 0;

void setup() {
  // Inisialisasi pin PIR dan LED
  pinMode(pirPin, INPUT);     // Sensor PIR sebagai input
  pinMode(ledPin, OUTPUT);    // LED sebagai output
  
  // Mulai komunikasi serial untuk debugging
  Serial.begin(9600);
}

void loop() {
  // Membaca status sensor PIR (HIGH = gerakan terdeteksi, LOW = tidak ada gerakan)
  motionDetected = digitalRead(pirPin);
  
  // Jika ada gerakan (sensor PIR HIGH)
  if (motionDetected == HIGH) {
    digitalWrite(ledPin, HIGH);   // Menyalakan LED (atau lampu)
    Serial.println("Gerakan Terdeteksi! Lampu Menyala.");
  }
  // Jika tidak ada gerakan (sensor PIR LOW)
  else {
    digitalWrite(ledPin, LOW);    // Mematikan LED (atau lampu)
    Serial.println("Tidak Ada Gerakan. Lampu Mati.");
  }
  
  delay(100);  // Menunggu sebentar sebelum membaca lagi
}