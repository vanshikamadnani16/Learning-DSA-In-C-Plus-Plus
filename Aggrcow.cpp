#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;
bool isPossible(vector<int> &arr,int n,int c,int MinAllowedDist){
    int cows=1,lastpossiblepos=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]-lastpossiblepos>=MinAllowedDist)
		{
            cows++;
            lastpossiblepos=arr[i];
        }
        if(cows==c)
        return true;

	}
	return false;


}
int MinDist(vector<int> &arr,int n,int c)
{
    sort(arr.begin(),arr.end());
	int st=1,end=arr[n-1]-arr[0],ans=-1;
	while(st<=end)
	{
		int mid=st+(end-st)/2;
		if(isPossible(arr,n,c,mid))
		{
			ans=mid;
			st=mid+1;
		}
		else
		end=mid-1;
	}
	return ans;
}

int main() {
	vector<int>stalls={1,2,8,4,9};
	int n=5,c=3;
	cout<<MinDist(stalls,n,c)<<endl;		
	return 0;
	}
