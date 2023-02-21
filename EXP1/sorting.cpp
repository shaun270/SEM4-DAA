#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void insertion_sort(int arr[], int n)
{   
    cout<<"n"<<","<<"Insertion Sort"<<endl;
    int temp, p;
    for (int i = 100; i <= n; i += 100)
    {   
        auto start = chrono::high_resolution_clock::now();
        for (int j = 1; j < i; j += 1)
        {
            p = j;
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
            while (p > 0)
            {
                if (arr[p - 1] > arr[p])
                {
                    temp = arr[p - 1];
                    arr[p - 1] = arr[p];
                    arr[p] = temp;
                }
                p--;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        cout<<"\n"<<i/100<<"\t"<<chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<"\t";
    }
    for (int i = 0; i < n; i++)
    {
        cout <<i<<","<<arr[i]<<endl;
    }
    
}

void selection_sort(int arr[], int n)
{
    cout<<"n"<<","<<"Selection Sort"<<endl;
    int temp, pos;
    int min;
    auto start = chrono::high_resolution_clock::now();auto start = chrono::high_resolution_clock::now();
    for (int k = 100; k <= n; k += 100)
    {
        for (int i = 0; i < k - 2; i++)
        {   
            min = i;
            for (int j = i + 2; j < k; j++)
            {
                if (arr[j] <= arr[min])
                {
                    min = j;
                }
            }
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
        auto end = chrono::high_resolution_clock::now();
        cout<<"\n"<<k/100<<"\t"<<chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<"\t";
    }
    for (int i = 0; i < n; i++)
    {
        cout <<i<<","<<arr[i]<<endl;
    }
}

int main()
{
    int n = 100000;
    int arr[n];
    int input;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Choose your sorting algorithm: \n"
         << "(1) Insertion sort\n"
         << "(2) Selection sort" << endl;
    cin >> input;
    switch (input)
    {
    case 1:
        insertion_sort(arr, n);
        break;

    case 2:
        selection_sort(arr, n);
        break;

    default:
        break;
    }

    return 0;
}
