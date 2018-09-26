

#define SWITCH 3
#define BOCINA 5

unsigned int frecuencias[] = {120, 240, 260, 240, 120};
byte CANTIDAD_TONOS = 5;
unsigned int DURACION_FRECUENCIAS = 5000; // = 5 segundos

void setup() {  
  pinMode(SWITCH, INPUT);
  //attachInterrupt(digitalPinToInterrupt(SWITCH), activarAlarma, FALLING);
  attachInterrupt(digitalPinToInterrupt(SWITCH), desactivarAlarma, RISING);
}

void loop() {
  
  reproducirAlarma();
}

void reproducirAlarma(){
  for(int i = 0; i < CANTIDAD_TONOS; i++){
    tone(BOCINA, CANTIDAD_TONOS);
    //delay(DURACION_FRECUENCIAS / frecuencias.length);
  }
}

void activarAlarma(){
  
}
void desactivarAlarma(){
  //dormir arduino cuando se cierra la puerta
  noTone(BOCINA);
  
}
