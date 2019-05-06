void setup() {
  // Comunicación seria a 9600 baudios
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop() {
  long tiempo=millis(); //tiempo antes de iniciar la lectura
  int D_cm=distancia(40); //lectura de distancia
  tiempo=millis()-tiempo; //milisegundos que duró la lectura
// Serial.print("Tiempo de lectura: ");
//  Serial.print(tiempo); 
//  Serial.print("ms  Distancia: ");
  Serial.println(D_cm);
//  Serial.println("  cm");
  delay(10);
}

float distancia(int n)
{
  long suma=0;
  for(int i=0;i<n;i++)
  {
    suma=suma+analogRead(A0);
  }  
  float adc=suma/n;
  float distancia_cm = 195113307100 * pow(adc, -4.395507946);
  return(distancia_cm); 
}
}
