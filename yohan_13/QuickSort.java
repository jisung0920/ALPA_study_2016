package sort;
public class QuickSort {
	private int[] array;
    private int length;
 
    public void sort(int[] inputArr) {
         
        if (inputArr == null || inputArr.length == 0) {
            return;
        }
        ////////////////////
        array = inputArr;
        int low=0;
        int high = inputArr.length -1;
        quickSort(low,high);
        /////////////////////
    }
 
    private void quickSort(int low, int high) {
    	if(array == null || array.length ==0)
    		return;
    	if(low>=high)
    		return;
        int middle = (low + high)/2;
    	int pivot = array[middle];
    	
    	int i = low;
        int j = high;
        
        // Divide into two arrays
        while (i <= j) {
        	while(array[i] < pivot){
        		i++;
        	}
        	while(array[j] >pivot){
        		j--;
        	}
        	if(i<=j){
        		swap(i,j);
        		i++;
        		j--;
        	}
        }
        
        // call quickSort() method recursively
        if(low<j)
        	quickSort(low,j);
        if(high>i)
        	quickSort(i,high);
    }
 
    private void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
     
  
}
