int Botao1 = 6; //Define a Porta Do Botao 1
int Botao2 = 7; //Define a Porta Do Botao 2
int BotaoReset = 8; //Define a Porta Do Botao De Resetar
int Led1 = 9; //Define a Porta Do led Do Botao 1
int Led2 = 10; //Define a Porta Do led Do Botao 2
int Trava = 0; //Variavel Que Define Se Algum Botao Foi Clicado

unsigned long PiscaTime; //Variavel Que Guarda a Ultima Vez Que o Led Acesso Piscou
const unsigned long interval = 500; //Define o Intervalo Entre Cada Piscada do Led do Botao Clicado (Tempo Em Milisegundos, 1000ms = 1s)

void setup(){
  //Definiçoes De Modo Das Portas
  pinMode(Botao1, INPUT); 
  pinMode(Botao2, INPUT);
  pinMode(BotaoReset, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}
void loop(){
  //Pegando Status De Click Dos Botoes
  int Bt1 = digitalRead(Botao1);
  int Bt2 = digitalRead(Botao2);
  int Bt3 = digitalRead(BotaoReset);

  //Vendo Se Nenhum Botao Foi Clicado
  if(Trava == 0){
    //Vendo Se o Botao 1 Foi Clicado
    if(Bt1 == 1){
      //Definindo o Led Como Ligado e Definindo o Valor de "Trava" Com o Valor do Led
      digitalWrite(Led1, HIGH);
      Trava = Led1;
    }
    //Vendo Se o Botao 2 Foi Clicado
    if(Bt2 == 1){
      //Definindo o Led Como Ligado e Definindo o Valor de "Trava" Com o Valor do Led
      digitalWrite(Led2, HIGH);
      Trava = Led2;
    }   
    
  }else{//Caso Algum Botao Tenha Sido Clicado e o Valor da "Trava" Seja Diferente de 0
    
    //Ve a Ultima Vez Que o Led Piscou, Caso Tenha Passado o Delay Definido Ele Inverte o Sinal Do Led
    if (millis() - PiscaTime >= interval) {
      PiscaTime = millis();
      digitalWrite(Trava, !digitalRead(Trava));
    }

    //Vendo Se o Botao Reset Foi Clicado e Se "Trava" e Realmente Diferente de 0
    if((Bt3 == 1)&&(Trava != 0)){
      //Define Todos Os Leds Como Desligados e Volta "Trava" Para 0
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, LOW);
      Trava = 0;
    }   
  }
}

