#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse(char s[]){
	int len = strlen(s);
	int i, j;
	char temp[100];
	for(i = 0, j = len - 1; i < len; i++, j--){
		temp[j] = s[i];
	}
	strcpy(s, temp);
	s[len] = '\0';
	return ;
}

bool isPalindromic(char s[]){
	int len = strlen(s), i, j;
	int halflen = len / 2;
	for(i = 0, j = len - 1; i <= halflen; i++, j--){
		if((s[i] - s[j]) != 0){
			return false; 
			break;
		}
	}
	return true;
}

void add(char s1[], char s2[]){
	int len = strlen(s1), carry=0, i;
	for(i=len-1; i>=0; i--){
		s1[i] = s1[i] + s2[i] + carry - '0';
		carry = 0;
		if(s1[i] > '9') {
			s1[i] = s1[i] - 10;
			carry = 1;
		}
	}
	if(carry==1) {
		for(i=len-1; i>=0; i--) {
			s1[i+1] = s1[i];
		}
		s1[0] = '1';
		s1[len+1] = '\0';
	}
	return ;
}

int main(){
	int max, i = 0;
	char s[100];
	bool ans;
	scanf("%s", s);
	scanf("%d", &max);

	while(i < max){
		ans = isPalindromic(s);
		if(ans) break;
		char rvs[100] = {0};
		strcpy(rvs, s);
		reverse(rvs);
		add(s, rvs);
		i++;
	}
	printf("%s\n%d", s, i);
    return 0;
}
