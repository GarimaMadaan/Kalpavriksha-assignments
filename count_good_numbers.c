#include<stdio.h>
#define mod 1000000007
long long power(long long x,long long y){
    if(y == 0) return 1;
    long long ans = power(x,y/2);
    ans*= ans;
    if(y%2) ans *=x;
    ans %= mod;
    return ans;
}

int countGoodNumbers(long long length){
    long long odd = length/2;
    long long even = length/2 +length%2;
    return(power(5,even)*power(4,odd));
}
int main(){
    long long length;
    printf("Enter length of good string : ");
    scanf("%lld",&length);

    printf("%d",countGoodNumbers(length));
}