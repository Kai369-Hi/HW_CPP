#include <iostream>
using namespace std;


// ============================================================
// SWAP
// ============================================================
void swap(int &a, int &b)
{
    cout << "    SWAP: " << a << " <-> " << b << endl;

    int temp = a;
    a = b;
    b = temp;
}


// ============================================================
// PRINT ARRAY
// ============================================================
void printArray(int arr[], int start, int end)
{
    cout << "[ ";

    for(int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "]";
}


// ============================================================
// PARTITION
// ============================================================
int Partition(int arr[], int start, int end)
{
    cout << "\n";
    cout << "========================================\n";
    cout << "ENTER Partition()\n";

    cout << "start = " << start << endl;
    cout << "end   = " << end << endl;


    // --------------------------------------------------------
    // Choose pivot
    // --------------------------------------------------------
    int pivot = arr[end];

    cout << "pivot = arr[" << end << "] = "
         << pivot << endl;


    int pIndex = start;

    cout << "Initial pIndex = "
         << pIndex << endl;


    cout << "Array before partition: ";
    printArray(arr, start, end);
    cout << endl;


    // --------------------------------------------------------
    // Loop through the array
    // --------------------------------------------------------
    for(int i = start; i < end; i++)
    {
        cout << "\n----------------------------------------\n";

        cout << "i = " << i << endl;

        cout << "arr[" << i << "] = "
             << arr[i] << endl;

        cout << "pivot = "
             << pivot << endl;


        // ----------------------------------------------------
        // Compare arr[i] with pivot
        // ----------------------------------------------------
        if(arr[i] <= pivot)
        {
            cout << "Condition: "
                 << arr[i]
                 << " <= "
                 << pivot
                 << " -> TRUE" << endl;


            cout << "Swap arr[" << i << "] with "
                 << "arr[" << pIndex << "]"
                 << endl;


            swap(arr[i], arr[pIndex]);


            cout << "Array after swap: ";
            printArray(arr, start, end);
            cout << endl;


            pIndex++;

            cout << "pIndex increased to "
                 << pIndex << endl;
        }
        else
        {
            cout << "Condition: "
                 << arr[i]
                 << " <= "
                 << pivot
                 << " -> FALSE" << endl;


            cout << "No swap." << endl;

            cout << "pIndex stays at "
                 << pIndex << endl;
        }
    }


    // --------------------------------------------------------
    // Put pivot into its correct position
    // --------------------------------------------------------
    cout << "\n----------------------------------------\n";

    cout << "Loop finished." << endl;

    cout << "Final pIndex = "
         << pIndex << endl;


    cout << "Now swap pivot with arr[pIndex]."
         << endl;

    cout << "Swap arr[" << pIndex << "] = "
         << arr[pIndex]
         << " with arr[" << end << "] = "
         << arr[end]
         << endl;


    swap(arr[pIndex], arr[end]);


    cout << "Array after placing pivot: ";
    printArray(arr, start, end);
    cout << endl;


    cout << "Pivot " << pivot
         << " is now at index "
         << pIndex << endl;


    cout << "EXIT Partition()\n";
    cout << "========================================\n";


    return pIndex;
}


// ============================================================
// QUICK SORT
// ============================================================
void QuickSort(int arr[], int start, int end)
{
    cout << "\n";
    cout << "----------------------------------------\n";

    cout << "ENTER QuickSort("
         << start
         << ", "
         << end
         << ")\n";


    // --------------------------------------------------------
    // Check whether we need to sort
    // --------------------------------------------------------
    if(start < end)
    {
        cout << "start < end -> TRUE" << endl;

        cout << "Current part: ";
        printArray(arr, start, end);
        cout << endl;


        // ----------------------------------------------------
        // Partition
        // ----------------------------------------------------
        cout << "\n>>> Calling Partition()\n";


        int p = Partition(arr, start, end);


        cout << "\nPartition returned p = "
             << p << endl;


        cout << "Array after Partition: ";
        printArray(arr, start, end);
        cout << endl;


        // ----------------------------------------------------
        // Sort LEFT side
        // ----------------------------------------------------
        cout << "\n>>> Sort LEFT side\n";

        cout << "QuickSort("
             << start
             << ", "
             << p - 1
             << ")\n";


        QuickSort(arr, start, p - 1);


        // ----------------------------------------------------
        // Sort RIGHT side
        // ----------------------------------------------------
        cout << "\n>>> Sort RIGHT side\n";

        cout << "QuickSort("
             << p + 1
             << ", "
             << end
             << ")\n";


        QuickSort(arr, p + 1, end);
    }
    else
    {
        cout << "start < end -> FALSE" << endl;

        cout << "No sorting needed." << endl;

        if(start == end)
        {
            cout << "Only one element: "
                 << arr[start]
                 << endl;
        }
        else
        {
            cout << "Empty range." << endl;
        }
    }


    cout << "EXIT QuickSort("
         << start
         << ", "
         << end
         << ")\n";

    cout << "----------------------------------------\n";
}


// ============================================================
// MAIN
// ============================================================
int main()
{
    int len = 5;

    int myarr[5] = {4, 6, 1, 2, 7};


    cout << "========================================\n";
    cout << "       QUICK SORT DEBUG VERSION\n";
    cout << "========================================\n";


    cout << "\nBefore sorting: ";

    for(int i = 0; i < len; i++)
    {
        cout << myarr[i] << " ";
    }

    cout << endl;


    // --------------------------------------------------------
    // Start Quick Sort
    // --------------------------------------------------------
    cout << "\n>>> START QUICK SORT\n";


    QuickSort(myarr, 0, len - 1);


    // --------------------------------------------------------
    // Final result
    // --------------------------------------------------------
    cout << "\n========================================\n";
    cout << "       SORTING FINISHED\n";
    cout << "========================================\n";


    cout << "\nAfter sorting: ";

    for(int i = 0; i < len; i++)
    {
        cout << myarr[i] << " ";
    }

    cout << endl;


    return 0;
}