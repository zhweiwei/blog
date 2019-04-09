#include <stdlib.h>
#include <stdio.h>


#define LEN sizeof(struct node)
#define LN sizeof(struct counter)

struct node{
  int count;
  char a[50];
  struct node * next;
};

struct counter{
  char name[20];
  int count;
  struct node * no;
  struct counter *next;
}

int main(){
  struct counter *head,
  char name[20];
  printf("请输入账户");
  scanf("%s",name);

  struct counter *p;

  p =head;

  while(p != NULL){
    if(compare(p->name,name) == 0)
    break;
    p = p->next;
  }

  if(p == NULL){
    printf("账户不存在");
    return 0;
  }

  while(1){
    printf("输入值 0表示退出，1表示存钱，2，表示取钱，3表示查询记录，4查询余额");
    int n ;
    int k;

    scanf("%d",&n);
    switch (n)
    {
      case 0:
        printf("用户退出");
        return 0;
      case 1:
        printf("输入存入金额")；
        scanf("%d",k);
        p->count += k;
        struct node * w = (struct node*)malloc(LEN);
        w->count = k;
        w->a = "存入金额为";
        w->next = p->no;
        p->no = w;
        break;
      
      case 2:
         printf("输入存入金额")；
        scanf("%d",k);
        if(p->count < k){
          printf("金额不足");
          return 0;
        }
        p->count -= k;
        struct node * w = (struct node*)malloc(LEN);
        w->count = k;
        w->a = "取出金额为";
        w->next = p->no;
        p->no = w;
        break;

      case 3:
       struct node *w;
       w = p->no;
       while(w){
         printf("%s %d",w->a,w->count);
         w = w->next;
       } 
        break;

      case 4:
        printf("用户余额为%d",p->count);
        break;
      default:
        break;
    }
  }
}
/*

第三题
*/
#include <stdio.h>
#include <stdlib.h>

int test(int *arr,int count, int num){ //用于检测生成的随机数之前是否已经生成过
    int i = 0;

    for(;i <count;i++){
        if(arr[i] == num)
        return -1;
    }

    return count;
}

int main(){
    int arr[5] ; //存储抽奖结果
    int i = 0;
    while(i < 5){
        int num = rand()%100 +1; //随机生成1-100的数
        int re = test(arr,i,num);
        if(re != -1){
            arr[i] = num;
            i++;
        }
    }

    printf("生成的随机数是：");

    for(i = 0;i < 5;i++){
        printf("%d ",arr[i]);
    }
}

/*

第五题

*/

#include <stdio.h>

struct Node{
    char cout[20];
    int number;
    struct Node * next;
};

int main(){
    char formcout[20],tocout[20];
    int number;
    struct Node * head; //假设head是客户群的链表头
    printf("请输入用户账号:")；
    scanf("%s",formcout);
    printf("请输入转账金额：");
    scanf("%d",&number);
    printf("请输入转入账号:")；
    scanf("%s",tocout);

    struct Node * p ,*q;
    p = head;
    while(p){
        if(compare(p->cout,formcout) == 0)
        break;

        p = p->next;
    }

    if(!p){
        printf("no find user!");
        return ;
    }

    if(p->number < number){
        printf("金额不足");
        return 0;
    }
  
    q  = head;
    while(q){
        if(compare(q->cout,formcout) == 0)
        break;

        q= q->next;
    }

    if(!q){
        printf("no find user!");
        return ;
    }

    p->number -= number;
    q->number += number;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

} 