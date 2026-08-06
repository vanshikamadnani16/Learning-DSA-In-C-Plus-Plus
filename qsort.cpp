#include<iostream>
#include <vector>
using namespace std;
int partition(vector<int> &nums,int st,int e){
    int idx=st-1,pivot=nums[e];
    for(int j=st;j<e;j++){
         if(nums[j]<=pivot){
        idx++;
        swap(nums[j],nums[idx]);
         }
    }
    idx++;
    swap(nums[e],nums[idx]);
    return idx;
}
void quickSort(vector<int> &nums,int st,int e)
{
    if(st<e){
    int  pivot=partition(nums,st,e);
    quickSort(nums,st,pivot-1);
    quickSort(nums,pivot+1,e);
    }
}
int main()
{
    vector<int> nums={12,31,35,8,32,17};
    quickSort(nums,0,nums.size()-1);
    for(int val:nums){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}