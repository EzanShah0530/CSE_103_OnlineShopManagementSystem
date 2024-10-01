#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define error puts("\n\t\t\t\t\t\t   ><><><><><><><><\n\t\t\t\t\t\t   <  \a! ERROR !   >  \n\t\t\t\t\t\t   ><><><><><><><><")
//Intro
void title();
//Screen Headings
int fixed_title(int);
void admin_panel();
void customer_panel();
//Admin side
int access();
void admin_permission();
void product_scan();
void product_add();
void product_edit();
void product_search();
void product_delete();
//Customer side
int customer_purchase();
void review();
//Declaring file for stock
FILE *fptr;
//Declaring structure for stock
struct store
{
    char ProductId[1000];
    char ProductName[1000];
    int quantity;
    int want;
    float price;
} ;
int counter;
int cas=0;
//main start
int main()
{
    struct store STORE;
    int press;
    int a;
    title();
    fixed_title(0);
    system("color F0");
    puts("\n\n\t\t\t\t\tWhat would you like to do?");
    puts("	\n\t\t\t\t\t1. If You Are The Admin Then Press 1.");
    puts("	\t\t\t\t2. If You Are The Customer Then Press 2.");
    puts("	\t\t\t\t3. If You Want to give feedback then press 3.");
    puts("	\t\t\t\t4. If You Want to Exit Press 4.");
    printf("\n\t\t\t\tEnter Your Press: ");
    scanf("%d",&press);
    switch (press)
    {
        case 1 :
            {
                system("color 70");
                a=access();
                if(a==1)
                admin_permission();
                else
                    {
                        getch();
                        main();
                    }
                break;
            }
        case 2 :
            {
               customer_purchase();
               break;
            }
        case 3 :
            {
               review();
               getch();
               main();
               break;
            }
        default :
            {
               fixed_title(0);
               system("color F9");
               puts("\n\n\n\n\n\n\t\t\t\t\t\t      Thank you");
               puts("\n\t\t\t\t\t Please purchase from our shop next time");
               puts("\n\t\t\t\t\t\t   Have a nice day");
               fclose(fptr);
               getch();
               exit(0);
            }
    }
}
void title()
{
    system("cls");
    system("color 7");
    printf("\n\n\n\t\t\t#######################################################################");
    printf("\n\n\n\n\t\t\t\t      Project about Online Shop Management System\n");
    printf("\n\t\t\t\t\t     Instructor:Dr. Ahmed Wasif Reza");
    printf("\n\n\t\t\t\t\t\t      Created by \n");
    printf("\t\t\t\t\t\t     ------------ \n");
    printf("\n\t\t\t\t\t         Name:Suraiya Nusrat Tanha");
    printf("\n\t\t\t\t\t         ID  :2021-2-60-030");
    printf("\n\n\t\t\t\t\t         Name:Umme Habiba Fariha");
    printf("\n\t\t\t\t\t         ID  :2021-2-60-079");
    printf("\n\n\t\t\t\t\t         Name:Shah Abdul Mazid");
    printf("\n\t\t\t\t\t         ID  :2021-2-60-046");
    printf("\n\n\n\t\t\t#######################################################################");
    puts("\n\n\t\t\t\t\t <><><><>  LETS GET STARTED  <><><><>");
    puts("\n\n\t\t\t\t\t        Press any key to continue");
    getch();
}
int fixed_title(int ftitle)
{
    system("cls");
    printf("\n\n\n\t\t       ******************************************************************************\n");
    printf("\n\t\t\t\t\t\t   MERCADO ONLIN SHOP\n");
    printf("\n\t\t\t\t\t ---TRUST IS THE BASE OF A STRONG BOND---\n");
    printf("\n\n\t\t       ******************************************************************************\n");
    printf("\n\n\n\t\t\t\t        Delivery Charge inside Dhaka 50Tk!");
    printf("\n\n\t\t\t\t        Delivery Charge outside Dhaka 100Tk!");
    printf("\n\n\t\t\t       Use Voucher Code 'wasif sir' to get 50 Percent Discount");
    printf("\n\n\t\t\t       Shop more than 1000 tk to get 'FREE HOME DELIVERY OFFER'");
    printf("\n\n\t\t\t       Shop more than 700 tk to get 'BUMPER OFFER'(200 Tk less)");
    printf("\n\n\t\t\t       Shop more than 300 tk to get 'BOGO OFFER'(50 Tk less)");
    printf("\n\n\n\n   ******************************************************************************************************************\n");
}
void admin_panel()
{
    printf("\n\t\t********************************************************************************************\n");
    printf("\n\t\t\t\t\t\t    \"Admin Panel\"\n");
    printf("\t\t\t\t\t    ---Let's Do Something Great---\n");
    printf("\n\t\t********************************************************************************************\n");
}
void customer_panel()
{
    printf("\n\t\t********************************************************************************************\n");
    printf("\n\t\t\t\t\t\t     \"Customer Purchase\"\n");
    printf("\t\t\t\t\t\t---You Are Valuable For Us---\n");
    printf("\n\t\t********************************************************************************************\n");

}
int access()
{
    fflush(stdin);
    char admin[1000];
    static char password[100];
    int a;
    printf("\n\t\t\t\tEnter Admin username: ");
    scanf("%s",&admin);
    if(strcmpi(admin,"wasif@ewubd.edu")==0 || strcmpi(admin,"suraiya030@gmail.com")==0 || strcmpi(admin,"habiba079@gmail.com")==0 || strcmpi(admin,"mazid046@gmail.com")==0)
    {
        puts("\n\n\t\t\t\tAdmin identity verified!");
        printf("\n\t\t\t\tEnter your 4-digit password: ");
        for(int i=0; i<4; i++)
        {
            password[i]=getch();
            if(password[i]=='\r')
            {
                break;
            }
            else
                printf(".");
        }
        if(strcmp(password,"2021")==0)
        {
            puts("\a\n\n\n\t\t\t\t\tPassword is correct!");
            puts("\a\n\t\t\t\tEnter any key to start");
            getch();
            a=1;
        }
        else
        {
            puts("\a\n\n\n\t\t\t\t\tWrong password!");
            a=0;
        }
    }
    else
    {
        fixed_title(0);
        puts("\a\n\n\n\t\t\t\t\t\t     User is unknown!");
        a=0;
    }
    return a;
}
void admin_permission()
{
    system("color F2");
    int c;
    fptr=fopen("stockinfofile.txt","ab+");
    fseek(fptr,0,0);
    fixed_title(0);
    admin_panel();
    printf("\t\t\t\t\t1. Scan available products in the stock.");
    printf("\n\t\t\t\t\t2. Add new products in the stock.");
    printf("\n\t\t\t\t\t3. Edit existing product in the stock.");
    printf("\n\t\t\t\t\t4. Search product from the stock.");
    printf("\n\t\t\t\t\t5. Delete product from the stock.");
    printf("\n\t\t\t\t\t6. Return to previous screen\n");
    printf("\n\n\t\t\t\t\tEnter a choice: ");
    scanf("%d",&c);
    switch (c)
    {
    case 1 :
        product_scan();
        break;
    case 2 :
        product_add();
        break;
    case 3 :
        product_edit();
        break;
    case 4 :
        product_search();
        break;
    case 5 :
        product_delete();
        break;
    case 6 :
        main();
    }
}
void product_scan()
{
    struct store STORE;
    fixed_title(0);
    admin_panel();
    printf("\n\t\t\t               Choice 01: Scanning available products");
    printf("\n\t\t\t");
    printf("******************************************************************");
    rewind(fptr);
    while(fread(&STORE,sizeof(STORE),1,fptr)==1)
    {
        printf("\n\t\t\t ");
        printf("***************************************************************");
        printf("\n\t\t\t\t\t\tProduct Id: ");
        puts(STORE.ProductId);
        printf("\t\t\t\t\t\tProductName: ");
        puts(STORE.ProductName);
        printf("\t\t\t\t\t\tQuantity: ");
        printf("%d",STORE.quantity-cas);
        printf("\n\t\t\t\t\t\tPrice: ");
        printf("%.3fTk",STORE.price);
    }
    printf("\n\t\t\t\t    Press any key to return main menu...\n");
    getch();
    system("cls");
    fclose(fptr);
    admin_permission();
}
void product_add()
{
    struct store STORE;
    fixed_title(0);
    char id1[1000];
    char id2[1000];
    admin_panel();
    printf("\n\t\t\tChoice 02: Addition of new products by the perspective of customer demands ");
    printf("\n\n\t\t");
    printf("********************************************************************************************");
    fflush(stdin);
    printf("\n\n\t\t\t\t\t\t     Product Id: ");
    gets(id1);
    while(fread(&STORE,sizeof(STORE),1,fptr)==1)
    {
        if(((strcmpi(STORE.ProductId,id1))==0))
        {
            error;
            printf("\n\t\t\t\t\t Sorry! This product is already in our stock.\n");
            printf("\n\t\t\t\t       Enter any key to add new product....\n");
            getch();
            product_add();
        }
    }
    strcpy(STORE.ProductId,id1);
    printf("\n\t\t\t\t\t\t     Product Name: ");
    gets(id2);
    while(fread(&STORE,sizeof(STORE),1,fptr)==1)
    {
        if(((strcmpi(STORE.ProductName,id2))==0))
        {
            printf("\nSame Products Name With Different ID Added. \n");
            getch();
            product_add();
        }
    }
    strcpy(STORE.ProductName,id2);
    printf("\n\t\t\t\t\t\t     Quantity: ");
    scanf("%d",&STORE.quantity);
    printf("\n\t\t\t\t\t\t     Price: ");
    scanf("%f",&STORE.price);
    fwrite(&STORE,sizeof(STORE),1,fptr);
    printf("\n\t\t\t\t    Enter any key to return in main menu...\n");
    getch();
    fclose(fptr);
    admin_permission();
}
void product_edit()
{
    struct store STORE;
    fflush(stdin);
    fixed_title(0);
    admin_panel();
    FILE *tptr;
    printf("\n\t\t\t\t        Choice 03: Modify the products in stock");
    printf("\n\t\t\t ");
    printf("******************************************************************");
    char id[1000];
    int a=0;
    char option[1000];
    printf("\n\n\t\t\t\t\t       I want to edit by: ");
    gets(option);
    if(strcmpi(option,"Id")==0)
    {
        char another='y';
        while(another=='y' || another=='Y')
        {
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t       Enter product ID to edit: ");
            gets(id);
            tptr=fopen("temporary.txt","wb");
            rewind(fptr);
            int flag=0, flag1=0, flag2;
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductId,id)==0)
                {
                    flag1++;
                    flag2=1;
                    fflush(stdin);
                    printf("\n\t\t\t\t\t         \"%s\" Product is in the stock!\n",id);
                    flag=10;
                    printf("\n\t\t\t\t\t           New Product Id : ");
                    gets(STORE.ProductId);
                    printf("\n\n\t\t\t\t\t           New Product Name : ");
                    gets(STORE.ProductName);
                    printf("\n\t\t\t\t\t           New Quantity: ");
                    scanf("%d",&STORE.quantity);
                    printf("\n\t\t\t\t\t           Price: ");
                    scanf("%f",&STORE.price);
                    if(flag1==1 && flag2==1)
                    {
                        fseek(tptr,0,0);
                    }
                    else
                    {
                        fseek(tptr,(flag1-1)*sizeof(STORE),0);
                    }
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }
                else
                {
                    flag1++;
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }

            }
            if(flag!=10)
            {
                error;
                puts("\n\t\t\t\t\t This product doesn't exist in the stock!");
            }
            fclose(fptr);
            fclose(tptr);
            remove("stockinfofile.txt");
            rename("temporary.txt","stockinfofile.txt");
            fptr=fopen("stockinfofile.txt","ab+");
            printf("\n\t\t\t\t\t        Want to edit another product? (Y/N)? ");
            fflush(stdin);
            another = getche();
        }
    }
    else if(strcmpi(option,"Name")==0)
    {
        char another='y';
        while(another=='y' || another=='Y')
        {
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t       Enter product Name to edit: ");
            gets(id);
            tptr=fopen("temporary.txt","wb");
            rewind(fptr);
            int flag=0, flag1=0, flag2;
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductName,id)==0)
                {
                    flag1++;
                    flag2=1;
                    fflush(stdin);
                    printf("\n\t\t\t\t\t         \"%s\" Product is in the stock!\n",id);
                    flag=10;
                    printf("\n\t\t\t\t\t           New Product Id : ");
                    gets(STORE.ProductId);
                    printf("\n\n\t\t\t\t\t           New Product Name : ");
                    gets(STORE.ProductName);
                    printf("\n\t\t\t\t\t           New Quantity: ");
                    scanf("%d",&STORE.quantity);
                    printf("\n\t\t\t\t\t           Price: ");
                    scanf("%f",&STORE.price);
                    if(flag1==1 && flag2==1)
                    {
                        fseek(tptr,0,0);
                    }
                    else
                    {
                        fseek(tptr,(flag1-1)*sizeof(STORE),0);
                    }
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }
                else
                {
                    flag1++;
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }

            }
            if(flag!=10)
            {
                error;
                puts("\n\t\t\t\t\t This product doesn't exist in the stock!");
            }
            fclose(fptr);
            fclose(tptr);
            remove("stockinfofile.txt");
            rename("temporary.txt","stockinfofile.txt");
            fptr=fopen("stockinfofile.txt","ab+");
            printf("\n\t\t\t\t\t        Want to edit another product? (Y/N)? ");
            fflush(stdin);
            another = getche();
        }
    }
    else
    {

        printf("\n\t\t\t\t\t     Enter Valid searching form");
    }
    fclose(fptr);
    admin_permission();
}
void product_search()
{
    struct store STORE;
    int a=0;
    char id[100];
    fixed_title(0);
    admin_panel();
    fptr=fopen("stockinfofile.txt","ab+");
    fflush(stdin);
    printf("\n\t\t\t\t          Choice 04: Search in available stock");
    printf("\n\t\t\t ");
    printf("******************************************************************");
    char option[100];
    printf("\n\n\t\t\t\t\t       I want to search by : ");
    gets(option);
    if(strcmpi(option,"Id")==0)
    {
        printf("\n\n\n\t\t\t\t\t      Enter products ID to search: ");
        gets(id);
        while(fread(&STORE,sizeof(STORE),1,fptr)==1)
        {
            if(strcmpi(STORE.ProductId,id)==0)
            {
                puts("\n\t\t\t\t     **************************************************\n\t\t\t\t\t\t     Product Found \n\t\t\t\t     **************************************************\n");
                printf("\n\n\t\t\t\t\t           Product Id: ");
                puts(STORE.ProductId);
                printf("\n\t\t\t\t\t           ProductName: ");
                puts(STORE.ProductName);
                printf("\n\t\t\t\t\t           Quantity: ");
                printf("%d",STORE.quantity);
                printf("\n\n\t\t\t\t\t           Price: ");
                printf("%.3fTk",STORE.price);
                a=1;
            }
        }
    }
    else if(strcmpi(option,"Name")==0)
    {
        printf("\n\n\n\t\t\t\t\t      Enter products Name to search: ");
        gets(id);
        while(fread(&STORE,sizeof(STORE),1,fptr)==1)
        {
            if(strcmpi(STORE.ProductName,id)==0)
            {
                puts("\n\t\t\t\t     **************************************************\n\t\t\t\t\t\t     Product Found \n\t\t\t\t     **************************************************\n");
                printf("\n\n\t\t\t\t\t           Product Id: ");
                puts(STORE.ProductId);
                printf("\n\t\t\t\t\t           ProductName: ");
                puts(STORE.ProductName);
                printf("\n\t\t\t\t\t           Quantity: ");
                printf("%d",STORE.quantity);
                printf("\n\n\t\t\t\t\t           Price: ");
                printf("%.3fTk",STORE.price);
                a=1;
            }
        }
    }
    else
    {

        printf("\n\t\t\t\t\t     Enter Valid searching form");
    }
    if (a!=1)
    {
        error;
        printf("\n\t\t\t\t\t      %s product doesn't exist in the stock!\n",id);
    }
    printf("\n\t\t\t\t         enter any key to continue to previous menu....");
    getch();
    system("cls");
    fclose(fptr);
    admin_permission();
}
void product_delete()
{
    struct store STORE;
    fflush(stdin);
    fixed_title(0);
    admin_panel();
    FILE *tptr;
    printf("\n\t\t\t\t        Choice 05: Delete existing products      ");
    printf("\n\t\t\t");
    printf("******************************************************************");
    char id[30];
    int a=0;
    char option[100];
    printf("\n\n\t\t\t\t\t       I want to delete by : ");
    gets(option);
    if(strcmpi(option,"Id")==0)
    {
        char another='y';
        while(another=='y' || another=='Y')
        {
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t      Enter product id to delete: ");
            gets(id);
            tptr=fopen("tempdel.txt","wb");
            rewind(fptr);
            int flag=0;
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductId,id)!=0)
                {
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }
                else if(strcmpi(STORE.ProductId,id)==0)
                {
                    puts("\n\t\t\t\t     **************************************************\n\t\t\t\t\t      Product is successfully deleted \n\t\t\t\t     **************************************************\n");
                    flag=10;
                }
            }
            if(flag!=10)
            {
                error;
                puts("\n\t\t\t\t\t      No such record exists in our stock!");
            }
            fclose(fptr);
            fclose(tptr);
            remove("stockinfofile.txt");
            rename("tempdel.txt","stockinfofile.txt");
            fptr=fopen("stockinfofile.txt","ab+");
            printf("\n\t\t\t\t\tDelete another product out of stock? (Y/N)? ");
            fflush(stdin);
            another = getch();
        }
    }
    else if(strcmpi(option,"Name")==0)
    {
        char another='y';
        while(another=='y' || another=='Y')
        {
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t      Enter product Name to delete: ");
            gets(id);
            tptr=fopen("tempdel.txt","wb");
            rewind(fptr);
            int flag=0;
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {

                if(strcmpi(STORE.ProductName,id)!=0)
                {
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }
                else if(strcmpi(STORE.ProductName,id)==0)
                {
                    puts("\n\t\t\t\t     **************************************************\n\t\t\t\t\t      Product is successfully deleted \n\t\t\t\t     **************************************************\n");
                    flag=10;
                }
            }
            if(flag!=10)
            {
                error;
                puts("\n\t\t\t\t\t      No such record exists in our stock!");
            }
            fclose(fptr);
            fclose(tptr);
            remove("stockinfofile.txt");
            rename("tempdel.txt","stockinfofile.txt");
            fptr=fopen("stockinfofile.txt","ab+");
            printf("\n\t\t\t\t\tDelete another product out of stock? (Y/N)? ");
            fflush(stdin);
            another = getch();
        }
    }
    else
    {

        printf("\n\t\t\t\t\t     Enter Valid searching form");
    }
    fclose(fptr);
    admin_permission();
}
int customer_purchase()
{
    struct store STORE;
    system("color F4");
    fixed_title(0);
    char product[1000];
    float total=0;
    float actamount=0;
    customer_panel();
    fptr=fopen("stockinfofile.txt","ab+");
    puts("\n\n\n\t\t\t\t\t         Products in our stock:");
    rewind(fptr);
    while(fread(&STORE,sizeof(STORE),1,fptr)==1)
    {
        printf("\n\t\t");
        printf("\t\t\t******************************************");
        printf("\n\n\t\t\t\t\t           Product Id: ");
        puts(STORE.ProductId);
        printf("\t\t\t\t\t           ProductName: ");
        puts(STORE.ProductName);
        printf("\t\t\t\t\t           Quantity: ");
        printf("%d",STORE.quantity-cas);
        printf("\n\t\t\t\t\t           Price: ");
        printf("%.3fTk",STORE.price);
        printf("\n");
    }
    puts("\n\t\t\t\t\t  Enter any key to continue purchase");
    getch();
    fixed_title(0);
    while(1)
    {
        counter++;
        fflush(stdin);
        char option[1000];
        printf("\n\n\t\t\t\t\t       I want to Shop by : ");
        gets(option);
        if(strcmpi(option,"Id")==0)
        {
            printf("\n\n\t\t\t\t\t   Type 'end' if you are done shopping");
            printf("\n\n\t\t\t\t\t   Enter the product id you want to buy: ");
            gets(product);
            if(strcmpi(product,"end")==0)
            {
            }
            else
            {
                printf("\n\n\t\t\t\t\t   Enter the quantity of the product: ");
                scanf("%d",&STORE.want);
                cas=STORE.want;
            }
            fixed_title(0);
            rewind(fptr);
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductId,product)==0)
                {
                    if(STORE.quantity>=cas)
                    {
                        puts("\n\t\t\t\t     **************************************************\n\t\t\t\t\t\t      Your Product is \n\t\t\t\t     **************************************************\n");
                        total= cas*STORE.price;
                        printf("\n\n\t\t\t\t\t           Product Id: ");
                        puts(STORE.ProductId);
                        printf("\t\t\t\t\t           ProductName: ");
                        puts(STORE.ProductName);
                        printf("\t\t\t\t\t           Quantity: ");
                        printf("%d",cas);
                        printf("\n\t\t\t\t\t           Price: ");
                        printf("%.3fTk",STORE.price);
                        actamount=actamount+total;
                    }
                    else
                    {
                        system("color F9");
                        printf("\n\n\t\t\t\t\t     Sorry! This Product Is Not Available Right Now!");
                        printf("\n\n\t\t\t\t\t           Select other products!");
                    }
                }
                else if(strcmpi(product,"end")==0)
                {
                    break;
                }
            }
        }
        else if(strcmpi(option,"Name")==0)
        {
            printf("\n\n\t\t\t\t\t   Type 'end' if you are done shopping");
            printf("\n\n\t\t\t\t\t   Enter the product Name you want to buy: ");
            gets(product);
            if(strcmpi(product,"end")==0)
            {

            }
            else
            {
                printf("\n\n\t\t\t\t\t   Enter the quantity of the product: ");
                scanf("%d",&cas);
            }
            fixed_title(0);
            rewind(fptr);
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductName,product)==0)
                {
                    if(STORE.quantity>=cas)
                    {
                        puts("\n\t\t\t\t     **************************************************\n\t\t\t\t\t\t      Your Product is \n\t\t\t\t     **************************************************\n");
                        total= cas*STORE.price;
                        printf("\n\n\t\t\t\t\t           Product Id: ");
                        puts(STORE.ProductId);
                        printf("\t\t\t\t\t           ProductName: ");
                        puts(STORE.ProductName);
                        printf("\t\t\t\t\t           Quantity: ");
                        printf("%d",cas);
                        printf("\n\t\t\t\t\t           Price: ");
                        printf("%.3fTk",STORE.price);
                        actamount=actamount+total;
                    }
                    else
                    {
                        system("color F9");
                        printf("\n\n\t\t\t\t\t     Sorry! This Product Is Not Available Right Now!");
                        printf("\n\n\t\t\t\t\t           Select other products!");
                    }
                }
                else if(strcmpi(product,"end")==0)
                {
                    break;
                }
            }
        }
        else
        {
            printf("\n\t\t\t\t\t     Enter Correctly to Search Prodects");
        }
        if((strcmpi(product,"end")==0) && actamount!=0)
        {
            printf("\n\t\t");
            printf("\n\n\t\t\t\t\t\t        Receipt \n");
            printf("\t\t\t\t\t\t     ------------- \n");
            printf("\n\t\t");
            printf("\n\t\        Product Id\t Product Name\t Ordered Quantity\t Price per Product\t Total Price ");
            printf("\n");
            printf("\n\t             %s\t           %s\t            %d\t               %.3fTk\t            %.3fTk",STORE.ProductId,STORE.ProductName, cas,STORE.price,(STORE.price* cas));
            if(actamount>=300 && actamount<700)
            {
                printf("\n\n\t\t\t\t\t\t  The Total Bill: %.3fTk",actamount);
                float y=(actamount-50);
                printf("\n\n\t\t\t\t\t     Your Total Bill After'BOGO OFFER': %.3fTk",y);
                char voucher[1000];
                printf("\n\n\t\t\t\t\t***Press 'Enter' if you do not have Voucher***");
                printf("\n\n\t\t\t\t\tEnter Voucher Code to get 50 percent discount:  ");
                gets(voucher);
                if((strcmpi(voucher,"wasif sir")==0))
                {
                    float x =(y-(y*0.5));
                    printf("\n\n\t\t\t\t\tYour Total Bill After Using Voucher: %.3fTk",x);
                    char location[1000];
                    printf("\n\n\t\t\t\t\t\tEnter your location: ");
                    gets(location);
                    if((strcmpi(location,"Dhaka")==0))
                    {
                        if(actamount>=1000)
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(Free of Delivery Charge): %.3fTk",x);
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(With Delivery Charge): %.3fTk",x+50);
                        }
                    }
                    else if((strcmpi(location,"Dhaka")!=0))
                    {
                        if(actamount>=1000)
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(Free of Delivery Charge)Outside Dhaka: %.3fTk",x);
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(With Delivery Charge)Outside Dhaka: %.3fTk",x+100);
                        }
                    }
                }
                else
                {
                    printf("\n\t\t\t\t\t\t       The Voucher Code is Invalid!");
                }
            }
            else if(actamount>=700)
            {
                printf("\n\n\t\t\t\t\t\t  The Total Bill: %.3fTk",actamount);
                float y=(actamount-200);
                printf("\n\n\t\t\t\t     Your Total Bill After'BUMPER OFFER': %.3fTk",y);
                char voucher[1000];
                printf("\n\n\t\t\t\t\t***Press 'Enter' if you do not have any Voucher***");
                printf("\n\n\t\t\t\t\tEnter Voucher Code to get 50 percent discount:  ");
                gets(voucher);
                if((strcmpi(voucher,"wasif sir")==0))
                {
                    float x =(y-(y*0.5));
                    printf("\n\n\t\t\t\t\tYour Total Bill After Using Voucher: %.3fTk",x);
                    char location[1000];
                    printf("\n\n\t\t\t\t\t\tEnter your location: ");
                    gets(location);
                    if((strcmpi(location,"Dhaka")==0))
                    {
                        if(actamount>=1000)
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(Free of Delivery Charge): %.3fTk",x);
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(With Delivery Charge): %.3fTk",x+50);
                        }
                    }
                    else if((strcmpi(location,"Dhaka")!=0))
                    {
                        if(actamount>=1000)
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(Free of Delivery Charge)Outside Dhaka: %.3fTk",x);
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(With Delivery Charge)Outside Dhaka: %.3fTk",x+100);
                        }
                    }
                }
                else
                {
                    printf("\n\t\t\t\t\t\t       The Voucher Code is Invalid!");
                }
            }
            else
            {
                printf("\n\n\t\t\t\t\t\tThe Total Bill: %.3fTk",actamount);
                char voucher[1000];
                printf("\n\n\t\t\t\t\t***Press 'Enter' if you do not have Voucher code***");
                printf("\n\n\t\t\t\t\tEnter the Voucher Code to get 50 percent discount:  ");
                gets(voucher);
                if((strcmpi(voucher,"wasif sir")==0))
                {
                    printf("\n\n\t\t\t\t\tThe Total Bill After Using Voucher Code: %.3fTk",(actamount-(actamount*0.5)));
                    char location[1000];
                    printf("\n\n\t\t\t\t\t\tEnter your location: ");
                    gets(location);
                    if((strcmpi(location,"Dhaka")==0))
                    {
                        printf("\n\n\t\t\t\t\tYour Total Bill(With Delivery Charge): %.3fTk",(actamount-(actamount*0.5))+50);
                        if(actamount>=1000)
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(Free of Delivery Charge): %.3fTk",(actamount-(actamount*0.5)));
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(With Delivery Charge): %.3fTk",(actamount-(actamount*0.5))+50);
                        }
                    }
                    else if((strcmpi(location,"Dhaka")!=0))
                    {
                        if(actamount>=1000)
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(Free of Delivery Charge)Outside Dhaka: %.3fTk",(actamount-(actamount*0.5)));
                        }
                        else
                        {
                            printf("\n\n\t\t\t\t\tYour Total Bill(With Delivery Charge)Outside Dhaka: %.3fTk",(actamount-(actamount*0.5))+100);
                        }
                    }
                }
                else
                {
                    printf("\n\t\t\t\t\t\t       The Voucher Code is Invalid!");
                }
            }
            printf("\n\n\t\t\t\t\t      Enter \"1\" to return to main screen");
            printf("\n\n\t\t\t\t   If you want to buy again then press 'Enter'.");
            char afterpurchase;
            afterpurchase=getche();
            if (afterpurchase=='1')
            {
                fclose(fptr);
                main();
            }
        }
        else if((strcmpi(product,"end")==0) && actamount==0)
        {
            printf("\n\n\t\t\t\t\tYou did not select any product, your cart is empty");
            printf("\n\n\t\t\t\t\t      Enter \"1\" to return to main screen");
            printf("\n\n\t\t\t\t   If you want to buy again then press 'Enter'.");
            char afterpurchase;
            afterpurchase=getche();
            if (afterpurchase=='1')
            {
                fclose(fptr);
                main();
            }
        }
    }
}
void review()
{
    system("color FD");
    printf("\n\t\t\t##############################################################");
    printf("\n\t\t\t\t\t      \"Review Panel\"");
    printf("\n\t\t\t##############################################################");
    int rev;
    printf("\n\n\n\t\t\t\t\t1.Press 0 for Worst experience\n");
    printf("\t\t\t\t\t2.Press 1 for Medium experience\n");
    printf("\t\t\t\t\t3.Press 2 for Good experience\n");
    printf("\t\t\t\t\t4.Press 3 for Best experience\n");
    printf("\n\t\t\t\t\t\tMy Opinion");
    printf("\n\t\t\t\t\t   <><><><><><><><><><>");
    printf("\n\n\t\t\t\t\tMy review choice:");
    scanf("%d",&rev);
    printf("\n\n\t\t\t\t\tThe Feedback about This Shop, My choice is %d",rev);
    if(rev==0)
    {
        printf("\n\t\t\t\t\tMy Experience Is Quite Worst!\n\n");
    }
    if(rev==1)
    {
        printf("\n\t\t\t\t\tMy Experience Is Medium!");
    }
    if(rev==2)
    {
        printf("\n\t\t\t\t\tMy Experience Is Quite Good!");
    }
    if(rev==3)
    {
        printf("\n\t\t\t\t\tMy Experience Is Amazing!\n\n");
    }
    printf("\n\n\n\t\t\t\t\tPress Any Key to Return...");
}

