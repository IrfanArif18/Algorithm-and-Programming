#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *odd = NULL;
struct node *even = NULL;

void input_data();
void insert_at_end(int, int);
void traverse(struct node *);
int count = 0;

int main() {
    system("cls");

	input_data();

	printf("\n\nStart:\n");
	traverse(start);
    printf("Odd:\n");
	traverse(odd);
	printf("Even:\n");
	traverse(even);

    printf("\n\n\nPress any key to end program . . . ");
    getch();

	return 0;
}

void input_data() {
	int data1, data2, data3, data4, data5, data6;
	struct node *t;

	printf("Input any number for data1: ");
	scanf("%d", &data1);
	insert_at_end(0, data1);
	
	printf("Input a non-zero number for data2: ");
	scanf("%d", &data2);
	insert_at_end(0, data2);
	
	data3 = data1 + data2;
	insert_at_end(0, data3);
	
	data4 = data1 * data2;
	insert_at_end(0, data4);
	
	if(data2 != 0) data5 = data1 / data2;
    else data5 = INT_MAX;
	insert_at_end(0, data5);
	
	data6 = data1 - data2;
	insert_at_end(0, data6);

	t = start;
	count = 1;

	while(t != NULL) {
		if(count % 2 == 0) {
			insert_at_end(2, t->data);
		} else if(count % 2 != 0) {
			insert_at_end(1, t->data);
		}
		
		t = t->next;
		count++;
	}
}

void insert_at_end(int flag, int x) {
	struct node *t, *temp;
	t = (struct node*)malloc(sizeof(struct node));

	switch(flag) {
		case 0:
			t->data = x;
			if(start == NULL) {
				start = t;
				start->next = NULL;
				return;
			}
			
			temp = start;
			while(temp->next != NULL) temp = temp->next;
			temp->next = t;
			t->next = NULL;
			
			break;
		case 1:
			t->data = x;
			if(odd == NULL) {
				odd = t;
				odd->next = NULL;
				return;
			}
			
			temp = odd;
			while(temp->next != NULL) temp = temp->next;
			temp->next = t;
			t->next = NULL;

			break;
		case 2:
			t->data = x;
			if(even == NULL) {
				even = t;
				even->next = NULL;
				return;
			}
			
			temp = even;
			while(temp->next != NULL) temp = temp->next;
			temp->next = t;
			t->next = NULL;

			break;
		default:
			printf("\nProgrammer error.\nInvalid argument (0: start, 1: odd, 2: even)\n\n\n\n");
			getch();
	}
}

void traverse(struct node *num_type) {
	struct node *t;
	
	t = num_type;
	
	if(t == NULL) {
		printf("Linked list is empty.\n");
		return;
	}
	
	// printf("There are %d elements in linked list.\n", count);
	
	while(t->next != NULL) {
		printf("%d -> ", t->data);
		t = t->next;
	}
	
	printf("%d -> NULL\n", t->data);
}
