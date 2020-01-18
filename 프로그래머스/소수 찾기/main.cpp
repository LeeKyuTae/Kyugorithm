#include <string>
#include <vector>

using namespace std;
int arr[1000001] = {0,};

int solution(int n) {
    int answer = 0;
    for(int i=2; i<=n; i++){
        if(arr[i] == 0){
            answer ++;
            for(int j= 1; j*i <=n; j++){
                arr[j*i] = 1;
            }
        }
    }
    return answer;
}