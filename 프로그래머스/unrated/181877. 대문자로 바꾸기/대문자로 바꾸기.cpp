#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(int i=0;i<myString.size();i++){
        if(myString[i]-'A'>=0&&myString[i]-'A'<=25)answer+=myString[i];
        else answer+=(myString[i]-32);
    }
    return answer;
}