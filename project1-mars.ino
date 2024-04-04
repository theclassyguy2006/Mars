const int echo = 8;
const int trig = 9;
const int red = 10;
const int yellow = 11;
const int green = 12;

int moist;
float moisperc;

int distance;
long duration;

void setup()
{
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(5);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  
  distance = duration*0.034/2 ;

  moist = analogRead(A2);
  moisperc = (moist/539.00)*100;

  if(distance > 100){  
    if(moisperc <= 100 && moisperc > 70){
      digitalWrite(green,HIGH);
      digitalWrite(yellow,LOW);
      digitalWrite(red,LOW);
    }
    else if(moisperc <= 70 && moisperc > 40){
      digitalWrite(yellow,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(red,LOW);
    }
    else
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(yellow,LOW);
  }
  else{
      digitalWrite(green,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(red,LOW);
  }
}