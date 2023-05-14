#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *file1;
    char *dx;
    int q=0;
    int b=0;
    

    file1 = fopen("test1.txt", "r");

    if (file1 != NULL) {
        char lineOfText1[1000];
        char dividedText1[1000][10];
        int i=0;
        int x=0;

    //load all characters into the 2d array

    while (fgets(lineOfText1, 1000, file1) != NULL) {
        for(dx=lineOfText1;*dx; dx++){
            if(isalpha(*dx)==0&&dividedText1[i][0]!=0){
                //checks if the variable is a character and try to skip those that aren't
                i++;
                x=0;
            }
            if(isalpha(*dx)!=0){
                *dx=tolower(*dx);
                //put all characters to lower case
                dividedText1[i][x]=*dx;
                x++;
            }
        }
    }
    

    while(q<i||dividedText1[q][b]!=0){
        printf("%c",dividedText1[q][b]);
        //print all to try to debug
        b++;
        if(dividedText1[q][b]==0){
           q++;
           b=0;
        }
    }

    while(q<i||dividedText1[q][b]!=0){
        printf("%c",dividedText1[q][b]);
        b++;
        if(dividedText1[q][b]==0){
           q++;
            b=0;
        }
    }
    
        fclose(file1);
    }
}