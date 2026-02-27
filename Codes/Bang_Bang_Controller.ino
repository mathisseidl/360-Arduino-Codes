// BANG-BANG CODE
// only counting ; next time will convert to RPM or RPS = Hz (1/s)
volatile long int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode (2, INPUT);
pinMode (3, INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
attachInterrupt(digitalPinToInterrupt (2), myFunction, RISING); // attachInterrupt function only for pin 2 and 3 
Serial.begin(9600);
Serial.println(counter); // makes new line for each output code ; print(counter) would just print all the counter #'s in one single horizontal line

digitalWrite(6,LOW);


}
void loop() {

if (counter>230)
  analogWrite(5,0);
else 
  analogWrite(5,50);

Serial.println(counter);

}

void myFunction() {
  if (digitalRead(3)==HIGH)
    counter++;
  else
    counter--;
}
