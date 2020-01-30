#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool number[10000000] = { false, };
vector<string> input;
vector<string> numberList;
void findPrimeNumber() {
	for (int i = 2; i < 10000000; i++) {
		if (number[i] == false) {
			for (int j = 2; j*i < 10000000; j++)
				number[j*i] = true;
		}
	}
	return;
}

void makeNumber(int numberSize, string number, bool check[], int remainPick) {
	if (remainPick == 0) {
		if (number[0] == '0' && number.size() > 1)
			number = number.substr(1, number.size() - 1);
		numberList.push_back(number);
		return;
	}
	else {
		for (int i = 0; i < numberSize; i++) {
			if (check[i]) continue;
			else {
				check[i] = true;
				string value = number + input[i];
				makeNumber(numberSize, value, check, remainPick - 1);
				check[i] = false;
			}
		}
	}

}

int solution(string numbers) {
	int answer = 0;
	findPrimeNumber();
	number[0] = true;
	number[1] = true;
	int size = numbers.size();
	bool check[7] = { false, };
	for (int i = 0; i < size; i++) {
		string value = numbers.substr(i, 1);
		input.push_back(value);
	}
	for (int i = 1; i <= size; i++)
		makeNumber(size, "", check, i);


	for (int i = 0; i < numberList.size(); i++) {
		int value = stoi(numberList[i]);
		if (number[value] == false) {
			answer++;
			number[value] = true;
		}
	}
	return answer;
}