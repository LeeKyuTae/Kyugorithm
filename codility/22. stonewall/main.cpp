// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    int answer = 0;
    stack<int> input;
    for(int i=0; i<H.size(); i++){
       int value = H[i];
       while(!input.empty()){
           int standard = input.top();
           if(standard == value){
               break;
           }else if(standard > value){
               input.pop();
           }else {
               answer ++;
               input.push(value);
               break;
           }
       }if(input.empty()){
           answer ++;
           input.push(value);
       }
            
    }
    return answer;
}