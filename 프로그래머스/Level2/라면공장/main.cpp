#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int index = 0;
    priority_queue<int> q;
    for(int i=0; i<k; i++){
        if(dates[index] ==i){
            q.push(supplies[index]);
            if(index < dates.size()-1)
                index ++;
        }
        if(stock ==0){
            stock += q.top();
            q.pop();
            answer ++;
        }
        stock --;
    }
    return answer;
}