#include <cstddef>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
 
class Solution {
    map<RandomListNode*,RandomListNode*> mapkey;
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
        return nullptr;

        RandomListNode * tmp = pHead;
        while(tmp){
            if(tmp->random)
                mapkey.insert(pair<RandomListNode* , RandomListNode*>(tmp,tmp->random));

            RandomListNode *q = new RandomListNode(tmp->label);
            q->next = tmp->next;
            tmp->next =q;
            tmp = tmp->next->next;
        }
        tmp = pHead;
        makeRandNode();
       return returnNode(tmp);

    }

    void makeRandNode(){
        for(auto tmp = mapkey.begin();tmp != mapkey.end();tmp++){
            tmp->first->next->random = tmp->second->next;
        }
    }

    RandomListNode * returnNode(RandomListNode * Node){
        RandomListNode * tmp,*p,*q;
        if(Node != nullptr)
        tmp = p = Node->next;
        q = Node;
        while(p ->next != nullptr){
            q->next = q->next->next;
            p->next = p->next->next;
            p = p->next;
            q= q->next;
        }
        q->next = nullptr;
        return tmp;
    }
};

int main(){
    RandomListNode * head,*p ,*q;
    head = new RandomListNode(1);
    p = new RandomListNode(2);
    q = new RandomListNode(3);

    head->next = p;
    p->next =q;
    q->next = nullptr;

    head->random = q;
    p->random = head;

    Solution s;

    RandomListNode* tmp = s.Clone(head);
    RandomListNode *k  = tmp;
    while(tmp){
        cout <<tmp->label<<" ";
        tmp = tmp->next;
    }
    cout << k->random->label<<" next print head";
    while(head){
        cout <<head->label<<" ";
        head = head->next;
    }

}