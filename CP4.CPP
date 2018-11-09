#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>
void ref(char&);                   //Reflector
char rot1(char);                   //Rotor 1
char rot2(char);                   //Rotor 2
char rot3(char);                   //Rotor 3

char a1[100], b1[100], a2[100], b2[100], alp[26];
int count=0, h, z, q, len;
int r1i[26], r1t[26], r1[26]={3,11,17,19,14,3,5,10,12,15,6,2,-2,-8,-10,-6,-14,-17,7,-18,-5,-15,1,-9,-17,-4};
//int r2i[26], r2t[26], r2[26]={4,17,12,18,11,20,3,-7,16,7,10,-3,5,-6,9,-4,-3,-12,1,-13,-10,-18,-20,-11,-2,-24};
//int r3i[26], r3t[26], r3[26]={},r3t[26];

void main()
{
 clrscr();
 cin.getline(a1,100);
 len=strlen(a1);
 for(int al=0; al<26; al++)       //Alphabet
  alp[al]=char(al+97);

 for(int i=0;i<len;i++)           //Rotor 1
 {
  for(int k=0;k<26;k++)
   r1t[k]=r1[k];

  for (int j=0;j<26;j++)          //Relation Changer
  {
   if(j<25)
   r1[j]=r1t[j+1];
   else
   r1[j]=r1t[j-25];
  // cout<<r1[j]<<"\t";
  }

  for(int l=0; l<26; l++)         //Inverse Motor Relation
  {
   h=alp[l]+r1[l];
   if(h>122)
    h-=26;
   else if (h<97)
    h+=26;
   r1i[h-97]=r1[l];
  }

  z=a1[i]-97;                      //Ciphering
  q=a1[i]+r1[z];
  if (q<97)
   b1[i]=q+26;
  else if(q>122)
   b1[i]=q-26;
  else
   b1[i]=q;
  //cout<<endl<<"Rotor 1:"<<b1[i];
  z=0; q=0;
  count++;

  ref(b1[i]);

  z=b1[i]-97;                      //Ciphering
  q=b1[i]-r1i[z];
  if (q<97)
   a1[i]=q+26;
  else if(q>122)
   a1[i]=q-26;
  else
   a1[i]=q;
  //cout<<endl<<"Inverse Rotor 1:"<<a1[i]<<endl;
  cout<<a1[i];
 }
getch();
}

void ref(char &o)
{
  switch(o)                      //Reflector
  {
   case 'a': o='f'; break;
   case 'b': o='v'; break;
   case 'c': o='p'; break;
   case 'd': o='j'; break;
   case 'e': o='i'; break;
   case 'f': o='a'; break;
   case 'g': o='o'; break;
   case 'h': o='y'; break;
   case 'i': o='e'; break;
   case 'j': o='d'; break;
   case 'k': o='r'; break;
   case 'l': o='z'; break;
   case 'm': o='x'; break;
   case 'n': o='w'; break;
   case 'o': o='g'; break;
   case 'p': o='c'; break;
   case 'q': o='t'; break;
   case 'r': o='k'; break;
   case 's': o='u'; break;
   case 't': o='q'; break;
   case 'u': o='s'; break;
   case 'v': o='b'; break;
   case 'w': o='n'; break;
   case 'x': o='m'; break;
   case 'y': o='h'; break;
   case 'z': o='l'; break;
   default: cout<<"Reflector Error";
  }
  //cout<<endl<<"Reflector:"<<o;
}