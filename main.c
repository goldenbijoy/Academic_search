#include <stdio.h>
#include <stdlib.h>

int S_student();
int S_Teacher();
int S_course();
int find_year(char* x);
int HOME()
{
    printf("Welcome to the Search Engine xD!\n");
    printf("|\n|--1. Search By Student ID\n");
    printf("|\n|--2. Search By Course Code\n");
    printf("|\n|--3. Search By Teacher Name\n");
    char x;
    ii:
        x = getch();
        if(x=='1') S_student();
        else if(x=='2') S_course();
        //else if(x=='3') //S_Teacher();
        else goto ii;
}

int S_student()
{
    FILE* fp;
    char line[1000];
    char S_roll[100];
    int check = 0;
    S_S:
        fp = fopen("file/Student.txt","r");
        printf("   |\n   |--Enter the roll of student(ex: CE-16018): ");
        scanf("%s",S_roll);
        while(fgets(line,sizeof(line),fp)){
            char roll[100],temp[100],year[100];
            int y;
            sscanf(line,"%s %s %[^\n]s",&roll,&year,&temp);
            int z = strcmp(S_roll,roll);
            if(z==0){
                char pp[2];
                pp[0] = year[0];
                pp[1] = year[1];
                y = find_year(year);
                printf("      |\n      |%s\n",roll);
                printf("      |\n      |%s\n",temp);
                printf("      |\n      |%s\n",year);
                printf("      |\n      |subject:\n");
                FILE* f;
                f = fopen("file/course.txt","r");
                char sub[1000];
                while(fgets(sub,sizeof(sub),f)){
                    if(sub[4]==pp[0]&&sub[5]==pp[1]) printf("      |%s",sub);
                }
                printf("\n");
                fclose(f);
                check = 1;
                break;
            }

        }
        fclose(fp);
        if(check==0) printf("      |\n      |--Sorry The entry not found.\n");
        printf("         |\n         |--1. search Again.\n");
        printf("         |\n         |--2. Search in another format.\n");
        char z;
        ll:
            z = getch();
            if(z=='1') goto S_S;
            else if(z=='2') HOME();
            else goto ll;
        //goto S_S;
        return 0;
}

int S_course()
{
    FILE* fp;
    char line[1000];
    char S_code[100];
    int check = 0;
    S_S:
        fp = fopen("file/course.txt","r");
        printf("   |\n   |--Enter the code of the subject(ex: CSE-2101): ");
        scanf("%s",S_code);
        while(fgets(line,sizeof(line),fp)){
            char code[100],temp[100];
            sscanf(line,"%s %[^/n]s",&code,&temp);
            int z = strcmp(code,S_code);
            if(z==0){
                check = 1;
                printf("      |\n      |%s\n",code);
                printf("      |\n      |%s",temp);
                char year[100];
                year[0] = code[4];
                year[1] = code[5];
                find_year(year);
                printf("      |\n      |%s\n",year);
                FILE* f = fopen("file/Teacher.txt","r");
                char teacher[1000];
                while(fgets(teacher,sizeof(teacher),f)){
                    sscanf(teacher,"%s %[^/n]s",&code,&temp);
                    int z = strcmp(code,S_code);
                    if(z==0){
                        printf("      |\n      %s\n",temp);
                        break;
                    }
                }
                fclose(f);
                break;
            }
        }
        fclose(fp);
        if(check==0) printf("      |\n      |--Sorry The entry not found.\n");
        printf("         |\n         |--1. search Again.\n");
        printf("         |\n         |--2. Search in another format.\n");
        char z;
        ll:
            z = getch();
            if(z=='1') goto S_S;
            else if(z=='2') HOME();
            else goto ll;

        return 0;
}

int find_year(char* x)
{
    if(x[0]=='1' && x[1]=='1'){
        strcpy(x,"1st Year 1st Semester");
        return 11;
    }
    else if(x[0]=='1' && x[1]=='2'){
        strcpy(x,"1st Year 2nd Semester");
        return 12;
    }
    else if(x[0]=='2' && x[1]=='1'){
        strcpy(x,"2nd Year 1st Semester");
        return 21;
    }
    else if(x[0]=='2' && x[1]=='2'){
        strcpy(x,"2nd Year 2nd Semester");
        return 22;
    }
    else if(x[0]=='3' && x[1] == '1'){
        strcpy(x,"3rd Year 1st Semester");
        return 31;
    }
    else if(x[0]=='3' && x[1]=='2'){
        strcpy(x,"3rd Year 2nd Semester");
        return 32;
    }
    else if(x[0]=='4' && x[1]=='1'){
        strcpy(x,"4th Year 1st Semester");
        return 41;
    }
    else if(x[0]=='4' && x[1]=='2'){
        strcpy(x,"4th Year 2nd Semester");
        return 41;
    }
}


int main()
{
    HOME();
    return 0;
}
