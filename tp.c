#include<stdio.h>
#include<stdlib.h>

typedef struct Cities{
    char* ch;
}Cities;

char* createCity(){
    return (char*)malloc(sizeof(char)*20);
}

int main(){

    Cities c[10];
    for(int i=0;i<10;i++){
        c[i].ch = createCity();
    }

    char ch[20];
    for(int i=0;i<10;i++){
        printf("Enter string:");
        scanf("%s",ch);
        int j;
        for(j=0;ch[j]!='\0';j++){
            c[i].ch[j] = ch[j];
        }
        c[i].ch[j] = ch[j];
    }

    for(int i=0;i<10;i++){
        printf("\n");
        for(int j=0;c[i].ch[j]!='\0';j++){
            printf("%c",c[i].ch[j]);
        }
        printf("\n");
    }

  return 0;
}