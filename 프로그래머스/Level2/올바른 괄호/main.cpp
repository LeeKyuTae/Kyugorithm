#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> input;
    for(int i=0; i<s.size(); i++){
        if(input.size() != 0){
            char value = input.top();
            if(value == '(' && s[i] == ')'){
                input.pop();
                continue;
            }
        }
        input.push(s[i]);
    }
    return (input.size() != 0) ? false : true;
}