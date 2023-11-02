//* Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//? Selection Sort Algorithm
void selectionSort(int *arr, int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        if (i != minIndex)
            swap(arr + i, arr + minIndex); //? swap(&arr[i], &arr[minIndex]);
    }
}

//? Insertion Sort Algorithm
void insertionSort(int *arr, int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}