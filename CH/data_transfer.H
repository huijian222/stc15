
#ifndef __DATA_TRANSFER_H_
#define __DATA_TRANSFER_H_
#include "CONFIG.H"
//void Data_Send_Senser(float sv,float pv);
void Data_Receive_Anl(U8 *data_buf,U8 num);
void Data_Send_Check(U8 check);
void Data_Send_Senser(float sv,float pv);
void PrintString1(U8 *puts,U8 _cnt)	;	//·¢ËÍÒ»´®×Ö·û´®
#endif