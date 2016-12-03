package sort;
public class MergeSort {
	private int[] array;
	private int[] helper;

	private int size;

	public void sort(int[] inputArr) {
		if (inputArr == null || inputArr.length == 0) {
			return;
	    }
		////////////////
		size = inputArr.length;
		array = inputArr;
		helper = new int[inputArr.length];
		mergesort(0,size-1);

		///////////////
	  }
	  private void mergesort(int low, int high) {
	    // check if low is smaller then high, if not then the array is sorted
		if (low < high) {
			int middle = low + (high - low)/2;
			mergesort(low , middle);
			mergesort(middle+1,high);
			merge(low,middle,high);
	    	}
	    }
	    

	  private void merge(int low, int middle, int high) {

	    // Copy both parts into the helper array
	    for (int i = low; i <= high; i++) {
	      helper[i] = array[i];
	    }
	    int i = low;
	    int j= middle+1;
	    int k =low;
	    while((i<=middle) && (j<=high)){
	    	if(helper[i] <= helper[j]){
	    		array[k] = helper[i];
	    		i++;
	    	}else{
	    		array[k] = helper[j];
	    		j++;
	    	}
	    	k++;
	    }
	    while(i<=middle){
	    	array[k] = helper[i];
	    	k++;
	    	i++;
	    }
	  }

}
