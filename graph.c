#include"Graph.h"

int main(){
  cityFunction();
    int n = 10;
    Graph g[n];
    createGraph(&g[0],n);
    printf("\nGraph build start\n");

    FILE *fp;
    char c;
    char str[10];
    fp=fopen("data.txt","r+");
    if(fp==NULL)
    {
        printf("File is not created.");
        exit(1);    //intentionally stop the file
    }else{
        char c1,c2,c3,c4,c5;
        while(fgets(str,8,fp))
        {   c1 = str[0];
            c2 = str[1];
            c3 = str[2];
            c4 = str[3];
            c5 = str[4];

             int num1 = (int)(c1-'0');
             int num2 = (int)(c2-'0');
             int num3 = (int)(c3-'0');
             int num4 = (int)(c4-'0');
             int num5 = (int)(c5-'0');

             createVertex(&g[0],num1,num2,num3,num4,num5);
        }
    }
    fclose(fp);

    printf("\nGraph build successful\n");
    system("cls"); 

    char s[20];
    int vis[n];
    int source,destination; 
    

    int choice;
    printf("\n\n*************Flight Assist*************\n\n");
    printf("Enter 1 to search for Direct flight:\n");
    printf("Enter 2 to search for cost efficient route:\n");
    printf("Enter 3 to search for time efficient route:\n");
    printf("Enter 4 to EXIT:\n\n");
    while(1){
        printf("\n\nEnter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter Source City: ");
            scanf("%s",s);
            source = getIndex(s);
            printf("Enter Destination city City: ");
            scanf("%s",s);
            destination = getIndex(s);
            if(directFlight(&g[0],n,source,destination)==0){
                printf("\nDirect Flight is Not Available!!!\n");
            }
            break;

        case 2://cost efficient
            printf("Enter Source City: ");
            scanf("%s",s);
            source = getIndex(s);
            printf("Enter Destination city City: ");
            scanf("%s",s);
            destination = getIndex(s);
    
   
            for(int i=0;i<n;i++)
                vis[i] = 0;
    
            dijkstras(&g[0],vis,n,source,destination);

            break;  

        case 3://time efficient
            printf("Enter Source City: ");
            scanf("%s",s);
            source = getIndex(s);
            printf("Enter Destination city City: ");
            scanf("%s",s);
            destination = getIndex(s);

            for(int i=0;i<n;i++)
                vis[i] = 0;
            dijkstrasTime(&g[0],vis,n,source,destination);

        break;    

        case 4: exit(0);
            break;      
        
        default:printf("\nEnter a valid Choice!!!\n");
            break;
        }
        
    }
  return 0;  
}