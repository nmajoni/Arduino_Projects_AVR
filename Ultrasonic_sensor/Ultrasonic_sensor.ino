/*
---------------------------------------
Simple program using the Ultrasonic
Sensor to detect the distance of an 
object from it.
----------------------------------------

 Nyasha Godknows Majoni
 Embedded Software Developer
 Bremen, Germany
 
*/

const int trig = 9;  
const int echo = 10;
long timeTaken;
int  dist;


void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  
}

void loop() {

  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);   //Setting trig high for 10µs then low to send out an 8 cycle sonic bursts
  digitalWrite(trig, LOW);

  timeTaken = pulseIn(echo, HIGH); //Echo will measure the time in µs the sound wave travels 
  dist = timeTaken*0.034/2;        //Divided by 2 because signal goes forth and back.
  
  Serial.print("Distance: ");
  Serial.println(dist);

}
