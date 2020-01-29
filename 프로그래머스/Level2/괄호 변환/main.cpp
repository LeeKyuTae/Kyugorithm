#include <string>
#include <vector>
#include <stack>
using namespace std;
string answer = "";


bool isCorrect(string p){
    stack<char> input;
	for (int i = 0; i < p.size(); i++) {
		char value = p[i];
		if (input.size() == 0) {
			input.push(value);
			continue;
		}
		char front = input.top();
		if (front == '(' && value == ')') {
			input.pop();
		}
		else {
			input.push(value);
		}
	}
	if (input.size() > 0)
		return false;
	else
		return true;
}

string change(string input){
    string output = "";
    for(int i= 1; i<input.size()-1; i++){
        if(input[i]== '(')
            output += ")";
        else
            output +="(";
    }
    return output;
}

string replay(string w){
    if(w== "")
        return "";
    string u = "";
    string v = "";
    int left =0;
    int right = 0;
    for(int i=0; i<w.size(); i++){
        (w[i] == '(') ? left ++ : right ++;
        u += w[i];
        if(left == right){
            for(int j=i+1; j<w.size(); j++){
                v += w[j];
            }
            break;
        }
    }
    if(isCorrect(u)){
        return u + replay(v);
    }else{
        return "(" + replay(v) +")" + change(u);
    }
}

string solution(string p) {
    int pSize = p.size();
    if(isCorrect(p))
        return p;
    answer = replay(p);
    return answer;
}