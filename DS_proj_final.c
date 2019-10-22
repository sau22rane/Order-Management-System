#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int num_items, total=0;
int a[10][2];
int *p = (int*)malloc(sizeOf(int));

void makedb ();
void display_menu();
void addtally(int item);
void addtotal();
void editmenu();
void add_queue();

int main()
{
    int s, item, n, i =0, control;

    makedb();
    
    while (1)
    {
        printf("1) Edit Menu \n2) Add item \n3) Order completed \n4) Exit \n");
        printf ("Your selection : ");
        scanf("%d", &s);

        switch (s)
        {
            case 1: editmenu();
                    break;

            case 2: printf ("Enter number of items to be added : ");
                    scanf ("%d", &n);
                    display_menu();
                    printf("Please add the item code from the Menu : \n");
                    
                    do
                    {
                        scanf("%d", &item);
                        //add function
                        addtally(item);
                        i++;
                        printf("Added! \n");
                    }while (i<n);

                    break;

            case 3: break;

            case 4: addtotal();  
                    return 0;              
        }
    }
}

void editmenu()
{
    FILE *f;
    int num,price, i=0;
    char x[20];

    f = fopen("Menu.txt","w");
    printf("How many items do you want to add in the menu?\n");
    scanf("%d",&num_items);
    
    for(int i=0; i<num_items; i++) //updating item in the menu file
    {
        printf("Enter Item\n");
        scanf("%d %s %d",&num,x,&price);
        fprintf(f,"%d %s %d\n",num,x,price);
    }
    printf("Menu has been updated \n");
    fclose(f);
}

void makedb()  // Function to make a MENU and then make a 2D array from the menu file - for chef login
{
    FILE *f;
    int num,price, i=0;
    char x[20];

    f = fopen("Menu.txt","r");
    rewind(f);
    
    while(!feof(f))
    {
      int num,price;
      char x[20];  
      fscanf(f,"%d %s %d\n",&num,x,&price);
      a[i][0] = num;
      a[i][1] = price;
      i++;
    }

    fclose(f);
}

void addtally(int item)  // Searches the item which is ordered using fibonacci search algorithm and adds its corresponding price to the tally
{
    total+=a[item-1][1];
    printf("%d",total);
}

void display_menu()
{
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

    fclose (fp);
}

void addtotal()  // function to add the total of the day to a file 
{
    char day[10];
    int d,m,y;
    FILE *f;
    
    f = fopen("Tally.txt","a+");
    
    printf("Enter Day \t:");
    scanf("%s",day);
    
    printf("\nEnter Date \t:");
    scanf("%d %d %d",&d,&m,&y);
    
    fprintf(f,"%s\t%d-%d-%d\tRs.%d\n",day,d,m,y,total);
    fclose(f);
    
    printf("Tally for the Day %d\n",total);
    printf("Today's tally was successfully saved to database\n");
}

void add_queue()
{

}