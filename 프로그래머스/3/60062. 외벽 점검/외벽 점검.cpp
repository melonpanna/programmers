#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    sort(dist.begin(),dist.end());
    do{
        vector<int> copy=vector<int>(weak.begin(),weak.end());
        int k=0;
        while(k<copy.size()){
            int d=0;
            int cnt=1;
            for(int i=0;i<copy.size()-1;i++){
                if(d+copy[i+1]-copy[i]<=dist[cnt-1])d+=(copy[i+1]-copy[i]);
                else{
                    cnt++;
                    d=0;
                    if(cnt>dist.size()
                      ||(answer!=-1&&answer<=cnt))break;
                }
            }
            if(cnt<=dist.size()){
                if(answer==-1)answer=cnt;
                else answer=min(answer,cnt);
            }
            d=0;
            cnt=1;
            for(int i=copy.size()-1;i>0;i--){
                if(d+copy[i]-copy[i-1]<=dist[cnt-1])d+=(copy[i]-copy[i-1]);
                else{
                    cnt++;
                    d=0;
                    if(cnt>dist.size()
                      ||(answer!=-1&&answer<=cnt))break;
                }
            }
            if(cnt<=dist.size()){
                if(answer==-1)answer=cnt;
                else answer=min(answer,cnt);
            }
            //그다음에 바꿈
            copy.push_back(n+copy[0]);
            copy.erase(copy.begin());
            k++;
        }
    }while(next_permutation(dist.begin(),dist.end()));
    return answer;
}