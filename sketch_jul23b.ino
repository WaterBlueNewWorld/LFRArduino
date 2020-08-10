#include <NewPing.h> //https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home

#define luzPin A0 
int M1_Izq = 12; 
int M1_Derecha = 11;
int M2_Izq = 8;
int M2_Derecha = 9;
const int Trigger = 6;
const int Echo = 5;
const int MaxDistancia = 200;

NewPing sonar(Trigger, Echo, MaxDistancia);

//Setup
void setup()
{
  Serial.begin(9600);
  pinMode(luzPin, INPUT);
  delay(1000);
  
  pinMode(M1_Izq, OUTPUT);
  pinMode(M1_Derecha, OUTPUT);
  pinMode(M2_Izq, OUTPUT);
  pinMode(M2_Derecha, OUTPUT);
}

void loop(){
  res = Serial.read();
  if (res == '10')
  {
    adelante();
  }
   if (res == '11')
  {
    reversa();
  }
   if (res == '12')
  {
    giroIzquierda();
  }
   if (res == '13')
  {
    giroDerecha();
  }

  avanzar ();
  delay(250); 
}

void avanzar()
{ 
  
  
  
  int intensidad;
  intensidad = analogRead(luzPin);
  Serial.println(intensidad);
  

  if(intensidad > 800){
    Serial.println("Encendido");
  
    //If de distancia si es mayor a 10 cm e igual a 0
    
    if(sonar.ping_cm(MaxDistancia) > 10 || sonar.ping_cm(MaxDistancia) == 0 ){
      
      adelante ();
      Serial.println(sonar.ping_cm(MaxDistancia));
    }else{
        stop();
        delay(2000);
        
        reversa ();
      }
   
  }else{
    stop();
   }
    
}



void stop(){
    digitalWrite(M1_Izq, LOW);
    digitalWrite(M1_Derecha, LOW);
    digitalWrite(M2_Izq, LOW);
    digitalWrite(M2_Derecha, LOW);
}

void reversa(){
    digitalWrite(M1_Izq, LOW);
    digitalWrite(M1_Derecha, HIGH);
    digitalWrite(M2_Izq, LOW);
    digitalWrite(M2_Derecha, HIGH);
}

void adelante(){
    digitalWrite(M1_Izq, HIGH);
    digitalWrite(M1_Derecha, LOW);
    digitalWrite(M2_Izq, HIGH);
    digitalWrite(M2_Derecha, LOW);
}

void giroDerecha(){
    digitalWrite(M1_Izq, HIGH);
    digitalWrite(M1_Derecha, LOW);
    digitalWrite(M2_Izq, LOW);
    digitalWrite(M2_Derecha, HIGH);
}

void giroIzquierda(){
    digitalWrite(M1_Izq, LOW);
    digitalWrite(M1_Derecha, HIGH);
    digitalWrite(M2_Izq, HIGH);
    digitalWrite(M2_Derecha, LOW);
}
