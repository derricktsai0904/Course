

int speed = 20;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for(int i=8;i<=12;i++){ 
    pinMode(i,OUTPUT); 
  }
}

// the loop function runs over and over again forever
void loop() {
  for(int i=8;i<=12;i++){ 
      digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(speed);                       // wait for a second
      digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
      delay(speed);   
  }

  for(int i=12;i>=8;i--){ 
      digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(speed);                       // wait for a second
      digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
      delay(speed);   
  }

}
