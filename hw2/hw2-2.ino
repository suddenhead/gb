void setup() {
  Serial.begin(9600);
}


float real_val = 0;

void loop() {

  int new_val = analogRead(A0);
  real_val += (new_val - real_val)*0.1;
 

  // 285-973
  int val = map(real_val, 285, 973, 0, 10);
  constrain(val, 0, 10);
  Serial.println(val);
}
