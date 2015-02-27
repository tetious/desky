int desk_switch = D4;
int deskState = 0;

void setup() {
  pinMode(desk_switch, INPUT_PULLUP);
  Spark.variable("desk-state", &deskState, INT);
}

void loop() {
  int newDeskState = digitalRead(desk_switch);
  if(newDeskState != deskState)
  {
    Spark.publish("desk-state-change", String(newDeskState));
    deskState = newDeskState;
  }

  delay(1000);
}
