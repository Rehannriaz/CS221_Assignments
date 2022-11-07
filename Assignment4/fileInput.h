#include "trie.h"
class fileInput
{
private:
    ifstream iFile;

public:
    fileInput(TrieClass &a)
    {
        iFile.open("words.txt");
        if (!iFile.is_open())
        {
            cout << "error, file did not load successfully ";
            exit(1);
        }
        string data;

        while (getline(iFile, data))
        {
            if (data.size() > 2)
                a.insertion(data);
            
        }
    }
};