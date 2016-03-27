const int pot0 = A0;
const int pot1 = A1;

int pot0value = 0;
int pot1value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot0value = analogRead(pot0);
  pot1value = analogRead(pot1);

  Serial.print(pot0value);
  Serial.print(",");
  Serial.println(pot1value);
}
