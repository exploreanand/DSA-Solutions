// Multiple Parenthesis Matching
#include <iostream>
using namespace std;

class stack
{
    public:
    int size;
    int top;
    char * arr;
    stack(int s)
    {
        size = s;
        top = -1;
        arr = new char[size];
    }
};

int push(stack * s,char a)
{
    if (s->top == s->size-1)
    {
        return 0;
    }
    s->top++;
    s->arr[s->top]=a;
    return 1;
}
char pop(stack * s)
{
    if (s->top == -1)
    {
        return 0;
    }
    char x = s->arr[s->top];
    s->top--;
    return x;
}

int parenthesis(string exp)
{
    int size = 100;
    stack * s = new stack(size);
    char a = '(', b = '{',c = '[';
    for (int i = 0; i < size; i++)
    {
        if (exp[i]==a)
        {
            push(s,a);
        }
        else if (exp[i]==b)
        {
            push(s,b);
        }
        else if (exp[i]==c)
        {
            push(s,c);
        }
        else if (exp[i]==')')
        {
            if (s->arr[s->top]=='(')
            {
                pop(s);
            }
            else
            {
                return 0;
            }
        }
        else if (exp[i]=='}')
        {
            if (s->arr[s->top]=='{')
            {
                pop(s);
            }
            else
            {
                return 0;
            }  
        }
        else if (exp[i]==']')
        {
            if (s->arr[s->top]=='[')
            {
                pop(s);
            }
            else
            {
                return 0;
            } 
        }   
    }
    if (s->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    string s;
    cin >> s;;
    if (parenthesis(s))
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    
    return 0;
}