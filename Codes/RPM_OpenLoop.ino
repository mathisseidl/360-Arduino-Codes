// Open Loop RPM Monitor
volatile long int counter=0;
double w=0; // Angular velocity rpm
void setup() {
  // put your setup code here, to run once:
pinMode (2, INPUT);
pinMode (3, INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
attachInterrupt(digitalPinToInterrupt (2), myFunction, RISING);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (6,LOW);
analogWrite(5,127);
delay(500);
w=getSpeed(100);
Serial.println(w);
}
void myFunction () {
  if (digitalRead(3)==HIGH)
  counter++;
  else
  counter--;

}

double getSpeed(int milliseconds) {
  double th0=0, th1=0, velocity = 0;
  th0=counter / 240.0; // revolutions
  delay(milliseconds); // allow time to elapse
  th1=counter / 240.0; // revolutions 
  velocity= (th1-th0) / (milliseconds / 1000.0 / 60.0); // R.P.M
  return(velocity);
}
