// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2016.01.18
// 21:03:10
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "App.h"


/*------------------------------------------------------------------------------


 ------------------------------------------------------------------------------*/
void EEPROM_init(void)
{
  // Частота шины 16 МГц
  FTMRH_FCLKDIV = 0
                  + LSHIFT(1, 7)     // FDIVLD  | Clock Divider Loaded
                  + LSHIFT(0, 6)     // FDIVLCK | Clock Divider Locked
                  + LSHIFT(0x0F, 0)  // FDIV  | Clock Divider Bits. Рекомендованный делитель для частоты шины 16 Мгц
  ;
  FTMRH_FERCNFG = 0
                  + LSHIFT(0, 1)     // DFDIE  | Double Bit Fault Detect Interrupt Enable
                  + LSHIFT(0, 0)     // SFDIE | Single Bit Fault Detect Interrupt Enable
  ;
  FTMRH_FCNFG = 0
                + LSHIFT(0, 7)     // CCIE   | Command Complete Interrupt Enable
                + LSHIFT(0, 4)     // IGNSF  | Ignore Single Bit Fault  | 0 All single-bit faults detected during array reads are reported
                + LSHIFT(0, 1)     // FDFD   | Force Double Bit Fault Detect | 0 Flash array read operations will set the FERSTAT[DFDIF] flag only if a double bit fault is detected
                + LSHIFT(0, 0)     // FSFD   | Force Single Bit Fault Detect | 0 Flash array read operations will set the SFDIF flag in the FERSTAT register only if a single bit fault is detected.
  ;

}

/*------------------------------------------------------------------------------



 \return __ramfunc void
 ------------------------------------------------------------------------------*/
__ramfunc uint32_t EEPROM_execute(void)
{
  FTMRH_FSTAT = BIT(7); // Запускаем выполнение команды
  while ((FTMRH_FSTAT & BIT(7)) == 0); // Ожидаем завершения
  while ((FTMRH_FSTAT & BIT(3)) != 0); // Ожидаем установку MGBUSY в 0
  return FTMRH_FSTAT & ~BIT(7);
}
/*------------------------------------------------------------------------------
 Проверка стерта ли вся область EEPROM

 \return int32_t возвращает ноль если все стерто и ошибок нет
 ------------------------------------------------------------------------------*/
uint32_t EEPROM_is_errased(void)
{
  // Ожидаем готовность бита CCIF
  while ((FTMRH_FSTAT & BIT(7)) == 0);

  FTMRH_FSTAT = BIT(4) + BIT(5); // Сбрасываем ACCERR (Flash Access Error Flag) и FPVIOL (Flash Protection Violation Flag)

  FTMRH_FCCOBIX =  0;
  FTMRH_FCCOBHI =  2; // flash command
  FTMRH_FCCOBLO =  BIT(7); // Global address [23:16]

  FTMRH_FCCOBIX =  1;
  FTMRH_FCCOBHI =  0; // Global address [15:8]
  FTMRH_FCCOBLO =  0; // Global address [7:0]

  // Возвращаем результат
  return EEPROM_execute();
}

/*------------------------------------------------------------------------------
 Проверка стерта ли вся область EEPROM

 \return int32_t возвращает ноль если все стерто и ошибок нет
 ------------------------------------------------------------------------------*/
uint32_t EEPROM_is_sector_errased(uint32_t addr)
{
  // Ожидаем готовность бита CCIF
  while ((FTMRH_FSTAT & BIT(7)) == 0);

  FTMRH_FSTAT = BIT(4) + BIT(5); // Сбрасываем ACCERR (Flash Access Error Flag) и FPVIOL (Flash Protection Violation Flag)

  FTMRH_FCCOBIX =  0;
  FTMRH_FCCOBHI =  0x10; // flash command
  FTMRH_FCCOBLO =  0; // Global address [23:16]

  FTMRH_FCCOBIX =  1;
  FTMRH_FCCOBHI =  0; // Global address [15:8]
  FTMRH_FCCOBLO =  addr & 0xFE; // Global address [7:0]

  FTMRH_FCCOBIX =  2;
  FTMRH_FCCOBHI =  0; //
  FTMRH_FCCOBLO =  2; //

  // Возвращаем результат
  return EEPROM_execute();
}

/*------------------------------------------------------------------------------
  Стирает всю EEPROM

  !!! Приводит к сбросу микроконтроллера, требует тестирования
 ------------------------------------------------------------------------------*/
uint32_t EEPROM_erase_all(void)
{
  // Ожидаем готовность бита CCIF
  while ((FTMRH_FSTAT & BIT(7)) == 0);
  FTMRH_FSTAT = BIT(4) + BIT(5); // Сбрасываем ACCERR (Flash Access Error Flag) и FPVIOL (Flash Protection Violation Flag)

  FTMRH_FPROT = 0
                + LSHIFT(1, 7)     // FPOPEN | Flash Protection Operation Enable
                + LSHIFT(1, 6)     // RNV6   |
                + LSHIFT(1, 5)     // FPHDIS |
                + LSHIFT(0x03, 3)  //        |
                + LSHIFT(1, 2)     // FPLDIS |
                + LSHIFT(0x03, 0)  //
  ;


  FTMRH_FCCOBIX =  0;
  FTMRH_FCCOBHI =  0x09; // flash command
  FTMRH_FCCOBLO =  BIT(7); // Global address [23:16]

  FTMRH_FCCOBIX =  1;
  FTMRH_FCCOBHI =  0; //
  FTMRH_FCCOBLO =  0; //

  // Возвращаем результат
  return EEPROM_execute();
}


/*------------------------------------------------------------------------------


 ------------------------------------------------------------------------------*/
uint32_t EEPROM_erase_sector(uint32_t addr)
{
  // Ожидаем готовность бита CCIF
  while ((FTMRH_FSTAT & BIT(7)) == 0);
  FTMRH_FSTAT = BIT(4) + BIT(5); // Сбрасываем ACCERR (Flash Access Error Flag) и FPVIOL (Flash Protection Violation Flag)

  FTMRH_FCCOBIX =  0;
  FTMRH_FCCOBHI =  0x12; // flash command
  FTMRH_FCCOBLO =  0; // Global address [23:16]

  FTMRH_FCCOBIX =  1;
  FTMRH_FCCOBHI =  0; //
  FTMRH_FCCOBLO =  addr & 0xFF; //

  // Возвращаем результат
  return EEPROM_execute();
}

/*------------------------------------------------------------------------------
  Запись в сектор EEPROM 2-х байтного слова по адресу, адрес приводится к границе 2-х байт

  Данные в EEPROM хранятся в порядке little endian, сначала младший байт потом стращий
 ------------------------------------------------------------------------------*/
uint32_t EEPROM_program_sector(uint32_t addr, uint16_t data)
{
  // Ожидаем готовность бита CCIF
  while ((FTMRH_FSTAT & BIT(7)) == 0);
  FTMRH_FSTAT = BIT(4) + BIT(5); // Сбрасываем ACCERR (Flash Access Error Flag) и FPVIOL (Flash Protection Violation Flag)

  FTMRH_FCCOBIX =  0;
  FTMRH_FCCOBHI =  0x11; // flash command
  FTMRH_FCCOBLO =  0; // Global address [23:16]

  FTMRH_FCCOBIX =  1;
  FTMRH_FCCOBHI =  0; //
  FTMRH_FCCOBLO =  addr & 0xFE; //

  FTMRH_FCCOBIX =  2;
  FTMRH_FCCOBHI =  0; //
  FTMRH_FCCOBLO =  data & 0xFF; //

  FTMRH_FCCOBIX =  3;
  FTMRH_FCCOBHI =  0; //
  FTMRH_FCCOBLO =  (data >> 8) & 0xFF; //


  // Возвращаем результат
  return EEPROM_execute();
}

/*------------------------------------------------------------------------------
 Считывание из сектора EEPROM  2-х байтного слова по адресу, адрес приводится к границе 2-х байт

 \param addr

 \return int32_t
 ------------------------------------------------------------------------------*/
uint16_t EEPROM_read_sector(uint32_t addr)
{
  uint8_t bh;
  uint8_t bl;
  addr &= ~BIT(0);
  bl = *(uint8_t *)addr;
  bh = *(uint8_t *)(addr + 1);
  return (bh << 8) + bl;
}

/*------------------------------------------------------------------------------
 \param buf
 \param len

 \return int32_t - Возвращает 0 в случае успеха
 ------------------------------------------------------------------------------*/
uint32_t EEPROM_write(uint32_t addr, uint32_t buf, uint32_t len)
{
  uint32_t  res;

  uint16_t sdata;

  if ((addr < EEPROM_START) || (addr >= (EEPROM_START + EEPROM_SIZE)) || (len == 0))
  {
    return -1;
  }

  // Если адрес не четный, то сместить его на один байт для выравнивания и обработать первый байт
  if (addr & 1)
  {
    sdata = 0xFFFF;
    if (EEPROM_is_sector_errased(addr) != 0) // Проверим чистый ли сектор (2-а байта)
    {
      sdata = EEPROM_read_sector(addr); // Сохраним старые данные (2-а байта)
      res = EEPROM_erase_sector(addr);  // Сотрем сектор (2-а байта)
      if (res != 0) return res;
    }
    // Младший байт надо сохранить, так как он в EEPROM записывается перед старшим
    sdata = (sdata & 0x00FF) | ((*(uint8_t *)buf) << 8); // Совмещаем с данными не принадлежащими записываемой области
    res = EEPROM_program_sector(addr, sdata);
    if (res != 0) return res;
    len--;
    addr++;
    buf++;
  }


  while (len > 0)
  {
    sdata = 0xFFFF;
    if (EEPROM_is_sector_errased(addr) != 0) // Проверим чистый ли сектор (2-а байта)
    {
      sdata = EEPROM_read_sector(addr); // Сохраним старые данные (2-а байта)
      res = EEPROM_erase_sector(addr);  // Сотрем сектор (2-а байта)
      if (res != 0) return res;
    }
    if (len == 1)
    {
      // Старший байт надо сохранить, так как он в EEPROM записывается после младшего
      sdata = (sdata & 0xFF00) | (*(uint8_t *)buf); // Совмещаем с данными не принадлежащими записываемой области
      res = EEPROM_program_sector(addr, sdata);
      addr++;
      buf++;
      len--;
    }
    else
    {
      sdata = (*(uint8_t *)buf);
      buf++;
      sdata += (*(uint8_t *)buf) << 8;
      buf++;
      res = EEPROM_program_sector(addr, sdata);
      addr += 2;
      len -= 2;
    }
    if (res != 0) return res;
  }
  return 0;
}
/*------------------------------------------------------------------------------
  Чтение в буфер данных из EEPROM.
  Чтение допустимо только побайтовое. Иное стение вызывает исключение.


 \param buf
 \param len

 ------------------------------------------------------------------------------*/
void EEPROM_read(uint32_t addr, uint32_t buf, uint32_t len)
{
  int32_t i;
  for (i = 0; i < len; i++)
  {
    *(uint8_t *)buf = *(uint8_t *)addr;
    addr++;
    buf++;
  }
}


/*------------------------------------------------------------------------------
  Вывод дампа памяти области EEPROM
 ------------------------------------------------------------------------------*/
void Dump_EEPROM(void)
{
  uint8_t *buf;
  int32_t n;
  int32_t i;

  buf = (uint8_t *)EEPROM_START;

  RTT_printf("\r\n");
  n = 0;
  for (i = 0; i < EEPROM_SIZE; i++)
  {
    RTT_printf("%02X ", buf[i]);
    n++;
    if (n >= 16)
    {
      RTT_printf("\r\n");
      n = 0;
    }
  }
  RTT_printf("\r\n");
}

