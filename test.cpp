/**
 * @file A1_2021438_2021051.cpp
 * @author Rehan Riaz, GTA
 * @brief 4 way linked list
 * @version 0.1
 * @date 2022-10-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

/**
 * @brief telephone directory class
 *
 */
class telephoneDirectory
{
private:
    /**
     * @brief a struct for Node which handles all the data in a single node
     *
     */
    struct Node
    {
        int phoneNumber;
        string ownerName, address, email;
        Node *next, *prev, *top, *bot;

        Node()
        {
            phoneNumber = 0;
            ownerName = "", address = "", email = "";
        }
        ~Node() {}
    };

    Node *nextLL;
    int rows, cols;
    Node *listHeadPtr;

public:
    /**
     * @brief Construct a new telephone Directory object
     *
     * @param row
     * @param col
     */
    telephoneDirectory(int row = 3, int col = 5);
   
    /**
     * @brief Create a 4 way linked list with X number of rows and Y number of columns
     *
     */
    void createList();

    /**
     * @brief traverse's through the linked list
     *        goes down when it reaches the end
     *        traverses front in odd rows
     *        traverses back in even rows
     *
     * @param i
     * @param j
     * @return Node*, returns  pointer of last node added
     */
    Node *traverse(int i, int j);
    {

        Node *temp = listHeadPtr;

        if (listHeadPtr == NULL)
            return listHeadPtr;

        for (int x = 1; x <= i;) // fix cols for going down
            for (int y = 1; y <= j;)
            {
                // MAKE FUNCTION THAT CHECKS IF TEMP->NEXT IS EMPTY OR NOT
                if (y == cols)
                {
                    if (y % rows == 0) // HOW TO CHECK IT REACHED LAST NODE????
                        return temp;
                    x++;
                    temp = temp->bot;
                    y = 0;
                }
                else if (x % 2 == 1)
                {
                    y++;
                    if (temp->next == NULL)
                        return temp;
                    temp = temp->next;
                }
                else
                {
                    y++;
                    if (temp->prev == NULL)
                        return temp;
                    temp = temp->prev;
                }
            }
        return temp;
    }

    /**
     * @brief traverses to a specific Node
     *
     * @param R
     * @param colNum
     * @return Node*
     */
    Node *specificTraverse(int R, int colNum)
    {
        int j = 1;
        Node *temp;
        if (R == 1)
        {
            temp = listHeadPtr;
            while (temp->next != NULL)
            {
                if (j + colNum != cols + 1)
                {
                    temp = temp->next;
                    j++;
                }
                else
                {
                    return temp;
                }
            }
        }
        else
        {
            if (R % 2 == 1)
            {
                temp = nextLL;
                while (temp->next != NULL)
                {
                    if (j + colNum != cols + 1)
                    {
                        temp = temp->next;
                        j++;
                    }
                    else
                    {
                        return temp;
                    }
                }
            }
            else
            {
                temp = nextLL;
                while (temp->prev != NULL)
                {
                    if (j + colNum != cols + 1)
                    {
                        temp = temp->prev;
                        j++;
                    }
                    else
                        return temp;
                }
            }
        }
        return temp;
    }

    /**
     * @brief insertion of data into an empty node
     *
     * @param phoneNum
     * @param name
     * @param address_
     * @param Email
     */
    void insertPhoneNum(int phoneNum, string name, string address_, string Email = "")
    {
    }

    /**
     * @brief Destroy the telephone Directory object
     *
     */
    ~telephoneDirectory() {}
};


/**
 * @brief int main where object is created and called
 * 
 */
int main()
{

    telephoneDirectory a;
    a.createList();
}

telephoneDirectory::telephoneDirectory(int row =3, int col =5)
{
        this->rows = row;
        this->cols = col;
        listHeadPtr = NULL;
}
void telephoneDirectory::createList()
    {
        Node *top = new Node;
        for (int i = 1; i <= rows; i++)

            for (int j = 1; j <= cols; j++)
            {
                Node *curr = new Node;
                if (j % cols == 1)
                {
                    curr->prev = NULL;

                    if (i != 1)
                    {
                        Node *previous = traverse(i, j);
                        curr->prev = NULL;
                        curr->top = previous;
                        previous->bot = curr;
                        nextLL = curr;
                    }
                }
                else if (j % cols == 0)
                {
                    curr->next = NULL;
                }

                if (i % rows == 1)
                {
                    curr->top = NULL;
                }

                else if (i % rows == 0)
                {
                    curr->bot = NULL;
                }

                if (i % 2 == 1) // odd numbers
                {
                    Node *previous;
                    if (listHeadPtr != NULL)
                    {
                        previous = traverse(i, j);
                        curr->next = NULL;
                        previous->next = curr;
                        curr->prev = previous;

                        if (i > 1 && j != 1)
                        {
                            top = specificTraverse(i - 1, j);
                            curr->top = top;
                            top->bot = curr;
                        }
                    }
                    else
                    {
                        listHeadPtr = curr;
                        curr->next = NULL;
                        curr->prev = NULL;
                    }
                }
                else if (i % 2 == 0)
                {
                    Node *previous = traverse(i, j);
                    curr->prev = NULL;
                    previous->prev = curr;
                    curr->next = previous;

                    if (j != 1)
                    {
                        top = specificTraverse(i - 1, j);
                        curr->top = top;
                        top->bot = curr;
                    }
                }
            }
        cout << "LIST CREATED\n";
    }

    Node* telephoneDirectory::traverse(int i, int j)
    {

        Node *temp = listHeadPtr;

        if (listHeadPtr == NULL)
            return listHeadPtr;

        for (int x = 1; x <= i;) // fix cols for going down
            for (int y = 1; y <= j;)
            {
                // MAKE FUNCTION THAT CHECKS IF TEMP->NEXT IS EMPTY OR NOT
                if (y == cols)
                {
                    if (y % rows == 0) // HOW TO CHECK IT REACHED LAST NODE????
                        return temp;
                    x++;
                    temp = temp->bot;
                    y = 0;
                }
                else if (x % 2 == 1)
                {
                    y++;
                    if (temp->next == NULL)
                        return temp;
                    temp = temp->next;
                }
                else
                {
                    y++;
                    if (temp->prev == NULL)
                        return temp;
                    temp = temp->prev;
                }
            }
        return temp;
    }