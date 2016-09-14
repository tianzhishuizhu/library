
// find minimum tree path       (14)
//        10
//      /    \
//     8      2
//    / \    /
//   3   5  2
void dfs(binaryNode_t *root, int arr[], int n, int last[], int *m)
{
	if (!root) {
		return;
	}
	else {
		arr[n] = root->data;
		n++;
		if (!(root->leftChild) && !(root->rightChild)) { // leaf node
			printArr(arr, n, last, m);
		}
		dfs(root->leftChild, arr, n, last, m);
		dfs(root->rightChild, arr, n, last, m);	
	}
}

void printArr(int arr[], int n, int last[], int *m) 
{
	int i;
	int sum;

	sum = 0;

	for (i = 0; i < n; i++) {
		sum += arr[i];
	}

	last[*m] = sum;
	(*m)++;
}

int min1(int last[], int m)
{
	int i;
	int min;

	min = 0;
	for (i = 1; i < m; i++) {
		if (last[i] < last[min]) {
			min = i;
		}
	}
	
	return last[min];
}
