// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    for(int i= A.size()-1; i>=2; i--){
        int max = A[i], mid =A[i-1], min =A[i-2];
        if(mid >(max-min)){
            return 1;
        }
    }
    return 0;
}