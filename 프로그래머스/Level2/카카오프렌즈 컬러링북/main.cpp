#include <vector>
#include <queue>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool arr[100][100] = {0,};
    
    queue<pair<int,int>> input;
    for(int i=0; i<m; i++){
        
        for(int j=0; j<n; j++){
             int num = 0;
            
            int value = picture[i][j];
            if(value == 0 || arr[i][j] == true)
                continue;
            else{
                number_of_area ++;
                arr[i][j] = true;
                input.push(make_pair(i, j));
                num ++;
                while(!input.empty()){
                    int x = input.front().first;
                    int y = input.front().second;
                    input.pop();
                    for(int k=0; k<4; k++){
                        int currentX = x + dx[k];
                        int currentY = y + dy[k];
                        if(currentX < 0 || currentX >=m || currentY < 0 || currentY >=n)
                            continue;
                        else if(arr[currentX][currentY] == true)
                            continue;
                        else{
                            int currentValue = picture[currentX][currentY];
                            if(currentValue == value){
                                arr[currentX][currentY] = true;
                                num ++;
                                input.push(make_pair(currentX, currentY));
                            }
                        }
                    }
                }
                if(num > max_size_of_one_area)
                    max_size_of_one_area = num;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}