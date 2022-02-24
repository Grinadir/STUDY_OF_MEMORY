

void eeprom_write_str(const char *str, char *address){
  if(FLASH_IAPSR_DUL==0){
    FLASH_DUKR = 0xAE;
    FLASH_DUKR = 0x56; 
  }
  
  for(uint8_t i=0; i<=5; i++){
  *address=str[i];
  address++;
  }
  
  FLASH_IAPSR_DUL=0;
}

void eeprom_full_clear(){
  
    if(FLASH_IAPSR_DUL==0){
    FLASH_DUKR = 0xAE;
    FLASH_DUKR = 0x56; 
  }
  char * address=(char *) 0x001000;
  for(uint32_t i=0; i<=1024; i++){
  *address=0xbb;
  address++;
  }

  
  FLASH_IAPSR_DUL=0;
}