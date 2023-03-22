#define mra 4  //Right Motor MA1
#define mrb 5  //Right Motor MA2
#define mla 2  //Left Motor MB1
#define mlb 3  //Left Motor MB2
#define r1 9   //Right Motor Enable Pin EA
#define l2 10  //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

#define button 7

#define pinZumbador 8
//*************************************************//
bool buttonNoPress;
bool isWhite;

void sonidoTerminado() {
  Serial.println("Sonido terminado");
}

void setup() {
  Serial.begin(9600);
  Serial.println("Hello world!");
  pinMode(mra, OUTPUT);
  pinMode(mrb, OUTPUT);
  pinMode(mla, OUTPUT);
  pinMode(mlb, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(button, INPUT_PULLUP);

  buttonNoPress = true;
  isWhite = true;
}

void loop() {

  //
  if (buttonNoPress) {
    if (digitalRead(button) == HIGH) {
      buttonNoPress = false;
      Serial.println("Boton apretado");
      delay(1000);
      Serial.println("ARRANCA");
    }
  } else {


    //Reading Sensor Values
    // int sa1 = digitalRead(ir4);  //Right Sensor
    // int sa5 =  digitalRead(ir1);  //Left Most Sensor
    // int sa2 =  digitalRead(ir2);  //Left Sensor
    // int sa3 =  digitalRead(ir3);  //Middle Sensor
    // int sa4 =  digitalRead(ir5);  //Right Most Sensor

    int sa1 =  analogRead(ir1);  //Left Most Sensor
    int sa2 =  analogRead(ir2);  //Left Sensor
    int sa3 =  analogRead(ir3);  //Middle Sensor
    int sa4 =  analogRead(ir4);  //Right Sensor
    int sa5 =  analogRead(ir5);  //Right Most Sensor

    //Serial.println(sa1 + sa2 + sa3 + sa4 + sa5);
    Serial.println(sa1);
    Serial.println("es1");
    delay(3000);
    Serial.println(sa2);
    Serial.println("es2");
    delay(3000);
    Serial.println(sa3);
    Serial.println("es3");    
    delay(3000);
    Serial.println(sa4);
    Serial.println("es4");
    delay(3000);
    Serial.println(sa5);
    Serial.println("es5");    
    delay(3000);
    //if only middle sensor detects black line
    // L ooxoo R
    if ((sa3 == 0)) {
      //going forward with full speed
      Serial.println("ooxoo");

      analogWrite(r1, 100);  //you can adjust the speed of the motors from 0-100
      analogWrite(l2, 100);  //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if only left sensor detects black line
    // L oxooo R
    if ((sa2 == 0)) {
      Serial.println("oxooo");


      //going right with full speed
      analogWrite(r1, 125);  //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 100);  //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if only left most sensor detects black line
    //  xoooo
    if ((sa1 == 0)) {
      Serial.println("xoooo");

      //going right with full speed
      analogWrite(r1, 125);  //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 75);   //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if only right sensor detects black line
    // oooxo
    if ((sa4 == 0)) {
      Serial.println("oooxo");


      //going left with full speed
      analogWrite(r1, 100);  //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 125);  //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if only right most sensor detects black line
    // oooox
    if (sa5 == 0) {
      Serial.println("oooox");

      //going left with full speed
      analogWrite(r1, 75);   //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 125);  //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if middle and right sensor detects black line
    // ooxxo
    if (((sa1 == 1) && (sa2 == 1) && (sa3 == 0) && (sa4 == 0) && (sa5 == 1))) {
      Serial.println("ooxxo");


      //going left with full speed
      analogWrite(r1, 75);   //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 100);  //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if middle and left sensor detects black line
    // oxxoo
    if (((sa1 == 1) && (sa2 == 0) && (sa3 == 0) && (sa4 == 1) && (sa5 == 1))) {
      Serial.println("oxxoo");

      //going right with full speed
      analogWrite(r1, 100);  //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 75);   //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if middle, left and left most sensor detects black line
    // xxxoo
    if (((sa1 == 0) && (sa2 == 0) && (sa3 == 0) && (sa4 == 1) && (sa5 == 1))) {
      Serial.println("xxxoo");

      //going right with full speed
      analogWrite(r1, 25);   //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 125);  //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if middle, right and right most sensor detects black line
    // ooxxx
    if (((sa1 == 1) && (sa2 == 1) && (sa3 == 0) && (sa4 == 0) && (sa5 == 0))) {
      Serial.println("ooxxx");

      //going left with full speed
      analogWrite(r1, 125);  //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 25);   //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //siguelineas en el aire
    // xxxxx
    if (((sa1 == isWhite) && (sa2 == isWhite) && (sa3 == isWhite) && (sa4 == isWhite) && (sa5 == isWhite))) {
      Serial.println("xxxxx");

      //stop
      digitalWrite(mra, LOW);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, LOW);
      digitalWrite(mlb, LOW);
    }
  }
}
