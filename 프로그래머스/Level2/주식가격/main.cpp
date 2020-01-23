#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size(); i++){
        int output = 0;
        int standard = prices[i];
        for(int j=i+1; j<prices.size(); j++){
            if(prices[j] >= standard)
                output ++;
            else{
                output ++;
                break;
            }
        }
        answer.push_back(output);
    }
    return answer;
}