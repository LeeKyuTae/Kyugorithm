#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string week[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int totalDay = 0;
    for(int i=1; i<a; i ++){
        totalDay += month[i-1];
    }
    totalDay += b-1;
    
    string answer = week[totalDay%7];
    return answer;
}