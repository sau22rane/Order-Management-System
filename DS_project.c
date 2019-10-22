// Data Structures Project - Tally functionality 
#include<stdio.h>
#include<math.h>
int total,num_items;
int a[10][2];
int min (int a,int b)
{
    return a<b?a:b;
}
void makedb()  // Function to make a MENU and then make a 2D array from the menu file - for chef login
{
    int i=0;
    FILE *fp;
    int num,price;
    char x[20];
    FILE *f;
    f = fopen("Menu.txt","w");
    printf("How many items do you want to add ?\n");
    scanf("%d",&num_items);
    for(int i=0;i<num_items;i++)
    {
        printf("Enter Item\n");
        scanf("%d %s %d",&num,x,&price);
        fprintf(f,"%d %s %d\n",num,x,price);
    }
    fclose(f);
    fp = fopen("Menu.txt","r");
    rewind(fp);
    while(!feof(fp))
    {
      int num,price;
      char x[20];  
      fscanf(fp,"%d %s %d\n",&num,x,&price);
      a[i][0] = num;
      a[i][1] = price;
      i++;
    }
}

void addtally(int item)  // Searches the item which is ordered using fibonacci search algorithm and adds its corresponding price to the tally
{
    total+=a[item-1][1];
}



int main()
{
    int l;
    printf("Welcome to Smart Order Manager\n\n");
    makedb();
    while(1)
    {
        printf("Please choose among the Menu to add an item to the Order\nTo exit Press 0\n");
        FILE *fp;
        int num,price,choice;
        char x[20];
        fp = fopen("Menu.txt","r");
        rewind(fp);
        while(!feof(fp))
        {
            fscanf(fp,"%d %s %d\n",&num,x,&price);
            printf("%d %s Rs.%d\n",num,x,price);
        }
        scanf("%d",&choice);
        if(choice==0) //While exiting the program the total tally of the day is stored in a file 
        {
            FILE *f;
            f = fopen("Tally.txt","a+");
            char day[10];
            int d,m,y;
            printf("Enter Day \t:");
            scanf("%s",day);
            printf("\nEnter Date \t:");
            scanf("%d %d %d",&d,&m,&y);
            fprintf(f,"%s\t%d-%d-%d\tRs.%d\n",day,d,m,y,total);
            fclose(f);
            break;
        }
        else
        {
            addtally(choice); // call to function to add the item in the total
        }
        
        
    
    } // End of while loop
    return 0;
}