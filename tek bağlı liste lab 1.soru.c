#include <stdio.h>
#include <stdlib.h>

//klavyeden -1 girilinceye kadar girilen tek sayýlarý listenin baþýna,çift sayýlarý listenin sonuna ekleyen 

struct node{
	int data;
	struct node *next;
};

struct node *basaEkle(struct node *head,int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> data =n;
	temp -> next = head;
	return temp;
}
struct node *sonaEkle(struct node *head,int n){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	
	temp -> data = n;
	temp -> next = NULL;
	
	if(head==NULL)
		return temp;
		
	struct node *temp1 = head;
	
	while(temp1 -> next != NULL)
		temp1 = temp1 -> next;
		
	temp1 -> next = temp;
	return head;
}

void printlist(struct node *head){
	int i = 1;
	while(head != NULL) {
		printf("%d\n",head -> data);
		head = head -> next;
		i++;
	}
}

int main(){
	
	struct node *head=NULL;
	
	int sayi;

	while(1){
		printf("bir sayi giriniz:");
		scanf("%d",&sayi);
		if(sayi==-1)
			break;
		else if(sayi%2==0)
			head=sonaEkle(head,sayi);
		else
			head=basaEkle(head,sayi);
	}
	printlist(head);
	return 0;
}


