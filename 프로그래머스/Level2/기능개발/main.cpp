#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> release_day;
    vector<int> answer;
    for(int i=0; i<progresses.size(); i++){
        int rest = 100 - progresses[i];
        int a = rest / speeds[i] ;
        int b = rest % speeds[i] ;
        (b == 0) ? release_day.push(a) : release_day.push(a+1);
    }
    
    int count = 0;
    while(!release_day.empty()){
        int standard = release_day.front();
        int size = release_day.size();
    
        for(int i=0; i<size; i++){
            int value = release_day.front();
            if(value <= standard){
                count ++;
                release_day.pop();
            } else {
                break;
            }  
        }
        if( count != 0){
            answer.push_back(count);
            count = 0;
        }
    }
    return answer;
}