/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Javier Andre Gonzalez Barrera
 * Carnet: 2019474
 * Proyecto: Practica #3
*/
#include <Ticker.h>

#define potenciometro A1
#define Red 7
#define Green 3
#define Blue 2  


int luminosidad;
int pos;
int pausa;
int tiempo();
void RGB();
void ISR_lec();

Ticker ISR_pausa(ISR_lec, 1);

void setup() 
{
  ISR_pausa.start();
  Serial.begin(9600);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(potenciometro, INPUT);
}

void loop() 
{
  RGB();
  ISR_pausa.update();
}

int tiempo()
{
  luminosidad = analogRead(potenciometro);
  pos = map(luminosidad, 0, 1023, 100, 1000);
  return pos;
}
 void ISR_lec()
 {
    pausa = tiempo();
    Serial.println(pausa);
 }
   
  void RGB()
{    
//    R: 174 G: 92 B: 230
    analogWrite(Red, 174);
    analogWrite(Green, 92);
    analogWrite(Blue, 230);
    delay(pausa);
    
    //    R: 255 G: 255 B: 255
    analogWrite(Red, 255);
    analogWrite(Green, 255);
    analogWrite(Blue, 255);
    delay(pausa);
    
     //    R: 0 G: 255 B: 255
    analogWrite(Red, 0);
    analogWrite(Green, 255);
    analogWrite(Blue, 255);
    delay(pausa);
    
     //   R: 189 G: 174 B: 20
    analogWrite(Red, 189);
    analogWrite(Green, 174);
    analogWrite(Blue, 20);
    delay(pausa);
    
    //    R: 225 G: 87 B: 35
    analogWrite(Red, 255);
    analogWrite(Green, 87);
    analogWrite(Blue, 35);
    delay(pausa);
    }
