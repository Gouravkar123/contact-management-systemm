#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 100
#define MAX_NAME_LEN 50
#define MAX_CONTACTS 100
#define MAX_PASS_LENGTH 20
#define MAX_DOB_LEN 100
#define MAX 2000

bool isRunning = true;
void registration();
void login();
void add_email_to_file(char *email);
int is_valid_email(char *email);
void customer_interface();
void emergency();
void mail();
void date();
void delete();
void ex_it();
void add_contact();
void view_all();
void search();
void quick_dial();
void view_contact_list();
int display_quick_dial();

typedef struct 
{
 char name[MAX_NAME_LEN];
 char pass[MAX_PASS_LENGTH];
}Member;
int readMembers(Member members[])
{
 FILE *fptr;
 int count = 0;
 fptr = fopen("members.txt", "rb");
 if (fptr == NULL) 
 {printf("Error opening file.\n");exit(1);}
 while(fscanf(fptr,"%s %s",members[count].name,members[count].pass)!= EOF)
 {count++;}
 fclose(fptr);
 return count;
}
void writeMembers(Member members[], int count)
{
 FILE *fptr;int i;
 fptr = fopen("members.txt", "wb");
 if (fptr == NULL) 
 {printf("Error opening file.\n");exit(1);}
 for (i = 0; i < count; i++)
 {
  fprintf(fptr, "%s %s\n", members[i].name, members[i].pass);
 }
  fclose(fptr);
}

void main()
{
 int choice;
 printf("\n\t|||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]|||||||||||");
 printf("\n\t||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]||||||||||");
 printf("\n\t|||||||||||[][][][][]|                                    |[][][][][]|||||||||||");
 printf("\n\t||||||||||[][][][][][]      WELCOME TO CONTACT BOOK       [][][][][][]||||||||||");
 printf("\n\t|||||||||||[][][][][]|                                    |[][][][][]|||||||||||");
 printf("\n\t||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]||||||||||");
 printf("\n\t|||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][][]|||||||||||\n\n\n\n");
 printf("\t================================================================================\n\n");
 printf("\t[1]---> REGISTRATION\n");

 printf("\t[2]---> LOGIN\n");
 printf("\t[3]---> EXIT\n\n");  
 printf("\t[_]---> Enter your choice : ");
 scanf("%d", &choice);
 printf("\n\t================================================================================\n\n");
 switch(choice) 
 {
  case 1 : registration();
           break;
  case 2 : login();
           break;
  case 3 : ex_it();
           break;
  default :printf("\t------> Invalid CHOICE\n");
           printf("\n\t================================================================================\n\n\n\n\n");
   
 }
}

void registration()
{ 
 FILE *fp;
 char firstname[50];
 char lastname[50];
 char username[50];
 char password[20];

 fp=fopen("members.txt","a");
 if(fp == NULL)
 {
  printf("Error 404 !! FILE NOT FOUND !!\n");   
  exit(1);             
 }
  printf("\n\n\t================================================================================\n");
  printf("\t|                                  REGISTRATION                                |\n");
  printf("\t================================================================================");
  printf("\n\n\t------> Enter your FIRSTNAME : ");
  scanf("%s",firstname);
  printf("\t------> Enter your LASTNAME  : ");
  scanf("%s",lastname);
  printf("\t------> Enter your USERNAME  : ");
  scanf("%s",username);
  printf("\t------> Enter your PASSWORD  : ");
  scanf("%s",password);
  fprintf(fp, "%s %s %s %s\n",username,password,firstname,lastname);
  fclose(fp);
  printf("\n\t------> User registered SUCCESSFULLY");
  printf("\n\t================================================================================\n\n\n\n\n");
  login();             
}
void login()
{
 printf("\n\n\t================================================================================\n");
 printf("\t|                                    LOGIN                                     |\n");
 printf("\t================================================================================\n\n");
 Member members[MAX_CONTACTS];
 int count, i;
 char name[MAX_NAME_LEN], pass[MAX_PASS_LENGTH];
 count = readMembers(members);
 printf("\t------> Enter your USERNAME  : ");
 scanf("%s", name);
 printf("\t------> Enter your PASSWORD  : ");
 scanf("%s", pass);
 for (i = 0; i < count; i++)
 {
  if(strcmp(members[i].name,name)==0&&strcmp(members[i].pass,pass)==0) 
  {
   printf("\n\t------> User Login SUCCESSFULLY!  Welcome, %s.",members[i].name);
   printf("\n\t================================================================================\n\n\n\n\n");
   customer_interface();
   return;
  }
 }
  printf("\n\tInvalid USERNAME or PASSWORD\n\n");
  printf("\tLogin Again  !?!");
  printf("\n\t================================================================================\n\n\n\n\n");
  login();
}

void mail() 
{
 char email[50];
 printf("\t------> Enter E-MAIL          : ");
 scanf("%s",email);
 if (!is_valid_email(email)) {
 printf("\t(Invalid email format, Enter Again)\n");
 mail();
 return ;
 }
  FILE *file = fopen("contacts.txt", "a");
  fprintf(file,"%s\t", email);
  fclose(file);
}

int is_valid_email(char *email) 
{
 char *at = strchr(email, '@');
 char *dot = strchr(email, '.');
 return (at != NULL && dot != NULL && at < dot);
}
void customer_interface()
{
 int choice;
 printf("\t||||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][]||||||||||||\n");
 printf("\t|||||||||||[][][][][]          --- MAIN MENU ---           [][][][][]|||||||||||\n");
 printf("\t||||||||||||[][][][][][][][][][][][][][][][][][][][][][][][][][][][]||||||||||||\n\n");
 printf("\t[1]---> ADD NEW CONTACTS\n");
 printf("\t[2]---> VIEW ALL CONTACTS\n");
 printf("\t[3]---> SEARCH FOR CONTACTS\n");
 printf("\t[4]---> DELETE CONTACT\n");
 printf("\t[5]---> EMERGENCY CONTACTS\n");
 printf("\t[6]---> QUICK DIAL\n");
 printf("\t[7]---> LOGOUT\n\n");
 printf("\t[_]---> Enter your choice : ");
 scanf("%d", &choice);
 printf("\n\t================================================================================\n\n\n\n\n");
 switch(choice) 
 {
  case 1 : add_contact();
           break;
  case 2 : view_all();
           customer_interface();
           break;
  case 3 : search();
           break;
  case 4 : delete();
           break;
  case 5 : emergency();
           break;
  case 6 : quick_dial();
           break;
  case 7 : main();
           break;
  default : printf("\t------> Invalid CHOICE\n");
            printf("\n\t================================================================================\n\n\n\n\n");
   }
}


void add_contact()
{
 FILE *fp;int i;int choice;
 char first_name[20];
 char last_name[20];
 char email[50];
 char phone[15];
 char notes[100];
 char dob[10];
 char add[50];


 printf("\n\n\t================================================================================\n");
 printf("\t|                                ADD NEW CONTACT                               |\n");
 printf("\t================================================================================\n");
 fp = fopen("contacts.txt", "a");
 printf("\n\t------> Enter FIRSTNAME       : ");
 scanf("%s",first_name);
 fprintf(fp,"%s ",first_name);
 printf("\t------> Enter LASTNAME        : ");
 scanf("%s",last_name);
 fprintf(fp,"%s ",last_name);
 printf("\t------> Enter Your PHONE NO.  : ");
 scanf("%s",phone);
 if(strlen(phone)!=10)
 {
  for(i=strlen(phone);i<10 || i>10;)
  {
   printf("\t(Invalid Phone no. format, Enter Again)\n");
   printf("\t------> Enter PHONE NO. again : ");
   scanf("%s",phone);
   if(strlen(phone)==10)
   {fprintf(fp,"%s\t",phone);fclose(fp);
    break;}
  }
  }
   else if(strlen(phone)==10)
   {fprintf(fp,"%s\t",phone);fclose(fp);}
 mail();
 FILE *fptr=fopen("contacts.txt", "a");
 printf("\t------> DOB (DD/MM/YYYY*)     : ");
 scanf("%s",dob);
 fprintf(fptr,"%s ",dob);
 
 printf("\t------> Enter Adderess        : ");
 scanf("%s",add);
 fprintf(fptr,"%s ",add);
 printf("\t------> Add NOTES to Contact  : ");
 scanf("%s",notes);
 fprintf(fptr,"%s\n",notes);
 fclose(fptr);
 printf("\n\t------> Contact Added SUCCESSFULLY");
 printf("\n\t================================================================================\n\n");

 printf("\t[1]---> Add another NEW CONTACT\n");
 printf("\t[2]---> RETURN to MAIN MENU\n\n");
 printf("\t[_]---> Enter your choice : ");
 scanf("%d", &choice);
 printf("\n\t================================================================================\n\n\n\n\n");
 switch(choice) 
 {
  case 1 : add_contact();
           break;
  case 2 : customer_interface();
           break;
  default : printf("\t------> Invalid CHOICE\n");
            printf("\n\t================================================================================\n\n\n\n\n");
   }
 }

void view_all()
{
 FILE *fp;
 char first_name[20];
 char last_name[20];
 char email[50];
 char phone[15];
 char notes[100];
 char dob[10];
 char add[50];


 printf("\n\n\t================================================================================\n");
 printf("\t|                               LIST ALL CONTACT                               |\n");
 printf("\t================================================================================");
 fp = fopen("contacts.txt", "r");      
 printf("\n\t--------------------------------------------------------------------------------");
 printf("\n\t--------------------------------------------------------------------------------");
 while(fscanf(fp, "%s %s %s %s %s %s %s",first_name,last_name,phone,email,dob,notes,add) != EOF) 
 {
  printf("\n\tFIRSTNAME        : %s",first_name);
  printf("\n\tLASTNAME         : %s",last_name);
  printf("\n\tMOBILE NO.       : %s",phone);
  printf("\n\tE-mail Address   : %s",email);
  printf("\n\tDOB (DD/MM/YYYY) : %s",dob);
  printf("\n\tNotes Added      : %s",notes);
  printf("\n\tAddress          : %s\n",add );
  printf("\t--------------------------------------------------------------------------------\n");
  printf("\t--------------------------------------------------------------------------------");
 }
  fclose(fp);
  printf("\n\t================================================================================\n\n\n\n\n");

}
void search()
{
FILE *fp;int choice;
 char search_string[100], line[200];

 printf("\n\n\t================================================================================\n");
 printf("\t|                                 SEARCH CONTACTS                              |\n");
 printf("\t================================================================================\n\n");

 printf("\t------> Enter name to search : ");
 scanf("%s", search_string);
 printf("\t================================================================================\n\n");
 fp = fopen("contacts.txt", "r");
 if(fp==NULL)
 {
  printf("\t------> Unable to open file\n");
  return;
 }
  printf("\t------> All contacts with that name are listed below : \n\n");
  printf("\t--------------------------------------------------------------------------------\n");
  while(fgets(line,sizeof(line),fp)!=NULL)
  {
   if(strstr(line, search_string) != NULL)
  {
   printf("\t %s", line);
   printf("\t--------------------------------------------------------------------------------\n");
  }
 }
  printf("\n\t================================================================================\n\n\n\n\n");
  printf("\t[1]---> SEARCH another CONTACT\n");
  printf("\t[2]---> RETURN to MAIN MENU\n\n");
  printf("\t[_]---> Enter your choice : ");
  scanf("%d", &choice);
  printf("\n\t================================================================================\n\n\n");
  switch(choice) 
  {
   case 1 : search();
            break;
   case 2 : customer_interface();
            break;
   default : printf("\t------> Invalid CHOICE\n");
             printf("\n\t================================================================================\n\n\n\n\n");
    }
  fclose(fp);
  return;
     }
void delete()
    {
    int lno, ctr = 0,a;int choice;
 char ch;
 FILE *fptr1, *fptr2;
 char str[MAX], temp[] = "temp.txt";
 printf("\n\n\t================================================================================\n");
 printf("\t|                                 DELETE CONTACTS                              |\n");
 printf("\t================================================================================");
 view_contact_list();
 printf("\n\t------> DELETE CONTACT :\n");
 printf("\n\t================================================================================\n");
 fptr1 = fopen("contacts.txt", "r");
 if (!fptr1) 
 {
  printf("\t------> CONTACT not found or unable to open the CONTACT!!\n");
  return;
 }
  fptr2 = fopen(temp, "w");
  if (!fptr2) 
 	{
   printf("\t------> Unable to open a temporary file to write!!\n");
   fclose(fptr1);
   return;
  }
   printf("\t------> Input the Number of CONTACT you want to DELETE : ");
   scanf("%d", &lno);
   while (!feof(fptr1)) 
   {
    strcpy(str,"\0");
    fgets(str, MAX, fptr1);
    if (!feof(fptr1)) 
    {
     ctr++;
     if (ctr != lno) 
     {
      fprintf(fptr2, "%s", str);
     }
    }
   }
     fclose(fptr1);
     fclose(fptr2);
     remove("contacts.txt");  		
     rename(temp, "contacts.txt"); 	
     view_contact_list();
  printf("\n\t================================================================================\n\n\n\n\n");

  printf("\t[1]---> DELETE another CONTACT\n");
  printf("\t[2]---> RETURN to MAIN MENU\n\n");
  printf("\t[_]---> Enter your choice : ");
  scanf("%d", &choice);
  printf("\n\t================================================================================\n\n\n");
  switch(choice) 
  {
   case 1 : delete();
            break;
   case 2 : customer_interface();
            break;
   default : printf("\t------> Invalid CHOICE\n");
             printf("\n\t================================================================================\n\n\n\n\n");
    }
}

void view_contact_list()
{
FILE *fp;
char line[100];
int line_num=0;
fp = fopen("contacts.txt", "r");
printf("\n\n\t------> Listed Contacts with numbers :\n");
printf("\n\t================================================================================\n");
printf("\t--------------------------------------------------------------------------------\n");
while(fgets(line, sizeof(line), fp) != NULL) 
{
 printf("\t%d. %s", ++line_num, line);
 printf("\t--------------------------------------------------------------------------------\n");
}
fclose(fp);
}
void quick_dial()
{
 FILE *sourceFile, *destinationFile;
 char line[MAX_LINE_LENGTH];int targetLineNumber;
 char firstString[MAX_LINE_LENGTH];
 char secondString[MAX_LINE_LENGTH];
 int choice;
 printf("\n\n\t================================================================================\n");
 printf("\t|                                   QUICK DIALS                                |\n");
 printf("\t================================================================================\n\n");
 int lineNumber = 0; view_contact_list();
 printf("\n\t------> Add CONTACT to QUICK DIALS :");
 printf("\n\t================================================================================\n");
 printf("\n\t------> Enter contact no. you want to add to quick dials :");
 scanf("%d",&targetLineNumber);
 sourceFile = fopen("contacts.txt", "r");
 if (sourceFile == NULL)
 {
  printf("Failed to open source file.\n");
  return;
 }
  destinationFile = fopen("quickdial.txt", "a");
  if (destinationFile == NULL)
  {
   printf("Failed to open destination file.\n");
   fclose(sourceFile);
   return;
  }
   while (fgets(line, sizeof(line), sourceFile) != NULL)
   {
    lineNumber++;
    if(lineNumber == targetLineNumber)
    {
     sscanf(line, "%s %s", firstString, secondString);
     fprintf(destinationFile, "%s %s\n", firstString, secondString);
     break;
    }
   }
    fclose(sourceFile);
    fclose(destinationFile);
    printf("\t------> Contact added SUCCESSFULLY\n");

  printf("\t================================================================================\n\n\n\n\n");

  printf("\t[1]---> Add another CONTACT to QUICK DIALS\n");
  printf("\t[2]---> RETURN to MAIN MENU\n\n");
  printf("\t[3]---> Display Quick Dials\n\n");
  printf("\t[_]---> Enter your choice : ");
  scanf("%d", &choice);
  printf("\n\t================================================================================\n\n\n");
  switch(choice) 
  {
   case 1 : quick_dial();
            break;
   case 2 : customer_interface();
            break;
   case 3 : display_quick_dial();
            break;
   default : printf("\t------> Invalid CHOICE\n");
             printf("\n\t================================================================================\n\n\n\n\n");
    }
    return;
}
int display_quick_dial()
{
 FILE *file;
 char line[100];
 file = fopen("quickdial.txt", "r");
 if (file == NULL)
 {
  printf("Error opening the file.\n");
  return 1;
 }
 int i=1;
  while(fgets(line,sizeof(line),file)!= NULL)
  {
   printf("\t%d %s",i,line);
   i++;
  }
   fclose(file);
   return 0;
}
void emergency()
{
 printf("\n\n\t================================================================================\n");
 printf("\t|                              EMERGENCY CONTACTS                              |\n");
 printf("\t================================================================================");
 printf("\n\t------> National Emergency No. : 112\n");
 printf("\n\t------> Police Station         : 100\n");
 printf("\n\t------> COVID-19 Helpline      : 011-23978046/1075 \n");
 printf("\n\t------> Ambulance Helpline     : 08/102/108\n");
 printf("\n\t------> Fire station           : 101\n");
 printf("\n\t------> Railway Helpline       : 1512/139\n");
 printf("\n\t------> Child Helpline         : +91-712-2520699\n");
 printf("\n\t------> Womens Helpline        : 1091/181\n");
 printf("\n\t------> hospital helpline      : 104\n");
 printf("\n\t------> Blood Bank             : 1910\n");
 printf("\n\t------> LPG Leak Helpline      : 1906\n");
 printf("\n\t------> Diasater Helpline      : 1077\n");
 printf("\n\t------> Muncipal Corporation   : 1800 1030 222\n");
 printf("\n\t------> Cyber Crime            : 020-29710097\n\n");
 printf("\t================================================================================\n\n\n\n\n");
 customer_interface();
}
void ex_it()
{
 printf("\n\t================================================================================");
 printf("\n\t|                           EXITING FROM THE SYSTEM                            |");
 printf("\n\t================================================================================\n\n");

    
        char ThankYou[100] = "\t====== THANK YOU =======\n";
        char SeeYouSoon[100] = "\t===== SEE YOU SOON =====\n";
        int i=0;
        for(i=0;i<strlen(ThankYou);i++){
            printf("%c",ThankYou[i]);
            Sleep(40);
        }
        for(i=0;i<strlen(SeeYouSoon);i++){
            printf("%c",SeeYouSoon[i]);
            Sleep(40);
      
    }
  
}