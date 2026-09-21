#include <math.h>

const int pin_PWM = 18;

const int frec_PWM = 5000; 
const int resolucion = 8;      

const float frec_seno = 2.0;
const unsigned long intervalo = 5;

unsigned long tiempoAnterior = 0;

void setup() {

  Serial.begin(921600);
  ledcAttach(pin_PWM, frec_PWM, resolucion);

}

void loop() {

  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoAnterior >= intervalo) {

    tiempoAnterior = tiempoActual;

    float t = tiempoActual / 1000.0;
    float senoNormalizado = (sin(2.0 * PI * frec_seno * t) + 1.0) / 2.0;

    int duty = (int)(senoNormalizado * 255);

    ledcWrite(pin_PWM, duty);

    Serial.println(duty);
  }

}