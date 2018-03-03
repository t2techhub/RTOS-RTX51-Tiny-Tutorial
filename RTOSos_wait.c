#include <REGX51.H>
#include <RTX51TNY.H>					//Su dung thu vien RTX51 Tiny Real-Time
#define INIT 0								//Dinh nghia INIT = 0
#define DO   1								//Dinh nghia DO = 1
#define XANH 2								//Dinh nghia XANH = 2
sbit LED_DO = P1^0;						//Dinh nghia chan LED_DO
sbit LED_XANH = P1^1;					//Dinh nghia chan LED_XANH
unsigned int i,j;
//=========Ham Start up==========
void Startup(void) _task_ INIT
{		
 TMOD = 0x21;	 								//Timer 1 mode 2	   
 os_create_task (DO);					//Tao Task_Led_Do	
 os_create_task (XANH);	  		//Tao Task_Led_Xanh
 os_delete_task (INIT);				//Xoa Task hien tai (Task 0)
}
void Task_Led_Do(void) _task_ DO 
{
	while(1)
	{
		for(i=0; i<10000; i++);   
		os_wait2 (K_IVL, 50);     //Cho 50 ticks = 500ms 
		LED_DO ^= 1;							//Dao trang thai Led Do
	}
}
void Task_Led_Xanh(void) _task_ XANH
{
	while(1)
	{
		for(j=0; j<10000; j++);
		os_wait2 (K_TMO, 50);     //Cho 50 ticks = 500ms 
		LED_XANH ^= 1;						//Dao trang thai Led Xanh		
	}
}
