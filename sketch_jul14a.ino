const char d1 = 9, d2 = 10, d3 = 11, d4 = 12; //digit controller (NOT SEGMENT)
const int numDigits = 4; //four digit display
const int interrupt = 5; //in ms, the delay for multiplexing (switching between each digit rapidly to update screen)
int startNum[] = {0, 0, 0, 0};
int loopTime = 0; //controls timer loop, summed from interrupt, everytime it reaches 1000 ms, or 1 second, it increments the seconds digit
const int interval = 100;
void setup() {
  int i;
  for(i = 0; i < 13; i++)
  {
    pinMode(i, OUTPUT); //set all pins :)
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    int digit = d1;
    int number = numDigits - 1;
    int i;
    for(i = 0; i < numDigits; i++)
    {
      selectDigit(digit);
      pickNumber(startNum[number]);
      delay(interrupt);
      ++digit;
      --number;
    }
    loopTime += interrupt * numDigits;
    if(loopTime == interval) //controls seconds digit
    {
      ++startNum[numDigits - 1];
      if(startNum[numDigits - 1] == 10) //controls tenth digit
      {
        startNum[numDigits - 1] = 0;
        ++startNum[numDigits - 2];
        if(startNum[numDigits - 2] == 10) //controls hundreds digit
        {
          startNum[numDigits - 2] = 0;
          ++startNum[numDigits - 3];
          if(startNum[numDigits - 3] == 10) //thousands! 
          {
            startNum[numDigits - 3] = 0;
            ++startNum[numDigits - 4];
          }
        }
      }
      loopTime = 0;
    }
  }


void selectDigit(int digit)
{
  int i;
  for(i = d1; i < (d4 + 1); i++)
  {
    if(i == digit)
    {
      i++;
    }
    digitalWrite(i, HIGH);
  }
  digitalWrite(digit, LOW);
}

void pickNumber(int x)   //define pickNumber(x)to display number x
{
  switch(x)
  {
  default: 
    zero(); 
    break;
  case 1: 
    one(); 
    break;
  case 2: 
    two(); 
    break;
  case 3: 
    three(); 
    break;
  case 4: 
    four(); 
    break;
  case 5: 
    five(); 
    break;
  case 6:
    six();
    break;
  case 7:
    seven();
    break;
  case 8:
    eight();
    break;
  case 9: 
    nine();
    break;
  }
}

void zero()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void one()  // define 1 as cathode pin switch
{
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void two()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void three()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);

}

void four()
{
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

void five()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

void six()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

void seven()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void eight()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

void nine()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

