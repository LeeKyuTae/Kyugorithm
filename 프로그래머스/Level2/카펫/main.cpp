#include <string>
#include <vector>

using namespace std;
bool check(int brown, int red, int row, int column){
    int redColumn = column - 2;
    if(red%redColumn == 0){
        int redRow = red / redColumn;
        if(row-redRow >0){
            int expectBrown = (row*2) + redColumn * (row-redRow);
            if(expectBrown==brown)
                return true;
        }
    }
    return false;
}

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int carpet = brown + red;
	for (int i = carpet; i>=3 ; i--) {
		if ((carpet%i) == 0 && (carpet / i) >= 3) {
			if (check(brown, red, i, carpet / i) ) {
				answer.push_back(i);
				answer.push_back(carpet / i);
				break;
			}
		}
	}
	return answer;
}