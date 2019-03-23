// I2C LCD screen demo
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16 ,2); 
#define echo 12
#define trigger 13
#include <Servo.h> // Συμπερίλαβε τη βιβλιοθήκη του σέρβο
Servo myservo; // Δημιούργησε ένα αντικείμενο τύπου Servo
int s=1; // Το βήμα (μοίρες) που θα αυξάνουμε τη θέση του σέρβο σε κάθε επανάληψη
const int LDR=A0;
int input=0;
int brightness=0;
const int CityLIGHTSA=5;
const int CityLIGHTSB=3;
long receiver_init()   //ΤΟ CONTROL-ΔΕΚΤΗΣ ΠΟΥ ΘΑ ΕΛΕΓΧΕΙ ΤΗΝ ΠΑΡΑΛΑΒΗ Ή ΟΧΙ ΤΟΥ ΣΗΜΑΤΟΣ-ΠΟΙΟ ΚΑΤΩ ΦΑΙΝΕΤΑΙ ΟΤΑΝ ΧΡΗΣΙΜΟΠΟΙΗΤΑΙ
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

void setup()
{
pinMode(CityLIGHTSA,OUTPUT);  //LIGHTSA AND B  ΣΤΑΔΙΑΚΟΣ ΦΩΤΙΣΜΟΣ ΠΟΛΗΣ
pinMode(CityLIGHTSB,OUTPUT);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
Serial.begin(9600);
lcd.init(); // initialize the lcd
// Print a message to the LCD.
lcd.backlight();
lcd.setCursor(0,0);
myservo.attach(9); // Σχετίζει το σερβο με το πιν 9

myservo.write(0); // Γύρισε τον άξονα του servo στην τιμή 0
delay(15); // Περίμενε λίγο για να γυρίσει το servo στην τιμή που θέλουμε

}
void loop()
{
  
   input = analogRead(LDR);
 brightness = map(input,400,1023,0,255);  //ΣΤΑΔΙΑΚΟΣ ΦΩΤΙΣΜΟΣ ΠΟΛΗΣ ΑΝΤΙΣΤΡΟΦΩΣ ΑΝΑΛΟΓΗ ΤΗΣ ΕΞΩΤΕΡΙΚΗΣ ΦΩΤΕΙΝΟΤΗΤΑΣ
 analogWrite(CityLIGHTSA,brightness);
 analogWrite(CityLIGHTSB,brightness);
 Serial.println(receiver_init());
  if ( receiver_init()<=10) { //ΑΝ ΔΕΝ ΑΝΙΧΝΕΥΤΕΙ ΣΗΜΑ ΚΛΕΙΣΕ ΤΗΝ ΜΠΑΡΑ
  myservo.write(0); // Γύρισε τον άξονα του servo στην τιμή 0
delay(4500); // Περίμενε λίγο για να γυρίσει το servo στην τιμή που θέλουμε
  }
 //ΑΝ ΑΝΙΧΝΕΥΤΕΙ ΥΠΕΡΗΧΟΣ ΚΑΝΕ
if ( receiver_init()>=10) {
  
myservo.write(110); // Γύρισε τον άξονα του servo στην τιμή 110-άνοιξε την μπάρα
delay(25); 

lcd.setCursor(0,0);
lcd.print("AMBULANCE DETECT");
lcd.setCursor(0,1);
lcd.print(" DOORS OPEN!!! ");  
delay(40000);
}
else {

lcd.setCursor(0,0);
lcd.print(" NO AMBULANCE!   ");
lcd.setCursor(0,1);
lcd.print(" DOORS CLOSED    ");  

myservo.write(0); // Γύρισε τον άξονα του servo στην τιμή 0-κλεισε την μπαρα
delay(4500); 


}
// τα παρακατω ειναι για τον έλεγχο παραλαβης υπερηχου,ldr,φωτεινοτητας
Serial.println(receiver_init());

Serial.println(input);
 Serial.println(brightness);
}

