#include <stdio.h>

int main(){
    int sum = 0, tmp;
    scanf("%d", &sum);
    scanf("%d", &tmp);
    sum += tmp;
    
    if(sum==0) {
        printf("0");
        return 0;
    }
    
    int sign = 1;
    if(sum < 0) {
        sign = -1;
        sum = -sum;
    }
    
    int i = -1, num[5]={0};
    while(sum != 0){
        i++;
        num[i] = sum % 1000;
        sum = sum / 1000;
    }
    int len = i;
    if(sign == -1) printf("-");  //negative number
    
    for(; i>=0; i--){
        if(num[i]!=0) {
            if(i != len) printf("%03d", num[i]);
            else printf("%d", num[i]);
        }
        else printf("000");
        
        if(i>0) printf(",");
    }
    
    return 0;
}