/**
 * @file A2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
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

    Node *setInfo()
    {
        Node *temp = new Node;
        cout << "Enter Phone Number: ";
        cin.ignore();
        getline(cin, temp->phoneNumber);
        cout << "Enter Owner Name: ";
        getline(cin, temp->ownerName);
        cout << "Enter address: ";
        getline(cin, temp->address);
        cout << "Enter Email: ";
        getline(cin, temp->email);

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
            cout << endl
                 << endl;
            ptrTemp = ptrTemp->next;
        }
        row_++;
        printList(row_);
    }

    // SEARCH FOR DUPLICATESSSSS
    Node *search(string data, int row_ = 1)
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
            if (ptrTemp->ownerName == data || ptrTemp->email == data || ptrTemp->address == data)
                return ptrTemp;
            if (ptrTemp->next != NULL)
                ptrTemp = ptrTemp->next;
            else
                break;
        }
        row_++;
        return search(data, row_);

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

    void setNode(Node *temp1, Node *temp2)
    {
        temp1->address = temp2->address;
        temp1->phoneNumber = temp2->phoneNumber;
        temp1->email = temp2->email;
        temp1->ownerName = temp2->ownerName;
    }

    void deleteNode(string ownerName_)
    {
        Node *temp = search(ownerName_);
        if (temp == NULL)
        {
            cout << "Phone Number does not exist in the directory";
            return;
        }
        userCounter-=2;
        if (temp->next != NULL)
            temp = temp->next;
        else
        {
            Node *temp2 = temp->prev;
            temp2->next = NULL;
            delete temp;
            cout << "node deleted\n";
            return;
        }
        while (temp != NULL)
        {

            setNode(temp->prev, temp);
            if (temp->next != NULL)
                temp = temp->next;
            else
                break;
        }
        Node *temp2 = temp->prev;
        temp2->next = NULL;
        delete temp;
        cout << "node deleted\n";
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
    int rows = 3, cols = 5;
    int select_menu;
    cout << "Enter Number of Rows and Columns: ";
    cin >> rows >> cols;
    telephoneDirectory A(rows, cols);
    menu();
    cin >> select_menu;
    do
    {
        string ownerName_;
        switch (select_menu)
        {
        case 1:
            cout << endl;
            A.insert();
            cout << endl;
            break;
        case 2:

            cout << "\n Enter an Owner's Name you would like to Delete: ";
            cin.ignore();
            getline(cin, ownerName_);
            system("CLS");
            A.deleteNode(ownerName_);
            cout << endl;
            system("pause");
            break;
        case 3:

            cout << "\n Enter an Owner's Name, Email or Address you would like to search: ";
            cin.ignore();
            getline(cin, ownerName_);
            system("CLS");
            A.displaySpecific(A.search(ownerName_));
            cout << endl
                 << endl;
            system("pause");
            break;
        case 4:
            system("CLS");
            A.printList();
            cout << endl
                 << endl;
            system("pause");
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