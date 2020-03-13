#include <map>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int answer = -1;
    int standard =  A.size()/2;
    map<int, int> input;
    pair<map<int, int>::iterator, bool> pr;
    for(int i=0; i<A.size(); i++){
        pr = input.insert(make_pair(A[i], 1));
        if(pr.second == false){
            input[A[i]] ++;
        }
        
        if(input[A[i]] > standard){
                answer = i;
                break;
        }
    }
    
    return answer;
}