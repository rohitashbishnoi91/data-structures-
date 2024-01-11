#include<iostream>
using namespace std;

int binary_search(int arr[],int n,int target){
    int s=0;
    int e=n-1;
    int i=-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if(arr[m]==target){
            i=m;
            break;
        }
        else if(arr[m]>target){
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return i;
}
int main(){
    int n;
    cout<<"enter n: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    int result=binary_search(arr,n,target);
    cout<<result;
    return 0;

}