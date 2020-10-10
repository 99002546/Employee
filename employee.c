#include<stdio.h>
struct employee
{
 int empid;
 char name[30];
 char Address[100];
 char Email[50];
 char Phone[10];
}emp;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Employee Id   :");
 scanf("%d", &emp.empid);
 printf("Enter the Name      :");
 scanf("%s", &emp.name);
 printf("Enter the Address      :");
 scanf("%f", &emp.Address);
 printf("Enter the Email      :");
 scanf("%f", &emp.Email);
 printf("Enter the Phone      :");
 scanf("%f", &emp.Phone);
 fwrite(&emp, sizeof(emp), 1, fp);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nEmployee Id\tName\tAddress\tEmail\tPhone\n\n");
 while (fread(&emp, sizeof(emp), 1, fp1))
 printf("  %d\t\t%s\t\t%s\t\t%s\t\t%s\n", emp.empid, emp.name, emp.Address, emp.Email, emp.Phone);
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the Employee Id you want to search  :");
 scanf("%d", &r);
 avl = avlempid(r);
 if (avl == 0)
  printf("Employee Id %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record", "r");
  while (fread(&emp, sizeof(emp), 1, fp2))
  {
   s = emp.empid;
   if (s == r)
   {
    printf("\nEmployee Id = %d", emp.empid);
    printf("\nName        = %s", emp.name);
    printf("\nAddress     = %s\n", emp.Address);
    printf("\nEmail       = %s\n", emp.Email);
    printf("\nPhone       = %s\n", emp.Phone);
   }
  }
  fclose(fp2);
 }
}
//    FUNCTION TO DELETE A RECORD


void deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Employee Id you want to delete :");
 scanf("%d", &r);
 if (avlempid(r) == 0)
  printf("Employee Id %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&emp, sizeof(emp), 1, fpo))
  {
   s = emp.empid;
   if (s != r)
    fwrite(&emp, sizeof(emp), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&emp, sizeof(emp), 1, fpt))
   fwrite(&emp, sizeof(emp), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
//    FUNCTION TO UPDATE THE RECORD
void update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter Employee Id to update:");
 scanf("%d", &r);
 avl = avlempid(r);
 if (avl == 0)
 {
  printf("Employee Id %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&emp, sizeof(emp), 1, fpo))
  {
   s = emp.empid;
   if (s != r)
    fwrite(&emp, sizeof(emp), 1, fpt);
   else
   {
    printf("Enter Name: ");
    scanf("%s", &emp.name);
    printf("Enter Address: ");
    scanf("%f", &emp.Address);
    printf("Enter Email: ");
     scanf("%s", &emp.Email);
     printf("Enter Phone: ");
     scanf("%f", &emp.Phone);
    fwrite(&emp, sizeof(emp), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&emp, sizeof(emp), 1, fpt))
  {
   fwrite(&emp, sizeof(emp), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}
//    FUNCTION TO CHECK GIVEN ROLL NO IS AVAILABLE //
int avlempid(int id)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&emp, sizeof(emp), 1, fp);

  if (id == emp.empid)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record", "r");
 while (fread(&emp, sizeof(emp), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
// MAIN PROGRAM
void main()
{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE");
  printf("\n\t6. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 6:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 6);
}