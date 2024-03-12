#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    int i=0,j=0;
    while(i<A.size()&&j<B.size()){
        if(A[i]>B[j]){
            i++;
        }
        else if(A[i]==B[j]){
            //이 경우 어차피 승점 못 얻으므로 나중에 남는애들 욱여넣어
            i++;
        }
        else{
            i++;j++;
            answer++;
        }
    }
    return answer;
}