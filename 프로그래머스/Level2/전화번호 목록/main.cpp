#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i=0; i<phone_book.size(); i++){
        string standard = phone_book[i];
        int standardSize = standard.size();
        for(int j=0; j<phone_book.size(); j++){
            string value = phone_book[j];
            if(j==i)
                continue;
            else if(value.size() < standardSize)
                continue;
            else if(standard == value.substr(0,standardSize)){
                answer = false;
                break;
            }
        }
        if(answer == false)
            break;
    }
    return answer;
}