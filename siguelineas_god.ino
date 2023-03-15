#define mra 4  //Right Motor MA1
#define mrb 5  //Right Motor MA2
#define mla 2  //Left Motor MB1
#define mlb 3  //Left Motor MB2
#define r1 9  //Right Motor Enable Pin EA
#define l2 10 //Left Motor Enable Pin EB

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

void sonidoTerminado(){
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
  Serial.println(digitalRead(button));

  //  
  if(buttonNoPress)
  {
    if(digitalRead(button) == HIGH)
    {
         buttonNoPress = false;
         Serial.println("Boton apretado");
         delay(1000);   
         Serial.println("ARRANCA");

    }
  }
  else
  {

        
    //Reading Sensor Values
    int s1 = isWhite ^ digitalRead(ir1);  //Left Most Sensor
    int s2 = isWhite ^ digitalRead(ir2);  //Left Sensor
    int s3 = isWhite ^ digitalRead(ir3);  //Middle Sensor
    int s4 = isWhite ^ digitalRead(ir4);  //Right Sensor
    int s5 = isWhite ^ digitalRead(ir5);  //Right Most Sensor

    //if only middle sensor detects black line
    // L ooxoo R
    if(((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1)))
    {
      //going forward with full speed 
      analogWrite(r1, 100); //you can adjust the speed of the motors from 0-100
      analogWrite(l2, 100); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }
    
    //if only left sensor detects black line
    // L oxooo R   
    if(((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1)))
    {
      //going right with full speed 
      analogWrite(r1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 100); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }
    
    //if only left most sensor detects black line
    //  xoooo   
    if(((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1)))
    {
      //going right with full speed 
      analogWrite(r1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 75); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if only right sensor detects black line
    // oooxo
    if(((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1)))
    {
      //going left with full speed 
      analogWrite(r1, 100); //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if only right most sensor detects black line
    // oooox
    if(((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0)))
    {
      //going left with full speed 
      analogWrite(r1, 75); //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }
   
    //if middle and right sensor detects black line
    // ooxxo    
    if(((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1)))
    {
      //going left with full speed 
      analogWrite(r1, 75); //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 100); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if middle and left sensor detects black line
    // oxxoo
    if(((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)))
    {
      //going right with full speed 
      analogWrite(r1, 100); //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 75); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if middle, left and left most sensor detects black line
    // xxxoo
    if(((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)))
    {
      //going right with full speed 
      analogWrite(r1, 25); //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //if middle, right and right most sensor detects black line
    // ooxxx
    if(((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)))
    {
      //going left with full speed 
      analogWrite(r1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(l2, 25); //you can adjust the speed of the motors from 0-125
      digitalWrite(mra, HIGH);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, HIGH);
      digitalWrite(mlb, LOW);
    }

    //siguelineas en el aire
    // xxxxx
    if(isWhite ^ ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0)))
    {
      //stop
      digitalWrite(mra, LOW);
      digitalWrite(mrb, LOW);
      digitalWrite(mla, LOW);
      digitalWrite(mlb, LOW);
    }
  }  


 
}
