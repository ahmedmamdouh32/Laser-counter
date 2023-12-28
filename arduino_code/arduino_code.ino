#define LDR_pin A0
#define seven_segment_a 7 //LSB
#define seven_segment_b 6
#define seven_segment_c 5
#define seven_segment_d 4 //MSB
#define Buzzer 8
#define threshold_value 120

//this function is used to show numbers on seven segment
void write_on_ss(unsigned char number);


unsigned char counter = 0;

unsigned int LDR_reading = 0;

void setup() {

pinMode(LDR_pin,INPUT);
pinMode(seven_segment_a,OUTPUT);
pinMode(seven_segment_b,OUTPUT);
pinMode(seven_segment_c,OUTPUT);
pinMode(seven_segment_d,OUTPUT);
pinMode(Buzzer,OUTPUT);
}

void loop() {
  
LDR_reading = analogRead(LDR_pin); //take reading from LDR 

if(LDR_reading >= threshold_value){ //if reading is less than threshold then there is an object blocking light beam
  digitalWrite(Buzzer,HIGH);
  counter++;
  write_on_ss(counter);
  delay(200);
  digitalWrite(Buzzer,LOW);

  //do nothing until the object is moved away 
  while(LDR_reading >= threshold_value){
    LDR_reading = analogRead(LDR_pin);
  }
  
}

}

void write_on_ss(unsigned char number){
    digitalWrite(seven_segment_a,number&1);
    digitalWrite(seven_segment_b,(number>>1)&0x01);
    digitalWrite(seven_segment_c,(number>>2)&0x01);
    digitalWrite(seven_segment_d,(number>>3)&0x01);
}
