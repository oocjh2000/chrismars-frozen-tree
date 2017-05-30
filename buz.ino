int melody[] = {
  NOTE_G5, NOTE_GS5, NOTE_C5, NOTE_G5, NOTE_GS5,
  NOTE_G5, NOTE_GS5, NOTE_C5, NOTE_GS5, NOTE_G5, NOTE_AS4,
  NOTE_F5, NOTE_G5, NOTE_AS4, NOTE_F5, NOTE_G5, NOTE_AS4,
  NOTE_DS5, NOTE_CS5,

  NOTE_G5, NOTE_GS5, NOTE_C5, NOTE_G5, NOTE_GS5,
  NOTE_GS5, NOTE_G5, NOTE_C5, NOTE_GS5, NOTE_G5, NOTE_AS4,
  NOTE_F5, NOTE_G5, NOTE_AS4, NOTE_F5, NOTE_G5, NOTE_AS4,
  NOTE_DS5, NOTE_D5, NO_SOUND, NOTE_F3,

  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4,
  NOTE_C4, NOTE_AS3, NOTE_GS3, NOTE_GS3, NO_SOUND, NOTE_GS3, NOTE_GS3,
  NOTE_AS3, NOTE_AS3, NO_SOUND, NOTE_GS3, NOTE_G3, NOTE_F3,
  NO_SOUND, NO_SOUND, NOTE_F3,

  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_DS4, NOTE_DS4,
  NOTE_C4, NOTE_C4, NO_SOUND, NOTE_GS3, NOTE_GS3,
  NOTE_AS3, NOTE_C4, NO_SOUND, NO_SOUND, NOTE_AS3, NOTE_GS3, NOTE_AS3,
  NO_SOUND,

  NO_SOUND, NOTE_C4, NOTE_C4, NOTE_DS4, NOTE_F4,
  NOTE_DS4, NOTE_C4, NOTE_DS4, NOTE_DS4,
  NOTE_DS4, NOTE_CS4, NOTE_C4, NOTE_CS4,
  NOTE_C4,

  NO_SOUND, NOTE_C4, NOTE_C4, NOTE_AS3, NOTE_GS3, NOTE_AS3,
  NO_SOUND, NOTE_C4, NOTE_C4, NOTE_AS3, NOTE_GS3,
  NOTE_F3,
  NO_SOUND,

  NO_SOUND, NOTE_AS3, NOTE_AS3, NOTE_DS4, NOTE_DS4,
  NOTE_AS3, NOTE_AS3, NOTE_F4, NOTE_F4,
  NO_SOUND, NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_F4, NO_SOUND, NOTE_DS4,
  NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_G4,

  NO_SOUND, NOTE_AS3, NOTE_AS3, NOTE_DS4, NOTE_DS4,
  NO_SOUND, NOTE_AS3, NOTE_AS3, NOTE_F4, NOTE_F4,
  NO_SOUND, NOTE_DS4, NOTE_F4,

  NOTE_G4, NOTE_GS4, NOTE_GS4,
  NO_SOUND, NOTE_F4, NOTE_G4, NOTE_GS4,
  NO_SOUND, NOTE_DS4, NOTE_DS4, NOTE_AS4,
  NO_SOUND, NOTE_GS4, NOTE_F4,

  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_GS4,
  NO_SOUND, NOTE_F4, NOTE_G4, NOTE_GS4,
  NO_SOUND, NOTE_DS4, NOTE_C5, NOTE_C5,
  NOTE_AS4, NO_SOUND, NOTE_GS4, NOTE_AS4, NOTE_C5,

  NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS4, NOTE_GS4,
  NOTE_AS4, NOTE_GS4, NO_SOUND,
  NOTE_DS5, NOTE_C5, NOTE_AS4,
  NO_SOUND, NOTE_GS4, NOTE_GS4,

  NOTE_DS5, NOTE_C5, NOTE_GS4,
  NO_SOUND, NO_SOUND, NOTE_GS4, NOTE_GS4,
  NOTE_G4, NOTE_DS4, NOTE_DS4,
  NO_SOUND, NOTE_GS3,

  NOTE_CS4, NOTE_CS4, NOTE_C4, NOTE_CS4, NOTE_C4, NOTE_CS4, NOTE_CS4,
  NOTE_C4, NOTE_GS3, NO_SOUND,
  
  NO_SOUND
  };
int noteDurations[] = {
  8, 8, 8, 4, 3,
  8, 8, 8, 4, 4, 8,
  8, 8, 8, 4, 4, 8,
  2, 2,

  8, 8, 8, 4, 3,
  8, 8, 8, 4, 4, 8,
  8, 8, 8, 4, 4, 8,
  2, 4, 8, 8,

  4, 4, 4, 8, 8,
  8, 8, 8, 8, 4, 8, 8,
  8, 3, 8, 8, 8, 1.75,
  4, 8, 8,

  8, 8, 8, 3, 8, 8,
  8, 3, 4, 8, 8,
  8, 8, 4, 8, 8, 8, 8,
  1,

  4, 8, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 8,
  1,

  4, 8, 8, 8, 4, 8,
  4, 8, 8, 4, 2,
  1.5,
  1,

  4, 8, 4, 4, 4,
  4, 4, 4, 8,
  4, 8, 8, 8, 8, 8, 8,
  8, 4, 4, 4, 8,

  4, 8, 4, 4, 8,
  4, 8, 4, 4, 1,
  4, 8, 4,

  4, 8, 1,
  8, 8, 8, 1.75,
  8, 8, 8, 1.75,
  4, 8, 8,

  8, 8, 4, 8, 4, 1.75,
  8, 8, 8, 1.75,
  8, 8, 8, 8,
  2, 8, 8, 8, 4,

  4, 4, 8, 8, 8,
  8, 4, 2,
  3, 3, 2,
  4, 4, 4,

  3, 3, 2,
  4, 4, 8, 8,
  3, 3, 1,
  8, 8,

  4, 8, 8, 8, 8, 8, 8,
  8, 8, 8,

  3
  };
  int buztotal = sizeof(melody) / sizeof(int);
void buz()
{
  static unsigned long ut = 0;
 int i = buzzcnt;

  unsigned long t = millis();

  int duration = 1500 / noteDurations[i];
  
  if(t - ut >= duration)
  {
//    SerialUSB.println(i);

    tone(pinSPK, melody[i], duration);
    i++;
    i = i % buztotal;
    ut = millis();
    buzzcnt=i;
  }
}

