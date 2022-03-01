#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, n1, n2, n3;
    int e1[10], e2[10], e3[20];
    double a1[10], a2[10], a3[20];
    
    scanf("%d", &n1);
    for(i = n1-1; i >= 0; i--)
        scanf("%d %lf", &e1[i], &a1[i]);
    
    scanf("%d", &n2);
    for(j = n2-1; j >= 0; j--)
        scanf("%d %lf", &e2[j], &a2[j]);
    
    double a;
    n3 = -1;
    for(i=0, j=0; i<n1 && j<n2; )
    {
        if(e1[i] == e2[j]) {
            a = a1[i] + a2[j];
            if (a!=0) 
            {
                n3++;
                a3[n3] = a;
                e3[n3] = e1[i];
            }
            i++;
            j++;
        } else if (e1[i] < e2[j]) {
            n3++;
            a3[n3] = a1[i];
            e3[n3] = e1[i];
            i++;
        } else if (e1[i] > e2[j]){
            n3++;
            a3[n3] = a2[j];
            e3[n3] = e2[j];
            j++;
        }
    }
    
    
    for (;i < n1; i++) {
        n3++;
        a3[n3] = a1[i];
        e3[n3] = e1[i];
    }
    
    for (;j < n2; j++) {
        n3++;
        a3[n3] = a2[j];
        e3[n3] = e2[j];
    }
    
    printf("%d", n3+1);    //num of nonzero coef
    
    for(i = n3; i >= 0; i--) {
        if(a3[i]!=0) printf(" %d %.1lf", e3[i], a3[i]);
    }
    
    return 0;
}