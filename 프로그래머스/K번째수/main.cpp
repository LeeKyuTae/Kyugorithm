#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> input = commands[i];
        vector<int> allocatedArray;
        for(int j = input[0]; j <= input[1]; j++){
            allocatedArray.push_back(array[j-1]);
        }
        sort(allocatedArray.begin(), allocatedArray.end());
        answer.push_back(allocatedArray[input[2]-1]);
    }
    return answer;
}