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
            //result�� ���ڿ��� �������� �־ ����ϴ� ���
            /*
            if(sameValue == 1){
                result += current;
            }else {
                result += (to_string(sameValue) + current);
            }
            */
            
            //���� ������� �����ϴ� ���
            sameValue = (sameValue == 1) ? 0 : to_string(sameValue).size();
            output += i;
            output += sameValue;
            
            //���� �� ����� ���� �ʱ�ȭ ����
            current = compare1;
            sameValue = 1;
            }  
        }
        // ������ �ڸ����� ���ϴ� ����
        int rest = sizes % i;
        output += rest;
        
        //result�� ���ڿ��� �������� �־ ����ϴ� ���
        /*
        if(sizes / i != 0)
            result += s.substr((sizes/i)*i);
        answer = (result.size() + rest < answer) ? result.size() + rest : answer;
        */
        
        //���� ������� �����ϴ� ���
        answer = (output < answer) ? output : answer;
    }
    return answer;
}