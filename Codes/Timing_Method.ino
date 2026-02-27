// program to move motor exactly one revolution (240 counts)
// worst method b/c code must be changed between different motors to adjust for friction, torque, etc.
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

// TIMING METHOD ; make one pin GROUND ; D5 and D6 control GRD and some signal to direct the motor in one direction
digitalWrite (6,LOW); // pin6 is set as GROUND
analogWrite (5, 114); // 114 is PWM for the DC motor to hit 240 count; modulate speed with the number
delay(625); // 625 millisecond delay --> check counter for each run

digitalWrite(6,LOW);
analogWrite(5,0);

}
void loop() {
Serial.println(counter);
while (true){}
}

void myFunction() {
  if (digitalRead(3)==HIGH)
    counter++;
  else
    counter--;
}
