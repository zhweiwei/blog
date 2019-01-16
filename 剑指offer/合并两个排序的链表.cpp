#include <cstddef>
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr)
        return pHead2;
        if(pHead2 == nullptr)
        return pHead1;
        
        ListNode * head,*tail,*p;
        head = tail = nullptr;

        while(pHead1 != nullptr && pHead2 != nullptr){
            if(pHead1->val < pHead2->val){
                p = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                p = pHead2;
                pHead2 = pHead2->next;
            }

            if(head == nullptr){
                head = tail = p;
                tail->next = nullptr;
                continue;
            }

            p->next = tail->next;
            tail->next = p;
            tail = p;
        }

        if(pHead1){
            tail->next = pHead1;
        }

        if(pHead2){
            tail->next = pHead2;
        }

        return head;
    }
};

int main(){
    cout<<"begin"<<endl;
    ListNode *Head, * second,*p,*q;
    second = Head = q = p = nullptr;
    for(int i = 0;i < 5;i++){
    p  = new ListNode(i);
    if(Head == nullptr){
        Head =q = p;
        p->next = nullptr;
        continue;
    }
    p->next = q->next;
    q->next = p;
    q = p;
    }

    for(int i = 0;i < 5;i++){
    p  = new ListNode(i);
    if(second == nullptr){
        second = q = p;
        p->next = nullptr;
        continue;
    }
    p->next = q->next;
    q->next = p;
    q = p;
    }

    Solution s;
    
    cout<<"begin"<<endl;
    s.Merge(Head,second);

    cout<<"end"<<endl;

}