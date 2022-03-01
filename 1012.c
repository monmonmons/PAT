#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int id;
    int grade[4];
};
struct node stu[2000];

char order[5]={'A','C','M','E'};
int flag = -1;
int check[1000000][4];

int cmp(const void *a, const void *b){
    struct node s1 = *(struct node *)a;
    struct node s2 = *(struct node *)b;
    return s2.grade[flag]-s1.grade[flag];
}
int main(){
    int i, j, rank;
    int N, M;
    
    memset(check, 0, sizeof(check));
    
    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){
        scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3;
    }
    for(flag=0; flag<4; flag++){
        qsort(stu, N, sizeof(stu[0]), cmp);
        
        rank = 1;
        check[stu[0].id][flag] = rank;
        for(i=1; i<N; i++){
            if(stu[i].grade[flag] != stu[i-1].grade[flag])
                rank = i + 1;
            check[stu[i].id][flag] = rank;
        }
    }
    
    //search
    int tmp_id, min, min_num;
    for(i=0; i<M; i++){
        scanf("%d", &tmp_id);
        if(i!=0) printf("\n");
        if(check[tmp_id][0]==0) printf("N/A");
        else {
            min = 0;
            min_num = check[tmp_id][0];
            for(j=1; j<4; j++){
                if(check[tmp_id][j] < min_num) {
                    min = j;
                    min_num = check[tmp_id][j];
                }
            }
            printf("%d %c", min_num, order[min]);
        }
        
    }
    
    
    return 0;
}