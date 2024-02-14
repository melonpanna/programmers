#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    for(int i=0;i<cities.size();i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto it=find(v.begin(),v.end(),cities[i]);
        //캐시에 있으면 + 업데이트
        if(!v.empty()&&it!=v.end()){
            answer+=1;
            //맨 뒤로 넘김
            v.erase(it);
            v.push_back(cities[i]);
        }
        //캐시에 없음
        else{
            answer+=5;
            v.push_back(cities[i]);
            if(v.size()>cacheSize)v.erase(v.begin());
        }      
        
    }
    return answer;
}