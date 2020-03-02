// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    int start = (A%K==0)? A/K : (A/K)+1;
    int end = B/K;
    return end-start+1;
}