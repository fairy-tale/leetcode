//recursion dfs gets run time error.
//use iterative bfs.
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty())return;
		queue<pair<int, int>> q;
		vector<pair<int, int>> path{ { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
		for (int i = 0; i<board[0].size(); i++){
			if (board[0][i] == 'O'){
				board[0][i] = '*';
				q.push({ 0, i });
			}
			if (board[board.size() - 1][i] == 'O'){
				board[board.size() - 1][i] = '*';
				q.push({ board.size() - 1, i });
			}
		}
		for (int i = 0; i<board.size(); i++){
			if (board[i][0] == 'O'){
				board[i][0] = '*';
				q.push({ i, 0 });
			}
			if (board[i][board[0].size() - 1] == 'O'){
				board[i][board[0].size() - 1] = '*';
				q.push({ i, board[0].size() - 1 });
			}
		}
		while (!q.empty()){
			auto res = q.front();
			q.pop();
			int x = res.first, y = res.second;
			for (auto i : path){
				int xx = x + i.first;
				int yy = y + i.second;
				if (xx>0 && yy>0 && xx<board.size() - 1 && yy<board[0].size() - 1 && board[xx][yy] == 'O'){
					board[xx][yy] = '*';
					q.push({ xx, yy });
				}
			}
		}
		for (int i = 0; i<board.size(); i++)
			for (int j = 0; j<board[0].size(); j++){
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == '*')
					board[i][j] = 'O';
			}
	}
};