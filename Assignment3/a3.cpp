#include <iostream>

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

public:
    binaryTree()
    {
        root = NULL;
    }
    void insertNode(int val);
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

    void remove(int num) { removeNode(num, root); }
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
};

int main()
{
    binaryTree a;
    a.insertNode(7);
    a.insertNode(6);
    a.insertNode(4);
    a.insertNode(2);
    a.insertNode(2);
    cout << "\n";
    a.showNodesPostOrder();
    a.remove(2);
    cout << "\n";
    a.showNodesPostOrder();
    a.remove(2);
    cout << "\n";
    a.showNodesPostOrder();

    cout << "\n";
}

void binaryTree::insertNode(int val)
{
    treeNode *curr, *temp;

    curr = new treeNode;
    curr->value = val;

    if (root == NULL)
    {
        root = curr;
        cout << "Node Inserted\n";
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
                cout << "Node Inserted\n";

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
                cout << "Node Inserted\n";
                break;
            }
        }
        else
        {
            temp->counter++;
            cout << "dupe value\n";
            break;
        }
    }
}