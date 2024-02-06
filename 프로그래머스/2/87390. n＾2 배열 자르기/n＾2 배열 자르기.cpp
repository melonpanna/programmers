#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    long long temp=right-left;
    int arrsize=(int)temp+1;
    vector<int> answer=vector<int>(arrsize);
    int a,b,c,d;
    int cnt=0;
    a=(int)(left/(long long)n);
    b=(int)(left%(long long)n);
    c=(int)(right/(long long)n);
    d=(int)(right%(long long)n);
    if(left==right){
        answer[cnt]=max(a,b)+1;
        return answer;
    }
    for(long long i=0;i<arrsize;i++){
        long long temp=left+i;
        answer[i]=(int)max(temp/n,temp%n)+1;
    }
    // for(int j=b;j<n;j++)answer[cnt++]=max(a,j)+1;
    // for(int i=a+1;i<c;i++){
    //     for(int j=0;j<n;j++){
    //         answer[cnt++]=max(i,j)+1;
    //     }
    // }
    // for(int j=0;j<=d;j++)answer[cnt++]=max(c,j)+1;
    return answer;
}