#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s/n==0){
        answer.push_back(-1);
    }
    else{
        int a=s/n;//3
        int b=s%n;//2
        for(int i=0;i<n-b;i++)answer.push_back(a);
        for(int i=0;i<b;i++)answer.push_back(a+1);
    }
    return answer;
}