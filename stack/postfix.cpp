#include<iostream>
#include<stack>

using namespace std;

void postfix(string str)
{
    stack<char> s;
    char q;
    for(char c:str)
    {
        if(c == '(')
            continue;
        else if(c == '+')
            s.push(c);
        else if(c == '-')
            s.push(c);
        else if(c == '*')
            s.push(c);
        else if(c == '/')
            s.push(c);
        else if(c == ')')
        {
            cout << s.top() << " ";
            s.pop();

        }

        else
            cout << c << " ";
    }
}


int main()
{
    string str = "((a+(b*c))+d)";
    postfix(str);


    return 0;
}
