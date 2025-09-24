// #include <iostream>
// #include <vector>
// #include <algorithm>

// // Function to partition the array on the pivot
// int partition(std::vector<int>& arr, int low, int high) {
//     int pivot = arr[high]; // Choose the last element as the pivot
//     int i = (low - 1); // Index of the smaller element

//     for (int j = low; j < high; j++) {
//         // If the current element is smaller than or equal to the pivot
//         if (arr[j] <= pivot) {
//             i++;
//             std::swap(arr[i], arr[j]);
//         }
//     }
//     std::swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

// // Main function to perform quick sort
// void quickSort(std::vector<int>& arr, int low, int high) {
//     if (low < high) {
//         // Find the partitioning index
//         int pi = partition(arr, low, high);

//         // Recursively sort elements before and after the partition
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main() {
//     std::vector<int> arr = {10, 7, 8, 9, 1, 5};
//     quickSort(arr, 0, arr.size() - 1);
//     std::cout << "Sorted array is: ";
//     for (int x : arr) {
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }


// #include <iostream>

// // Manual swap function
// void swap(int* a, int* b) {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

// // Function to partition the array on the pivot
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = (low - 1);

//     for (int j = low; j < high; j++) {
//         if (arr[j] <= pivot) {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }

// // Main function to perform quick sort
// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main() {
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     quickSort(arr, 0, n - 1);
//     std::cout << "Sorted array is: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }