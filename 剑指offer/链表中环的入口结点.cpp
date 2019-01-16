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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr)
        return nullptr;

        ListNode* p1,*p2;
        p2 = pHead;
        p1 = p2->next;
        while(p1 != nullptr && p2 != nullptr){
            if(p1 == p2)
            break;
            p2 = p2->next;

            p1= p1->next;
            if(p1 == nullptr)
            break;
            p1= p1->next;
        }

        if(p1 == nullptr || p2 == nullptr)
        return nullptr;

        int cout = 1;
        p1 = p1->next;
        while(p1 != p2){
            cout++;
            p1 = p1->next;
        }

        p1 = pHead;
        for(int i = 0;i < cout;i++)
        p1 = p1->next;

        p2 = pHead;

        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};

int main(){
    ListNode *Head, *p,*q;
    p = new ListNode(3);
    Head = q= p;
    for(int i = 0;i < 5;i++){
    p  = new ListNode(i);
    q->next = p;
    q = p;
    }
    q->next = Head->next->next;
    
    Solution s;
    p = nullptr;
    cout<< "begin "<<endl;
    p = s.EntryNodeOfLoop(Head);
    if(p)
    cout<<p->val<<endl;
    else
    cout<<"no find"<<endl;

}