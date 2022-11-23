//* Implement Page Replacement Algorithms - FIFO,LRU,OPTIMAL


#include<stdio.h>
#include<stdlib.h>

typedef struct page
{
int frame;
int count[10],curr[10];
}page;

void fifo(page p,int pa,int pag[],int flag1)
{
int i,j,k,flag,temp,fault=0;

for(i=0;i<p.frame;i++)
{
p.curr[i]=-1;
p.count[i]=100;
printf("\t p%d",i+1);
}
printf("page Fault\n");
for(i=0;i<pa;i++)
{
flag=0;
temp=0;
for(j=0;j<p.frame;j++)
{
if(p.curr[j]==pag[i])
{
flag=1;
if(flag1==1)
p.count[j]=0;
break;
}
if(temp<p.count[j])
{
temp=p.count[j];
k=j;
}
}
for(j=0;j<p.frame;j++)
{
if(flag==0 && k==j)
{
p.curr[j]=pag[i];
p.count[j]=1;
fault++;
}
else
if(j<fault)
p.count[j]++;
printf("\t");
if(p.curr[j]!=-1)
printf("%d",p.curr[j]);
}
if(flag==0)
printf("\tf");
printf("\n");
}
printf("\n Total no of page faults=%d",fault);
}


void optimal(page p,int pages,int pag[],int flag1)
{
int i,j,l,k,flag,temp,fault=0;

for(i=0;i<p.frame;i++)
{
p.curr[i]=-1;
p.count[i]=100;
printf("\t p%d",i+1);
}
printf("page Fault");
for(i=0;i<pages;i++)
{
flag=0;
temp=0;
for(j=0;j<p.frame;j++)
{
if(p.curr[j]==pag[i])
{
flag=1;
if(flag1==1)
p.count[j]=0;
break;
}
if(temp<p.count[j])
{
temp=p.count[j];
k=j;
}
}
for(j=0;j<p.frame;j++)
{
if(flag==0 && k==j)
{
p.curr[j]=pag[i];
p.count[j]=0;
fault++;
}
else
if(j<fault)
{
	p.count[j]=0;
for(l=i+1;l<pages;l++)
{
if(pag[l]==p.curr[j])
	break;

}
}
printf("\t");
if(p.curr[j]!=-1)
printf("%d",p.curr[j]);
}
if(flag==0)
printf("\tf");
printf("\n");
}
printf("\n Total no of page faults=%d",fault);
}


void lru(page p,int pages,int pag[],int flag1)
{
int i,j,l,k,flag,temp,fault=0;

for(i=0;i<p.frame;i++)
{
p.curr[i]=-1;
p.count[i]=100;
printf("\t p%d",i+1);
}
printf("page Fault\n");
for(i=0;i<pages;i++)
{
flag=0;
temp=0;
for(j=0;j<p.frame;j++)
{
if(p.curr[j]==pag[i])
{
flag=1;
if(flag1==1)
p.count[j]=0;
break;
}
if(temp<p.count[j])
{
temp=p.count[j];
k=j;
}
}
for(j=0;j<p.frame;j++)
{
if(flag==0 && k==j)
{
p.curr[j]=pag[i];
p.count[j]=0;
fault++;
}
else
if(j<fault)
{
	p.count[j]=0;
for(l=i-1;l<pages;l++)
{
if(pag[l]==p.curr[j])
	break;
else 
	p.count[j]++;
}
}
printf("\t");
if(p.curr[j]!=-1)
printf("%d",p.curr[j]);
}
if(flag==0)
printf("\tf");
printf("\n");
}
printf("\n Total no of page faults=%d",fault);

}



void main()
{
page p;
int ch;
int i,j,pages,pag[20];
printf("\n Enter the no.of pages: ");
scanf("%d",&pages);
printf("\n Enter the pages:");
for(i=0;i<pages;i++)
{
scanf("%d",&pag[i]);
}
printf("Enter the no. of frames:");
scanf("%d",&p.frame);
printf("1)fifo");
printf("2)optimal");
printf("3)lru");
printf("4)exit");
printf("\n Enter the choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:fifo(p,pages,pag,0);
       break;
case 2:optimal(p,pages,pag,0);
       break;
case 3:lru(p,pages,pag,0);

}

}
