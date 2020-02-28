vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> answer;
    int changedValue = 0;
    for(int i=0; i<N; i++){
        answer.push_back(0);
    }
    int max = 0;
    for(int i=0; i<A.size(); i++){
        int value = A[i];
        if(value <= N){
            if(answer[value-1] < changedValue){
                answer[value-1] = changedValue;
            }
            answer[value-1] ++;
            max = (max >= answer[value-1]) ? max : answer[value-1];
        }else if(value == N+1){
            changedValue = max;
        }
    }
    for(int i=0; i<answer.size(); i++){
        if(answer[i]<changedValue)
            answer[i] = changedValue;
    }
    return answer;
}