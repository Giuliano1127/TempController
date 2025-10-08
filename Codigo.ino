#include <LiquidCrystal_I2C.h> // biblioteca LCD com interface I2C
#include <Servo.h> // biblioteca de servo

#define I2C_ADDR    0x27 // endereço do display 
#define LCD_COLUMNS 16 //definição de colunas
#define LCD_LINES   2 //definição de linhas

//objeto lcd com os parametros definidos.
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
//objeto do servo 
Servo meuservo;

//parâmetros de funções
void configuraMotor();
void iniciaLCD();
void acionaMotor();
float configuraNTC();

//variáveis globais.
const float BETA = 3950;
float exibe = 0;
int pos = 0;

void setup() {
  iniciaLCD();
  configuraMotor();
}

void loop() {
  exibe = configuraNTC(); // atribui temperatura a variável exibe.

  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  lcd.setCursor(0,1);
  lcd.print(exibe,1);
  lcd.print(" C");

  acionaMotor();
  delay(500); // reduz o bloqueio e suaviza atualização
}

void iniciaLCD(){
  //função que inicia LCD
  lcd.init();
  lcd.backlight();
}

float configuraNTC(){
  //função que configura NTC e retorna valor da temperatura.
  int analogValue = analogRead(A3);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  delay(500);
  return celsius; // retorna o calculo do NTC
}

void configuraMotor(){
  //função define pino do servo
  meuservo.attach(3);
}

void acionaMotor(){
  //função liga servo de acordo com temperatura
  if(exibe>50){
    meuservo.write(180);
  }
  else{
    meuservo.write(0);
    }
  }
