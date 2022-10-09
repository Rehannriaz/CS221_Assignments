#include <iostream>

using namespace std;

class telephoneDirectory
{

    struct Node
    {
        int phoneNumber;
        string ownerName, address, email;
        Node *next, *prev, *top, *bot;
    };

    int rows, cols;
    Node *listHeadPtr;
    Node *mainListHeadPtr;

public:
    telephoneDirectory()
    {
        this->rows = 3;
        this->cols = 5;
        listHeadPtr = NULL;
    }
    telephoneDirectory(int row, int col)
    {
        this->rows = row;
        this->cols = col;
        listHeadPtr = NULL;
        listHeadPtr->top = NULL;
        // listHeadPtr->prev = NULL;
    }

    void createList()
    {
        
    }

    void addNodeAtTail()
    {
        Node *ptrNew = new Node;
        ptrNew->next = NULL;
        Node *ptrTemp = listHeadPtr;
        if (listHeadPtr == NULL)
        {
            listHeadPtr = ptrNew;
            return;
        }
        while (ptrTemp->next != NULL)
            ptrTemp = ptrTemp->next;

        ptrTemp->next = ptrNew;
    }

    Node *traverse(int i, int j) {}

    Node *specificTraverse(int R, int mod);
    void insertPhoneNum(int phoneNum, string name, string address_, string Email = "")
    {

        // curr->phoneNumber = phoneNum;
        // curr->ownerName = name;
        // curr->address = address_;
        // curr->email = Email;
    }

    ~telephoneDirectory()
    {
    }
};

int main()
{
    telephoneDirectory a;
    a.createList();
}
