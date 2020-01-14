#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    int size = heights.size();
    for(int i=0; i<size; i++){
        int output = 0;
        for(int j=i; j>=0; j--){
            if(heights[j] > heights[i]){
                output = j+1;
                break;
            }
        }
        answer.push_back(output);
    }
    return answer;
}