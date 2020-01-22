#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> input;
    int stick = 0;
    for(int i=0; i<arrangement.size(); i++){
        if(arrangement[i] == '('){
            stick ++;
        }else if(arrangement[i] == ')'){
            if(arrangement[i-1] == '('){
                stick --;
                answer += stick;
            }else if(arrangement[i-1] == ')'){
                stick --;
                answer ++;
            }
        }
    }
    return answer;
}