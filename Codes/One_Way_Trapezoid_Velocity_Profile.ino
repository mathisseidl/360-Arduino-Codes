1)// Generate a one-way trapezoid velocity profile. 0-100 RPM in 5 second, for 5-10 second, RPM=100, for 10 to 15 second, RPM goes from 100 to 0.
void setup() {
Â  // put your setup code here, to run once:
Â  Serial.begin(9600);
}

float t=0;
int target=0;
unsigned long int t0=millis();

void loop() {
Â  t=(double(millis())-t0)*1E-3;

  // Define target as a function of time
  if (t<5.0)
    target=100.0/5.0*t;
  else if ( (t>=5.0) & (t<10.0) )
    target=100;
  else
    target=300.0-100.0/5.0*t;   
Â 

Â  Serial.println(target);
Â  delay(50);
}
