#include<iostream>
using namespace std;

void maxmin(int a[],int i,int j,int &max,int &min)
{
int mid,max1,min1,max2,min2;
if(i==j)
{
max=min=a[i];
}
else if(i==j-1)
{
if(a[i]<a[j])
{
max=a[j];
min=a[i];
}
else
{
max=a[i];
min=a[j];
}
}
else
{
mid=(i+j)/2;
maxmin(a,i,mid,max1,min1);
maxmin(a,mid+1,j,max2,min2);
if(max1>max2)
max=max1;
else
max=max2;
if(min1<min2)
min=min1;
else
min=min2;
}
}

int main()
{
int n,a[100],i,max,min;
cin>>n;
for(i=0;i<n;i++)
cin>>a[i];
maxmin(a,0,n-1,max,min);
cout<<max<<endl;
cout<<min;
return 0;
}
