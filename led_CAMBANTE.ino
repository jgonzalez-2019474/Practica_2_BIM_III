#define potenciometro A0
#define LED_pro 6

int luminosidad;
int posicion;

void setup()
{
  pinMode(potenciometro, INPUT);
  pinMode(LED_pro, OUTPUT);
}
void loop()
{
  luminosidad = analogRead(potenciometro);
  posicion = map(luminosidad, 0, 1023, 0, 255);
  analogWrite(LED_pro, posicion);
}
