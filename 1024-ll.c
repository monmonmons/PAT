#include <stdio.h>

int IsPalindromic(long long int n);
long long int reverse(long long int n);

int main(){
    long long int num;
    int step=0, max;
    int flag=0;
    scanf("%lld %d", &num, &max);
    
    while(step<max){
        flag = IsPalindromic(num);
        if(flag==1) break;
        num += reverse(num); 
        step++;
    }
    
    printf("%lld\n%d", num, step);
    
    return 0;
}

int IsPalindromic(long long int n){
    int cnt=0, i, flag=1;
    long long int tmp=n;
    char str[500];
    if(n<10) return 1;   //single digit number
    
    while(tmp>0){
        str[cnt] = '0' + tmp % 10;
        tmp = tmp / 10;
        cnt++;
    }
    cnt--;
    for(i=0; i<(cnt+1)/2; i++){
        if(str[i]!=str[cnt-i]) {
            flag = 0;
            break;
        }
    }
        
    return flag;
}
    
long long int reverse(long long int n){
    long long int ans = 0;
    int res = n % 10;
    if(n<10) return n;
    while(n>0){
        ans = ans * 10 + res;
        n = n / 10;
        res = n % 10;
    }
    return ans;
}