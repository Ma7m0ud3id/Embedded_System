#include<stdint.h>
#define STACK_START_PS 0x20001000
void reset_Handler(void);
extern int main(void);
void defult_Handler(){
	reset_Handler();
}
NMI_Handler(void)__attribute__((weak, alias ("defult_Handler")));;
H_fault_Handler(void)__attribute__((weak, alias ("defult_Handler")));;
MM_fault_Handler(void)__attribute__((weak, alias ("defult_Handler")));;
Bus_fault(void)__attribute__((weak, alias ("defult_Handler")));;
Usage_fault_Handler(void)__attribute__((weak, alias ("defult_Handler")));;


uint32_t vectors[]__attribute__((section(".vectors")))={
	STACK_START_PS,
	(uint32_t) &reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Handler,
	(uint32_t) &Bus_fault,
	(uint32_t) &Usage_fault_Handler,
	
};
extern unsigned int _Etxt;
extern unsigned int Sdata;
extern unsigned int _Edata;
extern unsigned int Sbss;
extern unsigned int _Ebss;

void reset_Handler(void){
	unsigned int Data_size = (unsigned int*) &_Edata-(unsigned int*) &Sdata;
	unsigned int p_src = (unsigned int*) &_Edata;
	unsigned int p_dst = (unsigned int*) &Sdata;
	int i;
	for(i=0;i<Data_size;i++){
		*((unsigned int*)p_dst++)=*((unsigned int*)p_src++);
	}
	unsigned int bss_size = (unsigned int*) &_Ebss-(unsigned int*) &Sbss;
	unsigned int p_bst = (unsigned int*) &Sbss;
	for(i=0;i<bss_size;i++){
		*((unsigned int*)p_bst++)=(unsigned int)0;
	}
	main();
}