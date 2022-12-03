[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9329768&assignment_repo_type=AssignmentRepo)
# Assignment-4 Sorting and Heaps
Jason Chen
In this assignment, I will compare various sorting algorithms. I will also modify the algorithms in order
for a Comparator class to be used for comparisons. I will then further experiment with algorithmic
variations.

How to run:

    make clean
    make all
    ./test_sorting_algorithms <input_type> <input_size> <comparison_type>
    
where <input_type> can be random, sorted_small_to_large, or sorted_large_to_small, <input_size> is the
number of elements of the input, and <comparison_type> is either less or greater.

For example, you should be able to run

Input:

    ./test_sorting_algorithms random 20000 less
    
The above should produce a random vector of 20000 integers and apply all three algorithms using the
less<int>{} Comparator.

Output:

    Running sorting algorithms: random 20000 less
    Heapsort
    Runtime: <X> ns
    Verified: 1
    
    MergeSort
    Runtime: <X> ns
    Verified: 1
    
    QuickSort
    Runtime: <X> ns
    Verified: 1
    
    Testing Quicksort Pivot Implementations
    
    Median of Three
    Runtime: <X> ns
    Verified: 1
    
    Middle
    Runtime: <X> ns
    Verified: 1
    
    First
    Runtime: <X> ns
    Verified: 1

Heapsort: is a popular and efficient sorting algorithm. The concept of heap sort is to eliminate the elements
one by one from the heap part of the list, and then insert them into the sorted part of the list.

Merge Sort: that is a sorting algorithm that is based on the Divide and Conquer paradigm. In this
algorithm, the array is initially divided into two equal halves and then they are combined in a sorted
manner.

Quicksort: is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array
around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 
Always pick the first element as a pivot.
Always pick the last element as a pivot (implemented below)
Pick a random element as a pivot.
Pick median as the pivot.

Things I struggled on:

1. Especially on quicksort 2 and quicksort3, It shows both quicksorts are verified when I test them but
grade scope says otherwise (says they're inccorect and returns 0, when they return 1 on my terminal ).
//lines 210 - 406 
I set the pivot to the first element and middle element using a[left] which = a[0] the first element of the 
array and center = (left + right) /2 which = a[center]. set int i = left - 1 and int j = right + 1 (line 318
and line 345).

2. struggled with figuring out how to implement comparator into sorting. Couldn't figure out the syntaxs and 
add the template but managed

3. couldn't figure why my sort were not processing correctly on gradescope, it was because of my function
and helper placement.

If I had more time:

Spend more time figuring out quicksort2 and quicksort3. Using first element as a pivot and middle element as
a pivot




