#include <cstdio>
#include <iostream>
using namespace std;

typedef struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
}ListNode;

typedef struct linklist{
    ListNode *head;
    ListNode *rear;
    linklist(){
        head = new ListNode;
        rear = head;
    }
}linklist;

void insert(linklist &linkList, int n){
    linkList.rear->m_pNext = new ListNode;
    linkList.rear = linkList.rear->m_pNext;
    linkList.rear->m_nKey = n;
    linkList.rear->m_pNext = NULL;
}

void destoryLinklist(linklist &linkList){
    ListNode *p = linkList.head->m_pNext;
    while(linkList.head->m_pNext != NULL){
        p = linkList.head->m_pNext;
        linkList.head->m_pNext = p->m_pNext;
        delete(p);
    }
    linkList.rear = linkList.head;
}

int main() {
    int n = 0, k = 0;
    linklist linkList;
    int temp;
    ListNode *p = linkList.head;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            insert(linkList, temp);
        }
        scanf("%d", &k);
        for(int i = 0; i < n - k + 1; i++){
            if(p->m_pNext == NULL){
                p = NULL;
                break;
            }
            p = p->m_pNext;
        }
        if(p != linkList.head && p != NULL){
            printf("%d\n", p->m_nKey);
        }
        destoryLinklist(linkList);
        p = linkList.head;
    }
    
    return 0;
}
// 64 位输出请用 printf("%lld")