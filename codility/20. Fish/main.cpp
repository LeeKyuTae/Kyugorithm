// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
    int size = A.size();
    stack<int> fish;
    for(int i=0; i<size; i++){
        if(B[i] == 0){
            int downFish = A[i];
            while(!fish.empty()){
                int upFish = fish.top();
                if(upFish > downFish){
                    break;
                } else {
                    fish.pop();
                }
            }
            if(fish.empty()) {
                answer ++;
            }
        }else {
            fish.push(A[i]);
        }
    }
    return(answer + fish.size());
}