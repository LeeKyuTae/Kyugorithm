int solution(vector<int> & A) {
	int size = A.size();
	int answer = size - 2;
	double min = double(A[size - 2] + A[size - 1]) / 2;
	for (int i = 0; i < size - 2; i++) {
		double value2 = double(A[i] + A[i + 1]) / 2;
		double value3 = double(A[i] + A[i + 1] + A[i + 2]) / 3;
		double small = (value2 <= value3) ? value2 : value3;
		if (small == min) {
			if (i < answer) {
				answer = i;
			}
		}
		else if (small < min) {
			min = small;
			answer = i;
		}
	}
	return answer;
}