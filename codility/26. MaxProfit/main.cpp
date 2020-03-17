int solution(vector<int> &A) {
    int globalProfit = 0;
    int localProfit = 0;
    for(int i=1; i<A.size(); i++){
        localProfit = max(A[i]-A[i-1], A[i]-A[i-1]+localProfit);
        globalProfit = max(globalProfit, localProfit);
    }
    
    return (globalProfit <0) ? 0 : globalProfit;
}