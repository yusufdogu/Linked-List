#include <stdio.h>
#include <stdlib.h>
void rev();
void add(int);
void delet();
void adaf(int);
void adbe(int);
void outpt();
typedef struct NODE {
    int data;
    struct NODE *next;

}node;
node *head=NULL;
node *temp=NULL;
int main() {
    int a,data,i=4;
    while(i>0) {
        scanf("%d",&a);
        scanf("%d",&data);
        if(a==1) {
            add(data);
        }
        if(a==2) {
            delet();
        }
        if(a==3) {
            adaf(data);
        }
        if(a==4) {
            rev();
        }
        if(a==5) {
            adbe(data);
        }
        outpt();
        i--;
    }

}
void add(int data) {
    node *new=malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    if(head==NULL) {
        head=new;
    }
    else {
        temp=head;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=new;
    }
}
void adbe(int data) {
    node *new=malloc(sizeof(node));
    new->data=data;
    new->next=head;
    head=new;
}
void adaf(int data) {
    int r;
    node *new=malloc(sizeof(node));
    printf("Where would you like to add this?");
    scanf("%d",&r);
    new->data=data;
    node *prev=NULL;
    temp=head;
    while(r-1>0) {
        prev=temp;
        temp=temp->next;
        r--;
    }
    prev->next=new;
    new->next=temp;
}
void delet() {
    int r;
    scanf("%d",&r);
    node *prev=NULL;
    node *curr=NULL;
    temp=head;
    while(r-1>0) {
        prev=temp;
        temp=temp->next;
        r--;
    }
    curr=prev->next;
    free(curr);
    prev->next=temp;

}
void rev() {
    node *prev=NULL;
    node *curr=head;
    node *post=NULL;
    while (curr!=NULL) {
        post=curr->next;
        curr->next=prev;
        prev=curr;
        curr=post;
    }
    head=curr;
}
void outpt() {
    temp=head;
    while(temp->next!=NULL) {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}