/*
1. Implement a CPP program based on matrix operations and sparse matrix using OOP concepts.
 */
/*
STEPS:
    1. Take two inputs:
        a. Operations on Normal Matrices
        b. Operations on Sparse Matrices
    2. If a:
        i. Take both inputs
        ii. Ask for addition/subtraction
        iii. Convert both matrices into compact form
        iv. Operate on compact form
        v. Covert resultant into normal form
    3. If b:
        i. Take both inputs
        ii. Check isSparse() on both
        iii. If true convert both into compact
        iv. Operate on compact
        v. Check isSparse() on resultant
        vi. If True, store compact form else covert resultant into normal and store normal form.
        

    FUNCTIONS:
        1. Constructor(s)
        2. input()
        3. isSparse()
        4. makeCompact()
        5. makeNormal()
        6. operator+()
        7. operator-()
        8. Display()
*/
#include<bits/stdc++.h>
using namespace std;
class matrix{
    private:
        int **a;
        bool validSparse;
        int dimension;
        int nonzero;
        // If validSparse is true, then compact form will be stored else normal form will be stored.
    public:
        void display(){
            // If matrix is sparse, print its compact form. Else print the entire matrix.
            if(validSparse){
                // The matrix representation is in compact form.
                cout<<"Output matrix is:\n";
                // No of columns in compact form is no of non zero elements in that matrix.
                cout<<"Row ID: ";
                for(int i=0; i < nonzero; i++)
                    cout<<a[0][i]<<"\t";
                cout<<"\nCol ID: ";
                for(int i=0; i < nonzero; i++)
                    cout<<a[1][i]<<"\t";
                cout<<"\nValue: ";
                for(int i=0; i < nonzero; i++)
                    cout<<a[2][i]<<"\t";
            }
            else{
                // The matrix representation is in normal nxn form.
                cout<<"Output matrix is:\n";
                for(int i=0; i < dimension; i++){
                    for(int j=0; j < dimension; j++)
                        cout<<a[i][j]<<"\t";
                    cout<<"\n";
                }
            }
        }

        void makeCompact(int **m, int d){  // m is a 2d matrix of d x d size
            // Convert the nxn matrix into compact form.
            // If given matrix is sparse, change the matrix "a" to new compact.
            // Else keep a temporary representation because current matrix is a normal matrix and compact matrix is required just for arithmetic operations.
            int **compact = new int*[3];    // Compact form always has 3 rows.
            for(int i=0; i < 3; i++)
                compact[i] = new int[nonzero];  // No of rows = no of nonzero elements.
            
            // Iterate on each element (a[row][column]) and if non zero found, add that to compact matrix
            int temp_count = 0;
            for(int i=0; i < d; i++){
                for(int j=0; j < d; j++){
                    if(m[i][j] != 0){
                        compact[0][temp_count] = i; //ROW
                        compact[1][temp_count] = j; //COLUMN
                        compact[2][temp_count] = a[i][j];   //VALUE
                        temp_count++;
                    }
                }
            }   // Temporary compact matrix is created.
            if (validSparse)
                a = compact;

        }

        matrix operator+(matrix m);
        matrix operator-(matrix m);

        bool isSparse(){
            // For a matrix to be a sparse matrix, no of non-zero elements > (total no of elements)/2
            nonzero = 0;
            for(int i=0; i < dimension; i++)
                for(int j=0; j < dimension; j++)
                    if(a[i][j] != 0)
                        nonzero++;
            if (nonzero > (dimension*dimension)/2)
                return true;
            return false;
        }

        void input(int d, bool sparse){
            // d is the dimensions which main() will give
            // sparse will tell if this input is for a sparse matrix or a normal matrix
            a = new int*[d];
            dimension = d;
            for(int i=0; i < d; i++)
                a[i] = new int;     // Creating a dynamic 2d array.
            for(int i=0; i < d; i++)
                for(int j=0; j < d; j++){
                    cout<<"Enter element row: "<<i<<" and col: "<<j<<":\n";
                    cin>>a[i][j];
                }
            // If the input is for a sparse matrix, check if given matrix is a sparse matrix or not.
            if (sparse)
                validSparse = isSparse();
            // Else it is a normal matrix no need to check
        }

        matrix(){
            a = NULL;
            validSparse = false;    // Initially
        }
};

int main(){
    matrix m1, m2;
    // Two matrices for any operation.
    matrix result;
    // Final resultant matrix
    int c;
    while(1){
        cout<<"Enter your choice:\n";
        cout<<"1. Operation on Normal Matrices.:\n";
        cout<<"2. Operation on Sparse Matrices.:\n";
        cin>>c;
        switch(c){
            case 1:{
                int size;
                cout<<"Enter one dimension of both the square matrices:\n";
                cin>>size;
                cout<<"Enter first matrix\n";
                m1.input(size, false);  // Normal matrix = false
                cout<<"Enter second matrix\n";
                m2.input(size, false);  // Normal matrix = false
                
                // Now ask for addition/subtraction
                cout<<"Choose an operation:\n";
                cout<<"1. Addition\n2. Subtraction\n";
                cin>>c;
                if(c == 1)  //Addition
                    result = m1 + m2;
                else
                    result = m1 - m2;
                
                cout<<"The resultant matrix is:\n";
                result.display();
                break;
            }
            case 2:{
                int size;
                cout<<"Enter one dimension of both the square matrices:\n";
                cin>>size;
                cout<<"Enter first matrix\n";
                m1.input(size, true);  // Sparse matrix = true
                // Check if the given matrix is actually sparse
                if(!m1.isSparse()){
                    cout<<"The first matrix that you entered is not a valid sparse matrix.\n";
                    exit(1);
                }
                cout<<"The first matrix is:\n";
                m1.display();

                cout<<"Enter second matrix\n";
                m2.input(size, true);  // Sparse matrix = true
                // Check if the given matrix is actually sparse
                if(!m2.isSparse()){
                    cout<<"The second matrix that you entered is not a valid sparse matrix.\n";
                    exit(1);
                }
                cout<<"The second matrix is:\n";
                m2.display();

                // Now ask for addition/subtraction
                cout<<"Choose an operation:\n";
                cout<<"1. Addition\n2. Subtraction\n";
                cin>>c;
                if(c == 1)  //Addition
                    result = m1 + m2;
                else
                    result = m1 - m2;
                
                // Check if the result is a sparse matrix
                if(result.isSparse())
                    cout<<"The resultant matrix is a sparse matrix. The output will be its compact form.";
                cout<<"The resultant matrix is:\n";
                result.display();
                break;
            }
        }
    }
}

