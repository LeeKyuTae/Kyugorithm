int solution(int N) {
    int answer = 0;
    long i=1;
    for(i=1; i*i < N; i++){
        if(N%i ==0){
            answer +=2;
        }
    }
    if(i*i == N){
            answer ++;
    }
    return answer;
}