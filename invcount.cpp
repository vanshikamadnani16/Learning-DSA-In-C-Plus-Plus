#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>& nums,int st,int mid,int e){
    vector<int> temp;
    int i=st,j=mid+1,Invcount=0;
    while(i<=mid && j<=e)
    {
        if(nums[i]<=nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
            Invcount+=mid-i+1;
        }
    }
    while(i<=mid)
    {
       temp.push_back(nums[i]);
            i++; 
    }
    while(j<=e)
    {
        temp.push_back(nums[j]);
            j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        nums[idx+st]=temp[idx];
    }
     return Invcount;
}
int mergeSort(vector<int>& nums,int st,int e){
    if(st<e)
    {
        int mid=st+(e-st)/2;
       int LeftInvcount= mergeSort(nums,st,mid);
       int RightInvcount= mergeSort(nums,mid+1,e);
       int Invcount= merge(nums,st,mid,e);
       return (LeftInvcount+RightInvcount+Invcount);
    }
    return 0;
}
    int main()
    {
        vector<int> nums={6,3,5,2,7};
        int ans= mergeSort(nums,0,nums.size()-1);
        cout<<"Inversion count:"<<ans<<endl;
    }
