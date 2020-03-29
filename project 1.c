#include<stdio.h>
#include<stdlib.h>
int* array;
unsigned int size=1;
int insert(void)
{
	int value;
	unsigned int position;
	printf("\nEnter value to change/add:");
	scanf("%d",&value);
    printf("\nEnter position to change/add:");
	scanf("%d",&position);
	position--;
	if(position<size)
	{
		printf("\nEntering new value");
		*(array+position)=value;
		printf("\nDone");
		return 0;
	}
	else
	{
		printf("\nPosition not present.\nValue will be entered in new element.");
        array=realloc(array,(size+1)*sizeof(int));
	    size++;
	    *(array+size-1)=value;
	    printf("\nValue entered in new element.");
        return 0;
	}
}
int delete(void)
{
	unsigned int position;
	printf("\nEnter position to delete:");
	scanf("%d",&position);
	position--;
	if(position>=size)
		{
			printf("\nWrong position entered./nNow exiting.");
			return 1;
		}
	else
		{
			printf("\nDeleting.");
			for(unsigned int i=position;i<size;i++)
				*(array+i)=*(array+i+1);
			free(array+size-1);
			size--;
			return 0;
		}
}
int rotate(void)
{
	int temp;
	unsigned int j=0;
	unsigned int no_elmts=0;
	printf("\nEnter number of elements to rotate by:");
	scanf("%d",&no_elmts);
	for(unsigned int i=0;i<no_elmts;i++)
	{
		temp=*(array);
		for(j=0;j<size-1;j++)
			*(array+j)=*(array+j+1);
		*(array+j)=temp;
	}
	return 0;
}
int odd_beginning(void)
{
	int temp;
	for(unsigned int i=0;i<size;i++)
		for(unsigned int j=0;j<size-1;j++)
		{
			if(*(array+j)%2==0)
			{
				temp=*(array+j);
				*(array+j)=*(array+j+1);
				*(array+j+1)=temp;
			}
		}
	return 0;
}
int even_beginning(void)
{
	int temp;
	for(unsigned int i=0;i<size;i++)
		for(unsigned int j=0;j<size-1;j++)
		{
			if(*(array+j)%2!=0)
			{
				temp=*(array+j);
				*(array+j)=*(array+j+1);
				*(array+j+1)=temp;
			}
		}
	return 0;
}
int largest(void)
{
	int large=*(array);
	for(unsigned int i=0;i<size;i++)
		if(large<*(array+i))
			large=*(array+i);
	printf("\nLargest element is %d",large);
	return 0;
}
int smallest(void)
{
	int small=*(array);
	for(unsigned int i=0;i<size;i++)
		if(small>*(array+i))
			small=*(array+i);
	printf("\nSmallest element is %d",small);
	return 0;
}
int display(void)
{
	for(unsigned int i=0;i<size;i++)
		printf("\n%d",*(array+i));
	return 0;
}
int main(void)
{
	array=(int*)malloc(size*sizeof(int));
	int option;
	menu:
	printf("\n1.Enter new element/update an element\n2.Delete a specific element\n3.Rotate elements\n4.Rearrange odd elements to the beginning\n5.Rearrange even elements to the beginning\n6.Find largest element\n7.Find smallest element\n8.Display the array\n9.exit\nEnter your choice:");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			insert();
			break;
		case 2:
			delete();
			break;
		case 3:
			rotate();
			break;
		case 4:
			odd_beginning();
			break;
		case 5:
			even_beginning();
			break;
		case 6:
			largest();
			break;
		case 7:
			smallest();
			break;
		case 8:
			display();
			break;
		case 9:
			free(array);
			return 0;
			break;
		default:
			printf("\nWrong choice entered.\nEnter correct choice.");
			break;
	}
	goto menu;
}
