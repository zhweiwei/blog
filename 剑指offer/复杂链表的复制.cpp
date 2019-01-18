#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
 
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        
    }
};