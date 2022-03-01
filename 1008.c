#include<stdio.h>

int main(){
    int N, level[101], time=0;
    int i, tmp, up = 6, down = 4, stay = 5;
    
    
    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &level[i+1]);
    }
    level[0] = 0;
    for(i=0; i<N; i++){
        tmp = level[i+1] - level[i];
        if(tmp>0){
            time += stay + tmp*up;
        } else if(tmp<0){
            time += stay + (-tmp)*down;
        } else if(tmp==0) {
            time += stay;
        }
    }
    
    printf("%d\n", time);
    return 0;
}