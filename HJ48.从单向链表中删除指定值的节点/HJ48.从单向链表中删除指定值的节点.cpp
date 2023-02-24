#include <cstddef>
#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
    node(){
        data = 0;
        next = NULL;
    }
    node(int _data, node* _next){
        data = _data;
        next = _next;
    }
}node, *linkList;

//查找值为value的节点
node* find(linkList L, int value){
    node *p = L;
    node* ans = NULL;
    while(p != NULL){
        if(p->data == value){
            ans = p;
            break;
        }
        else{
            p = p->next;
        }
    }
    return ans;
}
//在链表L中值为pos的节点后面插入节点value，若插入的表为空，则pos可为任意值
void insert(linkList &L, int pos, int value){
    if(L == NULL){
        L = new node(value, NULL);
        return;
    }
    node *p = find(L, pos);
    node *temp;
    if(p != NULL){
        temp = p->next;
        p->next = new node(value, temp);
    }
}
//删除值为value的节点
void erease(linkList &L, int value){
    node *temp;
    if( L != NULL &&L->data == value){
        temp = L;
        L = L->next;
        delete(temp);
        return;
    }
    node *pre = L, *p = L;
    if(p != NULL){
        p = p->next;
        while(p != NULL && p->data != value){
            pre = p;
            p = p->next;
        }
        if(p != NULL){
            pre->next = p->next;
            delete(p);
        }
    }

}

int main() {
    linkList L = new node;
    int n;
    int value, pos;
    node *p = L;
    cin >> n >> L->data;
    for(int i = 0; i < n - 1; i++){
        cin >> value >> pos;
        insert(L, pos, value);
    }
    cin >> value;
    erease(L, value);
    while(p != NULL){
        cout << p->data << ' ';
        p = p->next;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")