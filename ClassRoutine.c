#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
void heading()
{
    printf("\t\t\t\tMawlana Bhashani Science and Technology University\n");
    printf("\t\t\t\t\t\tClass Routine\n");
    printf("\t\t\t\t\t   1st Year, 2nd Semister\n");
}
struct Routine
{
    char day[300], courseName[300],courseTeacher[300];
    int timeHour,timeMin;
};

int main()
{
    while(1)
    {
        system("cls");
        heading();
        FILE *x;
        x=fopen("ProjectPro.txt","r");
        int i=0,j=0,n,choose;
        struct Routine a[300],temp;
        printf("1. Teacher's Option\n");
        printf("2. Student's Option\n");
        printf("3. Messages\n");
        printf("4. Exit\n");
        printf("\nChoose Any Option....");
        while(fscanf(x," %[^\n] %[^\n] %[^\n]%d%d",&a[i].day,&a[i].courseName,&a[i].courseTeacher,&a[i].timeHour,&a[i].timeMin)!=EOF)
            i++;
        n=i;
        scanf("%d",&choose);
        system("cls");
        if(choose==1)
        {
            int number;
            while(1)
            {
                char Teacher[300][300];
                int i,j,k=1,count=0;
                for(i=0; i<30; i++)
                {
                    for(j=0; j<30; j++)
                    {
                        Teacher[i][j]='0';
                    }
                }
                strcpy(Teacher[0],a[0].courseTeacher);
                for(i=1; i<n; i++)
                {
                    count=0;
                    for(j=0; j<=k; j++)
                    {
                        if(strcmp(a[i].courseTeacher,Teacher[j])==0)
                            count++;
                    }
                    if(count==0)
                    {
                        strcpy(Teacher[k],a[i].courseTeacher);
                        k++;
                    }
                }
                system("cls");
                heading();
                for(i=0; i<k; i++)
                {
                    printf("%d. ",i+1);
                    printf("%s\n",Teacher[i]);
                }

                printf("%d. Add a new teacher\n",k+1);
                printf("%d. Delete a course\n",k+2);
                printf("%d. Back",k+3);
                printf("\nSelect Your Option....");
                int number;
                scanf("%d",&number);
                system("cls");
                heading();
                if(number==k+3)
                {
                    choose=1;
                    break;
                }
                else if(number==k+1)
                {
                    int jh=0;
                    while(1)
                    {
                        printf("Enter Class Day : ");
                        scanf(" %[^\n]",&a[n].day);
                        printf("Enter Course Name : ");
                        scanf(" %[^\n]",&a[n].courseName);
                        printf("Enter Course Teacher Name : ");
                        scanf(" %[^\n]",&a[n].courseTeacher);
                        printf("Enter Class Starting Time (HH:MM): ");
                        scanf("%d%d",&a[n].timeHour,&a[n].timeMin);
                        for(i=0; i<n; i++)
                        {
                            if(strcmp(a[n].day,a[i].day)==0 &&
                                    (a[n].timeHour==a[i].timeHour && a[n].timeMin == a[n].timeMin))
                            {
                                printf("There is a class at this time.\n");
                                jh=0;
                                break;
                            }
                            else
                                jh=1;
                        }
                        if(jh==1)
                            break;
                    }
                    x=fopen("ProjectPro.txt","w");
                    for(i=0; i<=n; i++)
                        fprintf(x,"%s\n%s\n%s\n%d %d\n",a[i].day,a[i].courseName,a[i].courseTeacher,a[i].timeHour,a[i].timeMin);
                    fclose(x);
                    fopen("ProjectPro.txt","r");
                    printf("\n\nYour Data Uploaded Successfully.");
                    n=n+1;
                    printf("\nPress any key to continue......");
                    getch();
                }
                else if(number==k+2)
                {

                    for(i=0; i<k; i++)
                    {
                        printf("%d. ",i+1);
                        printf("%s\n",Teacher[i]);
                    }
                    printf("\n\nChoose any option for delete : ");
                    int num;
                    scanf("%d",&num);
                    x=fopen("ProjectPro.txt","w");
                    for(i=0; i<n; i++)
                    {
                        if(strcmp(Teacher[num-1],a[i].courseTeacher)!=0)
                            fprintf(x,"%s\n%s\n%s\n%d %d\n",a[i].day,a[i].courseName,a[i].courseTeacher,a[i].timeHour,a[i].timeMin);
                    }
                    n=n-1;
                    fclose(x);
                    fopen("ProjectPro.txt","r");
                    printf("\n\nYour Data Deleted Successfully.");
                    printf("\nPress any key to continue......");
                    /*
                    for(i=0; i<30; i++)
                    {
                        for(j=0; j<30; j++)
                        {
                            Course[i][j]='0';
                        }
                    }*/
                    getch();
                }
                else
                {
                    printf("\t\t                    %s\n",Teacher[number-1]);
                    printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\t\t       Day              Course Name                Time\n");
                    printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    for(i=0; i<n; i++)
                    {
                        if(strcmp(Teacher[number-1],a[i].courseTeacher)==0)
                            printf("\t\t    %-17s%-29s%d:0%d\n",a[i].day,a[i].courseName,a[i].timeHour,a[i].timeMin);
                    }
                    for(i=0; i<k; i++)
                    {
                        for(j=0; j<k; j++)
                        {
                            Teacher[i][j]='0';
                        }
                    }
                    printf("\n\nPress any key to continue......");
                    getch();
                }
            }
        }

        if(choose==2)
        {
            while(1)
            {
                system("cls");
                heading();
                printf("1. Full Routine\n");
                printf("2. Routine for specific day\n");
                printf("3. Back\n");
                printf("\nChoose Any Option....");
                int ask;
                scanf("%d",&ask);
                system("cls");
                if(ask==1)
                {
                    char Dayf[300][300];
                    int k=1,count=0;
                    for(i=0; i<30; i++)
                    {
                        for(j=0; j<k; j++)
                        {
                            Dayf[i][j]='0';
                        }
                    }
                    strcpy(Dayf[0],a[0].day);
                    for(i=1; i<n; i++)
                    {
                        count=0;
                        for(j=0; j<=k; j++)
                        {
                            if(strcmp(a[i].day,Dayf[j])==0)
                                count++;
                        }
                        if(count==0)
                        {
                            strcpy(Dayf[k],a[i].day);
                            k++;
                        }
                    }
                    system("cls");
                    heading();
                    printf("\n\t                                      Class Routine\n");
                    printf("\t         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("\t               Course Name                   Course Teacher                      Time\n");
                    printf("\t         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    int f;
                    for(i=0; i<k; i++)
                    {
                        f=0;
                        printf("\n     %-8s\t",Dayf[i]);
                        for(j=0; j<n; j++)
                        {

                            if(strcmp(Dayf[i],a[j].day)==0)
                            {
                                f++;
                                if(f!=1)
                                    printf("\t\t");
                                printf("     %-29s%-39s%d:0%d\n",a[j].courseName,a[j].courseTeacher,a[j].timeHour,a[j].timeMin);
                            }
                        }
                    }
                    for(i=0; i<k; i++)
                    {
                        for(j=0; j<k; j++)
                        {
                            Dayf[i][j]='0';
                        }
                    }
                    printf("\n\nPress any key to continue......");
                    getch();
                }
                if(ask==2)
                {
                    while(1)
                    {
                        //    system("cls");
                        int k=1;
                        char Day[300][300];
                        for(i=0; i<10; i++)
                        {
                            for(j=0; j<k; j++)
                            {
                                Day[i][j]='0';
                            }
                        }
                        int count=0;
                        strcpy(Day[0],a[0].day);
                        for(i=1; i<n; i++)
                        {
                            count=0;
                            for(j=0; j<=k; j++)
                            {
                                if(strcmp(a[i].day,Day[j])==0)
                                    count++;
                            }
                            if(count==0)
                            {
                                strcpy(Day[k],a[i].day);
                                k++;
                            }
                        }
                        system("cls");
                        heading();
                        for(i=0; i<k; i++)
                        {
                            printf("%d. ",i+1);
                            printf("%s\n",Day[i]);
                        }
                        printf("%d. Back\n",k+1);
                        printf("\nSelect Your Option....");
                        int day_number;
                        scanf("%d",&day_number);
                        if(day_number==k+1)
                        {
                            break;
                        }
                        system("cls");
                        heading();
                        printf("\n\t\t                             Class Routine (%s)\n",Day[day_number-1]);
                        printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        printf("\t\t       Course Name                   Course Teacher                      Time\n");
                        printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                        for(i=0; i<n; i++)
                        {
                            if(strcmp(Day[day_number-1],a[i].day)==0)
                                printf("\t\t    %-29s%-39s%d:0%d\n",a[i].courseName,a[i].courseTeacher,a[i].timeHour,a[i].timeMin);
                        }
                        for(i=0; i<k; i++)
                        {
                            for(j=0; j<k; j++)
                            {
                                Day[i][j]='0';
                            }
                        }
                        printf("\n\nPress any key to continue......");
                        getch();
                    }
                }
                if(ask==3)
                {
                    choose=1;
                    break;
                }
            }
        }
        if(choose==3)
        {
            int d,h,m,countClass=0;
            char dayName[20];
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);

            d=tm.tm_wday;
            h=tm.tm_hour;
            m=tm.tm_min;
            /*
                             d=6;
                              h=7;
                            m=50;
            */
            if(d==1)
                strcpy(dayName,"Monday");
            else if(d==2)
                strcpy(dayName,"Tuesday");
            else if(d==3)
                strcpy(dayName,"Wednesday");
            else if(d==6)
                strcpy(dayName,"Saturday");
            else if(d==7)
                strcpy(dayName,"Sunday");
            heading();
            for(i=0; i<n; i++)
            {
                if(strcmp(dayName,a[i].day)==0)
                {
                    if(a[i].timeMin==0)
                    {
                        if((h==a[i].timeHour-1) && m>=45)
                        {
                            printf("\nFor Teacher\n");
                            printf("Dear, %s Sir,Your are requested to join a class, Subject: %s, at %d:0%d o'clock.",a[i].courseTeacher,a[i].courseName,a[i].timeHour,a[i].timeMin);
                            printf("\n\nFor Student\n");
                            printf("Dear Student,Your are requested to join a class, Subject: %s, at %d:0%d o'clock, conducted by Honorable %s Sir.",a[i].courseName,a[i].timeHour,a[i].timeMin,a[i].courseTeacher);
                            countClass++;
                        }
                    }
                    else if(a[i].timeMin<=15)
                    {
                        if(((h==a[i].timeHour) && m<=a[i].timeMin) || ((h==a[i].timeHour-1) && m>=(45+a[i].timeMin)))
                        {
                            printf("\nFor Teacher\n");
                            printf("Dear, %s Sir,Your are requested to join a class, Subject: %s, at %d:%d o'clock.",a[i].courseTeacher,a[i].courseName,a[i].timeHour,a[i].timeMin);
                            printf("\n\nFor Student\n");
                            printf("Dear Student,Your are requested to join a class, Subject: %s, at %d:%d o'clock, conducted by Honorable %s Sir.",a[i].courseName,a[i].timeHour,a[i].timeMin,a[i].courseTeacher);
                            countClass++;
                        }
                    }
                    else if(a[i].timeMin>15)
                    {
                        if((h==a[i].timeHour) && m>=a[i].timeMin-15)
                        {
                            printf("\nFor Teacher\n");
                            printf("Dear, %s Sir,Your are requested to join a class, Subject: %s, at %d:%d o'clock.",a[i].courseTeacher,a[i].courseName,a[i].timeHour,a[i].timeMin);
                            printf("\n\nFor Student\n");
                            printf("Dear Student,Your are requested to join a class, Subject: %s, at %d:%d o'clock, conducted by Honorable %s Sir.",a[i].courseName,a[i].timeHour,a[i].timeMin,a[i].courseTeacher);
                            countClass++;
                        }
                    }
                }
            }
            if(countClass==0)
                printf("There is no class yet.\n");
            printf("\n\nPress any key to continue......");
            getch();

        }
        if(choose==4)
            break;
    }
    return 0;
}

