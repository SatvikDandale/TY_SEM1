/*
    CPP Program to count the number of inversions present in an array using merge sort.
*/
#include<bits/stdc++.h>
using namespace std;

int merge(int *a, int *t, int l, int m, int h, int count){
    int i = l, k = l, j = m+1;
    cout<<"LEFT:\n";
    for(int s=l; s<m; s++)
        cout<<a[s]<<"\t";
    cout<<"\nRight:\n";
    for(int s=m; s<=h; s++)
        cout<<a[s]<<"\t";
    cout<<endl;

    while(i <= m && j <= h){    // Comparing two sub arrays
        if(a[i] <= a[j])
            t[k++] = a[i++];
        else{
            // a[i] > a[j]
            t[k] = a[j];
            // We can say that all the elements from i to m are greater than a[j] because they are sorted.
            cout<<"Inversion pair found when: "<<a[i]<<" > "<<a[j]<<endl;
            cout<<"Count is: ";
            cout<<"Before adding: "<<count<<endl;
            cout<<"Actual current count: "<<(m - i + 1)<<endl;
            count += (m - i + 1);
            cout<<"After adding: "<<count<<endl;
            k++;
            j++;
        }
    }
    // Copy remaining left subarray
    while(i <= m)
        t[k++] = a[i++];
    
    // Copy remaining right subarray
    while(j <= h)
        t[k++] = a[j++];

    // Copy the entire temp array to original array
    for(i=l; i <= h; i++)
        a[i] = t[i];
    
    return count;
}

int mergeSort(int *arr, int *t, int l, int h){
    int count = 0;
    if (h > l){
        int m = (l+h)/2;
        count += mergeSort(arr, t, l, m);    // Left subarray
        cout<<"Count initially: "<<count<<endl;
        count += mergeSort(arr, t, m+1, h);     // Right subarray
        cout<<"Count after 1st MS: "<<count<<endl; 

        // Merge the two subarrays
        count += merge(arr, t, l, m, h, count);
    }
    return count;
}


int main(){
    int *arr;
    int n;
    cout<<"Enter the length of the array:\n";
    cin>>n;
    // Allocate the size
    arr = new int [n];
    cout<<"Enter the elements of the array:\n";
    for(int i=0; i < n; i++){
        cout<<"Enter element no. "<<i+1<<" : ";
        cin>>arr[i];
    }
    // Before calling mergeSort, create a temp array of size n
    int *t = new int [n];
    int inversion_count = mergeSort(arr, t, 0, n-1);    // n-1 is the last index of the array
    cout<<"The number of inversion pairs are: "<<inversion_count<<endl;

    cout<<"ARRAY AFTER SORTING:\n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}