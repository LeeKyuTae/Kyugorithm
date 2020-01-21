#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int same = 0;
	int value = priorities[location];
	queue<int> input;
	for (int i = 0; i < priorities.size(); i++) {
		input.push(priorities[i]);
	}
	location++;
	while (1) {
		queue<int> subQ;
		int standard = input.front();
		input.pop();
		subQ.push(standard);
		bool check = false;
		int inputSize = input.size();
		for (int i = 0; i < inputSize; i++) {
			int value = input.front();
			if (value > standard) {
				check = true;
				break;
			}
			else {
				input.pop();
				subQ.push(value);
			}
		}
		if (check == false) {
			answer++;
			subQ.pop();
			if (location == 1) {
				break;
			}
			else
				location--;
			inputSize--;
			int size = subQ.size();
			for (int i = 0; i < size; i++) {
				int value = subQ.front();
				input.push(value);
				subQ.pop();
			}
		}
		else {
			int size = subQ.size();
			for (int i = 0; i < size; i++) {
				int value = subQ.front();
				if (location == 1) {
					location = inputSize + 1;
				}
				else {
					location--;
				}
				input.push(value);
				subQ.pop();
			}
		}
	}

	return answer;
}