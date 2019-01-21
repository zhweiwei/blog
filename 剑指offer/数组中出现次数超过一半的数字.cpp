#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
    struct Node{
        int val;
        int count;
        Node* left;
        Node* right;
        Node(int value):val(value),count(1),left(nullptr),right(nullptr){}
    };
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size = numbers.size();
        Node * tmp = nullptr;
        for(int i = 0;i < size;i++){
            insertNode(&tmp,numbers[i]);
        }

        return findnumber(tmp,size/2);
    }

    int findnumber(Node* root,int value){
        if(root == nullptr)
        return 0;

        if(root->count > value)
        return root->val;

        int k = findnumber(root->left,value);
        if(k != 0)
        return k;
        return  findnumber(root->right,value);
    }

    void insertNode(Node ** root,int value){
        if(*root == nullptr){
            *root = new Node(value);
            return;
        }

        if(value == (*root)->val){
            (*root)->count +=1;
            return ;
        }

        if(value < (*root)->val){
            insertNode(&(*root)->left,value);
        }

        if(value > (*root)->val)
        insertNode(&(*root)->right,value);
    }
};

int main(){
    vector<int> val = {1,2,3,2,2,2,5,4,2};
    Solution s;
    cout << s.MoreThanHalfNum_Solution(val);
}