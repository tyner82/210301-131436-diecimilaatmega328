#include <Arduino.h>
#include <FastLED.h>
//#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 241
#define CLOCK_PIN 5
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
#define COLOR_ORDER GRB
#define BRIGHTNESS  20

//Put these Function definitions after your #define variables
void Chase(int  ring, int tailLength, bool continuous, bool forward);
void RBSpin();

//If we have the start of each ring, we can calculate how many leds per ring
int RowStarts[] = {241,240,232,220,204,180,148,108,60,0};
// use same formula to determine how many rows based on how many numbers are in the rowstarts array
// here we get 10 even though there are actually only 9 rows
// it just helps our for loops later on
uint8_t Rows = sizeof(RowStarts) / sizeof(RowStarts[0]);
uint8_t AlternationCount = 1;
uint8_t UpdateSection = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("resetting");
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  LEDS.setBrightness(BRIGHTNESS);
}

//This is in the loop function
void loop()
{
  //RBSpin(); //original Function

  Chase(0, 5, true, true); //New Function, this function takes an 'argument' which represents which row to circle around
  
  //This is an example of a way to change the behaviour of the Chase function
  // for (int i = 0; i < Rows; i++)
  // {
  //   Chase(i, 1, i % 2 == 0);
  // }
}

//You can pick a ring to have the lights circle around
void Chase(int  ring, int tailLength, bool continuous, bool forward)
{
    if (ring > 8 || ring < 0)
    {
        ring = 8;
    }
  //if you remove the 'argument' above  so it looks like void Chase()
  //you would have to put this next line,
  //int ring = 0
  // having it as an argument means you could write other code to make this Function
  // perform in different ways
    int start;
    int finish;
  if (forward == true)
  {
    start = RowStarts[ring + 1];
    finish = RowStarts[ring];
    for(int j = start; j < finish + (continuous ? 0 : tailLength); j++)
    {
      int lastLed;

      if (j < start + tailLength)
      {
        int diff = (start+tailLength)-j;
        lastLed = finish - diff;
      }
      else lastLed = (j - tailLength) < finish ? j-tailLength : finish-1 ;
      int nextLed = j < finish ? j : finish-1;
      leds[nextLed] = CRGB::White;
      FastLED.show();
      delay(50);
      leds[lastLed] = CRGB::Black;
    }
  }
  else
  {
    start = RowStarts[ring]-1;
    finish = RowStarts[ring+1]-1;
    for(int j = start; j > finish - (continuous ? 0 : tailLength); j--)
    {
      int lastLed;

      if (j > start - tailLength )
      {
        int diff = j - (start-tailLength);
        lastLed = finish + diff;
      }
      else lastLed = j + tailLength > finish ? j + tailLength : finish + 1;
      
      int nextLed = j > finish ? j : finish + 1;
      
      leds[nextLed] = CRGB::HotPink;
      FastLED.show();
      delay(50);
      leds[lastLed].fadeToBlackBy(5);
    }
  }
}

void RBSpin()
{
  int sections = 4;
  int numColours = 2;
  int currentSection = 0;
  if (AlternationCount > 0) AlternationCount = 0;
  if (UpdateSection > sections) UpdateSection = 1;
  //Index each Ring of Leds, Last RowStart is ledZero
  for(int i=0; i < Rows-1; i++)
  {
    // RowStart[0] is center, start at rowstarts[i+1] count up from the value stored there
    // till we get to the value stored in rowstarts[i]
    // for ex. if i = 1,  for (j = 232; j < 240; j++)
    // this way we can use j as the index to send to leds[] array
    for(int j = RowStarts[i + 1]; j < RowStarts[i]; j++)
    {
      int rowCount = RowStarts[i] - RowStarts[i+1];
      // if you don't check that the number of leds on this ring is bigger
      // than the number of sections it will crash trying to divide by zero
      // so we set a default colour for those leds
      // this could be equal to some variation of j - rowstarts[i+1] to make 
      // them different colours rather then white
      int Colour = 0;
      if (rowCount > sections)
      {
        //dividing integers in c++ returns an integer, so we can use that to make sections
        currentSection = ((j - RowStarts[i+1]) / (rowCount / sections));
        // this says take whatever section this index belongs to and mod it by the number of colours
        // so with 4 sections and 2 colours, sections 0 and 2 are colour 1,
        // and 1 and 3 are colour 2, the alternation count lets us bring in more colours, say alternation
        // count is 0 then colours are 1 and 2, alternation count = 1 then colours are 3 and 4
        Colour = currentSection % numColours + AlternationCount * numColours + 1;
        // % means mod, it returns the remainder of a division operation
        // here where we are checking if x mod y equals 0, means for example
        // if rowCount is 20, and sections is 4, rowcount/sections = 5;
        // so this equation would equal zero on 0,5,10,15
        if ((j - RowStarts[i+1]) % (rowCount / sections) == 0) Colour = 0;
      }
      // only change colours if this is the first time, or it's this sections turn
      if(currentSection + 1 == UpdateSection)
      {
          if(Colour == 1)
          {
              leds[j] = CRGB::Blue;
          }
          else if(Colour == 2)
          {
              leds[j] = CRGB::Red;
          }
      }
      // need to update the last section aswell to revert it to it's original colour
      // this '?' is a ternary operator, it's the same as writing
      // int x = 0;
      // if (currentSection + 2 > sections) 
      // {
      //  x = 1;
      // } 
      // else 
      // {
      //   x = currentSection + 2;
      // }
      // if (updatesection == 0 || x == updatesection)
      else  if (UpdateSection == 0 || (currentSection + 2 > sections ? 1 : currentSection + 2 ) == UpdateSection)
      {
        if (Colour == 0)
        {
            leds[j] = CRGB::White;
        }
        else if(Colour == 1)
        {
            leds[j] = CRGB::Red;
        }
        else if(Colour == 2)
        {
            leds[j] = CRGB::Blue;
        }
      }
    } 
  }
  AlternationCount++;
  UpdateSection++;
  delay(200);
  FastLED.show();
}