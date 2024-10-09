//Implementation stack using array #include<stdio.h> 
int stack[100],ch,n,top,x,i; 
void push(); 
void pop(); 
void display(); 
int main() 
{ 
  top=-1; 
  printf("enter the size of stack"); 
  scanf("%d",&n); 
  printf("\n1.push"); 
  printf("\n2.pop"); 
  printf("\n3.display"); 
  printf("\n4.exit"); 
do 
{ 
printf("\nEnter your choice"); 
scanf("%d",&ch); 
switch(ch) 
{ 
case 1:  
{ 
push(); 
break; 
} 
case 2:  
{ 
pop(); 
break; 
} 
case 3:  
{
1 
display(); 
break; 
} 
case 4:  
{ 
printf("Exit"); 
break; 
} 
default:  
{ 
printf("Invalid choice!Enter 1 to 4"); 
} 
} 
}while(ch!=4); 
return 0; 
} 
void push() 
{ 
if(top>=n-1)//check size of stack 
{ 
printf("stack overflow"); 
} 
else 
{ 
printf("Enter a value to be pushed:"); 
scanf("%d",&x); 
top++; 
stack[top]=x; 
} 
} 
void pop() 
{ 
if(top<=-1) 
{
2 
printf("\nStack is empty"); 
} 
else 
{ 
printf("\nThe poped element is:%d ",stack[top]); top--; 
} 
} 
void display() 
{ 
if(top>=0) 
{ 
printf("\n the element in stack is:\n"); 
for(i=top;i>=0;i--) 
{ 
printf("%d\n",stack[i]); 
} 
printf("\npress next choice"); 
} 
else 
{ 
printf("\n stack is empty"); 
} 
} 
