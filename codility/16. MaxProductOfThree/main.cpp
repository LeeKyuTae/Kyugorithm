// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int max = A[A.size()-1];
    int minusSize = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i] <=0){
            minusSize ++;
        }
    }
    int answer = A[A.size()-1]*A[A.size()-2]* A[A.size()-3];
    if(minusSize >=2){
        int value  = A[A.size()-1]*A[0]* A[1];
        answer = (answer >= value) ? answer : value;
    }
    
    return answer ;
}