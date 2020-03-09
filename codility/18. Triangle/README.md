problem link
=========
<https://app.codility.com/programmers/lessons/6-sorting/triangle/>

result link
=======
java : <https://app.codility.com/demo/results/trainingN625GF-SBS/> 
c++(wrong) : <https://app.codility.com/demo/results/trainingPSWZT8-9AU/>
c++ : <https://app.codility.com/demo/results/trainingQ46RSF-2VJ/>

issue about this problem
������ �ڵ带 java�� c++�� ���� �� c++������ ����� 100%�� ������ ����.

java 100%
=======
~~~java
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        Arrays.sort(A);
        for(int i=0; i<A.length-2; i++){
            if(A[i+1]>(A[i+2]-A[i])){
                return 1;
            }
        }
        return 0;
    }
}
~~~

c++ 87%
========
�迭�� ũ�Ⱑ 3���� ���� �� ������ �߻�
~~~c++
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    for(int i=0; i<A.size()-2; i++){
        if(A[i+1] > (A[i+2]-A[i])){
            return 1;
        }
        
    }
    return 0;
}
~~~
