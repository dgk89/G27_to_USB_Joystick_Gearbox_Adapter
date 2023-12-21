/*
G27 gearbox interface
*/

int horizontalAxisPin = A1;   // select the input pin for the potentiometer
int verticalAxisPin = A0;   // select the input pin for the potentiometer

int horizontalAxisValue = 0;   // value read by the sensor
int verticalAxisValue = 0;   // value read by the sensor

int gear1pin = 7;   // select the output pin for the gear
int gear2pin = 8;   // select the output pin for the gear
int gear3pin = 9;   // select the output pin for the gear
int gear4pin = 10;   // select the output pin for the gear
int gear5pin = 11;   // select the output pin for the gear
int gear6pin = 12;   // select the output pin for the gear

int offset = 100;

int gear1horizontalReference = 300;
int gear2horizontalReference = 289;
int gear3horizontalReference = 513;
int gear4horizontalReference = 517;
int gear5horizontalReference = 676;
int gear6horizontalReference = 683;

int gear1verticalReference = 790;
int gear2verticalReference = 0;
int gear3verticalReference = 794;
int gear4verticalReference = 0;
int gear5verticalReference = 844;
int gear6verticalReference = 0;


int gear1minimumVerticalRange = gear1verticalReference - offset;
int gear2minimumVerticalRange = gear2verticalReference - offset;
int gear3minimumVerticalRange = gear3verticalReference - offset;
int gear4minimumVerticalRange = gear4verticalReference - offset;
int gear5minimumVerticalRange = gear5verticalReference - offset;
int gear6minimumVerticalRange = gear6verticalReference - offset;

int gear1maximumVerticalRange = gear1verticalReference + offset;
int gear2maximumVerticalRange = gear2verticalReference + offset;
int gear3maximumVerticalRange = gear3verticalReference + offset;
int gear4maximumVerticalRange = gear4verticalReference + offset;
int gear5maximumVerticalRange = gear5verticalReference + offset;
int gear6maximumVerticalRange = gear6verticalReference + offset;

int gear1minimumHorizontalRange = gear1horizontalReference - offset;
int gear2minimumHorizontalRange = gear2horizontalReference - offset;
int gear3minimumHorizontalRange = gear3horizontalReference - offset;
int gear4minimumHorizontalRange = gear4horizontalReference - offset;
int gear5minimumHorizontalRange = gear5horizontalReference - offset;
int gear6minimumHorizontalRange = gear6horizontalReference - offset;

int gear1maximumHorizontalRange = gear1horizontalReference + offset;
int gear2maximumHorizontalRange = gear2horizontalReference + offset;
int gear3maximumHorizontalRange = gear3horizontalReference + offset;
int gear4maximumHorizontalRange = gear4horizontalReference + offset;
int gear5maximumHorizontalRange = gear5horizontalReference + offset;
int gear6maximumHorizontalRange = gear6horizontalReference + offset;

void setup() {
  // declare the pins as OUTPUT:
  pinMode(gear1pin, OUTPUT);
  pinMode(gear2pin, OUTPUT);
  pinMode(gear3pin, OUTPUT);
  pinMode(gear4pin, OUTPUT);
  pinMode(gear5pin, OUTPUT);
  pinMode(gear6pin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  readGears();

  setGears();
  
  // turn the ledPin off
  delay(50);
}

void readGears(){
  // read the value from the sensor:
  horizontalAxisValue = analogRead(horizontalAxisPin);
  verticalAxisValue = analogRead(verticalAxisPin);

  Serial.println("---------------");
  Serial.println(horizontalAxisValue);
  Serial.println(verticalAxisValue);
}

void setGears(){

  if (gear1engaged())
    set1gear();
  else if (gear2engaged())
    set2gear();
  else if (gear3engaged())
    set3gear();
  else if (gear4engaged())
    set4gear();
  else if (gear5engaged())
    set5gear();
  else if (gear6engaged())
    set6gear();
  else
    setNeutral();

}

bool gear1engaged(){
  if (gear1horizontalRange() && gear1verticalRange())
    return true;
  else
    return false;
}
bool gear2engaged(){
  if (gear2horizontalRange() && gear2verticalRange())
    return true;
  else
    return false;
}
bool gear3engaged(){
  if (gear3horizontalRange() && gear3verticalRange())
    return true;
  else
    return false;
}
bool gear4engaged(){
  if (gear4horizontalRange() && gear4verticalRange())
    return true;
  else
    return false;
}
bool gear5engaged(){
  if (gear5horizontalRange() && gear5verticalRange())
    return true;
  else
    return false;
}
bool gear6engaged(){
  if (gear6horizontalRange() && gear6verticalRange())
    return true;
  else
    return false;
}

void set1gear(){
  Serial.println("1 GEAR ENGAGED");
  digitalWrite(gear1pin, HIGH); // sets the digital pin on
  digitalWrite(gear2pin, LOW); // sets the digital pin on
  digitalWrite(gear3pin, LOW); // sets the digital pin on
  digitalWrite(gear4pin, LOW); // sets the digital pin on
  digitalWrite(gear5pin, LOW); // sets the digital pin on
  digitalWrite(gear6pin, LOW); // sets the digital pin on
}
void set2gear(){
  Serial.println("2 GEAR ENGAGED");
  digitalWrite(gear1pin, LOW); // sets the digital pin on
  digitalWrite(gear2pin, HIGH); // sets the digital pin on
  digitalWrite(gear3pin, LOW); // sets the digital pin on
  digitalWrite(gear4pin, LOW); // sets the digital pin on
  digitalWrite(gear5pin, LOW); // sets the digital pin on
  digitalWrite(gear6pin, LOW); // sets the digital pin on
}
void set3gear(){
  Serial.println("3 GEAR ENGAGED");
  digitalWrite(gear1pin, LOW); // sets the digital pin on
  digitalWrite(gear2pin, LOW); // sets the digital pin on
  digitalWrite(gear3pin, HIGH); // sets the digital pin on
  digitalWrite(gear4pin, LOW); // sets the digital pin on
  digitalWrite(gear5pin, LOW); // sets the digital pin on
  digitalWrite(gear6pin, LOW); // sets the digital pin on
}
void set4gear(){
  Serial.println("4 GEAR ENGAGED");
  digitalWrite(gear1pin, LOW); // sets the digital pin on
  digitalWrite(gear2pin, LOW); // sets the digital pin on
  digitalWrite(gear3pin, LOW); // sets the digital pin on
  digitalWrite(gear4pin, HIGH); // sets the digital pin on
  digitalWrite(gear5pin, LOW); // sets the digital pin on
  digitalWrite(gear6pin, LOW); // sets the digital pin on
}
void set5gear(){
  Serial.println("5 GEAR ENGAGED");
  digitalWrite(gear1pin, LOW); // sets the digital pin on
  digitalWrite(gear2pin, LOW); // sets the digital pin on
  digitalWrite(gear3pin, LOW); // sets the digital pin on
  digitalWrite(gear4pin, LOW); // sets the digital pin on
  digitalWrite(gear5pin, HIGH); // sets the digital pin on
  digitalWrite(gear6pin, LOW); // sets the digital pin on
}
void set6gear(){
  Serial.println("6 GEAR ENGAGED");
  digitalWrite(gear1pin, LOW); // sets the digital pin on
  digitalWrite(gear2pin, LOW); // sets the digital pin on
  digitalWrite(gear3pin, LOW); // sets the digital pin on
  digitalWrite(gear4pin, LOW); // sets the digital pin on
  digitalWrite(gear5pin, LOW); // sets the digital pin on
  digitalWrite(gear6pin, HIGH); // sets the digital pin on
}
void setNeutral(){
  Serial.println("NEUTRAL");
  digitalWrite(gear1pin, LOW); // sets the digital pin on
  digitalWrite(gear2pin, LOW); // sets the digital pin on
  digitalWrite(gear3pin, LOW); // sets the digital pin on
  digitalWrite(gear4pin, LOW); // sets the digital pin on
  digitalWrite(gear5pin, LOW); // sets the digital pin on
  digitalWrite(gear6pin, LOW); // sets the digital pin on
}

bool gear1horizontalRange(){
  if (horizontalAxisValue > gear1minimumHorizontalRange && horizontalAxisValue < gear1maximumHorizontalRange)
    return true;
  else
    return false;
}

bool gear1verticalRange(){
  if (verticalAxisValue > gear1minimumVerticalRange && verticalAxisValue < gear1maximumVerticalRange)
    return true;
  else
    return false;
}

bool gear2horizontalRange(){
  if (horizontalAxisValue > gear2minimumHorizontalRange && horizontalAxisValue < gear2maximumHorizontalRange)
    return true;
  else
    return false;
}

bool gear2verticalRange(){
  if (verticalAxisValue > gear2minimumVerticalRange && verticalAxisValue < gear2maximumVerticalRange)
    return true;
  else
    return false;
}

bool gear3horizontalRange(){
  if (horizontalAxisValue > gear3minimumHorizontalRange && horizontalAxisValue < gear3maximumHorizontalRange)
    return true;
  else
    return false;
}

bool gear3verticalRange(){
  if (verticalAxisValue > gear3minimumVerticalRange && verticalAxisValue < gear3maximumVerticalRange)
    return true;
  else
    return false;
}

bool gear4horizontalRange(){
  if (horizontalAxisValue > gear4minimumHorizontalRange && horizontalAxisValue < gear4maximumHorizontalRange)
    return true;
  else
    return false;
}

bool gear4verticalRange(){
  if (verticalAxisValue > gear4minimumVerticalRange && verticalAxisValue < gear4maximumVerticalRange)
    return true;
  else
    return false;
}

bool gear5horizontalRange(){
  if (horizontalAxisValue > gear5minimumHorizontalRange && horizontalAxisValue < gear5maximumHorizontalRange)
    return true;
  else
    return false;
}

bool gear5verticalRange(){
  if (verticalAxisValue > gear5minimumVerticalRange && verticalAxisValue < gear5maximumVerticalRange)
    return true;
  else
    return false;
}

bool gear6horizontalRange(){
  if (horizontalAxisValue > gear6minimumHorizontalRange && horizontalAxisValue < gear6maximumHorizontalRange)
    return true;
  else
    return false;
}

bool gear6verticalRange(){
  if (verticalAxisValue > gear6minimumVerticalRange && verticalAxisValue < gear6maximumVerticalRange)
    return true;
  else
    return false;
}