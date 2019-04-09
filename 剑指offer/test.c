#include <stdlib.h>
#include <stdio.h>

int main(){
  char a = '0';
  char b= '8';
  printf("a = %d\n",(int)a);
  printf("b -a = %d\n",b - a);
}

void sort(struct student* head){
  struct student * p,*q,*a= NULL;
  p = head;
  while(p){
    q = p;
    p = p->next;
    q->next =NULL;
    if(a ==NULL){
      a = q;
    }else{
      if(a->sore > q->sore){  //判断插入的是否小于头指针
        q->next = a;
        a = q;
      }else{
        m = a;
        while(m->next && m->next->sore >= q->sore) //寻找next的值小于q的值
        m = m->next;

        q->next = m->next;
        m->next = q;
      }      
    }
  }
  head = a;
}

struct student* sort(struct student* a,struct student* b){
  struct student *head,*p,*q,*m,*tail;
  p = a;
  q = b;
  while(p && q){
    if(p->sore < q->sore){
      m = p;
      p =p->next;
    }else{
      m = q;
      q = q->next;
    }

    if(head == NULL){
     tail = head = m;
    }else{
      tail->next = m;
      tail = tail->next;
    }
  }

  if(p)
  tail->next = p;

  if(q)
  tail->next = q;

  return head;
}

struct student{
  char no[20],
  int sore,
  struct student* next;
}

int main(){
  struct student * a,*b;
  struct student *p,*q,*m;

  p = a;
  while(p){
    m = p;
    p = p->next;
    q = b;
    while(q && strcmp(m->no,q->no) != 0)    //从b的头指针开始遍历，当q为NULL或者相等是跳出循环
    q = q->next;

    if(q){  //表示q不为NULL，即存在相同
      if(m == a){   //判断是否为a的头指针
        a = a->next;
        free(m);
      }else{
        
        struct student * n ;
        n = a;
        while(n->next != m) //找到删除的前一个节点
        n = n->next;

        n->next = m->next;
        free(m);
      }
    }
  }
}

int  main(){
  int a,b,result;
  result = 0;
  while(a>0){
    result = result*10 + a%10;
    a /=10;
  }
  printf("%d",result);
}