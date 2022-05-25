#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queueNode {
	char nama[20];
	int kelas;
	int nomor;
	int harga;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, QueueNode input);
void instructions();

int main() {
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	QueueNode input;

	int choice;
    
    system("cls");
	instructions();
	printf("? ");
	scanf("%d", &choice);
	
	while(choice != 3) {
		switch(choice) {
			case 1:
				system("cls");
				printf("Nama: ");
				scanf("%s", &input.nama);
				printf("Kelas (Eksekutif = 1/ Bisnis = 0): ");
				scanf("%d", &input.kelas);
				printf("Nomor Kursi: ");
				scanf("%d", &input.nomor);
				printf("Harga Tiket: ");
				scanf("%d", &input.harga);
				enqueue(&headPtr, &tailPtr, input);
				printQueue(headPtr);
				break;
			case 2:
				if(!isEmpty(headPtr)) {
					dequeue(&headPtr, &tailPtr);
				}
				printQueue(headPtr);
				break;
			default:
				printf("invalid choice.\n\n");
				instructions();
				break;
		}
		instructions();
		printf("? ");
		scanf("%d", &choice);
	}
	
	printf("End of run.\n");
	
	return 0;
}

void instructions() {
	printf("Enter your choice:\n"
			"   1 to add an item to the queue\n"
			"   2 to remove an item from the queue\n"
			"   3 to end\n");
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, QueueNode input) {
	QueueNodePtr newPtr;
	
	newPtr = malloc(sizeof(QueueNode));
	
	if(newPtr != NULL) {
		strcpy(newPtr->nama, input.nama);
    	newPtr->kelas = input.kelas;
    	newPtr->nomor = input.nomor;
    	newPtr->harga = input.harga;
		newPtr->nextPtr = NULL;
		
		if(isEmpty(*headPtr)) {
			*headPtr = newPtr;
		} else {
			(*tailPtr)->nextPtr = newPtr;
		}
		
		*tailPtr = newPtr;
	} else {
		printf("%c not inserted. No memory available.\n", input.nama);
	}
}

void dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
	QueueNodePtr tempPtr;
	
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;
	
	if(*headPtr == NULL) {
		*tailPtr = NULL;
	}
	
	free(tempPtr);
}

int isEmpty(QueueNodePtr headPtr) {
	return headPtr == NULL;
}

void printQueue(QueueNodePtr currentPtr) {
	int antrian;
	if(currentPtr == NULL) {
		printf("Queue is empty.\n\n");
	} else {
		system("cls");
		printf("The queue is:\n\n");
		
		antrian = 1;
		while(currentPtr != NULL) {
			printf("Antrian ke-%d\n", antrian);
			printf("Nama = %s \n", currentPtr->nama);
			if(currentPtr->kelas == 0) printf("Kelas = Eksekutif\n");
			else if(currentPtr->kelas == 1) printf("Kelas = Bisnis\n");
			printf("Nomor Kursi = %d\n", currentPtr->nomor);
			printf("Harga tiket = %d\n   |\n   V\n", currentPtr->harga);
			currentPtr = currentPtr->nextPtr;
			antrian++;
		}
		
		printf("NULL\n\n");
	}
}