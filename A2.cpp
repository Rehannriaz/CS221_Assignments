


#include <iostream>

using namespace std;

class telephoneDirectory
{
private:
    /**
     * @brief a struct for Node which handles all the data in a single node
     *
     */
    struct Node
    {
        string ownerName, address, email, phoneNumber;
        Node *next, *prev, *top, *bot;

        Node()
        {
            next = NULL;
            prev = NULL;
            top = NULL;
            bot = NULL;
            phoneNumber = "", ownerName = "", address = "", email = "";
        }
        ~Node() {}
    };
    int rows, cols;
    int counterDisplay;
    int userCounter;
    int rowCounter, colsCounter;
    Node *listHeadPtr;

public:
    telephoneDirectory(int row = 3, int col = 5)
    {
        this->rows = row;
        this->cols = col;
        this->counterDisplay = 0;
        rowCounter = 1;
        colsCounter = 0;

        userCounter = 0;
        listHeadPtr = NULL;
    }

    void insert(string phoneNum = "", string ownerName_ = "", string addres_ = "", string email_ = "")
    {
        userCounter++;
        if (userCounter > rows * cols)
        {
            cout << "\nReached Maximum limit of users : " << rows * cols;
            return;
        }
        Node *curr = new Node;
        curr->phoneNumber = phoneNum;
        curr->ownerName = ownerName_;
        curr->address = addres_;
        curr->email = email_;

        Node *ptrTemp = listHeadPtr;
        if (listHeadPtr == NULL)
        {
            listHeadPtr = curr;
            cout << "Node Inserted\n";
            return;
        }


        for (int i = 1; i < rowCounter; i++) // THIS IS CALLED EVEN THO 6th node is not created
            ptrTemp = ptrTemp->bot;

        while (ptrTemp->next != NULL)
            ptrTemp = ptrTemp->next;

        if (colsCounter <= cols)
        {
            ptrTemp->next = curr;
            curr->prev = ptrTemp;
        }
        colsCounter++;
        if (colsCounter == cols)
        {
            colsCounter = 0;
            rowCounter++;
            return;
        }
        if (rowCounter > 1)
        {
            if (colsCounter == 1)
            {
                ptrTemp = listHeadPtr;
                // curr->prev=NULL;
                // curr->next=NULL;
                while (ptrTemp->bot != NULL)
                    ptrTemp = ptrTemp->bot;

                ptrTemp->bot = curr;
                curr->top = ptrTemp;
                // return;
            }
            else
            {
                ptrTemp = curr->prev->top->next;
                ptrTemp->bot = curr;
                curr->top = ptrTemp;
            }
        }
        cout << "Node Inserted\n";
    }

    void printList(int row_ = 1)
    {
        counterDisplay = 0;
        if (row_ > rowCounter)
            return;

        Node *ptrTemp = listHeadPtr;
        for (int i = 1; i < row_; i++)
            ptrTemp = ptrTemp->bot;
        //   ptrTemp=listHeadPtr;
        while (ptrTemp != NULL)
        {
            counterDisplay++;
            cout << "User No." << counterDisplay << endl;
            displaySpecific(ptrTemp);
            ptrTemp = ptrTemp->next;
        }
        row_++;
        printList(row_);
    }

    Node *search(string phNum, int row_ = 1)
    {

        if (row_ > rowCounter)
        {
            cout << "\nPhone Number Not FOUND\n";
            Node *temp;
            return temp;
        }

        Node *ptrTemp = listHeadPtr;
        for (int i = 1; i < row_; i++)
            ptrTemp = ptrTemp->bot;

        while (ptrTemp->next != NULL)
        {
            if (ptrTemp->next->phoneNumber == phNum)
                return ptrTemp->next;

            ptrTemp = ptrTemp->next;
        }
        row_++;
        search(phNum, row_);
        // return ptrTemp;
    }

    void displaySpecific(Node *ptrTemp)
    {
        // cout<<"Owner Name :"<< ptrTemp->ownerName<<"\n";
        cout << "Phone Number :" << ptrTemp->phoneNumber << "\n";
        // cout<<"Address :"<< ptrTemp->address<<"\n";
        // cout<<"email :"<< ptrTemp->email<<"\n";
    }
};
int main()
{
    telephoneDirectory a(3, 5);
    a.insert("1", "", "", "");
    // a.display();
    a.insert("2", "", "", "");
    // a.insert("345", "","","");
    // a.insert("345", "","","");
    a.insert("3", "", "", "");
    // a.insert("3", "heasdllo", "nig", "cat");
    a.insert("4", "", "", "");
    a.insert("5", "", "", "");
    a.insert("6", "", "", "");
    // a.insert("6", "hello", "nig", "cat");
    a.printList();
    // a.displaySpecific(a.search("10"));
    // a.printList();
}