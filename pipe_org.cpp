#include<iostream>
using namespace std;
#define INT_MAX 9999999
int m,n;
struct pr{
    bool u=false,d=false,l=false,r=false;
};
bool issafe(int x,int y,int m,int n)
{
	if(x>=m || y>=n)
		return false;
	return true;
}
void func(int x,int y,int k,int a[100][100],pr arr[8],int &ans,int m,int n,int vis[100][100],int temp)
{
	if(k==0)
	{
	    if(vis[x][y]==INT_MAX)
	    {
	        vis[x][y]=temp;
		    ans+=1;
	    }
		return;
	}
	if(vis[x][y]==INT_MAX && a[x][y])
		    ans+=1;
    vis[x][y]=temp;
	if(arr[a[x][y]].d && issafe(x+1,y,m,n) && vis[x+1][y]>temp && arr[a[x+1][y]].u)
	{
		func(x+1,y,k-1,a,arr,ans,m,n,vis,temp+1);
	}
	if(arr[a[x][y]].u && issafe(x-1,y,m,n) && vis[x-1][y]>temp && arr[a[x-1][y]].d)
	{
		func(x-1,y,k-1,a,arr,ans,m,n,vis,temp+1);
	}
	if(arr[a[x][y]].l && issafe(x,y-1,m,n) && vis[x][y-1]>temp && arr[a[x][y-1]].r)
	{
		func(x,y-1,k-1,a,arr,ans,m,n,vis,temp+1);
	}
	if(arr[a[x][y]].r && issafe(x,y+1,m,n) && vis[x][y+1]>temp && arr[a[x][y+1]].l)
	{
		func(x,y+1,k-1,a,arr,ans,m,n,vis,temp+1);
	}
}
int main()
{
    pr arr[8];
    arr[1].u=true;
    arr[1].d=true;
    arr[1].l=true;
    arr[1].r=true;
    arr[2].u=true;
    arr[2].d=true;
    arr[3].l=true;
    arr[3].r=true;
    arr[4].u=true;
    arr[4].r=true;
    arr[5].d=true;
    arr[5].r=true;
    arr[6].l=true;
    arr[6].d=true;
    arr[7].u=true;
    arr[7].l=true;
    int t;
    cin>>t;
    while(t--)
    {
    int k,x,y;
    cin>>m>>n>>x>>y>>k;
    int a[100][100];
	int vis[100][100];
	
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
	{
		vis[i][j]=INT_MAX;
        cin>>a[i][j];
	}
	int ans=0;
    func(x,y,k-1,a,arr,ans,m,n,vis,1);
	cout<<ans<<endl;
    }
}