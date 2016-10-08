#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define PF(num) printf("num1 is %d",num);

enum days {ONE=1,TWO,THREE};

struct listNode {
	int val;
	struct listNode *nextNode;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

int fa(int num);
void PrintArr(int arr[], int size);
void BubbleSort(int arr[], int size);
void PrintSort(int arr[], int arrSize, void(*Sort)(int arr[], int arrSize));
void UpSort(int arr[], int arrSize);
void DownSort(int arr[], int arrSize);
void ResetArr(int arr[], int arrSize);

void AddNode(ListNodePtr startNode) {
	ListNodePtr currentNode;
	ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
	newNode->val = rand() % 100;
	newNode->nextNode = NULL;
	printf("AddNode val %d\n", newNode->val);

	currentNode = startNode;

	while (currentNode->nextNode!=NULL) {
		currentNode = currentNode->nextNode;
	}
	currentNode->nextNode = newNode;
}

void PrintAllNodeVal(ListNodePtr startNode) {
	ListNodePtr currentNode;

	currentNode = startNode;

	for (int i = 0; currentNode != NULL;i++) {
		printf("Node[%d] val %d\n", i,currentNode->val);
		currentNode = currentNode->nextNode;
	}
}
void Insert(int insertVal, ListNodePtr startNode) {
	ListNodePtr currentNode;
	currentNode = startNode;
	ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
	newNode->val = rand() % 100+100;
	newNode->nextNode = NULL;
	printf("InsertNode val %d\n", newNode->val);
	while (currentNode->val != insertVal) {
		currentNode = currentNode->nextNode;
	}
	newNode->nextNode = currentNode->nextNode;
	currentNode->nextNode = newNode;
}
void DeleteNode(int insertVal, ListNodePtr *startNode) {
	ListNodePtr previousNode;
	ListNodePtr currentNode;
	ListNodePtr nextNode;
	currentNode = *startNode;
	if ((*startNode)->val == insertVal) {
		*startNode = (*startNode)->nextNode;
	}
	else {
		while (currentNode->val != insertVal) {
			previousNode = currentNode;
			currentNode = currentNode->nextNode;
		}
		previousNode->nextNode = currentNode->nextNode;
	}
	free(currentNode);
}


int main() {
	double num1, num2;
	int arr[10],opa, val;
	srand(time(NULL));
	
	ListNodePtr startNode = (ListNodePtr)malloc(sizeof(ListNode));

	startNode->val = rand() % 100;
	startNode->nextNode = NULL;
	printf("AddNode val %d\n", startNode->val);

	while (1) {
		printf("1.AddNode\t2.PrintAllNodeVal\n");
		printf("3.InsertNode\t4.DeleteNode\n");
		scanf("%d", &opa);
		switch (opa) {
			case 1:
				AddNode(startNode);
			break;
			case 2:
				PrintAllNodeVal(startNode);
				break;
			case 3:
				scanf("%d", &val);
				Insert(val, startNode);
				break;
			case 4:
				scanf("%d", &val);
				DeleteNode(val, &startNode);
				break;
			case -1:
				break;
		}
		printf("\n");
	}

	/*printf("原\n");
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
		printf("%d\t", arr[i]);
	}
	ResetArr(arr, 10);
	printf("改\n");
	for (int i = 0; i < 10; i++) {
		printf("%d\t", arr[i]);
	}*/
	//PrintSort(arr,10,DownSort);
	//printf("%d\n", ONE);

	system("pause");
	return 0;
}

int fa(int num) {
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return fa(num - 2) + fa(num - 1);
}

void PrintArr(int arr[], int size) {
	printf("Arr\n");
	for (int i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}
}

void BubbleSort(int arr[], int size) {
	int tmp;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] > arr[j]) {
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

void PrintSort(int arr[], int arrSize, void(*Sort)(int arr[], int arrSize)) {
	(*Sort)(arr, arrSize);
}
void UpSort(int arr[], int arrSize) {
	sort(arr, arr + arrSize);
	printf("UpSort\n");
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void DownSort(int arr[], int arrSize) {
	sort(arr, arr + arrSize);
	reverse(arr, arr + arrSize);
	printf("DownSort\n");
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void ResetArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		arr[i] = 0;
	}
}