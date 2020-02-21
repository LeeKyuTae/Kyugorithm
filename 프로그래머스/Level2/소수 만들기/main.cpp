#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int max = 0;
    // arr[index] == false => primeNumber
    for(int i=0; i<nums.size(); i++)
        max += nums[i];
    vector<bool>arr(max+1);
    arr[0] = true;
    arr[1] = false;
    for(int i=2; i<=max; i++){
        if(arr[i] == false){
            for(int j=i*2; j<=max; j += i)
                arr[j] = true;
        }
    }
   
    vector<int> combination(nums.size()-3);
    for(int i=0; i<3; i++)
        combination.push_back(1);
    sort(combination.begin(), combination.end());
    
    do{
        int result = 0;
        int count = 0;
        for(int i=0; i<combination.size(); i++){
            if(combination[i] >= 1){
                 result += nums[i];
                 count ++;
            }
            if(count ==3)
                break;
        }
        if(arr[result] == false)
            answer ++;
    }while(next_permutation(combination.begin(), combination.end()));
    return answer;
}