MEMORY
{
	flash(RX) : ORIGIN = 0x08000000 , LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 20k
}
SECTIONS
{
	.text : {
	    *(.vectors*)
	    *(.text*)
	    _Etxt = . ;
	} > flash
	.data : {
	    Sdata = . ;
	    *(.data*)
	    _Edata = . ;
	} > sram AT> flash
	.bss : {
	    Sbss = . ;
	    *(.bss*)
	    . = ALIGN(4);
	    _Ebss = . ;
	} > sram
}