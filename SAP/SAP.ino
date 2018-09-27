// <--------> Librerías/Bibliotecas <-------->
#include "LowPower.h"     //BIblioteca con funciones para el ahorro de energía en las placas Arduino (con microcontroladores ATMega)

// <--------> Asignación de Pines <-------->
#define SWITCH 3          //Pin para el ReedSwitch
#define BOCINA 5          //Pin para el Buzzer

void setup() {  
  pinMode(SWITCH, INPUT);
}

void loop() {
  
  while(digitalRead(SWITCH) == LOW)
    tone(BOCINA, 440);    //Prendemos el Buzzer con una frecuencia de 440 Hz  
  
  noTone(BOCINA);   //Apagamos el Buzzer
  attachInterrupt(digitalPinToInterrupt(SWITCH), despertarArduino, FALLING);  //Asignamos la interrupción para despertar el arduino cuando empiece a bajar el voltaje
  //attachInterrupt(digitalPinToInterrupt(SWITCH), despertarArduino, LOW);    //Asignamos la interrupción para despertar el arduino cuando el voltaje sea cero
  
  /*
   * El método powerDown de la clase LowPower, activa el ahorro de energía y es la de menor consumo de energía
   * SLEEP_FOREVER: Es el WatchDogTimer
   * ADC_OFF: Apaga los convertidores analógico a digital
   * BOD_OFF: Apaga el circuito Brown Out Detection, que es para detectar los niveles bajos de tensión (sirve para proteger los circuitos)
   */
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);

  //el detachInterrupt permite que la interrupción no vuelva a activarse 
  detachInterrupt(SWITCH);
}


// <--------> Interrupciones <-------->

/**
 * Método que omite el ahorro de energía, por medio de una interrupción, 
 */
void despertarArduino(){  //Manejador Interrupcion
}
