//GtJordan 06/Jan/17
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9


typedef struct binaryTree
{
    int value;
    struct binaryTree *pLeft;
    struct binaryTree * pRight;
}binTree;

binTree* create();
void menu(binTree* pRootNode);
void traverse (binTree* pRootNode);
binTree* preOrder(binTree* prootNode);
binTree* inOrder(binTree* prootNode);
binTree* postOrder(binTree* prootNode);
binTree* layOrder(binTree* prootNode); // TODO Code the Lay Order
int findHeight (binTree* pRootNode);
int numberOfLeafs (binTree* pRootNode);
binTree* deleteTree (binTree* pRootNode);
binTree* insert(binTree *pRootNode,int value);
void swap (binTree* pRootNode);
binTree* minValueNode(pRootNode);
binTree* delete(binTree *pRootNode,int value);

int main()
{
    binTree myBinTree;
    binTree *pMyBinTree=&myBinTree;
    pMyBinTree=create();
    

    system("pause");
    do
    {   system("cls");
        menu(pMyBinTree);
    }while(1);
    deleteTree(pMyBinTree);
    return 0;
}
///////////////////////////////////////////////////////
//---------Menu
void menu(binTree* pRootNode)
{
    char choice;
    int value=0;
    puts("\n+-+-+-+-+-+- Binary Tree Implimentation +-+-+-+-+-+-");
    printf("\nOperation:\n");
    puts("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Show (I/Pr/Po)\n");
    printf("4. Find Height\n");
    printf("5. Find Number of leaves\n");
    printf("6. Swap\n");
    printf("7. Delete Tree\n");
    printf("8. Exit");
    puts("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    printf("Select option: ");
    scanf(" %c",&choice);
    switch(choice)
    {
        case '1':
            printf("Insert the value to insert: ");
            scanf("%d",&value);
            insert(pRootNode,value);
            puts("Successfully inserted");
            system("pause");
            break;
        case '2':
            printf("Insert the value to delete: ");
            scanf("%d",&value);
            delete(pRootNode,value);
            puts("Successfully deleted");
            system("pause");
            break;
        case '3':
            traverse(pRootNode);
            system("pause");
            break;
        case '4':
            printf("\nHeight: %d\n",findHeight(pRootNode));
            system("pause");
            break;
        case '5':
            printf("\nNumber Of Leafs: %d\n",numberOfLeafs(pRootNode));
            system("pause");
            break;
        case '6':
            swap(pRootNode);
            puts("Successfully deleted");
            system("pause");
            break;
        case '7':
            deleteTree(pRootNode);
            puts("Tree Successfully deleted");
            system("pause");
            break;
        default:
            deleteTree(pRootNode);
            exit(0);
            break;
    }

}
//////////////////////////////////////////////////
 //----------create
binTree* create()
{
{
    int input[N],i,j,temp,found;
    time_t seconds;
    time(&seconds);
    srand(seconds);
    printf("\nGenerating Random Data: ");
    for(i=0;i<N;i)
    {
        temp=rand()%50;
        found=0;
        for(j=0;j<i;j++)
        {
            if (input[j]==temp)
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
           input[i++]=temp;
        }
    }
    for(i=0;i<N;i++)
    {
        printf("%d ",input[i]);
    }

    binTree *pRootNode=NULL;

    for(i=0;i<N;i++)
    {
        pRootNode=insert(pRootNode,input[i]);
    }
    puts("");
    return pRootNode;
}
}
///////////////////////////////////////////////
//-------insertion
binTree* insert(binTree* pRootNode,int value)
{
    binTree *temp=pRootNode;
    if(temp==NULL)
    {
        temp=(binTree *)malloc(sizeof(binTree));
        temp->value=value;
        temp->pLeft=temp->pRight=NULL;
    }
    else if(temp->value > value)
    {
        temp->pLeft=insert(temp->pLeft,value);
    }
    else if(temp->value < value)
    {
        temp->pRight=insert(temp->pRight,value);
    }
    return temp;

}
////////////////////////////////////////////////////////
//-------Traversal
void traverse(binTree* pRootNode)
{
    puts("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    printf("\nPreOrder: ");
    preOrder(pRootNode);
    puts("");
    printf("\nInOrder: ");
    inOrder(pRootNode);
    puts("");
    printf("\nPostOrder: ");
    postOrder(pRootNode);
    puts("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    return;
}
////-----Traversal:PreOrder
binTree* preOrder(binTree* pRootNode)
{
    if(pRootNode==NULL)
        return;
    printf("%d ",pRootNode->value);
    preOrder(pRootNode->pLeft);
    preOrder(pRootNode->pRight);
}
////-----Traversal:InOrder
binTree* inOrder(binTree* pRootNode)
{
    if(pRootNode==NULL)
        return;
    inOrder(pRootNode->pLeft);
    printf("%d ",pRootNode->value);
    inOrder(pRootNode->pRight);
}
////-----Traversal:PreOrder
binTree* postOrder(binTree* pRootNode)
{
    if(pRootNode==NULL)
        return;
    postOrder(pRootNode->pLeft);
    postOrder(pRootNode->pRight);
    printf("%d ",pRootNode->value);
}
//////////////////////////////////////////////////////

int findHeight (binTree* pRootNode)
{
    int lHeight,rHeight;
    if(pRootNode==NULL)
        return 0;
    else
    {
        lHeight=findHeight(pRootNode->pLeft);
        rHeight=findHeight(pRootNode->pRight);
        if(lHeight>=rHeight)
            return lHeight+1;
        else
            return rHeight+1;
    }
}

//////////////////////////////////////////////////////
int numberOfLeafs (binTree* pRootNode)
{
    int lAmount,rAmount;

    if(pRootNode==NULL)
        return 0;
    else if(pRootNode->pLeft==NULL && pRootNode->pRight==NULL)
    {
        return 1;
    }
    else
        return numberOfLeafs(pRootNode->pLeft)+ numberOfLeafs(pRootNode->pRight);

}
//////////////////////////////////////////////////////
binTree* deleteTree (binTree* pRootNode)
{
    if(pRootNode)
    {
        deleteTree(pRootNode->pLeft);
        deleteTree(pRootNode->pRight);
        free(pRootNode);
    }
    return NULL;
}
////////////////////////////////////////////////////////
void swap (binTree* pRootNode)
{
    binTree* temp=NULL;
    if (pRootNode==NULL)
        return;
    else
    {
        swap(pRootNode->pLeft);
        swap(pRootNode->pRight);
        temp=pRootNode->pLeft;
        pRootNode->pLeft=pRootNode->pRight;
        pRootNode->pRight=temp;
    }
    return;
}
//////////////////////////////////////////////////
//-----------DELETION
binTree* delete(binTree *pRootNode,int value)
{
    //binTree* temp;
    if(pRootNode==NULL)
    {   
        //printf("%d < %d",value,pRootNode->value);
        return pRootNode;
    }
    if(value < pRootNode->value)
    {
        //printf("%d < %d",value,pRootNode->value);
        pRootNode->pLeft=delete(pRootNode->pLeft,value);
    }
    else if(value > pRootNode->value)
    {
        //printf("%d > %d",value,pRootNode->value);
        pRootNode->pRight=delete(pRootNode->pRight,value);
    }
    
    else
    {
        //temp=pRootNode;
        if(pRootNode->pLeft==NULL)
        {
            binTree* temp=pRootNode->pRight;
            free(pRootNode);
            return temp;

        }
        else if(pRootNode->pRight==NULL)
        {
            binTree* temp=pRootNode->pLeft;
            free(pRootNode);
            return temp;
        }
        //printf("\nTwo children\n");
        binTree* temp=minValueNode(pRootNode->pRight);
        pRootNode->value=temp->value;
        pRootNode->pRight=delete(pRootNode->pRight,temp->value);

    }
    return pRootNode;
}
/////////////////////////////
binTree* minValueNode(pRootNode)
{
    binTree *temp=pRootNode;
    while(temp->pLeft !=NULL)
    {
        temp=temp->pLeft;
    }
    return temp;
}
