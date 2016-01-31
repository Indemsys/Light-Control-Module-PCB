#ifndef INDICATOR_H
  #define INDICATOR_H

void Clear_display(void);
void Fill_display(uint8_t v);
void Show_float(const char *fmt, float val, uint8_t offs);
void Show_int(const char *fmt, int32_t val, uint8_t offs);
void Show_mnemonic(uint8_t *str);

void Set_LED(void);
void Clear_LED(void);

#endif // INDICATOR_H



