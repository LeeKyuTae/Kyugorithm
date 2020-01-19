#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_weight = 0;
    queue<int> trucks ;
    
    int size = truck_weights.size();
    
    for(int i=0; i<truck_weights.size(); i++){
        int truck = truck_weights[i];
        while(1){
            if(trucks.empty()){
                trucks.push(truck);
                current_weight += truck;
                answer ++;
                break;
            } else if(trucks.size() == bridge_length){
                current_weight -= trucks.front();
                trucks.pop();
            }else{
                if(current_weight + truck > weight){
                    trucks.push(0); answer ++;
                }else{
                    trucks.push(truck);
                    current_weight += truck;
                    answer ++;
                    break;
                }
            }
        }
    }
    answer += bridge_length;
    return answer;
}