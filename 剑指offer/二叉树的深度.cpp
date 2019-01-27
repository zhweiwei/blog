#include <cstddef>
#include <vector>
#include <queue>

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
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot == nullptr)
        return 0;

        queue<TreeNode *> bfs;
        bfs.push(pRoot);
        int count ,level,nextcount;

        level = 0;
        count =1;
        nextcount =0 ;

        while(!bfs.empty()){
            TreeNode *tmp = bfs.front();
            bfs.pop();
            count--;

            if(tmp->left){
                bfs.push(tmp->left);
                nextcount++;
            }
            
            if(tmp->right){
                bfs.push(tmp->right);
                nextcount++;
            }

            if(count == 0){
                count = nextcount;
                nextcount = 0;
                level++;
            }
        }
        return level;
    }
};