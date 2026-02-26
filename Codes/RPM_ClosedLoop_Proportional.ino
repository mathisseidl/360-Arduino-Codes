// Closed Loop RPM Monitor ~ PROPORTIONAL CONTROL

volatile long int counter=0;
double w=0; double wTarget=190; // Angular velocity rpm, constantly 190rpm even with slope

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), myFunction, RISING);
  Serial.begin(9600);
  digitalWrite(6, LOW);
}

double vout=0, error=0, kp=0.5;

void loop() {
  // put your main code here, to run repeatedly:
w=getSpeed(100);
error=wTarget-w;
vout=vout+kp*error; 

//if (vout>255)
//vout=255;
//else if(vout<0)
//vout=0;

analogWrite(5, int(vout));
delay(500);
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
