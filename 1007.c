#include <stdio.h>

int main(){
    int numSize, i, tmp=0, sum=-(1<<20);
    int nums[10000], begin=0, begin_tmp=0, end=0;
    
    scanf("%d", &numSize);
    for(i=0; i<numSize; i++){
        scanf("%d", &nums[i]);
    }
    
    for (i = 0; i < numSize; i++) {
        tmp += nums[i];
        if (tmp > sum) {
            sum = tmp;
            begin = begin_tmp;
            end = i;
        }
        if(tmp < 0) {
            tmp = 0;
            begin_tmp = i+1;
        }
    }
    
    if(sum<0) printf("%d %d %d", 0, nums[0], nums[numSize-1]);
    else printf("%d %d %d", sum, nums[begin], nums[end]);
    
    return 0;
}

