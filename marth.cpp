#include<iostream.h>
#include<conio.h>
main(){
clrscr();
int choice;
     char x;
char name;
int number ,y;
cout<<"please enter the choice ";
cin>>choice;
switch(choice){
case 1:
{
cout<<" name : marthed ahmed mohammed ali \n department:computer engineering\n class:22 \n";

char x;
char name;
int number ,y;  /* define the variable of number of university*/
cout<<"enter the namuber of unversit(just number)\n";/* out put to desing*/
cin>>number; /* to input the number of university */
cout<<"enter the name (just one char)\n";/* the output to desing*/
cin>>name;  /* to input name user */
  cout<<"enter degree just intger\n";
  cin>>y;
}
break;
case 2:{
cout<<"enter the char (a,c,t)to show the department";
      cin>>x;
if(x=='a'){
cout<<"control eng\n";}
	  {
  if (x=='t')
cout<<"communiction eng\n";}
{
if(x=='c')
cout<<"computer eng\n";
}
}
break;
case 3:{
cout<<"enter the mark \n";
cin>>y;
if(y>=90 && y<=100)
cout<<"the grade is A\n";
if(y>=80 && y<=90)
cout<<"the grade is   b\n";
if (y>=70 && y<=80)
cout<<"the grade is c\n";
if(y>=60 && y<=70)
cout<<"the grade is d\n";
if(y>=50 && y<=60)
cout<<"the grade is  f\n";
}
break;
case 5:{
    cout<<"input the data of student:\n";
char sto='N';
while(sto!='Y'&&sto!='y')
{
cout<<"enter the name student (one char)\n";
cin>>name;
cout<<"enter the degree of student(intger number)\n";
cin>>y;
cout<<"enter the department of student(one char)\n";
cin>>x;
cout<<"are you finish(Y,N)press y to exit or n to contnio \n";
cin>>sto;

}
break;
default:
{
cout<<"error";
}}
getch();}}