#include <string>
#include <vector>
#include <math.h>
using namespace std;
int getCount(int n){
    int count = 0;
    while(n>0){
        int value = n%2;
        if(value == 1)
            count ++;
        n /=2;
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    int value = getCount(n);
    while(1){
        n++;
        int output = getCount(n);
        if(value == output)
            break;
    }
   
    return n;
}