
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/


#ifndef		__CONFIG_H
#define		__CONFIG_H


/*********************************************************/

#define MAIN_Fosc		22118400L	//定义主时钟
//#define MAIN_Fosc		12000000L	//定义主时钟
//#define MAIN_Fosc		11059200L	//定义主时钟
//#define MAIN_Fosc		 5529600L	//定义主时钟
//#define MAIN_Fosc		24000000L	//定义主时钟


/*********************************************************/

#include	"STC15Fxxxx.H"
typedef struct PID{float SetSpeed,ActualSpeed,err,err_last,Kp,Ki,Kd,voltage,integral;}PID;
extern PID PID_PID_2;
extern U8 FLAG_RETURN;
#define S16  int 
#define BYTE0(dwTemp)       (*(U8 *)(&dwTemp))
#define BYTE1(dwTemp)       (*((U8 *)(&dwTemp) + 1))
#define BYTE2(dwTemp)       (*((U8 *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((U8 *)(&dwTemp) + 3))
extern bit data_to_send_ok;
extern bit sys_clk;
extern U8 data_to_send[40];
void PID_init();
void Timer_config(void);
void shangweiji(void);
#endif
