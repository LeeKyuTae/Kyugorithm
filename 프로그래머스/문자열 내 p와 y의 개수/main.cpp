#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;
    for(int i=0; i < s.size(); i++){
        char value = tolower(s.at(i));
        if(value == 'p')
            p ++;
        else if(value == 'y')
            y ++;
    }
    (p == y) ? answer = true : answer = false;
    return answer;
}