// Programa : Detector de cores usando modulo TCS230  
// Baseado no programa original de Martin Mason  
   
//Pinos de conexao do modulo TCS230 

//Sensores da Esquerda
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;    
    

//Sensores da Direita
const int s0d = 8;  
const int s1d = 9;  
const int s2d = 12;  
const int s3d = 11;  
const int outd = 10;    
    

//Variaveis que armazenam o valor das cores  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  

  //sensores da esquerda
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT); 

  //sensores da direita
  pinMode(s0d, OUTPUT);  
  pinMode(s1d, OUTPUT);  
  pinMode(s2d, OUTPUT);  
  pinMode(s3d, OUTPUT);  
  pinMode(out, INPUT);  

  Serial.begin(9600);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, LOW);

}  

//VOID LOOP

void loop(){

  esquerda(); //Chama o teste pra esquerda
  direita(); //Chama o teste pra direita


}


//ESQUERDA

void esquerda() 
{  

  coloresq(); //Chama a rotina que le as cores  

  //Mostra no serial monitor os valores detectados  
  Serial.print("Vermelho :");  
  Serial.print(red, DEC);  
  Serial.print(" Verde : ");  
  Serial.print(green, DEC);  
  Serial.print(" Azul : ");  
  Serial.print(blue, DEC);  
  Serial.println();  


  //Verifica se a cor verde foi detectada  
  if (green < red && green < blue){  

   Serial.println("Virar para a esquerda");  
  
  }  

  else{

  Serial.println();  

  //Aguarda 2 segundos, apaga os leds e reinicia o processo  
  delay(2000);    

  }

}  


void coloresq(){   //Rotina que le o valor das cores  

  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);


}


//DIREITA


void direita() 
{  

  colordir(); //Chama a rotina que le as cores  

  //Mostra no serial monitor os valores detectados  
  Serial.print("Vermelho :");  
  Serial.print(red, DEC);  
  Serial.print(" Verde : ");  
  Serial.print(green, DEC);  
  Serial.print(" Azul : ");  
  Serial.print(blue, DEC);  
  Serial.println();  


  //Verifica se a cor verde foi detectada  
  if (green < red && green < blue){  

   Serial.println("Virar para a direita");  
  
  }  

  else{

  Serial.println();  

  //Aguarda 2 segundos, apaga os leds e reinicia o processo  
  delay(2000);    

  }

}  


void colordir(){   //Rotina que le o valor das cores  

  digitalWrite(s2d, LOW);  
  digitalWrite(s3d, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(outd, digitalRead(outd) == HIGH ? LOW : HIGH);  
  digitalWrite(s3d, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(outd, digitalRead(outd) == HIGH ? LOW : HIGH);  
  digitalWrite(s2d, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(outd, digitalRead(outd) == HIGH ? LOW : HIGH);


}

