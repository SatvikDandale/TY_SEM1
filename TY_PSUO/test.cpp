#include<bits/stdc++.h>
using namespace std;

int main(){

	int **a;
	int n=3;
	// Create 3x3 matrix using calloc
	a = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++){
		a[i] = (int*)calloc(n, sizeof(int));
	}
	a[0][1] = a[1][2] = 1;
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++)
			cout<<a[i][j]<<"\t";
		cout<<"\n";
	}

}