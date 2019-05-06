const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
int ledPin =(13); // Add the onboard LED on pin 13.
char DATO_0;
int TIME=500;
int i1 = 5;//Salidas para el motor1
int i2 = 6;//Salida para motor1
int i3 = 10;//Salida para motor2
int i4 = 11;//Salida para motor2
int pwm_izq = 7;
int pwm_der = 8;
int timeAvance = 100;
int velocidad = 175;
int velocidadizq = 158;
void setup() {
   Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode(i1, OUTPUT); 
  pinMode(i2, OUTPUT); 
  pinMode(i3, OUTPUT); 
  pinMode(i4, OUTPUT);
 }
void loop() {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
   t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);  
if(d <=30) // If the sensor detects an obstacle less than 30 cm in distance, the LED will start to blink.
{
digitalWrite (ledPin, HIGH);
delay(50);
}
if(d >=30)// If no obstacle is there within 30 cm, the Led should turn off.
{
digitalWrite (ledPin, LOW);
delay(50);
}
   velocidad = constrain(velocidad, 125, 255);
  velocidadizq = velocidad * 0.92;
  analogWrite(pwm_izq,velocidadizq);
  analogWrite(pwm_der,velocidad);
  if (Serial1.available()){
    DATO_0= Serial1.read();
      switch (DATO_0){
    case 0x41:
        forward();
        if(d <=30) // If the sensor detects an obstacle less than 30 cm in distance, the LED will start to blink.
{
digitalWrite (ledPin, HIGH);
delay(3000);
}
        delay(timeAvance);
        break;
    case 0x42:
        backward();
        delay(timeAvance);
        break;
     case 0x43:
       turn_left();
        delay(timeAvance);
        break;
    case 0x44:
        turn_right();
        delay(timeAvance);
        break;
    case 0x45:
        velocidad = velocidad + 10;
        break;
    case 0x46:
        velocidad = velocidad - 10;
        break;
  }
  }
  else{
    Detener();
    delay(timeAvance);
  }
}
void backward(){
  Serial.println("Retroceso-recto...");
  digitalWrite(i1,LOW); 
  digitalWrite(i2,HIGH); 
  digitalWrite(i3,LOW); 
  digitalWrite(i4,HIGH); 
 
 }
 void forward(){
  Serial.println("Avance-recto...");
  digitalWrite(i1,HIGH); 
  digitalWrite(i2,LOW); 
  digitalWrite(i3,HIGH); 
  digitalWrite(i4,LOW); 
   }
void Detener(){
  Serial.print("Parada...  ");
  Serial.println(velocidad);
  digitalWrite(i1,LOW); 
  digitalWrite(i2,LOW); 
  digitalWrite(i3,LOW); 
  digitalWrite(i4,LOW);
  }

void turn_left() {
  Serial.println("GiroIzquierda...");
  digitalWrite(i1,HIGH); 
  digitalWrite(i2,LOW); 
  digitalWrite(i3,LOW); 
  digitalWrite(i4,LOW);
}

void turn_right(){
  Serial.println("GiroDerecha...");
  digitalWrite(i1,LOW); 
  digitalWrite(i2,LOW); 
  digitalWrite(i3,HIGH); 
  digitalWrite(i4,LOW);
}
