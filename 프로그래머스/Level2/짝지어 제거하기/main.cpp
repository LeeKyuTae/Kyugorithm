#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s){
    stack<char> input;
    for(int i=0; i<s.size(); i++){
        if(input.size() != 0){
            char standard = input.top();
            char value = s[i];
            if(standard == value){
                input.pop();
            }else{
                input.push(value);
            }
        }else{
            input.push(s[i]);
        }
    }
    return (input.size() >0) ? 0 : 1;
}