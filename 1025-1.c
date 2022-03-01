#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	long long int id;
	int loc;
	int lrank;
	int grade;
};

struct node testee[30005];

int cmp(const void *a, const void *b){
	struct node aa = *(struct node*)a;
	struct node bb = *(struct node*)b;
	if(bb.grade != aa.grade) return bb.grade - aa.grade;
	else if(bb.grade == aa.grade){
		long long int aid = aa.id;
		long long int bid = bb.id;
		if(aid > bid) return 1;
	    else if(aid == bid) return 0;
	    else if(aid < bid) return -1;
	}
    return -1;
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
		int tmp;
		for(int j = 0; j < nums[i]; j++){   //
            tmp = total - nums[i] + j;
            if (j==0) {
                testee[tmp].lrank = 1;
                continue;
            }
			if(testee[tmp].grade != testee[tmp-1].grade) {
                testee[tmp].lrank = j + 1;
            } else {
                testee[tmp].lrank = testee[tmp-1].lrank;
            }
            
		}
	}
	
	qsort(testee, total, sizeof(testee[0]), cmp);
	printf("%d\n", total);

	int rank = 1;
	for(int i = 0; i < total; i++){
        if (testee[i].grade != testee[i-1].grade) {
			rank = i + 1;
		}
        printf("%013lld %d %d %d\n", testee[i].id, rank, testee[i].loc, testee[i].lrank);
    }
	
	return 0;
}



