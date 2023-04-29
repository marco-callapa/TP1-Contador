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
byte valor; //Almacena el dato de los pulsadores
int num = 0;  //Variable que almacena el numero a mostrar                   
int unid; //Variable que almacena la unidad 
int dec;  //Variable que almacena la decena 
//Delcaración de Los pines del display
byte a=2;
byte b=3;
byte c=4;
byte d=5;
byte e=6;
byte f=7;
byte g=8;
//Delcaración de los pines de control
byte disp1 = 9;
byte disp2 = 10;
//Delcaración de los pines de las teclas
byte tec1 = 11;
byte tec2 = 12;
//Función que coloca en el puerto de salida los bits comenzando
// desde el pin ini hasta el pin fin
void puerto(int bits,int ini,int fin){
  for(int i=ini;i<=fin;i++)
  {
    digitalWrite(i,bitRead(bits,i-ini));
  }
}
//Función encargada de la multiplexación
void mostrar(int num) //Rutina mostrar
{
  if (num<=9){
    digitalWrite(disp1,HIGH); //Energiza la SALIDA DIGITAL (5V)
      puerto(i,2,8);
  }
  else{
    dec  = num/10;
    unid = num%10;
    //Rutina de Multiplexación
    digitalWrite(disp1,HIGH);  //Enciende el display de decena
    puerto(display7c[dec],2,8); //Envia la decena al display 1
    delay(1);               //Retardo de 1 milisegundos
    digitalWrite(disp1,LOW);  //Apaga el display de decena
    digitalWrite(disp1,HIGH);  //Enciende el display de unidades
    puerto(display7c[unid],2,8); ////Envia la unidad al display 2
    delay(1);               //Retardo de 1 milisegundos
    digitalWrite(disp2,LOW);   //Apaga el display de unidades
  }                  
}

void setup() {
  //Configura los pines del display como salida
  for(int i=a;i<=disp2;i++){
    pinMode(i,OUTPUT);
  }
  // Configura los PINES 30 y 31 como entradas
  pinMode(tec1,INPUT);
  pinMode(tec2,INPUT);
}

void loop() {
  if(digitalRead(tec1)){
    delay(1);
    valor = 1; //Cambia el valor 
    }

  if(digitalRead(tec2)){
    delay(1);
    valor = 0; //Cambia el valor 
  }

  if(valor == 1){ 
    num ++;
    mostrar(num);
    }
  else{ 
    // num --;        
    mostrar(num);
    }
    
}
