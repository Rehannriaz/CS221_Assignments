#include <iostream>
using namespace std;

class List
{
    struct Node
    {
        int val;
        Node *next;
        Node *prev;
    };
    Node *listHeadPtr;
    Node *listTailPtr;

public:

    List()
    {
        listHeadPtr=NULL;
        listTailPtr=NULL;
    }
    void addNodeAtHead(int value)
    {
        Node *curr = new Node;
        curr->val = value;
        curr->prev=NULL;
        curr->next = listHeadPtr;
        if(listHeadPtr==NULL)
            listHeadPtr=new Node;
        listHeadPtr->prev = curr;
        listHeadPtr = curr;
    }
    void addNodeAtTail(int value)
    {
        Node *curr = new Node;
        curr->val = value;
        curr->next = NULL;
        if (listHeadPtr == NULL)
        {
            curr->prev = NULL;
            listHeadPtr = curr;
            return;
        }
        Node *temp = listHeadPtr;

        while (temp->next != NULL)
            temp = temp->next;
        temp->next = curr;
        curr->prev = temp;
    }
    void print()
    {
        Node *temp = listHeadPtr;
        while (temp != NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
            listTailPtr=temp;
            // cout<<temp->val<<" ";
            // temp=temp->prev;
        }
        // cout<<endl;
            // temp=temp->prev;
        cout<<"\n REVERSE";
        while(temp->prev!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->prev;
        }    
    }

};

int main()
{ 
    List a;
    a.addNodeAtTail(5);
    // a.addNodeAtHead(5);
    a.addNodeAtTail(6);
    // a.addNodeAtTail(7);
    // a.addNodeAtHead(6);
    // a.addNodeAtHead(8);
    a.print();
}