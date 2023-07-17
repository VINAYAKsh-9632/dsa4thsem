// Next Greater Element  for every element in given Array
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

struct stack {
	int top;
	int val[STACKSIZE];
};


void push(struct stack* ps, int x)
{
	if (ps->top == STACKSIZE - 1) {
		printf("Error: stack overflown");
		getchar();
		exit(0);
	}
	else {
		ps->top += 1;
		int top = ps->top;
		ps->val[top] = x;
	}
}

bool isEmpty(struct stack* ps)
{
	return (ps->top == -1) ? true : false;
}

int pop(struct stack* ps)
{
	int temp;
	if (ps->top == -1) {
		printf("Error: stack underflow n");
		getchar();
		exit(0);
	}
	else {
		int top = ps->top;
		temp = ps->val[top];
		ps->top -= 1;
		return temp;
	}
}

void print(int arr[], int n)
{
	int i = 0;
	struct stack s;
	s.top = -1;
	int element, next;

	push(&s, arr[0]);

	for (i = 1; i < n; i++) {
		next = arr[i];

		if (isEmpty(&s) == false) {
			element = pop(&s);
			while (element < next) {
				printf("%d ",next);
				if (isEmpty(&s) == true)
					break;
				element = pop(&s);
			}
			if (element > next)
				push(&s, element);
		}
		push(&s, next);
	}
	while (isEmpty(&s) == false) {
		element = pop(&s);
		next = -1;
		printf("%d ",next);
	}
}

/* Driver code */
int main()
{
    int m;
    printf("Enter the number of elements\n");
    scanf("%d", &m);

	int arr[m];
    for(int i=0;i<m;i++){
      scanf("%d",&arr[i]); 
    }
    for(int i=0;i<m;i++){
      printf("%d ",arr[i]); 
    }
    printf("\n");
	int n = sizeof(arr) / sizeof(arr[0]);
	print(arr, n);
	
	return 0;
}
