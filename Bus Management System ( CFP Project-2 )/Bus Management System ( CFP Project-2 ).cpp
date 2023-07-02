#include<stdio.h>
void seatfunc();
void agefunc();
void details();
void baggagefunc();
int 
seatno[48],i,num,seatbooked[48],n,c1,seat,window,j,w,occupied,remainingseats=48;
float 
fare[48],win[48],sumfare,sumwin,sumbaggage,baggage,b,total,discount=0;
int mass;
int child=0,ladies=0,adult=0,senior=0,age;
int main()
{
sumbaggage=0;
for(i=0;i<48;i++)
{
seatno[i]=i+1;
}
while(1)
{
for(i=0;i<48;i++)
{
fare[i]=48;
win[i]=0;
}
printf("\\Welcome to SAPTCO VIP Bus Service from Makkah to Madina\\\n");
while(1)
{
printf("\nHow many Seats do you want to book?\n");
scanf("%d",&num);
if(num>0&&num<remainingseats)
break;
else
printf("\nInvalid Input\n");
}
seatfunc();
printf("\n********************************************\n");
agefunc();
printf("\n********************************************\n");
baggagefunc();
printf("\n********************************************\n"); 
details();
printf("\n********************************************\n");
// printf("\n");
// scanf(""); 
}
getchar();
return 0;
}
void seatfunc()
{
printf("\nAvailable Seats\n");
for(i=0;i<48;i++)
{
printf("\t%d\t",seatno[i]);
if ((i+1)%4==0)
printf("\n");
}
int c=1;
printf("\nAvailable Window Seats(6%% Additional Charges)\n\n");
for(i=0;i<48;i++)
{
for(j=0,w=1;w<=48;j++)
{
if (seatno[i]==w)
{
printf("\t%d\t",seatno[i]);
if (c%4==0)
printf("\n");
c++;
}
if(j%2==0)
w=w+3;
else
w=w+1;
}
}
 printf("\nSeat no 9 and 10 are reseved for Ladies");
printf("\nEnter the seat numbers\nSeat Numbers marked as '0' mean already booked\n");
for(i=0;i<num;i++)
{
printf("Seat Number of Passenger %d:",i+1);
scanf("%d",&seat);
for(j=0,w=1;w<=48;j++)
{
if (seat==w)
{
win[i]=2.88;
printf("\nYou booked a Window Seat with 6%% Additional Charges\n\n");
}
if(j%2==0)
w=w+3;
else
w=w+1;
}
occupied=1;
for(j=0;j<48;j++)
{
if(seat==seatno[j]);
{
occupied=0;
break;
}
}
if(seat==23||seat==24)
{
printf("\nOnly for Ladies");
printf("\nDo you want to reserve?");
printf("\nPress 1 for Yes\nPress 2 for No\n");
scanf("%d",&c1);
if(c1==2)
{
i--;
printf("\nSelect Another Seat:");
}
else
{
seatbooked[i]=seat;
remainingseats--;
ladies++;
}
}
if (seat<=0||seat>48||occupied==1)
{
if((occupied==1&&seat!=0))
printf("\nAlready Booked\nEnter another seat\n\n");
else
printf("\nEnter a Valid Seat Number\n\n");
i--;
}
if(seat==2)
{
printf("\nReserved for Helper\n");
printf("\nChoose Another Seat\n");
i--;
}
else
{
if(seat==9||seat==10)
ladies++;
seatbooked[i]=seat;
remainingseats--;
}
}
for(i=0;i<num;i++)
{
for(n=0;n<48;n++)
{
if(seatno[n]==seatbooked[i])
seatno[n]=0;
}
}
}
void agefunc()
{
for(i=0;i<num;i++)
{
while(1)
{
printf("Enter the age of passenger %d: ",i+1);
scanf("%d",&age);
if(age>=2)
break;
if(age<=0)
printf("\nInvalid Input\n");
if(age<2)
{
printf("\nNo seat can be booked for children younger than 2 years\n\n");
}
}
if(age<=6)
{
if (child<=2)
{
fare[i]=(fare[i]/100)*48;
win[i]=(win[i]/100)*48;
printf("\n48%% Concession Given to Child no %d\n\n",child+1);
printf("\nSeat Type= Child\n\n");
child++;
}
else
{
fare[i]=(fare[i]/100)*67;
win[i]=(win[i]/100)*67;
}
}
else if(age>=65)
{
if (senior<=2)
{
fare[i]=(fare[i]/100)*52;
win[i]=(win[i]/100)*52;
printf("\n52%% Concession Given to senior no %d\n\n",senior+1);
printf("\nSeat Type= Senior\n\n");
senior++;
}
else
{
fare[i]=(fare[i]/100)*78;
win[i]=(win[i]/100)*78;
}
}
if (age>6&&age<65)
{
printf("\nSeat Type= Adult\n\n");
adult++;
}
}
}
void details()
{
for(i=0;i<num;i++)
sumfare+=fare[i];
for(i=0;i<num;i++)
sumwin+=win[i];
printf("\nReserved Seats are ");
for(i=0;i<num;i++)
printf("%d ",seatbooked[i]);
printf("\nSeniors=%d\nAdults=%d\nChildren=%d\nLadies=%d",senior,adult,child,ladies);
printf("\nSeats Fare: %.3f Riyaal",sumfare);
printf("\nWindow Side Charges: %.3f Riyaal",sumwin);
printf("\nExtra Baggage Charges: %.3f Riyaal",sumbaggage);
total=sumfare+sumwin+sumbaggage;
if(total>220)
{
discount=(total/100)*6;
}
printf("\nDiscount: %.3f Riyaal",discount);
printf("\nTotal Fare= %.3f Riyaal\n",total-discount);
}
void baggagefunc()
{
for(i=0;i<num;i++)
{
printf("\nPlease Enter the baggage mass in kg of Passenger %d: ",i+1);
scanf("%d",&mass);
if(mass<22)
{
baggage=0;
printf("\nNo Additional Charges\n");
}
else
 { 
if((mass-22)>18)
{
printf("\nMaximum Additional allowed baggage is 18 kg\nYour Additional baggage is %d kg\n",mass-22);
i--;
printf("\nReEnter the Mass within Limit");
} 
else
{
baggage=(mass-22)*5;
sumbaggage+=baggage;
printf("\nAdditional baggage Charges= %.3f Riyaal",baggage);
}
}

}

}








