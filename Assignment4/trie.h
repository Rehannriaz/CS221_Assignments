#include "headers.h"

const int AlphaSize = 26;

class TrieClass
{
    struct Trie
    {
        bool endOfWord;
        Trie *children[AlphaSize];

        Trie()
        {
            endOfWord = false;

            for (int i = 0; i < AlphaSize; i++)
                children[i] = NULL;
        }
    };
    Trie *root;

public:
    TrieClass()
    {
        root = new Trie;
    }

    void insertion(string word)
    {
        Trie *trav = root;

        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (!trav->children[index])
                trav->children[index] = new Trie;

            trav = trav->children[index];
        }
        trav->endOfWord = true;
        // cout << word << " entered \n";
    }

    bool search(string key)
    {
        Trie *trav = root;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!trav->children[index])
                return false;

            trav = trav->children[index];
        }
        return trav->endOfWord;
    }
    void search2(string key)
    {
        bool check = true;
        Trie *trav = root;
        // Trie *travPrev = NULL;
        string temp = "";
        // static int j=0;
        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!trav->children[index])
            {
                check = false;
                // j++;
            }
            if (!trav->endOfWord)
            {
                temp="";
            }
            if (check)
            {

                temp += key[i];
                // travPrev = trav;
                trav = trav->children[index];
            }
            else
            {
                check = true;

                if (trav->endOfWord)
                    cout << temp << " ";
                temp = "";
                temp += key[i];
                // travPrev = trav;
                // what if the word after it also exists?
                trav = root;
                if (trav->children[index])
                    trav = trav->children[index];
            }
        }
        cout << temp << " ";
        // dogxbxxxnoon
        // return trav->endOfWord;
    }
};
