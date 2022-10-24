/**
 * @file CS221-A2-2021438-2021051.cpp
 * @author Muhammad Rehan, Adeen Amir
 * @brief
 * @version 0.1
 * @date 2022-10-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

/**
 * @brief template class of Stack
 *
 */
template <class T>
class stack
{
protected:
    T *arr;
    int size;
    int top;

public:
    /**
     * @brief Construct a new stack object
     *
     */
    stack()
    {
        top = -1;
        size = 1;
        arr = new T[size];
        clear(arr, size);
    }
    /**
     * @brief sets all the values to 0 in a stack
     *
     * @param arr
     * @param size
     */
    void clear(T *arr, int size)
    {
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }
    /**
     * @brief pushesback a T datatype into the stack
     *
     * @param op
     */
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
    /**
     * @brief true if stack is empty, false if it is not empty
     *
     * @return true
     * @return false
     */
    bool isEmpty() { return (top == -1) ? true : false; }
    /**
     * @brief returns top value in the stack without popping it
     *
     * @return arr[top]
     */
    T topValue() { return arr[top]; }
    /**
     * @brief pops the very last data pushed into the stack
     *
     * @return T
     */
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

/*
 * @brief class for PostFix
 *
 */
class Post : public stack<char>, public stack<float>
{
private:
    stack<char> a;
    string exp;
    float answer = 0;
    string result;

public:
    /**
     * @brief Construct a new Post object
     *
     */
    Post() : stack<char>(), stack<float>()
    {
        answer = 0;
        exp = "";
        result = "";
    }
    /**
     * @brief Set the expression in the class
     *
     * @param expression
     */
    void setExp(string expression)
    {
        exp = "";
        this->exp = expression;
    }
    void clear()
    {
        answer = 0;
        exp = "";
        result = "";
    }

    /**
     * @brief precedence for each operator
     *
     * @param c
     * @return int
     */
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
    /**
     * @brief prints the result ignoring spaces
     *
     */
    void print()
    {
        for (int i = 0; i < result.length(); i++)
            if (result[i] != ' ')
                cout << result[i];
        cout << endl;
    }
    /**
     * @brief Calculates the postfix expression giving an answer if its not an algebric expression
     *
     */

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
    /**
     * @brief addition of two numbers
     *
     * @param A
     * @param B
     * @return float
     */
    float addition(float A, float B) { return A + B; }
    /**
     * @brief subtraction of two numbers
     *
     * @param A
     * @param B
     * @return float
     */
    float subtraction(float A, float B) { return A - B; }
    /**
     * @brief multiplication of two numbers
     *
     * @param A
     * @param B
     * @return float
     */
    float multiplication(float A, float B) { return A * B; }
    /**
     * @brief division of two numbers
     *
     * @param A
     * @param B
     * @return float
     */
    float division(float A, float B) { return A / B; }
    /**
     * @brief power of two numbers
     *
     * @param A
     * @param B
     * @return float
     */
    float power(float A, float B) { return pow(A, B); }

    /**
     * @brief converts the expression into postFix
     *
     */
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
                while (precedence(exp[j]) == -1 && exp[j] != ')' && exp[j] != '\0')
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

/**
 * @brief menu
 *
 */
void menu()
{
    cout << "(1)Input An Expression\n";
    cout << "(2)Convert Expression to PostFix and print result\n";
    cout << "(3)Calculate input Equation\n\n";
    cout << setw(50) << "Enter the menu you would like to enter or -1 to exit:";
}

int main()
{
    int input;
    menu();
    cin >> input;
    Post a;
    do
    {
        string exp = "";
        switch (input)
        {
        case 1:
            system("CLS");
            a.clear();
            cout << "Enter an expression\n";
            cin.ignore();
            getline(cin, exp);
            a.setExp(exp);
            cout << "Expression Noted" << endl;
            break;

        case 2:
            system("CLS");
            a.postFix();
            a.print();
            cout << endl;
            break;
        case 3:
            system("CLS");
            a.postFixCalc();
            cout << endl;
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