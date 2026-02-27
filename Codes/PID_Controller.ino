// PID (Proportional-Derivative-Integrative) Control
//program to move motor two revolutions (480 counts) ~ closed loop
volatile long int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode (2, INPUT);
pinMode (3, INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
attachInterrupt(digitalPinToInterrupt (2), myFunction, RISING); // attachInterrupt function only for pin 2 and 3 
Serial.begin(9600); // 9600 bits per second (baud) ~ transfer rate ; can use either bits or bytes ; 1 byte = 10 bits (for ARDUINO!)
//captures 960 bytes per second
Serial.println(counter); // makes new line for each output code ; print(counter) would just print all the counter #'s in one single horizontal line
digitalWrite(6,LOW);
}

double vout=255, kp=0.5; // IMPORTANT! Adjust kp to SEE WHAT HAPPENS!
int error=0, target=480, vcontrol=255;
int minVol = 50; // minimum voltage to overcome friction

void loop() {
  error = target - counter;
  vout = kp * counter;

  vcontrol = constrain(int(vout), 0 , 255); // 255 caps the increase so the difference doesn't negative

  // apply minimum PWM threshold
  if (vcontrol > 0 && vcontrol < minVol) vcontrol = minVol;

  analogWrite(5, abs(vcontrol));

  Serial.println(counter);
  delay(20);
}

void myFunction(){
  if (digitalRead(3)==HIGH)
  counter++;
  else
  counter--;

}
