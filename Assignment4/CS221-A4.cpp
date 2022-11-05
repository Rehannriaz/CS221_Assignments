#include "fileInput.h"
#include <array>
class charArr
{
private:
    char **arr;
    vector<vector<char>> vecArr;
    TrieClass Words;
    int rows, cols, rowCount;

public:
    charArr(TrieClass &a, int R)
    {
        rows = R;

        cols = 20;
        Words = a;
        arr = new char *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new char[cols];
        }
    }
    // void insertion(string Word)
    // {
    //     static int J = 0;
    //     int j;
    //     for (int j = 0; j < Word.length(); j++)
    //         arr[J][j] = Word[j];
    //     arr[J][j + 1] = '\0';
    //     J++;
    //     rowCount = J;
    //     for (int i = 0; i < rowCount; i++)
    //     {

    //         for (int a = 0; a < cols; a++)
    //             cout << arr[i][a] << " ";
    //         cout << "\n";
    //     }
    //     cout << "\n\n\n\n";
    // }
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
        for (int i = 0; i < vecArr.size(); i++)
        {

            for (int a = 0; a < vecArr[i].size(); a++)
                cout << vecArr[i][a];
            cout << "\n";
        }
    }
    void compareWord()
    {
        string temp = "";
        string temp2 = "";
        for (int i = 0; i < vecArr.size(); i++)
        {
            for (int j = 0; i < vecArr[i].size(); j++)
            {
                temp += arr[i][j];
                if (Words.search(temp))
                {
                    cout << temp << " ";
                    temp2 = temp;
                    temp = "";
                }
                if (Words.search(temp2))
                {
                    cout << temp2 << " ";
                    temp = temp2;
                    temp2 = "";
                }
            }
        }
    }
};

int main()
{
    TrieClass a;
    fileInput iFile(a);
    charArr b(a, 10);
    b.insertion("hello");
    b.insertion("zones");
    b.insertion("hello4");
    b.compareWord();
}