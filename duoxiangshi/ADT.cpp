#include"ADT.h"
#include<iostream>
using namespace std;
Node*create(){
    Node*head=new Node;
    head->next=nullptr;
    Node*tail=head;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int c,e;
        cin>>c>>e;
        Node*newNode=new Node;
        newNode->coef=c;
        newNode->expon=e;
        tail->next=newNode;
        tail=newNode;
    }
    tail->next=nullptr;
    return head;
}