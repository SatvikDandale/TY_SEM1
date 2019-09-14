/*
A graph is given. There are vertices and edges.
We have to color each vertex such that no two adjacent vertices have the same color.
Use backtracking algortihm to progressively solve this problem.
*/
#include<bits/stdc++.h>
using namespace std;

class m_color{

private:
	int n; // No of vertices in the graph
	int **adjacents;	// Adjacency matrix
	int *colors;	// Store the color ID of each vertex.
public:
	m_color(int v){
		// v is the no of vertices in the graph
		n = v;
		// Dynamic allocation.
		colors = (int*)calloc(n, sizeof(int));
		adjacents = new int*[n];
		for(int i=0; i<n; i++)
			adjacents[i] = new int[n];
	}
	void display(){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<adjacents[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
	void init_graph(){
		// This function will take the input of all the parameters needed for the graph
		// and will initialize the adjacency matrix.
		int temp = 0;
		int vid = 0;
		cout<<"The no of vertices are: "<<n<<endl;
		for(int i=0; i<n; i++){
			cout<<"For vertex "<<i<<", Enter the no of adjacent vertices: \n";
			cin>>temp;
			cout<<"For the same vertex, enter the IDs of all the adjacent vertices one by one:\n";
			for(int j=0; j<temp; j++){
				cin>>vid;
				adjacents[i][vid] = 1;
			}
		}
	}

	// Recursive function to assign colors to each vertex.
	bool add_Colors(int v){	
		/* v is the current vertex number and cid is the color id
		This function will return true if the color is successively placed in all the future cases.
		Else will return false.*/

		while(1){

		}
		// First check if this cid is valid for this v
		for(int i=0; i<=v; i++){
			// For all vertices before 'v' take all adjacents
			if(adjacents[v][i] == 1){
				// Check if this adjacent has the same color
				if(colors[i] == cid){
					// This cid cannot be marks to 'v'
					return false;
				}
				else{
					colors[v] = cid;
					// Now check for future cases
					if (v < n-1){
						if(add_Colors(v+1))
							break;
						else{}
					}
				}
			}
		}

		// For this CID, check if all the future cases can be solved in minimum colors.


		return false;	// If the function reaches end, it means that the current color cannot be placed at that vertex.
	}

};

int main(){
	cout<<"HI\n";
	int v = 0;
	cout<<"Enter the number of vertices:\n";
	cin>>v;
	m_color g1(v);
	g1.init_graph();
	g1.display();
}