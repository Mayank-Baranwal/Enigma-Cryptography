#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>
void main(){
clrscr();
char a[4]={'a','b','c','d'},b[4];

int  x[4]={1,2,-2,-1},temp[4];
int count=0;
cin>>count;
int y=count%4;
for(int k=0;k<4;k++){

temp[k]=x[k];
}
for (int j=0;j<4;j++){

  if(j<3)
  x[j]=temp[j+1];
  else
  x[j]=temp[j-4];
  cout<<x[j]<<endl;}
for(int i=0;i<4;i++){
  b[i]=a[i]+x[i];
  if (b[i]<97)
  b[i]=b[i]+4;
  if(b[i]>100)
  b[i]=b[i]-4;
  cout<<"NEW "<<i+1<<" "<<b[i]<<endl;
 }




getch();

}