// Homework 4
// Testing Sorting Algorithms
// Jason Chen

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

// Computes duration given a start time and a stop time in nano seconds.
// Keep it in.
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, 
			  chrono::high_resolution_clock::time_point end_time) {
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

// Test function that shows how you can time a piece of code.
// Just times a simple loop. Remove for final submission.


// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  // Use rand() to generate random integer
    //create a vector
    //loop through a vector
    //pushback rand() numbers into the vector
    //return vector
    vector<int> random_vector;
    for(unsigned int i = 0; i < size_of_vector; ++i){
        random_vector.push_back(rand());
    }

    return random_vector;
}

// Generates and returns sorted vector of size @size_of_vector.
// If @smaller_to_larger is true, returns vector sorted from small to large.
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
  // Add code
    //create a vector
    //if its sorted smaller to larger
    //loop through vector using size of vector and push back i
    vector<int> sorted_vector;
    if(smaller_to_larger == true){
        for(unsigned int i = 0; i < size_of_vector; ++i){
            sorted_vector.push_back(i);
            
        }
    }
    else{
        for(unsigned int i = size_of_vector; i > 0; --i){
            sorted_vector.push_back(i);
        }
    }
    
    return sorted_vector;
}

// Verifies that a vector is sorted given a comparator.
// I.e. it applies less_than() for consecutive pair of elements and returns true
// if less_than() is true for all pairs.
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
    //if input is empty = true
    //if input size is 1 = true
    //loop through input and check if its in order using comparator
    //if its in consecutive order - nothing
    //else return false
    //return true.
    if(input.empty()){
        return true;
    }
    
    if(input.size() == 1){
        return true;
    }
    
    for(unsigned int i = 0; i < input.size() - 1; ++i){
        if(less_than(input[i], input[i+1]) || input[i] == input[i+1]){
            
        }
        else{
            
            return false;
        }
    }
    
    return true;
    
}

// Wrapper function to test different sorting algorithms. See homework's PDF for details.
void testSortingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return;
  }

  // This block of code to be removed for your final submission.
  //TestTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
    vector<int> input_vector{};
  if (input_type == "random") {
    // Generate random vector @input_vector.
      input_vector = GenerateRandomVector(input_size);
      
    
  } else {
    // Generate sorted vector @input_vector.
      input_vector = GenerateSortedVector(input_size, false);
      
  }
    // Call HeapSort / MergeSort / QuickSort  using appropriate input.
    // ...
    // if comparison type is "less" then call
    // MergeSort(input_vector, less<int>{})
    // otherwise call
    // MergeSort(input_vector, greater<int>{})
    // ...
    // ^^SAME for HeapSort & QuickSort

    // Call quicksort with median of three as pivot / middle as pivot / first as pivot using appropriate input.
    // ...
    // if comparison type is "less" then call
    // QuickSort(input_vector, less<int>{})
    // otherwise call
    // QuickSort(input_vector, greater<int>{})
    // ...
    // ^^SAME for QuickSort2 & QuickSort3

    if(comparison_type == "less"){
        cout << "HeapSort" << endl;
        auto begin_time = chrono::high_resolution_clock::now();
        HeapSort(input_vector, less<int>{});
        auto end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl;
        cout << endl;
        
        
        cout << "MergeSort" << endl;
        begin_time = chrono::high_resolution_clock::now();
        MergeSort(input_vector, less<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl;
        cout << endl;
        
        
        cout << "QuickSort" << endl;
        begin_time = chrono::high_resolution_clock::now();
        QuickSort(input_vector, less<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl;
        cout << endl;
        
        cout << "ShellSort" << endl;
        begin_time = chrono::high_resolution_clock::now();
        ShellSort(input_vector, less<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl;
        cout << endl;
        
        
    }
    else if(comparison_type == "greater"){
        cout << "HeapSort" << endl;
        auto begin_time = chrono::high_resolution_clock::now();
        HeapSort(input_vector, greater<int>{});
        auto end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl << endl;
        
        
        cout << "MergeSort" << endl;
        begin_time = chrono::high_resolution_clock::now();
        MergeSort(input_vector, greater<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl << endl;
        
        
        cout << "QuickSort" << endl;
        begin_time = chrono::high_resolution_clock::now();
        QuickSort(input_vector, greater<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl << endl;
        
        cout << "ShellSort" << endl;
        begin_time = chrono::high_resolution_clock::now();
        ShellSort(input_vector, greater<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl << endl;
        
    }
    
    
    if(comparison_type == "less"){
        
        cout << "Testing QuickSort Pivot Implementions" << endl << endl;
        cout << "Median of Three" << endl;
        auto begin_time = chrono::high_resolution_clock::now();
        QuickSort(input_vector, less<int>{});
        auto end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl << endl;
        
        cout << "Middle" << endl;
        begin_time = chrono::high_resolution_clock::now();
        QuickSort2(input_vector, less<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl << endl;
        
        cout << "First" << endl;
        begin_time = chrono::high_resolution_clock::now();
        QuickSort3(input_vector, less<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl;
        
    
    }
    else if(comparison_type == "greater"){
        
        cout << "Testing QuickSort Pivot Implementions" << endl << endl;
        cout << "Median of Three" << endl;
        auto begin_time = chrono::high_resolution_clock::now();
        QuickSort(input_vector, greater<int>{});
        auto end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl << endl;
        
        cout << "Middle" << endl;
        begin_time = chrono::high_resolution_clock::now();
        QuickSort2(input_vector, greater<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl << endl;
        
        cout << "First" << endl;
        begin_time = chrono::high_resolution_clock::now();
        QuickSort3(input_vector, greater<int>{});
        end_time = chrono::high_resolution_clock::now();
        cout << "Runtime: " << ComputeDuration(begin_time, end_time) << " ns" << endl;
        cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl;
  
    }
}


int main(int argc, char **argv) {
  // DO NOT CHANGE or ADD ANY CODE in this function.
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  testSortingWrapper(argc, argv);

  return 0;
}
