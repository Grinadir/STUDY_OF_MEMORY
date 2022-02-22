#include <iostm8l152c6.h>
#include "utils.h"
#include <stdint.h>
#include <string.h>


void init_uart(){
  CLK_CKDIVR=0x00; //делитель частоты 1
  CLK_PCKENR1_bit.PCKEN15 = 1;
  //PC_DDR_bit.DDR2 = 0; // PC2 на вход
  PC_DDR_bit.DDR3 = 1; // PC3 на выход
  USART1_CR2_bit.TEN=1;
  
  USART1_BRR2 = 0x03; //скорость 9600bps
  USART1_BRR1 = 0x68;

}

void print(char *str){
  
  for(uint8_t i=0;i<strlen(str);i++){
    USART1_DR=str[i];
    delay(1000000);
       
  }
  
  
  
}