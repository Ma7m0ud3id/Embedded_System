/* startup bashar */

.section .vectors
.word 0x20001000
.word reset
.word vector_handler/*NMI*/
.word vector_handler/*Hard fault*/
.word vector_handler/*MM fault*/
.word vector_handler/*Bus fault*/
.word vector_handler/*Usage fault*/
.word vector_handler/*RESERVED*/
.word vector_handler/*RESERVED*/
.word vector_handler/*RESERVED*/
.word vector_handler/*RESERVED*/
.word vector_handler/*SV CALL*/
.word vector_handler/*Depug reserved*/
.word vector_handler/*RESERVED*/
.word vector_handler/*PendSV*/
.word vector_handler/*SysTick*/
.word vector_handler/*IRQ0*/
.word vector_handler/*IRQ1*/
.word vector_handler/*IRQ2*/
.word vector_handler/*....*/

.section .text
reset:
bl main
b .

.thumb_func
vector_handler:
b reset


