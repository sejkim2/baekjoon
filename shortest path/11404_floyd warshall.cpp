#include <iostream>
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

#include <algorithm>
#define INF 99999999
int n, m, a, b, c;
int city[101][101];

void floyed_warshall()
{
	//필수로 거쳐야 되는 노드 
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			for(int k = 1; k<=n; k++)
			{
				if (j == k)
					continue;
				else
					city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
			}
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if (i != j)
				city[i][j] = INF;
		}
	}

	for(int i = 0; i<m; i++)
	{
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b], c);
	}
	
	floyed_warshall();
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if (city[i][j] == INF)
				cout << "0" << " ";
			else
				cout << city[i][j] << " ";
		}
		cout << endl;
	}
}