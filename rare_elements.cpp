#include<iostream>
#include<queue>
using namespace std;
int mat[20][20];
int vis[20][20];

int h[501];

void func(int i,int j,int n,int c)
{
    queue<int> q;
    int u=i*(n+1)+j;
    int x,y;
    q.push(u);
    vis[i][j]=1;
    while(!q.empty()&& c>0)
    {
        int v=q.front();
        q.pop();
        x=v/(n+1);
        y=v%(n+1);
        if(x<n && !vis[x+1][y] && mat[x+1][y]==1)
        {
            vis[x+1][y]=vis[x][y]+1;
            u=(x+1)*(n+1)+y;
            q.push(u);
          
        }
        if(x>1 && !vis[x-1][y] && mat[x-1][y]==1)
        {
            vis[x-1][y]=vis[x][y]+1;
            u=(x-1)*(n+1)+y;
            q.push(u);
           
        }
        if(j<n && !vis[x][y+1] && mat[x][y+1]==1)
        {
            vis[x][y+1]=vis[x][y]+1;
            u=x*(n+1)+y+1;
            q.push(u);
          
        }
        if(j>1 && !vis[x][y-1] && mat[x][y-1]==1)
        {
            vis[x][y-1]=vis[x][y]+1;
            u=x*(n+1)+y-1;
            q.push(u);
        
        }
        if(h[x*(n+1)+y])
            {
                c--;
            }    
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c,min=10000,max=0;
        cin>>n>>c;
        
        for(int i=1;i<501;i++)
            h[i]=0;
        
        int x,y;    
        for(int i=1;i<=c;i++)
            {
                cin>>x>>y;
                h[x*(n+1)+y]=1;
            }    
            
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>mat[i][j];
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                vis[i][j]=0;
                
                
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    int max=0;
                    if(mat[i][j]==1 && h[i*(n+1)+j]!=1)
                    {
                           func(i,j,n,c);
                      
                        for(int k=1;k<=n;k++)
                            for(int l=1;l<=n;l++)
                            {
                                if(vis[l][k]>max && h[l*(n+1)+k])
                                    max=vis[l][k];
                            }
                            
                        for(int a=1;a<=n;a++)
                            for(int b=1;b<=n;b++)
                                vis[a][b]=0;
                        if(max<min)
                        {
                          min=max;
                        } 
                    }
                }    
        cout<<min-1<<endl;    
    }
    return 0;
}