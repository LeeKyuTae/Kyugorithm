#include <algorithm>
#include <map>

int solution(vector<int> &A) {
    int answer = 0;
    map<int, int> input;
    vector<int> leaderIndex;
    pair<map<int,int>::iterator, bool> pr;
    int leader =0;
    int AHalf = A.size()/2;
    for(int i=0; i<A.size(); i++){
        pr = input.insert(make_pair(A[i], 1));
        if(pr.second == false){
            input[A[i]] ++;
            if(input[A[i]] > AHalf){
                leader = A[i];
                break;
            }
        }
    }
    
    for(int i=0; i<A.size(); i++){
        if(A[i] == leader){
            leaderIndex.push_back(i);
        }
    }
    
    int total = leaderIndex.size();
    int leftLeaderCount = 0;
    for(int i=0; i< (total-1); i++){
        int until = leaderIndex[i+1];
        leftLeaderCount  ++;
        int rightLeaderCount = total - leftLeaderCount;
        for(int j = leaderIndex[i]; j < until; j++){
            int leftTotal = j+1;
            int rightTotal = A.size()- leftTotal;
            if(leftLeaderCount > leftTotal/2 && rightLeaderCount > rightTotal/2){
                answer ++;
            }
        }
    }
    return answer;
}