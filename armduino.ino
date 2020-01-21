#include <Servo.h> //add servo library. this library is standard library
#define INIT_TIME 500
//define the servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
//define the buttons & LEDs
const int button1 = 4;
const int button2 = 2;
const int led_work =8 ;
const int led_free = 13;
const int led_record=10;
//define variable for values of the button
int button1Pressed = 0;
boolean button2Pressed = false;
//define variable for counting & control flow 
int ser_steps=0;
int counter=0;
int n_free=0;
int ser_speed;
//define potentiometers
const int pot1 = A0;
const int pot2 = A1;
const int pot3 = A2;
const int pot4 = A3;
const int pot5 = A4;
//define variable for values of the potentiometers
int pot1Val;
int pot2Val;
int pot3Val;
int pot4Val;
int pot5Val;
int pot6Val;
//define variable for angles of the potentiometer
int pot1Angle;
int pot2Angle;
int pot3Angle;
int pot4Angle;
int pot5Angle;
//define variable for saved position of the servos
int servo1PosSave[]={1,1,1,1,1,1,1,1,1,1};
int servo2PosSave[]={1,1,1,1,1,1,1,1,1,1};
int servo3PosSave[]={179,179,179,179,179,179,179,179,179,179};
int servo4PosSave[]={1,1,1,1,1,1,1,1,1,1};
int servo5PosSave[]={1,1,1,1,1,1,1,1,1,1};
int prev1;
int prev2;
int prev3;
int prev4;
int prev5;
void setup() {
    //define attached pins of the servos
    servo1.attach(3);
    servo2.attach(5);
    servo3.attach(7);
    servo4.attach(9);
    servo5.attach(11);
    //define buttons as input units
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    //define LEDs as output units
    pinMode(led_work, OUTPUT);
    pinMode(led_free, OUTPUT);
    pinMode(led_record, OUTPUT);
    //initialize serial communication for debuging 
    Serial.begin(9600);
}

void loop() {
  //read the potentiometer values and define the servo angle to
  //the potentiometer value with the map function (Not Working in record mode )
    if(n_free>=counter)
        {
            digitalWrite(led_record, LOW);
            digitalWrite(led_free, HIGH);
            Serial.println("////////////////////////////////////////////");
            pot1Val = analogRead(pot1);
            pot1Angle = map (pot1Val, 0, 1023, 0, 179);
            pot2Val = pot3Val = analogRead(pot2);
            pot2Angle = map (pot2Val, 0, 1023, 0, 179);
            pot3Angle = map (pot3Val, 0, 1023, 179, 0);
            pot4Val = analogRead(pot3);
            pot4Angle = map (pot4Val, 0, 1023, 0, 179);
            pot5Val = analogRead(pot4);
            pot5Angle = map (pot5Val, 0, 1023, 0, 179);
            //servos move to mapped angles
            servo1.write(pot1Angle);
            servo2.write(pot2Angle);
            servo3.write(pot3Angle);
            servo4.write(pot4Angle);
            servo5.write(pot5Angle);
            
        }
    //if button1 is pressed (HIGH), save the potentiometers position
    //as long as button1 is pressed
    if(digitalRead(button1) == HIGH && button1Pressed<10){
        digitalWrite(led_record, HIGH);
        delay(INIT_TIME);
        Serial.println("**************************** : ");
        button1Pressed++;
        ser_steps=button1Pressed;
        switch(button1Pressed){
        case 1:
            servo1PosSave[0] = pot1Angle;
            servo2PosSave[0] = pot2Angle;
            servo3PosSave[0] = pot3Angle;
            servo4PosSave[0] = pot4Angle;
            servo5PosSave[0] = pot5Angle;
            Serial.println("Position #1 Saved");
            break;
        case 2:
            servo1PosSave[1] = pot1Angle;
            servo2PosSave[1] = pot2Angle;
            servo3PosSave[1] = pot3Angle;
            servo4PosSave[1] = pot4Angle;
            servo5PosSave[1] = pot5Angle;
            Serial.println("Position #2 Saved");
            break;
        case 3:
            servo1PosSave[2] = pot1Angle;
            servo2PosSave[2] = pot2Angle;
            servo3PosSave[2] = pot3Angle;
            servo4PosSave[2] = pot4Angle;
            servo5PosSave[2] = pot5Angle;
            Serial.println("Position #3 Saved");
            break;
        case 4:
            servo1PosSave[3] = pot1Angle;
            servo2PosSave[3] = pot2Angle;
            servo3PosSave[3] = pot3Angle;
            servo4PosSave[3] = pot4Angle;
            servo5PosSave[3] = pot5Angle;
            Serial.println("Position #4 Saved");
            break;
        case 5:
            servo1PosSave[4] = pot1Angle;
            servo2PosSave[4] = pot2Angle;
            servo3PosSave[4] = pot3Angle;
            servo4PosSave[4] = pot4Angle;
            servo5PosSave[4] = pot5Angle;
            Serial.println("Position #5 Saved");
            break;
        case 6:
            servo1PosSave[5] = pot1Angle;
            servo2PosSave[5] = pot2Angle;
            servo3PosSave[5] = pot3Angle;
            servo4PosSave[5] = pot4Angle;
            servo5PosSave[5] = pot5Angle;
            Serial.println("Position #6 Saved");
            break;
        case 7:
            servo1PosSave[6] = pot1Angle;
            servo2PosSave[6] = pot2Angle;
            servo3PosSave[6] = pot3Angle;
            servo4PosSave[6] = pot4Angle;
            servo5PosSave[6] = pot5Angle;
            Serial.println("Position #7 Saved");
            break;
        case 8:
            servo1PosSave[7] = pot1Angle;
            servo2PosSave[7] = pot2Angle;
            servo3PosSave[7] = pot3Angle;
            servo4PosSave[7] = pot4Angle;
            servo5PosSave[7] = pot5Angle;
            Serial.println("Position #8 Saved");
            break;
        case 9:
            servo1PosSave[8] = pot1Angle;
            servo2PosSave[8] = pot2Angle;
            servo3PosSave[8] = pot3Angle;
            servo4PosSave[8] = pot4Angle;
            servo5PosSave[8] = pot5Angle;
            Serial.println("Position #9 Saved");
            break;
        case 10:
            servo1PosSave[9] = pot1Angle;
            servo2PosSave[9] = pot2Angle;
            servo3PosSave[9] = pot3Angle;
            servo4PosSave[9] = pot4Angle;
            servo5PosSave[9] = pot5Angle;
            Serial.println("Position #10 Saved");
            break;
        }
}
//if button2 pressed (HIGH), the servos move saved position
        if(digitalRead(button2) == HIGH && button1Pressed ){
            digitalWrite(led_free, LOW);
            digitalWrite(led_work, HIGH);
            button2Pressed = true;
        }
        while(button2Pressed){
            if(counter>1)
                {
                    prev1=servo1PosSave[ser_steps-1];
                    prev2=servo2PosSave[ser_steps-1];
                    prev3=servo3PosSave[ser_steps-1];
                    prev4=servo4PosSave[ser_steps-1];
                    prev5=servo5PosSave[ser_steps-1];
                    if(servo1PosSave[ser_steps-1]<servo1PosSave[0])
                        {
                         
                            for(int j=prev1;j<servo1PosSave[0];j++)
                                {
                                    servo1.write(j);
                                    delay(ser_speed);
                                }
                        }
                    else
                        {
                            for(int j =prev1;j>servo1PosSave[0];j--)
                                {
                                    servo1.write(j);
                                    delay(ser_speed);
                                }

                        }

                    if(servo2PosSave[ser_steps-1]<servo2PosSave[0])
                        {
                            int  k=prev3;
                            for(int j=prev2;j<servo2PosSave[0];j++)
                                {
                                    k--;
                                    servo2.write(j);
                                    servo3.write(k);
                                    delay(ser_speed);
                                }
                        }
                    else
                        {
                            int k=prev3;
                            for(int j=prev2;j>servo2PosSave[0];j--)
                                {
                                    k++;
                                    servo2.write(j);
                                    servo3.write(k);
                                    delay(ser_speed);
                                }
                        }
                    if(servo4PosSave[ser_steps-1]<servo4PosSave[0])
                        {
                         
                            for(int j=prev4;j<servo4PosSave[0];j++)
                                {
                                    servo4.write(j);
                                    delay(ser_speed);
                                }
                        }
                    else
                        {
                            for(int j =prev4;j>servo4PosSave[0];j--)
                                {
                                    servo4.write(j);
                                    delay(ser_speed);
                                }

                        }
                    if(servo5PosSave[ser_steps-1]<servo5PosSave[0])
                        {
                            for(int j=prev5;j<servo5PosSave[0];j++)
                                {
                                    servo5.write(j);
                                    delay(ser_speed);
                                }
                        }
                    else
                        {
                            for(int j =prev5;j>servo5PosSave[0];j--)
                                {
                                    servo5.write(j);
                                    delay(ser_speed);
                                }
                        }
                }
            ///////////////////////////////////////////////////////////////////////////////////
            delay(INIT_TIME);
            prev1=servo1PosSave[0];
            prev2=servo2PosSave[0];
            prev3=servo3PosSave[0];
            prev4=servo4PosSave[0];
            prev5=servo5PosSave[0];
            for(int i=0;i<ser_steps; i++)
                {
                    pot6Val = analogRead(pot5);
                    ser_speed = map(pot6Val, 0, 1023, 10, 30); 
                    prev1=servo1PosSave[i];
                    prev2=servo2PosSave[i];
                    prev3=servo3PosSave[i];
                    prev4=servo4PosSave[i];
                    prev5=servo5PosSave[i];
                    if(i>=1)
                        {
                            prev1=servo1PosSave[i-1];
                            prev2=servo2PosSave[i-1];
                            prev3=servo3PosSave[i-1];
                            prev4=servo4PosSave[i-1];
                            prev5=servo5PosSave[i-1];
                        }
                    if(prev1<servo1PosSave[i])
                        {
                            for(int j=prev1 ; j<servo1PosSave[i];j++)
                                {
                                    servo1.write(j);
                                    delay(ser_speed);
                                }
                        }
                    else
                        {
                            for(int j=prev1 ; j>servo1PosSave[i];j--)
                                {
                                    servo1.write(j);
                                    delay(ser_speed);
                                }
                        }
                    if(prev2<servo2PosSave[i])
                        {
                            int  k=prev3;
                            for(int j=prev2;j<servo2PosSave[i];j++)
                                {
                                    k--;
                                    servo2.write(j);
                                    servo3.write(k);
                                    delay(ser_speed);
                                }
                        }
                    else
                        {
                            int k=prev3;
                            for(int j=prev2;j>servo2PosSave[i];j--)
                                {
                                    k++;
                                    servo2.write(j);
                                    servo3.write(k);
                                    delay(ser_speed);
                                }
                        }
                    if(prev4<servo4PosSave[i])
                        {
                            for(int j=prev4 ; j<servo4PosSave[i];j++)
                                {
                                    servo4.write(j);
                                    delay(ser_speed);
                                }
                        }
                    else
                        {
                            for(int j=prev4 ; j>servo4PosSave[i];j--)
                                {
                                    servo4.write(j);
                                    delay(ser_speed);
                                }
                        }
                    if(prev5<servo5PosSave[i])
                        {
                            for(int j=prev5 ; j<servo5PosSave[i];j++)
                                {
                                    servo5.write(j);
                                    delay(ser_speed);
                                }
                        }
                    else
                        {
                            for(int j=prev5 ; j>servo5PosSave[i];j--)
                                {
                                    servo5.write(j);
                                    delay(ser_speed);
                                }
                        }
                    counter++;
                }
        }
}
