using namespace std;

long long solution(int price, int money, int count)
{
    long long temp=(long long)money;
    for(long long i=1;i<=count;i++){
        temp-=i*(long long)price;
    }
    if(temp<0)return -temp;
    return 0;
}