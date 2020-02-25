// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int standard = A[0];
    for(int i=1; i<A.size(); i++){
        standard = standard ^ A[i];
    }
    
    return standard;
}
