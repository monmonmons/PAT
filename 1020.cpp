#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
};
void level_output(node* root);

node* build_tree(int r, int start, int ends);

int post[30];
int in[30];
int count;

int main(){
    int N, i;
    scanf("%d", &N);
    
    for(i=0; i<N; i++) scanf("%d", &post[i]);
    for(i=0; i<N; i++) scanf("%d", &in[i]);
    
    node *root = build_tree(N-1, 0, N-1);
    level_output(root);
    
    return 0;
}

node* build_tree(int r, int start, int ends){
    if(start>ends) return NULL;
    int i = start;
    while(i<ends && post[r]!=in[i]) i++;   //find root
    node *root=(node *)malloc(sizeof(node));
    root->val = post[r];
    root->left = build_tree(r-(ends-i+1), start, i-1);
    root->right= build_tree(r-1, i+1, ends);
    return root;
}

void level_output(node* root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *top = q.front();
        q.pop();
        printf("%s%d", count==0 ? "" : " ", top->val);
        if(!count) count++;
        if(top->left!=NULL) q.push(top->left);
        if(top->right!=NULL) q.push(top->right);
    }
}


