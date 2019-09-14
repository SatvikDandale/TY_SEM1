/*
Take a matrix in which 1's will represent the position of queen.
No two queens shall have a common row, column, or a diagonal.
Use recursive backtracking algorithm

NOTE: THE COORDINATES USED IN MATRICES ARE: matrix[y][x]: y is the row and x is the column

*/
#include<bits/stdc++.h>
using namespace std;

#define n 6

class n_queen{

private:
	int matrix[n][n];
public:
	void printMatrix(){
		// DISPLAY FUNCTION
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				cout<<matrix[i][j]<<"\t";
			cout<<endl;
		}
	}

	n_queen(){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				matrix[i][j] = 0;
	}

	bool checkRow(int row){
		// Returns true if another queen found
		for(int i=0; i<n; i++)
			if(matrix[row][i] == 1)
				return true;
		return false;
	}
	bool checkColumn(int col){
		// Returns true if another queen found
		for(int i=0; i<n; i++)
			if(matrix[i][col] == 1)
				return true;
		return false;
	}
	bool checkDiagonals(int row, int col){
		// returns true if another queen is found in any of the diagonal passing through the given point
		// Top Left
		for(int i=row; i>=0; i--){
			for(int j=col; j>=0; j--){
				if(i>0 && j>0){
					if(matrix[i-1][j-1] == 1)
						return true;
				}
				else
					break;
				i--;
			}
		}

		// Top right
		for(int i=row; i>=0; i--){
			for(int j=col; j<n; j++){
				if(i>0 && j<n-1){
					if(matrix[i-1][j+1] == 1)
						return true;
				}
				else
					break;
				i--;
			}
		}		

		// Bottom Left
		for(int i=row; i<n; i++){
			for(int j=col; j>=0; j--){
				if(i<n-1 && j>0){
					if(matrix[i+1][j-1] == 1)
						return true;
				}
				else
					break;
				i++;
			}
		}	

		// Bottom Right
		for(int i=row; i<n; i++){
			for(int j=col; j<n; j++){
				if(i<n-1 && j<n-1){
					if(matrix[i+1][j+1] == 1)
						return true;
				}
				else
					break;
				i++;
			}
		}

		return false;
	}

	bool startPlacing(int queen){
		// Backtracking
		// Use recurssion to place queens.
		/*
			Place a queen
			Call next recurssion for queen 2
			For queen 2: Check all rows. If a valid row is found, check column and so on.
			If valid position is found, place the queen 2 and recurssively call next func for queen 3
			If valid position not found, return False for queen 2.
		*/
		cout<<"QUEEN: "<<queen<<endl;
		// FOR EACH ROW
		for(int i=0; i<n; i++){// Rows
			// CHECK ROW

			if(!checkRow(i)){
				cout<<"ROW: "<<i<<endl;
				// FOR EACH COLUMN

				for(int j=0; j<n; j++){// Columns
					// CHECK COLUMN

					if(!checkColumn(j)){
						cout<<"COL: "<<j<<endl;
						// CHECK DIAGONAL

						if(!checkDiagonals(i, j)){
							cout<<"I: "<<i<<endl;
							cout<<"J: "<<j<<endl;
							cout<<"Q: "<<queen<<endl;

							matrix[i][j] = 1;
							
							printMatrix();
							if(i<n && j<n && queen<n){
								if(startPlacing(queen+1)){
									return true;
								}else{
									// FUTURE CASES ARE NOT POSSIBLE
									matrix[i][j] = 0;
									continue;
								}
							}
							else
								return true;
						}// DIAGONAL CHECKING ENDS
					}// COLUMN CHECKING ENDS
				}// COLUMNS LOOP

			}// ROW CHECKING ENDS

		}// ROWS LOOP
		return false;
	}

};

int main(){
	n_queen m1;
	//cout<<m1.checkDiagonals(0, 0);
	//cout<<m1.checkColumn(1);
	m1.startPlacing(1);

}