#define pinButton 2
#include "pitches.h"


const byte pinLED1 = 9;
const byte pinLED2 = 10;
const byte pinLED3 = 11;

const byte pinSPK = 3;
int buzStateus = 0;
int ledst = 0;
int buzzcnt = 0;
int last = 0;
int ipt = 0;
int butt = 0;
void setup()
{
  SerialUSB.begin(9600);
  delay(3000);
  SerialUSB.println("Start");
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinSPK, OUTPUT);
}


void loop()
{

  button();
  if (buzStateus) {
    buz();
  }
  if (ledst)
    tree();
}




//int buztotal = sizeof(melody) / sizeof(int);
void button()
{
  static unsigned long downut = 0;// 시간값
  static unsigned long ut = 0;// 시간값
  static int down = 0;// 버튼 눌렸니 떨어졌니 상태
  static int btCnt = 0;

  if (down == 0)
  {
    if (digitalRead(pinButton) == LOW)
    {
      down = 1;
      SerialUSB.println("LOW");
    }
  }
  else if (down == 1)
  {
    if (digitalRead(pinButton) == HIGH)
    {
      down = 0;
      SerialUSB.println("HIGH");

      btCnt++;
      downut = millis();
    }
  }

  if (btCnt)
  {
    if (btCnt == 1)
    {
      ut = downut;
    }

    if (btCnt == 2 && millis() - ut <= 500)
    {
      btCnt = 0;
      SerialUSB.println("Double Click");
   //   buzzcnt = 0;
      buzStateus = !buzStateus;
    }
    else if (millis() - ut > 500)
    {
      btCnt = 0;
      SerialUSB.println("One Click");
      ledst++;
      ledst = ledst % 7;
    }
  }
}


