/*
Operation in Array!
-->insertion,deletion
-->traversing,searching
*/

#include<iostream>
using namespace std;

void printFunction(int arr[],int n)
{   
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}
int *searchFunction(int arr[],int n,int value,int &foundSize)
{
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==value) count++;
    }
    if(count==0) return NULL;
    int *foundArr=new int[count];
    int idx=0;
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            foundArr[idx++]=i;
        }
    }
    foundSize=count;
    return foundArr;
}

int* insertFunction(int arr[],int &n,int value,int idx)
{
    if( idx<0 || idx>n){
        cerr<<"Error:Invalid index!"<<endl;
        return arr;
    }
    int *newArr=new int[n+1];
    for(int i=0;i<idx;i++){
        newArr[i]=arr[i];
    }
    for(int i=n; i>idx; i--){
        newArr[i]=arr[i-1];
    }
    newArr[idx]=value;
    delete[] arr;
    (n)++;
    return newArr;
}
int *deleteFunction(int arr[],int &n,int idx)
{
    if( idx<0 || idx>=n){
        cerr<<"Error:Invalid index!"<<endl;
        return arr;
    }
    int *newArr=new int[n-1];
    for(int i=0;i<idx;i++){
        newArr[i]=arr[i];
    }
    for(int i=idx;i<n-1;i++){
        newArr[i]=arr[i+1];
    }
    delete[] arr;
    n--;
    return newArr;
}
int main(){
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    if( n<0 ){
        cerr<<"Error:Array size!"<<endl;
        return 1;
    }
    int *arr=new int[n];
    cout<<"Enter "<<n<<" Element  : ";
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    cout<<"Array : ";
    printFunction(arr,n);

    int idx,value;
    cout<<"Enter index(0 to "<<n<<") and value to insert : ";
    cin>>idx>>value;
    arr=insertFunction(arr,n,value,idx);
    cout<<"After insertion : ";
    printFunction(arr,n);

    int idx2;
    cout<<"Enter index number to delete : ";
    cin>>idx2;
    arr=deleteFunction(arr,n,idx2);
    cout<<"After deletion : ";
    printFunction(arr,n);

    int num;
    cout<<"Enter value to search : ";
    cin>>num;
    int foundSize;
    int *found=searchFunction(arr,n,num,foundSize);
    if(found==NULL){
        cout<<num<<" not found";
    }else{
        cout<<num<<" is found in "<<foundSize<<" idex position : ";
        for(int i=0;i<foundSize;i++){
            cout<<found[i]<<" ";
        }
        cout<<endl;
        delete[] found;
    }

    delete[] arr;
    return 0;
}