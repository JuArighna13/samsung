//Adv Test: Intersteller  - finding shortest path between two nodes by utilzing the worm holes.
#include<stdio.h>
#include<conio.h>

//sample inputs are at the end of the program

int adj[13][13];	//matrix representation of start and end node + entry and exit as vertices of the worm hole
int X[13];			//x coordinate of all vertices of start and end node + entry and exit as vertices of the worm hole
int Y[13];			//y coordinate of (same as above)
int W[5];			// time from one vertices to another.  This is comes as input for every given worm hole.
int V;              //total number of vertices include tart and end node + entry and exit as vertices of the worm hole
int visited[13];	//visited the node or not
int key[13];		//Key - maintain the minimum time to reach from SOURCE to other vertices.

int getMin()		//function to find the next available minimum travel time vertex.
{
	int min=100000;		//assume this is the max time - we call it infinity
	int min_vertex;		//next available vertex with minimum cost from the source.
	int i;

	for(i=1;i<=V;i++)
	{
		if(min>key[i] && visited[i]==0)
		{
			min = key[i];
			min_vertex = i;		//found the next available vertex with minimium cost and not visited as condition.
		}
	}
	return min_vertex;
}

int dijkstra(int adj[][13])          //  standard algorithm to compute shortest path from given source to any other vertex within a given graph.
{
	int i;
	for( i=1;i<=V;i++)
	key[i]=100000;		//infinity initialized as time from source to destination (all vertices
	key[1]=0;			//as the time is zero from source to source.  Hence it is zero.
	
	for(int i=1;i<=V;i++)		//This loop for rest of the vertices will find minimium time from source to other vertices.
	{
		int u = getMin();
		visited[u] = 1;
		for(int v=1;v<=V;v++)
		{
			if(adj[u][v]&& key[u]+adj[u][v] < key[v])
			key[v] = key[u]+adj[u][v];			//adding the min time at the intermediate destination node from the source, which over write all infinite value with actuals.
		}
	}
	return key[2];// As 2 is the destination node here. 
}

int intersteller(int X[],int Y[])   // this function will setup out matrix graph and finally call dijkstra algorithm
{
	for(int i=1;i<=V+1;i++)
	{
		for(int j=1;j<=V+1;j++)   //calculate the min time between any 2 vertex (populating our full graph)
		{
			adj[i][j] = (X[i]-X[j] > 0?X[i]-X[j] : X[j]-X[i]) + (Y[i]-Y[j] > 0?Y[i]-Y[j] : Y[j]-Y[i]);
			adj[j][i] = adj[i][j];
		}
	}
	
	int j=0;
	for(int i=3;i<V;)		//updating min time between entry and exit point of the worm holes. This comes as input.
	{
		adj[i][i+1] = W[j];
		adj[i+1][i] = W[j++];
		i = i+2;
	}
	/*
	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		printf("%d ",adj[i][j]);
		printf("\n");
	}*/
	return dijkstra(adj);
}

int AnswerN;

int main()
{
	int i=1;
	int n;
	scanf("%d",&n); // number of warmholes.
	
	scanf("%d%d",&X[i],&Y[i]);
	i++;
	scanf("%d%d",&X[i],&Y[i]);
	i++;
	
	V= 2*n + 2; // Total of warmhole gates, source and destination.
	int k=0;
	for(int j=1;j<=n;j++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		i++;
		scanf("%d%d%d",&X[i],&Y[i],&W[k]);
		i++;
		k++;
	}
	
	for(int l=1;l<=i;l++)
	printf("%d %d\n",X[l],Y[l]);
	i=1;
	int j=2; // 1 : source, 2 : destination
	int s_d = (X[i]-X[j] > 0?X[i]-X[j] : X[j]-X[i]) + (Y[i]-Y[j] > 0?Y[i]-Y[j] : Y[j]-Y[i]);
	
	if(n==0)
	{
		AnswerN = s_d;
	}
	else
		AnswerN = intersteller(X,Y);
	
	printf("%d\n",AnswerN);
	
	getch();
	return 0;
}



/*  Smaple inputs..
5     // Number of test cases

0     // number of worm holes
0 0 60 60 // co-ordinates of start and end points.

1			// number of worm holes
0 0 2 0		// co-ordinates of start and end points.
1 0 1 2 0   // Co-ordinates of entry/exit and exit/entry with time taken to travel through the worm hole.

1 
0 0 60 60 
40 40 20 20 20 

2 
100 50 10 5 
80 40 10 6 10 
80 10 70 40 5 

3
500 500 1000 1000 
501 501 999 999 1000
1 1 499 499 100
1000 999 0 0 200
*/
