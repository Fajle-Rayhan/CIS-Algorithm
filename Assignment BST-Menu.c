#include<stdio.h>
#include<stdlib.h>

//linked list node
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
}; //structure type define anther NODE
typedef struct node NODE;

//**********************************************

//NODE* For pointer to integer Cast
NODE *maximum(NODE *x){
    while(x->rlink != NULL){
        x = x->rlink;
    }
    return x->info;
}

NODE *minimum(NODE *x){
    while(x->llink != NULL){
        x = x->llink;
    }
    return x->info;
}

//**********************************************

NODE *insert(NODE *root, int item)
{
    NODE *temp,*cur,*prev;

    //fist time allocation[
    temp=(NODE *)malloc(sizeof(NODE));
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
        return temp;
    //fist time allocation]

    prev=NULL;
    cur=root;
    while(cur!=NULL)
        {
            prev=cur;
            if(cur->info < item )
                cur=cur->rlink;
            else
                cur=cur->llink;

        }
        if(item<prev->info)
            prev->llink=temp;
        else
            prev->rlink=temp;
        return root;
}

//**********************************************

NODE *minValueNode(NODE *node)
{
    NODE *current = node;
/* loop to find the leftmost leaf */
    while (current->llink != NULL)
            current = current->llink;
    return current;
}

//**********************************************

NODE *delete_element(NODE *root,int key)
{
        if (root == NULL)
            return root;
        if (key < root->info)
            root->llink = delete_element(root->llink, key);
        else if (key > root->info)
            root->rlink = delete_element(root->rlink, key);
        else
            {
// node with only one child or no child
                if (root->llink == NULL)
                    {
                        NODE *temp = root->rlink;
                        free(root);
                        return temp;
                    }
                else if (root->rlink == NULL)
                    {
                        NODE *temp = root->llink;
                        free(root);
                        return temp;
                    }
// node with two children: Get the inorder successor (smallest
// in the right subtree)
                else
                {
                NODE *temp = minValueNode(root->rlink);
                root->info = temp->info;
                root->rlink = delete_element(root->rlink, temp->info);
                }
            }
        return root;
}

//**********************************************

int search_element(NODE *root,int key)
{
    NODE *cur;
    int n=0;
    cur=root;
    if (cur!=NULL)
        {
            if (key==cur->info)
                n=1;
            else if (key<cur->info)
                return search_element(cur->llink,key);
            else
                return search_element(cur->rlink,key);
        }
        else
            return n;
}

//**********************************************

void inorder(NODE *x)
{
    if(x != NULL)
        {
            inorder(x->llink);
            printf("%d ... ", x->info);
            inorder(x->rlink);
        }
}

//**********************************************
//**********************************************

void main()
{
    int item,ch,key,n, a, x;
    NODE *root;
    root = NULL;

    while (1)
    {
        printf("\n\nEnter the choice\n1.Maximum\n2.Minimum\n3.Insert an Element\n4.Delete an Element\n5.Search an Element\n0:Exit");
        printf("\n\nChoice: ");
        scanf("%d",&ch);
        switch(ch)
        {

            case 1:
                x = maximum(root);
                printf("\nmaximum number is %d\n", x);

                break;
            case 2:

                x = minimum(root);
                printf("\nminimum number is %d\n", x);

                break;
            case 3: //insert
                    printf("Enter the elements: ");
                    scanf("%d",&a);
                    root=insert(root, a);

                    printf("\n");
                    inorder(root); //Inorder Sort Tree

                break;
            case 4: //delete
                    if (root==NULL)
                        printf("List Empty\n");
                    else
                    {
                        printf("Enter the element: ");
                        scanf("%d",&key);
                        n=search_element(root,key);
                    if(n)
                        root=delete_element(root,key);
                    else
                        printf("Not found\n");
                    }

                    printf("\n");
                    inorder(root); //Inorder Sort Tree

                break;
            case 5: //search
                    if (root==NULL)
                        printf("List Empty\n");
                    else
                    {

                        printf("Enter the element: ");
                        scanf("%d",&key);
                        n=search_element(root,key);
                        if(n)
                            printf("\nNumber-Found\n");
                        else
                            printf("\nNot-Found\n");
                    }
                break;
            case 0: //exit
                exit(0);
            default: printf("\nWrong Choice\n");
        }
    }
}
