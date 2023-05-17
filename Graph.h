#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"LL.h"

typedef struct Cities{
    char* ch;
}Cities;

char* createCity(){
    return (char*)malloc(sizeof(char)*20);
}

Cities c[10];

// typedef struct queue{
//     struct Queue* q;
// }queue;

typedef struct Graph{
    Node* graph;
}Graph;


void createGraph(Graph* g,int n){
    printf("start\n");
    for(int i=0;i<n;i++){
        (g+i)->graph = NULL;
    }
    printf("end\n");
}

void createVertex(Graph* g,int i,int src,int dest,int weight,int time){
        add(&((g+i)->graph),src,dest,weight,time);
}

void dfs(Graph* g,int curr,int vis[]){
    printf("%d\t",curr);
    vis[curr] = 1;

    for(int j=0;j<size(((g+curr)->graph));j++){
        Node* vertex = get(&((g+curr)->graph),j);
        if(!vis[vertex->dest]){
            dfs(g,vertex->dest,vis);
        }
    }
}

void printparent(int parent[],int i,int cost[]){
    
    if(parent[i]==-1){
        return;
    }
    printparent(parent,parent[i],cost);
    // printf("%d",parent[i]);
    printf("%s->",c[parent[i]].ch);
    printf("( %d000) ->",cost[i]);

}

void printparentTime(int parent[],int i,int cost[]){
    
    if(parent[i]==-1){
        return;
    }
    printparentTime(parent,parent[i],cost);
    // printf("%d",parent[i]);
    printf("%s->",c[parent[i]].ch);
    printf("( %dhours) ->",cost[i]);

}

int directFlight(Graph* g,int n,int source,int destination){
    for(int i=0;i<n;i++){
        for(int j=0;j<size(((g+i)->graph));j++){
             Node* edge = get(&((g+i)->graph),j);
             int u = edge->src;
             int v = edge->dest;
             int wt = edge->wt;
             int time = edge->time;
             if(u == source && v==destination){
                printf("\nCost:%d000\n",wt);
                printf("Time:%d Hours\n",time);

                return 1;
             }
        }
    }
    return 0;
}


void dijkstras(Graph* g,int vis[],int n,int source,int destination){
    int dis[n];
    for(int i=0;i<n;i++){
     if(i!=source){
        dis[i] = 99999;  
        }
    }
    dis[source] = 0;
    int V = n;

    // queue qu[n];
    // for(int i=0;i<n;i++){
    //     ((&qu[0])+i)->q = NULL;
    // }

    int path[n];
    path[source] = -1;
    int cost[n];
    

    for(int i=0;i<V-1;i++){
        for(int j=0;j<V;j++){
            // printf("%d\n",size(((g+j)->graph)));
            for(int k=0;k<size(((g+j)->graph));k++){
                Node* edge = get(&((g+j)->graph),k);
                int u = edge->src;
                int v = edge->dest;
                int wt = edge->wt;
                int time = edge->time;
                // printf("\n%d\t%d\t%d\t\n",u,v,wt);

                if(dis[u]!=99999){
                    if(dis[u]+wt<dis[v]){
                        dis[v] = dis[u]+wt;
                        path[v] = j;
                        cost[v] = wt;
                    }
                }

                    
            }
            // printf("\nbreaking\n");
        }
    }    

    // for(int i=0;i<n;i++){
    //     printf("%d\t",dis[i]);
    // }     

    printparent(path,destination,cost);
    printf("%s\n",c[destination]);
    
}

void dijkstrasTime(Graph* g,int vis[],int n,int source,int destination){
    int dis[n];
    for(int i=0;i<n;i++){
     if(i!=source){
        dis[i] = 99999;  
        }
    }
    dis[source] = 0;
    int V = n;

    // queue qu[n];
    // for(int i=0;i<n;i++){
    //     ((&qu[0])+i)->q = NULL;
    // }

    int path[n];
    path[source] = -1;
    int cost[n];
    

    for(int i=0;i<V-1;i++){
        for(int j=0;j<V;j++){
            // printf("%d\n",size(((g+j)->graph)));
            for(int k=0;k<size(((g+j)->graph));k++){
                Node* edge = get(&((g+j)->graph),k);
                int u = edge->src;
                int v = edge->dest;
                int wt = edge->wt;
                int time = edge->time;
                // printf("\n%d\t%d\t%d\t\n",u,v,wt);

                if(dis[u]!=99999){
                    if(dis[u]+time<dis[v]){
                        dis[v] = dis[u]+time;
                        path[v] = j;
                        cost[v] = time;
                    }
                }

                    
            }
            // printf("\nbreaking\n");
        }
    }    

    // for(int i=0;i<n;i++){
    //     printf("%d\t",dis[i]);
    // }     

    printparentTime(path,destination,cost);
    printf("%s\n",c[destination]);
    
}


int len(char s[]){
    int j=0;
    for(int i=0;s[i]!='\0';i++){
        j++;
    }
    return j;
}

void cityFunction(){
    for(int i=0;i<10;i++){
        c[i].ch = createCity();
    }

    char ch[20];
    for(int i=0;i<10;i++){
        printf("Enter string %d :",i);
        scanf("%s",ch);
        int j;
        for(j=0;ch[j]!='\0';j++){
            c[i].ch[j] = ch[j];
        }
        c[i].ch[j] = ch[j];
    }

}

int getIndex(char str[]){
    int count = 0;
    for(int i=0;i<10;i++){
        count = 0; 
        for(int j=0;str[j]!='\0';j++){
            if(c[i].ch[j] == str[j]){
                count++;
            }
        }
        if(count==len(str)){
            return i;
        }
    }
  return -1;
}
