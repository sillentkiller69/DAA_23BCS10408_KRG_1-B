#include<bits/stdc++.h>
using namespace std;

// Define the size of the Sudoku board
const int N = 9;
const int UNASSIGNED = 0;

// Utility function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if(col==3||col==6) cout << "| "; 
            cout << board[row][col] << " ";
        }
        cout << endl;
        if(row==2||row==5) cout << "------+------+-------" << endl;
    }
    cout << endl;
}

// Check if a number is safe to place in the cell
bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }
    // Check the column
    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }
    // Check the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Recursive backtracking function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>>& board) {
    int row, col;
    bool emptyCell = false;

    // Find an unassigned (empty) cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == UNASSIGNED) {
                emptyCell = true;
                break;
            }
        }
        if (emptyCell) break;
    }

    // No empty cells means the puzzle is solved
    if (!emptyCell) {
        return true;
    }

    // Try placing numbers 1-9 in the current cell
    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            // Backtrack if placing num does not lead to a solution
            board[row][col] = UNASSIGNED;
        }
    }
    return false; // Trigger backtracking
}

// Function to check if the Sudoku puzzle is solved
bool isSolved(const vector<vector<int>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == UNASSIGNED) {
                return false;
            }
        }
    }
    return true;
}

// Function to generate a partially filled Sudoku board
void generateSudoku(vector<vector<int>>& board) {
    // Fill diagonal 3x3 subgrids to ensure a valid puzzle structure
    for (int i = 0; i < N; i += 3) {
        for (int row = i; row < i + 3; row++) {
            for (int col = i; col < i + 3; col++) {
                int num;
                do {
                    num = rand() % 9 + 1; // Random number between 1 and 9
                } while (!isSafe(board, row, col, num));
                board[row][col] = num;
            }
        }
    }
    // Solve the board using the backtracking algorithm
    solveSudoku(board);

    // Remove random elements to create a solvable puzzle
    int removeCount = 40; // Number of cells to remove
    while (removeCount > 0) {
        int row = rand() % N;
        int col = rand() % N;
        if (board[row][col] != UNASSIGNED) {
            board[row][col] = UNASSIGNED;
            removeCount--;
        }
    }
}

// Main function to run the game
int main() {
    srand(time(0)); // Initialize random seed

    // Initialize the Sudoku board with zeros (empty cells)
    vector<vector<int>> board(N, vector<int>(N, UNASSIGNED));

    // Generate a Sudoku puzzle
    generateSudoku(board);

    cout << "Generated Sudoku Puzzle:" << endl;
    printBoard(board);

    char choice;
    do {
        cout << "Options: " << endl;
        cout << "1. Solve the puzzle automatically" << endl;
        cout << "2. Enter your solution" << endl;
        cout << "Enter option (1 or 2): ";
        cin >> choice;

        if (choice == '1') {
            // Solve the puzzle automatically using backtracking
            if (solveSudoku(board)) {
                cout << "Solved Sudoku Puzzle:" << endl;
                printBoard(board);
            } else {
                cout << "No solution exists." << endl;
            }
        } else if (choice == '2') {
            int row, col, num;
            cout << "Enter row (1-9), column (1-9), and number (1-9) to insert: ";
            cin >> row >> col >> num;

            if (isSafe(board, row - 1, col - 1, num)) {
                board[row - 1][col - 1] = num;
                cout << "Updated Sudoku Puzzle:" << endl;
                printBoard(board);
            } else {
                cout << "Invalid move. Try again." << endl;
            }

            if (isSolved(board)) {
                cout << "Congratulations! You solved the Sudoku puzzle!" << endl;
                break;
            }
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    } while (true);

    return 0;
}