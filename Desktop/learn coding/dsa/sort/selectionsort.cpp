// #include <iostream>
// #include <vector>
// #include <algorithm>

// void selectionSort(std::vector<int>& arr) {
//     int n = arr.size();
//     for (int i = 0; i < n - 1; ++i) {
//         int min_idx = i;
//         for (int j = i + 1; j < n; ++j) {
//             if (arr[j] < arr[min_idx]) {
//                 min_idx = j;
//             }
//         }
//         std::swap(arr[i], arr[min_idx]);
//     }
// }

// int main() {
//     std::vector<int> arr = {64, 25, 12, 22, 11};
//     selectionSort(arr);
//     std::cout << "Sorted array is: ";
//     for (int x : arr) {
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>

// void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; ++i) {
//         int min_idx = i;
//         for (int j = i + 1; j < n; ++j) {
//             if (arr[j] < arr[min_idx]) {
//                 min_idx = j;
//             }
//         }
//         // Manual swap
//         int temp = arr[min_idx];
//         arr[min_idx] = arr[i];
//         arr[i] = temp;
//     }
// }

// int main() {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     selectionSort(arr, n);
//     std::cout << "Sorted array is: ";
//     for (int i = 0; i < n; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }