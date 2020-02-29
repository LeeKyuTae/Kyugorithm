// you can use includes, for example:
// #include <algorithm>
#include<algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    bool checkingFirstPositive = false;
    for(int i=0; i<A.size(); i++){
        if(A[i]<0){
            continue;
        }else if(checkingFirstPositive == false){
            if(A[i] ==1){
                checkingFirstPositive = true;
                break;
            }else if(A[i] >1){
                break;
            }
        }
    }
    if(checkingFirstPositive == false){
        return 1;
    }
    for(int i=0; i<A.size()-1; i++){
        if(A[i] <0){
            continue;
        }else{
            int standard = A[i];
            int nextValue = A[i+1];
            if(A[i+1] - A[i]>1){
                return A[i]+1;
            }
        }
    }
    return A.back()+1;
}