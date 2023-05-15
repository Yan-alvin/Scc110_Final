#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *file1;
    char *dx;
    int front1=0;
    int back1=0;
    int front2=0;
    int back2=0;
    int matchedWords[1000];
    int wordCount[1000];
    int varback2=0;
    int varback1=0;
    int sameWord[1000][50];
    

    file1 = fopen("test1.txt", "r");

    if (file1 != NULL) {
        char lineOfText1[1000];
        char dividedText1[1000][50];
        int i=0;
        int x=0;



    while (fgets(lineOfText1, 1000, file1) != NULL) {
        for(dx=lineOfText1;*dx; dx++){
            if(isalpha(*dx)==0&&dividedText1[i][0]!=0){
                //checks if the variable is front2 character and try to skip those that aren't
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
    
    while(front1<i||dividedText1[front1][back1]!=0){
        wordCount[front1]++;
        back1++;
        if(dividedText1[front1][back1]==0){
           front1++;
           back1=0;
        }
    }

    front1=0;
    back1=0;

    while(front1<i||dividedText1[front1][back1]!=0){
        front2=0;
        back2=0;
        while(front2<i||dividedText1[front2][back2]!=0){
            if(back1==back2&&wordCount[front1]==wordCount[front2]&&dividedText1[front1][back1]==dividedText1[front2][back2]){
                int sameCharacter=0;
                for(int y=0;y<wordCount[front2];y++){
                    if(dividedText1[front1][y]==dividedText1[front2][y]){
                        sameCharacter++;
                    }
                    if(sameCharacter==wordCount[front2])
                    sameWord[front1][back1]++;
                }
            }
            back2++;
            if(dividedText1[front2][back2]==0){
            front2++;
            back2=0;
            }
        }
        back1++;
        if(dividedText1[front1][back1]==0){
           front1++;
           back1=0;
        }
    }

    front1=0;
    back1=0;

    printf("Test1 Word frequency:\n");
    while(front1<i||dividedText1[front1][back1]!=0){
        printf("%c",dividedText1[front1][back1]);
        back1++;
        if(dividedText1[front1][back1]==0){
            printf("=%d\n",sameWord[front1][0]);
            front1++;
            back1=0;
        }
        
    }  
    
        fclose(file1);
    }

    FILE *file2;
    *dx=0;
    front1=0;
    back1=0;
    front2=0;
    back2=0;
    for(int i=0;i<1000;i++){
        matchedWords[i]=0;
    }
    for(int i=0;i<1000;i++){
        wordCount[i]=0;
    }
    varback2=0;
    varback1=0;
    for(int i=0;i<1000;i++){
        for(int x=0;x<50;x++){
        sameWord[i][x]=0;
        }
    }
    
    

    file2 = fopen("test2.txt", "r");

    if (file2 != NULL) {
        char lineOfText1[1000];
        for(int i=0;i<1000;i++){
        lineOfText1[i]=0;
    }
        char dividedText1[1000][50];
        for(int i=0;i<1000;i++){
            for(int x=0;x<50;x++){
                dividedText1[i][x]=0;
            }
    }
        int i=0;
        int x=0;



    while (fgets(lineOfText1, 1000, file2) != NULL) {
        for(dx=lineOfText1;*dx; dx++){
            if(isalpha(*dx)==0&&dividedText1[i][0]!=0){
                //checks if the variable is front2 character and try to skip those that aren't
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
    
    while(front1<i||dividedText1[front1][back1]!=0){
        wordCount[front1]++;
        back1++;
        if(dividedText1[front1][back1]==0){
           front1++;
           back1=0;
        }
    }

    front1=0;
    back1=0;

    while(front1<i||dividedText1[front1][back1]!=0){
        front2=0;
        back2=0;
        while(front2<i||dividedText1[front2][back2]!=0){
            if(back1==back2&&wordCount[front1]==wordCount[front2]&&dividedText1[front1][back1]==dividedText1[front2][back2]){
                int sameCharacter=0;
                for(int y=0;y<wordCount[front2];y++){
                    if(dividedText1[front1][y]==dividedText1[front2][y]){
                        sameCharacter++;
                    }
                    if(sameCharacter==wordCount[front2])
                    sameWord[front1][back1]++;
                }
            }
            back2++;
            if(dividedText1[front2][back2]==0){
            front2++;
            back2=0;
            }
        }
        back1++;
        if(dividedText1[front1][back1]==0){
           front1++;
           back1=0;
        }
    }

    front1=0;
    back1=0;

    printf("Test2 Word frequency:\n");
    while(front1<i||dividedText1[front1][back1]!=0){
        printf("%c",dividedText1[front1][back1]);
        back1++;
        if(dividedText1[front1][back1]==0){
            printf("=%d\n",sameWord[front1][0]);
            front1++;
            back1=0;
        }
        
    }  
    
        fclose(file2);
    }
}