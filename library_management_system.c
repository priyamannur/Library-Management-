#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include<time.h> 

struct book{
    char name[30];
    char author[30];
    int id;
    int copies;
    struct book *next;
};

struct student{
    char name[30];
    char email[20];
    char book[20];
    char a[30];
    int id;
    int issue_day ,issue_mon , issue_year ;
    struct student *next;
};


struct book *start_lib=NULL;
struct student *start=NULL;
struct book *initialize_lib(struct book *);   
struct student *book_issue(struct student *); 
struct student *book_return(struct student *); 
struct book *diplay_lib(struct book *); 
struct book *delete_book(int id, struct book *);  
struct book *add_book(char [],char [],int);
void display(struct student *);
void greetings();
void main_menu();


int is_leap_year(int);
int date_to_noOfDays(int, int, int);
void book_return_date(int , int , int);
void delay(int, int , int);


int main(){
    start_lib=initialize_lib(start_lib);
    greetings();
    main_menu();
    return 0;
}

void greetings(){
    printf("\n\n");
    printf("\t\t\t     **************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     **************\n");
    printf("\n\n");
    printf("\t\t\t     **************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *           STUDENT LIBRARY            *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *      Dharwad, Karnataka,India        *\n");
    printf("\t\t\t     *     Email: studentlib@gmail.com      *\n");
    printf("\t\t\t     *     Contact:8800991010,8800992020    *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     **************\n");
    printf("\n\n\t\t\t             Press any key to continue: ");
    getch();
}

void main_menu(){
    int choice;
    do{
        printf("\n\n");
        printf("\n\t\t\t*****************\n");
        printf("\n\t\t\t\t      MAIN MENU: ");
        printf("\n\t\t\t\t     1.ISSUE OF BOOKS ");
        printf("\n\t\t\t\t     2.RETURN OF BOOKS ");
        printf("\n\t\t\t\t     3.DISPLAY STUDENT DETAILS ");
        printf("\n\t\t\t\t     4.EXIT\n ");
        printf("\n\t\t\t*****************\n");
        printf("\n\t\t\t\t      Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                start=book_issue(start);
                break;
            }
            case 2:{
                start=book_return(start);
                break;
            }
            case 3:{
                display(start);
                break;
            }
            case 4:{
                exit(1);
            }
            default:{
                printf("\n\t\t\t\t      ...Invalid Option!...\n");
                printf("\n\t\t\t\t      Press any key to try again: ");
                getch();
            }
        }
    }while(choice!=4);
}

struct book *initialize_lib(struct book *start){
    struct book *ptr,*new_book1,*new_book2,*new_book3,*new_book4,*new_book5;

    new_book1=(struct book *)malloc(sizeof(struct book));
    new_book1->next=NULL;
    start_lib=new_book1;
    strcpy(new_book1->name,"The Kite Runner");
    strcpy(new_book1->author,"Khaled Hosseini");
    new_book1->id=101;
    new_book1->copies = 4;
    ptr=new_book1;

    new_book2=(struct book*)malloc(sizeof(struct book));
    new_book2->next=NULL;
    strcpy(new_book2->name,"To Kill A Mockingbird");
    strcpy(new_book2->author,"Harper Lee");
    new_book2->id=102;
    new_book2->copies = 4;
    ptr->next=new_book2;
    ptr=new_book2;

    new_book3=(struct book*)malloc(sizeof(struct book));
    new_book3->next=NULL;
    strcpy(new_book3->name,"The Alchemist");
    strcpy(new_book3->author,"Paulo Coelho");
    new_book3->id=103;
    new_book3->copies = 4;
    ptr->next=new_book3;
    ptr=new_book3;

    new_book4=(struct book*)malloc(sizeof(struct book));
    new_book4->next=NULL;
    strcpy(new_book4->name,"Pride And Prejudice");
    strcpy(new_book4->author,"Jane Austen");
    new_book4->id=104;
    new_book4->copies = 4;
    ptr->next=new_book4;
    ptr=new_book4;

    new_book5=(struct book*)malloc(sizeof(struct book));
    new_book5->next=NULL;
    strcpy(new_book5->name,"A Tale Of Two Cities");
    strcpy(new_book5->author,"Charles Dickens");
    new_book5->id=105;
    new_book5->copies = 4;
    ptr->next=new_book5;

    return start_lib;
}

struct student *book_issue(struct student *start){
    struct book *ptr;
    struct student *ptr2,*new_student;
    int i=1,id,flag=0;
    int count = 0;
    if(start_lib==NULL){
        printf("\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n");
    
        printf("\n\t\t\t\tTotal number of books available are:%d\n",count);
    }else{
        system("cls"); 
        ptr=start_lib;
        printf("\n\t****** Books Available: *******\n");
        while(ptr!=NULL){
            printf("\n\t_________________\n");
            printf("\n\t Book %d",i);
            printf("\n\t Book Title: %s",ptr->name);
            printf("\n\t Name of Author: %s",ptr->author);
            printf("\n\t Book ID: %d",ptr->id);
	    printf("\n\t No of copies available : %d",ptr->copies);
            printf("\n\t_________________\n");
            ptr=ptr->next;
            i++;
            count++;
        }
        printf("\n\n\t Total number of Books available are:%d",count);
        printf("\n\n\t Enter the Book ID: ");
        scanf("%d",&id);
        ptr=start_lib;
        while(ptr!=NULL){
            if(ptr->id==id){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==1){
            ptr=start_lib;
            while(ptr->id!=id){
                ptr=ptr->next;
            }
            new_student=(struct student *)malloc(sizeof(struct student));
            printf("\n\t Enter Student Details:\n ");
            printf("\n\t Enter your Name: ");
            scanf("%s",new_student->name);
            printf("\n\t Enter your Email: ");
            scanf("%s",new_student->email);
            strcpy(new_student->book,ptr->name);
            strcpy(new_student->a,ptr->author);
            new_student->id=ptr->id;
            new_student->next=NULL;

        
            time_t t;
            t = time(NULL);
            struct tm tm = *localtime(&t);
            new_student->issue_day = tm.tm_mday;
            new_student->issue_mon = tm.tm_mon+1;
            new_student->issue_year = tm.tm_year+1900;
        

            printf("\n\t Issue of Book ID %d done successfully!\n",new_student->id);
            printf("\n\n\t*****************\n");
            if(start==NULL){
                start=new_student;
            }else{
                ptr2=start;
                while(ptr2->next!=NULL){
                    ptr2=ptr2->next;
                }
                ptr2->next=new_student;
            }
	    struct book* temp = ptr;
            start_lib=delete_book(new_student->id,temp);
            printf("\n\n\t Press any key to go to the main menu: ");
            getch();
            system("cls");
        }else{
            printf("\n\t\t      ...Invalid Option!...\n");
            printf("\n\t\t      Press any key to try again: ");
            getch();
            system("cls");
        }
    }
    return start;
}

struct student *book_return(struct student *start){
    struct student *ptr,*preptr;
    char bookname[30],authorname[30];
    int flag=0,id,identity,c=0,d=1;
    printf("\n\n\t****** Books Submission: *******\n");
    printf("\n\n\t Enter your Book ID: ");
    scanf("%d",&identity);
    ptr=start;
    while(ptr!=NULL){
        if(ptr->id==identity){
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==1){
        ptr=start;
        while(ptr!=NULL){
            c++;
            ptr=ptr->next;
        }
        ptr=start;
        while(ptr->id!=identity){
                d++;
            ptr=ptr->next;
        }
        ptr=start;
        if( d==1 ){
            printf("\n\t_________________\n");
            printf("\n\t Student Name: %s",start->name);
            printf("\n\t Student Email: %s",start->email);
            printf("\n\t Name of Book Issued: %s",start->book);
            printf("\n\t_________________\n");
            printf("\n\n\t Return of Book ID %d done successfully!\n",identity);
            printf("\n\n\t*****************\n");
            strcpy(bookname,start->book);
            strcpy(authorname,start->a);
            id=start->id;
            start=start->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }else{
            ptr=start;
            while(ptr->id!=identity){
                preptr=ptr;
                ptr=ptr->next;
            }
            printf("\n\t_________________\n");
            printf("\n\t Student Name: %s",ptr->name);
            printf("\n\t Student Email: %s",ptr->email);
            printf("\n\t Name of Book Issued: %s",ptr->book);
            printf("\n\t Book ID: %d",ptr->id);
            printf("\n\t_________________\n");
            strcpy(bookname,ptr->book);
            strcpy(authorname,ptr->a);
            id=ptr->id;
            preptr->next=ptr->next;
            free(ptr);
            add_book(bookname,authorname,id);
        }
        printf("\n\t Thank you! \n\t Do visit again! ");
        printf("\n\n\t Press any key to go to the main menu: ");
        getch();
        system("cls");
    }else{
        printf("\n\tSorry the book doesn't exist! Please recheck the entered ID");
        printf("\n\t\t\t\t      Press any key to try again: ");
        getch();
        system("cls");
    }
    return start;
}

void display(struct student *start){
    struct student *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("\n\t***** Details of Students: ******\n");
        printf("\n\t_________________\n");
        printf("\n\t\t Student Name: %s",ptr->name);
        printf("\n\t\t Student Email: %s",ptr->email);
        printf("\n\t\t Name of Book Issued: %s",ptr->book);
        printf("\n\t\t Book ID: %d",ptr->id);
        printf("\n\t\t Issue date ID: %d/%d/%d",ptr->issue_day,ptr->issue_mon, ptr->issue_year);
        book_return_date(ptr->issue_day,ptr->issue_mon, ptr->issue_year);
        delay(ptr->issue_day,ptr->issue_mon, ptr->issue_year);
        printf("\n\t_________________\n");
        printf("\n\n\t*****************\n");
        ptr=ptr->next;
    }
    if (ptr == NULL)
        printf("\n\n\t\t No BOOKS are issued");
    printf("\n\n\t Press any key to go to the main menu: ");
    getch();
    system("cls");
}

struct book *delete_book(int id, struct book *del){
    struct book *ptr,*preptr;
    int c=0;
    ptr=start_lib;
    while(ptr!=NULL){
        c++;
        ptr=ptr->next;
    }
    if(del->copies==1){
    if(c==1){
        ptr=start_lib;
        start_lib=NULL;
        free(ptr);
    }else if(start_lib->id==id){
        ptr=start_lib;
        start_lib=start_lib->next;
        free(ptr);
    }else{
        ptr=start_lib;
        while(ptr->id!=id){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
    }
    else{
	    del->copies= del->copies-1;
    }
    return start_lib;
}

struct book *add_book(char bookname[30],char authorname[30],int id){
    struct book *ptr,*new_book;
    new_book=(struct book *)malloc(sizeof(struct book));
    strcpy(new_book->name,bookname);
    strcpy(new_book->author,authorname);
    new_book->id=id;
    new_book->next=NULL;
    if(start_lib==NULL){
        start_lib=new_book;
    }else{
        ptr=start_lib;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_book;
    }
    return start_lib;
} 


int is_leap_year(int year){
    int flag= 0;

    if(year % 400 == 0)
        flag =1;
    else if (year % 100 == 0)
        flag= 0;
    else if (year % 4 == 0)
        flag = 1;
    else 
        flag = 0;
    
    return flag;
}

int date_to_noOfDays(int day , int mon ,int year){
    int date=day;
     switch (mon){
        case 1: break;          
        case 2: date+=31;       
                break; 
        case 3: date+=59;       
                break;
        case 4: date+=90;       
                break;
        case 5: date+=120;      
                break;
        case 6: date+=151;      
                break;
        case 7: date+=181;      
                break;
        case 8: date+=212;      
                break;
        case 9: date+=243;      
                break;
        case 10: date+=273;     
                break;
        case 11: date+=304;     
                break;
        case 12: date+=334;     
                break;

        if(is_leap_year(year)==1){
            if (mon != 1 && mon !=2)
            date++;
        }
     }

     return date;
}
void book_return_date(int date , int mon , int year){
    
    if(mon == 1 || mon == 3 || mon == 5|| mon == 7 ||mon == 8 ||mon == 10){
            if(date+15 > 31){
                date = date+15-31; 
                mon++;
            }
            else 
                date+=15;
    }

    else if (mon == 4||mon == 6||mon == 9||mon == 11){
            if(date+15 > 30){
                date = date+15-30; 
                mon++;
            }
            else 
                date+=15;
    }

    
    else if (mon==2){
        if(is_leap_year(year)==1){
             if(date+15 > 29){
                date = date+15-29; 
                mon++;
            }
            else 
                date+=15;
        }

        else {
             if(date+15 > 28){
                date = date+15-28; 
                mon++;
            }
            else 
                date+=15;
        }
    }
    
    else {
         if(date+15 > 31){
                date = date+15-31; 
                mon=1;
                year++;
            }
            else 
                date+=15;
    }

 printf("\n\t\t Return date = %d/%d/%d" , date , mon , year);

}

void delay (int date , int mon , int year){
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    int delay_date = tm.tm_mday;
    int delay_mon = tm.tm_mon+1;
    int delay_year = tm.tm_year+1900;

    int issuedate = date_to_noOfDays(date , mon , year);
    int todaydate = date_to_noOfDays(delay_date ,delay_mon, delay_year);
    int difference;
    int y = delay_year - year;
        difference = (365*y) + todaydate - issuedate ;


    if(difference > 15 ){
        printf("\n\t\t The book is due from %d days" ,difference-15);
    }

    else 
        printf("\n\t\t No dues");
}
