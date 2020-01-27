#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int nameSize = name.size();
    int straight = nameSize - 1;
    int turn = 0;
    int turnIndex = 0;
    int arr[20] = {0,};
    for(int i=0; i<nameSize; i++){
        char value = name[i];
        answer = (abs(value - 'A') <= abs('Z'- value)) ? answer + abs(value - 'A') : answer + abs('Z'- value) +1;
        arr[i] = abs(value-'A');
        if(i!=0 && turnIndex ==0 && value=='A'){
            turnIndex = i;
        }
    }
    turn += (turnIndex-1)*2+1;
    int arrValue = 0;
    for(int i=nameSize-1; i>turnIndex; i--){
        arrValue += arr[i];
    }
    for(int i= nameSize-1; i>turnIndex; i--){
        if(arrValue - arr[i] >0){
            turn ++;
        }
        arrValue -= arr[i];
    }
    if(turnIndex ==0)
        answer += straight;
    else
        answer += (straight <= turn) ? straight : turn;
		
    return answer;
}