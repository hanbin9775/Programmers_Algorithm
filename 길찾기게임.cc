#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> btree;
vector<int> pre_v;
vector<int> post_v;

bool comp(vector<int> a, vector<int> b){
    if(a[1]==b[1]) return a[0] < b[0];
    return a[1] > b[1];
}

int getRoot(vector<vector<int>>& tree){

    int root = tree[0][2];

    vector<vector<int>> left_sub;
    vector<vector<int>> right_sub;

    for(int i=1; i<tree.size(); i++){
        if(tree[i][0]<tree[0][0]) left_sub.push_back(tree[i]);
        else if(tree[i][0]>tree[0][0]) right_sub.push_back(tree[i]);
    }

    sort(left_sub.begin(), left_sub.end(), comp);
    sort(right_sub.begin(), right_sub.end(), comp);

    if(left_sub.size()>0) btree[root].push_back(getRoot(left_sub));
    else btree[root].push_back(0);

    if(right_sub.size()>0) btree[root].push_back(getRoot(right_sub));
    else btree[root].push_back(0);

    return root;
}

void preorder(int root){

    pre_v.push_back(root);
    if(btree[root][0]!=0) preorder(btree[root][0]);
    if(btree[root][1]!=0) preorder(btree[root][1]);
}

void postorder(int root){
    if(btree[root][0]!=0) postorder(btree[root][0]);
    if(btree[root][1]!=0) postorder(btree[root][1]);
    post_v.push_back(root);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<vector<int>> infoWithIdx;
    btree.resize(nodeinfo.size()+1);

    for(int i=0; i<nodeinfo.size(); i++){
        vector<int> temp;
        temp.push_back(nodeinfo[i][0]);
        temp.push_back(nodeinfo[i][1]);
        temp.push_back(i+1);
        infoWithIdx.push_back(temp);    
    }

    sort(infoWithIdx.begin(), infoWithIdx.end(), comp);

    int root = getRoot(infoWithIdx);
    preorder(root);
    postorder(root);

    answer.push_back(pre_v);
    answer.push_back(post_v);

    return answer;
}