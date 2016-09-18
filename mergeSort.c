
// merge sort
// but problem exists in line 10

// merge sorted arr[l..m] and sorted arr[m+1..n]   
void merge(int arr[], int l, int m, int n) 
{
	int i;
	int j;
	int k;
	int newArr[1000]; // but the range is 1000

	for (i = 0; i < n - l + 1; i++) {
		newArr[i] = arr[i + l];
	}

	i = 0; 
	j = m - l + 1;
	k = l;
	for ( ; i <= m - l && j <=  n - l; ) { 
		if (newArr[i] <= newArr[j]) {
			arr[k] = newArr[i];
			i++;
		}
		else {
			arr[k] = newArr[j];
			j++;
		}
		k++;
	}

	while (i <= m - l) {
		arr[k++] =  newArr[i++];
	}
	while (j <= n - l) {
		arr[k++] =  newArr[j++];
	}
}

void mergeSort(int arr[], int begin, int end)
{
	int l;

	if (begin < end) {
		l = begin + (end - begin) / 2;
		mergeSort(arr, begin, l);
		mergeSort(arr, l + 1, end);
		merge(arr, begin, l, end);
	}
}
