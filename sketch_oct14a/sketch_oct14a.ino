const int PIN_ONE = 4;
const int PIN_TWO = 5;
const int PIN_THREE = 6;
const int PIN_FOUR = 7;
const int PIN_FIVE = 8;
const int BUZZER = 3;
const int BUTTON = 2;
const int SENSOR = A0;
int lectura = 0;
int prevLectura = 0;
int LEDS [5] = { PIN_ONE, PIN_TWO, PIN_THREE, PIN_FOUR, PIN_FIVE};


void setup()
{
  Serial.begin(9600);
pinMode(BUTTON, INPUT);
pinMode(BUZZER, OUTPUT);
  for(int i = 0; i < 5; i++){
    pinMode(LEDS[i],OUTPUT);
  };
 
}

void loop()
{
  lectura = porcentaje(analogRead(SENSOR));
  
  if(prevLectura != lectura) {
    Serial.print(lectura);
    Serial.println();
    prevLectura = lectura; 

  }
  
  for(int i = 0; i < 5; i++){
    digitalWrite(LEDS [i], LOW);
  };
  
  if (lectura = 100){
    for(int i = 0; i < 5; i++){
      digitalWrite(LEDS [i], HIGH);
    } 
  }else if( lectura > 80 && lectura < 100){
      for(int i = 0; i < 4; i++){
      digitalWrite(LEDS [i], HIGH);
      }
    }else if( lectura > 60 && lectura < 80){
      for(int i = 0; i < 3; i++){
      digitalWrite(LEDS [i], HIGH);
      }
    }else if( lectura > 40 && lectura < 60){
      for(int i = 0; i < 2; i++){
      digitalWrite(LEDS [i], HIGH);
  }
    }else if( lectura > 20 && lectura < 40){
      for(int i = 0; i < 1; i++){
      digitalWrite(LEDS [i], HIGH);
  }
    }else if( lectura > 0 && lectura < 20){
      for(int i = 0; i < 5; i++){
      digitalWrite(LEDS [i], LOW);
  		}
    }
    
  
  delay(100);
}

int porcentaje (float value) {
  return round(value / 1023 * 100);
}