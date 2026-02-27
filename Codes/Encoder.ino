void setup() {
  // put your setup code here, to run once:
pinMode (2, INPUT);
pinMode (3, INPUT);
attachInterrupt(digitalPinToInterrupt (2), myFunction, RISING); // attachInterrupt function only for pin 2 and 3 
// RISING seeks for rising edge, everytime rising edge detected --> myFunction (line 16) is run
// HIGH? Adds to counter
// LOW? Subtracts from counter
// if ONE REV ouptuts ~ 240 in change of serial monitor --> sensor functioning properly
Serial.begin(9600);
}

volatile long int counter=0;
void loop() {
  // put your main code here, to run repeatedly:
Serial.println(counter);

}

void myFunction() {
  if (digitalRead(3)==HIGH)
    counter++;
  else
    counter--;
}
