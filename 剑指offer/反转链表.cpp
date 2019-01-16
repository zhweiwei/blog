#include <cstddef>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode * tmp;

        tmp = nullptr;

        ListNode * p ,*q;
        p = pHead;
        while(p){
            q = p;
            p = p->next;
            
            q->next = tmp;
            tmp = q;
        }

        return tmp;
    }
};

int main(){

}