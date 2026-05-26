#include <Servo.h>
#define pinServo 13

const int abre = 2;
const int fecha = 3;
int LED1 = 8;
int LED2 = 9;

Servo servo1;

bool portaoAberto = false;

// controle do pisca
unsigned long tempoAnterior = 0;
int estadoLED = 0;

void setup()

{
  servo1.attach(pinServo);

  pinMode(abre, INPUT);
  pinMode(fecha, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  servo1.write(180); // fechado

}
void loop()
{

  // ABRIR

  if (digitalRead(abre) == HIGH)
  {
    servo1.write(90);
    portaoAberto = true;
    delay(200);
  }

  // FECHAR

  if (digitalRead(fecha) == HIGH)
  {
    servo1.write(180);
    portaoAberto = false;

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  delay(200);
  }

  // Piscar LEDs enquanto aberto
  if (portaoAberto == true)
  {
    if (millis() - tempoAnterior >= 500)
    {
      tempoAnterior = millis();

      estadoLED = !estadoLED;

      digitalWrite(LED1, estadoLED);
      digitalWrite(LED2, !estadoLED);
    }
  }
} 
