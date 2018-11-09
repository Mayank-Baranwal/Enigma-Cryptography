//Cyptography Main Program
#include<bits/stdc++.h>

using namespace std;

void ref(char&);                    //Reflector
void rot1(int,int); 	    	    //Rotor 1
void rot2(int,int);                 //Rotor 2
void rot3(int,int);                 //Rotor 3
void rot4(int,int);                 //Rotor 4
void rot5(int,int);                 //Rotor 5
void rot1i(int);                    //Inverse Rotor 1
void rot2i(int);                    //Inverse Rotor 2
void rot3i(int);                    //Inverse Rotor 3
void rot4i(int);                    //Inverse Rotor 4
void rot5i(int);                    //Inverse Rotor 5

char  alp[26], ch='n';
char a[100], o1[3], st[3];
int cnt=0, x, i, j, h, z, q, len, s[3];
int r1i[26], r1r[26], r1t[26], r1[26]={3,11,17,19,14,3,5,10,12,15,6,2,-2,-8,-10,-6,-14,-17,7,-18,-5,-15,1,-9,-17,-4};
int r2i[26], r2r[26], r2t[26], r2[26]={4,17,12,18,11,20,3,-7,16,7,10,-3,5,-6,9,-4,-3,-12,1,-13,-10,-18,-20,-11,-2,-24};
int r3i[26], r3r[26], r3t[26], r3[26]={11,3,22,6,17,-3,7,1,15,13,5,-10,4,-1,-11,2,3,-17,-8,6,-14,-16,-2,-16,-10,-7};
int r4i[26], r4r[26], r4t[26], r4[26]={13,24,7,4,2,12,-4,16,4,15,8,11,-11,1,6,-10,-16,-9,3,-8,-5,-17,-12,-7,-21,-6};
int r5i[26], r5r[26], r5t[26], r5[26]={9,14,4,18,10,15,6,-2,16,7,-9,-7,1,-6,11,2,-13,-7,-18,-1,3,-10,-14,-21,-5,-3};

int main()
{
 for (i=0; i<26; ++i)             //Relation Resetters
 {
  r1r[i]=r1[i];
  r2r[i]=r2[i];
  r3r[i]=r3[i];
  r4r[i]=r4[i];
  r5r[i]=r5[i];
 }

 do
 {
  cout<<setw(50)<<"\nWelcome to Cipherer 101!"<<endl;

  cout<<endl<<"Enter non-repeating 3 rotor combination (1-5,0 for none): ";
  for(i=0; i<3; ++i)
   cin>>o1[i];
  if (o1[0]==o1[1] || o1[1]==o1[2] || o1[0]==o1[2])
  {
   cout<<"ERROR. Rotor number repeated. Exiting...";
   exit(0);
  }

  cout<<"Enter starting positon of the 3 rotors (Default - aaa): ";
  for(i=0; i<3; ++i)
  {
   cin>>st[i];
   if (st[i]<97 || st[i]>122)
   {
    cout<<"ERROR. Rotor positon "<<st[i]<<" does not exist. Exiting...";
    exit(0);
   }
   else
    s[i]=int(st[i]-'a');
   //cout<<s[i];
  }

  cout<<"Enter message to be Ciphered/Deciphered (Enter . to end sentence):"<<endl;
  for (i=0; i<100; i++)
  {
   cin>>a[i];
   if ((a[i]>=97 && a[i]<=122) || a[i]=='.')
   {
    if (a[i]=='.')
    {
     a[i]='\0';
     len=i;
     break;
    }
   }
   else
   {
    cout<<"ERROR. Letter "<<a[i]<<" not in alphabet. Exiting...";
    exit(0);
   }
  }

  for(x=0; x<26; x++)          //Alphabet Generator
   alp[x]=char(x+97);

  for(i=0; i<len; i++)         //Code Launcher
  {
   cnt++;
   for(j=0; j<3; j++)          //Executing Rotor Combination
   {
    switch(o1[j])
    {
     case '0': break;
     case '1': rot1(i,s[i]); break;
     case '2': rot2(i,s[i]); break;
     case '3': rot3(i,s[i]); break;
     case '4': rot4(i,s[i]); break;
     case '5': rot5(i,s[i]); break;
     default: cout<<"ERROR. Rotor not present. Exiting..."; exit(0);
    }
   }
   ref(a[i]);
   for(j=0; j<3; j++)
   {
    switch(o1[2-j])
    {
     case '0': break;
     case '1': rot1i(i); break;
     case '2': rot2i(i); break;
     case '3': rot3i(i); break;
     case '4': rot4i(i); break;
     case '5': rot5i(i); break;
     default: cout<<"ERROR. Inverse Rotor not present. Exiting..."; exit(0);
    }
   }
  }
  cout<<"Ciphered/Deciphered Code:"<<endl;
  for(j=0; j<len; ++j)
   cout<<a[j];
  cout<<endl<<"Want to cipher again (y/n) ? ";
  cin>>ch;
  if (ch!='y' || ch!='Y')
   cout<<"Thank you for using the program.";
  cnt=0;
  for (i=0; i<26; ++i)            //Relation Resetters
  {
   r1[i]=r1r[i];
   r2[i]=r2r[i];
   r3[i]=r3r[i];
   r4[i]=r4r[i];
   r5[i]=r5r[i];
  }
 } while (ch=='y' || ch=='Y');
 return 0;
}

void rot1(int i,int s)            //Rotor 1
{
  for(int k=0;k<26;k++)
   r1t[k]=r1[k];

  if (cnt==1)                   //Starting Rotor Positon
  {
   for(int l=0; l<26; ++l)
   {
    if (l<26-s)
     r1[l]=r1t[l+s];
    else
     r1[l]=r1t[l-(26-s)];
   //cout<<"\t"<<r1[l];
   }
   for (int m=0; m<26; ++m)
    r1t[m]=r1[m];
  }

  for (int j=0;j<26;j++)          //Relation Changer
  {
   if(j<25)
   r1[j]=r1t[j+1];
   else
   r1[j]=r1t[j-25];
  // cout<<r1[j]<<"\t";
  }

  z=a[i]-97;                      //Ciphering Rotor
  q=a[i]+r1[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Rotor 1:"<<a[i];
  z=0; q=0;
}

void rot2(int i,int s)            //Rotor 2
{
  for(int k=0;k<26;k++)
   r2t[k]=r2[k];

  if (cnt==1)                   //Starting Rotor Positon
  {
   for(int l=0; l<26; ++l)
   {
    if (l<26-s)
     r2[l]=r2t[l+s];
    else
     r2[l]=r2t[l-(26-s)];
   //cout<<"\t"<<r2[l];
   }
   for (int m=0; m<26; ++m)
    r2t[m]=r2[m];
  }

  if (cnt%2==0)
  {
   for (int j=0;j<26;j++)         //Relation Changer
   {
    if(j<25)
    r2[j]=r2t[j+1];
    else
    r2[j]=r2t[j-25];
   // cout<<r2[j]<<"\t";
   }
  }

  z=a[i]-97;                      //Ciphering Rotor
  q=a[i]+r2[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Rotor 2:"<<a[i];
  z=0; q=0;
}

void rot3(int i,int s)            //Rotor 3
{
  for(int k=0;k<26;k++)
   r3t[k]=r3[k];

  if (cnt==1)                   //Starting Rotor Positon
  {
   for(int l=0; l<26; ++l)
   {
    if (l<26-s)
     r3[l]=r3t[l+s];
    else
     r3[l]=r3t[l-(26-s)];
   //cout<<"\t"<<r3[l];
   }
   for (int m=0; m<26; ++m)
    r3t[m]=r3[m];
  }

  for (int j=0;j<26;j++)          //Relation Changer
  {
   if(j<25)
   r3[j]=r3t[j+1];
   else
   r3[j]=r3t[j-25];
  // cout<<r3[j]<<"\t";
  }

  z=a[i]-97;                      //Ciphering Rotor
  q=a[i]+r3[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Rotor 3:"<<a[i];
  z=0; q=0;
}

void rot4(int i,int s)            //Rotor 4
{
  for(int k=0;k<26;k++)
   r4t[k]=r4[k];

  if (cnt==1)                   //Starting Rotor Positon
  {
   for(int l=0; l<26; ++l)
   {
    if (l<26-s)
     r4[l]=r4t[l+s];
    else
     r4[l]=r4t[l-(26-s)];
   //cout<<"\t"<<r4[l];
   }
   for (int m=0; m<26; ++m)
    r4t[m]=r4[m];
  }

  if (cnt%2==0)
  {
   for (int j=0;j<26;j++)         //Relation Changer
   {
    if(j<25)
     r4[j]=r4t[j+1];
    else
     r4[j]=r4t[j-25];
   // cout<<r4[j]<<"\t";
   }
  }

  z=a[i]-97;                      //Ciphering Rotor
  q=a[i]+r4[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Rotor 4:"<<a[i];
  z=0; q=0;
}

void rot5(int i,int s)            //Rotor 5
{
  for(int k=0;k<26;k++)
   r5t[k]=r5[k];

  if (cnt==1)                   //Starting Rotor Positon
  {
   for(int l=0; l<26; ++l)
   {
    if (l<26-s)
     r5[l]=r5t[l+s];
    else
     r5[l]=r5t[l-(26-s)];
   //cout<<"\t"<<r5[l];
   }
   for (int m=0; m<26; ++m)
    r5t[m]=r5[m];
  }

  for (int j=0;j<26;j++)          //Relation Changer
  {
   if(j<25)
   r5[j]=r5t[j+1];
   else
   r5[j]=r5t[j-25];
  // cout<<r5[j]<<"\t";
  }

  z=a[i]-97;                      //Ciphering Rotor
  q=a[i]+r5[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Rotor 5:"<<a[i];
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

  z=a[i]-97;                      //Ciphering Inverse
  q=a[i]-r1i[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Inverse Rotor 1:"<<a[i];
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

  z=a[i]-97;                      //Ciphering Inverse
  q=a[i]-r2i[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Inverse Rotor 2:"<<a[i];
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

  z=a[i]-97;                      //Ciphering Inverse
  q=a[i]-r3i[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Inverse Rotor 3:"<<a[i];
}

void rot4i(int i)                 //Inverse Rotor 4
{
  for(int l=0; l<26; l++)         //Inverse Motor Relation
  {
   h=alp[l]+r4[l];
   if(h>122)
    h-=26;
   else if (h<97)
    h+=26;
   r4i[h-97]=r4[l];
  }

  z=a[i]-97;                      //Ciphering Inverse
  q=a[i]-r4i[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Inverse Rotor 4:"<<a[i];
}

void rot5i(int i)                 //Inverse Rotor 5
{
  for(int l=0; l<26; l++)         //Inverse Motor Relation
  {
   h=alp[l]+r5[l];
   if(h>122)
    h-=26;
   else if (h<97)
    h+=26;
   r5i[h-97]=r5[l];
  }

  z=a[i]-97;                      //Ciphering Inverse
  q=a[i]-r5i[z];
  if (q<97)
   a[i]=q+26;
  else if(q>122)
   a[i]=q-26;
  else
   a[i]=q;
  //cout<<endl<<"Inverse Rotor 5:"<<a[i];
}


void ref(char &o)                 //Reflector
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
   default: cout<<"ERROR in Reflector Processing. Exiting..."; exit(0);
  }
  //cout<<endl<<"Reflector:"<<o;
}

/*Rotor 1:dmtwsilruyqnkfejcazbpgxohv
  Rotor 2:esovpzjayquirhxlnftgkdcmwb
  Rotor 3:leyjvcnixwpbqmdrtakzgfuhos
  Rotor 4:nzjhgrcxmyswboufaivlpekqdt
  Rotor 5:jpgvoumfyqbenhzrdkasxlictw*/
