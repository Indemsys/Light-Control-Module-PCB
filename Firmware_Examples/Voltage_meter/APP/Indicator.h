#ifndef INDICATOR_H
  #define INDICATOR_H

void Clear_display(void);
void Show_float(const char *fmt, float val);
void Show_int(const char *fmt, int val);
void Show_mnemonic(unsigned char *str);

void Set_LED(void);
void Clear_LED(void);

#endif // INDICATOR_H



