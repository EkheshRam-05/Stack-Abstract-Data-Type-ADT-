/*
	A C Program To Implement Stack Abstract Data Type with help of Linked Stack using Pointers

	Sample Input && Output:

		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 1

		Enter the Element to Push: 100

		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 2

		Element: 100

		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 1

		Enter the Element to Push: 200

		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 1

		Enter the Element to Push: 300

		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 4

		Stack: 200 300


		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 4

		Stack: 200 300


		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 3

		Peek Element : 300

		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 4

		Stack: 200 300


		1.Push
		2.Pop
		3.Peek
		4.Print
		(0 to Exit)
		Enter Your Choice: 0

*/


//Including Required Header Files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Declaration of Stack(Node)
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node Stack;

//Function Declaration
void Push();
void Pop();
void Peek();
void Print();

//Head Pointer
Stack *head = NULL;

int main(){
	int choice;
	while(1){
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Print\n(0 to Exit)\nEnter Your Choice: ");
		scanf("%d", &choice);

		if (choice == 0){	
			return 0;
		}
		switch (choice)
		{
		case 1:
			Push();
			break;
		case 2:
			Pop();
			break;
		case 3:
			Peek();
			break;
		case 4:
			Print();
			break;
		default:
			printf("\nWrong Choice!!!\n");
			break;
		}
	}
}

//Definition of Insert Function to insert elements into the Stack
void Push(){
	Stack *newnode = malloc(sizeof(Stack));
	printf("\nEnter the Element to Push: ");
	scanf("%d", &newnode->data);
	if (head == NULL){
		head = newnode;
		head->next = NULL;
		return;
	}
	Stack *ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newnode->next = NULL;
	ptr->next = newnode;
}


//Definition of Delete Function to Remove elements from the Stack
void Pop(){
	if (head == NULL){
		printf("\nStack is Empty!!\n");
		return;
	}
	Stack *ptr = head;
	Stack *preptr = ptr;
	while(ptr->next != NULL){
		preptr = ptr;
		ptr = ptr->next;
	}
	printf("\nElement: %d\n", ptr->data);
	if(head->next == NULL){
		head = NULL;
	}
	preptr->next  = NULL;
}

void Peek(){
	if (head == NULL){
		printf("\nStack is Empty!!!\n");
		return;
	}
	Stack *ptr = head;
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	printf("\nPeek Element : %d\n", ptr->data);
}

//Definition of Print Function to print the Stack
void Print(){
	if (head == NULL){
		printf("\nStack Empty!!\n\n");
		return;
	}
	printf("\nStack: ");
	Stack *ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("  <-- Top of the Stack\n\n");
	return;
}