/* 
startup_cortexM3
Mahmoud eid
*/

/* SRAM 0x20000000 */

// Defining The Vector Table
.section .vectors
.word 0x20001000    // Stack Top Address
.word _reset
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler
.word Vector_handler


.section .text
_reset:
    bl main
    b .
.thumb_func
Vector_handler:
    b _reset