

/* binary tree node */
typedef int binaryData_t; 

typedef struct binaryNode_s  binaryNode_t; 
struct binaryNode_s {
    struct binaryNode_s    *leftChild;
    struct binaryNode_s    *rightChild;
    binaryData_t		    data;
};

binaryNode_t *createNode(int data);


/* crate a node */
binaryNode_t *createNode(binaryData_t data)
{
    binaryNode_t *p;

    p = (binaryNode_t *)malloc(sizeof(binaryNode_t));
    if (!p) {
		return NULL;
    }

    p->data = data;
    p->leftChild = NULL;
    p->rightChild = NULL;

    return p;
}