#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int a[7] = { 2,7,11,15 };
	//char a0[6] = { '.','.","4",".",".",".","6","3","." };
	char a1[6] = { '0','5','1' };
	char a2[6] = { '.','.','0' };
	vector<int> nums(a, a + 4);
	vector<int> ans;
	vector<vector<char>> board;
	board.resize(3);
	for (int i = 0; i < board.size(); ++i)
	{
		board[i].resize(3);
	}
	//board[0] = vector<char>(a0, a0 + 3);
	board[1] = vector<char>(a1, a1 + 3);
	board[2] = vector<char>(a2, a2 + 3);
	/*cout << board[1][1] << board[2][2] << board[0][0];*/

	set<char> row;
	set<char> col;
	set<char> block;
	for (int i = 0; i < 3; ++i)
	{
		row.clear();
		row.clear();
		for (int j = 0; j < 3; ++j)
		{
			//¼ì²ârow
			if (board[i][j] != '.')
			{
				if (row.find(board[i][j]) != row.end())
				{
					return 0;
				}
				row.insert(board[i][j]);
			}
			//¼ì²âcol
			if (board[j][i] != '.')
			{
				if (col.find(board[j][i]) != col.end())
				{
					return 0;
				}
				col.insert(board[j][i]);
			}
			//¼ì²âblock
			if (i % 3 == 0&& j %3 == 0)
			{
				block.clear();
				for (int m = 0; m < 3; ++m )
				{
					for (int n = 0; n < 3; ++n)
					{
						if (board[i + m][j + n] != '.')
						{
							if (block.find(board[i + m][j + n]) != block.end())
							{
								return 0;
							}
							block.insert(board[i + m][j + n]);
						}
					}
				}
			}
		}
	}

	cout << "      ";
	system("pause");
	return 0;
}