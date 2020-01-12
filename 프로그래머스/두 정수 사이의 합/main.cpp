#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    /*
       if( b < a){
        int temp = a;
        a = b;
        b = temp;
    }
    */
    
   
 long long answer = ((long)a + (long)b) * ((long)abs(a - b) + 1) / 2;
    /*
    long long answer= 0;
    for(int i =a ; i<=b; i++)
        answer += i;
        */
    return answer;
}