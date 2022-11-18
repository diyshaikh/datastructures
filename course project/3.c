#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FIR {
  char Name[20];
  char Aadhar_number[20];
  int IPC;
  char Date[10];
};

int main(){
  struct FIR lib;
  char ar_nm[30], bk_nm[30];
  int i, input, count;
  i = input = count = 0;
  FILE *fp;
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
    fp=fopen("stu","ab");
    if(fp==NULL){
        printf("can't create file");
        break;
    }
    printf("Name = ");
    scanf("%s", lib.Name);
    printf("Enter Aadhar number = ");
    scanf("%s", lib.Aadhar_number);
    printf("Enter IPC = ");
    scanf("%d", &lib.IPC);
    printf("Enter Date = ");
    scanf("%s", &lib.Date);
    fwrite(&lib,sizeof(lib),1,fp);
    fclose(fp);

    break;
  case 2:
   printf("you have entered the following information\n");
   fp=fopen("stu","rb");
    if(fp==NULL){
      printf("can't read file");
    break;
    }
    while(fread(&lib,sizeof(lib),1,fp)==1){
    printf("Name = %s",lib.Name);
    printf("\t Aadhar_number = %s",lib.Aadhar_number);
    printf("\t IPC = %d",lib.IPC);

    printf("\t Date = %s\n",lib.Date);
   }
   fclose(fp);
   break;
  case 5:
   exit(0);
  }
 }
 return 0;
}
