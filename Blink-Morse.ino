//Length of time in ms a short and long dash should stay bright on the led
const int SHORT_DASH_BLNK_LEN = 500;
const int LONG_DASH_BLNK_LEN = 1800;

const int MORSE_CHAR_COUNT = 36;
const int MORSE_SEQ_MAX_LEN = 6;

//constants used for Morse code definition map
const char SHORT_DASH = '.';
const char LONG_DASH = '-';

//definitions for morse code characters 
char morseDict[MORSE_CHAR_COUNT][MORSE_SEQ_MAX_LEN] = 
{
  
  {SHORT_DASH,LONG_DASH,'\0'},
  {LONG_DASH,SHORT_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,SHORT_DASH,LONG_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {SHORT_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,LONG_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,LONG_DASH,SHORT_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,'\0'},
  {SHORT_DASH,LONG_DASH,LONG_DASH,LONG_DASH,'\0'},
  {LONG_DASH,SHORT_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,LONG_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,LONG_DASH,'\0'},
  {LONG_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,LONG_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,LONG_DASH,LONG_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,LONG_DASH,SHORT_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,LONG_DASH,SHORT_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,SHORT_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,LONG_DASH,LONG_DASH,'\0'},
  {LONG_DASH,SHORT_DASH,SHORT_DASH,LONG_DASH,'\0'},
  {LONG_DASH,SHORT_DASH,LONG_DASH,LONG_DASH,'\0'},
  {LONG_DASH,LONG_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,LONG_DASH,LONG_DASH,LONG_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,LONG_DASH,LONG_DASH,LONG_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,LONG_DASH,LONG_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,SHORT_DASH,LONG_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,SHORT_DASH,SHORT_DASH,LONG_DASH,'\0'},
  {SHORT_DASH,SHORT_DASH,SHORT_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,SHORT_DASH,SHORT_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,LONG_DASH,SHORT_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,LONG_DASH,LONG_DASH,SHORT_DASH,SHORT_DASH,'\0'},
  {LONG_DASH,LONG_DASH,LONG_DASH,LONG_DASH,SHORT_DASH,'\0'}
  
};

//An index of the Morse dictionary for convinience 
char morseCharMap[MORSE_CHAR_COUNT];

char* message;
char currSignal = '\0';
int currMsgIdx = 0;

void blinkDelay(int duration)
{
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(duration);// wait for the set duration
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(SHORT_DASH_BLNK_LEN);  //delay in between signals
}

void blinkMorseChar(char letter)
{
  if( letter == ' ' )
  {
    delay(1000);
  }
  else
  {
    char* seq = morseDict[ morseCharMap[letter] ];
    
    for(int i=0;i<MORSE_SEQ_MAX_LEN;i++)
    {
      if( seq[i] == '\0' )
      {
        break;
      }
      else
      {
        int duration = SHORT_DASH_BLNK_LEN;
  
        if( seq[i] == LONG_DASH )
        {
           duration = LONG_DASH_BLNK_LEN;
        }
        
        blinkDelay(duration);
        
      }
    }
  }
}

// the setup function runs once when you press reset or power the board
void setup() 
{
  // initialize digital pin 13 as an output. (Same pin used in Blink)
  pinMode(13, OUTPUT);

  morseCharMap['a'] = 0;
  morseCharMap['b'] = 1;
  morseCharMap['c'] = 2;
  morseCharMap['d'] = 3;
  morseCharMap['e'] = 4;
  morseCharMap['f'] = 5;
  morseCharMap['g'] = 6;
  morseCharMap['h'] = 7;
  morseCharMap['i'] = 8;
  morseCharMap['j'] = 9;
  morseCharMap['k'] = 10;
  morseCharMap['l'] = 11;
  morseCharMap['m'] = 12;
  morseCharMap['n'] = 13;
  morseCharMap['o'] = 14;
  morseCharMap['p'] = 15;
  morseCharMap['q'] = 16;
  morseCharMap['r'] = 17;
  morseCharMap['s'] = 18;
  morseCharMap['t'] = 19;
  morseCharMap['u'] = 20;
  morseCharMap['v'] = 21;
  morseCharMap['w'] = 22;
  morseCharMap['x'] = 23;
  morseCharMap['y'] = 24;
  morseCharMap['z'] = 25;
  morseCharMap['0'] = 26;
  morseCharMap['1'] = 27;
  morseCharMap['2'] = 28;
  morseCharMap['3'] = 29;
  morseCharMap['4'] = 30;
  morseCharMap['5'] = 31;
  morseCharMap['6'] = 32;
  morseCharMap['7'] = 33;
  morseCharMap['8'] = 34;
  morseCharMap['9'] = 35;

  message = "war and greed are bad";
}

// the loop function runs over and over again forever
//It will move from each letter in the 'message' variable 
void loop() 
{ 
  if( currSignal == '\0' )
  {
    currMsgIdx = 0;
  }
  else
  {
    currMsgIdx++;

    if(message[currMsgIdx] == '\0')
    {
      currMsgIdx = 0;
    }
  }
  
  blinkMorseChar( message[currMsgIdx] );
  currSignal = message[currMsgIdx];
  
}
