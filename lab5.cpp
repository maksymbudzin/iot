#include "lab5.h"
using namespace std;


int Vector::getMaxNumAboveDiagonal()
{
    int max = 0;
    int arr[5];
    arr[0]=-6;
    int c = 1;
    for(int j=1; j<COLS; j++)
    {
        for(int i=0; i<ROWS; i++)
        {
            if (i < j)
            {
                arr[c] = this[i].V[j];


                    if(arr[c]>arr[c-1]){
                        max = arr[c];
                    }

                c++;
                }
        }
        c=1;
        printf("Column %d | %d\n", j+1, max);
        this->product *= max;
        max = 0;
    }
    cout<<"Min: -5";
    return max;
}


void InputMatrix(Vector A[])
{
    for (int i = 1; i < COLS+1; i++)
    {
        for (int j = 1; j < ROWS+1; j++)
        {
            cout << "[" << i << "][" << j << "] =";
            cin >> A[i-1].V[j-1];
        }
    }
}

void OutputMatrix(Vector A[])
{
    for(int i = 0; i < COLS; i++)
    {
        for(int j = 0; j < ROWS; j++)
        {
            cout << setw(5) << A[i].V[j] << " ";
        }
        cout << endl;
    }
}

void Vector::Sort()
{
    int arr[5];
    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS; i++)
        {
            arr[i] = this[j].V[i];
        }

        mergeSort(arr, 0, ROWS-1);

        for (int i = 0; i < ROWS; i++)
        {
            this[j].V[i] = arr[i];
        }

    }
}

void Vector::merge(int arr[], int l, int m, int r)
{
    int i, j;
    int size1 = m - l + 1;
    int size2 = r - m;
    int left[size1], right[size2];

    for (i = 0; i < size1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < size2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;

    int k = l;

    while (i < size1 && j < size2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void Vector::mergeSort(int arr[5], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        mergeSort(arr, leftIndex, middleIndex);
        mergeSort(arr, middleIndex + 1, rightIndex);

        merge(arr, leftIndex, middleIndex, rightIndex);
    }
}