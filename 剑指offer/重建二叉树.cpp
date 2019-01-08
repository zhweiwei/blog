#include <vector>
#include<cstdlib>


using namespace std;

//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty())
        return nullptr;

        int val = pre[0];
         TreeNode * tmp = new TreeNode(val);
         int count = pre.begin() - pre.end();
        int sum = 0;
        for(int i = 0;i < count;i++){
            if(vin[i] == val)
            break;
            sum++;
        }

        
        tmp->left = reConstructBinaryTree(pre.begin()+1,vin.begin(),sum);
    tmp->right = reConstructBinaryTree(pre.begin()+1+sum,vin.begin()+sum+1,count-1-sum);

         return tmp;
    }

TreeNode* reConstructBinaryTree( vector<int>::iterator pre,vector<int>::iterator vin ,int count) {
    if(count == 0)
    return nullptr;

    int val = *pre;
    TreeNode * tmp = new TreeNode(val);

    int sum = 0;
    int i = 0;
    while(i < count){

        if(*(vin+i) == val)
        break;
        sum++;
        i++;
    }

    tmp->left = reConstructBinaryTree(pre+1,vin,sum);
    tmp->right = reConstructBinaryTree(pre+1+sum,vin+sum+1,count-1-sum);

    return tmp;
}

};

int main(){

    vector<int> v2{4,7,2,1,5,3,8,6};
    vector<int> v1{1,2,4,7,3,5,6,8};

    Solution s;
    s.reConstructBinaryTree(v1,v2);
}