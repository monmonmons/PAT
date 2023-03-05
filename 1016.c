#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
	char name[21];
	int mon, day, hour, min;
	bool state;
};

int cmp(const void *a, const void *b){
	struct node aa = *(struct node*)a;
	struct node bb = *(struct node*)b;
	if(strcmp(aa.name, bb.name) != 0) return strcmp(aa.name, bb.name);
	else{
		if(aa.day != bb.day) return aa.day - bb.day;
		else{
			if(aa.hour != bb.hour) return aa.hour - bb.hour;
			else{
				return aa.min - bb.min;
			}
		}
	}
}

int last(int d1, int h1, int m1, int d2, int h2, int m2){
	int t1 = (((d1 - 1) * 24) + h1) * 60 + m1;
	int t2 = (((d2 - 1) * 24) + h2) * 60 + m2;
	int ans = t2 - t1;
	return ans;
}

int abs_amount(int h, int m, int toll[24]){
	int temp = m + h * 60;
	int amount = 0, i = 0;
	while(temp > 0){
		if(temp >= 60){
			amount += toll[i] * 60;
		}else{
			amount += toll[i] * temp;
		}
		temp -= 60;
		i++;
	}
	return amount;
}

struct node c[1000];
int toll[24];

int main(){
	int n;
	char temp[10];
	
	for(int i = 0; i < 24; i++){
		scanf("%d", &toll[i]);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %d:%d:%d:%d %s", c[i].name, &c[i].mon, &c[i].day, &c[i].hour, &c[i].min, temp);
		c[i].state = (strcmp(temp, "off-line"));
	}
	qsort(c, n, sizeof(c[0]), cmp);
	
	
	int cnt = 0;
    float total_amount = 0.0;
	bool flag = true;	
	for(int i = 1; i < n; i++){
		if(strcmp(c[i-1].name, c[i].name) == 0){
			if(c[i-1].state && !c[i].state){
				int lasting = last(c[i-1].day, c[i-1].hour, c[i-1].min, c[i].day, c[i].hour, c[i].min), amount;
				amount = abs_amount(c[i].hour, c[i].min, toll) + abs_amount(24, 0, toll) * (c[i].day - c[i-1].day) - abs_amount(c[i-1].hour, c[i-1].min, toll);
				float amount_cent = amount / 100.00;
				total_amount += amount_cent;
				if(flag == true){
					printf("%s %02d\n", c[i].name, c[i].mon);
					flag = false;	
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", c[i-1].day, c[i-1].hour, c[i-1].min, c[i].day, c[i].hour, c[i].min, lasting, amount_cent);
			}
		}else{
			if(flag == false) printf("Total amount: $%.2f\n", total_amount);
            flag = true;
			total_amount = 0.0;
		}
	}
    if(flag==false){
        printf("Total amount: $%.2f\n", total_amount);
    }
	return 0;
}

