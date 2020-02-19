#include <string>
#include <vector>

using namespace std;
int leastCommonMultiple(int a, int b){
    int max = (a>= b) ? a : b ;
    int gcd = 1;
    for(int i=max ; i>=1; i--){
        if(a%i==0 && b%i==0){
            gcd = i;
            break;
        }
    }
    int output = gcd;
    for(int i= gcd; ; i = i + gcd){
        if(i%a==0 && i%b ==0){
            output = i;
            break;
        }
    }
    return output;
}

int solution(vector<int> arr) {
    int answer = 1;
    for(int i=0; i<arr.size(); i++){
        answer = leastCommonMultiple(answer, arr[i]);
    }
    return answer;
}