
public class QuickSort {
	private int[] array;
    private int length;
 
    public void sort(int[] inputArr) {
         
        if (inputArr == null || inputArr.length == 0) {
            return;
        }
        ////////////////////
        array = inputArr;
        length = inputArr.length;
        quickSort(0,length - 1);
        
        /////////////////////
    }
 
    private void quickSort(int low, int high) {
         
    	int pivot = array[low + (high - low)/2];
    	int i = low;
        int j = high;
        
        
        // Divide into two arrays
        while (i <= j) {
        	while(array[i] < pivot)
        		i++;
        	while(array[j] > pivot)
        		j--;
        	if(i<=j) {
        		swap(i,j);
        		i++;
        		j--;
        	}
        }
        if(low<j)
        	quickSort(low,j);
        if(i<high)
        	quickSort(i,high);
    }
    private void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
     
  
}
