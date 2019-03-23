
unsigned long start_time; // Δημιούργησε μια μεταβλητή τύπου unsigned long integer με όνομα start_time
#define echo 12
#define trigger 13
int ledRed = 11; 
int ledOrange = 10; 
int ledGreen = 9; 
int pedRed = 5; 
int pedGreen = 4; 
int ledRedB = 8; 
int ledOrangeB = 7; 
int ledGreenB = 6; 
int pedRedB = 3; 
int pedGreenB = 2;

long receiver_init()
{
 digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  long microseconds=pulseIn(echo,HIGH,100000);
  return microseconds ;
   
}

void setup() {
pinMode(echo,INPUT);
pinMode(trigger,OUTPUT);
Serial.begin(9600);
pinMode(ledRed, OUTPUT); 
pinMode(ledOrange, OUTPUT);
pinMode(ledGreen, OUTPUT); 
pinMode(pedRed, OUTPUT); 
pinMode(pedGreen, OUTPUT);
pinMode(ledRedB, OUTPUT); 
pinMode(ledOrangeB, OUTPUT);
pinMode(ledGreenB, OUTPUT); 
pinMode(pedRedB, OUTPUT); 
pinMode(pedGreenB, OUTPUT);

}
  

void loop() {


while (receiver_init()>= 5){ // Αν  ανιχνευτει υπερηχος κάνε:
digitalWrite(ledRed, LOW); 
digitalWrite(ledOrange, LOW); 
digitalWrite(ledGreen, HIGH);
digitalWrite(ledRedB, HIGH); 
digitalWrite(ledOrangeB, LOW); 
digitalWrite(ledGreenB, LOW);
digitalWrite(pedRed, HIGH); 
digitalWrite(pedGreen, LOW);
digitalWrite(pedRedB, LOW); 
digitalWrite(pedGreenB, HIGH);
delay(100000); //καθυστερησε 100 sec
}
 

if ( receiver_init()<= 5 || receiver_init() >=29930 ) { // Αν ο δεν ανιχνευτει υπερηχος
// κόκκινο για 3 δευτερόλεπτα, πράσινο στους πεζούς
start_time=millis(); // Βάλε στην start_time την τιμή της millis()
while (millis() - start_time < 3000) { // Εφόσον δεν πέρασαν 3 δευτ κάνε: 
digitalWrite(ledRed, HIGH); 
digitalWrite(ledOrange, LOW); 
digitalWrite(ledGreen, LOW); 
digitalWrite(pedRed, LOW); 
digitalWrite(pedGreen, HIGH);
digitalWrite(ledRedB, LOW); 
digitalWrite(ledOrangeB, LOW); 
digitalWrite(ledGreenB, HIGH); 
digitalWrite(pedRedB, HIGH); 
digitalWrite(pedGreenB, LOW);}}
 else {
  start_time=millis(); // Βάλε στην start_time την τιμή της millis()
while (millis() - start_time < 100000) { // Εφόσον δεν πέρασαν 100 δευτ κάνε:
  
  // πράσινο κυκλοφορίας για το ασθενοφορο
digitalWrite(ledRed, LOW); 
digitalWrite(ledOrange, LOW); 
digitalWrite(ledGreen, HIGH);
digitalWrite(ledRedB, HIGH); 
digitalWrite(ledOrangeB, LOW); 
digitalWrite(ledGreenB, LOW);
digitalWrite(pedRed, HIGH); 
digitalWrite(pedGreen, LOW);
digitalWrite(pedRedB, LOW); 
digitalWrite(pedGreenB, HIGH);
}}

if ( receiver_init()<= 5 || receiver_init() >=29930 ) { // Αν ο δεν ανιχνευτει υπερηχος
// κόκκινο στους πεζούς, περιμένω για 1 δευτερόλεπτο πριν δώσω πράσινο στα αμάξια
start_time=millis();
while (millis() - start_time < 1000) { // Εφόσον δεν πέρασαν 1 δευτ κάνε:
digitalWrite(pedRed, HIGH); 
digitalWrite(pedGreen, LOW);
digitalWrite(ledRed, HIGH); 
digitalWrite(ledOrange, LOW); 
digitalWrite(ledGreen, LOW); 
digitalWrite(ledRedB, LOW); 
digitalWrite(ledOrangeB, HIGH); 
digitalWrite(ledGreenB, LOW);
digitalWrite(pedRedB, HIGH); 
digitalWrite(pedGreenB, LOW); }}
 else {
 // πρασινο για τα ασθενοφορα
 start_time=millis(); // Βάλε στην start_time την τιμή της millis()
while (millis() - start_time < 100000) { // Εφόσον δεν πέρασαν 100 δευτ κάνε: 
  // πράσινο κυκλοφορίας για το ασθενοφορο 
digitalWrite(ledRed, LOW); 
digitalWrite(ledOrange, LOW); 
digitalWrite(ledGreen, HIGH);
digitalWrite(ledRedB, HIGH); 
digitalWrite(ledOrangeB, LOW); 
digitalWrite(ledGreenB, LOW);
digitalWrite(pedRed, HIGH); 
digitalWrite(pedGreen, LOW);
digitalWrite(pedRedB, LOW); 
digitalWrite(pedGreenB, HIGH);
 }}

if ( receiver_init()<= 5 || receiver_init() >=29930 ) {
// πράσινο κυκλοφορίας για 5 δευτερόλεπτα
start_time=millis(); 
while (millis() - start_time < 5000) { // Εφόσον δεν πέρασαν 5 δευτ κάνε: 
digitalWrite(ledRed, LOW); 
digitalWrite(ledOrange, LOW); 
digitalWrite(ledGreen, HIGH);
digitalWrite(ledRedB, HIGH); 
digitalWrite(ledOrangeB, LOW); 
digitalWrite(ledGreenB, LOW);
digitalWrite(pedRed, HIGH); 
digitalWrite(pedGreen, LOW);
digitalWrite(pedRedB, LOW); 
digitalWrite(pedGreenB, HIGH);}}
else{
  // πράσινο κυκλοφορίας για το ασθενοφορο  
 start_time=millis(); // Βάλε στην start_time την τιμή της millis()
while (millis() - start_time < 100000) { // Εφόσον δεν πέρασαν 100 δευτ κάνε:
digitalWrite(ledRed, LOW); 
digitalWrite(ledOrange, LOW); 
digitalWrite(ledGreen, HIGH);
digitalWrite(ledRedB, HIGH); 
digitalWrite(ledOrangeB, LOW); 
digitalWrite(ledGreenB, LOW);
digitalWrite(pedRed, HIGH); 
digitalWrite(pedGreen, LOW);
digitalWrite(pedRedB, LOW); 
digitalWrite(pedGreenB, HIGH);  
}}

if ( receiver_init()<= 5 || receiver_init() >=29930 ) {
// πορτοκαλί για 1 δευτερόλεπτο
start_time=millis();
while (millis() - start_time < 1000) { // Εφόσον δεν πέρασαν 1 δευτ κάνε:
digitalWrite(pedRed, HIGH); 
digitalWrite(pedGreen, LOW); 
digitalWrite(ledRed, LOW); 
digitalWrite(ledOrange, HIGH); 
digitalWrite(ledGreen, LOW);
digitalWrite(pedRedB, HIGH); 
digitalWrite(pedGreenB, LOW); 
digitalWrite(ledRedB, HIGH); 
digitalWrite(ledOrangeB, LOW); 
digitalWrite(ledGreenB, LOW);}}
else {
  // πράσινο κυκλοφορίας για το ασθενοφορο  
 start_time=millis(); // Βάλε στην start_time την τιμή της millis()
while (millis() - start_time < 100000) { // Εφόσον δεν πέρασαν 100 δευτ κάνε:
digitalWrite(ledRed, LOW); 
digitalWrite(ledOrange, LOW); 
digitalWrite(ledGreen, HIGH);
digitalWrite(ledRedB, HIGH); 
digitalWrite(ledOrangeB, LOW); 
digitalWrite(ledGreenB, LOW);
digitalWrite(pedRed, HIGH); 
digitalWrite(pedGreen, LOW);
digitalWrite(pedRedB, LOW); 
digitalWrite(pedGreenB, HIGH);    
}
}

}




