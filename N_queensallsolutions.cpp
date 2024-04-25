#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing a queen at position (row, col) is safe
bool isSafe(vector<int>& board, int row, int col) {
    // Check all previous columns for conflicts
    for (int i = 0; i < col; ++i) {
        // If there is a queen in the same row or in the same diagonal, return false
        if (board[i] == row || abs(board[i] - row) == col - i)
            return false;
    }
    // If no conflicts found, return true
    return true;
}

// Recursive function to solve the N-Queens problem using backtracking
void solveQueens(vector<int>& board, int col, vector<vector<int>>& solutions) {
    int n = board.size();
    // Base case: If all queens are placed successfully, add the solution to the solutions vector
    if (col == n) {
        solutions.push_back(board);
        return;
    }
    // Try placing a queen in each row of the current column
    for (int i = 0; i < n; ++i) {
        // Check if it's safe to place a queen at position (i, col)
        if (isSafe(board, i, col)) {
            // Place the queen and recursively solve for the next column
            board[col] = i;
            solveQueens(board, col + 1, solutions);
        }
    }
}

// Function to print a single solution (one configuration of queens on the board)
void printSolution(const vector<int>& board) {
    int n = board.size();
    // Iterate through each row and column of the board
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Print 'Q' if there is a queen at position (i, j), otherwise print '.'
            if (board[j] == i) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl; // Empty line to separate solutions
}

// Function to print all possible solutions for the N-Queens problem
void printAllSolutions(int n) {
    vector<int> board(n); // Initialize an empty board
    vector<vector<int>> solutions; // Vector to store all solutions
    solveQueens(board, 0, solutions); // Call the recursive function to solve the problem
    // Check if any solutions were found
    if (solutions.empty()) {
        cout << "No solutions found." << endl;
    } else {
        cout << "All possible solutions:" << endl;
        // Iterate through each solution and print it
        for (const auto& sol : solutions) {
            printSolution(sol);
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (n x n): ";
    cin >> n;
    printAllSolutions(n); // Print all solutions for the given board size
    return 0;
}



//Explanation of the approach:
//
//isSafe(): This function checks if placing a queen at position (row, col) is safe. It iterates through all previous columns and checks for conflicts with queens placed in those columns.
//solveQueens(): This is a recursive function that tries to place queens on the board, column by column. It backtracks if a safe position cannot be found for a queen in the current column.
//printSolution(): This function prints a single solution (one configuration of queens on the board) in a human-readable format.
//printAllSolutions(): This function initializes an empty board and a vector to store solutions. It calls the solveQueens() function to find all solutions, and then prints them one by one.
//main(): This function prompts the user to enter the size of the chessboard and then prints all possible solutions for that board size.