#include <iostream>
using namespace std;


// ============================================================
// Print current array
// ============================================================
void printArray(int arr[], int left, int right)
{
    cout << "[ ";

    for(int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "]";
}


// ============================================================
// MERGE
// ============================================================
void merge(int arr[], int left, int mid, int right)
{
    cout << "\n";
    cout << "========================================\n";
    cout << "ENTER merge()\n";
    cout << "left = " << left
         << ", mid = " << mid
         << ", right = " << right << endl;

    cout << "Left part  = ";
    printArray(arr, left, mid);

    cout << "\nRight part = ";
    printArray(arr, mid + 1, right);

    cout << "\n========================================\n";


    int i = left;
    int j = mid + 1;
    int k = left;

    int temp[5];


    cout << "\nInitial variables:\n";
    cout << "i = " << i << endl;
    cout << "j = " << j << endl;
    cout << "k = " << k << endl;


    // --------------------------------------------------------
    // Compare elements from left and right parts
    // --------------------------------------------------------
    while(i <= mid && j <= right)
    {
        cout << "\nCompare:\n";
        cout << "arr[" << i << "] = " << arr[i]
             << "  VS  "
             << "arr[" << j << "] = " << arr[j] << endl;


        if(arr[i] <= arr[j])
        {
            cout << "LEFT is smaller/equal\n";
            cout << "Put " << arr[i]
                 << " into temp[" << k << "]\n";

            temp[k] = arr[i];

            i++;
        }
        else
        {
            cout << "RIGHT is smaller\n";
            cout << "Put " << arr[j]
                 << " into temp[" << k << "]\n";

            temp[k] = arr[j];

            j++;
        }

        k++;


        // Show temp
        cout << "Current temp: ";

        for(int x = left; x < k; x++)
        {
            cout << temp[x] << " ";
        }

        cout << endl;

        cout << "Now: i = " << i
             << ", j = " << j
             << ", k = " << k << endl;
    }


    // --------------------------------------------------------
    // Copy remaining elements from LEFT
    // --------------------------------------------------------
    while(i <= mid)
    {
        cout << "\nRight side finished.\n";
        cout << "Copy remaining LEFT element: "
             << arr[i]
             << " into temp[" << k << "]\n";

        temp[k] = arr[i];

        i++;
        k++;
    }


    // --------------------------------------------------------
    // Copy remaining elements from RIGHT
    // --------------------------------------------------------
    while(j <= right)
    {
        cout << "\nLeft side finished.\n";
        cout << "Copy remaining RIGHT element: "
             << arr[j]
             << " into temp[" << k << "]\n";

        temp[k] = arr[j];

        j++;
        k++;
    }


    // --------------------------------------------------------
    // Copy temp back to original array
    // --------------------------------------------------------
    cout << "\nFinal temp: ";

    for(int x = left; x <= right; x++)
    {
        cout << temp[x] << " ";
    }

    cout << endl;


    cout << "\nCopy temp back to arr...\n";


    for(int s = left; s <= right; s++)
    {
        arr[s] = temp[s];
    }


    cout << "Array after merge: ";
    printArray(arr, left, right);

    cout << "\n";

    cout << "EXIT merge()\n";
}


// ============================================================
// MERGE SORT
// ============================================================
void mergeSort(int arr[], int left, int right)
{
    cout << "\n";
    cout << "----------------------------------------\n";
    cout << "ENTER mergeSort(" << left << ", " << right << ")\n";


    // --------------------------------------------------------
    // Base case
    // --------------------------------------------------------
    if(left < right)
    {
        int mid = (left + right) / 2;


        cout << "left = " << left
             << ", right = " << right << endl;

        cout << "mid = " << mid << endl;


        cout << "Split into:\n";

        cout << "Left  : ";
        printArray(arr, left, mid);

        cout << "\nRight : ";
        printArray(arr, mid + 1, right);

        cout << "\n";


        // ----------------------------------------------------
        // Sort LEFT half
        // ----------------------------------------------------
        cout << "\n>>> Go LEFT\n";

        mergeSort(arr, left, mid);


        // ----------------------------------------------------
        // Sort RIGHT half
        // ----------------------------------------------------
        cout << "\n>>> Go RIGHT\n";

        mergeSort(arr, mid + 1, right);


        // ----------------------------------------------------
        // Merge LEFT and RIGHT
        // ----------------------------------------------------
        cout << "\n>>> MERGE LEFT + RIGHT\n";

        merge(arr, left, mid, right);
    }
    else
    {
        cout << "Base case reached.\n";
        cout << "Only one element: ";

        printArray(arr, left, right);

        cout << "\n";
    }


    cout << "EXIT mergeSort("
         << left << ", "
         << right << ")\n";

    cout << "----------------------------------------\n";
}


// ============================================================
// MAIN
// ============================================================
int main()
{
    int myarr[5] = {4, 6, 1, 2, 7};


    cout << "========================================\n";
    cout << "        MERGE SORT DEBUG VERSION\n";
    cout << "========================================\n";


    cout << "\nBefore sorting: ";

    for(int i = 0; i < 5; i++)
    {
        cout << myarr[i] << " ";
    }

    cout << "\n";


    cout << "\nStarting mergeSort...\n";


    mergeSort(myarr, 0, 4);


    cout << "\n========================================\n";
    cout << "Sorting finished!\n";
    cout << "========================================\n";


    cout << "\nAfter sorting: ";

    for(int i = 0; i < 5; i++)
    {
        cout << myarr[i] << " ";
    }

    cout << "\n";


    return 0;
}