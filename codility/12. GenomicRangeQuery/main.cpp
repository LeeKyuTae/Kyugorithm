// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

const int INF = 987654321;

struct minimumTree

{

        //배열의 길이

        int n;

        //각 구간의 최소치

        vector<long long> minTree;

        minimumTree(const vector<long long> &array)

        {

                 n = array.size();

                 minTree.resize(n * 4);

                 init(array, 0, n - 1, 1);

        }

        //node 노드가 array[left...right] 배열을 표현할 때

        //node를 루트로 하는 서브트리를 초기화

        long long init(const vector<long long> &array, int left, int right, int node)

        {

                 if (left == right)

                         return minTree[node] = array[left];

 

                 int mid = (left + right) / 2;

                 long long leftSubTree = init(array, left, mid, node * 2);

                 long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);

 

                 return minTree[node] = min(leftSubTree, rightSubTree);

        }

        //node가 표현하는 범위 array[nodeLeft..nodeRight]가 주어질 때

        //이 범위와 array[left..right]의 교집합

        long long query(int left, int right, int node, int nodeLeft, int nodeRight)

        {

                 //두 구간이 겹치지 않으면 무시 됨

                 if (right < nodeLeft || nodeRight < left)

                         return INF; //INF 중요

                 //node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우

                 if (left <= nodeLeft && nodeRight <= right)

                         return minTree[node];

                 //양쪽 구간을 나눠서 푼 뒤 결과 중 작은 값을 저장

                 int mid = (nodeLeft + nodeRight) / 2;

                 return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));

        }

        //query()를 외부에서 호출하기 위한 인터페이스

        long long query(int left, int right)

        {

                 return query(left, right, 1, 0, n - 1);

        }

        //array[index]=newValue로 바뀌었을 떄 node를 루트로 하는

        //구간 트리를 갱신

        long long update(int index, int newValue, int node, int nodeLeft, int nodeRight)

        {

                 //index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다

                 if (index < nodeLeft || nodeRight < index)

                         return minTree[node];

                 //트리의 리프까지 내려온 경우

                 if (nodeLeft == nodeRight)

                         return minTree[node] = newValue;

 

                 int mid = (nodeLeft + nodeRight) / 2;

                 return minTree[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));

        }

        //update()를 외부에서 호출하기 위한 인터페이스

        long long update(int index, int newValue)

        {

                 return update(index, newValue, 1, 0, n - 1);

        }

};


vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<long long> original;
    for(int i=0; i<S.size(); i++){
        int value;
        if(S[i] == 'A'){
            value = 1;
        }else if(S[i] == 'C'){
            value = 2;
        }else if(S[i] == 'G'){
            value = 3;
        }else{
            value = 4;
        }
        original.push_back(value);
    }
    
    minimumTree m(original);
    vector<int> answer;
    for(int i=0; i<P.size(); i++){
        int firstIndex = P[i];
        int endIndex = Q[i];
        answer.push_back(m.query(firstIndex, endIndex));
    }
    return answer;
}