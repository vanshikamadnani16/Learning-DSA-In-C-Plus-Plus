#include<iostream>
#include<string>
using namespace std;
void getperms(string str,int idx){
    if(idx==str.length())
    {
        cout<<str<<endl;
        return;
    }
    for(int i=idx;i<str.length();i++){
        swap(str[idx],str[i]);
        getperms(str,idx+1);
        swap(str[idx],str[i]);
    }
}
int main()
{
    string str="abc";
    getperms(str,0);
    return 0;
}