#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向
*/

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
        return nullptr;

        if(pRootOfTree->left == nullptr && pRootOfTree->right == nullptr)
        return pRootOfTree;

        TreeNode * p = Convert(pRootOfTree->left);

        TreeNode * left = p;

        if(left != nullptr){
            while(left->right){
                left = left->right;
            }

            left->right = pRootOfTree;
            pRootOfTree->left = left;
        }

        TreeNode *right = Convert(pRootOfTree->right);

        if(right != nullptr){
            right->left = pRootOfTree;
            pRootOfTree->right = right;
        }

        return p != nullptr ? p : pRootOfTree;
        

    }

};