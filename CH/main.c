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
			Data_Send_PID2();   //发送PID2 在上位机中点击 读取飞控  其中PID3.P用来传输目标速度值 
		    FLAG_RETURN = 0;
		}

}

