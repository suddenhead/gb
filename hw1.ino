int cur_val, prev_val;

void setup() {
  // LED
  pinMode(13, OUTPUT);
  // buttons
  pinMode(2, INPUT); // external pulldown
  pinMode(3, INPUT); // external pullup
  pinMode(4, INPUT_PULLUP); // internal pullup
  pinMode(5, INPUT_PULLUP); // software debounce
}

void loop() {

  cur_val = digitalRead(5);

  if (cur_val != prev_val) {
    delay(50);
    cur_val = digitalRead(5);
  }

  prev_val = cur_val;
 
  if (cur_val == LOW) {
    digitalWrite(13, HIGH);  
  } else if (digitalRead(2) == HIGH ||
             digitalRead(3) == LOW ||
             digitalRead(4) == LOW) {
    digitalWrite(13, HIGH);
  } else if (cur_val == HIGH) {
    digitalWrite(13, LOW);
  } else {          
    digitalWrite(13, LOW);
  }
   
}
