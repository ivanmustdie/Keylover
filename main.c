#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int main()
{
    printf("Hello world!\n");
    while(!(GetAsyncKeyState(65)& 0x8000 != 0)){

    }
    printf("You pressed A");
    getchar();
    return 0;
}
