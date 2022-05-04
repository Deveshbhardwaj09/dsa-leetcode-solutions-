#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// APPROACH 1 
//using sorting in nlogn  
int helper(int arr[],int n,int k){
    // inbuilt sort 
    sort(arr,arr+n);
    return arr[n-k];
}

// APPROACH 2 
// using max/min heap in n
int bestsol(int nums[],int n,int k){
    // inbuilt min priority queue
      priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            int top= pq.top();
            if(nums[i]>=top){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
}


int main() {
       
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //int ans= helper(arr,n,k);
    int ans1= bestsol(arr,n,k);
    cout<<ans1<<endl;
}

