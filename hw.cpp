#include <iostream>
#include <stdio.h>

using namespace std;

//only give positive nos. as input
int main()
{
int arr[5],n,i,l,page[40];
l=4; //no of the pages
cout<<"Enter no  of inputs to be given:";
cin>>n;

cout<<"Enter the nos to be taken as input:";
for(i=0;i<n;i++)
 {
 cin>>page[i];
 }

for(i=0;i<l;i++)
 {
 arr[i]=-1;
 }
int end_index;
int j=0;
int count=0,flag=0;
for(i=0;i<n;i++)
 {
 int hit=0;

 for(j=0;j<l;j++)
  {
  if(page[i]==arr[j])
   {
   cout<<"\nPage hit";
   hit=1;
   break;
   }
  else if(arr[j]==-1)
   end_index=j;
  else
   end_index=l+1;
  }
  if(hit==0 && end_index<=l-1)//only for the first element
   {
   cout<<"\nPage Miss memory not full";
   count=count+1;
   arr[end_index]=page[i];
   }
  else if(hit==0 && end_index==l+1) //memory full
   {
   cout<<"\nPage Miss memory full";
   count=count+1;
   for(j=0;j<l-1;j++)
    {
    arr[j]=arr[j+1];
    }
   arr[j]=page[i];
   }
  cout<<"\n";
  
  for(int k=0;k<l;k++)
   {
   cout<<arr[k]<<" ";
   }
  }
 
 

return 0;
}
