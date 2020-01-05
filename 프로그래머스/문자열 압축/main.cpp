#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int sizes = s.length();
    int maxLength = sizes/2 ;
    if(maxLength == 0) maxLength = 1;
    int answer = sizes;
    
    for(int i=1; i<=maxLength; i++){
        int sameValue = 1;
        int output = 0;
        string current = s.substr(0,i);
        string result = "";
        
       for(int j = i; j <= sizes; j +=i){
        string compare1 = s.substr(j, i);
        if(current == compare1){
            sameValue ++;
        }else{
            if(sameValue == 1){
                result += current;
            }else {
                result += (to_string(sameValue) + current);
            }
            /*
            output += i ; // add split string size
            sameValue = (sameValue == 1) ? 0 : (sameValue / 10) + 1;
            output +=  sameValue; // 크기를 문자열로 나타냈을 때의 길이
            */
            current = compare1;
            sameValue = 1;
        }  
        }
      //  output += sizes % i ;
        if(sizes / i != 0)
            result += s.substr((sizes/i)*i);
        if(answer > result.size()) answer = result.size();
    //   answer = (output < answer) ? output : answer;
    }
    return answer;
}