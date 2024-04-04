// C++ code
//
const int echo = 2;
const int trig = 3;

int distance;
long duration;

void setup()
{
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(11,INPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
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

  if(distance > 100){
    if((analogRead(A0) >250)&& analogRead(A2) < 12){
      Serial.println(analogRead(A2));
      digitalWrite(4,HIGH);
      digitalWrite(7,LOW);
    }
    else{
      digitalWrite(7,HIGH);
      digitalWrite(4,LOW);
    }
  }
  else{
  	digitalWrite(7,LOW);
    digitalWrite(4,LOW);
  }
  
}