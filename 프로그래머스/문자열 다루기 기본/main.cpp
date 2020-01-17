#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int size = s.size();
    if(size ==6 || size == 4){
    for(int i=0; i<s.size(); i++){
        // 숫지 0의 아스키 코드 : 48. A의 아스키 코드 : 65, a의 아스키 코드 : 97
        if((int)s[i] < 48 || (int)s[i] > 58){
            answer = false;
            break;
        }
    }
    }
    else
        answer = false;
    
    
    return answer;
}