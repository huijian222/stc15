#include	"config.h"
#include	"USART1.h"
#include	"delay.h"

void main(void)
{
	UART_config();
	Timer_config();
	EA = 1;
	PID_init();
	while (1){
		shangweiji();
	}
}

void shangweiji(void){
		if(sys_clk){
		 	Data_Send_Senser(0,0);
		 	sys_clk = 0;
		}	
	 	if(data_to_send_ok){
	 		data_to_send_ok=0;																    
			PrintString1(data_to_send,8);
	 	}
		if(FLAG_RETURN == 1){
			Data_Send_PID2();   //����PID2 ����λ���е�� ��ȡ�ɿ�  ����PID3.P��������Ŀ���ٶ�ֵ 
		    FLAG_RETURN = 0;
		}

}

