#define N 1024

typedef int  stackElement_t; // stack element type
typedef struct stack_s  stack_t;
struct stack_s {
	stackElement_t data[N]; // size is N
	int head;
};

void init(stack_t *s) 
{
	s->head = 0;
}

void push(stack_t *s, stackElement_t c)
{
	if (s->head != N - 1) {
		s->data[s->head] = c;
		(s->head)++;

	}
}

void pop(stack_t *s, stackElement_t *c)
{
	if (s->head != 0) {
		*c = s->head;
		(s->head)--;
	}
}
