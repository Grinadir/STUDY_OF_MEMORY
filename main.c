#include "uart_driver.h"
#include <stdint.h>
#include "eeprom_driver.c"


int main( void )
{
  char str[]="RABOTA";
  eeprom_full_clear();
  eeprom_write_str(str, (char *) 0x1002);
  
  init_uart();
  print("START\r\n");
  return 0;
}

