int solution(vector<int> &A) {
    vector<int> peak;
    int limit = A.size()-1;
    for(int i=1; i< limit; i++){
        if(A[i] > A[i-1] && A[i] > A[i+1]){
            peak.push_back(i);
        }
    }
    
    if(peak.size()<=1){
        return peak.size();
    }
    
    vector<int> divArr;
    int size = A.size();
    for(int i=1; i<size; i++){
        if(size%i == 0){
            divArr.push_back(i);
        }
    }
    
    for(int i=0; i<divArr.size(); i++){
        int result = 1;
        int value = divArr[i];
        for(int j= 0; j<peak.size()-1; j++){
            if(value*(j+1) >= peak[j] && value*(j+1) < peak[j+1]){
                result ++;
            } else {
                break;
            }
            if(value*result == size){
                return result;
            }
        }
    }
}