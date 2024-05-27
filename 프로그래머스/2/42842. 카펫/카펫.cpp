#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer=vector<int>(2,0);
    for(int height=1;;height++){
        for(int width=height;;width++){
            int temp=(2*width+2*height-4);
            if(brown==temp){
                if(yellow==((width-2)*(height-2))){
                    answer[0]=width;
                    answer[1]=height;
                    return answer;
                }
            }
            else if(brown<temp)break;
        }
    }
    return answer;
}