#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string solution(string s) {
    vector<int> input;
     string value = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            input.push_back(stoi(value));
            value = "";
        }
        value += s[i];
    }
    input.push_back(stoi(value));
    sort(input.begin(), input.end());
    return (to_string(input[0]) + " " + to_string(input[input.size()-1]));
    /*
    priority_queue<int, vector<int>, greater<int>> q;
    string value = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            q.push(stoi(value));
            value = "";
        }
        value += s[i];
    }
    q.push(stoi(value));
    string answer = "";
    answer += to_string(q.top())+ " " ;
    while(q.size() >1)
        q.pop();
    answer += to_string(q.top());
    return answer;
    */
}