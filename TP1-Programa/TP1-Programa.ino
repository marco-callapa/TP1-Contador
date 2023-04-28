//Delcaración de los pines de las teclas
byte tec1 = 8;
byte tec2 = 9;
byte disp1 = 10;
byte disp2 = 7;
int display7c[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

int i = 0; //Variable del contador for
int uni; //Variable que almacena la unidad 
int dec; //Variable que almacena la decena 
long vel = 50; //Velocidad para multeplexacion
byte valor; //Almacena el dato de los pulsadores

void setup() {
  // put your setup code here, to run once:
  //Configura el display como salida
  DDRD = 1;
  // Configura los PINES 30 y 31 como entradas
  pinMode(tec1,INPUT);
  pinMode(tec2,INPUT);
  // Configura los pines 10 y 7 como salidas
  pinMode(disp1,OUTPUT);
  pinMode(disp1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTD = 0;
  if(digitalRead(tec1)){
    delay(vel);

    valor = 1; //Cambia el valor 
    }
  if(digitalRead(tec2)){
    delay(vel);
    valor = 0; //Cambia el valor 
  }
  if(valor == 1){ 
    i++;
    if(i<9){
      digitalWrite(disp1,HIGH); //Energiza la SALIDA DIGITAL (5V)
      PORTB = display7c[i];
    }
    if(i> 9){
      dec = i/10;
      uni = i%10;

      digitalWrite(disp2,HIGH); //Energiza la SALIDA DIGITAL (5V)
      PORTB = display7c[dec];
      delay(vel);
      digitalWrite(disp2,LOW); //Desenergiza la SALIDA DIGITAL (5V)
      digitalWrite(disp1,HIGH); //Energiza la SALIDA DIGITAL (5V)
      PORTB = display7c[uni];
    }
    
    }
  if(valor == 0){ 
    i--;
    if(i<9){
      digitalWrite(disp1,HIGH); //Energiza la SALIDA DIGITAL (5V)
      PORTB = display7c[i];
    }
    if(i> 9){
      dec = i/10;
      uni = i%10;

      digitalWrite(disp2,HIGH); //Energiza la SALIDA DIGITAL (5V)
      PORTB = display7c[dec];
      delay(vel);
      digitalWrite(disp2,LOW); //Desenergiza la SALIDA DIGITAL (5V)
      digitalWrite(disp1,HIGH); //Energiza la SALIDA DIGITAL (5V)
      PORTB = display7c[uni];
    }
    
    }

}
