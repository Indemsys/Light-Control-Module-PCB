// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2016.01.08
// 15:39:03
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "app.h"


unsigned int pos;
unsigned char disp_buf[DISPLEN];
const unsigned char ciphs[] =
{
  SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F,          //0
  SEG_B + SEG_C,                                          //1
  SEG_A + SEG_B + SEG_D + SEG_E + SEG_G,                  //2
  SEG_A + SEG_B + SEG_C + SEG_D + SEG_G,                  //3
  SEG_B + SEG_C +  SEG_F + SEG_G,                         //4
  SEG_A + SEG_C + SEG_D +  SEG_F + SEG_G,                 //5
  SEG_A + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G,          //6
  SEG_A + SEG_B + SEG_C,                                  //7
  SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G,  //8
  SEG_A + SEG_B + SEG_C + SEG_D + SEG_F + SEG_G,          //9
};

#define MAXSTRSZ 16
char nstr[MAXSTRSZ+1];

/*------------------------------------------------------------------------------
 Установка состояния сегментов


 \param val - битовая переменная биты соответствуют сегментам - a, b, c, d, e, f, g, h
 ------------------------------------------------------------------------------*/
void Set_segments(unsigned char val)
{
  if (val & SEG_A)
  {
    GPIOA_PSOR = BIT_PTA0;
  }
  else
  {
    GPIOA_PCOR = BIT_PTA0;
  }
  if (val & SEG_B)
  {
    GPIOA_PSOR = BIT_PTA1;
  }
  else
  {
    GPIOA_PCOR = BIT_PTA1;
  }
  if (val & SEG_C)
  {
    GPIOA_PSOR = BIT_PTB7;
  }
  else
  {
    GPIOA_PCOR = BIT_PTB7;
  }
  if (val & SEG_D)
  {
    GPIOA_PSOR = BIT_PTB6;
  }
  else
  {
    GPIOA_PCOR = BIT_PTB6;
  }
  if (val & SEG_E)
  {
    GPIOA_PSOR = BIT_PTC6;
  }
  else
  {
    GPIOA_PCOR = BIT_PTC6;
  }
  if (val & SEG_F)
  {
    GPIOA_PSOR = BIT_PTC7;
  }
  else
  {
    GPIOA_PCOR = BIT_PTC7;
  }
  if (val & SEG_G)
  {
    GPIOA_PSOR = BIT_PTA6;
  }
  else
  {
    GPIOA_PCOR = BIT_PTA6;
  }
  if (val & SEG_H)
  {
    GPIOA_PSOR = BIT_PTA7;
  }
  else
  {
    GPIOA_PCOR = BIT_PTA7;
  }
}

/*------------------------------------------------------------------------------
   Вывод длобальной строки nstr содержащей число с плавающей точкой на дисплей
 ------------------------------------------------------------------------------*/
static void NumToDisp()
{
  int i, k;
  unsigned char v;

  k = 0;
  for (i = 0; i < MAXSTRSZ; i++)
  {
    if ((nstr[i] >= '0') & (nstr[i] <= '9'))
    {
      v = nstr[i] - 0x30;
      disp_buf[k] = ciphs[v];
      k++;

    }
    else if (nstr[i] == '.')
    {
      if (k > 0)
      {
        disp_buf[k - 1] = disp_buf[k - 1] | SEG_H;
      }
    }
    else if (nstr[i] == '-')
    {
      disp_buf[k] = SEG_G;
      k++;
    }

    if (k >= DISPLEN) break;
  }
}

/*------------------------------------------------------------------------------
 \param fmt - строка форматирования
 \param val - величина с плавающей точкой
 ------------------------------------------------------------------------------*/
void Show_float(const char *fmt, float val)
{
  snprintf(nstr, MAXSTRSZ, fmt, val);
  NumToDisp();
}
/*------------------------------------------------------------------------------
 \param fmt - строка форматирования
 \param val - величина с плавающей точкой
 ------------------------------------------------------------------------------*/
void Show_int(const char *fmt, int val)
{
  snprintf(nstr, MAXSTRSZ, fmt, val);
  NumToDisp();
}

/*------------------------------------------------------------------------------

 \param str
 ------------------------------------------------------------------------------*/
void Show_mnemonic(const unsigned char *str)
{
  int i;
  for (i = 0; i < DISPLEN; i++)
  {
    disp_buf[i] = str[i];
  }
}
/*------------------------------------------------------------------------------


 ------------------------------------------------------------------------------*/
void Clear_display(void)
{
  int i;
  for (i = 0; i < DISPLEN; i++)
    disp_buf[i] = 0x0;
}

/*------------------------------------------------------------------------------
  Сканирование индикатора
  Вызываем из прерывания каждые 1 мс
 ------------------------------------------------------------------------------*/
void Display_scaning(void)
{
  // .....................................................................
  // Блок сканирование индикатора

  Clear_K1P(); // Отключение катодов всех 3-х индикаторов
  Clear_K2P(); // Индикаторы погасают
  Clear_K3P(); //

  Set_segments(disp_buf[pos]); // Установить состояние сегментов в позиции на дисплее с индеком pos

  switch (pos) // Подключить катод заданного индикатора
  {
  case 0:
    Set_K1P();
    break;
  case 1:
    Set_K2P();
    break;
  case 2:
    Set_K3P();
    break;
  }

  pos++;  // Увеличим индекс pos указавающий на текущию позицию на дисплее
  if (pos > 2) pos = 0;

  // Окончание блока сканирования индикатора
  // .....................................................................
}


