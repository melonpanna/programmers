#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long e:numbers){
        if(e%2==0){
            answer.push_back(e+1);
            continue;
        }
        //이진수 변환
        for(long long i=1;;i*=2){
            if((e&i)==0){
                e+=i;
                e-=i/2;
                break;
            }
        }
        answer.push_back(e);
    }
    return answer;
}