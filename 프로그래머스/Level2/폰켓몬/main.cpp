#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int size = nums.size();
    set<int> input;
    for(int i=0; i<nums.size(); i++){
        input.insert(nums[i]);
    }
    int maxSize = size/2;
	return (input.size() >= maxSize) ? maxSize : input.size();
}