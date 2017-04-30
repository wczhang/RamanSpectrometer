int sent = 0;
int received = 0;

void setup() {
  Serial.begin(112500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH); // check for Arduino get past RESET
}

void loop() {
  ping();
}

void ping() {
  // end ping test conditions
  if (received == 10 || sent > 1000) {
    Serial.println("exit"); // send exit flag
    while(1){}
  }

  // send message to MATLAB
  sent++;
  Serial.println(String(sent) + " sent, " + String(received) + " received");
  delay(30);

  // check for acknowledge from MATLAB
  while (Serial.available()) {
    if (Serial.readString().equals("received")){
      received++;
    }
  }
}
