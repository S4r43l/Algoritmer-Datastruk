// Compulsory 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random vector
vector<int> generateVector(int size)
{
    vector<int> randomVector;

    for (int i = 0; i < size; ++i)
    {
        int randomNum = rand(); // Generate a random number
        randomVector.push_back(randomNum); // Add it to the vector
    }

    return randomVector;
}


//Quick Sort: (recursive)
int partition(vector<int>& vec, int b, int t) //b = bottom, t = top
{
    int pivot = vec[b];
    int i = b, j = t;

    while (i <= j)
    {
        while (i <= j && vec[i] <= pivot)
        {
            i++;
        }

        while (i <= j && vec[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[b], vec[j]);
    return j;
}

void quickSort(vector<int>&vec, int b, int t)
{
   
    int j;

    if (b >= t) return;

    if(b<t)
    {
        
        j = partition(vec, b, t);
        
        quickSort(vec, b, j-1);

        quickSort(vec, j + 1, t);

    }


}

//Merge Sort:(recursive)
void merge(vector<int>& vec, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    vector<int> vec2(vec.size());

    while (i <= mid && j <= high)
    {
        if (vec[i] < vec[j])
        {
            vec2[k++] = vec[i++];
        }
        else
        {
            vec2[k++] = vec[j++];
        }
    }

    while (i <= mid)
    {
        vec2[k++] = vec[i++];
    }

    while (j <= high)
    {
        vec2[k++] = vec[j++];
    }

    for (i = low; i <= high; i++)
    {
        vec[i] = vec2[i];
    }
}

void mergeSort(vector<int>& vec, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(vec, low, mid);

        mergeSort(vec, mid + 1, high);

        merge(vec, low, mid, high);
    }
}

//Bubble Sort: (iterative)
void bubbleSort(vector<int>& vec,int n)
{
    for (int i = 0; i<n-1; i++)
    {

        for (int j=0; j<n-1; j++)
        {
	        if (vec[j] > vec[j+1])
	        {
                swap(vec[j], vec[j + 1]);
	        }
        }
	    
    }

}



int main()
{
    int choice; //chose between bubble, quick or merge sort

    //time
    float millisec;
    std::chrono::time_point<chrono::steady_clock> start;
    std::chrono::time_point<chrono::steady_clock> end;
    chrono::duration<float> elapsed_time;


    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator

    // choose the size of the vector
    int size;
    cout << "Enter the size of the random vector: ";
    cin >> size;

    // generate a random vector 
    vector<int> randomVector = generateVector(size);

    // print the random vector
    cout << "Random vector with size " << size << ":" << endl;
    for (const int& num : randomVector)
    {
        cout << num << endl;
    }

    cout << endl;

    cout << "Write 1 for Bubble Sort" << endl
        << "Write 2 for Quick Sort" << endl
        << "Write 3 for Merge Sort" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << endl << "Bubble sort:" << endl;

        start = chrono::high_resolution_clock::now();

        bubbleSort(randomVector, size);

    	end = chrono::high_resolution_clock::now();


        // print sorted vector
        for (int k = 0; k < size; k++)
        {
            cout << randomVector[k] << " ";
            if (k % 10 == 9)
            {
                cout << endl;
            }
        }

        //print time
        elapsed_time = end - start;
        millisec = elapsed_time.count() * 1000;
        cout << endl << endl << "Time used:" << endl << millisec << endl << endl;

        break;

    case 2:
        cout << "Quick Sort" << endl;

     
        start = chrono::high_resolution_clock::now();

        quickSort(randomVector, 0, size-1);

        end = chrono::high_resolution_clock::now();
       
        //print sorted vector
        for (int k = 0; k < size; k++)
        {
            cout << randomVector[k] << " ";
            if (k % 10 == 9)
            {
                cout << endl;
            }
        }

        //print time
    	elapsed_time = end - start;
        millisec = elapsed_time.count() * 1000;
        cout << endl << endl << "Time used:" << endl << millisec << endl << endl;

        break;

    case 3:
        cout << "Merge Sort:" << endl;

        start = chrono::high_resolution_clock::now();

        mergeSort(randomVector, 0, size-1);

        end = chrono::high_resolution_clock::now();

        //print sorted vector
        for (int k = 0; k < size; k++)
        {
            cout << randomVector[k] << " ";
            if (k % 10 == 9)
            {
                cout << endl;
            }
        }

        //print time
        elapsed_time = end - start;
        millisec = elapsed_time.count() * 1000;
        cout << endl << endl << "Time used:" << endl << millisec << endl << endl;
        break;

    default: 
        cout << "Invalid input" << endl;
        break;
    }

  

    return 0;
}
