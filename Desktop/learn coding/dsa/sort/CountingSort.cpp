// #include <iostream>
// #include <vector>
// #include <algorithm>

// // A utility function to get the maximum value in arr[]
// int getMax(const std::vector<int>& arr) {
//     int max = arr[0];
//     for (size_t i = 1; i < arr.size(); i++) {
//         if (arr[i] > max) {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// // A function to do counting sort of arr[] according to the digit represented by exp
// void countSort(std::vector<int>& arr, int exp) {
//     std::vector<int> output(arr.size());
//     std::vector<int> count(10, 0);

//     // Store count of occurrences in count[]
//     for (size_t i = 0; i < arr.size(); i++) {
//         count[(arr[i] / exp) % 10]++;
//     }

//     // Change count[i] so that count[i] now contains the actual
//     // position of this digit in output[]
//     for (size_t i = 1; i < 10; i++) {
//         count[i] += count[i - 1];
//     }

//     // Build the output array
//     for (int i = arr.size() - 1; i >= 0; i--) {
//         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//         count[(arr[i] / exp) % 10]--;
//     }

//     // Copy the output array to arr[], so that arr[] now
//     // contains sorted numbers according to the current digit
//     for (size_t i = 0; i < arr.size(); i++) {
//         arr[i] = output[i];
//     }
// }

// // The main function to sort arr[] of size n using Radix Sort
// void radixSort(std::vector<int>& arr) {
//     int m = getMax(arr);

//     // Do counting sort for every digit. Note that exp is 10^i
//     // where i is the current digit number
//     for (int exp = 1; m / exp > 0; exp *= 10) {
//         countSort(arr, exp);
//     }
// }

// int main() {
//     std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
//     radixSort(arr);
//     std::cout << "Sorted array is: ";
//     for (int x : arr) {
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }


// #include <iostream>

// // A utility function to get the maximum value in arr[]
// int getMax(int arr[], int n) {
//     int max = arr[0];
//     for (int i = 1; i < n; i++) {
//         if (arr[i] > max) {
//             max = arr[i];
//         }
//     }
//     return max;
// }

// // A function to do counting sort of arr[] according to the digit represented by exp.
// void countSort(int arr[], int n, int exp) {
//     int output[n];
//     int count[10] = {0};

//     // Store count of occurrences in count[]
//     for (int i = 0; i < n; i++) {
//         count[(arr[i] / exp) % 10]++;
//     }

//     // Change count[i] so that count[i] now contains the actual
//     // position of this digit in output[]
//     for (int i = 1; i < 10; i++) {
//         count[i] += count[i - 1];
//     }

//     // Build the output array
//     for (int i = n - 1; i >= 0; i--) {
//         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//         count[(arr[i] / exp) % 10]--;
//     }

//     // Copy the output array to arr[], so that arr[] now
//     // contains sorted numbers according to the current digit
//     for (int i = 0; i < n; i++) {
//         arr[i] = output[i];
//     }
// }

// // The main function to sort arr[] of size n using Radix Sort
// void radixSort(int arr[], int n) {
//     int m = getMax(arr, n);

//     // Do counting sort for every digit. Note that exp is 10^i
//     // where i is the current digit number
//     for (int exp = 1; m / exp > 0; exp *= 10) {
//         countSort(arr, n, exp);
//     }
// }

// int main() {
//     int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     radixSort(arr, n);
//     std::cout << "Sorted array is: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }