#include "fileInput.h"
#include <array>
class charArr
{
private:
    vector<vector<char>> vecArr;
    TrieClass Words;
    int rows, cols, rowCount;

public:
    charArr(TrieClass &a, int R)
    {
        rows = R;
        cols = 20;
        Words = a;
    }

    void insertion(string Word)
    {
        static int staticJ = 0;
        vecArr.resize(staticJ + 1);
        int j = 0;
        for (j; j < Word.length(); j++)
            vecArr[staticJ].push_back(Word[j]);
        vecArr[staticJ][j + 1] = '\0';
        staticJ++;
        rowCount = staticJ;
    }
    void compareWord()
    {
        string temp = "";
        string temp2 = "";
        for (int i = 0; i < vecArr.size(); i++)
        {
            for (int j = 0; j < vecArr[i].size(); j++)
            {
                temp += vecArr[i][j];
                if (Words.search(temp))
                {
                    cout << temp << " ";
                    // temp2 = temp;
                    temp = "";
                }
                else if (j % 3 == 0)
                {
                    temp = "";
                }
            }
        }
    }
};

int main()
{
    TrieClass a;
    fileInput iFile(a);
    // charArr b(a, 10);
    // // b.insertion("dogxbxxxnoon");
    // // // b.insertion("zones");
    // // b.insertion("rhellotherex");
    // a.search("rhellotherex");
    // // b.compareWord();
    a.search2("dogxbxxxnoon");
}