#include<iostream>
using namespace std;
int mat[15][15];
bool vis[15][15];
int m,n;
void func(int i,int j,int d,int s,int &sum)
{
    /*cout<<i<<" "<<j<<" "<<d<<" "<<s<<endl;
    
    for(int l=1;l<=m;l++)
			{
			for(int k=1;k<=n;k++)
				cout<<vis[l][k];
			cout<<endl;
			}*/
			
	if(d==0)
	{
		if(s>sum)
			sum=s;
		return;
	}
	
	if(i<1||i>m||j<1||j>n)
		return;
	//cout<<"check"<<endl;
	if( i<m && !vis[i+1][j] ) 
	{
		vis[i+1][j]=1;
		func(i+1,j,d-1,s+mat[i+1][j],sum);
		vis[i+1][j]=0;
	}
	//cout<<"check1"<<endl;
	if( i>1 && !vis[i-1][j] ) 
	{
		vis[i-1][j]=1;
		func(i-1,j,d-1,s+mat[i-1][j],sum);
		vis[i-1][j]=0;
	}
	//cout<<"check2"<<endl;
	if( j<n && !vis[i][j+1] ) 
	{
		vis[i][j+1]=1;
		func(i,j+1,d-1,s+mat[i][j+1],sum);
		vis[i][j+1]=0;
	}
	//cout<<"check3"<<endl;
	if( j>1 && !vis[i][j-1] ) 
	{
		vis[i][j-1]=1;
		func(i,j-1,d-1,s+mat[i][j-1],sum);
		vis[i][j-1]=0;
	}

	if(j%2==0)
	{
	   if( j>1 && i<m  && !vis[i+1][j-1] ) 
	    {
		    vis[i+1][j-1]=1;
		    func(i+1,j-1,d-1,s+mat[i+1][j-1],sum);
		    vis[i+1][j-1]=0;
	    }
	    if( j<n && i<m && !vis[i+1][j+1] ) 
	    {
		    vis[i+1][j+1]=1;
		    func(i+1,j+1,d-1,s+mat[i+1][j+1],sum);
		    vis[i+1][j+1]=0;
	    }
	}
	else
	{
	    if( j>1 && i>1  && !vis[i-1][j-1] ) 
	    {
		    vis[i-1][j-1]=1;
		    func(i-1,j-1,d-1,s+mat[i-1][j-1],sum);
		    vis[i-1][j-1]=0;
	    }
	    if( j<n && i>1 && !vis[i-1][j+1] ) 
	    {
		    vis[i-1][j+1]=1;
		    func(i-1,j+1,d-1,s+mat[i-1][j+1],sum);
		    vis[i-1][j+1]=0;
	    }
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		int max=0;
		
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
					cin>>mat[i][j];
		int d=3;
		
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				vis[i][j]=0;
				
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				int sum=0;
				int s=mat[i][j];
				vis[i][j]=1;
				func(i,j,d,s,sum);
				vis[i][j]=0;
				//cout<<sum<<endl;
				if(sum>max)
					max=sum;
			}
		for(int i=2;i<=m-1;i++)
		    for(int j=2;j<=n-1;j++)
		    {
		        int val,val1;
		        if(j%2==0)
		           {
		               val=mat[i][j]+mat[i][j-1]+mat[i][j+1]+mat[i+1][j];
		               val1=mat[i][j]+mat[i+1][j-1]+mat[i+1][j+1]+mat[i-1][j];
		               if(val<val1)
		                val=val1;
		           }
		        else
		            {
		                val=mat[i][j]+mat[i][j-1]+mat[i][j+1]+mat[i-1][j];
		                val1=mat[i][j]+mat[i-1][j-1]+mat[i-1][j+1]+mat[i+1][j];
		                if(val<val1)
		                val=val1;
		            } 
		        if(val>max)
		            max=val;
		    }
			
		cout<<max<<endl;	
	}
}