

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)
        return nullptr;

        if(pNode->right != nullptr){
          return  PrintNext(pNode->right);
        }

       return PrintRight(pNode);

    }

    TreeLinkNode* PrintNext(TreeLinkNode* pNode){
        while(pNode->left != nullptr)
                pNode = pNode->left;
        return pNode;
    }

    TreeLinkNode* PrintRight(TreeLinkNode* pNode){
        if(pNode->next == nullptr)
        return nullptr;
        if(pNode->next->left == pNode)
        return pNode->next;

        return PrintRight(pNode->next);
    }
};