// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int min = A[0];
    int remain = 0;
    for(int i=1 ; i<A.size(); i++){
        remain +=A[i];
    }
    int answer = abs(min-remain);
    for(int i=1; i<A.size()-1; i++){
        min += A[i];
        remain -=A[i];
        
        answer = (answer <= abs(min-remain) ) ? answer : abs(min-remain);
        
    }
    return answer;
    
}