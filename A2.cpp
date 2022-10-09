#include <iostream>
#include <iomanip>
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

    Node* setInfo()
    {
        Node *temp=new Node;
        cout<<"Enter Phone Number: ";
        cin>>temp->phoneNumber;
        cout<<"Enter Owner Name: ";
        cin>>temp->ownerName;
        cout<<"Enter address: ";
        cin>>temp->address;
        cout<<"Enter Email: ";
        cin>>temp->email;

        return temp;
    }

    void insert()
    {
        userCounter++;
        if (userCounter > rows * cols)
        {
            cout << "\nReached Maximum limit of users : " << rows * cols << endl;
            return;
        }

        Node *curr = setInfo();
        // curr->phoneNumber = phoneNum;
        // curr->ownerName = ownerName_;
        // curr->address = addres_;
        // curr->email = email_;

        Node *ptrTemp = listHeadPtr;
        if (listHeadPtr == NULL)
        {
            colsCounter++;
            listHeadPtr = curr;
            cout << "Node Inserted\n";
            return;
        }


        if (rowCounter > 1)
            while (ptrTemp->bot != NULL)
                ptrTemp = ptrTemp->bot;

        if (colsCounter > 1)
            while (ptrTemp->next != NULL)
                ptrTemp = ptrTemp->next;

        colsCounter++;
        if (colsCounter <= cols && colsCounter != 1)
        {

            ptrTemp->next = curr;
            curr->prev = ptrTemp;
        }
        if (colsCounter == cols)
        {
            colsCounter = 0;
            rowCounter++;
            cout << "Node Inserted\n";
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
        if (row_ == 1)
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

    // SEARCH FOR DUPLICATESSSSS
    Node *search(string ownerName_, int row_ = 1)
    {

        if (row_ > rowCounter)
        {
            cout << "\nPhone Number Not FOUND\n";
            Node *temp = NULL;
            return temp;
        }

        Node *ptrTemp = listHeadPtr;
        for (int i = 1; i < row_; i++)
            ptrTemp = ptrTemp->bot;

        while (ptrTemp != NULL)
        {
            if (ptrTemp->ownerName == ownerName_)
                return ptrTemp;
            if (ptrTemp->next != NULL)
                ptrTemp = ptrTemp->next;
            else
                break;
        }
        row_++;
        return search(ownerName_, row_);

        // return temp;
    }

    void displaySpecific(Node *ptrTemp)
    {
        if (ptrTemp != NULL)
        {
            cout << "Owner Name :" << ptrTemp->ownerName << "\n";
            cout << "Phone Number :" << ptrTemp->phoneNumber << "\n";
            cout << "Address :" << ptrTemp->address << "\n";
            cout << "email :" << ptrTemp->email << "\n";
        }
    }


    void deleteNode(string ownerName_)
    {
        Node *temp=search(ownerName_);
        if(temp==NULL)
        {
            cout<<"Phone Number does not exist in the directory";
            return;
        }
        
    }
};

void menu()
{
    cout << "(1)Insert a Phone Number \n";
    cout << "(2)Delete an existing phone Number from the system \n";
    cout << "(3)Search an Owner's Name and display the details \n";
    cout << "(4)Display Entire Phone Directory\n\n";

    cout << setw(50) << "Enter the menu you would like to enter or enter -1 to exit:";
}


int main()
{

    int rows = 3, int cols = 5;
    int select_menu;
    cout << "Enter Number of Rows and Columns\n";
    cin >> rows >> cols;
    telephoneDirectory A(rows, cols);
    menu();
    cin >> select_menu;
    do
    {
        switch(select_menu)
        {
        case 1:
            cout << endl;
            A.insert();
            cout << endl;
            break;
        case 2:
            string ownerName_;
            cout<<"\n Enter an Owner's Name you would like to Delete: ";
            cin>>ownerName_;
            A.deleteNode(ownerName_);
            cout << endl;
            break;
        case 3:
            string ownerName_;
            cout<<"\n Enter an Owner's Name you would like to search: ";
            cin>>ownerName_;
            A.displaySpecific(A.search(ownerName_));
            cout << endl;
            break;
        case 4:
            break;
        case -1:
            system("CLS");
            cout << "Program Exiting...\n\n";
            exit(1);
        default:
            cout << setw(50) << "Invalid Input...Try Again: \n";
        }
        menu();
        cin >> select_menu;
    } while (1);
}