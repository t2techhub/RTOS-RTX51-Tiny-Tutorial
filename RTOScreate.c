#include <REGX51.H>
#include <RTX51TNY.H>					//Su dung thu vien RTX51 Tiny Real-Time
sbit LED_DO = P1^0;						//Dinh nghia chan LED_DO
sbit LED_XANH = P1^1;					//Dinh nghia chan LED_XANH
//=========Ham Start up==========
void Startup(void) _task_ 0
{		
 TMOD = 0x21;	 								//Timer 1 mode 2	   
 os_create_task (1);					//Tao Task "Led_Do"	
 os_create_task (2);	  			//Tao Task "Led_Xanh"
 os_delete_task (0);					//Xoa Task hien tai (Task 0)
}
void Task_Led_Do(void) _task_ 1 
{
	while(1)
	{
		LED_DO = 1;								//Bat Led Do
		os_wait (K_TMO, 70, 0);   //Cho 70 ticks = 700ms 
		LED_DO = 0;							  //Tat Led Do
		os_wait (K_TMO, 70, 0);   //Cho 70 ticks = 700ms
	}
}
void Task_Led_Xanh(void) _task_ 2
{
	while(1)
	{
		LED_XANH = 1;							//Bat Led Xanh
		os_wait (K_TMO, 30, 0);  	//Cho 30 ticks = 300ms 
		LED_XANH = 0;							//Tat Led Xanh
		os_wait (K_TMO, 30, 0);  	//Cho 30 ticks = 300ms
	}
}
