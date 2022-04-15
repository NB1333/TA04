//
//  main.cpp
//  TA04
//
//  Created by Nikita  on 12.04.2022.
//

#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

void BubbleSort(int[], int);
void InsertionSort(int[], int);
void SelectionSort(int[], int);
void swap(int*, int*);
void RandomArray(int[], int);
void SortedArray(int[], int);

int main() {
    int array1[1000];
    int array2[10000];
    int array3[100000];
    
    //1K elements sort
    RandomArray(array1, sizeof(array1)/sizeof(array1[0]));
    BubbleSort(array1, sizeof(array1)/sizeof(array1[0]));
    
    RandomArray(array1, sizeof(array1)/sizeof(array1[0]));
    InsertionSort(array1, sizeof(array1)/sizeof(array1[0]));

    RandomArray(array1, sizeof(array1)/sizeof(array1[0]));
    SelectionSort(array1, sizeof(array1)/sizeof(array1[0]));
    
    cout << endl;
    
    //10K elements sort
    RandomArray(array2, sizeof(array2)/sizeof(array2[0]));
    BubbleSort(array2, sizeof(array2)/sizeof(array2[0]));
    
    RandomArray(array2, sizeof(array2)/sizeof(array2[0]));
    InsertionSort(array2, sizeof(array2)/sizeof(array2[0]));
    
    RandomArray(array2, sizeof(array2)/sizeof(array2[0]));
    SelectionSort(array3, sizeof(array2)/sizeof(array2[0]));
    
    cout << endl;
    
    //100K elements sort
    RandomArray(array3, sizeof(array3)/sizeof(array3[0]));
    BubbleSort(array3, sizeof(array3)/sizeof(array3[0]));
    
    RandomArray(array3, sizeof(array3)/sizeof(array3[0]));
    InsertionSort(array3, sizeof(array3)/sizeof(array3[0]));
    
    RandomArray(array3, sizeof(array3)/sizeof(array3[0]));
    SelectionSort(array3, sizeof(array3)/sizeof(array3[0]));
    
    cout << endl;

    //1K elements sort
    SortedArray(array1, sizeof(array1)/sizeof(array1[0]));
    BubbleSort(array1, sizeof(array1)/sizeof(array1[0]));
    
    SortedArray(array1, sizeof(array1)/sizeof(array1[0]));
    InsertionSort(array1, sizeof(array1)/sizeof(array1[0]));

    SortedArray(array1, sizeof(array1)/sizeof(array1[0]));
    SelectionSort(array1, sizeof(array1)/sizeof(array1[0]));
    
    cout << endl;
    
    //10K elements sort
    SortedArray(array2, sizeof(array2)/sizeof(array2[0]));
    BubbleSort(array2, sizeof(array2)/sizeof(array2[0]));
    
    SortedArray(array2, sizeof(array2)/sizeof(array2[0]));
    InsertionSort(array2, sizeof(array2)/sizeof(array2[0]));
    
    SortedArray(array2, sizeof(array2)/sizeof(array2[0]));
    SelectionSort(array3, sizeof(array2)/sizeof(array2[0]));
    
    cout << endl;
    
    //100K elements sort
    SortedArray(array3, sizeof(array3)/sizeof(array3[0]));
    BubbleSort(array3, sizeof(array3)/sizeof(array3[0]));
    
    SortedArray(array3, sizeof(array3)/sizeof(array3[0]));
    InsertionSort(array3, sizeof(array3)/sizeof(array3[0]));
    
    SortedArray(array3, sizeof(array3)/sizeof(array3[0]));
    SelectionSort(array3, sizeof(array3)/sizeof(array3[0]));
    
    cout << endl;
    
    return 0;
}

void RandomArray(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1;
    }
}

void SortedArray(int array[], int size)
{
    int j = 2;
    for (int i = 0; i < size; i++) {
        array[i] = j++;
    }
}

void BubbleSort(int array[], int size)
{
    clock_t start = clock();
    for (int step = 0; step < size; ++step) {
      for (int i = 0; i < size - step; ++i) {
        if (array[i] > array[i + 1]) {
          int temp = array[i];
          array[i] = array[i + 1];
          array[i + 1] = temp;
        }
      }
    }
    
    clock_t end = clock();
    cout << size << " elements was sorted by Bubble Sort in: " <<(double) (end-start)/ CLOCKS_PER_SEC << " seconds" << endl;
}

void InsertionSort(int array[], int size)
{
    clock_t start = clock();
    
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0) {
          array[j + 1] = array[j];
          --j;
        }
        array[j + 1] = key;
      }
    
    clock_t end = clock();
    cout << size << " elements was sorted by Insertion Sort in: " <<(double) (end-start)/ CLOCKS_PER_SEC << " seconds" << endl;
}

void SelectionSort(int array[], int size)
{
    clock_t start = clock();
    
    for (int step = 0; step < size - 1; step++) {
       int min_idx = step;
       for (int i = step + 1; i < size; i++) {

         // To sort in descending order, change > to < in this line.
         // Select the minimum element in each loop.
         if (array[i] < array[min_idx])
           min_idx = i;
       }

       // put min at the correct position
       swap(&array[min_idx], &array[step]);
     }
    
    clock_t end = clock();
    cout << size << " elements was sorted by Selection Sort in: " <<(double) (end-start)/ CLOCKS_PER_SEC << " seconds" << endl;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

