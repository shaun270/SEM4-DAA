#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
    a[i]=arr[l+i];
    for(int j=0;j<n2;j++)
    b[j]=arr[mid+1+j];
    int i=0,j=0,ind=l;
    while(i<n1 && j<n2){
        if(a[i]<=b[j])
        arr[ind]=a[i++];
        else
        arr[ind]=b[j++];
        ind++;
    }
    while(i<n1){
        arr[ind]=a[i++];
        ind++;
    }
    while(j<n2){
        arr[ind]=b[j++];
        ind++;
    }
}

void merge_sort(int arr[], int l, int r)
{

    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void quick(int b[],int beg,int end)
{
    if(beg>end)
    return;
    int pivot=beg,low=beg+1,high=end;
    while(pivot!=high)
    {
        if(b[low]<=b[pivot])
        low++;
        else
        {
            if(b[high]>b[pivot])
            high--;
            else
            {
                if(low<high)
                swap(b[low],b[high]);
                else
                {
                    swap(b[pivot],b[high]);
                    break;
                }
            }
        }
    }
    quick(b,beg,high-1);
    quick(b,high+1,end);
}

// void print(int arr[], int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }


int main()
{
    int n=100000;

    for(int i=100;i<=n;i+=100){
        int arr[n],b[n];
        for(int i=0;i<n;i++){
            arr[i]=rand()%100;
        }
        copy(arr,arr+n,b);
        auto start = chrono::high_resolution_clock::now();
        merge_sort(arr,0,n-1);
        auto end = chrono::high_resolution_clock::now();
        cout<<"\n"<<n<<"\t"<<chrono::duration_cast<chrono::nanoseconds>(end - start).count()<<"\t";
        start = chrono::high_resolution_clock::now();
        quick(b,0,n-1);
        end = chrono::high_resolution_clock::now();
        cout<<chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    }
    
    
    

    return 0;
}