char DATO_0;
int TIME=500;
int i1 = 5;//Salidas para el motor1
int i2 = 6;//Salida para motor1
int i3 = 10;//Salida para motor2
int i4 = 11;//Salida para motor2
void setup() {
  Serial.begin(9600);
  pinMode(i1, OUTPUT); 
  pinMode(i2, OUTPUT); 
  pinMode(i3, OUTPUT); 
  pinMode(i4, OUTPUT);
 }
void loop() {
  if (Serial.available()){
    DATO_0= Serial.read();
    }
    switch (DATO_0){
    case 0x41:
        forward();
        delay(2000);
        stop();
        break;
    case 0x42:
        backward();
        delay(2000);
        stop();
        break;
     case 0x43:
       turn_left();
        delay(2000);
        stop();
        break;
    case 0x44:
        turn_right();
        delay(2000);
        stop();
        break;
  }
}
void backward(){
  Serial.println("Retroceso-recto...");
  digitalWrite(i1,HIGH); 
  digitalWrite(i2,LOW); 
  digitalWrite(i3,HIGH); 
  digitalWrite(i4,LOW); 
  }
 void forward(){
  Serial.println("Avance-recto...");
  digitalWrite(i1,LOW); 
  digitalWrite(i2,HIGH); 
  digitalWrite(i3,LOW); 
  digitalWrite(i4,HIGH); 
  }
void stop(){
  Serial.println("Parada...");
  digitalWrite(i1,HIGH); 
  digitalWrite(i2,HIGH); 
  digitalWrite(i3,HIGH); 
  digitalWrite(i4,HIGH);
  }
void turn_left() {
  Serial.println("GiroIzquierda...");
  digitalWrite(i1,LOW); 
  digitalWrite(i2,HIGH); 
  digitalWrite(i3,HIGH); 
  digitalWrite(i4,HIGH);
}
void turn_right(){
  Serial.println("GiroDerecha...");
  digitalWrite(i1,HIGH); 
  digitalWrite(i2,HIGH); 
  digitalWrite(i3,LOW); 
  digitalWrite(i4,HIGH);
}
