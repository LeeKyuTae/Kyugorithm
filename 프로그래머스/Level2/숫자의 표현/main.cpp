#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int origin = n;
    int result;
    while(n>0){
        result = 0;
        for(int i=n; i>0; i--){
            result += i;
            if(result == origin){
                answer ++;
                break;
            }else if(result > origin)
                break;
        }
        n --;
    }
    return answer;
}