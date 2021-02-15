#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	char id;
	int addr;
	int size;
	struct node *next;
}N;
N *start;

N *nodeAttr(char id, int addr, int size){
	N *nu = (N*)malloc(sizeof(N));
	nu->id = id; nu->addr = addr; nu->size = size;
	nu->next = NULL;
	return nu;
}

void insert(char id, int addr, int size){
	N *nu = nodeAttr(id, addr, size),*ptr;
	if(start==NULL){
		start=nu;
		return;	
	}
	for(ptr=start;ptr->next!=NULL;ptr=ptr->next);
	ptr->next=nu;
}

void dispMem(){
	N * ptr;
	if(start == NULL){
		printf("NULL\n");
		return;
	}
	for(ptr = start; ptr->next != NULL; ptr = ptr->next){
		printf("(%c, %d, %d, %c)---", ptr->id, ptr->addr, ptr->size, ptr->next->id);
	}
	printf("(%c, %d, %d, NULL)\n", ptr->id, ptr->addr, ptr->size);
}

void delNode(char id){
	N *ptr,*prev;int c=0;
	if(start==NULL){
		printf("\nEmpty");
		return;
	}
	ptr=prev=start;
	while(ptr!=NULL){
		if(ptr->id==id)
		break;
		prev=ptr;
		ptr=ptr->next;
	}
	if(ptr == NULL) printf("Doesnt exist\n");
	else
		ptr->id = 'H';
}

int firstFit(int *requests, int n){
	N *ptr = start; int c = 0, filled = 0;
	if (ptr == NULL) return 0;
	while(ptr!=NULL && c < n){
		if(ptr->id == 'H' && ptr->size >= requests[c]){
			ptr->id = 'P' + c;
			filled += requests[c];
			c++;
			ptr = start;// first fit
		}
		ptr = ptr->next;
	}
	return filled;
}

int nextFit(int *requests, int n){
	N *ptr = start; int c = 0, filled = 0;
	if (ptr == NULL) return 0;
	while(ptr!=NULL && c < n){
		if(ptr->id == 'H' && ptr->size >= requests[c]){
			ptr->id = 'P' + c;
			filled += requests[c];
			c++;
		}
		ptr = ptr->next;
	}
	return filled;
}

void revSort(int *A, int n){
	int i, d, temp;
	for(i = 1; i < n; i++){
		d = i;
		while(d > 0 && A[d] > A[d-1]){
			temp = A[d];
			A[d] = A[d-1];
			A[d-1] = temp;
			d--;
		}
	}
}

int bestFit(int *requests, int n){
	N *ptr = start; int c = 0, filled = 0;
	if (ptr == NULL) return 0;
	revSort(requests, n);
	while(ptr!=NULL && c < n){
		if(ptr->id == 'H' && ptr->size >= requests[c]){
			ptr->id = 'P' + c;
			filled += requests[c];
			c++;
			ptr = start;// first fit
		}
		ptr = ptr->next;
	}
	return filled;
}

N* search(int size){
	N *ptr = start;
	if(start == NULL) return start;
	while(ptr!=NULL){
		if(ptr->size == size){
			break;
		}
		ptr = ptr->next;
	}
	return ptr;
}

int worstFit(int *requests, int n){
	int sizes[100], k = 0, c = 0, filled = 0, i;
	N *ptr = start, *temp;
	if (start == NULL) return 0;

	// Determine Memory sizes and sort in descending
	while(ptr != NULL){
		if (ptr->id == 'H')
			sizes[k++] = ptr->size;
		ptr = ptr->next;
	}
	revSort(sizes, k);
	while(c < k && c < n){
		temp = search(sizes[c]);
		temp->id = 'P' + c;
		filled += requests[c];
		c++;
	}
	return filled;
}

int main(){
	int requests[4] = {25, 50, 100, 75}, filled, n = 4, ch;

	// Memory List
	// 50k(A) - 75k(H) - 150k(B) - 175k(H) - 300k(C)

	// INSERTION
	insert('A', 1, 50);
	insert('H', 10, 75);
	insert('B', 50, 150);
	insert('H', 80, 175);
	insert('C', 120, 300);

	// DELETION
	// delNode('B');

	// DISPLAY
	dispMem();

	// ALGORITHM
	printf("Enter Choice of Algo:\n1. First Fit\n2. Next Fit\n3. Best Fit\n4. Worst Fit\nEnter your choice: ");
	scanf("%d", &ch);

	switch(ch){
		case 1:
			// First Fit
			filled = firstFit(requests, n);
			dispMem();
			printf("FirstFit filled : %d out of 250\n", filled);
			break;
		case 2:
			// Next Fit
			filled = nextFit(requests, n);
			dispMem();
			printf("NextFit filled : %d out of 250\n", filled);
			break;
		case 3:
			// Best Fit
			filled = bestFit(requests, n);
			dispMem();
			printf("BestFit filled : %d out of 250\n", filled);
			break;
		case 4:
			// Worst Fit
			filled = worstFit(requests, n);
			dispMem();
			printf("WorstFit filled : %d out of 250\n", filled);
			break;
		default:
			printf("Wrong Choice\n");
	}

	return 0;
}


