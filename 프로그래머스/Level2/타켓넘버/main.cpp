#include <string>
#include <vector>

using namespace std;
int answer, output ;
void search(int input, vector<int> numbers, int current){
    if(current == numbers.size()){
        if(input == output)
            answer ++;
        return;
    }
    search(input+numbers[current],numbers, current+1);
    search(input-numbers[current],numbers, current+1);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    output = target;
    search(0, numbers, 0);
    return answer;
}