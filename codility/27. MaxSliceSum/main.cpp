long solution(vector<int> &A) {
    long globalProfit =A[0];
    long localProfit = A[0];
    for(int i=1; i<A.size(); i++){
        localProfit = max(long(A[i]),long( A[i]+localProfit));
        globalProfit = max(globalProfit, localProfit);
    }
    
    return globalProfit;
}