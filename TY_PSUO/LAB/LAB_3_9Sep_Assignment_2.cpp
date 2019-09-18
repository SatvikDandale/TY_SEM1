/*
1. Implement a CPP program based on matrix operations and sparse matrix using OOP concepts.
 */
/*
STEPS:
    1. Take two inputs:
        a. Operations on Normal Matrices DONE
        b. Operations on Sparse Matrices DONE
    2. If a:
        i. Take both inputs DONE
        ii. Ask for addition/subtraction DONE
        iii. Add both matrices normally DONE
        iv. Return resultant which will be in normal form. DONE
    3. If b:
        i. Take both inputs DONE
        ii. Check isSparse() on both DONE
        iii. If true convert both into compact DONE
        iv. Operate on compact DONE
        v. Check isSparse() on resultant DONE
        vi. If True, store compact form else covert resultant into normal and store normal form. DONE
        

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

        int* isSparse(int **temp, int d){
            // Given is a dxd matrix. Check if it is sprase.
            // For a matrix to be a sparse matrix, no of non-zero elements > (total no of elements)/2
            int *arr = new int[2];
            arr[0] = arr[1] = 0;
            // arr[0] is nonzero count
            // arr[1] is bool isSparse()
            for(int i=0; i < d; i++)
                for(int j=0; j < d; j++)
                    if(temp[i][j] != 0)
                        arr[0]++;
            if (arr[0] > (d*d)/2)
                arr[1] = 1; //isSparse True
            else
                arr[1] = 0; //isSparse False
            return arr;
        }

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

        int** makeCompact(){
            // Convert the nxn matrix into compact form.
            // If current matrix is sparse, change the matrix "a" to new compact.
            // Else keep a temporary representation because current matrix is a normal matrix and compact matrix is required just for arithmetic operations.
            int **compact = new int*[3];    // Compact form always has 3 rows.
            for(int i=0; i < 3; i++)
                compact[i] = new int[nonzero];  // No of rows = no of nonzero elements.
            
            // Iterate on each element (a[row][column]) and if non zero found, add that to compact matrix
            int temp_count = 0;
            for(int i=0; i < dimension; i++){
                for(int j=0; j < dimension; j++){
                    if(a[i][j] != 0){
                        compact[0][temp_count] = i; //ROW
                        compact[1][temp_count] = j; //COLUMN
                        compact[2][temp_count] = a[i][j];   //VALUE
                        temp_count++;
                    }
                }
            }   // Temporary compact matrix is created.
            if (validSparse){
                // Perform a deep copy since both are pointers.
                a = new int* [3];
                for(int i=0; i<3; i++){
                    a[i] = new int [nonzero];
                    for(int j=0; j < nonzero; j++)
                        a[i][j] = compact[i][j];
                }
            }
            // Else we need not copy compact to a
            return compact;
        }

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

        matrix operator+(matrix m){
            // Before adding, check if the given matrices are in comapct form, i.e. if they are sparse matrices
            int **result;
            result = new int* [dimension];
            for(int i=0; i<dimension; i++)
                result[i] = new int(0); //Initializing result with matrix of 0s
            int nz=0;   //NONZERO COUNT
            if (!validSparse && !m.validSparse){    // Either they both will be normal or they both will be sparse.
                // Add a1 and a2
                // Make a new nxn matrix with all 0s
                for(int i=0; i < dimension; i++)
                    for(int j=0; j < dimension; j++){
                        result[i][j] = a[i][j] + m.a[i][j];
                        if (result[i][j] == 0)
                            nz++;
                    }
                // NOW ADDITION IN NORMAL FORM IS DONE.
                matrix temp(result, dimension, false, nz);
                return temp;
            }
            else{
                // Both are sparse matrices so "a" will be in compact form.
                // ADD this->a to result
                for(int i=0; i < nonzero; i++){// All the nonzero members will be added.
                    int row = a[0][i];
                    int col = a[1][i];
                    int value = a[2][i];
                    result[row][col] += value;
                }
                // ADD a2
                for(int i=0; i < nonzero; i++){// All the nonzero members will be added.
                    int row = m.a[0][i];
                    int col = m.a[1][i];
                    int value = m.a[2][i];
                    result[row][col] += value;
                }
                for(int i=0; i < dimension; i++)
                    for(int j=0; j<dimension; j++)
                        if(result[i][j] == 0)
                            nz++;
                // NOW ADDITION OF SPARSE MATRIX IS DONE.
                // Check if resultant matrix is still a sparse matrix
                int* check = isSparse(result, dimension);
                // check[0] is nz count
                // check[1] is bool isSparse
                // MAKE A NEW matrix OBJECT FROM RESULTANT MATRIX
                matrix temp(result, dimension, check[1], check[0]);
                return temp;
            }
            
        }

        matrix operator-(matrix m){
            // Before subtracting, check if the given matrices are in comapct form, i.e. if they are sparse matrices
            int **result;
            result = new int* [dimension];
            for(int i=0; i<dimension; i++)
                result[i] = new int(0); //Initializing result with matrix of 0s
            int nz=0;   //NONZERO COUNT
            if (!validSparse && !m.validSparse){    // Either they both will be normal or they both will be sparse.
                // Add a1 and a2
                // Make a new nxn matrix with all 0s
                for(int i=0; i < dimension; i++)
                    for(int j=0; j < dimension; j++){
                        result[i][j] = a[i][j] - m.a[i][j];
                        if (result[i][j] == 0)
                            nz++;
                    }
                // NOW SUBTRACTION IN NORMAL FORM IS DONE.
                matrix temp(result, dimension, false, nz);
                return temp;
            }
            else{
                // Both are sparse matrices so "a" will be in compact form.
                // SUBTRACT this->a to result
                for(int i=0; i < nonzero; i++){// All the nonzero members will be added.
                    int row = a[0][i];
                    int col = a[1][i];
                    int value = a[2][i];
                    result[row][col] -= value;
                }
                // SUBTRACT a2
                for(int i=0; i < nonzero; i++){// All the nonzero members will be added.
                    int row = m.a[0][i];
                    int col = m.a[1][i];
                    int value = m.a[2][i];
                    result[row][col] -= value;
                }
                for(int i=0; i < dimension; i++)
                    for(int j=0; j<dimension; j++)
                        if(result[i][j] == 0)
                            nz++;
                // NOW SUBTRACTION OF SPARSE MATRIX IS DONE.
                // Check if resultant matrix is still a sparse matrix
                int* check = isSparse(result, dimension);
                // check[0] is nz count
                // check[1] is bool isSparse
                // MAKE A NEW matrix OBJECT FROM RESULTANT MATRIX
                matrix temp(result, dimension, check[1], check[0]);
                return temp;
            }
            
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
            if (sparse){
                if(isSparse()){ // User entered sparse matrix
                    // Convert to compact
                    makeCompact();
                    validSparse = true;
                }
            }
            // Else it is a normal matrix no need to check
        }

        matrix(){
            a = NULL;
            validSparse = false;    // Initially
        }
        matrix(int **m, int d, bool sparse, int nz){    //PARAMETERIZED CONSTRUCTOR
            // Given a matrix, if it is a sparse, given array will be compact matrix.
            // Else it will be a normal matrix.
            // nz is no of nonzero elements
            if(sparse){
                a = new int* [3];
                for(int i=0; i<3; i++){
                    a[i] = new int[nz];
                    for(int j=0; j<nz; j++)
                        a[i][j] = m[i][j];  // DEEP COPY
                }
            }
            else{
                a = new int* [d];
                for(int i=0; i<d; i++){
                    a[i] = new int [d];
                    for(int j=0; j<d; j++)
                        a[i][j] = m[i][j];  // DEEP COPY
                }
                // Finally, check if this matrix is a sparse.
                if(isSparse()){
                    // This matrix can be converted into compact
                    makeCompact();
                }
            }
            nonzero = nz;
            dimension = d;
            validSparse = sparse;
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

