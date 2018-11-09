#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>
void main()
{
 clrscr();
 char a[100],b[100];
 cin.getline(a,100);
long int len=strlen(a);
long int  x[26]={3,11,17,19,14,3,5,10,12,15,6,2,-2,-8,-10,-6,-14,-17,7,-18,-5,-15,1,-9,-17,-4},temp[26];
 int count=0;
 //int y=count%4;



 for(int i=0;i<len;i++)
 {

  for(int k=0;k<26;k++)
   temp[k]=x[k];

  for (int j=0;j<26;j++)          //Relation changer
  {
   if(j<25)
   x[j]=temp[j+1];
   else
   x[j]=temp[j-25];
   cout<<x[j]<<"\t";
  }


 long int z=a[i]-97;                //Ciphering
  b[i]=a[i]+x[z];
  if (b[i]<97)
   b[i]=b[i]+26;
  if(b[i]>122)
   b[i]=b[i]-26;
  cout<<"\n "<<b[i]<<endl;
  z=0;

  count++;
 }

getch();

}