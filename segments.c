#include<stdlib.h>

/*
The context was AVR, check it in IA
 * RAM 0X00|----- DATA -----|-----BSS-----|-----HEAP----->|- - - - - - - - - - - - - -|<----- STACK -----| RAMEND
 */
int a; // bss
int b; // bss
int c = 20; // data
const char cc = 'a'; // .rodata section in data.
static int d; // bss + scope is confined to this file.
static int e = 23; // data + scope is confined to this file.
extern int f; // data or bss | declared here but defined in another file
void *ptr; //bss
void *ptr1;
 
int main ( void )
{
    ptr = malloc ( 20 ); //*ptr1 is on data and malloc(20) is initialised on heap
    void *ptr2 = malloc ( 30 ); //*ptr2 is on stack and malloc ( 20 ) is initialised on heap
    void *ptr3; // *ptr3 is on stack
    int g; // stack
    int h = 10; // stack
    static int i = 10; // data | But the scope is confined to this function
}
