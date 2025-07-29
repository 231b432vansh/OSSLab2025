#include <iostream>
#include <vector>

void merge(std::vector<short>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<short> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<short>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<short> data = {34, 7, -2, 45, 8, 12};

    std::cout << "Original: ";
    for (short num : data) std::cout << num << " ";
    std::cout << "\n";

    mergeSort(data, 0, data.size() - 1);

    std::cout << "Sorted:   ";
    for (short num : data) std::cout << num << " ";
    std::cout << "\n";

    return 0;
}

