#include <cmath>
using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w*h;
    double start,end;
    for(double i=0;i<w;i+=1.0){
        start=((double)h*i/(double)w);
        end=((double)h*(i+1.0)/(double)w);
        int s=floor(start);
        int e=ceil(end);
        answer-=(e-s);
    }
    return answer;
}