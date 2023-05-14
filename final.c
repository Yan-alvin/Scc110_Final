#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *file1;
    char *dx;
    int q=0;
    int b=0;
    int a=0;
    int c=0;
    int matchedWords[1000];
    int wordCount[1000];
    int y=0;
    int vc=0;
    int vb=0;
    int sameWord[1000];
    

    file1 = fopen("own.txt", "r");

    if (file1 != NULL) {
        char lineOfText1[1000];
        char dividedText1[1000][10];
        int i=0;
        int x=0;



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
                //load all characters into the 2d array
                x++;
            }
        }
    }
    
    while(q<i||dividedText1[q][b]!=0){
        wordCount[q]++;
        b++;
        if(dividedText1[q][b]==0){
           q++;
           b=0;
        }
    }

    q=0;
    b=0;

    while(q<i||dividedText1[q][b]!=0){
        printf("%c",dividedText1[q][b]);
        a=0;
        c=0;
        while(a<i||dividedText1[a][c]!=0){
            printf("%c",dividedText1[a][c]);
            if(dividedText1[a][c]==dividedText1[q][b]&&wordCount[a]==wordCount[q]){
                vc=c;
                vb=b;
                printf("(%d,%d)",q,matchedWords[q]);
                while(y<wordCount[q]){
                    if(dividedText1[a][vc]==dividedText1[q][vb]){
                    matchedWords[q]++;
                    vc++;
                    vb++;
                    y++;
                    printf("[%d,%d]",vc,y);
                    printf("/%d,%d/",matchedWords[q],wordCount[q]);
                    }
                }
                if(matchedWords[q]==wordCount[q]){
                        sameWord[q]++;
                        printf("yay");
                        y=0;
                        matchedWords[q]=0;
                }
            }
            c++;
            if(dividedText1[a][c]==0){
            a++;
            c=0;
            }
        }
        b++;
        if(dividedText1[q][b]==0){
           q++;
           b=0;
        }
    }

    printf("%d",wordCount[0]);
    printf("/%d/",wordCount[1]);
    printf("%d",sameWord[0]);
    printf("/%d/",sameWord[1]);
    
    
        fclose(file1);
    }
}