2)// Generate a two-way triangular velocity profile:
// 0-255 in 3s, 255-0 in 3s, 0-(-255) in 3s, (-255)-0 in 3s, 0 afterwards
void setup() {
Â  // put your setup code here, to run once:
Â  Serial.begin(9600);
}

float t=0;
int target=0;
unsigned long int t0=millis();

void loop() {
Â  t=float(millis()-t0)/1000;
Â  if (t<3)
Â  Â  target=int(255.0/3.0*t + 0);
Â  else if (t<6)
Â  Â  target=int(-255.0/3.0*t + 510);
Â  else if (t<9)
Â  Â  target=int(-255.0/3.0*t + 510);
Â  else if (t<12)
Â  Â  target=int(255.0/3.0*t - 1020);
Â  else if (t<15)
Â  Â  target=0;
Â  else
Â  Â  t0=millis(); Â 

Â  Serial.println(target);
Â  delay(50);
}
