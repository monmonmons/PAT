#include<stdio.h>
#include<math.h>

void find_prime();

#define maxn 100010
int prime[maxn];
int pnum=0;
int p[maxn]={0};

struct factor{
    int x;
    int cnt;
};
struct factor fac[maxn];

int main(){
    int n, UB;
    scanf("%d", &n);
    UB = sqrt(n);
    int i, num=0;
    
    find_prime();
    
    if(n==1) printf("1=1");
    else {
        printf("%d=", n);
        for(i=0; i<pnum&&prime[i]<=UB; i++){
            if(n%prime[i]==0) {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while(n%prime[i]==0){
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if(n==1) break;
        }
        if(n!=1){
            fac[num].x=n;
            fac[num].cnt=1;
            num++;
        }
        for(i=0; i<num; i++){
            if(i>0) printf("*");
            printf("%d", fac[i].x);
            if(fac[i].cnt>1) printf("^%d", fac[i].cnt);
       
        }
    }
   
    return 0;
}

void find_prime(){
    for(int i=2; i<maxn; i++){
        if(p[i] == 0)
        {
            prime[pnum]=i;
            pnum++;
        }
        for(int j=2*i; j<maxn; j+=i){
            p[j] = 1;
        }
    }
}

