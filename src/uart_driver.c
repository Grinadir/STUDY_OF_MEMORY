#include <iostm8l152c6.h>



void init_uart(){
  CLK_CKDIVR=0x00; //�������� ������� 1
  CLK_PCKENR1_bit.PCKEN15 = 1;
  //PC_DDR_bit.DDR2 = 0; // PC2 �� ����
  PC_DDR_bit.DDR3 = 1; // PC3 �� �����
  USART1_CR2_bit.TEN=1;
  
  USART1_BRR2 = 0x03; //�������� 9600bps
  USART1_BRR1 = 0x68;
  USART1_DR='S';
  USART1_DR='T';
}

void print(char str[]){
  for(int i=0;i<=sizeof(str);i++){
    USART1_DR=str[i];
       
  }
  
  
  
}