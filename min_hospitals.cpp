#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


#define M 10
#define N 10
int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };

bool check_districts(int mat[M][N], int x, int y, bool visited[M][N])
{
	return (x >= 0) && (x < M) && (y >= 0) && (y < N) &&
		(mat[x][y] && !visited[x][y]);
}

void BFS(int mat[M][N], bool visited[M][N], int i, int j)
{
	
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	
	visited[i][j] = true;
	
	 	
	while (!q.empty())
	{
			
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

	
		for (int k = 0; k < 8; k++)
		{
					
			if (check_districts(mat, x + row[k], y + col[k], visited))
			{
				
				visited[x + row[k]][y + col[k]] = 1;
				q.push(make_pair(x + row[k], y + col[k]));
			}
		}
	}
}

int main()
{
	int mat[M][N]=
	{
		{ 0, 1, 1, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 1, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 0, 0, 0, 1 },
		{ 0, 1, 0, 0, 0, 1, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 1, 0 }
	};

	
	bool visited[M][N];

	
	memset(visited, 0, sizeof(visited));

	int hospitals = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j] && visited[i][j] == 0)
			{
				BFS(mat, visited, i, j);
				hospitals++;
			}
		}
	}

	cout << "Minimum number of hospitals  =  " << hospitals<< '\n';

	return 0;
}



// DFS for comapring with BFS

/*
void DFS(int mat[M][N], int row, int col, 
		bool visited[M][N]) 
{ 
	static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
	static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

	
	visited[row][col] = true; 

	// Recur for all connected neighbours 
	for (int k = 0; k < 8; ++k) 
		if (check_districts(mat, x + row[k], y + col[k], visited))
			{
				
				visited[x + row[k]][y + col[k]] = 1;
				q.push(make_pair(x + row[k], y + col[k]));
			}
} 




*/















