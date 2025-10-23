#include<iostream>
using namespace std;
int findGCD(int a,int b);
/*
Concept:
findGCD(a, b) = findGCD(b, a % b)
Example: findGCD(48, 18)
Step 1: 48 % 18 = 12
Step 2: findGCD(18, 12)
Step 3: 18 % 12 = 6  
Step 4: findGCD(12, 6)
Step 5: 12 % 6 = 0
Step 6: findGCD(6, 0) = 6
*/
int main()
{
    int a,b;
    cout<<"Enter two numbers : ";
    cin>>a>>b;
    cout<<"GCD : "<<findGCD(a,b)<<endl;
    return 0;
}
int findGCD(int a,int b)
{
    if(b==0) return a;
    return findGCD(b,a%b);
}
