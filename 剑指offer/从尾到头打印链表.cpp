#include <vector>

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
    vector<int> printListFromTailToHead(ListNode* head) {
       vector<int> a;
       if(head == nullptr)
       return a;

       ListNode* tmp =nullptr,*p;
        
       
       while(head != nullptr){
           
           p = head;
           head = head->next;
           if(tmp == nullptr){
               tmp = p;
               p->next = nullptr;
               continue;
           }
           p->next = tmp;
           tmp = p;
       } 

       while(tmp != nullptr){
           a.push_back(tmp->val);
           tmp = tmp->next;
       }

       return a;
    }
};