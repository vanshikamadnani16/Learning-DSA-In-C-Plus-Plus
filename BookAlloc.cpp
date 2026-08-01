#include<iostream>
#include<vector>
using namespace std;
bool isvalid(int n, vector<int>& arr,int m,int MaxAllowedPages)
{
    int stu=1,pages=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]> MaxAllowedPages)
        return false;
        if(pages+arr[i]<= MaxAllowedPages)
        {
            pages+=arr[i];
        }
        else
        {
            stu++;
            pages=arr[i];
        }
        }
         return stu>m?false:true;
}

    int AllocatePages(int n, vector<int>& arr,int m) {
        if(m>n)
        {
            return -1;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=arr[i]; 
        int st=0,end=sum,ans=-1;
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(isvalid(n,arr,m,mid)){
            ans=mid;
            end=mid-1;
            }
            else
            st=mid+1;
        }   
        return ans;    
        
    }
int main()
{
    vector<int>pages={15,17,20};
    int n=3,m=2;
    cout<<AllocatePages(n,pages,m)<<endl;
    return 0;

}

