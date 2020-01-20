#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string watermelon1 = "¼ö";
    string watermelon2 = "¹Ú";
    string answer = "";

    for(int i=0; i<n; i++){
        if(i%2 ==0)
            answer += watermelon1;
        else
            answer += watermelon2;
    }

    return answer;
}