

#define m1 4  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 2  //Left Motor MB1
#define m4 3  //Left Motor MB2
#define e1 9  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

#define button 7

#define pinZumbador 8
//*************************************************//
bool buttonPress;

void sonidoTerminado(){
  Serial.println("Sonido terminado");
}

void setup() {
  Serial.begin(9600);
  Serial.println("Hello world!");
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);  
  pinMode(button, INPUT_PULLUP);  
  
  buttonPress = false;  
}

void loop() {
  

  if(!buttonPress)
  {
    if(digitalRead(button) == LOW)
    {
         buttonPress = true;
         Serial.println("Boton apretado");
         delay(1000);   
         Serial.println("ARRANCA");

    }
  }
  else
  {

        
    //Reading Sensor Values
    int s1 = digitalRead(ir1);  //Left Most Sensor
    int s2 = digitalRead(ir2);  //Left Sensor
    int s3 = digitalRead(ir3);  //Middle Sensor
    int s4 = digitalRead(ir4);  //Right Sensor
    int s5 = digitalRead(ir5);  //Right Most Sensor

    //if only middle sensor detects black line
    if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
    {
      //going forward with full speed 
      analogWrite(e1, 200); //you can adjust the speed of the motors from 0-100
      analogWrite(e2, 200); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }
    
    //if only left sensor detects black line
    if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
    {
      //going right with full speed 
      analogWrite(e1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(e2, 25); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }
    
    //if only left most sensor detects black line
    if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
    {
      //going right with full speed 
      analogWrite(e1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(e2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }

    //if only right sensor detects black line
    if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
    {
      //going left with full speed 
      analogWrite(e1, 25); //you can adjust the speed of the motors from 0-125
      analogWrite(e2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }

    //if only right most sensor detects black line
    if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
    {
      //going left with full speed 
      analogWrite(e1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(e2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }


    xx--x      
    //if middle and right sensor detects black line
    if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
    {
      //going left with full speed 
      analogWrite(e1, 75); //you can adjust the speed of the motors from 0-125
      analogWrite(e2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }

    //if middle and left sensor detects black line
    if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
    {
      //going right with full speed 
      analogWrite(e1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(e2, 75); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }

    //if middle, left and left most sensor detects black line
    if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
    {
      //going right with full speed 
      analogWrite(e1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(e2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }

    //if middle, right and right most sensor detects black line
    if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
    {
      //going left with full speed 
      analogWrite(e1, 125); //you can adjust the speed of the motors from 0-125
      analogWrite(e2, 125); //you can adjust the speed of the motors from 0-125
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
    }

    //if all sensors are on a black line
    if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
    {
      //stop
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }
  }  


 
}
