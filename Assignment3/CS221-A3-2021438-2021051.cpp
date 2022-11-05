#include <iostream>
#include <iomanip>

using namespace std;

class binaryTree
{
private:
    struct treeNode
    {
        int value;
        int counter;
        treeNode *left;
        treeNode *right;
        treeNode()
        {
            counter = 0;
            left = NULL;
            right = NULL;
        }
    };

    treeNode *root;
    void displayInOrder(treeNode *nodePtr) // display from left node Right
    {
        if (nodePtr)
        {
            displayInOrder(nodePtr->left);
            cout << nodePtr->value << endl;
            displayInOrder(nodePtr->right);
        }
    }
    void displayOnlyDupe(treeNode *nodePtr)
    {
        if (nodePtr)
        {
            if (nodePtr->counter > 0)
                cout << "Dupe Value: " << nodePtr->value << endl;
            displayOnlyDupe(nodePtr->left);
            displayOnlyDupe(nodePtr->right);
        }
    }
    void displayPreOrder(treeNode *nodePtr)
    {
        if (nodePtr)
        {

            cout << nodePtr->value << endl;
            displayPreOrder(nodePtr->left);
            displayPreOrder(nodePtr->right);
        }
    }
    void displayPostOrder(treeNode *nodePtr)
    {
        if (nodePtr)
        {
            displayPostOrder(nodePtr->left);
            displayPostOrder(nodePtr->right);
            cout << nodePtr->value << endl;
        }
    }
    void removeNode(int num, treeNode *&nodePtr)
    {
        if (num < nodePtr->value)
            removeNode(num, nodePtr->left);
        else if (num > nodePtr->value)
            removeNode(num, nodePtr->right);
        else
            makeDeletion(nodePtr);
    }
    void makeDeletion(treeNode *&nodePtr)
    {
        if (nodePtr == NULL)
        {
            cout << "Empty Node\n";
            return;
        }
        treeNode *tempNode;
        if (nodePtr->counter > 0)
        {
            nodePtr->counter--;
            return;
        }
        if (nodePtr->right == NULL)
        {
            tempNode = nodePtr;
            nodePtr = nodePtr->left;
            delete tempNode;
        }
        else if (nodePtr->left == NULL)
        {
            tempNode = nodePtr;
            nodePtr = nodePtr->right;
            if (nodePtr->counter > 1)
                nodePtr->counter--;
            delete tempNode;
        }
        else
        {
            tempNode = nodePtr->right;
            while (tempNode->left)
                tempNode = tempNode->left;

            tempNode->left = nodePtr->left;
            tempNode = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNode;
        }
    }

public:
    binaryTree() { root = NULL; }
    
    void insertNode(int val)
    {
        treeNode *curr, *temp;

        curr = new treeNode;
        curr->value = val;

        if (root == NULL)
        {
            root = curr;
            return;
        }
        temp = root;

        while (temp != NULL)
        {
            if (val < temp->value)
            {
                if (temp->left)
                    temp = temp->left;
                else
                {
                    temp->left = curr;
                    break;
                }
            }
            else if (val > temp->value)
            {
                if (temp->right)
                    temp = temp->right;
                else
                {
                    temp->right = curr;
                    break;
                }
            }
            else
            {
                temp->counter++;
                system("CLS");
                cout << "dupe value\n";
                break;
            }
        }
    }
    void showDupeNodes() { displayOnlyDupe(root); }
    void showNodesInOrder() { displayInOrder(root); }
    void showNodesPreOrder() { displayPreOrder(root); }
    void showNodesPostOrder() { displayPostOrder(root); }
    bool searchBinaryTree(int val)
    {
        treeNode *trav = root;

        while (trav)
        {
            if (trav->value == val)
                return true;
            if (val < trav->value)
                trav = trav->left;
            else
                trav = trav->right;
        }
        return false;
    }

    void remove(int num)
    {
        if (searchBinaryTree(num))
        {
            removeNode(num, root);
            cout << "Node Deleted\n";
        }
        else
            cout << "Number does Not Exist\n";
    }
};

void menu()
{
    cout << "(1)Insert a Node\n";
    cout << "(2)Delete a Node\n";
    cout << "(3)Search for a Node\n";
    cout << "(4)Display Pre-Order Traversal\n";
    cout << "(5)Display In-Order Traversal\n";
    cout << "(6)Display Post-Order Traversal\n\n";
    cout << setw(50) << "Enter the menu you would like to enter or -1 to exit:";
}

int main()
{
    int input;
    menu();
    cin >> input;
    binaryTree a;
    do
    {
        int num;
        switch (input)
        {
        case 1:
            cout << "Enter a number you want to insert: ";
            cin >> num;
            a.insertNode(num);
            cout << "Node Inserted" << endl;
            break;

        case 2:

            cout << "Enter a number you want to delete: ";
            cin >> num;
            a.remove(num);
            cout << endl;
            break;
        case 3:

            cout << "Enter a number you want to search: ";
            cin >> num;
            if (a.searchBinaryTree(num))
                cout << "Value Exists";
            else
                cout << "Value does not Exist";
            cout << endl;
            break;
        case 4:
            system("CLS");
            a.showNodesPreOrder();
            cout << endl;
            system("pause");
            break;
        case 5:
            system("CLS");
            a.showNodesInOrder();
            cout << endl;
            system("pause");
            break;
        case 6:
            system("CLS");
            a.showNodesPostOrder();
            cout << endl;
            system("pause");
            break;
        case -1:
            break;
        default:
            cout << "Invalid Input\n";
            break;
        }
        menu();
        cin >> input;
    } while (input != -1);
}
