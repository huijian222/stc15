#include "CONFIG.h" 
PID PID_PID_2;
extern float adc_P0_0;

void PID_init(){
    PID_PID_2.SetSpeed=0.0;
    PID_PID_2.ActualSpeed=0.0;		//
    PID_PID_2.err=0.0;
    PID_PID_2.err_last=0.0;
    PID_PID_2.voltage=0.0;
    PID_PID_2.integral=0.0;
    PID_PID_2.Kp=4;   //200 p:0.07jike 
    PID_PID_2.Ki=0;
    PID_PID_2.Kd=0.0;
}

float PID_realize(float speed ,float actual){
	PID_PID_2.ActualSpeed=actual;	   //MaxActual 在pid.h中定义
    PID_PID_2.SetSpeed=speed;
    PID_PID_2.err=PID_PID_2.SetSpeed-PID_PID_2.ActualSpeed;
    if(PID_PID_2.Ki)PID_PID_2.integral += PID_PID_2.err;
	if(PID_PID_2.integral > 0.5) PID_PID_2.integral = 0.5;
	if(PID_PID_2.integral < -0.5) PID_PID_2.integral = -0.5;
    PID_PID_2.voltage=PID_PID_2.Kp*PID_PID_2.err+PID_PID_2.Ki*PID_PID_2.integral+PID_PID_2.Kd*(PID_PID_2.err-PID_PID_2.err_last);
    PID_PID_2.err_last=PID_PID_2.err;
    PID_PID_2.ActualSpeed=PID_PID_2.voltage*1.0;
    return  PID_PID_2.ActualSpeed;
}

float PID_application(float target,float adc){
	float PID_num;
	PID_num = PID_realize(target,adc);//(target, (float)((adc_P0_0-640)/360) );
	if(PID_num > 1){
		PID_num = 1.0;
	}
	if(PID_num < -1){
		PID_num = -1.0;
	}
//	PID_num=(PID_num+1.0)/2.0;
	return PID_num;
}