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
};
