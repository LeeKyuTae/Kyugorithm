#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> smallQ;
    priority_queue<int> bigQ;
	for (int i = 0; i < people.size(); i++){
       (people[i] <= limit/2) ? smallQ.push(people[i]) : bigQ.push(people[i]);   
    }
	while (!smallQ.empty() || !bigQ.empty()) {
		int person = 0;
        if(bigQ.size() >0){
            person += bigQ.top();
            bigQ.pop();
        }
		while (person <= limit && smallQ.size() > 0) {
			int next = smallQ.top();
			person += next;
			if (person <= limit) {
				smallQ.pop();
			}
		}
		answer++;
	}
	return answer;
}