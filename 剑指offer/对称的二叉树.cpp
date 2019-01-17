 #include <iostream>
 #include <cstddef>
 #include <stack>

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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == nullptr)
        return true;

        TreeNode * col = clone(pRoot);

        Megrant(col);

        return testSame(col,pRoot);
    }

    TreeNode* clone(TreeNode * pRoot){
        if(pRoot == nullptr)
        return nullptr;

        TreeNode * p = new TreeNode(pRoot->val);

        if(pRoot->left)
        p->left = clone(pRoot->left);

        if(pRoot->right)
        p->right = clone(pRoot->right);

        return p;
    }

    void Megrant(TreeNode * pRoot){
        if(pRoot != nullptr){
            stack<TreeNode *> st;
            TreeNode *t , *k;
            st.push(pRoot);

            while(!st.empty()){
                t  =st.top();
                st.pop();
                k = t->right;
                t->right = t->left;
                t->left = k;

                if(t->right)
                    st.push(t->right);
                
                if(t->left)
                st.push(t->left);
            }
        }
    }

    bool testSame(TreeNode * one,TreeNode *second){
        if(one == nullptr && second == nullptr)
        return true;

        if(one == nullptr)
        return false;

        if(second == nullptr)
        return false;

        if(one->val == second->val)
        return testSame(one->left,second->left) && testSame(one->right,one->right);

        return false;
    }
};