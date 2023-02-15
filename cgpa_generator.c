// *********Header file************

# include<stdio.h>
# include<conio.h>
# include<stdlib.h>
# include<string.h>


#define clrscr();system("cls");

//********gotoxy function*********
void gotoxy(int x, int y){
    printf("%c[%d;%df",0x1B,y,x);

}

//********structure***********

struct student
{
 int registration_number;
 char name[50];
 int physics_marks,cs_marks,maths_marks,ecc_marks,huc_marks,english_marks;
 float cgpa;
 char grade;
 int std;
}students;

//******global declaration**********

FILE *fptr;
char *ptr;
FILE *varnum;

//***********intro*******************

void intro()
{
 clrscr();
 gotoxy(35,11);
 printf("STUDENT");
 gotoxy(33,14);
 printf("REPORT CARD");
 gotoxy(35,17);
 printf("PROJECT");
 printf("\n\n\n\n\n\nTeam Member:  Shashwat Dwivedi  and  Shubham Yadav");
 printf("\n\nCOLLEGE : Indian Institute of Information Technology Kalyani");
 getch();
}





//***********writng function********

void write_student(){
    fptr=fopen("student.csv","a");
    printf("\nPlease Enter the Details of Student\n");
    printf("\nEnter the Registration number of student");
    scanf("%d",&students.registration_number);
    fflush(stdin);
    printf("\nEnter the Name of student");
    gets(students.name);
    printf("\nEnter the marks of PHY101:");
    scanf("%d",&students.physics_marks);
    printf("\nEnter the marks of CS101");
    scanf("%d",&students.cs_marks);
    printf("\nEnter The marks in MAC101 out of 100 : ");
    scanf("%d",&students.maths_marks);
    printf("\nEnter The marks in ECC101 out of 100 : ");
    scanf("%d",&students.ecc_marks);
    printf("\nEnter The marks in HUC101 out of 100 : ");
    scanf("%d",&students.huc_marks);
    printf("\nEnter The marks in HUC102 out of 100 : ");
    scanf("%d",&students.english_marks);    
    students.cgpa=(students.physics_marks+students.cs_marks+students.maths_marks+students.ecc_marks+students.huc_marks+students.english_marks)/60.0;
    if(students.cgpa>=9.5 && students.cgpa<=10)
       students.grade='E';
    else if(students.cgpa>=9 &&students.cgpa<9.5)
      students.grade='A';
    else if(students.cgpa>=8 &&students.cgpa<9)
      students.grade='B';
    else if(students.cgpa>=7 &&students.cgpa<8)
      students.grade='c';
    else if(students.cgpa>=6 &&students.cgpa<7)
      students.grade='D';
    else if(students.cgpa>=5 &&students.cgpa<6)
      students.grade='P';
    else
     students.grade='F';
    fprintf(fptr,"%d,%s,%d,%d,%d,%d,%d,%d,%.2f,%c\n",students.registration_number,students.name,students.physics_marks,students.cs_marks,students.maths_marks,students.ecc_marks,students.huc_marks,students.english_marks,students.cgpa,students.grade);

    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}

//**********multiple add***********

    void multiple_add()
{
    int a,i=1;
    clrscr();
    printf("\n\n\t\tEnter The Number Of Student\'s Record  You Want To Add: ");
    scanf("%d",&a);
    while(i<=a)
{
    write_student();
    i++;
    getch();
}
fclose(fptr);

}
void search(){
  char n[10];
  char *search;
  printf("\nEnter the Registration number of student");
  search = gets(n);
  char line[100];
  char line2[100];
  char *token;
  
  
  

  
  fptr=fopen("student.csv","r");
  if(fptr==NULL){
    printf("Unable to open the file\n");
    exit(1);
  }
  while(fgets(line,100,fptr)!=NULL){
    strcpy(line2,line);
    token= strtok(line,",");

    if (strcmp(token,search)==0){
      printf("%s\n",line2);
      break;
    }
  }
  fclose(fptr);
    getch();

}

void display_all(){
  FILE *fptr;
  fptr=fopen("student.csv","r");
  if (fptr==NULL){
    perror("File not open\n");
    return;
  }
  char line[200];
  printf("Reg Num Name   PHY101   CS101    MAC101   ECC101   HUC101   HUC102    CGPA     Grade\n");

  while (fgets(line,sizeof(line),fptr)){
    char *token;
    token = strtok(line,",");
    int temp=0;
  
    while(token!= NULL){
    
      printf("%s       ",token);
      token= strtok(NULL,",");
    }
    printf("\n");

  }getch();
}


void delete() {
    int reg_num;
    const char *filename="student.csv";
    
    printf("\nEnter the Registration Number of the student\t");
    scanf("%d",&reg_num);
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }
    
    char temp_filename[100];
    sprintf(temp_filename, "%s.csv", filename);
    FILE* temp_fp = fopen(temp_filename, "w");
    if (temp_fp == NULL) {
        printf("Failed to create temporary file %s\n", temp_filename);
        fclose(fptr);
        return;
    }
    
    char line[1024];
    int current_row = 0;
    while (fgets(line, sizeof(line), fptr) != NULL) {
        if (current_row != reg_num) {
            fputs(line, temp_fp);
        }
        current_row++;
    }
    
    fclose(fptr);
    fclose(temp_fp);
 
    
    if (remove(filename) != 0) {
        printf("Failed to delete file %s\n", filename);
        return;
    }
    
    if (rename(temp_filename, filename) != 0) {
        printf("Failed to rename file %s to %s\n", temp_filename, filename);
        return;
    }
    
    printf("Deleted row %d from file %s\n", reg_num, filename);

    
  
}


void update_all_record(){

    int n;
    fptr=fopen("student.csv","w");
    printf("\nEnter the number of student record you want to enter\t");
    scanf("%d",&n);
    while (n!=0){
    printf("\nPlease Enter the Details of Student\n");
    printf("\nEnter the Registration number of student");
    scanf("%d",&students.registration_number);
    fflush(stdin);
    printf("\nEnter the Name of student");
    gets(students.name);
    printf("\nEnter the marks of PHY101:");
    scanf("%d",&students.physics_marks);
    printf("\nEnter the marks of CS101");
    scanf("%d",&students.cs_marks);
    printf("\nEnter The marks in MAC101 out of 100 : ");
    scanf("%d",&students.maths_marks);
    printf("\nEnter The marks in ECC101 out of 100 : ");
    scanf("%d",&students.ecc_marks);
    printf("\nEnter The marks in HUC101 out of 100 : ");
    scanf("%d",&students.huc_marks);
    printf("\nEnter The marks in HUC102 out of 100 : ");
    scanf("%d",&students.english_marks);    
    students.cgpa=(students.physics_marks+students.cs_marks+students.maths_marks+students.ecc_marks+students.huc_marks+students.english_marks)/60.0;
    if(students.cgpa>=9.5 && students.cgpa<=10)
       students.grade='E';
    else if(students.cgpa>=9 &&students.cgpa<9.5)
      students.grade='A';
    else if(students.cgpa>=8 &&students.cgpa<9)
      students.grade='B';
    else if(students.cgpa>=7 &&students.cgpa<8)
      students.grade='c';
    else if(students.cgpa>=6 &&students.cgpa<7)
      students.grade='D';
    else if(students.cgpa>=5 &&students.cgpa<6)
      students.grade='P';
    else
     students.grade='F';
    fprintf(fptr,"%d,%s,%d,%d,%d,%d,%d,%d,%.2f,%c\n",students.registration_number,students.name,students.physics_marks,students.cs_marks,students.maths_marks,students.ecc_marks,students.huc_marks,students.english_marks,students.cgpa,students.grade);
    n--;
    }
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();

}



void main(){

  char ch2;
  intro();
  do{
    char ch2;
    clrscr();
    printf("\n\n\n\tENTRY MENU");
    printf("\n\n\t1.CREATE STUDENT RECORD");
    printf("\n\n\t2.CREATE Multiple STUDENT\'s RECORD");
    printf("\n\n\t3.DISPLAY ALL STUDENTS RECORDS");
    printf("\n\n\t4.SEARCH STUDENT RECORD ");
    printf("\n\n\t5.DELETE STUDENT RECORD");
    printf("\n\n\t6.Update all STUDENT RECORD");
    printf("\n\n\t7.BACK TO MAIN MENU");
    printf("\n\n\tPlease Enter Your Choice (1-7) ");
    ch2=getche();
    switch(ch2)
    {
      case '1': clrscr();
            write_student();
            break;
      case '2' : multiple_add();break;
      case '3': clrscr(); display_all();break;
      case '4':  {
            
             clrscr();
             
            
             search();
            }
            break;
      case '5': delete();break;
      case '6': update_all_record();break;
      case '7': return ;break;
      default:printf("\a");
  
  }
  
  }while(ch2!=6);
}




    


