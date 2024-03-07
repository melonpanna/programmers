#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(string s) {
    transform(s.begin(),s.end(),s.begin(),::tolower);
    if(s[0]>='a'&&s[0]<='z')s[0]-=(32);
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==' '){
            if(s[i+1]>='a'&&s[i+1]<='z')s[i+1]-=(32);
        }
    }
    return s;
}