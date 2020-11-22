#include <QCoreApplication>
#include <iostream>
#include <stack>

using namespace std;

bool ValidParentheses(char *str)
{
    bool return_flag(false);

    stack<char> local_stack;

    char top_element;

    for(size_t i(0); i < strlen(str); i++)
    {
        if(local_stack.size() == 0)
            local_stack.push(str[i]);
        else
        {
            top_element = local_stack.top();

            if(top_element == '(')
            {
                if(str[i] == ')')
                    local_stack.pop();
                else
                    local_stack.push(str[i]);
            }
            else if(top_element == '{')
            {
                if(str[i] == '}')
                    local_stack.pop();
                else
                    local_stack.push(str[i]);
            }
            else if(top_element == '[')
            {
                if(str[i] == ']')
                    local_stack.pop();
                else
                    local_stack.push(str[i]);
            }
        }
    }

    if(local_stack.size() == 0)
        return_flag = true;
    else
        return_flag = false;

    return return_flag;
}

bool ValidParentheses2(char *str)
{
    bool return_flag(true);

    char last_element;

    for(size_t i(0); i < strlen(str) - 1; i++)
    {
        last_element = str[i];
        for(size_t j(i+1); j < strlen(str); j++)
        {
            if(last_element == '(')
            {
                if(str[j] == ')')
                {
                    str[j] = '$';
                    str[i] = '$';
                    break;
                }
            }
            else if(last_element == '{')
            {
                if(str[j] == '}')
                {
                    str[j] = '$';
                    str[i] = '$';
                    break;
                }
            }
            else if(last_element == '[')
            {
                if(str[j] == ']')
                {
                    str[j] = '$';
                    str[i] = '$';
                    break;
                }
            }
        }
    }

    for(size_t i(0); i < strlen(str); i++)
    {
        if(str[i] != '$')
        {
            return_flag = false;
            break;
        }

    }
    cout << endl;

    return return_flag;
}

bool ValidParentheses3(string str)
{
    if(str.length() == 0)
        return true;

    if(str.find("()") != str.npos)
    {
        size_t index = str.find("()");
        str.replace(index, 2, "");

        return ValidParentheses3(str);
    }
    else if(str.find("{}") != str.npos)
    {
        size_t index = str.find("{}");
        str.replace(index, 2, "");

        return ValidParentheses3(str);
    }
    else if(str.find("[]") != str.npos)
    {
        size_t index = str.find("[]");
        str.replace(index, 2, "");

        return ValidParentheses3(str);
    }
    else
        return false;
}

int main()
{
//    char str[] = {"({[({[})]{()}})"};

    char str[] = {")("};

    string str2 = {"({[({})]{()}})"};

    for(size_t i(0); i < strlen(str); i++)
        cout << str[i] << endl;

    if(ValidParentheses(str))
    {
        cout << "ValidParentheses2::The parentheses are valid" << endl;
    }
    else
    {
        cout << "ValidParentheses2::The parentheses are unbalanced" << endl;
    }

    if(ValidParentheses3(str2))
    {
        cout << "ValidParentheses3::The parentheses are valid" << endl;
    }
    else
    {
        cout << "ValidParentheses3::The parentheses are unbalanced" << endl;
    }
}
