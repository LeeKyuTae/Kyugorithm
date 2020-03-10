// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<char> input;
    for(int i=0; i<S.size(); i++){
        if(input.size()==0){
            input.push(S[i]);
        } else {
            char value = input.top();
            if(value== '(' && S[i] == ')'){
                input.pop();
            }else if(value == '{' && S[i] == '}'){
                input.pop();
            }else if(value == '[' && S[i] == ']'){
                input.pop();
            }else{
                input.push(S[i]);
            }
        }
    }
    
    return (input.size() >0) ? 0 : 1;
}