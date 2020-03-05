int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    vector<int> prevOne;
    int countOne = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i] == 0){
            prevOne.push_back(countOne);
        }else{
            countOne ++;
        }
    }
    for(int i=0; i<prevOne.size(); i++){
        answer += (countOne-prevOne[i]);
        if(answer >1000000000){
            return -1;
        }
    }
    return answer;
}