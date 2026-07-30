#include<iostream>
#include<vector>
using namespace std;
vector<int> PairSum(vector<int> nums,int target)
{
    int start=0,end=nums.size()-1;
    vector<int> result;
    while(start<end)
    {
        int sum=nums[start]+nums[end];
        if(sum==target)
        {
            result.push_back(start);
            result.push_back(end);
            return result;
        }
        else if(sum<target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return result;
    
}
int main()
{
    vector<int> nums={2,7,11,15};
    int target=26;
    vector<int> result=PairSum(nums,target);
    cout<<"Indices of the pair that sums to "<<target<<": "<<result[0]<<" and "<<result[1]<<endl;
    return 0;
}
