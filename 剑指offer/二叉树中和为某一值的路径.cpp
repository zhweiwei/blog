#include <cstddef>
#include <vector>
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
    vector< vector<int> > reval;
    vector<int> tmp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
            vector<int > tmp;
            if(root == nullptr)
            return reval;

            testNode(root,expectNumber,0);
            return reval;
    }

    void testNode(TreeNode * root,int expectNumber,int val){
        tmp.push_back(root->val);

        if(root->left == nullptr && root->right ==nullptr){
            if(root->val + val == expectNumber){
                reval.push_back(tmp);
            }else{
                tmp.pop_back();
                return;
            }
        }

        if(root->val + val > expectNumber){
            tmp.pop_back();
            return;
        }
        

        if(root->left != nullptr)
        testNode(root->left ,expectNumber,val + root->val);

        if(root->right != nullptr)
        testNode(root->right,expectNumber,val+root->val);

        tmp.pop_back();
    }
};