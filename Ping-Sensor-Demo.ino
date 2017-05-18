int ping = 12;

void setup() {
  Serial.begin(9600);
}

void loop() {
  long distance = getDistance();    // stores the value in long distace
  /*
  Serial.print(distance);
  Serial.println("in");
  */
  delay(100);
}

/*
 * INPUT:  Reads from Ping sensor (pin variable "ping")
 * OUTPUT: The distance in inches away from the Ping sensor
 */
long getDistance() {
  // trigger ping sensor
  pinMode(ping, OUTPUT);                // code that actually
  digitalWrite(ping, LOW);              // reads from the sensor
  delayMicroseconds(2);                 // 
  digitalWrite(ping, HIGH);             // send initial pulse
  delayMicroseconds(5);                 //
  digitalWrite(ping, LOW);              //
                                        //
  pinMode(ping, INPUT);                 // find travel time
  long duration = pulseIn(ping, HIGH);  // store in variable duration
  
  return duration / 74 / 2;             // convert to inches
}
