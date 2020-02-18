#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for(int i=0; i<s.size(); i++){
        if(s[i] >='A' && s[i] <= 'Z')
            s[i] = tolower(s[i]);
    }
    bool changeUpper = true;
    for(int i=0; i<s.size(); i++){
        if(changeUpper == true){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = toupper(s[i]);
            }
            changeUpper = false;
            if(s[i] == ' ')
                changeUpper = true;
        }else if(s[i] == ' '){
            changeUpper = true;
        }
    }
    return s;
}