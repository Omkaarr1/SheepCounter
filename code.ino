// C++ code
//
int count = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

}

void loop()
{
  if (0.01723 * readUltrasonicDistance(6, 5) < 300) 
  {
    if (0.01723 * readUltrasonicDistance(11, 10) < 300)
    {
      count = (count + 1);
      Serial.print("Number of Sheep in Land: ");
      Serial.println(count);
    }
  } else if (0.01723 * readUltrasonicDistance(11, 10) < 300)
  {
      if (0.01723 * readUltrasonicDistance(6, 5) < 300)
      {
        count = (count - 1);
        Serial.print("Number of Sheep in Land: ");
        Serial.println(count);
      }
    }
  delay(500); // Wait for 2000 millisecond(s)
}