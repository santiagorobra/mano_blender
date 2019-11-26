#include "HCPCA9685.h"

#define I2CAdd 0x40

#define flexMenor A2
#define flexAnular A3
#define flexMedio A6
#define flexIndice A1
#define flexPulgar A7

int ServoMenor;
int ServoAnular;
int ServoMedio;
int ServoIndice;
int ServoPulgar;

HCPCA9685 HCPCA9685(I2CAdd);

void setup() 
{
Serial.begin(115200);
Serial.flush(); 
HCPCA9685.Init(SERVO_MODE);

HCPCA9685.Sleep(false);
}


void loop() 
{
int val1Menor = analogRead(flexMenor);
int val1Anular = analogRead(flexAnular);
int val1Medio = analogRead(flexMedio);
int val1Indice = analogRead(flexIndice);
int val1Pulgar = analogRead(flexPulgar);

ServoMenor = map(val1Menor, 266, 607, 180, 0);

ServoAnular = map(val1Anular, 327, 594, 180, 0);
//ServoAnular = map(val1Anular, 0, 1023, 10, 420);

ServoMedio = map(val1Medio, 248, 499, 180, 0);
//ServoMedio = map(val1Medio, 0, 1023, 10, 420);

ServoIndice = map(val1Indice, 159, 465, 180, 0);

ServoPulgar = map(val1Pulgar, 138, 403, 180, 0);

Serial.print(ServoMenor);    // The values are sent via the Tx pin (the digital pin 1)
Serial.print(",");
Serial.print(ServoAnular); 
Serial.print(","); 
Serial.print(ServoMedio);
Serial.print(",");  
Serial.print(ServoIndice);
Serial.print(",");
Serial.print(ServoPulgar);
Serial.println("");

HCPCA9685.Servo(0, ServoMenor);
HCPCA9685.Servo(4, ServoAnular);
HCPCA9685.Servo(8, ServoMedio);
HCPCA9685.Servo(12, ServoIndice);
HCPCA9685.Servo(15, ServoPulgar);
delay(1);
}
