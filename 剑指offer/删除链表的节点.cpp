#include <iostream>

using namespace std;

struct ListNode{
    int value;
    struct ListNode * next;
};

class Solusion{
    public:
    bool DeleteNode(ListNode ** head,ListNode * pToDelete){
        if(head ==NUll || pTODelete == NULL)
        return false;

        ListNode * tmp = *head;
        if(tmp == pToDelete){
            *head = pTodeDelete->next;
            delete(pToDelete);
            return true;
        }
        while(tmp->next != pToDelete && tmp ->next != NULL)
        tmp = tmp->next;

        if(tmp->next == pToDelete){
            tmp->next = pToDelete->next;
            delete(pToDelete);
            return true;
        }
        return false;

    }
}