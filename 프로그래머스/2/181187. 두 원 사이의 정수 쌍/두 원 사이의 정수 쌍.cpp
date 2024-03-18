#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int x=1;x<r2;x++){
        int upperbound=floor(sqrt(pow(r2,2)-pow(x,2)));
        int lowerbound=r1<=x?1:ceil(sqrt(pow(r1,2)-pow(x,2)));
        answer+=(upperbound-lowerbound+1);
    }
    answer*=4;
    answer+=(r2-r1+1)*4;
    return answer;
}