#include <iostream>
using namespace std;

int merge(int a[], int l, int m, int r)
{
    int temp[100];
    int i=l,j=m+1,k=l,count=0;
    while(i<=m&&j<=r)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            for(int x=i;x<=m;x++)
                cout<<"("<<a[x]<<","<<a[j]<<")"<<endl;
            count=count+(m-i+1);
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    for(i=l;i<=r;i++)
        a[i]=temp[i];
    return count;
}

int mergeSort(int a[],int l,int r)
{
    int count=0;
    if(l<r)
    {
        int m=(l+r)/2;
        count=count+mergeSort(a,l,m);
        count=count+mergeSort(a,m+1,r);
        count=count+merge(a,l,m,r);
    }
    return count;
}

int main()
{
    int n,a[100];
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int total=mergeSort(a,0,n-1);
    cout<<"Total inversion pairs = "<<total;
    return 0;
}
