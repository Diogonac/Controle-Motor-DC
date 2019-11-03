// Autor: Diogo Nobre de Araujo Cintra
// Graduacao: Engenharia Mecanica
// Instituicao: Insper

int PinoVelocidade = A0; //INPUT DO POTENCIOMETRO 
int OUTPWM = 3; //OUTPUT PARA CONTROLE DE VELOCIDADE 
int Entrada1 = 2; //OUTPUT PARA PONTE H
int Entrada2 = 7; //OUTPUT PARA PONTE H
int saida; //VARIAVEL PARA CONTROLE DE VELOCIADADE
int inverter = 5; //PINO PARA INVERTER O SENTIDO DO MOTOR 
int estado; //VARIAVEL PARA LEITURA DO BOTAO
int velocidade; //VARIAVEL PARA LEITURA DO POTENCIOMETRO
void setup()
{
  //DEFINE OS PINOS DE INPUT
  pinMode(PinoVelocidade, INPUT);
  pinMode(inverter, INPUT);

  //DEFINE OS PINOS DE OUTPUT
  pinMode(OUTPWM, OUTPUT);
  pinMode(Entrada1, OUTPUT);
  pinMode(Entrada2, OUTPUT);
}

void loop()
{
  estado = digitalRead(inverter); //LE O ESTADO DO BOTAO
  velocidade = analogRead(PinoVelocidade); //LE O SINAL DO POTENCIOMETRO
  
  saida = map(velocidade, 0, 1023, 0, 255); //FUNCAO PARA DEFINIR A VELOCIADE DO MOTOR
  analogWrite(OUTPWM, saida);// OUTPUT DA VELOCIDADE 

  //ACIONAMENTO DO MOTOR
  if (estado == 0) {
    digitalWrite(Entrada1, HIGH);
    digitalWrite(Entrada2, LOW);
  }
  else {
    digitalWrite(Entrada1, LOW);
    digitalWrite(Entrada2, HIGH);
  }
}
