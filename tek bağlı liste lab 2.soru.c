//Listeye rastgele üretilmiþ 100 sayý eklensin, girilen tüm sayýlarý küçükten büyüðe sýralayan ve ekrana basan program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct node{
	int data;
	struct node *next;
};

struct node *Sort(struct node *head);
void Listele(struct node *head);

int main(){
	int i=0;
	srand((time)NULL);
	struct node *head=NULL;
	
	while(i<99){//random sayilar iceren liste tanimlanir
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=rand();
		temp->next=head;
		head=temp;
		i++;
	}
	Listele(head);
	printf("\n\nListenin guncel hali:\n");
	
	Sort(head);	
	Listele(head);

	
	return 0;	
}
		
struct node *Sort(struct node *head){//sorting islemi
	struct node *temp,*newNode;
	int gecici;
	for(newNode=head;newNode!=NULL;newNode=newNode->next){
		for(temp=newNode->next;temp!=NULL;temp=temp->next){
			if(newNode->data>temp->data){
				gecici=newNode->data;
				newNode->data=temp->data;
				temp->data=gecici;
			}
		}
	
	}
	
}

void Listele(struct node *head){//listenin eski ve yeni halini ekrana verir
	if(head==NULL){
		printf("bos liste");
	}else{
		while(head!=NULL){
			printf("%d->",head->data);
			head=head->next;	
		}
	}
	
}

	


