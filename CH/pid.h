#ifndef __PID_H__
#define __PID_H__
#include "main.h"
#define MaxActual 977
//extern struct _pid pid;
typedef struct {
    float SetSpeed;	//定义设定值
    float ActualSpeed;	//定义实际值
    float err;			 //定义偏差值
    float err_last;		 //定义上一个偏差值
    float Kp,Ki,Kd;		  //定义比例、积分、微分系数
    float voltage;		//定义电压值(控制执行器的变量)
    float integral; //定义积分值
}_pid;

void PID_init();
float PID_realize(float speed ,float actual);
#endif