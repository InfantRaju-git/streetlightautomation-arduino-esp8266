int trigPin1=2;
int echoPin1=3;

int trigPin2=4;
int echoPin2=5;

int trigPin3=6;
int echoPin3=7;

int led1=A3;
int led2=A2;
int led3=A4;
int led4=A0;

int ndon=11;
int ndldr=12;
int ndsns=13;

int ir=9;
int ldr=10;


void setup() {
  Serial.begin (9600);
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
   pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
 
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
  pinMode(ndon,INPUT);
  pinMode(ndldr,INPUT);
  pinMode(ndsns,INPUT);
  
  pinMode(ldr,INPUT);
  pinMode(ir,INPUT);
   

}

void loop() {
  int ldrmob=digitalRead(ndldr);
  int ltmbcnt=digitalRead(ndon);
  int snscnt=digitalRead(ndsns);
if(ltmbcnt==HIGH)
{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
}
else if(ldrmob==HIGH)
{
  int ldrsn= digitalRead(ldr);
  if(ldrsn==HIGH)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
  else
  {
    
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
}
else if(snscnt==HIGH)
{
int irnum=digitalRead(ir);
    if(irnum==HIGH)
    {
      digitalWrite(led4,HIGH);
    }
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
   
   if (distance1 <60){
     if(irnum==LOW)
    {
      digitalWrite(led4,LOW);
    }
    digitalWrite(led1,HIGH);   
  }
  else {
    digitalWrite(led1,LOW);
  }
  delay(50);
long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= (duration2/2) / 29.1;
   
    if (distance2 <60){
       if (irnum==LOW)
    {
      digitalWrite(led4,LOW);
    }
    digitalWrite(led2,HIGH);
    
  }
  else {
    digitalWrite(led2,LOW);
  }
  delay(50);
  long duration3, distance3;
  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3= (duration3/2) / 29.1;

   if (distance3 <60){
    digitalWrite(led3,HIGH);
    
  }
  else {
    digitalWrite(led3,LOW);
  }
  delay(50);
}

}
