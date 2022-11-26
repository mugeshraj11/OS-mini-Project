#include<stdio.h>
#include<conio.h>
#define MAX 25
void main()
 {


printf("Enter 1 for CPU scheduling Comparison\nEnter 2 for Best Fit/Worst Fit\n" );
        int os;
    scanf("%d",&os);
    switch(os){
        case 1:
        {

            printf("\tPriority Scheduling\n");



   int x,n,p[10],pp[10],pt[10],w[10],t[10];
   int awt,atat;

   float compare[4],compare1[4];



   int new[10],new1[10],p1[10],pid[10],new2[10];
   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("\n Enter process : time priorities \n");
   for(int i=0;i<n;i++)
    {
      printf("\nProcess no %d : ",i+1);
      scanf("%d  %d",&pt[i],&pp[i]);
      p[i]=i+1;
    }

    for(int j=0;j<n;j++){
      pid[j]=p[j];
    }


    for(int j=0;j<n;j++){
      p1[j]=p[j];
    }
    for(int i=0;i<n;i++){
        new[i]=pt[i];
    }
    for(int j=0;j<n;j++){
        new1[j]=new[j];
    }
    for(int j=0;j<n;j++){
        new2[j]=new[j];
    }
  for(int i=0;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(pp[i]<pp[j])
       {
         x=pp[i];
         pp[i]=pp[j];
         pp[j]=x;
         x=pt[i];
         pt[i]=pt[j];
         pt[j]=x;
         x=p[i];
         p[i]=p[j];
         p[j]=x;
      }
   }
}
w[0]=0;
awt=0;
t[0]=pt[0];
atat=t[0];
for(int i=1;i<n;i++)
 {
   w[i]=t[i-1];
   awt+=w[i];
   t[i]=w[i]+pt[i];
   atat+=t[i];
 }
printf("\n\n Job \t Burst Time \t Wait Time \t Turn Around Time   Priority \n");
for(int i=0;i<n;i++)
  printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t %d \n",p[i],pt[i],w[i],t[i],pp[i]);
awt=awt/n;
atat=atat/n;
printf("\n Average Wait Time : %d \n",awt);
printf("\n Average Turn Around Time : %d \n",atat);
getch();

float a=(float)awt;
compare[0]=(float)awt;
compare1[0]=(float)atat;




printf("\tRound Robin Scheduling\n");
int count,j,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],rt[10];
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time for Process Process Number %d :",count+1);
    scanf("%d",&at[count]);
    rt[count]=new[count];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-new[count]);
      wait_time+=time-at[count]-new[count];
      turnaround_time+=time-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

compare[1]=(float)wait_time; 
compare1[1]=(float)turnaround_time;
 printf("\tShortest Job first\n");
    int wt1[20],tat1[20],total=0,pos,temp;
    float avg_tat=0.0;
    float avg_wt=0.0;
     //sorting burst time in ascending order using selection sort
    for(int i=0;i<n;i++)
    {
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(new1[j]<new1[pos])
                pos=j;
        }
 
        temp=new1[i];
        new1[i]=new1[pos];
        new1[pos]=temp;
 
        temp=p1[i];
        p1[i]=p1[pos];
        p1[pos]=temp;
    }
 
    wt1[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(int i=1;i<n;i++)
    {
        wt1[i]=0;
        for(int j=0;j<i;j++)
            wt1[i]+=new1[j];
 
        total+=wt1[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(int i=0;i<n;i++)
    {
        tat1[i]=new1[i]+wt1[i];     //calculate turnaround time
        total+=tat1[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p1[i],new1[i],wt1[i],tat1[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    getch();

compare[2]=avg_wt;
compare1[2]=avg_tat;


printf("FCFS Scheduling");
    //fcfs
    int wt2[n];
    wt2[0]=0;
 
    //for calculating waiting time of each process
    for(int i=1; i<n; i++)
    {
        wt2[i]= new2[i-1]+ wt2[i-1];
    }
 
    printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
    float twt2=0.0;
    float tat2= 0.0;
    for(int i=0; i<n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", new2[i]);
        printf("%d\t\t", wt2[i]);
 
        //calculating and printing turnaround time of each process
        printf("%d\t\t", new2[i]+wt2[i]);
        getch();
        printf("\n");
 
        //for calculating total waiting time
        twt2 += wt2[i];
 
        //for calculating total turnaround time
        tat2 += (wt2[i]+new2[i]);
    }
    float att,awt2;
 
    //for calculating average waiting time
    awt2 = twt2/n;
 
    //for calculating average turnaround time
    att = tat2/n;
    printf("Avg. waiting time= %f\n",awt2);
    printf("Avg. turnaround time= %f",att);
    getch();
compare[3]=awt2;
compare[3]=att;

float min = compare[0];
float max=compare1[0];
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
    if(compare[i]<compare[j]){
        min=compare[i];
    }
    if(compare1[i]<compare[j]){
        max=compare1[i];
    }
    }

}
if(min==compare[0]){
    printf("\nThe fairest Algorithm is the PRIORITY scheduling\n");
}
else if(min==compare[1]){
    printf("\nThe fairest Algorithm is the round robin scheduling\n");
}
else if(min==compare[2]){
    printf("\nThe fairest Algorithm is the shortest job first scheduling\n");
}
else{
    printf("\nThe fairest Algorithm is the fcfs scheduling\n");
}

if(max==compare1[0]){
    printf("\nThe fastest Algorithm is the PRIORITY scheduling\n");
}
else if(max==compare1[1]){
    printf("\nThe fastest Algorithm is the round robin scheduling\n");
}
else if(max==compare1[2]){
    printf("\nThe fastest Algorithm is the shortest job first scheduling\n");
}
else{
    printf("\nThe fastesr Algorithm is the fcfs scheduling\n");
}

break;

        }

    case 2:
    {
        int s;
    scanf("%d",&s);
switch(s){

    case 1:
    {

int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
int barray[20],parray[20];
printf("\n\t\t\tMemory Management Scheme - Best Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of processes:");
scanf("%d",&np);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
    {
printf("Block no.%d:",i);
        scanf("%d",&b[i]);
    }
printf("\nEnter the size of the processes :-\n");
for(i=1;i<=np;i++)
    {
        printf("Process no.%d:",i);
        scanf("%d",&p[i]);
    }
for(i=1;i<=np;i++)
{
for(j=1;j<=nb;j++)
{
if(barray[j]!=1)
{
temp=b[j]-p[i];
if(temp>=0)
if(lowest>temp)
{
parray[i]=j;
lowest=temp;
}
}
}
fragment[i]=lowest;
barray[parray[i]]=1;
lowest=10000;
}
printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
for(i=1;i<=np && parray[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parray[i]],fragment[i]);
break;
    }

case 2:
{
int frag[MAX],b[MAX],f[MAX],i,j,nb,nf,temp;
    static int bf[MAX],ff[MAX];

    printf("\n\tMemory Management Scheme - worst Fit");

    printf("\nEnter the number of blocks:");
    scanf("%d",&nb);

    printf("Enter the number of files:");
    scanf("%d",&nf);

    printf("\nEnter the size of the blocks:-\n");
    for(i=1;i<=nb;i++)
    {
        printf("Block %d:",i);
        scanf("%d",&b[i]);
    }

    printf("Enter the size of the files :-\n");
    for(i=1;i<=nf;i++)
    {
        printf("File %d:",i);
        scanf("%d",&f[i]);
    }

    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];

                if(temp>=0)
                {
                    ff[i]=j;
                    break;
                }
            }
        }

        frag[i]=temp;
        bf[ff[i]]=1;
        
    }

    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for(i=1;i<=nf;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
    
    break;



}
}
    }



    
}
 }








  
