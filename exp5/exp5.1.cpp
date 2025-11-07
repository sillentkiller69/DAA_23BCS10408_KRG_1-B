class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        
      if(low<high){
          int piv=partition(arr,low,high);
          quickSort(arr,low,piv-1);
           quickSort(arr,piv+1,high);
          
      }
        
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int piv=arr[low];
        int s=low;
        int e=high;
        while(s<e){
            while(piv>=arr[s]&&s<high)s++;
            while(piv<arr[e]&&e>low)e--;
            if(s<e)swap(arr[s],arr[e]);
        }
        swap(arr[low],arr[e]);
        return e;
        
    }
};