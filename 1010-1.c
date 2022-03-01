#include <stdio.h>
#include <string.h>

#define INF (1LL<<63)-1;

long long conversion(char str[], long long radix);
long long find_max(char str[]);
long long binary(char str[], long long l, long long r, long long sum1);

int main(){
	char n1[20], n2[20], t[20];
	int tag, radix1;
	scanf("%s %s %d %d", n1, n2, &tag, &radix1);
	if(tag == 2){
		strcpy(t, n1);
		strcpy(n1, n2);
		strcpy(n2, t);
	}
	
	long long sum1 = conversion(n1, radix1);
	long long max = find_max(n2);
	long long sum2 = 0;
    
    long long l, r, mid, ans, tmp=INF;
    int count = 0;
    l = max + 1;
    r = max+1 < sum1+1 ? sum1+1 : max+1;
    while(1){
        count++;
        ans = binary(n2, l, r, sum1);
        if(ans==-1) break;
        if(ans < tmp) tmp = ans;
        if(l >= ans-1) {
            break;
        }
        r = ans-1;
    }

	if(count==1 && ans == -1) printf("Impossible");
	else printf("%lld\n", tmp);
	
	return 0;
} 

long long conversion(char str[], long long radix){
	long long sum = 0;
	long long temp;
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			temp = str[i] - 'a' + 10;
		}else{
			temp = str[i] - '0';
		}
		sum = sum * radix + temp;
	}

	return sum;
}

long long find_max(char str[]){
	int len = strlen(str);
	long long max = 0, temp;
	for(int i = 0; i < len; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			temp = str[i] - 'a' + 10;
		}else if(str[i] >= '0' && str[i] <= '9'){
			temp = str[i] - '0';
		}
		if(temp > max){
			max = temp;
		}
	}
	return max;
}

long long binary(char str[], long long l, long long r, long long sum1){
    long long mid;
    long long sum2;
    while(l <= r){
        mid = (l + r)/2;
        sum2 = conversion(str, mid);
        if(sum2 == sum1) return mid;
        else if(sum2 > sum1 || sum2 < 0) r = mid - 1;
        else if(sum2 < sum1) l = mid + 1;
    }
    return -1;
}


