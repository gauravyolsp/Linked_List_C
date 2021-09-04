#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int iData;
	struct Node *pNext;
};

void Display(struct Node *);
int CountNode(struct Node *);
int DeleteLast(struct Node **);

int DeleteFirst(struct Node **);
void DeleteAllNode(struct Node **);
void ReverseDisplay(struct Node **);

void PhysicalReverse(struct Node **);
void InsertLast(struct Node **, int);
void InsertFirst(struct Node **, int);

int DeleteAtPosition(struct Node **, int);
int SearchAllOccurance(struct Node *, int);
int SearchLastOccurance(struct Node *, int);

int SearchFirstOccurance(struct Node *, int);
void InsertAtPosition(struct Node **, int, int);
void ConcatList(struct Node **, struct Node **);
void ConcatAtPosition(struct Node **, struct Node **, int);


int main(void)
{
	int iPos;
	int iData;
	int iChoice;
	struct Node *pFirst = NULL;
	struct Node *pSecond = NULL;

	printf("\t\tWELCOME TO SINGLY LINKED LIST MENU DRIVEN PROGRAM (2nd Form)\n");

	while(1)
	{
		printf("\n1. InsertFirst\n2. InsertLast\n3. InsertAtPosition\n4. DeleteFirst\n5. DeleteLast\n6. DeleteAtPosition\n7. SearchFirstOccurance\n8. SearchLastOccurance\n9. SearchAllOccurance\n10. CountNodes\n11. ConcatList\n12. ConcatAtPosition\n13. PhysicalReverse\n14. ReverseDisplay\n15. Exit\n");
		
		printf("\n\nEnter your choice:\t");
		scanf("%d", &iChoice);
	
		if(iChoice < 0 || iChoice >15)
		{
			printf("Enter valid choice!!!\n");
			continue;
		}

		switch(iChoice)
		{
			case 1:	printf("Enter the data:\t");
				scanf("%d", &iData);
	
				InsertFirst(&pFirst, iData);
				printf("\n");
				Display(pFirst);
				break;
			
			case 2:	printf("Enter the data:\t");
				scanf("%d", &iData);
	
				InsertLast(&pFirst, iData);
				printf("\n");
				Display(pFirst);
				break;

			case 3: printf("Enter the Position:\t");
				scanf("%d", &iPos);	
				
				iData = CountNode(pFirst);
			
				if(iPos <= 0 || iPos > iData + 1)
				{
					printf("Enter Valid position!!!\n");
					continue;
				}
				
				printf("Enter the data:\t");
				scanf("%d", &iData);
			
				InsertAtPosition(&pFirst, iData, iPos);
				printf("\n");
				Display(pFirst);
				break;

			case 4: iData = DeleteFirst(&pFirst);
	
				if(iData != -1)
					printf("Deleted data is %d\n", iData);
				Display(pFirst);
				break;
	
			case 5: iData = DeleteLast(&pFirst);

				if(iData != -1)
					printf("Deleted data is %d\n", iData);
				Display(pFirst);
				break;

			case 6:	printf("Enter the Position:\t");
				scanf("%d", &iPos);	
				
				iData = CountNode(pFirst);
			
				if(iPos <= 0 || iPos > iData + 1)
				{
					printf("Enter Valid position!!!\n");
					continue;
				}
						
				iData = DeleteAtPosition(&pFirst, iPos);
				printf("Deleted data is %d\n", iData);
				Display(pFirst);
				break;
			
			case 7: printf("Enter the data to be searched:\t");
				scanf("%d", &iData);
			
				iPos = SearchFirstOccurance(pFirst, iData);
				printf("[%d] found at %d position\n", iData, iPos);
				break;

			case 8: printf("Enter the data to be searched:\t");
				scanf("%d", &iData);
	
				iPos = SearchLastOccurance(pFirst, iData);
				printf("[%d] found at %d position\n", iData, iPos);
				break;

			case 9: printf("Enter the data to be seached:\t");
				scanf("%d", &iData);
	
				iPos = SearchAllOccurance(pFirst, iData);
				printf("[%d] is found %d times\n", iData, iPos);
				break;

			case 10: printf("Total Number of Nodes are %d\n", CountNode(pFirst));	
				 break;		
			
			case 11: printf("Enter the Second Linked List to Concat as a LIST:\n");				
				 while(1)
				 {
					printf("1. InsertFirst\n2. InsertLast\n3. InsertAtPosition\n4. Back\n");
					printf("Enter your Choice:\t");
					scanf("%d", &iChoice);
				
					if(iChoice <= 0 || iChoice > 4)
					{
						printf("Enter valid choice!!!\n");
						continue;
					}

					if(iChoice == 4)
						break;

					switch(iChoice)
					{
						case 1:	printf("Enter the data:\t");
						scanf("%d", &iData);
		
						InsertFirst(&pSecond, iData);
						printf("\n");
						Display(pSecond);
						break;
				
						case 2:	printf("Enter the data:\t");
							scanf("%d", &iData);
		
							InsertLast(&pSecond, iData);
							printf("\n");
							Display(pSecond);
							break;
	
						case 3: printf("Enter the Position:\t");
							scanf("%d", &iPos);	
						
							iData = CountNode(pSecond);
				
							if(iPos <= 0 || iPos > iData + 1)
							{
								printf("Enter Valid position!!!\n");
								continue;
							}
						
							printf("Enter the data:\t");
							scanf("%d", &iData);
					
							InsertAtPosition(&pSecond, iData, iPos);
							printf("\n");
							Display(pFirst);
							break;
					}
					
					ConcatList(&pFirst, &pSecond);
					Display(pFirst);
					Display(pSecond);
				 }break;

			case 12: printf("Enter the Second Linked List to Concat at position:\n");				
				 while(1)
				 {
					printf("\n1. InsertFirst\n2. InsertLast\n3. InsertAtPosition\n4. Back\n");
					printf("Enter your Choice:\t");
					scanf("%d", &iChoice);
				
					if(iChoice <= 0 || iChoice > 4)
					{
						printf("Enter valid choice!!!\n");
						continue;
					}

					if(iChoice == 4)
						break;
				
					switch(iChoice)
					{
						case 1:	printf("Enter the data:\t");
						scanf("%d", &iData);
		
						InsertFirst(&pSecond, iData);
						printf("\n");
						Display(pSecond);
						break;
				
						case 2:	printf("Enter the data:\t");
							scanf("%d", &iData);
		
							InsertLast(&pSecond, iData);
							printf("\n");
							Display(pSecond);
							break;
	
						case 3: printf("Enter the Position:\t");
							scanf("%d", &iPos);	
						
							iData = CountNode(pSecond);
				
							if(iPos <= 0 || iPos > iData + 1)
							{
								printf("Enter Valid position!!!\n");
								continue;
							}
						
							printf("Enter the data:\t");
							scanf("%d", &iData);
					
							InsertAtPosition(&pSecond, iData, iPos);
							printf("\n");
							Display(pSecond);
							break;
					}
				}	
				
				if(pSecond != NULL)				
				{
					printf("\nEnter the Position to do ConcatAtPosition:\t");
					scanf("%d", &iPos);
								
					ConcatAtPosition(&pFirst, &pSecond, iPos);
					printf("\nFirst Linked List is:\n");
					Display(pFirst);
					printf("\nSecond Linked List is:");
					Display(pSecond);
					break;
				}
				printf("No Elements is Entered\n");
				break;

			case 15: DeleteAllNode(&pFirst);
				 Display(pFirst);
				 return 0;	

			default: printf("Enter valid Choice:\t");
		}
	}

	return 0;
}

void InsertFirst(struct Node **ppHead, int iNo)
{
	struct Node *pNewNode = NULL;

	pNewNode = (struct Node *) malloc (sizeof(struct Node));

	if(NULL == pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n");
		return;
	}

	pNewNode->iData = iNo;

	if(NULL == *ppHead)
	{
		pNewNode->pNext = NULL;
		*ppHead = pNewNode;
		return;
	}

	pNewNode->pNext = *ppHead;
	*ppHead = pNewNode;
}

void InsertLast(struct Node **ppHead, int iNo)
{
	struct Node *pNewNode = NULL;
	struct Node *pTemp = NULL;

	pNewNode = (struct Node *) malloc (sizeof(struct Node));

	if(NULL == pNewNode)
	{
		printf("MEMORY ALLOCATION FAILED\n");
		return;
	}

	pNewNode -> iData = iNo;
	pNewNode -> pNext = NULL;
	
	if(NULL == *ppHead)		// if Linked List is empty
	{
		*ppHead = pNewNode;	
		return;
	}	

	// if Linked List is not empty atleat one Node

	pTemp = *ppHead;

	while(pTemp -> pNext != NULL)
		pTemp = pTemp -> pNext;

	pTemp -> pNext = pNewNode;
}

void InsertAtPosition(struct Node **ppHead, int iNo, int iPos)
{
	int iCount;
	struct Node *pNewNode = NULL;
	struct Node *pTemp = NULL;

	//iCount = CountNode(*ppHead);

	//if(iPos <= 0 || iPos > iCount + 1)
	//{
	//	printf("Position is invalid\n");
	//	return;
	//}

	if(1 == iPos)
	{
		InsertFirst(ppHead, iNo);
		return;
	}

	if(iPos == iCount + 1)
	{
 		InsertLast(ppHead, iNo);
		return;
	}

	pNewNode = (struct Node *) malloc (sizeof(struct Node));	

	if(NULL == pNewNode)
	{
		printf("Memory allocation Failed.\n");
		return;
	}
	
	pNewNode->iData = iNo;

	pTemp = *ppHead;
	iCount = 1;

	while(iCount < iPos - 1)
	{
		pTemp = pTemp->pNext;
		iCount++;
	}
	
	pNewNode->pNext = pTemp->pNext;
	pTemp->pNext = pNewNode;
}

int DeleteFirst(struct Node **ppHead)
{
	int iDelData;

	struct Node *pTemp = NULL;

	if(NULL == *ppHead)
		return -1;
	
	pTemp = *ppHead;
	iDelData = pTemp -> iData;

	*ppHead = pTemp -> pNext;
	pTemp -> pNext = NULL;

	free(pTemp);
	pTemp = NULL;
	
	return iDelData;			
}

int DeleteLast(struct Node **ppHead)
{
	int iDelData;
	struct Node *pTemp = NULL;

	if(NULL == *ppHead) 	// if linked list is empty
		return -1;

	pTemp = *ppHead;
	
	//if one node present
		
	if(NULL == pTemp->pNext)	
	{
		*ppHead = NULL;
		iDelData = pTemp -> iData;		
		free(pTemp);
	}

	// more than one node present

	else
	{
		while(pTemp->pNext->pNext != NULL)
			pTemp = pTemp->pNext;
	
		iDelData = pTemp->pNext->iData;

		free(pTemp->pNext);
		pTemp->pNext = NULL;
	}
	
	pTemp = NULL;
	return iDelData;
}

int DeleteAtPosition(struct Node **ppHead, int iPos)
{
	int iCount;
	struct Node *pTemp1 = NULL;
	struct Node *pTemp2 = NULL;


	//iCount = CountNode(*ppHead);

	//if(iPos <= 0 || iPos > iCount)
	//{
	//	printf("Position is not valid\n");
	//	return -1;
	//}

	if(1 == iPos)
	{
		DeleteFirst(ppHead);
		return;
	}

	if(iPos == iCount)
	{
		DeleteLast(ppHead);
		return;
	}

	pTemp1 = *ppHead;
	iCount = 1;

	while(iCount < iPos - 1)
	{
		pTemp1 = pTemp1->pNext;
		iCount++;
	}
	
	pTemp2 = pTemp1->pNext;
	iCount = pTemp2->iData;

	pTemp1->pNext = pTemp2->pNext;
	pTemp2->pNext = NULL;

	free(pTemp2);
	pTemp2 = pTemp1 = NULL;

	return iCount;
}

int SearchFirstOccurance(struct Node *pHead, int iKey)
{
	int iPos = 0;

	while(pHead != NULL)
	{
		iPos++;

		if(pHead->iData == iKey)
			break;

		pHead = pHead->pNext; 
	}
	
	if(NULL == pHead)
		iPos = 0;

	return iPos;
}

int SearchLastOccurance(struct Node *pHead, int iKey)
{
	int iPos = 0;
	int iLast = 0;

	while(pHead != NULL)
	{
		iPos++;

		if(pHead->iData == iKey)		
			iLast = iPos;

		pHead = pHead->pNext;
	}
	
	return iLast;
}

int SearchAllOccurance(struct Node *pHead, int iKey)
{
	int iCount = 0;
	
	while(pHead != NULL)
	{
		if(pHead->iData == iKey)
			iCount++;

		pHead = pHead->pNext;
	}

	return iCount;
}

int CountNode(struct Node *pHead)
{
	int iTotalCount = 0;

	while(pHead != NULL)
	{
		pHead = pHead->pNext;
		iTotalCount++;
	}
	
	return iTotalCount;
}

void Display(struct Node *pHead)
{
	if(NULL == pHead)
	{
		printf("\nLinked list is EMPTY!!!\n");
		return;
	}

	while(pHead != NULL)
	{
		printf("|%d|->", pHead->iData);
		pHead = pHead->pNext;
	}

	return;
}

void ConcatList(struct Node **ppHead1, struct Node **ppHead2)
{
	struct Node *pTemp = NULL;

	if(NULL == *ppHead2)
		return;

	if(NULL == *ppHead1)
	{
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;	
		return;
	}
	
	pTemp = *ppHead1;
		
	while(pTemp->pNext != NULL)
		pTemp = pTemp->pNext;

	pTemp->pNext = *ppHead2;
	*ppHead2 = NULL;
}	

void ConcatAtPosition(struct Node **ppHead1, struct Node **ppHead2, int iPos)
{
	int iCount;
	struct Node *pTemp1 = NULL;
	struct Node *pTemp2 = NULL;

	iCount = CountNode(*ppHead1);

	if(iPos <= 0 || iPos > iCount + 1)
	{
		printf("Position is InValid\n");
		return;
	}

	if(NULL == *ppHead2)
		return;

	if(1 == iPos)
	{
		ConcatList(ppHead2, ppHead1);	
		*ppHead1 = *ppHead2;
		*ppHead2 = NULL;
		return;
	}

	pTemp1 = *ppHead1;
	iCount = 1;

	while(iCount < iPos - 1)
	{
		pTemp1 = pTemp1->pNext;
		iCount++;
	}

	pTemp2 = *ppHead2;
	
	while(pTemp2->pNext != NULL)
		pTemp2 = pTemp2->pNext;
	
	pTemp2->pNext = pTemp1->pNext;
	pTemp1->pNext = *ppHead2;
	*ppHead2 = NULL;
}

void ReverseDisplay(struct Node **ppHead)
{
	if(NULL == *ppHead)
		return;

	PhysicalReverse(ppHead);
	Display(*ppHead);
	PhysicalReverse(ppHead);
}

void PhysicalReverse(struct Node **ppHead)
{
	struct Node *pPrev = NULL;
	struct Node *pCurrent = *ppHead;
	struct Node *pNext = NULL;

	while(pCurrent != NULL)
	{
		pNext = pCurrent->pNext;
		pCurrent->pNext = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;	
	}
	
	*ppHead = pPrev;
}

void DeleteAllNode(struct Node **ppHead)
{
	struct Node *pTemp = *ppHead;

	while(pTemp != NULL)
	{
		*ppHead = pTemp->pNext;
		pTemp->pNext = NULL;
		free(pTemp);
		pTemp = *ppHead;
	}

	printf("\nALL NODES ARE DELETED Successfully\n");
}
