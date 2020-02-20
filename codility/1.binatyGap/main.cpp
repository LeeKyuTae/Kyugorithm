int solution(int N) {
	// write your code in C++14 (g++ 6.2.0)
	int answer = 0;
	int current = 0;
	while (N > 0) {
		int value = N % 2;
		if (value == 1) {
			N /= 2;
			value = N % 2;
			while (value == 0 && N >0) {
				current++;
				N /= 2;
				value = N % 2;
			}
			answer = (answer >= current) ? answer : current;
			current = 0;
			continue;
		}
		N = N / 2;
	}
	return answer;
}