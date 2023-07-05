#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
struct moviedetails
{
	char name[25];
	char phone[15];
	int seat;
	int id;
};
int changeprize(int);
void reservation(int [],int,int );
int choice1();
void cancel(int [],int);
void ticket1(int choice,char name[10],int id2,int price);
void ticket2(int choice,char name[10],int id2,int price);
void ticket3(int choice,char name[10],int id2,int price);
int cmovie();
int movie();
void details();
struct moviedetails p1[300],p2[300],p3[300];
int count=0;
int id2=1000;
int main()
{
	int s1[100],s2[100],s3[100],choice,price=500,selection,i;
	for (int z=0,y=0;z<=100;z++)
    {
        s1[z]=y;
        s2[z]=y;
        s3[z]=y;
    }

	int x;
	while(x!=5)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				price=changeprize(price);
				break;
			case 2:
				details();
				break;
			case 3:
				selection=movie();
				if(selection==1)
				reservation(s1,price,selection);
				else if(selection==2)
                    reservation(s2,price,selection);
                else if(selection==3)
                    reservation(s3,price,selection);
				count++;
				break;
			case 4:
				selection=cmovie();
				if(selection==1)
                    cancel(s1,selection);
				else if(selection==2)
                    cancel(s2,selection);
                else if(selection==3)
                    cancel(s3,selection);
				break;
			case 5:
				x=5;
				break;
			default:
				printf("Choice not available\n");
				break;
		}
	}
}
int changeprize(int prize)
{
	char pass[10],pak[10]="pass";
	printf("Enter the password to change price of ticket: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		printf("Please enter new price: ");
		scanf("%d",&prize);
		system("PAUSE");
		system("CLS");
	}
	else
		printf("The entered password is wrong! ");
	return prize;
}
void reservation(int array[],int price,int selection)
{
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else
				printf("*\t",i);
			if(i%10==0)
				printf("\n\n");
		}
		if(selection==1)
        {
           printf("Please enter your name: ");
		scanf(" %[^\n]%*[^\n]",&p1[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&p1[count].phone);
		printf("Which seat number you want? ");
		scanf("%d",&j);
		if (j>100||j<1)
			{
				printf("seat number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		p1[count].seat=j;
			ticket1(j,p1[count].name,id2,price);
		id2++;
        }
        if(selection==2)
        {
           printf("Please enter your name: ");
		scanf(" %[^\n]%*[^\n]",&p2[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&p2[count].phone);
		printf("Which seat number you want? ");
		scanf("%d",&j);
		if (j>100||j<1)
			{
				printf("seat number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		p2[count].seat=j;
			ticket2(j,p2[count].name,id2,price);
		id2++;
        }
        if(selection==3)
        {
           printf("Please enter your name: ");
		scanf(" %[^\n]%*[^\n]",&p3[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&p3[count].phone);
		printf("Which seat number you want? ");
		scanf("%d",&j);
		if (j>100||j<1)
			{
				printf("seat number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				scanf("%d",&j);
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				scanf("%d",&j);
			}
		else
			array[j]=1;
		p3[count].seat=j;
			ticket3(j,p3[count].name,id2,price);
		id2++;
        }

}
int choice1()
{
	int choice;
	printf("                 Simple Movie Ticket Booking System\n");
	printf(" ==================================================================\n");
	printf("||             1- To edit price of ticket (only admin):           ||\n");
	printf("||             2- To view reserved tickets (only admin):          ||\n");
	printf("||             3- To purchase ticket:                              ||\n");
	printf("||             4- To cancel the seat:                             ||\n");
	printf("||             5- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancel(int array[], int selection)
{
      int Cseat,i,stop;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);
	  if(selection==1)
      {
          for (i=0;i<300;i++)
	  {
	  		if(Cseat==p1[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat %d is cancelled",p1[i].name,p1[i].seat);
					 getch();
					 system("cls");
					 array[p1[i].seat]=0;
					 p1[i].seat=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
      }
      if(selection==2)
      {
          for (i=0;i<300;i++)
	  {
	  		if(Cseat==p2[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat %d is cancelled",p2[i].name,p2[i].seat);
                     getch();
                     system("cls");
					 array[p2[i].seat]=0;
					 p2[i].seat=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
      }
      if(selection==3)
      {
          for (i=0;i<300;i++)
	  {
	  		if(Cseat==p3[i].id)
	  		{
					 stop=5;
					 system("cls");
					 printf("%s your seat %d is cancelled",p3[i].name,p3[i].seat);
					 getch();
					 system("cls");
					 array[p3[i].seat]=0;
					 p3[i].seat=0;
					 i=300;
	  		}
	  }
	  if (stop!=5)
	  		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
      }

}
void ticket1(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Baahubali\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 10-12-2020\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		p1[count].id=id2;
        printf("\t============================================================\n");
        return;
}
void details()
{
	int i;
	char pass[10],pak[10]="pass";
	printf("Enter the password to see details: ");
	scanf("%s",&pass);
	if (strcmp(pass,pak)==0)
	{
		for (i=0;i<count;i++)
		{
		    if(p1[i].seat!=0)
			printf("seat no: %d is booked by %s booking id is %d\n",p1[i].seat,p1[i].name,p1[i].id);
			if(p2[i].seat!=0)
			printf("seat no: %d is booked by %s booking id is %d\n",p2[i].seat,p2[i].name,p2[i].id);
			if(p3[i].seat!=0)
			printf("seat no: %d is booked by %s booking id is %d\n",p3[i].seat,p3[i].name,p3[i].id);
		}
	}
	else
		printf("Entered password is wrong \n");
		system("PAUSE");
		system("CLS");

}
int movie()
{
	int i;
	system("cls");
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tpress 1 for Baahubali\n\n");
	printf("\t\t\tpress 2 for KGF\n\n");
	printf("\t\t\tpress 3 for Harry Potter Goblet of Fire\n");
	scanf("%d",&i);
	system("cls");
	return i;
}
void ticket2(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : KGF\n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 10-12-2020\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        p2[count].id=id2;
        printf("\t============================================================\n");
        return;
}
int cmovie()
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for Baahubali\n\n");
	printf("\t\t\tpress 2 for KGF\n\n");
	printf("\t\t\tpress 3 for Harry Potter GOF\n");
	scanf("%d",&i);
	return i;
}
void ticket3(int choice,char name[10],int id2,int price)
{
		system("cls");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Harry Potter GOF \n",id2);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 10-12-2020\n");
        printf("\t                                              Time      : 10:00pm\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        p3[count].id=id2;
        printf("\t============================================================\n");
        return;
}
