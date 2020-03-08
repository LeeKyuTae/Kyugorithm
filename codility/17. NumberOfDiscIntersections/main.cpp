// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int size = A.size();
    int answer = 0;
    answer -=size;
    vector<int> start(size);
    vector<int> end(size);
    for(int i=0; i<size; i++){
        int min = (((long)(i)-(long)(A[i]))<(long)0) ? 0 : i-A[i];
        int max = (((long)(i)+(long)(A[i]))>(long)(size-1))? size-1 : i+A[i];
        start[min]++;
        end[max]++;
    }
    int current = 0;
    for(int i=0; i<size; i++){
        current += start[i];
        if(end[i] >0){
            int value = 0;
            for(int j=0; j<end[i]; j++){
                value +=current;
                current --;
            }
            answer +=value;
        }
    }
    return (answer > 10000000)? -1 : answer;
}