#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	int yas,no;
	char isim[100];
	struct student *next;
};

struct student *kayitEkle(struct student *head){//Yeni ogrenci kaydi alir
	struct student *bilgi=(struct student*)malloc(sizeof(struct student));
	
	printf("Ogrenci numarasini giriniz:");
	scanf("%d",&bilgi->no);
	printf("Ogrenci adini giriniz:");
	scanf("%s",bilgi->isim);
	printf("Ogrenci yasini giriniz:");
	scanf("%d",&bilgi->yas);
	
	bilgi->next=NULL;
	
	if(head==NULL)
		head=bilgi;
	else{
		struct student *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=bilgi;
	}

	return head;
	
}

void Listele(struct student *head){//kayitli ogrencileri listeler
	int i=1;
	if(head==NULL)
		printf("liste bos\n");
	else{
		while(head!=NULL)
		{
			printf("%d.%s %d %d\n",i,head->isim,head->no,head->yas);
			head=head->next;
			i++;
		}
	}
}

struct student *kayitArama(struct student *head,char name[100]){//Ýsimden kayit arar
	while(head!=NULL){
		if(strcmp(head->isim,name)==0){
			printf("Ýsim listede bulunmaktadir, bilgileri:%s,%d,%d\n",head->isim,head->no,head->yas);
			return head;
		}
		head=head->next;
	}
	printf("Ýsim listede bulunmamaktadir");
	return 0;
}

void enUzunAd(struct student *head){//En uzun isme sahip ogrenciyi ve isminin uzunlugunu yazdirir
	if(head==NULL){
		printf("liste bos.\n");
		return;
	}
	else{
		struct student *temp=head;
		while(head!=NULL){
			if(strlen(head->isim)>strlen(temp->isim)){
				temp=head;
			}
			head=head->next;	
		}
		printf("\nEn uzun isim:%s\nUzunlugu=%d",temp->isim,strlen(temp->isim));
	}
	
}

struct student *kayitSil(struct student *head,char *name){//Girilen ogrenciden bir sonraki dugumu siler
	struct student *temp=head;

	while(head!=NULL){
		if(strcmp(head->next->isim,name)==0)
			temp=head->next;
			struct student *temp1=temp->next;
			temp->next=temp1->next;
			free(temp1);//bellekte yer acma islemi
			return (head);
		head=head->next;	
		
	}
	printf("bu isim listede bulunmamaktadir.");
	return 0;
	
}

int main(){
	int secim;
	char arananAd[100];
	struct student *head=NULL;
	
	
	while (1) {
	        printf("1-Yeni Kayit\n2-Kayitlari listeleme\n3-Isim Arama\n4-En uzun isim sahibini bulma\n5-Secili Isimden sonraki kisinin kaydini silme\n6-Cikis: ");
	        scanf("%d", &secim);
	
	        switch (secim) {
	            case 1:
	                head = kayitEkle(head);
	                break;
	            case 2:
	                Listele(head);
	                break;
	            case 3:
	                printf("Bir isim giriniz: ");
	                scanf("%s", arananAd);
	                kayitArama(head, arananAd);
	                break;
	            case 4:
	                enUzunAd(head);
	                break;
	            case 5:
	                printf("Bir isim giriniz: ");
	                scanf("%s", arananAd);
	                head = kayitSil(head, arananAd);
	                break;
	            case 6:
	                printf("Cikis yapildi\n");
	                exit(0);
	            default:
	                printf("Gecersiz secim\n");
	        }
	    }

	return 0;
}
