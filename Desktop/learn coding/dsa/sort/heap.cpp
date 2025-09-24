// #include <iostream>
// #include <vector>
// #include <algorithm>

// // Function to heapify a subtree rooted with node i
// // n is the size of the heap
// void heapify(std::vector<int>& arr, int n, int i) {
//     int largest = i;       // Initialize largest as root
//     int left = 2 * i + 1;  // Left child
//     int right = 2 * i + 2; // Right child

//     // If left child is larger than root
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     // If right child is larger than largest so far
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     // If largest is not root
//     if (largest != i) {
//         std::swap(arr[i], arr[largest]);
//         // Recursively heapify the affected sub-tree
//         heapify(arr, n, largest);
//     }
// }

// // Main function to do heap sort
// void heapSort(std::vector<int>& arr) {
//     int n = arr.size();

//     // Build a max-heap (rearrange array)
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(arr, n, i);

//     // One by one extract an element from heap
//     for (int i = n - 1; i > 0; i--) {
//         // Move current root to end
//         std::swap(arr[0], arr[i]);
//         // Call max heapify on the reduced heap
//         heapify(arr, i, 0);
//     }
// }

// int main() {
//     std::vector<int> arr = {12, 11, 13, 5, 6, 7};
//     heapSort(arr);

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
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Function to heapify a subtree rooted with node i
// // n is the size of the heap
// void heapify(int arr[], int n, int i) {
//     int largest = i;       // Initialize largest as root
//     int left = 2 * i + 1;  // Left child
//     int right = 2 * i + 2; // Right child

//     // If left child is larger than root
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     // If right child is larger than largest so far
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     // If largest is not root
//     if (largest != i) {
//         swap(&arr[i], &arr[largest]);
//         // Recursively heapify the affected sub-tree
//         heapify(arr, n, largest);
//     }
// }

// // Main function to do heap sort
// void heapSort(int arr[], int n) {
//     // Build a max-heap (rearrange array)
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(arr, n, i);

//     // One by one extract an element from heap
//     for (int i = n - 1; i > 0; i--) {
//         // Move current root to end
//         swap(&arr[0], &arr[i]);
//         // Call max heapify on the reduced heap
//         heapify(arr, i, 0);
//     }
// }

// int main() {
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);
    
//     heapSort(arr, n);
    
//     std::cout << "Sorted array is: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }