#include <CustomStepper.h>
//eoasjkdhasd//


#include <Stepper.h>
void addFood();

//stepper motor varible
const int stepPin = 5;
const int dirPin = 4;
const int solenoidWater = 2;
//buttom varible
const int buttonPin = 2;     // the number of the pushbutton pin
//int buttonState=0;
  int buttonState = 0;         // variable for reading the pushbutton status

int food_sensor = A0;
int water_sensor = A1;

 void setup() {
  Serial.begin(9600);
  //stepper init
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  
  //buttom init
  int buttonState = 0;         // variable for reading the pushbutton status
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  int food_level = analogRead(A0);
  int water_level = analogRead(A1);
  if(map(food_level,0,1023,0,100)) < 20)  
  {
   // addFood();  //send question to user
  }
  if(map(water_level,0,1023,0,100)) < 20)  
  {
    //addWater(); //send question to user
  } 
}

void addFood()
{
  digitalWrite(dirPin, HIGH);
  for(int timeForFood = 0; timeForFood<1000; timeForFood++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1700);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(1700);
  }
  delay(1000);
}

void addWater()
{
  digitalWrite(solenoidWater, HIGH);
  delayMicroseconds(3000);
  digitalWrite(solenoidWater, LOW);
  delayMicroseconds(3000);
}

