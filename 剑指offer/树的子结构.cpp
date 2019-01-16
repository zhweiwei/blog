#include <cstddef>
#include <iostream>

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == nullptr)
        return false;

        return issubTree(pRoot1,pRoot2);

    }

    bool issubTree(TreeNode *p,TreeNode *q){
        if(q == nullptr)
        return true;

        if(p == nullptr)
        return false;


        if(p->val == q->val){
           if(nextsub(p,q))
           return true;
           
        }

        return  issubTree(p->left,q) || issubTree(p->right,q);

    }

    bool nextsub(TreeNode *p ,TreeNode *q){
        if(q == nullptr)
        return true;

        if(p == nullptr)
        return false;

        if(p->val != q->val)
        return false;

        return nextsub(p->left,q->left) && nextsub(p->right,q->right);
    }
};