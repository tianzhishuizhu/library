
#define NUM  10000

typedef int  queueElement_T; // queue element type is int

typedef struct queue_s  queue_t; 
struct queue_s {
    queueElement_T data[NUM]; // queue size is NUM
	int front;
	int last;
    int count;
};



void initialize(queue_t *q)
{
	q->front = 0;
	q->last = 0;
	q->count = 0;
}

void in(queue_t *q, queueElement_T d) 
{
	if (q->count != NUM) {
		q->data[q->last] = d;
		q->last = (q->last + 1) % NUM;
		(q->count)++;
	}
}


queueElement_T out(queue_t *q) 
{
	queueElement_T d;
	
	d = NULL;
	if (q->count != 0) {
		d = q->data[q->front];
		q->front = (q->front + 1) % NUM;
		(q->count)--;
	}

	return d;
}

