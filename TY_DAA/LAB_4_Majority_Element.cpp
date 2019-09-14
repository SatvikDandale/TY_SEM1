/*

	Use Divide and Conquor:
	Two functions:
		1. split(int *array, intl, int h)
			split the array.
			take occurances 
			return majority element of current subarray
		2. ret_max
			take the majority element of two arrays
			return the element whos occurence is more

*/

#include<bits/stdc++.h>
using namespace std;

class majority_element{
	private:
		int *main_array;
		int length;
	public:
		void get_input(){
			cout<<"Enter the no of elments\n";
			cin>>length;
			cout<<"Enter the array:\n";
			main_array = new int[length];
			for(int i=0; i<length; i++){
				cout<<"Enter element no: "<<i+1<<":\n";
				cin>>main_array[i];
			}
		}
		majority_element(){
			get_input();
		};

		int ret_max(int *left, int *right){
			/*
				We want return the reference to the majority element whose occrance is more
				1: left subarray
				2: right subarray
			*/
			if (left[1] > right[1])
				return 1;
			return 2;
		}

		int* split(int *array, int l, int h){
			// Check for single element first
			if (l == h){
				int *temp = new int[2];
				temp[0] = array[l];
				temp[1] = 1;
				return temp;
			}
			else{
				int m = (l+h)/2;
				int *left, *right;
				left = split(array, l, m);
				right = split(array, m+1, h);
				int major = ret_max(left, right);
				/*
					If we get 1:
						Search left[0] in current array from m+1 to h
						Add left[1] to it.
					Else
						Search right[0] in current array from l to m
						Add right[1] to it.
				*/
				int *temp = new int[2];
				int new_occurs = 0;
				if (major == 1){
					// We already have the occurance in left subarray
					// Calculate in right subarray
					for(int i=m+1; i<=h; i++)
						if (array[i] == left[0])
							new_occurs++;
					new_occurs += left[1];
					//While returning, we have to return majot element from left array
					temp[0] = left[0];
				}
				else{
					// We already /have the occurance in right subarray
					// Calculate in left subarray
					for(int i=0; i<m; i++)
						if(array[i] == right[0])
							new_occurs++;
					new_occurs += right[1];
					//While returning, we have to return majot element from right array
					temp[0] = right[0];
				}
				// Now check if the new_occurs >= current_len/2
				int len = h-l+1;
				//LEFT
				cout<<"\nLEFT:\n";
				for(int i=l; i<=m; i++)
					cout<<array[i];
				//RIGHT
				cout<<"\nRIGHT:\n";
				for(int i=m+1; i<=h; i++)
					cout<<array[i];
				cout<<"\n";
				if(new_occurs >= len/2){
					if(major == 1)
						temp[1] = new_occurs;
					else
						temp[1] = new_occurs;
					cout<<"O: "<<new_occurs<<endl;
					cout<<"L: "<<left[0];
					cout<<" R: "<<right[0]<<endl;
					return temp;
				}
			}
		}
		void split_utility(){
			int *final_majority_element = split(main_array, 0, length-1);
			cout<<"The majority element is: "<<final_majority_element[0]<<"\nAnd the no of occurances are: "<<final_majority_element[1]<<endl;
		}

};

int main(){
	majority_element *m = new majority_element();
	m->split_utility();

}