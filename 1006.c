#include<stdio.h>

int comp(int *a, int *b, int len);
void set(int *a, int *b, int len);
    
int main(){
    int num, i, ans;
    int in_time[3], out_time[3];
    int in_time_tmp[3], out_time_tmp[3];
    int in_id=0, out_id=0;
    
    scanf("%d", &num);
    char id[20][15]={0};
    
    for(i = 0; i < num; i++){
        scanf("%s", id[i]);
        scanf("%d:%d:%d", &in_time_tmp[0], &in_time_tmp[1], &in_time_tmp[2]);
        scanf("%d:%d:%d", &out_time_tmp[0], &out_time_tmp[1], &out_time_tmp[2]);
        
        if(i == 0) {
            set(in_time, in_time_tmp, 3);
            set(out_time, out_time_tmp, 3);
            continue;
        }
        ans = comp(in_time, in_time_tmp, 3);
        if(ans==1) {
            set(in_time, in_time_tmp, 3);  // tmp < out_time
            in_id = i;
        }

        ans = comp(out_time, out_time_tmp, 3);
        if(ans==0) {
            set(out_time, out_time_tmp, 3);  //tmp > out_time
            out_id = i;
        }
    }
    
    printf("%s %s\n", id[in_id], id[out_id]);

    return 0;
}

int comp(int *a, int *b, int len){
    int i = 0, ans = 1;   //default a >= b
    while (ans != 0 && i < len) {
        if(a[i] == b[i]) i++;
        else if(a[i] < b[i]) {
            ans = 0;
            break;
        } else if(a[i] > b[i]) {
            break;
        }
    }
    
    return ans;
}

void set(int *a, int *b, int len){
    for(int i = 0; i < len; i++){
        a[i] = b[i];
    }
    return;
}