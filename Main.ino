int Botao1 = 6;
int Botao2 = 7;
int BotaoPause = 8;
int Led1 = 9;
int Led2 = 10;
bool Trava = false;

void setup(){
  pinMode(Botao1, INPUT);
  pinMode(Botao2, INPUT);
  pinMode(BotaoPause, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int I1 = digitalRead(Botao1);
  int I2 = digitalRead(Botao2);
  int I3 = digitalRead(BotaoPause);

  if(Trava == false){
    if(I1 == 1){
      digitalWrite(Led1, HIGH);
      Trava = true;
      Serial.println("1");
    }
    if(I2 == 1){
      digitalWrite(Led2, HIGH);
      Trava = true;
      Serial.println("2");
    }   
    
  }else{
    if((I3 == 1)&&(Trava == true)){
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      Trava = false;
      Serial.println("Resetado!");
    }   
  }
}


