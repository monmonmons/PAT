#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	long long id;
	int loc;
	int lrank;
	int frank;
	int grade;
};

struct node testee[30005];

int cmp(const void *a, const void *b){
	struct node aa = *(struct node*)a;
	struct node bb = *(struct node*)b;
	return bb.grade - aa.grade;
}

int cmp_id(const void *a, const void *b){
    struct node aa = *(struct node*)a;
	struct node bb = *(struct node*)b;
	long long aid = aa.id;
	long long bid = bb.id;
	if(aid > bid) return 1;
    else if(aid==bid) return 0;
    else return -1;
}

int main(){
	int locnum, nums[100], total = 0;
	scanf("%d", &locnum);
	
	for(int i = 0; i < locnum; i++){
		scanf("%d", &nums[i]);
		total += nums[i];
		for(int j = total - nums[i]; j < total; j++){
			scanf("%lld %d", &testee[j].id, &testee[j].grade);
			testee[j].loc = i + 1;
		}
		qsort(&testee[total - nums[i]], nums[i], sizeof(testee[0]), cmp);  //
		int rank = 1, tmp;
		testee[total - nums[i]].lrank = rank;
		for(int j = 1; j < nums[i]; j++){   //
            tmp = total - nums[i] + j;
			if(testee[tmp].grade != testee[tmp-1].grade)
				rank = j + 1;
			testee[tmp].lrank = rank;
		}
	}
	
	qsort(&testee[0], total, sizeof(testee[0]), cmp);
	int rank = 1, count = 1;
	testee[0].frank = rank;
	for(int i = 1; i < total; i++){
		if(testee[i].grade != testee[i-1].grade) {
            rank = i + 1;
            if (count > 1){
                qsort(&testee[i-count], count, sizeof(testee[0]), cmp_id);
                count = 1;
            }
        }
        else {
            count++;
        }
		testee[i].frank = rank;
	}
	
	printf("%d", total);
	
	for(int i = 0; i < total; i++){
		printf("\n%lld %d %d %d", testee[i].id, testee[i].frank , testee[i].loc, testee[i].lrank);
	}
	
	return 0;
}

