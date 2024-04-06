#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(int e:arr)answer+=e;
    return answer/arr.size();
}