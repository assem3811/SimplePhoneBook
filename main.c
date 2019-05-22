#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int count = 1;
FILE *pRead;
int i,j;
int arrq[100];

typedef struct
{
    int day;
    int month;
    int year;
}birthdate;
struct phoneBook
{
    char firstName[100];
    char lastName[100];
    char street[100];
    char phoneNum[11];
    birthdate DOB;
    char Email[100];
}contacts [100];
int numver(char phone[]);
void sort (struct phoneBook contacts[]);
void printarray(int n);
int emailver(char s1[],char s2[]);
void addContact(struct phoneBook contacts[]);
void loadContacts();
int queryContact(char s1[]);
void saveContacts(struct phoneBook contacts[]);
void delete_contact(struct phoneBook contacts[]);
void modify(struct phoneBook contacts[]);


int main()
{
    printf("\t\t\t\tWELCOME TO PHONEBOOK APPLICATION\n");
    printf("\t\t\t\t---------------------------------\n\n");
    loadContacts();

    int iSelect;
    do
    {
        printf("\t\t\My Contacts (%d/100)\n\n",count-1);
        printf("\t1)\tSearch Contact\n");
        printf("\t2)\tAdd Contacts\n");
        printf("\t3)\tDelete Contact\n");
        printf("\t4)\tModify Contact\n");
        printf("\t5)\tPrint Contacts\n");
        printf("\t6)\tSave changes\n");
        printf("\t7)\tExit!\n");
        printf("\nWhat action do you want to take?");

        scanf("%d",&iSelect);

        if(iSelect==1)
        {
            queryContact(contacts);
        }
        else if (iSelect == 2)
        {
            addContact(contacts);
        }
        else if (iSelect == 3)
        {
            delete_contact(contacts);
        }
        else if (iSelect==4)
        {
            modify(contacts);
        }
        else if (iSelect==5)
        {
            printarray(count);
        }
        else if (iSelect == 6)
        {
            saveContacts(contacts);
        }
        else if (iSelect == 7)
        {
            int s;
            printf("Exit without saving will make all your changes discarded, Are you sure?\n1)Yes\n2)No\nwrite your option:");
            scanf("%d",&s);
            if (s == 1) exit(0);
        }
        else
        {
            printf("Wrong Entry!, Please try again\n\n");
        }



    }while (iSelect != 1 || iSelect !=2 || iSelect !=3 || iSelect !=4 || iSelect !=5 || iSelect !=6 || iSelect !=7 );



    return 0;
}

void printarray(int n)
{
    struct phoneBook temp;
    printf("Enter how you want your contacts to be sorted\n\n");
    printf("1)Sort by last name then first name then phone number\n\n2)Sort by date of birth\n");
    printf("Enter 1 or 2:");
    int op;
    scanf("%d",&op);
    if(op==2)
        {
            for(i=1;i<n;i++)
            {
                for(j=1;j<n;j++)
                {
                    if(contacts[i].DOB.year<contacts[j].DOB.year)
                    {
                        temp=contacts[i];
                        contacts[i]=contacts[j];
                        contacts[j]=temp;
                    }
                    if(contacts[i].DOB.year==contacts[j].DOB.year)
                    {
                        if(contacts[i].DOB.month<contacts[j].DOB.month)
                        {
                            temp=contacts[i];
                            contacts[i]=contacts[j];
                            contacts[j]=temp;
                        }
                        else if(contacts[i].DOB.day<contacts[j].DOB.day)
                        {
                            temp=contacts[i];
                            contacts[i]=contacts[j];
                            contacts[j]=temp;
                        }
                    }
                }
            }
        }

        else if (op==1)
        {
            for(i=1;i<n;i++)
            {
                for(j=1;j<n;j++)
                {
                    if(strcasecmp(contacts[i].lastName,contacts[j].lastName)<0)
                    {
                    temp=contacts[i];
                    contacts[i]=contacts[j];
                    contacts[j]=temp;
                }
                    if(strcasecmp(contacts[i].lastName,contacts[j].lastName)==0)
                    {
                        if(strcasecmp(contacts[i].firstName,contacts[j].firstName)<0)
                       {
                            temp=contacts[i];
                            contacts[i]=contacts[j];
                            contacts[j]=temp;
                       }
                        else if(strcasecmp(contacts[i].phoneNum,contacts[j].phoneNum<0))
                        {
                            temp=contacts[i];
                            contacts[i]=contacts[j];
                            contacts[j]=temp;
                        }
                    }
                }
           }
        }
    for (i=1;i<(n);i++)
    {
        printf("Contact with index:%d\n",i);
        printf("Last Name: %s\n",contacts[i].lastName);
        printf("First Name: %s\n",contacts[i].firstName);
        printf("Date of Birth: %d-%d-%d\n",contacts[i].DOB.day,contacts[i].DOB.month,contacts[i].DOB.year);
        printf("street: %s\n",contacts[i].street);
        printf("E-Mail: %s\n",contacts[i].Email);
        printf("Phone number: %s\n\n\n",contacts[i].phoneNum);
        printf("--------------------------------------------\n\n");

    }
}
int emailver(char s1[],char s2[])
{
    int sl1=strlen(s1),sl2=strlen(s2),i,j=0,f=0;
    for(i=0;i<sl1+1;i++)
    {

       if(f==sl2)
        return 1;
       if(s1[i]==s2[j])
       {
           f++;
           j++;
       }
       else
       {
           j=0;
           f=0;
       }
    }
return 0;
}

void addContact(struct phoneBook contacts[])
{
    struct phoneBook con;
    printf("First Name :");
    scanf("%s",&con.firstName);
    printf("Last Name :");
    scanf("\n%[^\n]",&con.lastName);
    int f;
    do
    {
        printf("Birth date:-\n");
        f=0;
        printf("Enter day:");
        scanf("%d",&con.DOB.day);
        printf("Enter Month:");
        scanf("%d",&con.DOB.month);
        printf("Enter year:");
        scanf("%d",&con.DOB.year);
        if(con.DOB.day>31)
            {
                printf("ERROR. DAY inserted bigger than 31. Enter Again.\n");
                f=1;
            }
        if(con.DOB.month>12)
            {
                printf("ERROR. MONTH inserted bigger than 12. Enter Again.\n");
                f=1;

            }
        if(con.DOB.year>2018)
            {
                printf("ERROR. Year inserted bigger than 2018. Enter Again.\n");
                f=1;}
    }while(f==1);
    printf("Street :");
    scanf("\n%[^\n]",&con.street);
    int a;
    do
    {
        printf("Email :");
        scanf("%s",&con.Email);
        a=emailver(con.Email,"@");
        if(a==0)
            printf("Error inserting email. Please insert again.\n");
    }while(a==0);
    printf("Phone Number :");
    scanf("%s",&con.phoneNum);
    contacts[count] = con;
    count++;
    printf("\n\t Contact added successfully!\n");
}
void loadContacts()
{
    FILE *fp;
    fp=fopen("MyContacts.txt","r");
        while(!feof(fp))
        {   fscanf(fp,"%[^,],",&contacts[count].lastName);
            fscanf(fp,"%[^,],",&contacts[count].firstName);
            fscanf(fp,"%d-",&contacts[count].DOB.day);
            fscanf(fp,"%d-",&contacts[count].DOB.month);
            fscanf(fp,"%d,",&contacts[count].DOB.year);
            fscanf(fp,"%[^,],",&contacts[count].street);
            fscanf(fp,"%[^,],",&contacts[count].Email);
            fscanf(fp,"%[^\n]\n",&contacts[count].phoneNum);
            count++;
        }

            fclose(fp);

}
int queryContact(char s1[])
{
    int i;
    int j=0;
    int arrq[100];
    int s2[100];
    printf("Enter the name you want to search for:\n");
    scanf("\n%[^\n]",&s2);
    for(i=0;i<count;i++)
    {
        if (!strcasecmp(contacts[i].lastName,s2))

        {
            arrq[j]=i;
            j++;
        }


    }
    if(j==0)
        printf("Contact you are searching for  not found.\n");
    else
    {
        printf("Contacts with the last name searched for:\n");
        int n;
        for (n=0;n<j;n++)
        {
            i=arrq[n];
            printf("Contact with index:%d\n",i);
            printf("Last Name: %s\n",contacts[i].lastName);
            printf("First Name: %s\n",contacts[i].firstName);
            printf("Date of Birth: %d-%d-%d\n",contacts[i].DOB.day,contacts[i].DOB.month,contacts[i].DOB.year);
            printf("street: %s\n",contacts[i].street);
            printf("E-Mail: %s\n",contacts[i].Email);
            printf("Phone number: %s\n\n\n",contacts[i].phoneNum);
            i++;
        }
    }
}
void saveContacts(struct phoneBook contacts[])
{
    FILE *fp;
    fp = fopen("MyContacts.txt","w");
    for(i=1;i<count;i++)
    {
        fprintf(fp,"%s,",contacts[i].lastName);
        fprintf(fp,"%s,",contacts[i].firstName);
        fprintf(fp,"%d-%d-%d,",contacts[i].DOB.day,contacts[i].DOB.month,contacts[i].DOB.year);
        fprintf(fp,"%s,",contacts[i].street);
        fprintf(fp,"%s,",contacts[i].Email);
        fprintf(fp,"%s\n",contacts[i].phoneNum);

    }
    fclose(fp);
    printf("\n\nYour system has been updated!\n\n");
}
void delete_contact(struct phoneBook contacts[])
{
    int i;
    int j=0;
    int arrq[100];
    int s2[100];
    printf("Enter the last name you want to search for to delete:");
    scanf("\n%[^\n]",&s2);
    for(i=0;i<count;i++)
    {
        if (!strcasecmp(contacts[i].lastName,s2))

        {
            arrq[j]=i;
            j++;
        }


    }
    if(j==0)
        printf("Contact you want to delete not found.\n");
    else
    {
        printf("Contacts with the last name searched for:\n\n");
        int n;
        for (n=0;n<j;n++)
        {
            i=arrq[n];
            printf("Contact with index:%d\n",i);
            printf("Last Name: %s\n",contacts[i].lastName);
            printf("First Name: %s\n",contacts[i].firstName);
            printf("Date of Birth: %d-%d-%d\n",contacts[i].DOB.day,contacts[i].DOB.month,contacts[i].DOB.year);
            printf("street: %s\n",contacts[i].street);
            printf("E-Mail: %s\n",contacts[i].Email);
            printf("Phone number: %s\n\n\n",contacts[i].phoneNum);
            i++;
        }

        printf("Enter the index of the contact you want to delete:");
        scanf("%d",&i);
        int k;
        for(k=i;k<=(count-2);k++)
            {
                contacts[k] = contacts[k+1];
            }

count--;
    }
}
void modify(struct phoneBook contacts[])
{
  int i;
    int j=0;
    int arrq[100];
    int s2[100];
    printf("Enter the last name you want to search for to modify:");
    scanf("\n%[^\n]",&s2);
    for(i=0;i<count;i++)
    {
        if (!strcasecmp(contacts[i].lastName,s2))

        {
            arrq[j]=i;
            j++;
        }


    }
    if(j==0)
        printf("Contact you want to modify not found.\n");
    else
    {
        printf("Contacts with the last name searched for:\n");
        int n;
        for (n=0;n<j;n++)
        {
            i=arrq[n];
            printf("Contact with index:%d\n",i);
            printf("Last Name: %s\n",contacts[i].lastName);
            printf("First Name: %s\n",contacts[i].firstName);
            printf("Date of Birth: %d-%d-%d\n",contacts[i].DOB.day,contacts[i].DOB.month,contacts[i].DOB.year);
            printf("street: %s\n",contacts[i].street);
            printf("E-Mail: %s\n",contacts[i].Email);
            printf("Phone number: %s\n\n\n",contacts[i].phoneNum);
            i++;
        }

        printf("Enter the index of the contact you want to modify:");
        scanf("%d",&i);
        printf("First Name :");
        scanf("%s",&contacts[i].firstName);
        printf("Last Name :");
        scanf("%s",&contacts[i].lastName);
        int f;
        do
        {
            printf("Birth date:-\n");
            f=0;
            printf("Enter day with format DD:");
            scanf("%d",&contacts[i].DOB.day);
            printf("Enter Month with format MM:");
            scanf("%d",&contacts[i].DOB.month);
            printf("Enter year with format YYYY:");
            scanf("%d",&contacts[i].DOB.year);
            if(contacts[i].DOB.day>31)
                {
                    printf("ERROR. DAY inserted bigger than 31. Enter Again\n");
                    f=1;
                }
            if(contacts[i].DOB.month>12)
                {
                    printf("ERROR. MONTH inserted bigger than 12. Enter Again\n");
                    f=1;

                }
            if(contacts[i].DOB.year>2018)
                {
                    printf("ERROR. Year inserted bigger than 2018. Enter Again\n");
                    f=1;}
    }while(f==1);
    printf("Street :");
    scanf("\n%[^\n]",&contacts[i].street);
    int a;
    do
    {
        printf("Email :");
        scanf("%s",&contacts[i].Email);
        a=emailver(contacts[i].Email,"@");
        if(a==0)
            printf("Error inserting email. Please insert again.\n");
    }while(a==0);
    printf("Phone Number :");
    scanf("%s",&contacts[i].phoneNum);
    printf("\n\t Contact modified successfully!\n");
    }
}
