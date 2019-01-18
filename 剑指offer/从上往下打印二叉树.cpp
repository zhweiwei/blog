#include <cstddef>
#include <queue>
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

    queue<int> tamp;
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> val;
        queue<TreeNode*> tamp;
        TreeNode * node;
        
        if(root == nullptr)
            return val;

        tamp.push(root);
        while(!tamp.empty()){
            node = tamp.front();
            tamp.pop();
            val.push_back(node->val);

            if(node->left)
            tamp.push(node->left);

            if(node->right)
            tamp.push(node->right);
        }

        return val;
        
    }
};