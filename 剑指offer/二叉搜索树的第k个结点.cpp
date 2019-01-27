#include <cstddef>


using namespace std;
 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
 
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k <= 0)
        return nullptr;

        int count = 0;
        return Mbs(pRoot,count,k);
    }

    TreeNode *Mbs(TreeNode * root,int & count,int k){
        if(root == nullptr)
        return nullptr;

        TreeNode* tmp;
        tmp = Mbs(root->left,count,k);
        if(tmp)
        return tmp;

        if(++count == k){
            return root;
        }

       return Mbs(root->right,count,k);
    }
};