#include <stack>

int solution(string &S) {
    stack<char> input;
    for(int i=0; i<S.size(); i++){
        if(input.empty()){
            input.push(S[i]);
        }else{
            if(input.top() == '(' && S[i] == ')'){
                input.pop();
            }else{
                input.push(S[i]);
            }
        }
        
    }
    return (input.size() >0) ? 0 : 1;
}