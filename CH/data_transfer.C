#include "data_transfer.h"
#include "USART1.H"
bit data_to_send_ok=0;
extern 	PID PID_PID_2;
U8 data_to_send[40],FLAG_RETURN;
void Data_Receive_Anl(U8 *data_buf,U8 num)
{

//	S16 rc_value_temp;
	U8 sum = 0,i=0;
	for( i=0;i<(num-1);i++)sum += *(data_buf+i);
	if(!(sum==*(data_buf+num-1)))		return;		//??sum
	if(!(*(data_buf)==0xAA && *(data_buf+1)==0xAF))		return;		//????
/////////////////////////////////////////////////////////////////////////////////////
	if(*(data_buf+2)==0X01)
	{
		if(*(data_buf+4)==0X01);
		if(*(data_buf+4)==0X02);
		if(*(data_buf+4)==0X03);
		if(*(data_buf+2)==0X02)
		{
			if(*(data_buf+4)==0X01)
			{
	//			Send_PID1 = 1;
	//			Send_PID2 = 1;
	//			Send_PID3 = 1;
	//			Send_PID4 = 1;
	//			Send_PID5 = 1;
	//			Send_PID6 = 1;
			}
			if(*(data_buf+4)==0X02);
	//			Send_Offset = 1;
		}
	}
	if(*(data_buf+2)==0X12)								//PID3
	{
			PID_PID_2.Kp = (float)((S16)(*(data_buf+4)<<8)|*(data_buf+5))/100;
			PID_PID_2.Ki = (float)((S16)(*(data_buf+6)<<8)|*(data_buf+7))/100;
			PID_PID_2.Kd = (float)((S16)(*(data_buf+8)<<8)|*(data_buf+9))/100;
//   		PID_PID_3.P = (float)((S16)(*(data_buf+10)<<8)|*(data_buf+11))/100;
//			PID_PID_3.I = (float)((S16)(*(data_buf+12)<<8)|*(data_buf+13))/100;
//   		PID_PID_3.D = (float)((S16)(*(data_buf+14)<<8)|*(data_buf+15))/100;
//			PID_PID_4.P = (float)((S16)(*(data_buf+16)<<8)|*(data_buf+17))/100;
//			PID_PID_4.I = (float)((S16)(*(data_buf+18)<<8)|*(data_buf+19))/100;
//			PID_PID_4.D = (float)((S16)(*(data_buf+20)<<8)|*(data_buf+21))/100;
	//		Data_Send_Check(sum);
	}
	if(*(data_buf+2)==0X13)								//PID4
	{
//			PID_PID_5.P = (float)((vs16)(*(data_buf+4)<<8)|*(data_buf+5))/100;
//			PID_PID_5.I = (float)((vs16)(*(data_buf+6)<<8)|*(data_buf+7))/100;
//			PID_PID_5.D = (float)((vs16)(*(data_buf+8)<<8)|*(data_buf+9))/100;
//			PID_PID_6.P = (float)((vs16)(*(data_buf+10)<<8)|*(data_buf+11))/100;
//			PID_PID_6.I = (float)((vs16)(*(data_buf+12)<<8)|*(data_buf+13))/100;
//			PID_PID_6.D = (float)((vs16)(*(data_buf+14)<<8)|*(data_buf+15))/100;
//			PID_PID_7.P = (float)((vs16)(*(data_buf+16)<<8)|*(data_buf+17))/100;
//			PID_PID_7.I = (float)((vs16)(*(data_buf+18)<<8)|*(data_buf+19))/100;
//			PID_PID_7.D = (float)((vs16)(*(data_buf+20)<<8)|*(data_buf+21))/100;
//			Data_Send_Check(sum);
	}
	if(*(data_buf+2)==0X14)								//PID5
	{
//			PID_PID_8.P = (float)((vs16)(*(data_buf+4)<<8)|*(data_buf+5))/100;
//			PID_PID_8.I = (float)((vs16)(*(data_buf+6)<<8)|*(data_buf+7))/100;
//			PID_PID_8.D = (float)((vs16)(*(data_buf+8)<<8)|*(data_buf+9))/100;
//			PID_PID_9.P = (float)((vs16)(*(data_buf+10)<<8)|*(data_buf+11))/100;
//			PID_PID_9.I = (float)((vs16)(*(data_buf+12)<<8)|*(data_buf+13))/100;
//			PID_PID_9.D = (float)((vs16)(*(data_buf+14)<<8)|*(data_buf+15))/100;
//			PID_PID_10.P = (float)((vs16)(*(data_buf+16)<<8)|*(data_buf+17))/100;
//			PID_PID_10.I = (float)((vs16)(*(data_buf+18)<<8)|*(data_buf+19))/100;
//			PID_PID_10.D = (float)((vs16)(*(data_buf+20)<<8)|*(data_buf+21))/100;
//			Data_Send_Check(sum);
	}
	if(*(data_buf+2)==0X15)								//PID6
	{
//			PID_PID_11.P = (float)((vs16)(*(data_buf+4)<<8)|*(data_buf+5))/100;
//			PID_PID_11.I = (float)((vs16)(*(data_buf+6)<<8)|*(data_buf+7))/100;
//			PID_PID_11.D = (float)((vs16)(*(data_buf+8)<<8)|*(data_buf+9))/100;
//			PID_PID_12.P = (float)((vs16)(*(data_buf+10)<<8)|*(data_buf+11))/100;
//			PID_PID_12.I = (float)((vs16)(*(data_buf+12)<<8)|*(data_buf+13))/100;
//			PID_PID_12.D = (float)((vs16)(*(data_buf+14)<<8)|*(data_buf+15))/100;
//			Data_Send_Check(sum);
//			EE_SAVE_PID();
	}
	if(*(data_buf+2)==0X16)								//OFFSET
	{
//			AngleOffset_Rol = (float)((vs16)(*(data_buf+4)<<8)|*(data_buf+5))/1000;
//			AngleOffset_Pit = (float)((vs16)(*(data_buf+6)<<8)|*(data_buf+7))/1000;
	}
			if(*(data_buf+2)==0X02)								//OFFSET
	{
//			AngleOffset_Rol = (float)((vs16)(*(data_buf+4)<<8)|*(data_buf+5))/1000;
//			AngleOffset_Pit = (float)((vs16)(*(data_buf+6)<<8)|*(data_buf+7))/1000;
			FLAG_RETURN = 1;

	}
	Data_Send_Check(sum);
}

void Data_Send_Senser(float sv,float pv)
{

	U8 _cnt=0,i=0,sum=0;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xF1;
	data_to_send[_cnt++]=0;
	data_to_send[_cnt++]=BYTE0(sv);  //?8?
	data_to_send[_cnt++]=BYTE1(sv);  //?8?
	data_to_send[_cnt++]=BYTE2(sv);  //?8?
	data_to_send[_cnt++]=BYTE3(sv);  //?8?
	data_to_send[_cnt++]=BYTE0(pv);  //?8?
	data_to_send[_cnt++]=BYTE1(pv);  //?8?
	data_to_send[_cnt++]=BYTE2(pv);  //?8?
	data_to_send[_cnt++]=BYTE3(pv);  //?8?
	data_to_send[3] = _cnt-4;
	for( i=0;i<_cnt;i++)sum += data_to_send[i];
	data_to_send[_cnt++] = sum;
	PrintString1(data_to_send,_cnt);
}
void Data_Send_PID2(void){
	unsigned char _cnt=0;
	unsigned int _temp;
	unsigned char sum = 0;
	unsigned char i = 0;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0x12;
	data_to_send[_cnt++]=0;
	_temp = PID_PID_2.Kp * 100;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = PID_PID_2.Ki * 100;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = PID_PID_2.Kd * 100;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = 1* 100 ;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = 0 * 100;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = 0 * 100;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = 0 * 100;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp = 0 * 100;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	_temp =0 * 100;
	data_to_send[_cnt++]=BYTE0(_temp);
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[3] = _cnt-4;
	for(;i<_cnt;i++)
	sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	PrintString1(data_to_send,_cnt);
}
void Data_Send_Check(U8 check)
{
	U8 sum=0 ,i= 0;
	data_to_send[0]=0xAA;
	data_to_send[1]=0xAA;
	data_to_send[2]=0xF0;
	data_to_send[3]=3;
	data_to_send[4]=0xBA;
	data_to_send[5]=00;
	data_to_send[6]=check;//BYTE0(check);
	for( i=0;i<7;i++)
		sum += data_to_send[i];
	data_to_send[7]=sum;
  data_to_send_ok=1;
}