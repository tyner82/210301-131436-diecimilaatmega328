#include <FastLED.h>
//#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 241
#define CLOCK_PIN 5
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
#define COLOR_ORDER GRB
#define BRIGHTNESS  20


//THESE ARE MY LED ARRAYS
/*
int A [ ] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
int B [ ] = {15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
int C [ ] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44};
int D [ ] = {45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
int E [ ] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71};
int F [ ] = {72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83};
int G [ ] = {84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95};
int H [] = {96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107};
int I [] = {108, 109, 110, 111, 112, 113, 114, 115, 116, 117};
int J [] = {118, 119, 120, 121, 122, 123, 124, 125, 126, 127};
int K [] = {128, 129, 130, 131, 132, 133, 134, 135, 136, 137};
int L [] = {138, 139, 140, 141, 142, 143, 144, 145, 146, 147};
int M [] = {148, 149, 150, 151, 152, 153, 154, 155};
int N [] = {156, 157, 158, 159, 160, 161, 162, 163};
int O [] = {164, 165, 166, 167, 168, 169, 170, 171};
int P [] = {172, 173, 174, 175, 176, 177, 178, 179};
int Q [] = {180, 181, 182, 183, 184, 185};
int R [] = {186, 187, 188, 189, 190, 191};
int S [] = {192, 193, 194, 195, 196, 197};
int T [] = {198, 199, 200, 201, 202, 203};
int U [] = {204, 205, 206, 207};
int V [] = {208, 209, 210, 211};
int W [] = {212, 213, 214, 215};
int X [] = {216, 217, 218, 219};
int Y [] = {220, 221, 222};
int Z [] = {223, 224, 225};
int AA [] = {226, 227, 228};
int BB [] = {229, 230, 231};
int CC [] = {232, 233};
int DD [] = {234, 235};
int EE [] = {236, 237};
int FF [] = {238, 239};
int GG [] = {240};
*/
int HH [] = {0,15,30,45,60,72,84,96,108,118,128,138,148,156,164,172,180,186,192,198,204,208,212,216,220,223,226,229,232,234,236,238,240};
int II [] = {0,30,60,84,108,128,148,164,180,192,204,212,220,226,232,236,240};
int JJ [] = {15,45,72,96,118,138,156,172,186,198,208,216,223,229,234,238,240};
int KK [] = {238, 239,229,230,231,216, 217, 218, 219,198, 199, 200, 201, 202, 203,172, 173, 174, 175, 176, 177, 178, 179,138, 139, 140, 141, 142, 143, 144, 145, 146, 147,96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107,45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
int LL [] = {236, 237,226, 227, 228,212, 213, 214, 215,192, 193, 194, 195, 196, 197,164, 165, 166, 167, 168, 169, 170, 171,128, 129, 130, 131, 132, 133,134, 135, 136, 137,84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44};
int MM [] = {234, 235,223, 224, 225,208, 209, 210, 211,186, 187, 188, 189, 190, 191,156, 157, 158, 159, 160, 161, 162, 163,118, 119, 120, 121, 122, 123, 124, 125, 126, 127,72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83,15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
int NN [] = {232, 233,220, 221, 222,204, 205, 206, 207,180, 181, 182, 183, 184, 185,148, 149, 150, 151, 152, 153, 154, 155,108, 109, 110, 111, 112, 113, 114, 115, 116, 117,60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
/*
int i;                                              // counting variable
int x;
int loop1 = 0, loop2 = 0;
uint8_t sizeA = sizeof(A) / sizeof(A[0]);
uint8_t sizeB = sizeof(B) / sizeof(B[0]);
uint8_t sizeC = sizeof(C) / sizeof(C[0]);
uint8_t sizeD = sizeof(D) / sizeof(D[0]);
uint8_t sizeE = sizeof(E) / sizeof(E[0]);
uint8_t sizeF = sizeof(F) / sizeof(F[0]);
uint8_t sizeG = sizeof(G) / sizeof(G[0]);
uint8_t sizeH = sizeof(H) / sizeof(H[0]);
uint8_t sizeI = sizeof(I) / sizeof(I[0]);
uint8_t sizeJ = sizeof(J) / sizeof(J[0]);
uint8_t sizeK = sizeof(K) / sizeof(K[0]);
uint8_t sizeL = sizeof(L) / sizeof(L[0]);
uint8_t sizeM = sizeof(M) / sizeof(M[0]);
uint8_t sizeN = sizeof(N) / sizeof(N[0]);
uint8_t sizeO = sizeof(O) / sizeof(O[0]);
uint8_t sizeP = sizeof(P) / sizeof(P[0]);
uint8_t sizeQ = sizeof(Q) / sizeof(Q[0]);
uint8_t sizeR = sizeof(R) / sizeof(R[0]);
uint8_t sizeS = sizeof(S) / sizeof(S[0]);
uint8_t sizeT = sizeof(T) / sizeof(T[0]);
uint8_t sizeU = sizeof(U) / sizeof(U[0]);
uint8_t sizeV = sizeof(V) / sizeof(V[0]);
uint8_t sizeW = sizeof(W) / sizeof(W[0]);
uint8_t sizeX = sizeof(X) / sizeof(X[0]);
uint8_t sizeY = sizeof(Y) / sizeof(Y[0]);
uint8_t sizeZ = sizeof(Z) / sizeof(Z[0]);
uint8_t sizeAA = sizeof(AA) / sizeof(AA[0]);
uint8_t sizeBB = sizeof(BB) / sizeof(BB[0]);
uint8_t sizeCC = sizeof(CC) / sizeof(CC[0]);
uint8_t sizeDD = sizeof(DD) / sizeof(DD[0]);
uint8_t sizeEE = sizeof(EE) / sizeof(EE[0]);
uint8_t sizeFF = sizeof(FF) / sizeof(FF[0]);
uint8_t sizeGG = sizeof(GG) / sizeof(GG[0]);
*/
uint8_t sizeHH = sizeof(HH) / sizeof(HH[0]);
uint8_t sizeII = sizeof(II) / sizeof(II[0]);
uint8_t sizeJJ = sizeof(JJ) / sizeof(JJ[0]);
uint8_t sizeKK = sizeof(KK) / sizeof(KK[0]);
uint8_t sizeLL = sizeof(LL) / sizeof(LL[0]);
uint8_t sizeMM = sizeof(MM) / sizeof(MM[0]);
uint8_t sizeNN = sizeof(NN) / sizeof(NN[0]);
void setup()
{
  Serial.begin(9600);
  Serial.println("resetting");
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  LEDS.setBrightness(BRIGHTNESS);
 
}

void loop()
{
  for (uint8_t i = 0; i < sizeKK; i++)
  {
    leds[ KK[i] ] = CRGB::Red;
  }
  delay(100);
  FastLED.show();

  for (uint8_t i = 0; i < sizeKK; i++)
  {
    leds[KK[i] ] = CRGB::Blue;
  }
  delay(200);
  FastLED.show();
 //--------------------------------------------------
  for (uint8_t i = 0; i < sizeHH; i++)
  {
    leds[ HH[i] ] = CRGB::White;
  }
  delay(0);
  FastLED.show();


 //--------------------------------------------------

 for (uint8_t i = 0; i < sizeLL; i++)
  {
    leds[ LL[i] ] = CRGB::Blue;
  }
  delay(100);
  FastLED.show();

  for (uint8_t i = 0; i < sizeLL; i++)
  {
    leds[LL[i] ] = CRGB::Red;
  }
  delay(200);
  FastLED.show();
 //--------------------------------------------------
 for (uint8_t i = 0; i < sizeHH; i++)
  {
    leds[ HH[i] ] = CRGB::White;
  }
  delay(0);
  FastLED.show();

 //--------------------------------------------------
 for (uint8_t i = 0; i < sizeMM; i++)
  {
    leds[ MM[i] ] = CRGB::Red;
  }
  delay(100);
  FastLED.show();

  for (uint8_t i = 0; i < sizeMM; i++)
  {
    leds[MM[i] ] = CRGB::Blue;
  }
  delay(200);
  FastLED.show();
  //---------------------------------------------------
  for (uint8_t i = 0; i < sizeHH; i++)
  {
    leds[ HH[i] ] = CRGB::White;
  }
  delay(0);
  FastLED.show();

 
 //--------------------------------------------------
   for (uint8_t i = 0; i < sizeNN; i++)
  {
    leds[ NN[i] ] = CRGB::Blue;
  }
  delay(100);
  FastLED.show();

  for (uint8_t i = 0; i < sizeNN; i++)
  {
    leds[NN[i] ] = CRGB::Red;
  }
  delay(200);
  FastLED.show();
  //---------------------------------------------------
  for (uint8_t i = 0; i < sizeHH; i++)
  {
    leds[ HH[i] ] = CRGB::White;
  }
  delay(0);
  FastLED.show();


 //--------------------------------------------------
}
