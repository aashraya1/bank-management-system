#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

struct data{
	int amt,id;
	char phone[20];
	char name[50];
}s[100];

void deposit();
void loan();
void view();
void del();
void edit();

int main(){
	int n,m,ak,i;
	FILE *fp;

	while(n!=6){
			printf(" 1.Loan  \n 2.Deposit \n 3.View record \n 4.Delete record \n 5.Edit \n 6.Exit \n");
	scanf("%d",&n);
	
		if(n==1){
			loan();
		
		}
		
		else if(n==2){
			deposit();
			
		}
		
		else if(n==3){
			view();
			
		}
		
		else if(n==4){
			del();
			
		}
		
		else if(n==5){
			edit();
			
		}
		
		else if(n==6){
			exit(0);
		}
		
		else{
			printf("Invalid! Try again \n");
		}
	}
		}
		
		
void loan(){
	int i,n;
	FILE *f;
	printf("How many record do you want to enter? \n");
	scanf("%d",&n);
	f = fopen("Loan.txt","a");
	
		for(i=1;i<=n;i++){
			printf("Enter the record of the person taking a loan:ID, First name, amount, phone number. Press enter after every entry.\n");
			scanf("%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone);
			fprintf(f,"%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
		}
		fclose(f);
}

void deposit(){
	int n,i;
	FILE *fp;
	
	printf("How many record do you want to enter? \n");
	scanf("%d",&n);
	
		fp = fopen("Deposit.txt","a");
		printf("Enter the record of the person making the deposit:ID, Name, amount, phone number \n");
		
	for(i=1;i<=n;i++){
			scanf("%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone);
			fprintf(fp,"%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
		}
		fclose(fp);
}

void view(){
	int i,n,d;
	FILE *a;
	printf("Press 1 to view loan record and 2 to view deposit record \n");
	scanf("%d",&n);
	
	if(n==1){
		a=fopen("Loan.txt","r");
		printf("Enter the ID of the person that you want to view \n");
	scanf("%d",&d);
	while(fscanf(a,"%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone)!=EOF){
		if(s[i].id==d){
			printf("%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
		}
	}
	fclose(a);
	}
	
	else if(n==2){
		a=fopen("Deposit.txt","r");
			printf("Enter the ID of the person that you want to view \n");
	scanf("%d",&d);
	while(fscanf(a,"%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone)!=EOF){
		if(s[i].id==d){
			printf("%d %s %d %s",s[i].id,s[i].name,s[i].amt,s[i].phone);
		}
	}
	fclose(a);
}
	else{
		printf("Please press 1 for loan or 2 for deposit \n");
	}
}

void del(){
	int r,i=0,l;
	FILE *b,*c;
	printf("Press 1 to remove loan data or 2 for removing deposit data \n");
	scanf("%d",&l);
	
	if(l==1){
	b=fopen("Loan.txt","r");
		printf("Enter the ID of the person that you want to remove \n");
	scanf("%d",&r);	
	while(fscanf(b,"%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone)!=EOF){
		if(s[i].id!=r){
			c=fopen("temp.txt","a");
			fprintf(c,"%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
			fclose(c);
		}
	}
		fclose(b);
		remove("Loan.txt");
		rename("temp.txt","Loan.txt");
	
	}
	else if(l==2){
	b=fopen("Deposit.txt","r");
			printf("Enter the ID of the person that you want to remove \n");
	scanf("%d",&r);
	while(fscanf(b,"%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone)!=EOF){
		if(s[i].id!=r){
			c=fopen("ct.txt","a");
			fprintf(c,"%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
			fclose(c);
		}
	}
		fclose(b);
		remove("Deposit.txt");
		rename("ct.txt","Deposit.txt");
	
}
	else{
		printf("Press either 1 or 2 \n");
	}
}

void edit(){
	int r,i=0,l;
	FILE *b,*c;
	printf("Press 1 to edit loan data or 2 for editing deposit data \n");
	scanf("%d",&l);
	
	if(l==1){
	b=fopen("Loan.txt","r");
		printf("Enter the ID of the person that you want to edit \n");
	scanf("%d",&r);	
	while(fscanf(b,"%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone)!=EOF){
		if(s[i].id!=r){
			c=fopen("temp.txt","a");
			fprintf(c,"%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
			fclose(c);
		}
		else{
			printf("Enter new record :ID, Name, Amount, Phone number \n");
			scanf("%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone);
			c=fopen("temp.txt","a");
			fprintf(c,"%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
			fclose(c);
		}
	}
		fclose(b);
		remove("Loan.txt");
		rename("temp.txt","Loan.txt");
	
	}
	else if(l==2){
	b=fopen("Deposit.txt","r");
			printf("Enter the ID of the person that you want to remove \n");
	scanf("%d",&r);
	while(fscanf(b,"%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone)!=EOF){
		if(s[i].id!=r){
			c=fopen("ct.txt","a");
			fprintf(c,"%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
			fclose(c);
		}
			else{
			printf("Enter new record :ID, Name, Amount, Phone number \n");
			scanf("%d%s%d%s",&s[i].id,s[i].name,&s[i].amt,&s[i].phone);
			c=fopen("ct.txt","a");
			fprintf(c,"%d %s %d %s \n",s[i].id,s[i].name,s[i].amt,s[i].phone);
			fclose(c);
		}
		
	}
		fclose(b);
		remove("Deposit.txt");
		rename("ct.txt","Deposit.txt");
	
}
	else{
		printf("Press either 1 or 2 \n");
	}
	
	
	
}


