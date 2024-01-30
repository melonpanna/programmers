#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(string n_str) {
    string answer = "";
    for(int i=0;i<n_str.size();i++){
        if(n_str[i]=='0')continue;
        else return n_str.substr(i,n_str.size());
    }
}