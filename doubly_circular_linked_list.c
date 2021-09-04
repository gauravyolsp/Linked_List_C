////////////////////////////////////////////////////////////////////////////////////////
//	HEADER FILES
////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////////////
//	STRUCTURE DECLARATION
//////////////////////////////////////////////////////////////////////////////////////

struct node
{
	struct node *pPrev;
	int iData;
	struct node *pNext;
};

////////////////////////////////////////////////////////////////////////////////////////
//	GLOBAL VARIABLES
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
//	FUNCTION DECLARATIONS
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
// 	INSERT
////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(struct node **, struct node **, int);
void InsertFirst(struct node **, struct node **, int);
void InsertAtPosition(struct node **, struct node **, int, int);

////////////////////////////////////////////////////////////////////////////////////////
//	DELETE
////////////////////////////////////////////////////////////////////////////////////////

int DeleteLast(struct node **, struct node **);
int DeleteFirst(struct node **, struct node **);
void DeleteAllNode(struct node **, struct node **);
int DeleteAtPosition(struct node **, struct node **, int);

////////////////////////////////////////////////////////////////////////////////////////
//	COUNT NODE
////////////////////////////////////////////////////////////////////////////////////////

int CountNode(struct node *, struct node *);

////////////////////////////////////////////////////////////////////////////////////////
//	DISPLAY
////////////////////////////////////////////////////////////////////////////////////////

void Display(struct node *, struct node *);

////////////////////////////////////////////////////////////////////////////////////////
//	SEARCH
////////////////////////////////////////////////////////////////////////////////////////

int SearchFirstOccurance(struct node *, struct node *, int);
int SearchLastOccurance(struct node *, struct node *, int);
int SearchAllOccurance(struct node *, struct node *, int);

////////////////////////////////////////////////////////////////////////////////////////
//	FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	int iPos;
	int iData;
	int iTemp;
	int iChoice;

	struct node *pFirst = NULL;
	struct node *pLast = NULL;
	struct node *pFirst1 = NULL;
	struct node *pLast1 = NULL;
	

	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Search\n4.Count\n5.Exit\n");
		printf("Enter your choice:\t");
		scanf("%d", &iChoice);
		
		if(iChoice <= 0 || iChoice > 8)
		{
			printf("Enter valid choice.\n");
			continue;
		}

		switch(iChoice)
		{
			case 1:	while(1)
				{
					printf("\n1.InsertFirst\n2.InsertLast\n3.InsertAtPosition\n4.Back\n");
					printf("Enter your choice:\t");
					scanf("%d", &iChoice);

					if(4 == iChoice)
						break;

					if(iChoice <= 0 || iChoice > 4)
					{
						printf("Enter valid choice.\n");
						continue;
					}

					if(3 == iChoice)
					{
						printf("\nEnter the position:\t");
						scanf("%d", &iPos);
						
						if(iPos <= 0 || iPos > (CountNode(pFirst, pLast) + 1))
						{
							printf("Enter valid position.\n");
							continue;
						}
					}

					printf("Enter data to be inserted:\t");
					scanf("%d", &iData);

					switch(iChoice)
					{
						case 1:	InsertFirst(&pFirst, &pLast, iData);
							break;
						
						case 2: InsertLast(&pFirst, &pLast, iData);
							break;
	
						case 3: InsertAtPosition(&pFirst, &pLast, iData, iPos);
					}			

					Display(pFirst, pLast);
				}break;
				
			case 2: if(NULL == pFirst)
				{
					printf("Linked List Empty, Deletion Not Possible.\n");
					break;
				}
		
				while(1)
				{
					printf("\n1.DeleteFirst\n2.DeleteLast\n3.DeleteAtPosition\n4.Back\n");
					printf("Enter your choice:\t");
					scanf("%d", &iChoice);

					if(4 == iChoice)
						break;

					if(iChoice <= 0 || iChoice > 4)
					{
						printf("Enter valid choice.\n");
						continue;
					}

					switch(iChoice)
					{
						case 1: iData = DeleteFirst(&pFirst, &pLast);
							break;

						case 2: iData = DeleteLast(&pFirst, &pLast);
							break;

						case 3: if(NULL == pFirst)
							{
								printf("Linked List is Empty\n");
								continue;
							}
								
							printf("\nEnter the position:\t");
							scanf("%d", &iPos);
						
							if(iPos <= 0 || iPos > CountNode(pFirst, pLast))
							{
								printf("Enter valid position.\n");
								continue;
							}
							iData = DeleteAtPosition(&pFirst, &pLast, iPos);
					}

					if(-1 != iData)
						printf("\nDeleted data is %d\n", iData);

					Display(pFirst, pLast);
				}break;

			case 3:	if(NULL == pFirst)
				{
					printf("Linked List Empty, Searching Not Possible.\n");
					break;
				}

				while(1)
				{
					printf("\n1.SearchFirstOccurance\n2.SearchLastOccurance\n3.SearchAllOccurance\n4.Back\n");
					printf("Enter your choice:\t");
					scanf("%d", &iChoice);
				
					if(4 == iChoice)
						break;

					if(iChoice <= 0 || iChoice > 4)
					{
						printf("Enter valid choice.\n");
						continue;
					}
					Display(pFirst, pLast);

					printf("Enter data to search:\t");
					scanf("%d", &iData);

					switch(iChoice)
					{
						case 1: iPos = SearchFirstOccurance(pFirst, pLast, iData);
							if(-1 == iPos)
								printf("Linked List is Empty\n");
							else if(0 != iPos)	
								printf("%d is found at %d location\n", iData, iPos);

							else
								printf("Data not Found\n");

							break;

						case 2: iPos = SearchLastOccurance(pFirst, pLast, iData);
							if(-1 == iPos)
								printf("Linked List is Empty\n");
							else if(0 != iPos)	
								printf("%d is found at %d location\n", iData, iPos);
							else
								printf("Data not Found\n");
							break;

						case 3: iPos = SearchAllOccurance(pFirst, pLast, iData);
							printf("%d is found %d time.\n", iData, iPos);
					}
				}break;

			case 4: printf("Total nodes present : %d\n", CountNode(pFirst, pLast));
				break;

			case 5: DeleteAllNode(&pFirst, &pLast);
				printf("Bye...\n");
				Display(pFirst, pLast);
				return 0;
		}
	}
}

void InsertFirst(struct node **ppHead, struct node **ppTail, int iData)
{
	struct node *pNewNode = NULL;
	
	pNewNode = (struct node *) malloc (sizeof(struct node));

	if(NULL == pNewNode)
	{	
		printf("Memory allocation failed\n");
		DeleteAllNode(ppHead, ppTail);
		return;
	}

	pNewNode->iData = iData;

	if(NULL == *ppHead)
	{
		*ppHead = *ppTail = pNewNode;
		(*ppTail)->pNext = *ppHead;
		(*ppHead)->pPrev = *ppTail;
		return;
	}

	pNewNode->pNext = *ppHead;
	(*ppHead)->pPrev = pNewNode;
	*ppHead = pNewNode;
	(*ppTail)->pNext = *ppHead;
	(*ppHead)->pPrev = *ppTail;
}

void InsertLast(struct node **ppHead, struct node **ppTail, int iData)
{
	struct node *pNewNode = NULL;

	pNewNode = (struct node *) malloc (sizeof(struct node));

	if(NULL == pNewNode)
	{
		printf("Memory allocation failed\n");
		DeleteAllNode(ppHead, ppTail);
		return;
	}
	
	pNewNode->iData = iData;

	if(NULL == *ppHead)
	{
		*ppHead = *ppTail = pNewNode;
		(*ppTail)->pNext = *ppHead;
		(*ppHead)->pPrev = *ppTail;
		return;
	}

	(*ppTail)->pNext = pNewNode;
	pNewNode->pPrev = *ppTail;
	*ppTail = pNewNode;
	(*ppTail)->pNext = *ppHead;
	(*ppHead)->pPrev = *ppTail;
}

void InsertAtPosition(struct node **ppHead, struct node **ppTail, int iNo, int iPos)
{
	int iCount;
	struct node *pTemp = NULL;
	struct node *pNewNode = NULL;

	iCount = CountNode(*ppHead, *ppTail);

	if(1 == iPos)
	{
		InsertFirst(ppHead, ppTail, iNo);
		return;
	}

	if(iPos == iCount + 1)
	{
		InsertLast(ppHead, ppTail, iNo);
		return;
	}

	pTemp = *ppHead;
	iCount = 1;

	while(iCount < iPos - 1)
	{
		iCount++;
		pTemp = pTemp->pNext;
	}

	pNewNode = (struct node *) malloc (sizeof(struct node));
	if(NULL == pNewNode)
	{
		printf("Memory allocation Failed\n");
		DeleteAllNode(ppHead, ppTail);
		return;
	}

	pNewNode->iData = iNo;

	pNewNode->pNext = pTemp->pNext;
	pTemp->pNext->pPrev = pNewNode;
	pTemp->pNext = pNewNode;
	pNewNode->pPrev = pTemp;
}

int DeleteFirst(struct node **ppHead, struct node **ppTail)
{
	int iDelData;

	if(NULL == *ppHead)
		return -1;

	iDelData = (*ppHead)->iData;	
	
	if(*ppHead == *ppTail)			// single node
	{
		(*ppHead)->pPrev = NULL;
		(*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
		return iDelData;
	}

	*ppHead = (*ppHead)->pNext;
	(*ppTail)->pNext->pPrev = NULL;			//First node ka pPrev NULL kiya
	(*ppTail)->pNext->pNext = NULL;			//First node ka pNext NULL kiya

	free((*ppTail)->pNext);
	(*ppHead)->pPrev = *ppTail;
	(*ppTail)->pNext = *ppHead;
	
	return iDelData;
}

int DeleteLast(struct node **ppHead, struct node **ppTail)
{
	int iDelData;

	if(NULL == *ppHead)	
		return -1;

	if(*ppHead == *ppTail)
	{
		(*ppHead)->pPrev = NULL;
		iDelData = (*ppHead)->iData;
		(*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead= *ppTail = NULL;
		return iDelData;
	}

	*ppTail = (*ppTail)->pPrev;
	(*ppTail)->pNext->pPrev = NULL;
	iDelData = (*ppTail)->pNext->iData;
	(*ppTail)->pNext->pNext = NULL;

	free((*ppTail)->pNext);
	(*ppHead)->pPrev = *ppTail;
	(*ppTail)->pNext = *ppHead;
	return iDelData;
}

int DeleteAtPosition(struct node **ppHead, struct node **ppTail, int iPos)
{
	int iValue;
	struct node *pTemp = NULL;

	if(NULL == *ppHead)
		return -1;

	if(1 == iPos)
		return DeleteFirst(ppHead, ppTail);

	if(iPos == CountNode(*ppHead, *ppTail))
		return DeleteLast(ppHead, ppTail);
	
	pTemp = *ppHead;
	iValue = 1;
	
	while(iValue < iPos)
	{
		iValue++;
		pTemp = pTemp->pNext;
	}
	
	pTemp->pPrev->pNext = pTemp->pNext;
	pTemp->pNext->pPrev = pTemp->pPrev;
	pTemp->pPrev = NULL;
	pTemp->pNext = NULL;

	iValue = pTemp->iData;
	free(pTemp);

	return iValue;   	
}

int SearchFirstOccurance(struct node *pHead, struct node *pTail, int iKey)
{
	int iCount = 1;

	if(NULL == pHead)
		return -1;

	do
	{
		if(pHead->iData == iKey)
			break;
		iCount++;		
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);

	if(pHead == pTail->pNext && iCount != 1)
		iCount = 0;

	return iCount;
}

int SearchLastOccurance(struct node *pHead, struct node *pTail, int iKey)
{
	int iCount = 0;
	int iLast = 0;

	if(NULL == pHead)
		return -1;

	do
	{
		iCount++;	
		if(pHead->iData == iKey)
			iLast = iCount;

		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);

	return iLast;
}

int SearchAllOccurance(struct node *pHead, struct node *pTail, int iKey)
{
	int iCount = 0;
		
	if(NULL == pHead)
		return -1;

	do
	{
		if(pHead->iData == iKey)
			iCount++;

		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	
	return iCount;
}

void Display(struct node *pHead, struct node *pTail)
{
	if(NULL == pHead)
	{
		printf("\nLinked List is Empty!!!\n");
		return;
	}

	printf("\nLinked List is:\n");
	do
	{
		printf("<-|%d|->", pHead->iData);
		pHead = pHead->pNext;
	}while(pHead != pTail->pNext);
	printf("\n");
}

int CountNode(struct node *pHead, struct node *pTail)
{
	int iCount = 0;

	if(NULL == pHead)
		return iCount;
	do
	{
		iCount++;
		pHead = pHead->pNext;	
	}while(pHead != pTail->pNext);

	return iCount;
}

void DeleteAllNode(struct node **ppHead, struct node **ppTail)
{
	if(NULL == *ppHead)
		return;

	while(*ppHead != *ppTail)
	{
		(*ppHead)->pPrev = NULL;
		*ppHead = (*ppHead)->pNext;
		(*ppTail)->pNext->pNext = NULL;
		free((*ppTail)->pNext);

		(*ppTail)->pNext = *ppHead;
	}

	(*ppHead)->pNext = NULL;
	(*ppHead)->pPrev = NULL;
	free(*ppHead);

	*ppHead = NULL;
	*ppTail = NULL;

	printf("\nAll Nodes Deleted Successfully\n");
}