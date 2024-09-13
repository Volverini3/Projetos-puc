#include "RTClib.h"

RTC_DS1307 rtc;

// Definição dos pinos para as lâmpadas RGB
const int Lampada0_R = 9;   // Pino do componente vermelho da lâmpada 1
const int Lampada0_G = 10;  // Pino do componente verde da lâmpada 1
const int Lampada0_B = 11;  // Pino do componente azul da lâmpada 1

const int Lampada1_R = 6;  // Pino do componente vermelho da lâmpada 2
const int Lampada1_G = 7;  // Pino do componente verde da lâmpada 2
const int Lampada1_B = 8;  // Pino do componente azul da lâmpada 2

const int Lampada2_R = 3;  // Pino do componente vermelho da lâmpada 3
const int Lampada2_G = 4;  // Pino do componente verde da lâmpada 3
const int Lampada2_B = 5;  // Pino do componente azul da lâmpada 3

const int Lampada3_R = A1;  // Pino do componente vermelho da lâmpada 4
const int Lampada3_G = A2;  // Pino do componente verde da lâmpada 4
const int Lampada3_B = 2;   // Pino do componente azul da lâmpada 4

const int Lampada4_R = 12;  // Pino do componente vermelho da lâmpada 5
const int Lampada4_G = 13;  // Pino do componente verde da lâmpada 5
const int Lampada4_B = A0;  // Pino do componente azul da lâmpada 5

int Fibonacci[3][5];

//Manipulacao do hardware
void acenderRelogio(int L[3][5]);
void acendeLampada(int linha, int coluna);
void apagarRelogio();

//Construcao da matriz
void funcionarFClock(int L[3][5]);
void construirFClock(int horas, int min, int L[3][5]);
void mostrarHoras(int F[3][5]);

//Manipulacao da matriz
void criarRelogioHoraZero(int F[3][5]);
void LightA_OffRG(int F[3][5]);
void LimparAzul(int F[3][5]);
void AcendeLinhaVerde(int F[3][5]);
void ApagaLinhaVerde(int F[3][5]);
void AcendeLinhaVermelha(int F[3][5]);
int calcularVerde(int F[3][5]);
int calcularVermelho(int F[3][5]);
void VermelhoMudaPara1Hr(int F[3][5]);
void Aumentar1UniVerde(int F[3][5]);
void Aumentar1UniVermelho(int F[3][5]);

void setup() {
  pinMode(Lampada0_R, OUTPUT);
  pinMode(Lampada0_G, OUTPUT);
  pinMode(Lampada0_B, OUTPUT);
  pinMode(Lampada1_R, OUTPUT);
  pinMode(Lampada1_G, OUTPUT);
  pinMode(Lampada1_B, OUTPUT);
  pinMode(Lampada2_R, OUTPUT);
  pinMode(Lampada2_G, OUTPUT);
  pinMode(Lampada2_B, OUTPUT);
  pinMode(Lampada3_R, OUTPUT);
  pinMode(Lampada3_G, OUTPUT);
  pinMode(Lampada3_B, OUTPUT);
  pinMode(Lampada4_R, OUTPUT);
  pinMode(Lampada4_G, OUTPUT);
  pinMode(Lampada4_B, OUTPUT);
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  DateTime now = rtc.now();
  int horas = now.hour();
  int min = now.minute();
  construirFClock(horas, min, Fibonacci);
  horas = calcularVermelho(Fibonacci);
  min = calcularVerde(Fibonacci)*5;
  String message = String(horas) + " horas e " + String(min) + " minutos";
  Serial.println(message);
  mostrarHoras(Fibonacci);
  acenderRelogio(Fibonacci);
  if(rtc.now().minute() % 5 == 0) {
    delay(300000-(rtc.now().second())*1000);
  }
  else {
    do {
      delay(1000); 
    }while(rtc.now().minute() % 5 != 0);
  }
}

void loop() {	
  int horas;
  int min;
  funcionarFClock(Fibonacci);
  horas = calcularVermelho(Fibonacci);
  min = calcularVerde(Fibonacci)*5;
  String message = String(horas) + " horas e " + String(min) + " minutos";
  Serial.println(message);
  mostrarHoras(Fibonacci);
  acenderRelogio(Fibonacci);
  delay(300000);
}

//Funcoes--------------------------------------------------------

void funcionarFClock(int L[3][5]) {
    apagarRelogio();
    int Verde = calcularVerde(L);
    int Vermelho = calcularVermelho(L);
    LimparAzul(L);

    if (Verde == 11) {
      ApagaLinhaVerde(L);
      if (Vermelho == 12)
        VermelhoMudaPara1Hr(L);
      else
        Aumentar1UniVermelho(L);
    } else
      Aumentar1UniVerde(L);

    LightA_OffRG(L);
}

void acenderRelogio(int L[3][5]) {
  int linha = 0;
  int coluna = 0;
  while (coluna < 5) {
    linha = 0;
    while (linha < 3 && L[linha][coluna] != 1) {
      linha++;
    }
    if (L[linha][coluna] == 1) {
      acendeLampada(linha, coluna);
    }
    coluna++;
  }
}
void acendeLampada(int linha, int coluna) {  //Acende o LED conforme a cor da Linha

  int pin_R;
  int pin_G;
  int pin_B;
  switch (coluna) {
    case 0:
      pin_R = Lampada0_R;
      pin_G = Lampada0_G;
      pin_B = Lampada0_B;
      break;

    case 1:
      pin_R = Lampada1_R;
      pin_G = Lampada1_G;
      pin_B = Lampada1_B;
      break;

    case 2:
      pin_R = Lampada2_R;
      pin_G = Lampada2_G;
      pin_B = Lampada2_B;
      break;

    case 3:
      pin_R = Lampada3_R;
      pin_G = Lampada3_G;
      pin_B = Lampada3_B;
      break;

    case 4:
      pin_R = Lampada4_R;
      pin_G = Lampada4_G;
      pin_B = Lampada4_B;
      break;
  }

  switch (linha) {
    case 0:  // Azul escuro
      analogWrite(pin_R, 0);
      analogWrite(pin_G, 0);
      analogWrite(pin_B, 255);
      break;

    case 1:  // Vermelho
      analogWrite(pin_R, 255);
      analogWrite(pin_G, 0);
      analogWrite(pin_B, 0);
      break;

    case 2:  // Verde
      analogWrite(pin_R, 0);
      analogWrite(pin_G, 255);
      analogWrite(pin_B, 0);
      break;
  }
}

void apagarRelogio() {
  analogWrite(Lampada0_R, 0);
  analogWrite(Lampada0_G, 0);
  analogWrite(Lampada0_B, 0);

  analogWrite(Lampada1_R, 0);
  analogWrite(Lampada1_G, 0);
  analogWrite(Lampada1_B, 0);

  analogWrite(Lampada2_R, 0);
  analogWrite(Lampada2_G, 0);
  analogWrite(Lampada2_B, 0);

  analogWrite(Lampada3_R, 0);
  analogWrite(Lampada3_G, 0);
  analogWrite(Lampada3_B, 0);

  analogWrite(Lampada4_R, 0);
  analogWrite(Lampada4_G, 0);
  analogWrite(Lampada4_B, 0);
}
void construirFClock(int horas, int min, int L[3][5]) {  //Realiza a construcao inicial da matriz do relogio (provavelmente entra em void setup())
  int R, Q;
  int a, b, c, x;
  criarRelogioHoraZero(L);  //Inicia relogio com zeros
  if (min != 0) {
    R = min % 60;
    Q = min / 60;
    if (Q > 0)
      horas = horas + 1;
    min = R / 5;
  }

  if (horas != 0) {
    R = horas % 12;
    if (R == 0)
      horas = 12;

    else
      horas = R;
  }

  if (min == 11) {
    AcendeLinhaVerde(L);
  }

  else if (min != 0) {
    a = 13;
    b = 8;
    x = min;
    do {
      c = a - b;
      if (x >= c) {
        x = x - c;
        if (c == 5) {
          L[2][c - 1] = 1;
        } else {
          L[2][c] = 1;
        }
      }
      a = b;
      b = c;
    } while (x != 0);
  }

  if (horas == 12) {
    AcendeLinhaVermelha(L);
  } else if (horas != 0) {
    a = 13;
    b = 8;
    x = horas;
    do {
      c = a - b;
      if (x >= c) {
        x = x - c;
        if (c == 1 || c == 5) {
          L[1][c - 1] = 1;
        } else {
          L[1][c] = 1;
        }
      }
      a = b;
      b = c;
    } while (x != 0);
  }

  LightA_OffRG(L);
}

void mostrarHoras(int F[3][5]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      Serial.print(F[i][j]);
      Serial.print("\t");  // Adiciona uma tabulação para separar os elementos
    }
    Serial.print("\n");  // Pula para a próxima linha após imprimir uma linha completa
  }
  Serial.print("\n");
}

void criarRelogioHoraZero(int F[3][5]) {
  for (int j = 0; j <= 2; j++)
    for (int k = 0; k <= 4; k++)
      F[j][k] = 0;
}

void LightA_OffRG(int F[3][5]) {  //Acende Azul de uma coluna e apaga vermelho e verde
  for (int j = 1; j <= 4; j++)
    if ((F[1][j] == 1) && (F[2][j] == 1)) {
      F[0][j] = 1;
      F[1][j] = 0;
      F[2][j] = 0;
    } else
      F[0][j] = 0;
}
void LimparAzul(int F[3][5]) {  //Deve limpar o azul de uma coluna se ele estiver aceso e acender o verde e vermelho
  for (int j = 1; j <= 4; j++)
    if (F[0][j] == 1) {
      F[0][j] = 0;
      F[1][j] = 1;
      F[2][j] = 1;
    }
}

void AcendeLinhaVerde(int F[3][5]) {
  for (int j = 1; j <= 4; j++) {
    F[2][j] = 1;
  }
}

void ApagaLinhaVerde(int F[3][5]) {
  for (int j = 1; j <= 4; j++) {
    F[2][j] = 0;
  }
}

void AcendeLinhaVermelha(int F[3][5]) {
  for (int j = 0; j <= 4; j++) {
    F[1][j] = 1;
  }
}

int calcularVerde(int F[3][5]) {  //Determina o valor de verde para verificar se nao chegou em seu limite (11)
  int P[] = { 1, 1, 2, 3, 5 };
  int Verde = 0;
  int j;
  for (int i = 0; i <= 1; i++) {
    j = 2 * i;
    for (int k = 0; k <= 4; k++)
      Verde = Verde + F[j][k] * P[k];
  }
  return Verde;
}

int calcularVermelho(int F[3][5]) {  //Determina o valor de vermelho para verificar se nao chegou em seu limite (12)
  int P[] = { 1, 1, 2, 3, 5 };
  int Vermelho = 0;
  for (int i = 0; i <= 1; i++) {
    for (int k = 0; k <= 4; k++)
      Vermelho = Vermelho + F[i][k] * P[k];
  }
  return Vermelho;
}

void VermelhoMudaPara1Hr(int F[3][5]) {  //Quando vermelho atinge o limite, reseta a linha vermelha (1 0 0 0 0)
  F[1][0] = 1;
  for (int j = 1; j <= 4; j++)
    F[1][j] = 0;
}
void Aumentar1UniVerde(int F[3][5]) {  //Determina o aumento de 1 unidade de verde na tabela de acordo com os pesos de cada coluna
  if (F[2][1] == 0)
    F[2][1] = 1;

  else if (F[2][2] == 0) {
    F[2][1] = 0;
    F[2][2] = 1;
  }

  else if (F[2][3] == 0) {
    F[2][2] = 0;
    F[2][3] = 1;
  }

  else {
    F[2][1] = 0;
    F[2][3] = 0;
    F[2][4] = 1;
  }
}

void Aumentar1UniVermelho(int F[3][5]) {  //Determina o aumento de 1 unidade de vermelho na tabela de acordo com os pesos de cada coluna
  if (F[1][0] == 0)
    F[1][0] = 1;

  else if (F[1][2] == 0) {
    F[1][0] = 0;
    F[1][2] = 1;
  }

  else if (F[1][3] == 0) {
    F[1][2] = 0;
    F[1][3] = 1;
  }

  else if (F[1][4] == 0) {
    F[1][0] = 0;
    F[1][3] = 0;
    F[1][4] = 1;
  }

  else {
    F[1][1] = 1;
  }
}
