const int botaoJogador1 = 6;
const int botaoJogador2 = 7;
const int ledJogador1 = 8;
const int ledJogador2 = 9;

bool jogador1Pressionado = false;
bool jogador2Pressionado = false;

void setup() {
  pinMode(botaoJogador1, INPUT_l);
  pinMode(botaoJogador2, INPUT);
  pinMode(ledJogador1, OUTPUT);
  pinMode(ledJogador2, OUTPUT);

  randomSeed(analogRead(0));
}

void loop() {
    jogador1Pressionado = false;
    jogador2Pressionado = false;
   digitalWrite(ledJogador1, LOW);
   digitalWrite(ledJogador2, LOW);

  if (digitalRead(botaoJogador1) == HIGH && !jogador2Pressionado) {
    jogador1Pressionado = true;
  }

  if (digitalRead(botaoJogador2) == HIGH && !jogador1Pressionado) {
    jogador2Pressionado = true;
  }

  if (jogador1Pressionado && jogador2Pressionado) {
    jogador1Pressionado = false;
    jogador2Pressionado = false;

    int numeroAleatorio = random(1, 3); 

    if (numeroAleatorio == 1) {
       jogador1Pressionado = true;
    } else {
      jogador2Pressionado = true;
    }
  }
If(jogador1Pressionado == true){
   digitalWrite(ledJogador1, HIGH);
}
If(jogador2Pressionado == true){
   digitalWrite(ledJogador2, HIGH);
}
delay(10000);
}
