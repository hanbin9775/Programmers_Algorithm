#include <string>
#include <vector>

using namespace std;

struct node{
    bool value;
    node* left;
    node* right;
};

vector<int> answer;

void make_child(node* leaf, int cnt){
    node* left_c = new node;
    left_c->value=0;
    left_c->left=NULL;
    left_c->right=NULL;    
    leaf->left = left_c;
    
    node* right_c = new node;
    right_c->value=1;
    right_c->left=NULL;
    right_c->right=NULL;
    leaf->right= right_c;
    
    if(cnt>1){
        make_child(left_c, cnt-1);
     }
    answer.push_back(leaf->value);
    if(cnt>1){
        make_child(right_c, cnt-1);
     }
}

vector<int> solution(int n) {
    

    node* root = new node;

    root->value = 0;
    root->left = NULL;
    root->right = NULL;    
    
    make_child(root,n);    
        
    
    
    return answer;
}