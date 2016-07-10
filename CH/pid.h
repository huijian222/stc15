#ifndef __PID_H__
#define __PID_H__
#include "main.h"
#define MaxActual 977
//extern struct _pid pid;
typedef struct {
    float SetSpeed;	//�����趨ֵ
    float ActualSpeed;	//����ʵ��ֵ
    float err;			 //����ƫ��ֵ
    float err_last;		 //������һ��ƫ��ֵ
    float Kp,Ki,Kd;		  //������������֡�΢��ϵ��
    float voltage;		//�����ѹֵ(����ִ�����ı���)
    float integral; //�������ֵ
}_pid;

void PID_init();
float PID_realize(float speed ,float actual);
#endif