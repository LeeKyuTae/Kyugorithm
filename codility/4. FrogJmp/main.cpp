int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = 0;
	int min = X;
	int max = Y;
	while (min < max) {
		int mid = (min + max) / 2;
		if (mid < max) {
			int value = (max - min) / D;
			answer += value;
			if (value == 0) {
				answer++;
				min += D * (value + 1);
			}
			else {
				min += value * D ;
			}
		}
	}
	return answer;
}