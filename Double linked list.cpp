#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char na[100];
	int roll;
	struct student *next;
	struct student *prev;
};
void create();
void display();
void beginning();
void end();
void after(int pos);
void del_beg();
void del_end();
void del_after(int pos);
void del_before(int pos);
void reverse();
void sort();
void delete_range();
int getlen();
struct student *head,*tail;
main()
{
	int ch,pos,check,pos1,pos2;
    head=tail=NULL;
    struct student *t;
    while(1)
    {
    	printf("Enter 1 to create or 2 to display or 3 to insert beginning 4 to insert at end 5 to insert after a node 6 to delete from begining 7 to delete from the end 8 to del after a node 9 to delete before a node 10 to reverse 11 to sort 12 to delete nodes in a specific range 13 to exit-");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			create();
    			break;
    		case 2:
    			display();
    			break;
    		case 3:
    			beginning();
    			break;
    		case 4:
    			end();
    			break;
    		case 5:
    			printf("Enetr the position");
    			scanf("%d",&pos2);
				after(pos2);
    			break;
    		case 6:
    			del_beg();
    			break;
    		case 7:
    			del_end();
    			break;
    		case 8:
    			printf("Enter the position of the node");
    			scanf("%d",&pos1);
				del_after(pos1);
    			break;
    		case 9:
    			printf("Enter the position of the node");
    			scanf("%d",&pos2);
				del_before(pos2);
    			break;
    		case 10:
    			reverse();
    			break;
    		case 11:
    			sort();
    			break;
    		case 12:
    			delete_range();
    			break;
    		case 13:
    			exit(1);
		}
	
}
}
void create()
{
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	printf("Enter the roll no. of the student-");
	scanf("%d",&temp->roll);
	fflush(stdin);
	printf("\nEnter the student name-");
	gets(temp->na);
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	head=tail=temp;
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}
void display()
{
	struct student *t=head;
	if(t==NULL)
	printf("List is empty\n");
	else
	{
	while(t!=NULL)
	{
		printf("Name of the student is-");
		puts(t->na);
		printf("\nRoll no. of the student is-%d\n",t->roll);
		t=t->next;
	}
}
}
void beginning()
{
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	scanf("%d",&temp->roll);
	fflush(stdin);
	gets(temp->na);
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL)
	head=tail=NULL;
	else
	{
		struct student *t=head;
		temp->next=t;
		t->prev=temp;
		head=temp;
	}
}
void end()
{
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	scanf("%d",&temp->roll);
	fflush(stdin);
	gets(temp->na);
	temp->next=NULL;
	temp->prev=NULL;
	struct student *t=head;
	if(t==NULL)
	head=tail=NULL;
	else
	{
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=temp;
	temp->prev=t;
	tail=temp;
}
}
void after(int pos)
{
	int c,count;
	c=1;
	count=0;
	struct student *t=head;
	struct student *temp=(struct student*)malloc(sizeof(struct student));
	scanf("%d",&temp->roll);
	fflush(stdin);
	gets(temp->na);
	temp->next=NULL;
	temp->prev=NULL;
	while(c<pos)
	{
		t=t->next;
		c++;
	}
	struct student *p=t->next;
	temp->next=t->next;
	temp->prev=t;
	t->next=temp;
	if(p!=NULL)
	p->prev=temp;
	else
	tail=temp;
}
void del_beg()
{
	struct student *t=head;
	if(t==NULL)
	printf("List is Empty");
	else
	{
		struct student *temp=head;
		head=temp->next;
		head->prev=NULL;
		free(temp);
	}
}
void del_end()
{
    struct student *t=head;
	if(t==NULL)
	printf("List is Empty");
	else
	{
		while(t->next!=NULL)
		t=t->next;
		struct student *temp=t;
		struct student *before=temp->prev;
		before->next=NULL;
		tail=before;
		free(temp);
	}	
}
void del_after(int pos)
{
	struct student *t=head;
	int c=1;
	while(c<pos)
	{
	t=t->next;
	c++;
}
struct student *temp=t->next;
t->next=temp->next;
struct student *before=temp->next;
before->prev=t;
free(temp);	
}
void del_before(int pos)
{
	struct student *t=head;
	int c=1;
	while(c<pos-1)
	{
	t=t->next;
	c++;
}
struct student *temp=t;
struct student *before=t->prev;
before->next=t->next;
struct student *after=t->next;
after->prev=before;
free(temp);
}
	void delete_range()
{
	int l=getlen();
	struct student *t=head;
	struct student *d;
	int pos1,pos2;
	int c=1;
	printf("Enter the starting and ending node-");
	scanf("%d %d",&pos1,&pos2);
	if(pos1==1 && pos2==l)
	{
		struct student *del;
		while(t!=NULL)
		{
			del=t;
			t=t->next;
			free(del);
		}
		head=NULL;
	}
	else
	{
	while(c<pos1)
	{
		d=t;
		c++;
		t=t->next;
	}
	while(c<=pos2)
	{
		struct student *temp=t;
		t=temp->next;
		c++;
		free(temp);
	}
	if(pos1==1)
	{
	head=t;
	head->prev=NULL;
    }
    else if(pos2==l)
    {
    	tail=d;
    	tail->next=NULL;
	}
    else
    {
	d->next=t;
	t->prev=d;
}
}
}
void reverse()
{
	struct student *currentnode,*nextnode;
	currentnode=head;
	while(currentnode!=NULL)
	{
		nextnode=currentnode->next;
		currentnode->next=currentnode->prev;
		currentnode->prev=nextnode;
		currentnode=nextnode;
	}
	currentnode=head;
	head=tail;
}
void sort()
	{
		struct student *i,*j;
		int c,flag;
		char s[100];
		for(i=head;i->next!=NULL;i=i->next)
		{
			flag=0;
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->roll>j->roll)
				{
					flag=1;
					c=i->roll;
					i->roll=j->roll;
					j->roll=c;
					strcpy(s,i->na);
					strcpy(i->na,j->na);
					strcpy(j->na,s);
				}
			}
			if(flag==0)
			break;
		}
	}
	int getlen()
{
	struct student *t=head;
	int count=1;
	while(t!=NULL)
	
{
	count++;
	t=t->next;
}
	return count;
}
