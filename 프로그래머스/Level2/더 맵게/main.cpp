#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i< scoville.size(); i++)
        q.push(scoville[i]);
    while(answer < scoville.size()){
        int top = q.top();
        q.pop();
        if(top >=K)
            break;
        if(q.size() ==0){
            q.push(top);
            break;
        }
        int second = q.top();
        q.pop();
        int value = top + second*2;
        answer ++;
        q.push(value);
    }
    if(q.top() < K)
        return -1;
    /*
    int size = scoville.size();
    make_heap(scoville.begin(), scoville.end());
    while(answer < scoville.size()){
        if(scoville[scoville.size()-1] >= K)
            break;
        scoville[size-2-answer] = scoville[size-1- answer] + (scoville[size-2-answer] *2);
        answer ++;
        push_heap(scoville.begin(), scoville.end()-answer);
       // pop_heap(scoville.end(), scoville.end());
      //  size --;
    }
    if(scoville[scoville.size()-1] <K)
        return -1;
    */
    
    /*
    sort(scoville.begin(), scoville.end());
    while(answer < scoville.size()){
        if(scoville[answer] >= K)
            break;
        scoville[answer +1] = scoville[answer] + (scoville[answer + 1]*2);
        answer ++;
        if(answer == scoville.size())
            break;
        sort(scoville.begin()+answer,scoville.end());
    }
    if(scoville[scoville.size()-1] < K)
        return -1;
    */    
    return answer;
}