//Program: Endoscope - by Veeraj - 17 Feb test

#include <iostream>

struct Pair 
{ // Structure to hold [row, col] as a pair
	Pair() : x(0), y(0) {}
	Pair(int r, int c) : x(r), y(c) {}
	int x, y; 
};

int N, M, X, Y, D, mat[55][55], vmat[55][55], dist[55][55], f, r;
Pair q[55*55];

// 1 Indicates pipe is open in that direction, 0 indicates it is closed
bool up[] = { 0, 1, 1, 0, 1, 0, 0, 1 }, down[] = { 0, 1, 1, 0, 0, 1, 1, 0 }, 
left[] = { 0, 1, 0, 1, 0, 0, 1, 1 }, right[] = { 0, 1, 0, 1, 1, 1, 0, 0 };

// Queue implementation
void push(Pair p) { q[r++] = p; }
Pair pop() { return q[f++]; }
bool empty() { return f == r; }

void push2(int x1, int y1, int x2, int y2)
{ // Utility function to track distance of pipe(at x2, y2) when it is visited from pipe(at x1, y1)
	dist[x2][y2] = dist[x1][y1] + 1;
	vmat[x2][y2] = 1;
	push(Pair(x2, y2));
}

void bfs(int ex, int ey)
{ // Run bfs
	push2(ex, ey, ex, ey);	// Push the initial vertex with distance 1
	while (!empty())
	{ // Pop from the queue and visit compatible pipes in all 4 directions if not visited already
		Pair p = pop();
		int x = p.x, y = p.y;
		if (x-1 >= 0 && up[mat[x][y]] && down[mat[x-1][y]] && !vmat[x-1][y]) push2(x, y, x-1, y);
		if (x+1 < N && down[mat[x][y]] && up[mat[x+1][y]] && !vmat[x+1][y]) push2(x, y, x+1, y);
		if (y-1 >= 0 && left[mat[x][y]] && right[mat[x][y-1]] && !vmat[x][y-1]) push2(x, y, x, y-1);
		if (y+1 < M && right[mat[x][y]] && left[mat[x][y+1]] && !vmat[x][y+1]) push2(x, y, x, y+1);
	}
}

int main()
{
	std::cin >> N >> M >> X >> Y >> D;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j) 
			std::cin >> mat[i][j];
	bfs(X, Y);

	// Count all pipes with distance set(dist > 0), and distance less than or equal to given depth
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (dist[i][j] && dist[i][j] <= D)
				++cnt;
	std::cout << cnt << std::endl;
	return 0;
}
