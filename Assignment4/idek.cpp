#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#define char_int(c) ((int)c - (int)'a')

#define int_to_char(c) ((char)c + (char)'a')

#define SIZE (26)

struct TrieNode
{
    TrieNode *Child[SIZE];

    bool leaf;
};

TrieNode *getNode()
{
    TrieNode *newNode = new TrieNode;
    newNode->leaf = false;
    for (int i = 0; i < SIZE; i++)
        newNode->Child[i] = NULL;
    return newNode;
}

void insert(TrieNode *root, char *Key)
{
    int n = strlen(Key);
    TrieNode *pChild = root;

    for (int i = 0; i < n; i++)
    {
        int index = char_int(Key[i]);

        if (pChild->Child[index] == NULL)
            pChild->Child[index] = getNode();

        pChild = pChild->Child[index];
    }

    pChild->leaf = true;
}

void ss(string word)
{
    
}

void searchWord(TrieNode *root, bool Hash[], string str)
{
    if (root->leaf == true)
        cout << str << endl;

    for (int K = 0; K < SIZE; K++)
    {
        if (Hash[K] == true && root->Child[K] != NULL)
        {
            char c = int_to_char(K);

            searchWord(root->Child[K], Hash, str + c);
        }
    }
}

void PrintAllWords(char Arr[], TrieNode *root, int n)
{
    bool Hash[SIZE];

    for (int i = 0; i < n; i++)
        Hash[char_int(Arr[i])] = true;

    TrieNode *pChild = root;

    string str = "";

    for (int i = 0; i < SIZE; i++)
    {
        if (Hash[i] == true && pChild->Child[i])
        {
            str = str + (char)int_to_char(i);
            searchWord(pChild->Child[i], Hash, str);
            str = "";
        }
    }
}

int main()
{
    char Dict[][20] = {"go", "bat", "me", "eat",
                       "goal", "boy", "game", "run"};

    TrieNode *root = getNode();

    int n = sizeof(Dict) / sizeof(Dict[0]);
    for (int i = 0; i < n; i++)
        insert(root, Dict[i]);

    char arr[] = {'e', 'o', 'b', 'a', 'm', 'g', 'l'};
    int N = sizeof(arr) / sizeof(arr[0]);

    PrintAllWords(arr, root, N);

    return 0;
}
