//{ Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    void insert(int arr[], int i)
    {
        // code here
        while (i > 0 && arr[i - 1] > arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
        }
    }

public:
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        // code here

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
                insert(arr, i);
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int arr[1000], n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.insertionSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends