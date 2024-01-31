#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    for(int j=1;j<=elements.size();j++){//연속 부분 수열 길이
        int temp=0;
        for(int i=0;i<j;i++)temp+=elements[i];
        s.insert(temp);
        for(int i=1;i<=elements.size()-1;i++){//i째부터 시작하는 애들
            temp+=elements[(i+j-1)%elements.size()];
            temp-=elements[i-1];
            s.insert(temp);
        }
    }
    return s.size();
}