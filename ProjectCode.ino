//Constants


//Setup & Defining functions
void DefineButtons(){
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  Serial.println("Buttons Defined");
}

void setup() {
  Serial.begin(9600);
  DefineButtons();
}
void loop() {
  if(ButtonPressed(1)){
    Serial.println("You pressed button 1");
  }

}
//Functions
//Function that checks if a button is pressed and released before returning True. buttonN corrosponds to button 1-4 on the board.
bool ButtonPressed(int buttonN){
  int buttonNf;
  switch(buttonN){
  case 1:
  buttonNf = 2;
  break;
  case 2:
  buttonNf = 3;
  break;
  case 3:
  buttonNf = 4;
  break;
  case 4:
  buttonNf = 5;
  break;  
  default:
  buttonNf =0;
  Serial.println("Button assignment error, No button:" + String(buttonN));
  break;
  }
  if((digitalRead(buttonNf)==LOW) && (buttonNf != 0)){
    while(true){
      //Serial.println("button " + String(buttonNf) + " pressed");
      if(digitalRead(buttonNf)==HIGH){
        //Serial.println("button " + String(buttonNf) + " released");
        return true;
      }
    }
  }
  else{
    return false;
  }
}
