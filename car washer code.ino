#include <LiquidCrystal.h>

#define BELT   3
#define BRUSH  5
#define SOAP   6
#define WATER  9
#define FAN    10

#define STAGE_SELECT  2
#define START  0

#define IR1   A0
#define IR2   A1
#define IR3   A2
#define IR4   A3

#define BELT_SPEED  200
#define STAGE_DELAY 10000

char flag=0;

LiquidCrystal lcd_1(12, 11, 13, 4, 7, 8);
                // (RS,ENABLE,PIN4,PIN5,PIN6,PIN7)
void setup()
{
  pinMode(BELT,OUTPUT);
  pinMode(BRUSH,OUTPUT);
  pinMode(SOAP,OUTPUT);
  pinMode(WATER,OUTPUT);
  pinMode(FAN,OUTPUT);

  pinMode(START,INPUT_PULLUP);
  pinMode(STAGE_SELECT,INPUT_PULLUP);

  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);

  lcd_1.begin(16,2);
  
  Serial.begin(9600);
  lcd_1.clear();
}

void loop() 
{
  unsigned char stages_num=1;
  lcd_1.setCursor(0, 0);
  lcd_1.print("Num of Stages");
  while(1)
  {
    
    lcd_1.setCursor(0, 0);
    lcd_1.print("Num of Stages");
    lcd_1.setCursor(7, 1);
    lcd_1.print(stages_num);
    if ( stages_num > 4 )
    {
     stages_num=1;
    }

    if(!digitalRead(STAGE_SELECT))
    {
      stages_num++;
      while(!digitalRead(STAGE_SELECT));
    }  

    if(!digitalRead(START))
    {
     flag=1;
      lcd_1.clear();
      lcd_1.setCursor(5, 0);
      lcd_1.print("START");
    }

    while(flag==1)
    {
     runnable(stages_num);
     delay(2000);
     lcd_1.clear();
    }

  }

}


void stage_1 (void)
{
  lcd_1.clear();
  lcd_1.setCursor(4, 0);
  lcd_1.print("Stage_1");
  analogWrite(SOAP,255);
  analogWrite(BRUSH,0);
  analogWrite(WATER,0);
  analogWrite(FAN,0);
}

void stage_2 (void)
{
  lcd_1.clear();
  lcd_1.setCursor(4, 0);
  lcd_1.print("Stage_2");
  analogWrite(SOAP,0);
  analogWrite(BRUSH,255);
  analogWrite(WATER,0);
  analogWrite(FAN,0);
}

void stage_3 (void)
{
  lcd_1.clear();
  lcd_1.setCursor(4, 0);
  lcd_1.print("Stage_3");
  analogWrite(SOAP,0);
  analogWrite(BRUSH,0);
  analogWrite(WATER,255);
  analogWrite(FAN,0);
}

void stage_4 (void)
{
  lcd_1.clear();
  lcd_1.setCursor(4, 0);
  lcd_1.print("Stage_4");
  analogWrite(SOAP,0);
  analogWrite(BRUSH,0);
  analogWrite(WATER,0);
  analogWrite(FAN,255);
}

void stop_stage (void)
{
  analogWrite(SOAP,0);
  analogWrite(BRUSH,0);
  analogWrite(WATER,0);
  analogWrite(FAN,0);
}

void runnable(char num)
{
  char fs=1;
  if (num == 1)
  {
    if(!digitalRead(IR1))
    {
      analogWrite(BELT,0);
      stage_1();
      delay(STAGE_DELAY);
      stop_stage();
      analogWrite(BELT,BELT_SPEED);
      delay(1000);
      analogWrite(BELT,0);
      flag=0;
        lcd_1.clear();
        lcd_1.setCursor(4, 0);
        lcd_1.print("FINISH");     
    }
    else
    {
      analogWrite(BELT,BELT_SPEED);
    }
  }

  else if (num == 2)
  {
    if(!digitalRead(IR1))
    {
      analogWrite(BELT,0);
      stage_1();
      delay(STAGE_DELAY);
      stop_stage();
      while(fs==1)
      {
        if(!digitalRead(IR2))
        {
          analogWrite(BELT,0);
          stage_2();
          delay(STAGE_DELAY);
          stop_stage();
          fs=0;
        }
        else
        {
          analogWrite(BELT,BELT_SPEED);
        }
      }
      
      analogWrite(BELT,BELT_SPEED);
      delay(1000);
      analogWrite(BELT,0);
      flag=0;
        lcd_1.clear();
        lcd_1.setCursor(4, 0);
        lcd_1.print("FINISH");      
    }
    else
    {
      analogWrite(BELT,BELT_SPEED);
    }
  }
  else if (num == 3)
  {
    if(!digitalRead(IR1))
    {
      analogWrite(BELT,0);
      stage_1();
      delay(STAGE_DELAY);
      stop_stage();
      while(fs==1)
      {
        if(!digitalRead(IR2))
        {
          analogWrite(BELT,0);
          stage_2();
          delay(STAGE_DELAY);
          stop_stage();
          fs=0;
        }
        else
        {
          analogWrite(BELT,BELT_SPEED);
        }
      }
      fs=1;
      while(fs==1)
      {
        if(!digitalRead(IR3))
        {
          analogWrite(BELT,0);
          stage_3();
          delay(STAGE_DELAY);
          stop_stage();
          fs=0;
        }
        else
        {
          analogWrite(BELT,BELT_SPEED);
        }
      }      
      analogWrite(BELT,BELT_SPEED);
      delay(1000);
      analogWrite(BELT,0);
      flag=0;
        lcd_1.clear();
        lcd_1.setCursor(4, 0);
        lcd_1.print("FINISH");      
    }
    else
    {
      analogWrite(BELT,BELT_SPEED);
    }
  }
  else if (num == 4)
  {
    if(!digitalRead(IR1))
    {
      analogWrite(BELT,0);
      stage_1();
      delay(STAGE_DELAY);
      stop_stage();
      while(fs==1)
      {
        if(!digitalRead(IR2))
        {
          analogWrite(BELT,0);
          stage_2();
          delay(STAGE_DELAY);
          stop_stage();
          fs=0;
        }
        else
        {
          analogWrite(BELT,BELT_SPEED);
        }
      }
      fs=1;
      while(fs==1)
      {
        if(!digitalRead(IR3))
        {
          analogWrite(BELT,0);
          stage_3();
          delay(STAGE_DELAY);
          stop_stage();
          fs=0;
        }
        else
        {
          analogWrite(BELT,BELT_SPEED);
        }
      }
      fs=1;
      while(fs==1)
      {
        if(!digitalRead(IR4))
        {
          analogWrite(BELT,0);
          stage_4();
          delay(STAGE_DELAY);
          stop_stage();
          fs=0;
        }
        else
        {
          analogWrite(BELT,BELT_SPEED);
        }
      }

      analogWrite(BELT,BELT_SPEED);
      delay(1000);
      analogWrite(BELT,0);
      flag=0;
        lcd_1.clear();
        lcd_1.setCursor(4, 0);
        lcd_1.print("FINISH");
    }
    else
    {
      analogWrite(BELT,BELT_SPEED);
    }
  }
}