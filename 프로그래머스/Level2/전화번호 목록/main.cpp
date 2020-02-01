#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    //내 첫번째 풀이
    /*
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
    */ 
    
    //두번째 방법
    /*
    sort(phone_book.begin(), phone_book.end());
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i]==phone_book[i+1].substr(0, phone_book[i].size())){
            answer = false;
            break;
        }
    }
    */
    
    priority_queue<string, vector<string>, greater<string>> q;
    for(int i=0; i<phone_book.size(); i++){
        q.push(phone_book[i]);
    }
    while(!q.empty()){
        string standard = q.top();
        q.pop();
        if(q.size()==0){
            break;
        }
        string value = q.top();
        q.pop();
        if(standard == value.substr(0, standard.size())){
            answer = false;
            break;
        }
    }
    return answer;
}