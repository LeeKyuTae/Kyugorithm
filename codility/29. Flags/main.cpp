#include <cmath>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
   int answer = 0;
   vector<int> peak;
   int limit = A.size()-1;
   for(int i=1; i<limit; i++){
       if(A[i] > A[i-1] && A[i] > A[i+1]){
           peak.push_back(i);
       }
   }
   if(peak.size()<1){
       return 0;
   }
   int x = peak[peak.size()-1] - peak[0]+1;
   int maxFlags = (int)sqrt(x)+1;
   for(int i= maxFlags; i>0; i--){
       int count = 1;
       int standard = peak[0];
       for(int j=1; j<peak.size(); j++){
           if(standard+i <= peak[j]){
               count ++;
               standard = peak[j];
           }
       }
       if(count >= i){
           return i;
       }
   }
   return answer;
}