#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<string> q;
void lineClear(string input, bool check[], int remain, char members[]){
    if(remain ==0){
        q.push(input);
        return;
    }
    for(int i=0; i<8; i++){
        if(check[i] == true)
            continue;
        string value = input;
        int user = remain-1;
        value += members[i];
        check[i] = true;
        lineClear(value, check, user, members);
        check[i] = false;
    }
    
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    queue<string> qwe;
    swap(q, qwe);
    
    int answer = 0;
    char members[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    bool check[8] = {false,};
    lineClear("", check, 8, members );
    int size = q.size();
    for(int k=0; k<size; k++){
        string output = q.front();
        q.pop();
        bool checking = true;
        for(int i=0; i<n; i++){
            char standard = data[i].at(0);
            char another = data[i].at(2);
            int standIndex = output.find(standard)+1;
            int anotherIndex = output.find(another)+1;
    
            int result = abs(standIndex - anotherIndex) -1;
            int gap = data[i].at(4) - '0';
            if(data[i].at(3) == '='){
                if(result != gap){
                    checking = false;
                    break;
                }
            }else if(data[i].at(3) == '<'){
                if(result >= gap){
                    checking = false;
                    break;
                }
                
            }else if(data[i].at(3) == '>'){
                if(result <= gap){
                    checking = false;
                    break;
                }
            }  
        }
        if(checking == true)
            answer ++;
    }
    return answer;
}