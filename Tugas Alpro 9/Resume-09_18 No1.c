#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *start = NULL;
void insert_at_begin(int x);
void insert_at_end(int x);
void traverse();
int count = 0;

int main() {
	int data1, data2, data3, data4, data5, data6;
	
    system("cls");

	printf("Input any number for data1: ");
	scanf("%d", &data1);
	insert_at_begin(data1);
	
	printf("Input a non-zero number for data2: ");
	scanf("%d", &data2);
	insert_at_end(data2);
	
	data3 = data1 + data2;
	insert_at_end(data3);
	
	data4 = data1 * data2;
	insert_at_end(data4);
	
    if(data2 != 0) data5 = data1 / data2;
    else data5 = INT_MAX;
	insert_at_end(data5);
	
	data6 = data1 - data2;
	insert_at_end(data6);
	
    printf("\n");
	traverse();

    printf("\n\n\nPress any key to end program . . . ");
    getch();

	return 0;
}

void insert_at_begin(int x) {
	struct node *t;
	t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	count++;
	
	if(start == NULL) {
		start = t;
		start->next = NULL;
		return;
	}
	
	t->next = start;
	start = t;
}

void insert_at_end(int x) {
	struct node *t, *temp;
	
	t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	count++;
	
	if(start == NULL) {
		start = t;
		start->next = NULL;
		return;
	}
	
	temp = start;
	while(temp->next != NULL) temp = temp->next;
	temp->next = t;
	t->next = NULL;
}

void traverse() {
	struct node *t;
	
	t = start;
	
	if(t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	
	printf("There are %d elements in linked list.\n", count);
	
	while(t->next != NULL) {
		printf("%d -> ", t->data);
		t = t->next;
	}
	
	printf("%d -> NULL\n", t->data);
}
