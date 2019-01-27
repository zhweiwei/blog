#include <queue>
#include <vector>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> Rvalue;

        if(pRoot == nullptr)
        return Rvalue;

        queue<TreeNode*> Qtamp;
        int count,nextcount;
        Qtamp.push(pRoot);
        count = 1;
        nextcount = 0;
        vector<int> tmp;
        while(!Qtamp.empty()){
            TreeNode *q = Qtamp.front();
            tmp.push_back(q->val);
            Qtamp.pop();
            count--;

            if(q->left){
                Qtamp.push(q->left);
                nextcount++;
            }

            if(q->right){
                Qtamp.push(q->right);
                 nextcount++;
            }

            if(count == 0){
                Rvalue.push_back(tmp);
                tmp.erase(tmp.begin(),tmp.end());
                count = nextcount;
                nextcount = 0;
            }
        }

        return Rvalue;
    }
    
};