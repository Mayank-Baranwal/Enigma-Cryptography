#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>
void ref(char&);                    //Reflector
void rot1(int); 		    //Rotor 1
void rot2(int);                     //Rotor 2
void rot3(int);                     //Rotor 3
void rot1i(int);                    //Inverse Rotor 1
void rot2i(int);                    //Inverse Rotor 2
void rot3i(int);                    //Inverse Rotor 3

char a1[100], b1[100], a2[100], b2[100], alp[26];
int count=0, h, z, q, len;
int r1i[26], r1t[26], r1[26]={3,11,17,19,14,3,5,10,12,15,6,2,-2,-8,-10,-6,-14,-17,7,-18,-5,-15,1,-9,-17,-4};
int r2i[26], r2t[26], r2[26]={4,17,12,18,11,20,3,-7,16,7,10,-3,5,-6,9,-4,-3,-12,1,-13,-10,-18,-20,-11,-2,-24};
int r3i[26], r3t[26], r3[26]={11,3,22,6,17,-3,7,1,15,13,5,-10,4,-1,-11,2,3,-17,-8,6,-14,-16,-2,-16,-10,-7};

void main()
{
 clrscr();
 cin.getline(a1,100);
 len=strlen(a1);
 for(int al=0; al<26; al++)       //Alphabet
  alp[al]=char(al+97);

 for(int i=0;i<len;i++)           //Rotor 1
 {
  count++;
  rot1(i);
  rot2(i);
  rot3(i);
  ref(a1[i]);
  rot3i(i);
  rot2i(i);
  rot1i(i);
  cout<<endl<<a1[i]<<endl;
 }
getch();
}

void rot1(int i)                   //Rotor 1
{
  for(int k=0;k<26;k++)
   r1t[k]=r1[k];

  for (int j=0;j<26;j++)           //Relation Changer
  {
   if(j<25)
   r1[j]=r1t[j+1];
   else
   r1[j]=r1t[j-25];
  // cout<<r1[j]<<"\t";
  }

  z=a1[i]-97;                      //Ciphering Rotor
  q=a1[i]+r1[z];
  if (q<97)
   a1[i]=q+26;
  else if(q>122)
   a1[i]=q-26;
  else
   a1[i]=q;
  cout<<endl<<"Rotor 1:"<<a1[i];
  z=0; q=0;
}

void rot2(int i)                   //Rotor 2
{
  for(int k=0;k<26;k++)
   r2t[k]=r2[k];

  if (count%2==0)
  {
   for (int j=0;j<26;j++)          //Relation Changer
   {
    if(j<25)
    r2[j]=r2t[j+1];
    else
    r2[j]=r2t[j-25];
   // cout<<r2[j]<<"\t";
   }
  }

  z=a1[i]-97;                      //Ciphering Rotor
  q=a1[i]+r2[z];
  if (q<97)
   a1[i]=q+26;
  else if(q>122)
   a1[i]=q-26;
  else
   a1[i]=q;
  cout<<endl<<"Rotor 2:"<<a1[i];
  z=0; q=0;
}

void rot3(int i)                   //Rotor 3
{
  for(int k=0;k<26;k++)
   r3t[k]=r3[k];

  if (count%3==0)
  {
   for (int j=0;j<26;j++)          //Relation Changer
   {
    if(j<25)
    r3[j]=r3t[j+1];
    else
    r3[j]=r3t[j-25];
   // cout<<r3[j]<<"\t";
   }
  }

  z=a1[i]-97;                      //Ciphering Rotor
  q=a1[i]+r3[z];
  if (q<97)
   a1[i]=q+26;
  else if(q>122)
   a1[i]=q-26;
  else
   a1[i]=q;
  cout<<endl<<"Rotor 3:"<<a1[i];
  z=0; q=0;
}


void rot1i(int i)                 //Inverse Rotor 1
{
  for(int l=0; l<26; l++)         //Inverse Motor Relation
  {
   h=alp[l]+r1[l];
   if(h>122)
    h-=26;
   else if (h<97)
    h+=26;
   r1i[h-97]=r1[l];
  }

  z=a1[i]-97;                     //Ciphering Inverse
  q=a1[i]-r1i[z];
  if (q<97)
   a1[i]=q+26;
  else if(q>122)
   a1[i]=q-26;
  else
   a1[i]=q;
  cout<<endl<<"Inverse Rotor 1:"<<a1[i];
}

void rot2i(int i)                 //Inverse Rotor 2
{
  for(int l=0; l<26; l++)         //Inverse Motor Relation
  {
   h=alp[l]+r2[l];
   if(h>122)
    h-=26;
   else if (h<97)
    h+=26;
   r2i[h-97]=r2[l];
  }

  z=a1[i]-97;                     //Ciphering Inverse
  q=a1[i]-r2i[z];
  if (q<97)
   a1[i]=q+26;
  else if(q>122)
   a1[i]=q-26;
  else
   a1[i]=q;
  cout<<endl<<"Inverse Rotor 2:"<<a1[i];
}

void rot3i(int i)                 //Inverse Rotor 3
{
  for(int l=0; l<26; l++)         //Inverse Motor Relation
  {
   h=alp[l]+r3[l];
   if(h>122)
    h-=26;
   else if (h<97)
    h+=26;
   r3i[h-97]=r3[l];
  }

  z=a1[i]-97;                     //Ciphering Inverse
  q=a1[i]-r3i[z];
  if (q<97)
   a1[i]=q+26;
  else if(q>122)
   a1[i]=q-26;
  else
   a1[i]=q;
  cout<<endl<<"Inverse Rotor 3:"<<a1[i];
}


void ref(char &o)                //Reflector
{
  switch(o)
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
  cout<<endl<<"Reflector:"<<o;
}