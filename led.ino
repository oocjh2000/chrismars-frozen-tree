int tree()
{
  static unsigned long ut = 0;
 int i = ledst;
  static int fade = 0;
  static int ct = 1;

  unsigned long t = millis();

  if(t - ut >= 10)
  {
    if(i == 0)
    {
      SerialUSB.println("OFF");
      analogWrite(pinLED1, 0);
      analogWrite(pinLED2, 0);
      analogWrite(pinLED3, 0);
    }
    if(i == 1)
    {
      analogWrite(pinLED1, fade);
      analogWrite(pinLED2, 0);
      analogWrite(pinLED3, 0);
    }
    if(i == 2)
    {
      analogWrite(pinLED1, 0);
      analogWrite(pinLED2, fade);
      analogWrite(pinLED3, fade);
    }
    if(i == 3)
    {
      analogWrite(pinLED1, fade);
      analogWrite(pinLED2, fade);
      analogWrite(pinLED3, 0);
    }
    if(i == 4)
    {
      analogWrite(pinLED1, 0);
      analogWrite(pinLED2, 0);
      analogWrite(pinLED3, fade);
    }
    if(i == 5)
    {
      analogWrite(pinLED1, 0);
      analogWrite(pinLED2, fade);
      analogWrite(pinLED3, 0);
    }
    if(i == 6)
    {
      analogWrite(pinLED1, fade);
      analogWrite(pinLED2, 0);
      analogWrite(pinLED3, fade);
    }

    fade += ct;

   if(fade == 255 || fade == 0)
    {
      ct *= -1;
      if(ct > 0)
      {
      /*  i++;
        i = i % 7;*/
      }
    }
    ut = millis();
  }
}

