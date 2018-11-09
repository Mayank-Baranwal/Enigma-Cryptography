#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
void main()
{
 cout.setf(ios::showpos);
 clrscr();
 char a[26],b[26];
 for (int i=0; i<26; ++i)
  a[i]=char(97+i);
 cout<<"Enter letters corresponding to alphabet for Enigma rotor:"<<endl;
 cin.getline(b,27);
// cout<<"Corresponding Relationships are:"<<endl;
 for (int j=0; j<strlen(b); ++j)
 {
  int x=b[j]-a[j];
  cout<<a[j]<<" "<<b[j]<<" "<<x<<"\t\t";
 }
 getch();
}