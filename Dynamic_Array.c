/*
Array insertion & Array deletion
using dynamic memory allocation.. 
*/

#include<stdio.h>
#include<stdlib.h>

void printFunction(int arr[],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return ;
}

int* insertFunction(int arr[],int *n,int value,int idx)
{
    if(idx<0||idx>*n){
       fprintf(stderr,"Error: Invalid index!\n");
        return arr; 
    } 
    // Resize memory
    int *temp=(int*)realloc(arr,(*n+1)*sizeof(int));
    if(temp==NULL){
        fprintf(stderr,"Error: Memorry allocation failed!\n");
        return arr;
    }
    arr=temp;
    for(int i=*n ; i > idx ; i--){
        arr[i]=arr[i-1];
    }
    arr[idx]=value;
    (*n)++;
    return arr;

}

int* deleteFunction(int arr[],int *n,int idx)
{   
    if(idx<0||idx>=*n){
       fprintf(stderr,"Error: Invalid index!\n");
        return arr; 
    }
    // Shift elements left
    for(int i=idx;i<*n-1;i++){
        arr[i]=arr[i+1];
    }
    // Resize memory
    int *temp = (int*)realloc(arr, (*n - 1) * sizeof(int));
    if(temp == NULL && *n - 1 > 0){
        fprintf(stderr, "Error: Memory reallocation failed!\n");
        return arr;
    }
    arr = temp;
    (*n)--;
    return arr;
}

int main(){
    int n;

    printf("Enter Array Size : ");
    scanf("%d",&n);

    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter %d elements : ", n);
    for (int i=0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    printf("After Input:\n");
    printFunction(arr,n);

    int value,idx;
    printf("Enter value and idx(0 to %d)  to insert: ",n);
    scanf("%d %d",&value,&idx);

    arr=insertFunction(arr,&n,value,idx);
    printf("After Insertion : ");
    printFunction(arr,n);

    int idx2;
    printf("Enter idx to delete : ");
    scanf("%d",&idx2);
    arr=deleteFunction(arr,&n,idx2);
    printf("After deletion : ");
    printFunction(arr,n);

    return 0;
}