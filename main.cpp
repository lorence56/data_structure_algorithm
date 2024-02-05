#include <iostream>
#include <climits> // For INT_MIN

int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

int maximum(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    // Get the length of the array from the user
    int n;
    std::cout << "Enter the length of the array : ";
    std::cin >> n;

    // Declare an array of length n
    int array[n];

    // Allow the user to enter n integers and store them in the array
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        std::cin >> array[i];
    }

    // Call the summation function and display the result
    int sum_result = summation(array, n);
    std::cout << "Sum of the array: " << sum_result << std::endl;

    // Call the maximum function and display the result
    int max_result = maximum(array, n);
    std::cout << "Largest element in the array: " << max_result << std::endl;

    return 0;
}
