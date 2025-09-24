// #include <iostream>
// #include <vector>
// #include <algorithm>

// // Function to merge two halves of a vector
// void merge(std::vector<int>& arr, int left, int mid, int right) {
//     // Create temporary vectors for the two halves
//     std::vector<int> left_half(arr.begin() + left, arr.begin() + mid + 1);
//     std::vector<int> right_half(arr.begin() + mid + 1, arr.begin() + right + 1);

//     // Merge the temporary vectors back into the original array
//     std::merge(left_half.begin(), left_half.end(),
//                right_half.begin(), right_half.end(),
//                arr.begin() + left);
// }

// // Main recursive function that sorts arr[left...right]
// void mergeSort(std::vector<int>& arr, int left, int right) {
//     if (left < right) {
//         // Find the middle point to divide the array into two halves
//         int mid = left + (right - left) / 2;

//         // Recursively sort the first and second halves
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         // Merge the sorted halves
//         merge(arr, left, mid, right);
//     }
// }

// int main() {
//     std::vector<int> arr = {12, 11, 13, 5, 6, 7};
//     mergeSort(arr, 0, arr.size() - 1);

//     std::cout << "Sorted array is: ";
//     for (int x : arr) {
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }



// #include <iostream>

// // Function to merge two halves of an array
// void merge(int arr[], int left, int mid, int right) {
//     int i, j, k;
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // Create temporary arrays
//     int L[n1], R[n2];

//     // Copy data to temporary arrays L[] and R[]
//     for (i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];

//     // Merge the temporary arrays back into arr[left..right]
//     i = 0;
//     j = 0;
//     k = left;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of L[], if there are any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of R[], if there are any
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// // Main recursive function that sorts arr[left...right]
// void mergeSort(int arr[], int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);
//         merge(arr, left, mid, right);
//     }
// }

// int main() {
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     mergeSort(arr, 0, n - 1);
    
//     std::cout << "Sorted array is: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }