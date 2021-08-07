void BacaKeypad()
{
  while(KeyA>10)
  {
    KeyA=analogRead(Key);
    if(Trig == 0)
    {
      for(int i=0;i<5;i++)
      {
        KeyA=analogRead(Key);
        Max=KeyA;
        delay(10);
      }
      Trig = 1;
    }

    if(Sama<12)
    {
      if(KeyA!=Max)
      {
        if(KeyA>Max)
        {
          Max = KeyA-Max;
        }
        else
        {
          Max = Max-KeyA;
        }
        if(Max<50)
        {
          Sama++;
          if(Sama>5)
          {
            Output=KeyA;
          }
        }
        else
        {
          Max=KeyA;
          if(Sama>0)
          {
            Sama--;
          }
        }
      }
      else
      {
        Sama++;
        if(Sama>5)
        {
          Output=KeyA;
        }
      }
    }
  }
}
