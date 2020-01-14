#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(char a, char b){
    return (a <= b) ? false : true;
}

string solution(string s) {
    sort(s.begin(), s.end(), compare);
    string answer = s;
    return answer;
}