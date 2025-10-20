#include<iostream>
#include<vector>
//n-th prime numbers print
using namespace std;
void sieveAlg(int n)
{
    vector<int> isPrime(n+1,1);
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]==1)
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    sieveAlg(n);
    return 0;
}