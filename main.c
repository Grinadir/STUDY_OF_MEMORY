#include "uart_driver.h"
#include <stdint.h>

__eeprom uint8_t buf[]={0xD0, 0xCE, 0xD1, 0xD1, 0xC8, 0xDF};

void eeprom_write_str(const char *str, char *address){
  
  unsigned char i=0;
  while(str[1]){
    
    *address++=str[i];
    i++;
  }
  *address++='\0';

}

int main( void )
{
  FLASH_DUKR = 0xAE;
  FLASH_DUKR = 0x56; 
  //char *address=0x001000;
  //&adress=0xD0;
  char str[]="JOPA";
  eeprom_write_str(str, (char *) 0x001002);


  //FLASH_ProgramBlock(0, FLASH_MemType_Data, FLASH_ProgramMode_Standart, buf);
  
  init_uart();
  print("START\r\n");
  return 0;
}

