int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = -1;
    int remain = X;
    vector<bool> cross(X+1);
    for(int i=0; i<A.size(); i++){
        if(cross[A[i]] == false){
            cross[A[i]] = true;
            remain --;
        }
        
        if(remain ==0){
            answer = i;
            break;
        }
    }
    return answer;
}