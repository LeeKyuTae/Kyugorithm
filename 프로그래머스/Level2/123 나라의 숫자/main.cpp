#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n) {
    string answer = "";
    stack<int> input;
    while(n > 0){
        int value = n%3;
        if(value ==0){
            value = 4;
            n = n/3 -1;
        }else
            n = n/3;
        input.push(value);
    }
    while(!input.empty()){
        int value = input.top();
        input.pop();
        answer.append(to_string(value));
    }
    return answer;
}