#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>
void main()
{
 clrscr();
 char a[100],b[100],c[100],d[100],alp[26];
 cin.getline(a,100);
 int count=0,len=strlen(a),h,z,q;
 int y[26], x[26]={3,11,17,19,14,3,5,10,12,15,6,2,-2,-8,-10,-6,-14,-17,7,-18,-5,-15,1,-9,-17,-4},temp[26];
 //int y=count%4;

 for(int al=0; al<26; al++)       //Alphabet
  alp[al]=char(al+97);

 for(int i=0;i<len;i++)           //Rotor 1
 {
  for(int k=0;k<26;k++)
   temp[k]=x[k];

  for (int j=0;j<26;j++)          //Relation Changer
  {
   if(j<25)
   x[j]=temp[j+1];
   else
   x[j]=temp[j-25];
  // cout<<x[j]<<"\t";
  }

  for(int l=0; l<26; l++)         //Inverse Motor Relation
  {
   h=alp[l]+x[l];
   if(h>122)
    h-=26;
   else if (h<97)
    h+=26;
   y[h-97]=x[l];
  }

  z=a[i]-97;                      //Ciphering
  q=a[i]+x[z];
  if (q<97)
   b[i]=q+26;
  else if(q>122)
   b[i]=q-26;
  else
   b[i]=q;
  //cout<<endl<<"Rotor 1:"<<b[i];
  z=0; q=0;
  count++;

  switch(b[i])                    //Reflector
  {
   case 'a': c[i]='f'; break;
   case 'b': c[i]='v'; break;
   case 'c': c[i]='p'; break;
   case 'd': c[i]='j'; break;
   case 'e': c[i]='i'; break;
   case 'f': c[i]='a'; break;
   case 'g': c[i]='o'; break;
   case 'h': c[i]='y'; break;
   case 'i': c[i]='e'; break;
   case 'j': c[i]='d'; break;
   case 'k': c[i]='r'; break;
   case 'l': c[i]='z'; break;
   case 'm': c[i]='x'; break;
   case 'n': c[i]='w'; break;
   case 'o': c[i]='g'; break;
   case 'p': c[i]='c'; break;
   case 'q': c[i]='t'; break;
   case 'r': c[i]='k'; break;
   case 's': c[i]='u'; break;
   case 't': c[i]='q'; break;
   case 'u': c[i]='s'; break;
   case 'v': c[i]='b'; break;
   case 'w': c[i]='n'; break;
   case 'x': c[i]='m'; break;
   case 'y': c[i]='h'; break;
   case 'z': c[i]='l'; break;
   default: cout<<"Reflector Error";
  }
  //cout<<endl<<"Reflector:"<<c[i];

  z=c[i]-97;                      //Ciphering
  q=c[i]-y[z];
  if (q<97)
   d[i]=q+26;
  else if(q>122)
   d[i]=q-26;
  else
   d[i]=q;
  //cout<<endl<<"Inverse Rotor 1:"<<d[i]<<endl;
  cout<<d[i];
 }
getch();
}