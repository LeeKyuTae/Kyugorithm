// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
bool check[100002] = {false,};
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 1;
    int size = A.size();
    for(int i=0; i<size; i++){
        check[A[i]] = true;
    }
    for(int i=1; i<=size+1; i++){
        if(check[i] == false){
            answer = i;
            break;
        }
    }
    return answer;
}