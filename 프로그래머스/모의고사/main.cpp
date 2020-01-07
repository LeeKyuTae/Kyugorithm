#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    
    int arr1[5] = {1,2,3,4,5};
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int output[3] = {0,0,0};
    
    int sizes = answers.size();
    for(int i=0; i<sizes; i++){
        if(answers[i] == arr1[i%5])
            output[0] ++;
        if(answers[i] == arr2[i%8])
            output[1] ++;
        if(answers[i] == arr3[i%10])
            output[2] ++;
    }
    
    int max = output[0];
    for(int i=1; i<3; i++){
        if(output[i] > max)
            max = output[i];
    }
    
    for(int i=0; i<3; i++){
        if(output[i] == max)
            answer.push_back(i+1);
    }
    
    return answer;
}