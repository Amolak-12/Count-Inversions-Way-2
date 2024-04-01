#include <iostream>
using namespace std;

void merge(int arr[], int &n, int &count, int s, int e, int &mid)
{
  mid = s+(e-s)/2;
  int length1 = mid-s+1;
  int length2 = e-mid;

  int *left = new int[length1];
  int *right = new int[length2];

  int k = s;
  //Copying the elements
  //left
  for(int i=0;i<length1;i++)
    {
      left[i] = arr[k];
      k++;
    }
  //right
  k = mid+1;
  for(int i=0;i<length2;i++)
    {
      right[i] = arr[k];
      k++;
    }

  //merge logic
  int leftarrIndex = 0;
  int rightarrIndex = 0;
  int mainarrayIndex = s;

  while(leftarrIndex < length1 && rightarrIndex < length2)
    {
      if(left[leftarrIndex] < right[rightarrIndex])
      {
        arr[mainarrayIndex++] = left[leftarrIndex++];
      }
      else{
        arr[mainarrayIndex++] = right[rightarrIndex++];
      }

    }
  while(leftarrIndex < length1)
    {
      arr[mainarrayIndex++] = left[leftarrIndex++];
    }
  while(rightarrIndex < length2)
    {
      arr[mainarrayIndex++] = right[rightarrIndex++];
    }
  //Change
   count++;
}
void MergeSort(int arr[], int &n, int &count, int s, int e, int &mid)
{
  //Base Case
  if(s>=e)
  {

    return;
  }

  //Step 1. divide
  mid = s+(e-s)/2;

  //Step 2. Left Recursive Call
  MergeSort(arr,n,count,s,mid,mid);
  //Step 3. Right Recursive Call
  MergeSort(arr,n,count,mid+1,e,mid);

  //Step 4. Merge both
  merge(arr,n,count,s,e,mid);
}
int main() {

  int arr[8] = {8,4,2,1,4,3,2,1};
  int n = 8;

  //count through merge sort
  int countMS = 1;

  //merge sort and count
  int s =0;
  int e = n-1;
  int mid = s+(e-s)/2;
  MergeSort(arr,n,countMS,s,e,mid);

  //printing the count through merge sort
  cout << "Count through Merge Sort: "<<countMS << endl;

}