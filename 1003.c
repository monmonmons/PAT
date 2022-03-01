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
    
    for(i=0; i<N; i++){
        dist[i] = adj[s][i];
        if(dist[i]!=INF && i!=s)
            amount[i] = amount[s] + weight[i];  //s可到达的点
    }
    
    int min;
    for(i=1; i<N; i++){
        //求s到v的最短路径，并将此点加入S中
        min = INF;
        for(j=0; j<N; j++){
            if(!mark[j] && dist[j]<min){
                newP = j;
                min = dist[j];            
            }
        }
        
        mark[newP] = true;  //加入集合
        
        //更新s到各点的距离
        for(j=0; j<N; j++){
            if(!mark[j] && dist[j]>dist[newP]+adj[newP][j]){
                dist[j] = dist[newP] + adj[newP][j];
                amount[j] = amount[newP] + weight[j];
                pathcount[j] = pathcount[newP];
            } else if(!mark[j] && dist[j]==dist[newP]+adj[newP][j]){
                pathcount[j] += pathcount[newP];
                
                if(amount[j]<weight[j]+amount[newP]){
                    amount[j] = weight[j] + amount[newP];
                }
            }
        }
    }
    
    return;
}