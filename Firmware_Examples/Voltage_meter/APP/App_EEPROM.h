#ifndef APP_EEPROM_H
  #define APP_EEPROM_H


// ѕример записи в EEPROM в переменную vcal.f1 переменной f из RAM : EEPROM_WR_VAR(vcal.f1, f)
// ѕример чтени€ из EEPROM переменной vcal.vcal  в переменную f в RAM: EEPROM_RD_VAR(vcal.vcal, f);

#define EEPROM_WR_VAR(dst_var, src_var) EEPROM_write((unsigned int)&(dst_var), (unsigned int)&(src_var), sizeof(dst_var));
#define EEPROM_RD_VAR(src_var, dst_var) EEPROM_read((unsigned int)&(src_var), (unsigned int)&(dst_var), sizeof(src_var));

void   EEPROM_init(void);
int    EEPROM_is_errased(void);
int    EEPROM_is_sector_errased(unsigned int addr);
int    EEPROM_erase_all(void);
int    EEPROM_erase_sector(unsigned int addr);
int    EEPROM_program_sector(unsigned int addr, unsigned short data);
int    EEPROM_write(unsigned int addr, unsigned int buf, unsigned int len);
void   EEPROM_read(unsigned int addr, unsigned int buf, unsigned int len);



#endif // APP_EEPROM_H



