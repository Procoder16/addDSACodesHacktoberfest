#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > result;
void solveBoard(vector<vector<char> >& board, int row,
				int rowmask, int ldmask, int rdmask,
				int& ways)
{

	int n = board.size();
	int all_rows_filled = (1 << n) - 1;
	if (rowmask == all_rows_filled) {

		vector<int> v;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] == 'Q')
					v.push_back(j + 1);
			}
		}
		result.push_back(v);
		return;
	}
	int safe
		= all_rows_filled & (~(rowmask | ldmask | rdmask));
	while (safe) {
		int p = safe & (-safe);
		int col = (int)log2(p);
		board[row][col] = 'Q';
		solveBoard(board, row + 1, rowmask | p,
				(ldmask | p) << 1, (rdmask | p) >> 1,
				ways);
		safe = safe & (safe - 1);
		board[row][col] = ' ';
	}
	return;
}

int main()
{
	int n = 4;
	int ways = 0;

	vector<vector<char> > board;
	for (int i = 0; i < n; i++) {
		vector<char> tmp;
		for (int j = 0; j < n; j++) {
			tmp.push_back(' ');
		}
		board.push_back(tmp);
	}
	int rowmask = 0, ldmask = 0, rdmask = 0;
	int row = 0;
	result.clear();
	solveBoard(board, row, rowmask, ldmask, rdmask, ways);
	sort(result.begin(),result.end());
	for (auto ar : result) {
		cout << "[";
		for (auto it : ar)
			cout << it << " ";
		cout << "]";
	}
	return 0;
}
// This code is contributed by Nishant Choudhary
