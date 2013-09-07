int STBY = 10; //standby (both boards share the same pin)

//Motor A
int PWMA = 3; //Speed control 
int AIN1 = 1; //Direction
int AIN2 = 0; //Direction

//Motor B
int PWMB = 5; //Speed control
int BIN1 = 2; //Direction
int BIN2 = 4; //Direction

int PWMC = 6;
int CIN1 = 7;
int CIN2 = 8;

int PWMD = 9;
int DIN1 = 11;
int DIN2 = 12;

int val = 0;                    //value of individual accelerometer or gyroscope sensor
unsigned long timer=0;          //timer
unsigned long  delta_t;  

int posArray[] ={};		//store the gyroscope and accelerometer value

void setup() {
	// setup 6DOF
	analogReference(EXTERNAL);     //using external analog ref of 3.3V for ADC scaling
	Serial.begin(115200);          //setup serial
  	DDRC = B00000000;              //make all analog ports as inputs (for arduino uno)

  	delay (100); //dealy just in case - to get things stabilized if need be....
 
 	// Serial.println("t[ms] \t gy \t gx \t gz \t az \t ay \t ax "); //print data header

 	timer=millis();

  	// setup TB6612FNG
  	pinMode(STBY, OUTPUT);
  	// setup motor A
	pinMode(PWMA, OUTPUT);
	pinMode(AIN1, OUTPUT);
	pinMode(AIN2, OUTPUT);
	// setup motor B
	pinMode(PWMB, OUTPUT);
	pinMode(BIN1, OUTPUT);
	pinMode(BIN2, OUTPUT);
	// setup motor D
	pinMode(PWMC, OUTPUT);
	pinMode(CIN1, OUTPUT);
	pinMode(CIN2, OUTPUT);
	// setup motor C
	pinMode(PWMD, OUTPUT);
	pinMode(DIN1, OUTPUT);
	pinMode(DIN2, OUTPUT);
}

void loop() {
	for (long i=0; i<6; i++) { 
		val[i] = analogRead(i);    // read the input pin
  		Serial.print(val);      //print data
  		Serial.print ("\t");
 	}  

  
}

void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop(){
//enable standby  
  digitalWrite(STBY, LOW); 
}