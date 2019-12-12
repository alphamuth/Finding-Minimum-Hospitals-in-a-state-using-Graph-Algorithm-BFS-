#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


#define M 10
#define N 10
int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };
// checking whether adjacent nodes are visited or not
// and whether the neighbor is in the range of M and N and returning boolean value if visited or not.
bool check_districts(int mat[M][N], int x, int y, bool visited[M][N])
{
	return (x >= 0) && (x < M) && (y >= 0) && (y < N) &&
		(mat[x][y] && !visited[x][y]);
}

void BFS(int mat[M][N], bool visited[M][N], int i, int j)
{
	//initialising the queue
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	//making the first node as visited
	visited[i][j] = true;
	
	 	//run while till queue is empty
	while (!q.empty())
	{
			
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

	    // checking the 8 neighbours a node or districts for better understanding have a look at documentation
		for (int k = 0; k < 8; k++)
		{
					// checking whether adjacent nodes are visited or not
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
	  // in this adjaency matrix 1 means two districts are connected whereas 0 means two districts are not connected and for graphical representation 
	//please see the documentation with this program
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

	//initialising the visited matrix
	bool visited[M][N];

	//setting the all districts to be 0 initially in the visited matrix which means none of the districts are visited yet
	memset(visited, 0, sizeof(visited));

	int hospitals = 0;
	//here we are calling the BFS function to check the whether neighbors are visited or not 
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//here we are checking whether the node is visited or basically checking if value is 1 in visited matrix and input adjacency matrix
			// then call the bfs
			if (mat[i][j] && visited[i][j] == 0)
			{
				 // calling bfs fucntion
				BFS(mat, visited, i, j);
				hospitals++;  // increasing the number of hospitals by 1
			}
		}
	}

	cout << "Minimum number of hospitals  =  " << hospitals<< '\n';

	return 0;
}

