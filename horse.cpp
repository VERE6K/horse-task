#include <iostream>
#include <vector>

using namespace std;

const int cord[][2] = { {1, -2}, {2, -1} };
//пути хода коня по условию


int main() {
	int n, m;
	cin >> n >> m;
	vector< vector<int> > square(m, vector<int>(n, 0));
	square[0][n - 1] = 1;
	for (int i = 1; i < m; ++i)
		for (int j = n - 2; j > -1; --j) {
			int x1 = i - cord[0][0];
			int y1 = j - cord[0][1];
			int x2 = i - cord[1][0];
			int y2 = j - cord[1][1];
			if ((x1 > -1) && (x1 < n) && (y1 > -1) && (y1 < m))
				square[i][j] += square[x1][y1];
			if ((x2 > -1) && (x2 < n) && (y2 > -1) && (y2 < m))
				square[i][j] += square[x2][y2];
		}
	cout << square[m - 1][0];
}
