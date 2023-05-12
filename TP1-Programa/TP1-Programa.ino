//Vector de valores de display
int display7c[10]= {0x3f, //Codigo del 0
                    0x06,
                    0x5b,
                    0x4f,
                    0x66,
                    0x6d,
                    0x7d,
                    0x07,
                    0x7f,
                    0x67}; //Codigo del 9 
int num = 95;  //Variable que almacena numuero a motstrar
int unid; //Variable que almacena la unidad 
int dec;  //Variable que almacena la decena 

//Declaración de Los pines del display
byte a=2; //Pin 2 de ARDUINO
byte b=3;
byte c=4;
byte d=5;
byte e=6;
byte f=7;
byte g=8; //Pin 8 de ARDUINO

//Delcaración de los pines de control
byte disp1 = 9;  // Pin 9 de ARDUINO
byte disp2 = 10; // Pin 10 de ARDUINO

//Delcaración de los pines de las teclas
byte tec1 = 11; // Pin 11 de ARDUINO, + +
byte tec2 = 12; // Pin 12 de ARDUINO, - -

//Función que coloca en el puerto de salida los bits comenzando
// desde el pin ini hasta el pin fin
void puerto(int bits,int ini,int fin){
  for(int i=ini;i<=fin;i++)
  {
    digitalWrite(i,bitRead(bits,i-ini));
  }
}

//Función encargada de la multiplexación
void mostrar() 
{
  unid = num % 10;
  dec  = num / 10;

  //Rutina de Multiplexación 
  digitalWrite(disp2,HIGH);  //Energiza el display de decena
  digitalWrite(disp1,LOW);   //Apaga la SALIDA DIGITAL (5V)
  puerto(display7c[dec],2,8); //Envia la decena al display 2
  delay(1);
  digitalWrite(disp2,LOW);  // Apaga el display de decena
  digitalWrite(disp1,HIGH); // Energiza la SALIDA DIGITAL (5V)
  puerto(display7c[unid],2,8); ////Envia la unidad al display 1
  delay(1);              
}

void setup() {
  //Configura los pines del display como salida
  for(int i=a; i<=disp2; i++){
    pinMode(i,OUTPUT);
  }
  // Configura los PINES 30 y 31 como entradas
  pinMode(tec1,INPUT);
  pinMode(tec2,INPUT);
}

void loop() {
  if(digitalRead(tec1) ==0){
    while (digitalRead(tec1) ==0){
      mostrar();
    }
    num = num +1;
    if (num > 99){
      num = 0;
    }
    }

  if(digitalRead(tec2) ==1){
    while (digitalRead(tec2) ==1){
      mostrar();
    }
    num = num -1;
    if (num <0){
      num = 99;
    }
    mostrar();
    }
    }
