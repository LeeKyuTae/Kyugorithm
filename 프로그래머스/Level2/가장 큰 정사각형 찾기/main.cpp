#include <iostream>
#include<vector>
#include <queue>
using namespace std;
int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(int i=1; i<board.size(); i++){
        for(int j=1; j<board[i].size(); j++){
            if(board[i][j]==1){
                board[i][j] = min(board[i-1][j-1], min(board[i][j-1],board[i-1][j]))+1;
            }
        }
    }
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++)
            answer = (answer >= board[i][j]) ? answer : board[i][j];
    }
    return answer*answer;
}