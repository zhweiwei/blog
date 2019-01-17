#include <iostream>
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot != nullptr){
            TreeNode *t;
            t = pRoot->right;
            pRoot->right = pRoot->left;
            pRoot->left = t;

            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }


    }
};