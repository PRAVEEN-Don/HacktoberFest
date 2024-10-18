def selection_sort(arr):
    """Sorts a list using the Selection Sort algorithm."""
    n = len(arr)
    
    # Traverse through all array elements
    for i in range(n):
        # Assume the minimum is the first element of the unsorted part
        min_index = i
        
        # Find the index of the smallest element in the remaining unsorted array
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        
        # Swap the found minimum element with the first element of the unsorted part
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Example usage
if __name__ == "__main__":
    sample_list = [64, 25, 12, 22, 11]
    print("Original list:", sample_list)
    selection_sort(sample_list)
    print("Sorted list:", sample_list)
