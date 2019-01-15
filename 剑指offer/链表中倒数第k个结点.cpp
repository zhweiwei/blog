#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k <= 0 || pListHead == nullptr)
        return nullptr;

        int size = 1;
        ListNode *tmp = pListHead;
        while(tmp){
            size++;
            tmp = tmp->next;
        }

        if(k> size)
        return nullptr;

        tmp = pListHead;
        for(int i= 1;i<=size - k;i++)
        tmp = tmp->next;

        return tmp;
    }
};