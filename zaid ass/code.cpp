#include <iostream>
using namespace std;

class list
{
private:
    struct node
    {
        long phNo;
        string name;
        string address;
        string email;
        node *left = NULL;
        node *right = NULL;
        node *up = NULL;
        node *down = NULL;
    };
    node *headptr, *temphead, *tail;
    int rows, columns;
    static int num_nodes, current_row;

public:
    list(int r, int c)
    {
        headptr = NULL;
        rows = r;
        columns = c;
    }

    void creation()
    {
        // node *row_head = headptr;
        // for(int i = 0; i<rows; i++){
        //     node *temp = new node;
        //     row_head->down = temp;
        //     temp->up = row_head;
        //     row_head = temp;
        // }
    }
    void get_details(node *newnode)
    {
        cout << "\nEnter the phone number: ";

        cin >> newnode->phNo;

        // cout<<"\nEnter the name: ";
        // cin>>newnode->name;
        // cout<<"\nEnter the address: ";
        // cin>>newnode->address;
        // cout<<"\nEnter the email: ";
        // cin>>newnode->email;
    }
    bool empty()
    {
        return (num_nodes == rows * columns);
    }
    void insert()
    {
        if (list::empty())
        {
            cout << "\nlist is full already. Can't add more items to the list\n";
            return;
        }
        else if (headptr == NULL)
        {
            node *temp = new node;
            get_details(temp);
            headptr = temp;
            temphead = headptr;
            num_nodes++;
            cout << "Node ADDED\n";

            return;
        }
        else
        {
            node *temp = new node();
            node *traverse = temphead;
            while (traverse->right != NULL && num_nodes % columns != 0)
            {
                traverse = traverse->right;
            }
            get_details(temp);
            if(current_row==1)
            {
            traverse->right = temp;
            temp->left = traverse;
            }
            num_nodes++;
            if (current_row > 1)
            {
                if (num_nodes % columns != 1)
                {
                    traverse->right = temp;
                    temp->left = traverse;
                    node *vertical_connect = temp->left->up->right;
                    temp->up = vertical_connect;
                    vertical_connect->down = temp;
                }
                else
                {
                    temphead->down = temp;
                    temp->up = temphead;
                }
            }
            
            if (num_nodes % columns == 0)
            {
                node *newtemphead = new node;
                newtemphead->up = temphead;
                temphead->down = newtemphead;
                temphead = newtemphead;
                current_row++;
            }
        }
        cout << "Node ADDED\n";
    }

    void display()
    { // printing 0 after printing the row 1???
        cout << "\nDisplaying...\n";

        node *traverse = headptr;
        while (traverse != NULL)
        {
            cout << "data: " << traverse->phNo << endl;
            cout << "up ptr: " << traverse->up << endl;
            cout << "down ptr: " << traverse->down << endl;
            cout << "left ptr" << traverse->left << endl;
            cout << "right ptr" << traverse->right << endl;
            // cout<<num_nodes<<endl;
            // cout<<current_row<<endl;
            traverse = traverse->right;
        }
    }
};
int list::num_nodes = 0;
int list::current_row = 1;

int main()
{
    list l(3, 3);
    l.insert();
    l.insert();
    l.insert();
    l.insert();
    l.insert();
    l.insert();
    l.insert();
    l.insert();
    l.insert();

    // l.display();
    return 0;
}