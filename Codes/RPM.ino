// Closed Loop RPM Monitor ~ DISPLACEMENT CONTROL

volatile long int count=0;
long int target=240, theta=0, theta0=0, error;
double kp=1.5;
int vout=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), myFunction, RISING);
  Serial.begin(9600);
  digitalWrite(6, LOW);
  theta0=count;
  
}

void loop() {
  if (error>0)
{
  vout=15+int(kp*error); //15 is added to overcome inertia and friction
  digitalWrite(6,LOW);
  analogWrite(5,vout);
}
  else if (error<0)
{
  vout=15-int(kp*error);; //15 is added to overcome the intertia and friction
  digitalWrite(5,LOW);
  analogWrite(6,vout);

}

theta=count-theta0; // In pulses
error=target-theta;
Serial.println(theta);
}

void myFunction () {
  if (digitalRead(3)==HIGH)
    count++;
  else
    count--;
}

double getSpeed(int milliseconds) {
  long int count0, count1;
  double theta0, theta1;
  double w;
  count0 = count;
  theta0=count0*15; // Degrees
  delay(100);
  count1=count;
  theta1=count1*1.5;
  w=(theta1=theta0)/0.1; // Degrees per second
  return(w/360.0*60.0); // R.P.M
}

