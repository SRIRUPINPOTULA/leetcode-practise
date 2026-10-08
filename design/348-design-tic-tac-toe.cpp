// 348. Design Tic-Tac-Toe
// https://leetcode.com/problems/design-tic-tac-toe/
// Difficulty: Medium
// Topics: Array, Hash Table, Design, Matrix
//
// Assume the following rules are for the tic-tac-toe game on an n x n board
// between two players:
//   1. A move is guaranteed to be valid and is placed on an empty block.
//   2. Once a winning condition is reached, no more moves are allowed.
//   3. A player who succeeds in placing n of their marks in a horizontal,
//      vertical, or diagonal row wins the game.
//
// Implement the TicTacToe class:
//   TicTacToe(int n) Initializes the object the size of the board n.
//   int move(int row, int col, int player) Indicates that the player with id
//     player plays at the cell (row, col) of the board. The move is guaranteed
//     to be a valid move, and the two players alternate in making moves. Return:
//       - 0 if there is no winner after the move,
//       - 1 if player 1 is the winner after the move, or
//       - 2 if player 2 is the winner after the move.

class TicTacToe {
private:
    vector<vector<int>>board;
public:
    bool check(int v)
    {
        int m = board.size();
        int n = board[0].size();
        bool found = false;
        // cout << "Option1: " << endl;
        for(int i = 0; i < m; i++)
        {
            found = false;
            for(int j=0; j<n; j++)
            {
                if(board[i][j] != v)
                {
                    found = true;
                    break;
                }
            }
            if(found == false)
                return true;
        }
        // cout << "Option2: " << endl;
        found = false;
        for(int i=0; i<n; i++)
        {
            found = false;
            for(int j=0; j<m; j++)
            {
                if(board[j][i] != v)
                {
                    found = true;
                    break;
                }
            }
            if(found == false)
                return true;
        }
        // cout << "Option3: " << endl;
        int i = 0, j = 0;
        found = false;
        while(i < m && j < n)
        {
            if(board[i][j] != v)
            {
                found = true;
                break;
            }
            cout << board[i][j] << endl;
            i++;
            j++;
        }
        if(found == false)
            return true;

        // cout << "Option4: " << endl;
        i = 0, j = n-1;
        found = false;
        while(i < m && j >= 0)
        {
            if(board[i][j] != v)
            {
                found = true;
                break;
            }
            i++;
            j--;
        }
        if(found == false)
            return true;

        return false;
    }


    TicTacToe(int n) {
        board = vector<vector<int>>(n, vector<int>(n, 0));
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        // cout << "Called the player: " << player << endl;
        bool ans1 = check(player);
        if(ans1 == true)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */