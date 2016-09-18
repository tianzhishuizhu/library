
// heap sort

// n nodes with root 'root' 
void heapfy(int arr[], int n, int root)
{
	int maxIndex;
	int left;
	int right;
	int temp;

	if (root > n / 2 - 1) {
		return;
	}
	left = 2 * root + 1;
	right = 2 * root + 2;
	if (right <= n - 1) { // range
		maxIndex = (arr[left] >= arr[right]) ? left : right; // max index
	}
	else {
		maxIndex = left;
	}

	if (arr[root] < arr[maxIndex]) {
		temp = arr[root];
		arr[root] = arr[maxIndex];
		arr[maxIndex] = temp;
		heapfy(arr, n, maxIndex);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	binaryNode_t *p;
	int arr[100] = {4, 10, 3, 5, 1, 9, 9, 9, 1000, 2, 7, 0};
	int n = 12; // n nodes
	int last[100];
	int m = 0;
	int i;
	int temp;
	
	for (i = n / 2 - 1; i >= 0; i--) { // create heap
		heapfy(arr, n, i); 
	}

	temp = arr[0];
	arr[0] = arr[n - 1];
	arr[n - 1] = temp;
	for (i = n - 1; i > 0; i--) {
		heapfy(arr, i, 0);
		temp = arr[0];
		arr[0] = arr[i - 1];
		arr[i - 1] = temp;

	}

	return 0;
}
