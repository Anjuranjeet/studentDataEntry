#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    char name[30];
    float mark;
}stud;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
    FILE *fp;
    fp=fopen("Record","a");
    printf("Enter the Roll no  :");
    scanf("%d",&stud.rollno);
    printf("Enter the Name      :");
    scanf("%s",&stud.name);
    printf("Enter the mark      :");
    scanf("%f",&stud.mark);
    fwrite(&stud,sizeof(stud),1,fp);
    fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
    FILE *fp1;
    fp1=fopen("Record","r");
    printf("\nRoll Number\tname\tMark\n\n");
   while(fread(&stud,sizeof(stud),1,fp1))
    printf("%d\t\t%s\t%.2f\n",stud.rollno,stud.name,stud.mark);
    fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
void search()
{
    FILE *fp2;
    int r,s,avl;
    printf("\nEnter the Roll no you want to search  :");
    scanf("%d",&r);
    avl=avlrollno(r);
    if(avl==0)
    printf("Roll No %d is not avilable in the file\n",r);
    else
    {
        fp2=fopen("Record","r");
        while(fread(&stud,sizeof(stud),1,fp2))
        {
            s=stud.rollno;
            if(s==r)
            {
                printf("\nRoll no = %d",stud.rollno);
                printf("\nName    = %s",stud.name);
                printf("\nMark    = %.2f",stud.mark);
            }
        }
        fclose(fp2);
    }
}
//    FUNCTION TO DELETE A RECORD
void deletef()
{
    FILE *fp;
    FILE *fpt;
    int r,s;
    printf("Enter the Roll no you want to delete :");
    scanf("%d",&r);
    if(avlrollno(r)==0)
	{
    printf("Roll no %d is not available in the file\n",r);
	return ;
	}
    else
    {
        fp=fopen("Record","r");
        fpt=fopen("TempFile","w");
        while(fread(&stud,sizeof(stud),1,fp))
        {
            s=stud.rollno;
            if(s!=r)
            fwrite(&stud,sizeof(stud),1,fpt);
        }
        fclose(fp);
        fclose(fpt);
        /*fp=fopen("Record","w");
        fpt=fopen("TempFile","r");
        while(fread(&stud,sizeof(stud),1,fpt))
        fwrite(&stud,sizeof(stud),1,fp);*/
			remove("Record");
			rename("TempFile","Record");
        printf("\nRECORD DELETE\n");
    }
    fclose(fp);
    fclose(fpt);
}
//    FUNCTION TO UPDATE THE RECORD
void update()
{
    int avl;
    FILE *fpt;
    FILE *fp;
    int s,r,ch;
    printf("enter roll number to update");
    scanf("%d",&r);
    avl=avlrollno(r);
    if(avl==0)
     {
        printf("roll number %d is not Available in the file",r);
		return ;
     }
    else
     {
        fp=fopen("Record","r");
        fpt=fopen("TempFile","w");
        while(fread(&stud,sizeof(stud),1,fp))
          {
            s=stud.rollno;
            if(s!=r)
            fwrite(&stud,sizeof(stud),1,fpt);
            else
             {
                printf("\n\t1_UPDATE THE NAME OF ROLL NUMBER %d",r);
                printf("\n\t2_UPDATE THE MARK OF ROLL NUMBER %d",r);
                printf("\n\t3_UPDATE BOTH NAME  AND MARK OF ROLL NUMBER %d",r);
                printf("\n\n eNTER YOUR CHOICE");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                    printf("Enter Name : ");
                    scanf("%s",stud.name);
                    break;
                    case 2:
                    printf("Enter Mark : ");
                    scanf("%f",&stud.mark);
                    break;
                    case 3:
                    printf("Enter Name and Mark: ");
                    scanf("%s%f",stud.name,&stud.mark );
                    break;
                    default:
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&stud,sizeof(stud),1,fpt);
            }
        }    
        fclose(fp);
        fclose(fpt);
       /* fp=fopen("Record","w");
        fpt=fopen("TempFile","r");
        while(fread(&stud,sizeof(stud),1,fpt))
        {
            fwrite(&stud,sizeof(stud),1,fp);
        }
        fclose(fp);
        fclose(fpt);*/
		remove("Record");
			rename("TempFile","Record");
        printf("RECORD UPDATED");
    }
}
xxxxxxx
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
  int c=0;
  FILE *fp;
  fp=fopen("Record","r");
  while(fread(&stud,sizeof(stud),1,fp))
  c=1;
  fclose(fp);
  return c;
}
// MAIN PROGRAM
int main()
{
int c,emp;
	int empty();
do
{
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2.DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5.UPDATE\n\t6.SORT");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
     scanf("%d",&c);
     printf("\n");
     switch(c)
    {
        case 1:
            insert();
            break;
        case 2:
            emp=empty();
            if(emp==0)
            printf("\nThe file is EMPTY\n");
            else
            disp();
            break;
        case 3:
            search();
            break;
        case 4:
            deletef();
            break;
        case 5:
            update();
            break;
        case 6:
            emp=empty();
            if(emp==0)
            printf("\n The file is EMPTY\n");
            else
            sort();
            break;
        case 7:
            exit(0);
        default:
            printf("\nYour choice is wrong\nPlease try again...\n");
            break;

        }
    }while(c!=7);
}
