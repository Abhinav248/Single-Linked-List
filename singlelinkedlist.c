# Single-Linked-List
// basic operations on single linked list


#include<stdio.h>
#include<stdlib.h>
#define max 1000


int size=0;


struct node
{
	int info;
	struct node *link;
};


void display(struct node *start);
struct node *addatbeg(struct node *start,int n);
struct node *addatend(struct node *start,int n);
struct node *deletenode(struct node *start,int n);
void search(struct node *start,int n);
int countnode(struct node *start);
struct node *addafter(struct node *start,int n,int num);
struct node *addbefore(struct node *start,int n,int num);
struct node*reverse(struct node *start);
struct node *deletefromfront(struct node *start);
struct node *deletefromend(struct node *start);
void deleteafter(struct node *start, int n);
struct node *deletebefore(struct node *start, int n);
struct node *sort(struct node *start);
struct node *deleteatposition(struct node *start, int position);


int main()
{
    printf("\n\nSINGLE LINKED LIST\n\n");
	struct node *start[10];
    int choice,n,num,pos,i,h;
	for(i=0;i<10;i++)
        start[i]=NULL;
	while(1)
	{
		printf("\n\nEnter your choice\n0: to initialise heads of all linked lists with NULL\n");
		printf("1: display\n2: add at beg.\n3: add at end\n4: delete a no.\n5: search\n6: count node");
		printf("\n7: addafter\n8: addbefore\n9: reverse\n10: delete from front\n11: delete from end");
		printf("\n12: delete after node\n13: delete before node\n14: iterative selection sort the list");
		printf("\n15: to delete node at a given position\n16: exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
            case 0:
                printf("\nAll linked lists are deleted\n");
                for(i=0;i<10;i++)
                    start[i]=NULL;
            break;
			case 1:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				display(start[h-1]);
				break;
			case 2:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				printf("\nenter a no. to be inserted at beg.\n");
				scanf("%d",&n);
				start[h-1]=addatbeg(start[h-1],n);
				break;
			case 3:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
             	printf("\nenter no. to be inserted at the end\n");
                scanf("%d",&n);
                start[h-1]=addatend(start[h-1],n);
                break;
			case 4:
				printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
		    	printf("\nenter no. to be deleted\n");
                scanf("%d",&n);
                start[h-1]=deletenode(start[h-1],n);
                break;
			case 5:
				printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
			    printf("enter the no. to be searched\n");
				scanf("%d",&n);
				search(start[h-1],n);
				break;
			case 6:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				printf("\nno of node in list = : %d\n",countnode(start[h-1]));
				break;
			case 7:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				printf("\nenter the no. to be inserted\n");
				scanf("%d",&n);
				printf("\nenter the value in the list\n");
				scanf("%d",&num);
				start[h-1]=addafter(start[h-1],n,num);
				break;
			case 8:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				printf("\nenter the no. to be inserted\n");
				scanf("%d",&n);
				printf("\nenter the value in the list\n");
				scanf("%d",&num);
				start[h-1]=addbefore(start[h-1],n,num);
				break;
			case 9:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				start[h-1]=reverse(start[h-1]);
				break;
			case 10:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				start[h-1]=deletefromfront(start[h-1]);
				break;
			case 11:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				start[h-1]=deletefromend(start[h-1]);
				break;
			case 12:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				printf("\nenter a node no. i.e. info \n");
				scanf("%d",&n);
				deleteafter(start[h-1],n);
				break;
			case 13:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				printf("\nenter a node no. i.e. info \n ");
				scanf("%d",&n);
				start[h-1]=deletebefore(start[h-1],n);
				break;
			case 14:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				start[h-1]=sort(start[h-1]);
				break;
			case 15:
			    printf("\nEnter list no. from array\n");
			    scanf("%d",&h);
				printf("\nenter position of node to be deleted\n");
				scanf("%d",&pos);
				start[h-1]=deleteatposition(start[h-1],pos);
				break;
            case 16:
                return 0;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}


void display(struct node *start)
{
	if(start==NULL)
        printf("\nlist is empty\n");
	else
	{
		printf("\nthe list is \n");
		while(start!=NULL)
		{
			printf("%d\n",start->info);
			start=start->link;
		}
	}
}


struct node *addatbeg(struct node *start,int n)
{
    size++;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->info=n;
	temp->link=start;
	return temp;
}


struct node *addatend(struct node *start,int n)
{
	struct node *temp,*p;
	size++;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=n;
    temp->link=NULL;
	if(start==NULL)
        return temp;
    else
    {
        p=start;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
        return start;
    }
}


struct node *deletenode(struct node *start,int n)
{
	struct node *p,*temp;
	if(start==NULL)
        return start;
	p=start;
	if(p->info==n)
	{
		size--;
		return p->link;
	}
	while(p->link!=NULL)
	{
		if(p->link->info==n)
		{
			size--;
			p->link=p->link->link;
			return start;
		}
		p=p->link;
	}
	printf("\n%d is not in the list\n",n);
	return start;
}


void search(struct node *start,int n)
{
	int pos=1;
	while(start!=NULL)
	{
		if(start->info==n)
		{
			printf("\n%d is found in node %d : \n",n,pos);
			return;
		}
		start=start->link;
		pos++;
	}
	printf("\n%d is not found in the list\n",n);
}


int countnode(struct node *start)
{
    int c=0;
    while(start!=NULL)
    {
        start=start->link;
        c++;
    }
	return c;
}


struct node *addafter(struct node *start,int n,int num)
{
	if(start==NULL)
	{
		printf("list is empty\n");
		return start;
	}
	struct node *temp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->info==num)
		{
			size++;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->info=n;
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	printf("%d is not found in the list \n",num);
	return start;
}


struct node *addbefore(struct node *start,int n,int num)
{
	struct node *temp,*p;
	if(!start)
        return start;
	p=start;
	if(p->info==num)
	{
		size++;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->info=n;
		temp->link=p;
		start=temp;
		return start;
	}
	while(p!=NULL)
	{
	    if(p->link==NULL && p->info!=num)
            break;
		if(p->link->info==num)
		{
			size++;
			temp=(struct node*)malloc(sizeof(struct node));
			temp->info=n;
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	printf("%d is not found in the list\n",num);
	return start;
}


/*struct node *reverse(struct node *start)//iterative
{
	struct node *prev,*p,*next;
	prev=NULL;
	p=start;
	while(p!=NULL)
	{
		next=p->link;
		p->link=prev;
		prev=p;
		p=next;
	}
	start=prev;
	return start;
}*/


struct node *reverse(struct node *start)//recursive
{
    if(start==NULL || start->link==NULL)
        return start;
    struct node *newstart=reverse(start->link);
    start->link->link=start;
    start->link=NULL;
    return newstart;
}


struct node *deletefromfront(struct node *start)
{
	struct node *p=start;
	if(p==NULL)
	{
		printf("empty list\n");
		return start;
	}
	size--;
	printf("%d is deleted\n",p->info);
	start=p->link;
	return start;
}


struct node *deletefromend(struct node *start)
{
	struct node *p=start,*t;
	if(p==NULL)
	{
		printf("empty list\n");
		return start;
	}
	if(p->link==NULL)
	{
		size--;
		printf("%d id deleted\n",p->info);
		start=p->link;
		return start;
	}
	while(p->link->link!=NULL)
	{
		p=p->link;
	}
	size--;
	t=p->link;
	printf("%d is deleted\n",t->info);
	p->link=NULL;
	return start;
}


void deleteafter(struct node *start, int n)
{
	struct node *p=start,*t;
	if(p==NULL)
	{
		printf("empty list\n");
		return;
	}
	if(p->link==NULL)
	{
		printf("sorry !\nno node after %d\n",p->info);
		return;
	}
	while(p->info!=n)
	{
		p=p->link;
	}
	if(p->link==NULL)
	{
		printf("sorry ! \n no node after %d\n",p->info);
		return;
	}
	else
	{
		size--;
		t=p->link;
     	printf("%d is deleted\n",t->info);
    	p->link=t->link;
    	return;
	}
	printf("%d is not in the list\n",n);
}


struct node *deletebefore(struct node *start, int n)
{
	struct node *p=start,*t;
	if(p==NULL)
	{
		printf("empty list\n");
		return start;
	}
	if(p->info==n)
	{
		printf("sorry ! \n no node before %d\n",n);
		return start;
	}
	if(p->link->info==n)
	{
		size--;
		printf("%d is deleted\n",p->info);
		start=p->link;
		return start;
	}
	while(p->link->info!=n)
	{
		p=p->link;
		if(p->link==NULL)
		{
			printf("%d is not in the list\n",n);
			return start;
		}
	}
	t=start;
	while(t->link!=p)
	{
		t=t->link;
	}
	size--;
	printf("%d is deleted\n",p->info);
	t->link=p->link;
	return start;
}


//iterative selection sort
struct node *sort(struct node *start)
{
    struct node *temp1,*temp2,*min;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp2=(struct node*)malloc(sizeof(struct node));
    min=(struct node*)malloc(sizeof(struct node));
    int temp;
	if(start==NULL||start->link==NULL)
    {
        display(start);
        return start;
    }
    else if((start->link->link==NULL)&&(start->info>start->link->info))
    {
        start->link->link=start;
        start=start->link;
        start->link->link=NULL;
        display(start);
        return start;
    }
    else
    {
        for(temp1=start;temp1->link->link!=NULL;temp1=temp1->link)
        {
            min=temp1;
            for(temp2=temp1->link;temp2->link!=NULL;temp2=temp2->link)
            {

                if(temp2->info<min->info)
                {
                    min=temp2;
                }
            }
            if(temp2->link==NULL && temp2->info<min->info)
            {
                min=temp2;
            }
            temp=min->info;
            min->info=temp1->info;
            temp1->info=temp;
        }
        display(start);
        return start;
    }
}


struct node *deleteatposition(struct node *start, int position)
{
    if(position>countnode(start) || position<1)
        return start;
    if(position==1)
        start=start->link;
    else
    {
        int c=2;
        struct node *temp=start;
        while((c++)!=position)
            temp=temp->link;
        temp->link=temp->link->link;
    }
    return start;
};


