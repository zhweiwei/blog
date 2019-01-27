#include <cstddef>
#include <map>

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;

        map<ListNode*,int> tmp;

        ListNode* p,*q;
        p = pHead1;
        q= pHead2 ;
        while(p){
            tmp[p]++;
            p = p->next;
        }

        while(q){
            if(tmp[q] > 0)
            return q;
            q = q->next;
        }

        return nullptr;
    }
};