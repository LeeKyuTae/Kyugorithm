#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int compare(string a, string b){
    if(a[0] == b[0]){
       string tempA = a + b;
       string tempB = b + a;
       return tempA <= tempB ? false : true;
    }
    return a < b ? false : true;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> input;
    for(int i=0; i<numbers.size(); i++)
        input.push_back(to_string(numbers[i]));
    sort(input.begin(), input.end(), compare);
    
    int count_0 = 0;
    for(int i=0; i<input.size(); i++){
        answer +=input[i];
        if(input[i] == "0")
            count_0 ++;
    }
    if(count_0 == input.size())
        answer = "0";
    return answer;
}