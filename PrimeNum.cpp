#include<iostream>
using namespace std;
int isPrime(long long num)
{   
    if(num<=1)   return 0;
    if(num==2)   return 1;
    if(num%2==0) return 0;
    for(int i=3;i*i<=num;i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    long long n;
    cin>>n;
    int p=isPrime(n);
    if(p)
        cout<<"Prime Number"<<endl;
    else  
        cout<<"Not a Prime number"<<endl;
    return 0;
}