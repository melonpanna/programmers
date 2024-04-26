#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> nums=vector<string>({
        "zero","one","two","three","four","five","six","seven","eight","nine"
    });
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            answer*=10;
            answer+=s[i]-'0';
        }
        else{
            for(int j=0;j<10;j++){
                if(s.size()-i>=nums[j].size()
                   &&s.substr(i,nums[j].size())==nums[j]){                    
                answer*=10;
                answer+=j;
                i+=nums[j].size()-1;
                break;
                }
            }
        }
    }
    return answer;
}