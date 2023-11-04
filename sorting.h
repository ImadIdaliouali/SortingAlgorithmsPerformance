//* Function to swap two integers
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}

//? Bubble Sort Algorithm
void bubbleSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr + j, arr + j + 1);
        }
    }
}

//? Shell Sort Algorithm
void shellSort(int *arr, int n)
{
    int gap, i, tmp, j;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            tmp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}