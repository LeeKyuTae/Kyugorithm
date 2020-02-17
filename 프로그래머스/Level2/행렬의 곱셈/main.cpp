#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int m = arr1.size();
    int n = arr2[0].size();
    for(int i=0; i<m; i++){
        vector<int> output;
        for(int j=0; j<n; j++){
            int value = 0;
            for(int k=0; k<arr2.size(); k++){
                value += arr1[i][k] * arr2[k][j];
            }
            output.push_back(value);
        }
        answer.push_back(output);
    }
    return answer;
}