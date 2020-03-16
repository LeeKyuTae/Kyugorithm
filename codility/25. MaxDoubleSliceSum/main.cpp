// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    vector<int> leftSum(A.size());
    for(int i=1; i<A.size()-1; i++){
        leftSum[i] = max(leftSum[i-1]+ A[i], 0);
    }
     vector<int> rightSum(A.size());
     for(int i= leftSum.size()-2; i>=0; i--){
         rightSum[i] = max(rightSum[i+1]+ A[i], 0);
     }
     
      int answer = 0;
     for(int i=1; i<A.size()-1; i++){
         int value = leftSum[i-1] + rightSum[i+1];
         answer = (answer >= value) ? answer : value;
     }
    
    return answer;
}