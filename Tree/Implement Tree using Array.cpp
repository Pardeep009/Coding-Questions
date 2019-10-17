  #include <iostream>
  using namespace std;
  void insertnode(int i,int node_val,int arr[])
  {
      if(arr[i]==0)
      {
          arr[i] = node_val;
      }
      else
      {
          if(arr[i]>=node_val)
          insertnode(i*2+1,node_val,arr);
          else
          insertnode(i*2+2,node_val,arr);
      }
  }
  void convertToBST(int a[],int arr[],int size)
  {
      for(int i=0;i<size;i++)
      {
          insertnode(0,a[i],arr);
      }
  }
  int main() {
    int a[] = {5,2,22,11,3,324,3};
    int arr[100] = {0};
    int size = sizeof(a)/sizeof(a[0]);
    convertToBST(a,arr,size);
    for(int i=0;i<50;i++)
    cout<<arr[i]<<" ";
    return 0;
  }
