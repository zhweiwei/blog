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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        map<int ,int> store;

        if(pHead == nullptr)
        return nullptr;

        ListNode * p,*d;

        p = pHead;
        while(p){
            store[p->val]++;
            p = p->next;
        }
         
         while(pHead && store[pHead->val] != 1){
             d = pHead;
             pHead = pHead->next;
         }

        if(!pHead)
        return nullptr;

         p = pHead;
        // while(p->next){
        //     if(store[p->next->val] == 0){
        //         ++store[p->next->val];
        //         p = p->next;
        //         continue;
        //     }
        //     d = p->next;
        //     p->next = d->next;
        //     delete d;
        // }
    
        while(p->next){
            if(store[p->next->val] == 1){
                p = p->next;
                continue;
            }else{
                d = p->next;
                p->next = d->next;
                delete d;
            }
        }

        return pHead;
    }
};