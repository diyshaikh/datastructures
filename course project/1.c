#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FIR {
  char Name[20];
  char Aadhar_number[20];
  int IPC;
  float Date;
};

int main(){
  struct FIR lib[100];
  char ar_nm[30], bk_nm[30];
  int i, input, count;
  i = input = count = 0;
printf("\nWELCOME TO FIR DATABASE \n");
printf("1. Register a FIR\n");
printf("2. Display all FIR information\n");
printf("3. List all FIR of given Aadhar_number\n");
printf("4. List the count of FIR's in the FIR\n");
printf("5. Exit\n");

 while (input != 5) {
  printf("\n\nEnter one of "
   "the above: ");
  scanf("%d", &input);
  switch (input) {
  case 1:
   printf("Name = ");
   scanf("%s", lib[i].Name);
   printf("Enter Aadhar number = ");
   scanf("%s", lib[i].Aadhar_number);
   printf("Enter IPC = ");
   scanf("%d", &lib[i].IPC);
   printf("Enter Date = ");
   scanf("%s", &lib[i].Date);
   count++;
   break;
  case 2:
   printf("you have entered"
    " the following "
    "information\n");
   for (i = 0; i < count; i++) {
    printf("Name = %s",
     lib[i].Name);
    printf("\t Aadhar_number = %s",
     lib[i].Aadhar_number);
    printf("\t IPC = %d",
     lib[i].IPC);

    printf("\t Date = %f",
     lib[i].Date);
   }
   break;

  case 3:
   printf("Enter Aadhar_number : ");
   scanf("%s", ar_nm);
   for (i = 0; i < count; i++) {

    if (strcmp(ar_nm,
      lib[i].Aadhar_number)
     == 0)
     printf("%s %s %d %f",
      lib[i].Name,
      lib[i].Aadhar_number,
      lib[i].IPC,
      lib[i].Date);
   }
   break;

  case 4:
   printf("\n No of FIR in "
    "Police Station : %d",
    count);
   break;
  case 5:
   exit(0);
  }
 }
 return 0;
}
