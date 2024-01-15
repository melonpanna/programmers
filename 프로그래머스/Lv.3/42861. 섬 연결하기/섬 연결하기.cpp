#include <string>
#include <vector>
#include <algorithm>
#define MAX_N 105

using namespace std;
int root[MAX_N];
bool cmp(vector<int> c1,vector<int> c2){
    return c1[2]<c2[2];
}
//union find
int find_(int a){
    if(a==root[a])return a;
    else return root[a]=find_(root[a]);
}
void union_(int a,int b){
    a=find_(a);
    b=find_(b);
    if(a<b)root[b]=a;
    else root[a]=b;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    if(n==1)return answer;
    sort(costs.begin(),costs.end(),cmp);
    for(int i=0;i<n;i++)root[i]=i;
    int cnt=0;
    for(vector<int> e:costs){
        if(cnt==n-1)break;
        int a=e[0];
        int b=e[1];
        if(find_(a)==find_(b))continue;
        union_(a,b);
        cnt++;
        answer+=e[2];
    }
    return answer;
}