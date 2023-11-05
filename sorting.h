int *copyArray(int *, int, int);

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
    int i, j;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr + j - 1, arr + j);
            j--;
        }
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
    int gap, i, j;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            j = i;
            while (j >= gap && arr[j - gap] > arr[j])
            {
                swap(arr + j - gap, arr + j);
                j -= gap;
            }
        }
    }
}

void merge(int *arr, int low, int middle, int high)
{
    int lSize = middle - low + 1;
    int rSize = high - middle;
    int *leftArr = copyArray(arr, low, middle);
    int *rightArr = copyArray(arr, middle + 1, high);
    int i = 0, j = 0, k = low;

    while (i < lSize && j < rSize)
        arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];

    while (i < lSize)
        arr[k++] = leftArr[i++];

    while (j < rSize)
        arr[k++] = rightArr[j++];
}

void mergeSortRecursive(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int middle = (low + high) / 2;
    mergeSortRecursive(arr, low, middle);
    mergeSortRecursive(arr, middle + 1, high);
    merge(arr, low, middle, high);
}

//? Merge Sort Algorithm
void mergeSort(int *arr, int n)
{
    mergeSortRecursive(arr, 0, n - 1);
}