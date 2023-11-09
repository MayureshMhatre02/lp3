#include <iostream>

using namespace std;

bool isSafe(int queens[], int row, int col, int N) {
  for (int i = 0; i < row; i++) {
    if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
      return false;
    }
  }
  return true;
}

void printQueens(int queens[], int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (queens[i] == j) {
        cout << "Q ";
      } else {
        cout << ". ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void solveNQueens(int queens[], int row, int N, int& count) {
  if (row == N) {
    // All queens are placed, print the solution and increment the count
    printQueens(queens, N);
    count++;
  } else {
    for (int col = 0; col < N; col++) {
      if (isSafe(queens, row, col, N)) {
        queens[row] = col;
        solveNQueens(queens, row + 1, N, count);
      }
    }
  }
}

int main() {
  int N;
  cout << "Enter the number of queens (N): ";
  cin >> N;

  int queens[N];
  for (int i = 0; i < N; i++) {
    queens[i] = -1;
  }

  int count = 0;
  solveNQueens(queens, 0, N, count);
  cout << "Total number of solutions: " << count << endl;

  return 0;
}


