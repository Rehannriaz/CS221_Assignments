#include <iostream>
#include <string>
#include <math.h>

using namespace std;

template <class T>
class stack
{
protected:
    T *arr;
    int size;
    int top;

public:
    stack()
    {
        top = -1;
        size = 1;
        arr = new T[size];
        clear(arr, size);
    }

    void clear(T *arr, int size)
    {
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }
    void pushBack(T op)
    {
        T *arr2 = new T[++size];
        clear(arr2, size);
        for (int i = 0; i < size - 1; i++)
            arr2[i] = arr[i];

        delete[] arr;
        arr2[++top] = op;
        arr = arr2;
    }
    bool isEmpty() { return (top == -1) ? true : false; }
    T topValue() { return arr[top]; }
    T popBack()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return '-';
        }
        else
        {
            size--;
            T returnData;
            returnData = arr[top--];
            return returnData;
        }
    }
};

class Post : public stack<char>, public stack<float>
{
private:
    stack<char> a;
    string exp;
    float answer = 0;
    string result;

public:
    Post() : stack<char>(), stack<float>()
    {
        cout << "Enter an expression\n";
        getline(cin,exp);
        result = "";
    }

    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    void print()
    {
        for (int i = 0; i < result.length(); i++)
            if (result[i] != ' ')
                cout << result[i];
        cout << endl;
    }
    void postFixCalc()
    {
        if (result == "")
        {
            cout << "No expression Entered\n";
            return;
        }
        for (int i = 0; i < result.length(); i++)
        {
            if ((result[i] >= 65 && result[i] <= 90) || (result[i] >= 97 && result[i] <= 122))
            {
                cout << "Characters found, algebric expression\n";
                return;
            }
        }

        stack<float> num;
        for (int i = 0; i < result.length(); i++)
        {
            if ((result[i] >= 48 && result[i] <= 57))
            {
                int j = i;
                string temp = "";
                while (result[j] != ' ')
                {
                    temp += result[j];
                    j++;
                }

                num.pushBack(float(stoi(temp)));
                i = j;
            }
            else
            {
                float A, B;
                switch (result[i])
                {
                case '^':
                    B = num.popBack();
                    A = num.popBack();
                    num.pushBack(power(A, B));
                    break;
                case '*':
                    B = num.popBack();
                    A = num.popBack();
                    num.pushBack(multiplication(A, B));
                    break;
                case '/':
                    B = num.popBack();
                    A = num.popBack();
                    num.pushBack(division(A, B));
                    break;
                case '+':
                    B = num.popBack();
                    A = num.popBack();
                    num.pushBack(addition(A, B));
                    break;
                case '-':
                    B = num.popBack();
                    A = num.popBack();
                    num.pushBack(subtraction(A, B));
                    break;
                case ' ':
                    break;
                default:
                    cout << "invalid character\n";
                    break;
                }
            }
        }
        answer = num.topValue();
        cout << "Answer = " << answer << endl;
    }
    float addition(float A, float B)
    {
        return A + B;
    }
    float subtraction(float A, float B)
    {
        return A - B;
    }
    float multiplication(float A, float B)
    {
        return A * B;
    }
    float division(float A, float B)
    {
        return A / B;
    }
    float power(float A, float B)
    {
        return pow(A, B);
    }

    void postFix()
    {
        string temp = "";
        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] != ' ')
                temp += exp[i];
            else
                continue;
        }
        exp = temp;
        for (int i = 0; i < exp.length(); i++)
        {
            if ((exp[i] >= 65 && exp[i] <= 90) || (exp[i] >= 97 && exp[i] <= 122) || (exp[i] >= 48 && exp[i] <= 57))
            {
                int j = i;
                while (precedence(exp[j]) == -1 && exp[j] != ')' && exp[j]!='\0')
                {
                    result += exp[j];
                    j++;
                }
                result += " ";
                i = j - 1;
            }
            else if (exp[i] == '(')
                a.pushBack(exp[i]);

            else if (exp[i] == ')')
            {
                while (a.topValue() != '(')
                {
                    result += a.popBack();
                    result += " ";
                }
                a.popBack();
            }
            else
            {
                if (a.isEmpty() && precedence(exp[i]) != -1)
                    a.pushBack(exp[i]);
                else
                {
                    if (precedence(exp[i]) <= precedence(a.topValue()))
                    {
                        while (precedence(exp[i]) <= precedence(a.topValue()) && !a.isEmpty())
                        {
                            result += a.popBack();
                            result += " ";
                        }

                        a.pushBack(exp[i]);
                    }
                    else
                        a.pushBack(exp[i]);
                }
            }
        }
        while (!a.isEmpty())
        {
            result += a.popBack();
            result += " ";
        }
    }
};

int main()
{
    Post a;
    a.postFix();
    a.print();
    a.postFixCalc();
}