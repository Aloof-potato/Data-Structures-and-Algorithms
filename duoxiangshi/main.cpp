#include"ADT.h"
#include<iostream>
using namespace std;

void Attach(int c,int e,Node*&tail){
    Node*newNode=new Node;
    newNode->coef=c;
    newNode->expon=e;
    tail->next=newNode;
    tail=newNode;
}
int main(){
    Node*head1=create();
    Node*head2=create();
    Node*p1=head1->next;
    Node*p2=head2->next;
    Node*head3=new Node;
    head3->next=nullptr;
    Node*tail=head3;
    while(p1!=nullptr&&p2!=nullptr){
        if(p1->expon>p2->expon){
            Attach(p1->coef,p1->expon,tail);
            p1=p1->next;
        }
        else if(p1->expon<p2->expon){
            Attach(p2->coef,p2->expon,tail);
            p2=p2->next;
        }
        else{
            int sum=p1->coef+p2->coef;
            if(sum!=0){
                Attach(sum,p1->expon,tail);
            }
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1!=nullptr){
        Attach(p1->coef,p1->expon,tail);
        p1=p1->next;
    }
    while(p2!=nullptr){
        Attach(p2->coef,p2->expon,tail);
        p2=p2->next;
    }
    Node*p=head3->next;
    while(p!=nullptr){
        cout<<p->coef<<" "<<p->expon<<endl;
        p=p->next;
    }
    return 0;
}