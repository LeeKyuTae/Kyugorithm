int solution(int N) {
    int answer = 2*(1+N);
    for(int i=2; i*i<= N; i++){
        if(N%i ==0){
            int value = 2*(i + (N/i));
            answer = (answer <= value) ? answer : value;
        }
    }
    return answer;
}