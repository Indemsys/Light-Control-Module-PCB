#ifndef APP_EEPROM_H
  #define APP_EEPROM_H


// ѕример записи в EEPROM в переменную vcal.f1 переменной f из RAM : EEPROM_WR_VAR(vcal.f1, f)
// ѕример чтени€ из EEPROM переменной vcal.vcal  в переменную f в RAM: EEPROM_RD_VAR(vcal.vcal, f);

#define EEPROM_WR_VAR(dst_var, src_var) EEPROM_write((uint32_t)&(dst_var), (uint32_t)&(src_var), sizeof(dst_var));
#define EEPROM_RD_VAR(src_var, dst_var) EEPROM_read((uint32_t)&(src_var), (uint32_t)&(dst_var), sizeof(src_var));

void     EEPROM_init(void);
uint32_t EEPROM_is_errased(void);
uint32_t EEPROM_is_sector_errased(uint32_t addr);
uint32_t EEPROM_erase_all(void);
uint32_t EEPROM_erase_sector(uint32_t addr);
uint32_t EEPROM_program_sector(uint32_t addr, uint16_t data);
uint32_t EEPROM_write(uint32_t addr, uint32_t buf, uint32_t len);
void     EEPROM_read(uint32_t addr, uint32_t buf, uint32_t len);



#endif // APP_EEPROM_H



