/*Hardware abstraction layer*/
const int relay01 = 8;
const int relay02 = 9;
const int relay03 = 10;
const int relay04 = 11;
const int soilsensor01 = A0;
const int soilsensor02 = A1;


/*System abstraction layer*/
const int valve01 = relay01;
const int valve02 = relay02;
const int pump = relay04;

int flag = 0;
double moisture01 = 0;
double moisture02 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay01, OUTPUT);
  pinMode(relay02, OUTPUT);
  pinMode(relay03, OUTPUT);
  pinMode(relay04, OUTPUT);
  digitalWrite(relay01, HIGH);
  digitalWrite(relay02, HIGH);
  digitalWrite(relay03, HIGH);
  digitalWrite(relay04, HIGH); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag == 0)
  {
    digitalWrite(relay01,LOW);
    delay(500);
    digitalWrite(relay01,HIGH);
    
    digitalWrite(relay02,LOW);
    delay(500);
    digitalWrite(relay02,HIGH);
    
    digitalWrite(relay03,LOW);
    delay(500);
    digitalWrite(relay03,HIGH);
    
    digitalWrite(relay04,LOW);
    delay(500);
    digitalWrite(relay04,HIGH);
    flag = 1;
  }
  moisture01 = 100 - analogRead(soilsensor01)/1024.0*100;
  Serial.print("sensor % = ");
  Serial.println(moisture01);
}
