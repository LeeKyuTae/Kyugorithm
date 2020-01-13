#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    int arr[26] = {0,};
    vector<string> answer;
    for(int i=0; i<strings.size(); i++){
        int value = (int)strings[i].at(n) - (int)'a';
        arr[value] ++;
        strings[i] = strings[i].at(n) + strings[i];
    }
    sort(strings.begin(), strings.end());
    for(int i=0; i<strings.size(); i++){
        answer.push_back(strings[i].substr(1));
    }
    int string_index = 0;
    for(int i=0; i<26; i++){
        int value = arr[i];
        sort(strings.begin()+string_index, strings.begin()+string_index+value);
        string_index += value;
    }
    return answer;
}