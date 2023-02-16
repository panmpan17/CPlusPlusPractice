//
//  sorting.cpp
//  CPlusPlus
//
//  Created by Michael Pan on 2023/2/16.
//

#include <iostream>
#include "sorting.hpp"

#define swap_array(array, index1, index2) {int temp = array[index2]; array[index2]=array[index1]; array[index1]=temp;}
#define print(message) std::cout << message << "\n";
#define print_array(array, size) for(int i=0; i<size; i++) std::cout << array[i] << ", "; std::cout << "\n";


void array_reinsert_last_item(int *array, int size)
{
    int last = array[size - 1];
    for (int index = 0; index < size; index++)
    {
        int temp = array[index];
        array[index] = last;
        last = temp;
    }
}

void bubble_sort(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int e = i + 1; e < size; e++)
        {
            if (array[i] > array[e])
                swap_array(array, i, e);
        }
    }
}

void insert_sort(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int insert_index = i;
        
        for (int e = i - 1; e >= 0; e--)
        {
            if (array[i] >= array[e])
                break;
            insert_index = e;
        }

        int last = array[i];
        for (int index = insert_index; index <= i; index++)
        {
            int temp = array[index];
            array[index] = last;
            last = temp;
        }
    }
}

void selection_sort(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int smallest_index = i;
        for (int e = i + 1; e < size; e++)
        {
            if (array[e] < array[smallest_index])
                smallest_index = e;
        }

        if (i != smallest_index)
            swap_array(array, i, smallest_index);
    }
}

void merge_sort(int* array, int size)
{
    if (size == 1)
        return;
    if (size == 2)
    {
        if (array[0] > array[1])
            swap_array(array, 0, 1);
        return;
    }

    int index = size / 2;
    int* anotherArray = (array+index);

    merge_sort(array, index);
    merge_sort(anotherArray, size - index);

    int index1 = 0;
    int index2 = index;
    
    int newArray[size];
    
    for (int i = 0; i < size; i++)
    {
        if (index1 == -1)
        {
            newArray[i] = array[index2];
            continue;
        }
        if (index2 == -1)
        {
            newArray[i] = array[index1];
            continue;
        }

        if (array[index1] <= array[index2])
        {
            newArray[i] = array[index1];
            if (++index1 >= index)
                index1 = -1;
        }
        else
        {
            newArray[i] = array[index2];
            if (++index2 >= size)
                index2 = -1;
        }
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = newArray[i];
    }
}

void quick_sort(int* array, int size)
{
    if (size <= 1)
        return;
    if (size == 2)
    {
        if (array[0] > array[1])
            swap_array(array, 0, 1);
        return;
    }

    int pivotNumber = array[size - 1];
    int frontIndex = 0;
    int backIndex = size - 2;
    
    while (frontIndex != backIndex && backIndex > frontIndex)
    {
        if (array[frontIndex] > pivotNumber)
        {
            swap_array(array, frontIndex, backIndex);
            backIndex--;
        }
        else if (array[backIndex] < pivotNumber)
        {
            swap_array(array, frontIndex, backIndex);
            frontIndex++;
        }
        else
        {
            backIndex--;
            frontIndex++;
        }
    }

    if (array[frontIndex] < pivotNumber)
        frontIndex++;

    int* anotherArray = array + frontIndex;
    array_reinsert_last_item(anotherArray, size - frontIndex);

    quick_sort(array, frontIndex);
    
    anotherArray += 1;
    quick_sort(anotherArray, size - frontIndex - 1);
}
