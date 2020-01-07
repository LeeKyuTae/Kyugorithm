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
            //result란 문자열에 최종값을 넣어서 계산하는 방법
            /*
            if(sameValue == 1){
                result += current;
            }else {
                result += (to_string(sameValue) + current);
            }
            */
            
            //최종 결과값만 산출하는 방법
            sameValue = (sameValue == 1) ? 0 : to_string(sameValue).size();
            output += i;
            output += sameValue;
            
            //다음 값 계산을 위한 초기화 과정
            current = compare1;
            sameValue = 1;
            }  
        }
        // 나머지 자릿값을 더하는 과정
        int rest = sizes % i;
        output += rest;
        
        //result란 문자열에 최종값을 넣어서 계산하는 방법
        /*
        if(sizes / i != 0)
            result += s.substr((sizes/i)*i);
        answer = (result.size() + rest < answer) ? result.size() + rest : answer;
        */
        
        //최종 결과값만 산출하는 방법
        answer = (output < answer) ? output : answer;
    }
    return answer;
}