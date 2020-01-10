#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int student[32] = {0,};
    for(int i=0; i<lost.size(); i++)
        student[lost[i]] -= 1;
    for(int i=0; i<reserve.size(); i++)
        student[reserve[i]] += 1;
    for(int i=1; i<=n; i++){
        if(student[i] == -1){
            if(student[i-1] == 1){
                student[i] = 0;
                student[i-1] = 0;
            } else if(student[i+1] == 1){
                student[i] = 0;
                student[i+1] = 0;
            } else {
                answer -- ;
            }
        }
    }
    return answer;
}