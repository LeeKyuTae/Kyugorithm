// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

const int INF = 987654321;

struct minimumTree

{

        //�迭�� ����

        int n;

        //�� ������ �ּ�ġ

        vector<long long> minTree;

        minimumTree(const vector<long long> &array)

        {

                 n = array.size();

                 minTree.resize(n * 4);

                 init(array, 0, n - 1, 1);

        }

        //node ��尡 array[left...right] �迭�� ǥ���� ��

        //node�� ��Ʈ�� �ϴ� ����Ʈ���� �ʱ�ȭ

        long long init(const vector<long long> &array, int left, int right, int node)

        {

                 if (left == right)

                         return minTree[node] = array[left];

 

                 int mid = (left + right) / 2;

                 long long leftSubTree = init(array, left, mid, node * 2);

                 long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);

 

                 return minTree[node] = min(leftSubTree, rightSubTree);

        }

        //node�� ǥ���ϴ� ���� array[nodeLeft..nodeRight]�� �־��� ��

        //�� ������ array[left..right]�� ������

        long long query(int left, int right, int node, int nodeLeft, int nodeRight)

        {

                 //�� ������ ��ġ�� ������ ���� ��

                 if (right < nodeLeft || nodeRight < left)

                         return INF; //INF �߿�

                 //node�� ǥ���ϴ� ������ array[left..right]�� ������ ���ԵǴ� ���

                 if (left <= nodeLeft && nodeRight <= right)

                         return minTree[node];

                 //���� ������ ������ Ǭ �� ��� �� ���� ���� ����

                 int mid = (nodeLeft + nodeRight) / 2;

                 return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));

        }

        //query()�� �ܺο��� ȣ���ϱ� ���� �������̽�

        long long query(int left, int right)

        {

                 return query(left, right, 1, 0, n - 1);

        }

        //array[index]=newValue�� �ٲ���� �� node�� ��Ʈ�� �ϴ�

        //���� Ʈ���� ����

        long long update(int index, int newValue, int node, int nodeLeft, int nodeRight)

        {

                 //index�� ��尡 ǥ���ϴ� ������ ������� ��쿣 �����Ѵ�

                 if (index < nodeLeft || nodeRight < index)

                         return minTree[node];

                 //Ʈ���� �������� ������ ���

                 if (nodeLeft == nodeRight)

                         return minTree[node] = newValue;

 

                 int mid = (nodeLeft + nodeRight) / 2;

                 return minTree[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));

        }

        //update()�� �ܺο��� ȣ���ϱ� ���� �������̽�

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