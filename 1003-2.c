#include<stdio.h>
#include<stdbool.h>

#define INF 999999
#define MAXNUM 500
int N, M;
int start, end;
int weight[MAXNUM];
int adj[MAXNUM][MAXNUM]={0};  //邻接矩阵
int dist[MAXNUM];      //start到各点的最小值
int pathcount[MAXNUM]; //start到各点的最短路径计数
int amount[MAXNUM];
bool mark[MAXNUM];

void Dijs(int s);

int main(){
    int i, j, k, tmp;
    
    scanf("%d %d %d %d", &N, &M, &start, &end);
    for(i=0; i<N; i++){
        scanf("%d", &weight[i]);
    }
    for(i=0; i<N; i++){
        dist[i] = INF;
        pathcount[i] = 1;
        mark[i] = false;
        amount[i] = weight[i];
        for(j=0; j<N; j++){
            adj[i][j] = INF;
        }
    }
    
    for(k=0; k<M; k++){
        scanf("%d %d %d", &i, &j, &tmp);
        adj[i][j] = tmp;
        adj[j][i] = tmp;
    }
    
    Dijs(start);
    
    printf("%d %d\n", pathcount[end], amount[end]);
        
    return 0;
}

void Dijs(int s){
    dist[s] = 0;
    mark[s] = true;
    amount[s] = weight[s];
    int newP = s, i, j;
    
    while(newP != end) {
        for(i=0; i<N; i++){
            if(mark[i] == false) {
                if(dist[i] > dist[newP] + adj[newP][i]){
                    dist[i] = dist[newP] + adj[newP][i];
                    amount[i] = amount[newP] + weight[i];
                    pathcount[i] = pathcount[newP];
                } else if(dist[i] == dist[newP] + adj[newP][i]){
                    pathcount[i] += pathcount[newP];
                    if(amount[i] < weight[i] + amount[newP]){
                        amount[i] = weight[i] + amount[newP];
                    }
                }
            }
        }
        
        int dmin = INF;
        for(i=0; i<N; i++){
            if (mark[i] == false && dist[i] < dmin){
                dmin = dist[i];
                newP = i;
            }
        }
        mark[newP] = true;
    }
    
    return;
}