

// 选择排序
void selectSort() {
    for (int i = 1; i <= n; ++i) {
        int k = i;
        for (int j = i; j <= n; ++j) {
            if (A[j] < A[k]) {
                k = j;
            }
        }

        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

// 插入排序
void insertSort() {
    for (int i = 2; i <= n; ++i) {
        int temp = A[i], j = i;
        while (j > 1 && temp < A[j - 1]) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}

// 归并排序
int maxn = 100;

void merge(int A[], int L1, int R1, int L2, int R2) {
    int i = L1, j = L2;
    int temp[maxn], index = 0;
    while (i <= R1 && j << R2) {
        if (A[i] <= A[j]) {
            temp[index++] = A[i++];
        } else {
            temp[index++] = A[j++];
        }
    }
    while (i <= R1) temp[index++] = A[i++];
    while (j <= R2) temp[index++] = A[j++];
    for (int i = 0; i < index; ++i) {
        A[L1 + i] = temp[i];
    }
}

void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, mid + 1, right);
    }
}


// 快速排序
int Partition(int A[], int left, int right) {
    int temp = A[left];
    while (left < right) {
        while (left < right && A[right] > temp) right--;
        A[left] = A[right];
        while (left < right && A[left] <= temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[], int left, int right) {
    if (left < right) {
        itn pos = Partition(A, left, right);
        quickSort(A, left, pos - 1);
        quickSort(A, pos + 1, right);
    }
}

