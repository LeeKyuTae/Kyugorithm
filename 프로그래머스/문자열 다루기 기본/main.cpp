#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int size = s.size();
    if(size ==6 || size == 4){
    for(int i=0; i<s.size(); i++){
        // ���� 0�� �ƽ�Ű �ڵ� : 48. A�� �ƽ�Ű �ڵ� : 65, a�� �ƽ�Ű �ڵ� : 97
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