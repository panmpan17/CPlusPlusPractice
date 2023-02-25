//
//  main.cpp
//  CPlusPlus
//
//  Created by Michael Pan on 2023/2/16.
//

#include <iostream>
#include "mathlib.hpp"
#include "sorting.hpp"
#include "class_struct.hpp"
#define print(message) std::cout << message << "\n";
#define print_array(array, size) for(int i=0; i<size; i++) std::cout << array[i] << ", "; std::cout << "\n";
#define copy_array(fromArray, toArray, size) for(int i=0; i<size; i++) toArray[i]=fromArray[i];
#define add(a, b) a + b;

// Declare
struct TestData;
void process_data(TestData* data);
int main(int argc, const char * argv[]);
void fill_array_with_random_value(int* array, int size, int min, int max);
int random_int(int min, int max);
bool check_sorting_result(int* array, int size);
void test_sorting();
void test_struct();


// Actual implementation
struct TestData
{
    int DataA;
    int DataB;
    int Result;
};


int main(int argc, const char * argv[])
{
//    test_sorting();
    test();

    return 0;
}

void test_structure()
{
    TestData data;
    data.DataA = 10;
    data.DataB = 3;
    process_data(&data);
    print(data.Result);
}

void test_sorting()
{
    const int arraySize = 30;

    int dataArray[arraySize];
    fill_array_with_random_value(dataArray, arraySize, 0, 1001);

    int array[arraySize];

    copy_array(dataArray, array, arraySize);
    bubble_sort(array, arraySize);
    print("Bubble Sort: " << check_sorting_result(array, arraySize));

    copy_array(dataArray, array, arraySize);
    insert_sort(array, arraySize);
    print("Insert Sort: " << check_sorting_result(array, arraySize));
    
    copy_array(dataArray, array, arraySize);
    selection_sort(array, arraySize);
    print("Selection Sort: " << check_sorting_result(array, arraySize));

    copy_array(dataArray, array, arraySize);
    quick_sort(array, arraySize);
    print("Quick Sort: " << check_sorting_result(array, arraySize));
    
    
    copy_array(dataArray, array, arraySize);
    heap_sort(array, arraySize);
    print("Heap Sort: " << check_sorting_result(array, arraySize));
}

void process_data(TestData* data)
{
    data->Result = sqaure(data->DataA, data->DataB);
}

void fill_array_with_random_value(int* array, int size, int min, int max)
{
    for (int i = 0; i < size; i++)
        array[i] = random_int(min, max);
}

int random_int(int min, int max) { return rand() % (max - min) + min; }

bool check_sorting_result(int* array, int size)
{
    int last = array[0];
    for (int i = 1; i < size; i++)
    {
        if (last > array[i])
            return false;
    }
    return true;
}
