#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{

int i,n,page[50],arr[5],k,s,j,large,large_index,dist[5],hit=0,found=0,f;
int nhit=0,nmiss=0;
int m=0;

cout<<"\nEnter the no of pages to be filled in the page table:";
cin>>n;

cout<<"\nEnter the no. of frames:";
cin>>f;

for(i=0;i<n;i++)
 cin>>page[i];



int finish=0; //keeps track of the last frame that was inserted into the page table
int pointer=0;//keeps track of the last location filled in the page table

//initializing the page table with -1
for(i=0;i<f;i++)
 arr[i]=-1;


//filling the page table
for(i=0;i<n;i++) //iterating through the frames in physical memory
{
 for(j=0;j<=i;j++) //iterating through page table to check if the input frame is already present in the page table or not
  {
   if(page[i]!=arr[j])
    hit=0;
   else
   {
   hit=1;
   nhit=nhit+1;
   cout<<"\nPage Hit!";
   break;
   }
  }
 if(hit==0) //if not presnt i.e. page miss ,then inserted into the page table
 {
 cout<<"\n j is:"<<j;
 nmiss=nmiss+1;
 cout<<"\nPage Miss!";
 arr[pointer]=page[i];
 pointer=pointer+1;

 }
 
 //Displaying the current state of the array!
 cout<<"\nArray:";
 for(k=0;k<f;k++)
 cout<<arr[k]<<" ";
 cout<<"\n";
 
 //checking if all locations of the page table have been filled
 if(pointer==f)
 {
 finish=i+1;
 cout<<"\nCompleted filling the frames"; 
 break;
 }
}



hit=0;
found=0;

//optimal page replacement
for(i=finish;i<n;i++)// traversing the frames
{
 for(j=0;j<f;)//traversing the page table
 {
  if(page[i]!=arr[j])
  {
   j=j+1;
   hit=0;
   
  }
  else
  {
   hit=1;
   break;
  }
 }

if(hit==1)
{ 
 //do nothing
 cout<<"\nPage hit!";
 nhit=nhit+1;
}
else
{
 //Page fault
 cout<<"\nPage miss!";
 nmiss=nmiss+1;

 int index=i;
 for(k=0;k<f;k++)
 {
  cout<<"\nindex:"<<index;
  // checking each element of the page table with the remaing array of frames, to check
  // for the one with the longest forward distance
  for(m=index;m>0;m--)
  { 
   if(arr[k]==page[m])
   {
    dist[k]=index-m;
    cout<<"\n m is "<<m;
    cout<<"\n"<<arr[k]<<"alloted a distance "<<int(dist[k]);
   
    found=1;
    break;
   }
  }
  if(found==0) //not found in frame array ,assigned a very large value
  {
   dist[k]=99;
   cout<<"\n"<<arr[k]<<"\nalloted a distance 99";
  }
 }
 
 //finding the one with largest backward distance and then replacing it
 large=dist[0];
 large_index=0;
 for(s=1;s<f;s++)
 { 
  if(large<dist[s])
  {
   large=dist[s];
   large_index=s;
   
  }
 }
cout<<"\n"<<arr[large_index]<<" stands with largest distance";
arr[large_index]=page[i];

}
cout<<"\n";

for(k=0;k<f;k++)
 cout<<arr[k]<<" ";
}

cout<<"\nNo of hits:"<<nhit;
cout<<"\nNo of misses:"<<nmiss;
return 0;
}

   
