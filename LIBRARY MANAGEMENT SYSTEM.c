#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define RETURNTIME 15

char password[10]={"b7"};
char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
int s;char findbook;
struct Date
{
    int mm,dd,yy;
};
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void brick1()
{
    int i;
    for(i=0;i<30;i++)
        printf("\xB2\xB2  ");
}
void brick2()
{
    int i;
    for(i=0;i<30;i++)
        printf("  \xB2\xB2");
}
void pattern1()
{
    int i;
    for(i=0;i<15;i++)
        printf("\xDB\xDB  \xB2\xB2  ");
}
void pattern2()
{
    int i;
    for(i=0;i<15;i++)
        printf("  \xDB\xDB  \xB2\xB2");
}
void patternline1()
{
    int i;
    for(i=0;i<60;i++)
        printf("\xDB\xB2");
}
void patternline2()
{
    int i;
    for(i=0;i<30;i++)
        printf("\xDB\xDB\xB2\xB2");
}
void patternline3()
{
    int i;
    for(i=0;i<60;i++)
        printf("\xB2\xDB");
}
void patternline4()
{
    int i;
    for(i=0;i<30;i++)
        printf("\xB2\xB2\xDB\xDB");
}

FILE *fp,*ft,*fs;
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct Date issued;
    struct Date duedate;
};
struct books a;

int getdata()
{
    int t,i,j;
    system("color A2");

    for(j=0;j<2;j++)
    {
       gotoxy(0,2*j);
       pattern1();
       gotoxy(0,(2*j)+1);
       pattern2();
    }
      for(j=13;j<15;j++)
    {
       gotoxy(0,2*j);
       pattern1();
       gotoxy(0,(2*j)+1);
       pattern2();
    }
     gotoxy(4,6);
    for(i=0;i<40;i++)
        printf("\xDB");
    printf("   Enter the Information Below   ");
     for(i=0;i<40;i++)
        printf("\xDB");
        gotoxy(44,8);
    printf("Category");
       gotoxy(54,8);
    printf("\xDB\xDB\xB2          %s",catagories[s-1]);
       gotoxy(44,10);
    printf("Book ID");
     gotoxy(54,10);printf("\xDB\xDB\xB2");
   gotoxy(66,10); scanf("%d",&t);
    if(checkid(t) == 0)
    {
            gotoxy(44,15);
        printf("\aThe book id already exists\a");
        getch();
        mainmenulib();
        return 0;
    }
    a.id=t;
      gotoxy(44,12);printf("Book Name");
    gotoxy(54,12);printf("\xDB\xDB\xB2");
    gotoxy(66,12);scanf("%s",a.name);

     gotoxy(44,14);printf("Author");
    gotoxy(54,14);printf("\xDB\xDB\xB2");
   gotoxy(66,14); scanf("%s",a.Author);

    gotoxy(44,16);printf("Quantity");
    gotoxy(54,16);printf("\xDB\xDB\xB2");
    gotoxy(66,16);scanf("%d",&a.quantity);

    gotoxy(44,18);printf("Price");
    gotoxy(54,18);printf("\xDB\xDB\xB2");
    gotoxy(66,18);scanf("%f",&a.Price);

    gotoxy(44,20);printf("Rack No");
    gotoxy(54,20);printf("\xDB\xDB\xB2");
    gotoxy(66,20);scanf("%d",&a.rackno);
    return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==t)
    return 0;  //returns 0 if book exits
      return 1; //return 1 if it not
}

void issuerecord()  //display issued book's information
{
         system("cls");
          system("color 8E");
    gotoxy(0,0);
    patternline1();
    gotoxy(0,1);
    patternline3();
    gotoxy(0,2);
    patternline1();
    gotoxy(0,3);
    patternline3();

   gotoxy(0,26);
   patternline1();
   gotoxy(0,27);
   patternline3();
   gotoxy(0,28);
   patternline1();
   gotoxy(0,29);
   patternline3();

       gotoxy(25,5); printf("The Book has taken by Mr.");
       gotoxy(58,5); printf("\xDB\xDB\xB2>");
       gotoxy(65,5);printf(" %s",a.stname);

       gotoxy(25,7); printf("Issued Date");
       gotoxy(58,7); printf("\xDB\xDB\xB2>");
       gotoxy(65,7);printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);

       gotoxy(25,9); printf("Returning Date");
       gotoxy(58,9); printf("\xDB\xDB\xB2>");
       gotoxy(65,9);printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);


}

void addbooks()
{
    system("cls");
    system("color F4");
    int i,j;
    for(j=0;j<3;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
    gotoxy(10,8);
    for(i=0;i<40;i++)
        printf("\xDB");
        printf("   SELECT CATEGOIES   ");
    for(i=0;i<40;i++)
        printf("\xDB");
    gotoxy(50,10);
    printf("\xDB\xDB\xB2 1. Computer");
    gotoxy(50,12);
    printf("\xDB\xDB\xB2 2. Electronics");
    gotoxy(50,14);
    printf("\xDB\xDB\xB2 3. Electrical");
    gotoxy(50,16);
    printf("\xDB\xDB\xB2 4. Civil");
    gotoxy(50,18);
    printf("\xDB\xDB\xB2 5. Mechanical");
    gotoxy(50,20);
    printf("\xDB\xDB\xB2 6. Architecture");
    gotoxy(50,22);
    printf("\xDB\xDB\xB2 7. Back to main menu");
    gotoxy(50,24);
    printf("\xB2\xB2 Enter your choice:");

    for(j=14;j<16;j++)
    { gotoxy(0,2*j);
      brick1();
      gotoxy(0,(2*j)+1);
      brick2();
    }
    gotoxy(55,25);
    scanf("%d",&s);
    if(s==7)
      mainmenulib();
    if(s>7)
      addbooks();
    system("cls");
    fp=fopen("book.dat","ab+");
    if(getdata()==1)
    {
      a.cat=catagories[s-1];
      fseek(fp,0,SEEK_END);
      fwrite(&a,sizeof(a),1,fp);
      fclose(fp);
      gotoxy(44,22);printf("The record is sucessfully saved");
      gotoxy(44,24);printf("Save any more?(Y / N):");

      if(getch()=='n')
        mainmenulib();
      else
        system("cls");
        addbooks();
    }

}

void deletebooks()
{  int i;
    system("cls");
    system("color F4");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
    system("cls");
    gotoxy(0,1);
    patternline1();
    gotoxy(0,2);
    patternline2();
    gotoxy(0,3);
    patternline3();
    gotoxy(0,4);
    patternline4();
    gotoxy(0,5);
    patternline1();
    gotoxy(0,6);
    patternline2();

    gotoxy(0,22);
    patternline1();
    gotoxy(0,23);
    patternline2();
    gotoxy(0,24);
    patternline3();
    gotoxy(0,25);
    patternline4();
    gotoxy(0,26);
    patternline1();
    gotoxy(0,27);
    patternline2();

   gotoxy(25,8); printf("Enter the Book ID to  delete");
   gotoxy(58,8);printf("\xB2\xB2>");
   gotoxy(65,8);scanf("%d",&d);
   fp=fopen("book.dat","rb+");
   rewind(fp);
   while(fread(&a,sizeof(a),1,fp)==1)
    {   if(a.id==d)
         {  gotoxy(1,10);
            for(i=0;i<40;i++)
             printf("\xDB");
             printf("    The book record is available     ");
            for(i=0;i<40;i++)
             printf("\xDB");

   gotoxy(25,12); printf("Book name is");
   gotoxy(58,12);printf("\xB2\xB2>");
   gotoxy(65,12); printf("%s",a.name);

    gotoxy(25,14); printf("Rack No. is");
    gotoxy(58,14);printf("\xB2\xB2>");
    gotoxy(65,14);printf("%d",a.rackno);
        findbook='t';
        }
    }
    if(findbook!='t')
    {
        gotoxy(40,20);
        printf("No record is found modify the search");
        if(getch())
        mainmenulib();
    }
    if(findbook=='t' )
    {
       gotoxy(25,16);
        printf("Do you want to delete it?(Y/N)");
        gotoxy(58,16);printf("\xB2\xB2>");
        if(getch()=='y')
        {
        ft=fopen("test.dat","wb+");  //temporary file for delete
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id!=d)
            {
            fseek(ft,0,SEEK_CUR);
            fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
            }                              //we want to delete
        }
        fclose(ft);
        fclose(fp);
        remove("book.dat");
        rename("test.dat","book.dat"); //copy all item from temporary file to fp except that
        fp=fopen("book.dat","rb+");    //we want to delete
        if(findbook=='t')
        {

           gotoxy(35,18); printf("The record is sucessfully deleted");

           gotoxy(35,20); printf("Delete another record?(Y/N)");
        }
        }
    else
    mainmenulib();
    fflush(stdin);
    another=getch();
    }
    }

    mainmenulib();
}




void editbooks()
{
    system("cls");
    system("color D0");
    int c=0;
    int d,e,i,j;



    char another='y';
    while(another=='y')
    {
        system("cls");
         for(j=0;j<2;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
     for(j=12;j<15;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
        gotoxy(25,5);printf("Enter Book Id to be edited");
        gotoxy(58,5);printf("\xB2\xB2>");
        gotoxy(65,5);scanf("%d",&d);
        fp=fopen("book.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {
                   gotoxy(1,7);
    for(i=0;i<40;i++)
        printf("\xDB");
                printf("    The book is available   ");
                 for(i=0;i<48;i++)
        printf("\xDB");

                gotoxy(25,9);printf("The Book ID");
                gotoxy(58,9);printf("\xB2\xB2>");
                gotoxy(65,9);printf("%d",a.id);

                 gotoxy(25,11);printf("Enter new name");
                 gotoxy(58,11);printf("\xB2\xB2>");
                 gotoxy(65,11); scanf("%s",a.name);

                gotoxy(25,13); printf("Enter new Author");
                 gotoxy(58,13);printf("\xB2\xB2>");
                gotoxy(65,13);scanf("%s",a.Author);

               gotoxy(25,15); printf("Enter new quantity");
               gotoxy(58,15);printf("\xB2\xB2>");
               gotoxy(65,15); scanf("%d",&a.quantity);

                gotoxy(25,17); printf("Enter new price");
                gotoxy(58,17);printf("\xB2\xB2>");
                gotoxy(65,17); scanf("%f",&a.Price);

               gotoxy(25,19); printf("Enter new rackno");
               gotoxy(58,19);printf("\xB2\xB2>");
               gotoxy(65,19); scanf("%d",&a.rackno);

               gotoxy(42,21); printf("The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {    gotoxy(40,20);

                printf("No record found");
            }
        }

       gotoxy(38,22); printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
    getch();
        mainmenulib();


}

void issuebooks()
{
    int t,i,j;

    system("cls");
    system("color D4");

    for(j=0;j<3;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }

     for(j=13;j<15;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
     gotoxy(10,7);
    for(i=0;i<40;i++)
        printf("\xDB");
    printf(" ISSUE SECTION  ");
    for(i=0;i<40;i++)
        printf("\xDB");

   gotoxy(40,9); printf("1. Issue a Book");

   gotoxy(40,11); printf("2. View Issued Book");

   gotoxy(40,13); printf("3. Search Issued Book");

    gotoxy(40,15);printf("4. Remove Issued Book");

    gotoxy(40,17);printf("Enter a Choice:");
    switch(getch())
    {
    case '1':  //issue book
    {
        system("cls");

        int c=0;
        char another='y';
        while(another=='y')
        {
            system("cls");

             for(j=0;j<2;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }

     for(j=13;j<15;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
            gotoxy(10,5);
    for(i=0;i<40;i++)
        printf("\xDB");
    printf(" ISSUE BOOK SECTION  ");
    for(i=0;i<40;i++)
        printf("\xDB");


           gotoxy(25,7); printf("Enter the Book Id");
           gotoxy(58,7); printf("\xDB\xDB\xB2>");
           gotoxy(65,7);scanf("%d",&t);
            fp=fopen("book.dat","rb+");
            fs=fopen("Issue.dat","ab+");
            if(checkid(t)==0) //issues those which are present in library
            {
                       gotoxy(10,9);
    for(i=0;i<40;i++)
        printf("\xB2");
    printf(" THE BOOK RECORD IS AVAILABLE  ");
    for(i=0;i<30;i++)
        printf("\xB2");

                   gotoxy(25,10); printf("NUMBER OF UNISSUED BOOK IN LRC");
           gotoxy(58,10); printf("\xDB\xDB\xB2>");
           gotoxy(65,10);printf("%d",a.quantity);

            gotoxy(25,11); printf("NAME OF BOOK");
           gotoxy(58,11); printf("\xDB\xDB\xB2>");
           gotoxy(65,11);printf("%s",a.name);


                 if(a.quantity>0)
                    {


                gotoxy(25,13); printf("Enter student name");
                 gotoxy(58,13); printf("\xDB\xDB\xB2>");
                 gotoxy(65,13); scanf("%s",a.stname);

                 gotoxy(25,14); printf("Enter issue day");
                  gotoxy(58,14); printf("\xDB\xDB\xB2>");
                  gotoxy(65,14);scanf("%d",&a.issued.dd);

                 gotoxy(25,15); printf("Enter issue month");
                  gotoxy(58,15); printf("\xDB\xDB\xB2>");
                 gotoxy(65,15); scanf("%d",&a.issued.mm);

                gotoxy(25,16);  printf("Enter issue year");
                 gotoxy(58,16); printf("\xDB\xDB\xB2>");
                  gotoxy(65,16); scanf("%d",&a.issued.yy);

                 gotoxy(25,17);  printf("ISSUED DATE");
                 gotoxy(58,17); printf("\xDB\xDB\xB2>");
                gotoxy(65,17); printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);

                 gotoxy(35,19);printf("The BOOK of ID %d is issued",a.id);
                 a.duedate.dd=a.issued.dd+RETURNTIME;   //for return date
                 a.duedate.mm=a.issued.mm;
                 a.duedate.yy=a.issued.yy;
                 if(a.duedate.dd>30)
                 {
                 a.duedate.mm+=a.duedate.dd/30;
                 a.duedate.dd-=30;

                 }
                 if(a.duedate.mm>12)
                 {
                a.duedate.yy+=a.duedate.mm/12;
                a.duedate.mm-=12;

                 }
                     gotoxy(25,21);  printf("TO BE RETURN");
                 gotoxy(58,21); printf("\xDB\xDB\xB2>");
                gotoxy(65,21); printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);

                 fseek(fs,sizeof(a),SEEK_END);
                 fwrite(&a,sizeof(a),1,fs);
                 fclose(fs);
                 c=1;
                 *(&a.quantity)=a.quantity-1;
                 fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);

            }
            else
               {
                   gotoxy(40,20);
                   printf("No available copies of book at present time");
               }
            }


            if(c==0)
            {gotoxy(20,15);
            printf("No record found");
            }gotoxy(40,22);
            printf("Issue any more(Y/N):");
            fflush(stdin);
            another=getch();
            fclose(fp);
        }

        break;
    }
    case '2':  //show issued book list
    {
        system("cls");
       for(j=0;j<2;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }

     for(j=13;j<15;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }    gotoxy(10,5);
    for(i=0;i<40;i++)
        printf("\xB2");
    printf(" ISSUED BOOK LIST  ");
    for(i=0;i<30;i++)
        printf("\xB2");
       gotoxy(5,7);
        printf("STUDENT NAME\tCATEGORY\tID\tBOOK NAME\tISSUED DATE\tRETURN DATE");
           fs=fopen("Issue.dat","rb");
           printf("\n");
        while(fread(&a,sizeof(a),1,fs)==1)
        {


            printf("      %s",a.stname);

            printf("     \t%s",a.cat);

            printf("\t%d",a.id);

            printf("\t%s",a.name);

            printf("\t\t%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy );

            printf("\t\t%d-%d-%d\n",a.duedate.dd,a.duedate.mm,a.duedate.yy);


            //struct dosdate_t d;
            //_dos_getdate(&d);

//          printf("Current date=%d-%d-%d",d.day,d.month,d.year);


        }
        getch();
        fclose(fs);

        mainmenulib();
    }
    break;
    case '3':   //search issued books by id
    {
        system("cls");
         for(j=0;j<2;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }

     for(j=13;j<15;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
       gotoxy(10,5);
    for(i=0;i<40;i++)
        printf("\xB2");
    printf(" ENTER BOOK ID  ");
    for(i=0;i<30;i++)
        printf("\xB2");

        int p,c=0;
        char another='y';
        while(another=='y')
        {
           gotoxy(40,6);
            scanf("%d",&p);
            fs=fopen("Issue.dat","rb");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(a.id==p)
                {
                    issuerecord();
                        gotoxy(40,8);
                    printf("\nPress any key.......");
                    getch();
                    issuerecord();
                    c=1;
                }

            }
            fflush(stdin);
            fclose(fs);
            if(c==0)
            {
                  gotoxy(40,10);
                printf("No Record Found");
            }

           gotoxy(40,20); printf("Try Another Search?(Y/N)");
            another=getch();
        }
    }
    break;
    case '4':  //remove issued books from list
    {
        system("cls");
          for(j=0;j<2;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }

     for(j=13;j<15;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
        int b;
        FILE *fg;  //declaration of temporary file for delete
        char another='y';
        fp=fopen("book.dat","rb+");
        while(another=='y')
        {

          gotoxy(25,5);  printf("Enter book id to remove");
          gotoxy(58,5); printf("\xDB\xDB\xB2>");
          gotoxy(65,5);  scanf("%d",&b);
            fs=fopen("Issue.dat","rb+");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(a.id==b)
                {
                    issuerecord();
                    findbook='t';
                }
                if(findbook=='t')
                {

                   gotoxy(40,16); printf("Do You Want to Remove it?(Y/N)");
                    if(getch()=='y')
                    {
                        fg=fopen("record.dat","wb+");
                        rewind(fs);
                        while(fread(&a,sizeof(a),1,fs)==1)
                        {
                            if(a.id!=b)
                            {
                            fseek(fs,0,SEEK_CUR);
                            fwrite(&a,sizeof(a),1,fg);
                            }
                        }
                        fclose(fs);
                        fclose(fg);
                        remove("Issue.dat");
                        rename("record.dat","Issue.dat");
                       gotoxy(40,18); printf("\nThe issued book is removed from list");

                       }
                       if(checkid(b)==0)
                {
                  *(&a.quantity)=a.quantity+1;
                 fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                }
                fclose(fp);

                }


                if(findbook!='t')
                {

                  gotoxy(40,15);  printf("No Record Found");
                }
            }
            gotoxy(40,20);printf("Delete any more?(Y/N)");
            another=getch();
        }
    }
    default:
     gotoxy(40,22);
    printf("\aWrong Entry!!");
    getch();
    issuebooks();
    break;
      }

     mainmenulib();
}

void searchbooks(int whc)
{
    system("cls");
    system("color 8E");
    gotoxy(0,0);
    patternline1();
    gotoxy(0,1);
    patternline3();
    gotoxy(0,2);
    patternline1();
    gotoxy(0,3);
    patternline3();

   gotoxy(0,26);
   patternline1();
   gotoxy(0,27);
   patternline3();
   gotoxy(0,28);
   patternline1();
   gotoxy(0,29);
   patternline3();

    int d,i,j;
    gotoxy(10,5);
    for(i=0;i<40;i++)
        printf("\xDB");
    printf(" SEARCH BOOKS  ");
    for(i=0;i<40;i++)
        printf("\xDB");
    gotoxy(40,7);
    printf("\xDB\xDB\xB2 1. Search By ID");
    gotoxy(40,9);
    printf("\xDB\xDB\xB2 2. Search By Name");
    gotoxy(40,12);
    printf("Enter Your Choice");
    fp=fopen("book.dat","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
      case '1':
    {
        system("cls");
        gotoxy(0,0);
        patternline1();
        gotoxy(0,1);
        patternline3();
        gotoxy(0,2);
        patternline1();
        gotoxy(0,3);
        patternline3();

        gotoxy(0,26);
        patternline1();
        gotoxy(0,27);
        patternline3();
        gotoxy(0,28);
        patternline1();
        gotoxy(0,29);
        patternline3();
        gotoxy(10,5);for(i=0;i<40;i++)printf("\xDB");
        printf(" SEARCH BOOKS BY ID ");
        for(i=0;i<40;i++)printf("\xDB");



       gotoxy(25,7); printf("Enter the book id");
       gotoxy(58,7); printf("\xDB\xDB\xB2>");
       gotoxy(65,7);scanf("%d",&d);

       gotoxy(15,9);
       for(i=0;i<40;i++)
       printf("\xB2");
       printf(" SEARCHING ");
       for(i=0;i<40;i++)
       {
           delay(30);
            printf("\xB2");
       }
       while(fread(&a,sizeof(a),1,fp)==1)
        {
        if(a.id==d)
        { gotoxy(10,11);
        for(i=0;i<40;i++)
            printf("\xDB");
        printf(" THE BOOK IS AVAILABLE ");
        for(i=0;i<40;i++)
        printf("\xDB");

        gotoxy(25,13); printf("ID");
        gotoxy(58,13); printf("\xDB\xDB\xB2>");
        gotoxy(65,13); printf("%d",a.id);

        gotoxy(25,15); printf("NAME");
        gotoxy(58,15); printf("\xDB\xDB\xB2>");
        gotoxy(65,15); printf("%s",a.name);

        gotoxy(25,17); printf("AUTHER");
        gotoxy(58,17); printf("\xDB\xDB\xB2>");
        gotoxy(65,17); printf("%s",a.Author);

        gotoxy(25,19); printf("QUANTITY");
        gotoxy(58,19); printf("\xDB\xDB\xB2>");
        gotoxy(65,19); printf("%d",a.quantity);

        gotoxy(25,21); printf("PRICE");
        gotoxy(58,21); printf("\xDB\xDB\xB2>");
        gotoxy(65,21); printf("Rs.%0.2f",a.Price);

        gotoxy(25,23); printf("RACKNO");
        gotoxy(58,23); printf("\xDB\xDB\xB2>");
        gotoxy(65,23); printf("%d",a.rackno);


            findbook='t';
        }

        }
        if(findbook!='t')  //checks whether conditiion enters inside loop or not
        {gotoxy(40,20);
        printf("\aNo Record Found");
        }gotoxy(40,25);
        printf("Try another search?(Y/N)");
        if(getch()=='y')
        searchbooks(whc);
        else
        {
            if(whc==1)
                  mainmenulib();
            else if(whc==0)
                  mainmenuuser();

        }
    break;
    }
    case '2':
    {
        char s[15];
        system("cls");
         gotoxy(0,0);
         patternline1();
         gotoxy(0,1);
         patternline3();
         gotoxy(0,2);
         patternline1();
         gotoxy(0,3);
         patternline3();

         gotoxy(0,26);
         patternline1();
         gotoxy(0,27);
         patternline3();
         gotoxy(0,28);
         patternline1();
         gotoxy(0,29);
        patternline3();
        gotoxy(10,5);for(i=0;i<40;i++)printf("\xDB");
        printf(" SEARCH BOOKS BY NAME ");
        for(i=0;i<40;i++)printf("\xDB");

        gotoxy(25,7); printf("ENTER BOOK NAME");
        gotoxy(58,7); printf("\xDB\xDB\xB2>");
        gotoxy(65,7); scanf("%s",s);

        int d=0;
        while(fread(&a,sizeof(a),1,fp)==1)
        {
        if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
        {   gotoxy(10,9);
            for(i=0;i<40;i++)
            printf("\xDB");
            printf(" THE BOOK IS AVAILABLE ");
            for(i=0;i<40;i++)
              printf("\xDB");

           gotoxy(25,11); printf("ID");
           gotoxy(58,11); printf("\xDB\xDB\xB2>");
           gotoxy(65,11); printf("%d",a.id);

           gotoxy(25,13); printf("NAME");
           gotoxy(58,13); printf("\xDB\xDB\xB2>");
           gotoxy(65,13); printf("%s",a.name);

           gotoxy(25,15); printf("AUTHER");
           gotoxy(58,15); printf("\xDB\xDB\xB2>");
           gotoxy(65,15); printf("%s",a.Author);

           gotoxy(25,17); printf("QUANTITY");
           gotoxy(58,17); printf("\xDB\xDB\xB2>");
           gotoxy(65,17); printf("%d",a.quantity);

           gotoxy(25,19); printf("PRICE");
           gotoxy(58,19); printf("\xDB\xDB\xB2>");
           gotoxy(65,19); printf("Rs.%0.2f",a.Price);

           gotoxy(25,21); printf("RACKNO");
           gotoxy(58,21); printf("\xDB\xDB\xB2>");
           gotoxy(65,21); printf("%d",a.rackno);

            d++;
        }

        }
        if(d==0)
        {  gotoxy(40,20);
           printf("\aNo Record Found");
        }
             gotoxy(40,23);
             printf("Try another search?(Y/N)");
        if(getch()=='y')
        searchbooks(whc);
        else
        {if(whc==1)
                  mainmenulib();
        else if(whc==0)
                  mainmenuuser();


        }
        break;
    }
    default :
    getch();
    searchbooks(whc);
    }
    fclose(fp);



}

void viewbooks()
{
    int i=0,j;
    system("cls");
    system("color F4");
     gotoxy(1,10);
            for(j=0;j<40;j++)
             printf("\xDB");
             printf("    BOOK LIST     ");
            for(j=0;j<40;j++)
             printf("\xDB");

    printf(" CATEGORY\tID\tBOOK NAME\tAUTHOR\tQTY\tPRICE\tRackNo \n");

    fp=fopen("book.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {

    printf("%s",a.cat);

    printf("\t%d",a.id);

    printf("\t%s",a.name);

    printf("\t%s",a.Author);

    printf("\t%d",a.quantity);

    printf("\t%.2f",a.Price);

    printf("\t%d",a.rackno);
    printf("\n\n");

    i=i+a.quantity;
      }

     gotoxy(40,28); printf("Total Books =%d",i);
      fclose(fp);
      getch();
      mainmenuuser();
}


void Password()
{  int i,j;
   char d[25]="Password Protected";
   char ch,pass[10];

   gotoxy(28,18);
   for(i=0;i<64;i++)
   {   delay(5);
       printf("\xB2");
   }

   gotoxy(50,19);
   printf("%s",d);

   gotoxy(28,20);
   for(i=0;i<64;i++)
   {   delay(5);
       printf("\xB2");
   }

   gotoxy(50,22);i=0;
   printf("Enter Password:");
   while(ch!=13)
   {
       ch=getch();
       if(ch!=13 && ch!=8)
       {
           putch('*');
           pass[i]=ch;
           i++;
       }
   }pass[i]='\0';

   if(strcmp(pass,password)==0)
   {  gotoxy(50,23);
      printf("Password match");
      gotoxy(44,24);
      printf("Press any key to countinue.....");
      getch();
      mainmenulib();
   }
   else
   {  gotoxy(44,23);
      printf("\aWarning!! Incorrect Password");
      Password();
   }
}





 void user()
 {
   mainmenuuser();
 }




 void librarian()
 {
     Password();
 }





int main()
{
   start();
   return 0;
 }


void start()
{int i,j;
system("color F1");
 for(j=0;j<3;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
     for(j=13;j<16;j++)
    {
       gotoxy(0,2*j);
       brick1();
       gotoxy(0,(2*j)+1);
       brick2();
    }
     gotoxy(4,8);
    for(i=0;i<40;i++)
        printf("\xDB");
        printf("   LIBERARY MANAGEMENT PROJECT   ");
    for(i=0;i<40;i++)
        printf("\xDB");
        gotoxy(55,10);
        printf("BATCH-B7");
        gotoxy(55,12);
        printf("MADE BY");
        gotoxy(0,14);
        patternline4();
        gotoxy(35,16);printf("AMAN PATEL");
        gotoxy(65,16);printf("(17103264)");

         gotoxy(35,18);printf("MAYUR BANSAL");
        gotoxy(65,18);printf("(17103291)");

         gotoxy(35,20);printf("BHARAT PANJWANI");
        gotoxy(65,20);printf("(17103288)");

         gotoxy(35,22);printf("VAIDYANATH SINGH");
        gotoxy(65,22);printf("(17103284)");
        getch();
         mainmenu1();



}






 void mainmenu1()
 {
    char ch;
    int i;

    system("cls");
    system("color E0");
    gotoxy(28,1);
    for(i=0;i<64;i++)
    printf("\xB2");

    gotoxy(30,2);
    for(i=0;i<60;i++)
    printf("\xDB");

    for(i=0;i<11;i++)
    {     gotoxy(28,2+i);
          printf("\xB2\xB2\n");
    }
    gotoxy(42,4);
    printf("WELCOME TO JIIT LIBRARY PORTAL\n");

    gotoxy(30,6);
    for(i=0;i<60;i++)
    printf("\xDB");

    for(i=0;i<11;i++)
    {   gotoxy(90,2+i);
        printf("\xB2\xB2\n");
    }

    gotoxy(45,8);
    printf("\xDB\xDB\xB2 1.User   \n");
    gotoxy(45,10);
    printf("\xDB\xDB\xB2 2.Librarian\n");

    gotoxy(30,12);
    for(i=0;i<60;i++)
    printf("\xB2");
    gotoxy(48,14);
    printf("Enter your choice:");


     switch(getch())
    {
        case '1':
        user();
        break;
    case '2':
        librarian();
        break;
        default:
gotoxy(32,16);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(getch())
            mainmenu1();
}
 }







 void mainmenulib()
{

    system("cls");

    int i;
     system("color 8E");
    gotoxy(0,0);
    patternline1();
    gotoxy(0,1);
    patternline3();
    gotoxy(0,2);
    patternline1();
    gotoxy(0,3);
    patternline3();

   gotoxy(0,26);
   patternline1();
   gotoxy(0,27);
   patternline3();
   gotoxy(0,28);
   patternline1();
   gotoxy(0,29);
   patternline3();

     gotoxy(30,5);
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
     gotoxy(30,6);
     printf("\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2              \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\n");
     gotoxy(30,7);
     printf("\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2  MAIN  MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\n");
     gotoxy(30,8);
     printf("\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2              \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\n");
     gotoxy(30,9);
     printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB \n");

     gotoxy(32,11);
     printf("\xDB\xDB 1. Add Books   \n");
     gotoxy(32,13);
     printf("\xDB\xDB 2. Delete books\n");
     gotoxy(32,15);
     printf("\xDB\xDB 3. Edit Book's Record\n");
     gotoxy(32,17);
     printf("\xDB\xDB 4. Search Books   \n");
     gotoxy(32,19);
     printf("\xDB\xDB 5. Close Application\n");

    gotoxy(20,21);
    for(i=0;i<54;i++)
     {   delay(15);
         printf("\xB2");
     }
    gotoxy(32,23);
    printf("Enter your choice:");


    switch(getch())
    {
        case '1':
                   addbooks();
                   break;
        case '2':
                   deletebooks();
                   break;
        case '3':
                   editbooks();
                   break;
        case '4':
                   searchbooks(1);
                   break;
         case '5':
                   {
                     system("cls");
                     system("color 0F");
                     gotoxy(20,8);
                     for(i=0;i<54;i++)
                       {    delay(15);
                            printf("\xB2");
                       }
                     gotoxy(20,10);
                     printf("\xB2\xB2        Thanks for using the Program..            \xB2\xB2");
                     gotoxy(20,12);
                     for(i=0;i<54;i++)
                       {     delay(15);
                             printf("\xB2");
                       }
                    gotoxy(38,16);
                    printf("Exiting");
                    gotoxy(20,18);
                    for(i=0;i<54;i++)
                    {
                        delay(120);
                        printf("*");
                    }


                    exit(0);

                  }
          default:
                   {
                    gotoxy(24,25);
                    printf("\aWrong Entry!!Please re-entered correct option");
                    if( getch() )
                    mainmenulib();
                   }
      }
}







 void mainmenuuser()
{
    system("cls");
    int i;
     system("color 8E");
    gotoxy(0,0);
    patternline1();
    gotoxy(0,1);
    patternline3();
    gotoxy(0,2);
    patternline1();
    gotoxy(0,3);
    patternline3();

   gotoxy(0,26);
   patternline1();
   gotoxy(0,27);
   patternline3();
   gotoxy(0,28);
   patternline1();
   gotoxy(0,29);
   patternline3();
    gotoxy(30,5);

    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    gotoxy(30,6);
    printf("\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2              \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\n");
    gotoxy(30,7);
    printf("\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2  MAIN  MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\n");
    gotoxy(30,8);
    printf("\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2              \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\n");
    gotoxy(30,9);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB \n");

    gotoxy(32,11);
    printf("\xDB\xDB 1. Search Books   \n");
    gotoxy(32,13);
    printf("\xDB\xDB 2. Issue Books\n");
    gotoxy(32,15);
    printf("\xDB\xDB 3. View Book List\n");
    gotoxy(32,17);
    printf("\xDB\xDB 4. Close Application\n");
    gotoxy(20,20);
    for(i=0;i<54;i++)
    {   delay(15);
        printf("\xB2");
    }

    gotoxy(32,22);
    printf("Enter your choice:");

     switch(getch())
    {
        case '1':
                   searchbooks(0);
                   break;
        case '2':
                   issuebooks();
                   break;
        case '3':
                   viewbooks();
                   break;
        case '4':
                   {
                      system("cls");
                      system("color 0F");
                      gotoxy(20,8);
                      for(i=0;i<54;i++)
                       {    delay(15);
                            printf("\xB2");
                       }
                      gotoxy(20,10);
                      printf("\xB2\xB2        Thanks for using the Program..            \xB2\xB2");
                      gotoxy(20,12);
                      for(i=0;i<54;i++)
                       {     delay(15);
                             printf("\xB2");
                       }
                      gotoxy(30,16);
                      printf("Exiting...........>");

                      exit(0);
                   }
        default:
                   {gotoxy(24,25);
                    printf("\aWrong Entry!!Please re-entered correct option");
                    if(getch())
                    mainmenuuser();
                   }
    }
}



