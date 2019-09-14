#include<bits/stdc++.h>
using namespace std;

void INSERTION(int *a, int n, int *count)
{
		// This function will not return anything. It will change the array whose address was given.
        int i, h, temp;
        for(i=1; i<n; i++)
        {
            temp = *(a + i);
            h = i;
            *count += 1;
            while(h>0 && *(a + (h-1))>temp)
            {
                *count += 1;
                *(a + h) = *(a + (h-1));
                h--;
            }
            *(a + h) = temp;
        }
}


void SWAP(int *a, int *b)
{
    int t;
    t = *b;
    *b = *a;
    *a = t;
}

int PARTITION(int *a, int l, int h, int *count)
{
    int i;
    int pivot = *(a + h);       //The pivot element is set to the last element of the array
    int p_index = l;
    for(i=l; i<h; i++)
    {
        *count += 1;
        if(*(a + i) <= pivot)
        {
            SWAP((a + i), (a + p_index));
            p_index++;
        }
    }
    SWAP((a + p_index), (a + h));     //Here *(a + h) element is the pivot element.
    return p_index;

}

void QUICKSORT(int *a, int l, int h, int *count)
{
    if(l<h)
    {
        int p_index = PARTITION(a, l, h, count);
        QUICKSORT(a, l, p_index-1, count);
        QUICKSORT(a, p_index+1, h, count);
    }

}

void printArray(int *a, int l)
{
    for(int i=0; i<l; i++)
        cout<<*(a + i)<<" ";
    cout<<"\n";
}

int main()
{

    // Unsorted array:
    int unsorted[] = {2, 3, 1, 9, 4, 0, 6, 8, 10, -1};
    int l1 = sizeof(unsorted)/sizeof(int);
    // Sorted array:
    int sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int l2 = sizeof(sorted)/sizeof(int);
    // Array of single element
    int unique[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int l3 = sizeof(unique)/sizeof(int);

    // QUICKSORT

    // Unsorted
    int count = 0;
    int *copy1 = unsorted;
    cout<<"Array before sorting is\n";
    printArray(copy1, l1);
    QUICKSORT(copy1, 0, l1-1, &count);
    cout<<"Array after sorting is\n";
    printArray(copy1, l1);
    cout<<"The no of comparisons for QUICKSORT on Unsorted array is: "<<count<<"\n\n";
    count = 0;

    // Sorted
    int *copy2 = sorted;
    cout<<"Array before sorting is\n";
    printArray(copy2, l2);
    QUICKSORT(copy2, 0, l2-1, &count);
    cout<<"Array after sorting is\n";
    printArray(copy2, l2);
    cout<<"The no of comparisons for QUICKSORT on Sorted array is: "<<count<<"\n\n";
    count = 0;

    // Unique array
    int *copy3 = unique;
    cout<<"Array before sorting is\n";
    printArray(copy3, l3);
    QUICKSORT(copy1, 0, l3-1, &count);
    cout<<"Array after sorting is\n";
    printArray(copy3, l3);
    cout<<"The no of comparisons for QUICKSORT on Unique array is: "<<count<<"\n\n";
    count = 0;

    // ##############################################

    // Unsorted array:
    int unsorted1[] = {2, 3, 1, 9, 4};//, 0, 6, 8, 10, -1};
    l1 = sizeof(unsorted1)/sizeof(int);
    // Sorted array:
    int sorted1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l2 = sizeof(sorted1)/sizeof(int);
    // Array of single element
    int unique1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    l3 = sizeof(unique1)/sizeof(int);

    // INSERTION SORT

    // Unsorted
    count = 0;
    copy1 = unsorted1;
    cout<<"Array before sorting is\n";
    printArray(copy1, l1);
    INSERTION(copy1, l1, &count);
    cout<<"Array after sorting is\n";
    printArray(copy1, l1);
    cout<<"The no of comparisons for INSERTION on Unsorted array is: "<<count<<"\n\n";
    count = 0;

    // Sorted
    copy2 = sorted1;
    cout<<"Array before sorting is\n";
    printArray(copy2, l2);
    INSERTION(copy2, l2, &count);
    cout<<"Array after sorting is\n";
    printArray(copy2, l2);
    cout<<"The no of comparisons for INSERTION on Sorted array is: "<<count<<"\n\n";
    count = 0;

    // Unique array
    copy3 = unique1;
    cout<<"Array before sorting is\n";
    printArray(copy3, l3);
    INSERTION(copy1, l3, &count);
    cout<<"Array after sorting is\n";
    printArray(copy3, l3);
    cout<<"The no of comparisons for INSERTION on Unique array is: "<<count<<"\n\n";
    count = 0;


    /*

    int n, i;
    printf("Enter the number of elements in your array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter your array:\n");
    for(i=0; i<n; i++)
    {
        printf("Element no %d: ", i+1);
        scanf("%d", (a + i));
    }
    INSERTION(a, n);
    printf("\nThe sorted array is:\n");
    for(i=0; i<n; i++)
        printf("%d\t", *(a + i));

    */
}
