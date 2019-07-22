// electroSkin #nuncadejesdecreer
//DECLARAMOS TODOS LOS PINS
byte directionPin1 = 3;
byte stepPin1 = 2;
byte directionPin2 = 5;
byte stepPin2 = 4;
byte directionPin3 = 7;
byte stepPin3 = 6;
byte directionPin4 = 9;
byte stepPin4 = 8;
byte directionPin5 = 11;
byte stepPin5 = 10;


//declaramos variables del movimiento de motores
int numberOfSteps = 120;
byte ledPin = 13;
int pulseWidthMicros = 80;//icroseconds
//subir mislisbetweensteps p0ra bajar la velocidad
/*
pulsewitdhMicros subirlo
*/
int millisbetweenSteps =70;
/*
milliseconds - or try 1000 for slower steps

*/
#define ENABLE 12  // interruptor reset del driver

//puertas lógicas de estado del motor
bool puerta1 = false;
bool puerta2 = false;
bool puerta3 = false;
bool puerta4 = false;
bool puerta5 = false;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  pinMode(directionPin1, OUTPUT);
  pinMode(stepPin1, OUTPUT);
  pinMode(directionPin2, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(directionPin3, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(directionPin4, OUTPUT);
  pinMode(stepPin4, OUTPUT);
  pinMode(directionPin5, OUTPUT);
  pinMode(stepPin5, OUTPUT);

  digitalWrite (ENABLE, LOW);


  delay(2000);

}

void loop() {
  
  //Si comunicacion disponible-----leer estado del motor emitido por Processing
  while (Serial.available() == 0 );
  char motorstate = Serial.read();


/*Lista de carácteres;
m1 0_cerrar 1_abrir
m2 2_cerrar 3_abrir
m3 4_cerrar 5_abrir
m4 6_cerrar 7_abrir
m5 8_cerrar 9_abrir
*/

//MOTOR1
  if (motorstate == '0')//CERRAR MOTOR
  {
    if (puerta1 == true) {
      Serial.println("Motor1 is Closing");
      digitalWrite(ledPin, LOW);
      ////////////////////////////////////////////////AQUI EL CODIGO PARA CERRAR MOTOR 1

      digitalWrite(directionPin1, LOW);
      for (int n = 0; n < numberOfSteps*1.8; n++) {
        digitalWrite(stepPin1, HIGH);
        delayMicroseconds(pulseWidthMicros); // probably not needed
        digitalWrite(stepPin1, LOW);

        delay(millisbetweenSteps);


        digitalWrite(ledPin, !digitalRead(ledPin));
      }


      puerta1 = false;
    }
    else {
      Serial.println("motor1 is ALREADY CLOSED");
    }
  }
  if (motorstate == '1')//ABRIR MOTOR
  {
    if (puerta1 == false) {
      Serial.println("Motor1 is Opening");
      ////////////////////////////////////////////////AQUI EL CODIGO PARA ABRIR MOTOR 1

      digitalWrite(directionPin1, HIGH);
      for (int n = 0; n < numberOfSteps*1.8; n++) {
        digitalWrite(stepPin1, HIGH);
        //delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
        digitalWrite(stepPin1, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }
      //abrir motor1
      puerta1 = true;



      delay(3000);


      digitalWrite(ledPin, HIGH);



    }
    else {
      Serial.println("Motor 1 is ALREADY OPENED");
    }
  }



  //////////////////////////////////////////////////////////////////////////////////////////////////////MOTOR

  if (motorstate == '2')//CERRAR MOTOR
  {
    if (puerta2 == true) {
      Serial.println("Motor2 is Closing");
      digitalWrite(ledPin, LOW);
      ////////////////////////////////////////////////AQUI EL CODIGO PARA CERRAR MOTOR 2

      digitalWrite(directionPin2, LOW);
      for (int n = 0; n < numberOfSteps* 2.2; n++) {
        digitalWrite(stepPin2, HIGH);
        digitalWrite(stepPin2, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }


      puerta2 = false;
    }
    else {
      Serial.println("motor2 is ALREADY CLOSED");
    }
  }
  if (motorstate == '3')//ABRIR MOTOR
  {
    if (puerta2 == false) {
      Serial.println("Motor2 is Opening");
      ////////////////////////////////////////////////AQUI EL CODIGO PARA ABRIR MOTOR 2

      digitalWrite(directionPin2, HIGH);
      for (int n = 0; n < numberOfSteps* 2.2; n++) {
        digitalWrite(stepPin2, HIGH);
        //delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
        digitalWrite(stepPin2, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }

      delay(3000);


      digitalWrite(ledPin, HIGH);
      //abrir motor1
      puerta2 = true;

    }
    else {
      Serial.println("Motor 2 is ALREADY OPENED");
    }
  }




  //////////////////////////////////////////////////////////////////////////////////////////////////////MOTOR3


  if (motorstate == '4')//CERRAR MOTOR
  {
    if (puerta3 == true) {
      Serial.println("Motor3 is Closing");
      digitalWrite(ledPin, LOW);
      ////////////////////////////////////////////////AQUI EL CODIGO PARA CERRAR MOTOR 3

      digitalWrite(directionPin3, HIGH);
      for (int n = 0; n < numberOfSteps+20; n++) {
        digitalWrite(stepPin3, HIGH);
        digitalWrite(stepPin3, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }


      puerta3 = false;
    }
    else {
      Serial.println("motor3 is ALREADY CLOSED");
    }
  }
  if (motorstate == '5')//ABRIR MOTOR
  {
    if (puerta3 == false) {
      Serial.println("Motor3 is Opening");
      ////////////////////////////////////////////////AQUI EL CODIGO PARA ABRIR MOTOR 3

      digitalWrite(directionPin3,LOW);
      for (int n = 0; n < numberOfSteps+20; n++) {
        digitalWrite(stepPin3, HIGH);
        //delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
        digitalWrite(stepPin3, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }

      delay(3000);


      digitalWrite(ledPin, HIGH);
      //abrir motor3
      puerta3 = true;

    }
    else {
      Serial.println("Motor 3 is ALREADY OPENED");
    }
  }






  //////////////////////////////////////////////////////////////////////////////////////////////////////MOTOR4

  if (motorstate == '6')//CERRAR MOTOR
  {
    if (puerta4 == true) {
      Serial.println("Motor4 is Closing");
      digitalWrite(ledPin, LOW);
      ////////////////////////////////////////////////AQUI EL CODIGO PARA CERRAR MOTOR 4



      digitalWrite(directionPin4, HIGH);
      for (int n = 0; n < numberOfSteps * 1.8; n++) {
        digitalWrite(stepPin4, HIGH);
        //delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
        digitalWrite(stepPin4, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }

      delay(3000);


      digitalWrite(ledPin, HIGH);

      puerta4 = false;
    }
    else {
      Serial.println("motor4 is ALREADY CLOSED");
    }
  }
  if (motorstate == '7')//ABRIR MOTOR
  {
    if (puerta4 == false) {
      Serial.println("Motor4 is Opening");
      ////////////////////////////////////////////////AQUI EL CODIGO PARA ABRIR MOTOR 4

      digitalWrite(directionPin4, LOW);
      for (int n = 0; n < numberOfSteps * 1.8; n++) { // añadimos mas pasos a este motor
        digitalWrite(stepPin4, HIGH);
        digitalWrite(stepPin4, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }
      //abrir motor4
      puerta4 = true;

    }
    else {
      Serial.println("Motor 4 is ALREADY OPENED");
    }
  }




  //////////////////////////////////////////////////////////////////////////////////////////////////////MOTOR5

  if (motorstate == '8')//CERRAR MOTOR 5
  {
    if (puerta5 == true) {
      Serial.println("Motor5 is Closing");
      digitalWrite(ledPin, LOW);
      ////////////////////////////////////////////////AQUI EL CODIGO PARA CERRAR MOTOR 5

      digitalWrite(directionPin5, LOW);
      for (int n = 0; n < numberOfSteps*1.2; n++) {
        digitalWrite(stepPin5, HIGH);
        digitalWrite(stepPin5, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }


      puerta5 = false;
    }
    else {
      Serial.println("motor5 is ALREADY CLOSED");
    }
  }
  if (motorstate == '9')//ABRIR MOTOR 5
  {
    if (puerta5 == false) {
      Serial.println("Motor5 is Opening");
      ////////////////////////////////////////////////AQUI EL CODIGO PARA ABRIR MOTOR 5

      digitalWrite(directionPin5, HIGH);
      for (int n = 0; n < numberOfSteps*1.2; n++) {
        digitalWrite(stepPin5, HIGH);
        //delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
        digitalWrite(stepPin5, LOW);

        delay(millisbetweenSteps);

        digitalWrite(ledPin, !digitalRead(ledPin));
      }

      delay(3000);


      digitalWrite(ledPin, HIGH);
      //abrir motor5
      puerta5 = true;

    }
    else {
      Serial.println("Motor 5 is ALREADY OPENED");
    }
  }







}
