#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<string> q;
void input(bool check[], string output) {
	if (output.size() == 3) {
		q.push(output);
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (check[i] == true)
			continue;
		string value = output;
		value += to_string(i);
		check[i] = true;
		input(check, value);
		check[i] = false;
	}
}

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	bool check[10] = { false, };
	input(check, "");
	for (int i = 0; i < baseball.size(); i++) {
		string standard = to_string(baseball[i][0]);
		int strike;
		int ball;
		int qSize = q.size();
		for (int j = 0; j < qSize; j++) {
			strike = 0;
			ball = 0;
			string value = q.front();
			q.pop();
			if (value == standard) {
				if (baseball[i][1] == 3)
					return 1;
				else
					continue;
			}
			for (int k = 0; k < 3; k++) {
				int number = standard.find(value[k]);
				if (number >= 0 && number < 3) {
					ball++;
				}
				if (standard[k] == value[k]) {
					strike++;
					ball--;
				}
			}
			if (strike == baseball[i][1] && ball == baseball[i][2]) {
				q.push(value);
			}
		}
	}
	answer = q.size();
	return answer;
}