// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size()==0){
        return A;
    }
    K = K%A.size();
    vector<int> answer;
    stack<int> input;
    for(int i=0; i<K; i++){
        input.push(A[A.size()-1-i]);
    }
    while(!input.empty()){
        answer.push_back(input.top());
        input.pop();
    }
    for(int i=0; i<A.size()-K; i++){
        answer.push_back(A[i]);
    }
    return answer;
}