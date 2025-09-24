// // #include <iostream>
// // #include <vector>
// // #include <algorithm>
// // using namespace std;

// // void bubbleSort(vector<int>& arr) {
// //     // Get the size of the vector.
// //     int n = arr.size();
    
// //     // Outer loop for the number of passes.
// //     // We only need n-1 passes to sort an array of size n.
// //     for (int i = 0; i < n - 1; ++i) {
// //         // Inner loop for comparing adjacent elements.
// //         // The last 'i' elements are already sorted, so we don't need to check them.
// //         for (int j = 0; j < n - i - 1; ++j) {
// //             // Compare the current element with the next element.
// //             if (arr[j] > arr[j + 1]) {
// //                 // If the current element is greater, swap them.
// //                 swap(arr[j], arr[j + 1]);
// //             }
// //         }
// //     }
// // }

// // int main() {
// //     // Create a vector of integers to be sorted.
// //     vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
// //     // Call the bubble sort function.
// //     bubbleSort(arr);
    
// //     // Print the sorted array.
// //     cout << "Sorted array is: ";
// //     for (int i : arr) {
// //         cout << i << " ";
// //     }
// //     cout << endl;
    
// //     return 0;
// // }


// //without 
// #include <iostream>

// // The function to perform bubble sort on a C-style array.
// // The size of the array must be passed as a separate argument.
// void bubbleSort(int arr[], int n) {
//     // Outer loop for the number of passes.
//     // We only need n-1 passes to sort an array of size n.
//     for (int i = 0; i < n - 1; ++i) {
//         // Inner loop for comparing adjacent elements.
//         // The last 'i' elements are already sorted, so we don't need to check them.
//         for (int j = 0; j < n - i - 1; ++j) {
//             // Compare the current element with the next element.
//             if (arr[j] > arr[j + 1]) {
//                 // Manually swap the elements using a temporary variable.
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     // Create a C-style array of integers.
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
    
//     // Calculate the size of the array.
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     // Call the bubble sort function.
//     bubbleSort(arr, n);
    
//     // Print the sorted array.
//     std::cout << "Sorted array is: ";
//     for (int i = 0; i < n; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
    
//     return 0;
// }