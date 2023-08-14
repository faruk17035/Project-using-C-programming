#include<stdio.h>
#include<string.h>
void print(int n);
int main()
{
    print(1);
    int month,m,year;
    printf("Enter the number of Month and year\n");
    scanf("%d%d",&m,&year);
    {
        if(m== 1||m== 3||m== 5||m== 7||m== 8||m== 10||m==12)
            month =31;
        else if(m==4 ||m== 6||m== 9||m==11 )
            month=30;
        else if(m==2 && ((year%400==0) ||((year%4==0) &&(year%100!=0))))
            month=29;
        else
            month=28;
    }

    int i,j,k,l;                 //for loop initialization
    int member;
    printf("Enter the number of Mess Members\n");
    scanf("%d",&member);
    char name[50][30];  //////////member name
    int sum_of_seat_bill=0,seat_bill[50]= {0},acu_seat_bill;         //seat bill calculation
    int  meal_cost_personal[50]= {0},meal_cost_total =0,meal_person=0;              // meal cost calculation
    double meal_personal[52][50]= {0},mess_meal_total=0,sum_of_pearsonal_meal[30]= {0};                     // meal calculation
    int bazaar_daily=0,bazar_total_month=0,bazaar_day=0;                    //bazaar calculation
    int another_cost_total=0,another_cost;//another_cost=0;                                //another cost section
    double manager_get[50]= {0.0},manager_give[50]= {0.0},manager_i[50]= {0.0},manager_i2[50]= {0};    //manager i section
    double meal_rate=0,total_cost=0;
    int name_lan[50]= {0},sp;               //name length count and space printing
    int congratulation;     //congratulation part
    double meal_max,meal_min,min_max_difference,z;              //meal max mini
    char dis[4];
    int kharir_bill=0;
    double another_cost_per_head;
    int man_now;
    printf("Enter the name of Mess Members\n\n\t Final result will be execute in this sequence \n");    //inputting name
    for(i=0; i<member; i++)
    {
        printf("%d ",i+1);
        scanf("%s",name[i]);
    }
    printf("\nEnter the accurate amount of Mess Seat Bill \n\n");
    scanf("%d",&acu_seat_bill);
    printf("\nEnter the  amount of Mess Seat Bill was given by members\n");     //inputting seat bill
    printf("If all member pay seat Bill completely just type yes else type no   and hit enter button\n");
    scanf("%s",dis);
    strlwr(dis);
    if(strcmp(dis,"yes")==0)
        sum_of_seat_bill=member*acu_seat_bill;
    else
    {
        for(j=0; j<member; j++)
        {
            printf("%d  %s   ",j+1,name[j]);
            scanf("%d",&seat_bill[j]);
            printf("\n");
        }
    }
    //inputing meal cost
    printf("\nEnter the  amount that given in Meal cost \n");
    for(i=0; i<member; i++)
    {
        printf("%d  %s   ",i+1,name[i]);
        scanf("%d",&meal_cost_personal[i]);
        printf("\n");
        meal_cost_total+=meal_cost_personal[i];
        meal_person=i;
    }

    printf("\nEnter the  meal amount in days\n if there has no data between last date just  press ctrl and z button    at a time\n  \n"); //inputing meal per day
    for(i=0; i<member; i++)
    {
        printf("%d  %s   ",i+1,name[i]);
        while(scanf("%lf",&z)!=EOF)
        {
            sum_of_pearsonal_meal[i]+=z;
        }
        printf("\n");
        mess_meal_total+=sum_of_pearsonal_meal[i];
    }
    //inputting daily bazaar amount
    printf("\nEnter the amount of daily Bazaar \n \t to close calculation just  press ctrl and z button    \n  ");
    i=0;
    while(scanf("%d",&bazaar_daily)!=EOF)
    {
        bazaar_day=i;
        bazar_total_month+=bazaar_daily;
        i++;
    }
    //inputting another cost
    printf("\nEnter the amount of another cost \n \t to close calculation just press ctrl and z button \n  ");
    while(scanf("%d",&another_cost)!=EOF)
    {
        another_cost_total+=another_cost;
    }
//////*********** Kharir bill

    printf("Enter The total cost of 'khari/Lakri' : ");
    scanf("%d",&kharir_bill);

///manger remaining balance
printf("\nEnter how much you have now !!!\n");
scanf("%d",&man_now);

///////////////////////////////   name length calculation/////////////////////////////////
    for(i=0; i<member; i++)
    {
        name_lan[i] =strlen(name[i]);
    }

    //////////////////////////////////main calculation part///////////////////////////


    total_cost=bazar_total_month+ another_cost_total+kharir_bill;
    int meal_cost_t=bazar_total_month+kharir_bill;
    meal_rate=total_cost/mess_meal_total;
    another_cost_per_head= another_cost_total/member;
    //////////////manager get and give section //////////////////
    for(i=0; i<member; i++)
    {
        manager_i[i]= meal_rate*sum_of_pearsonal_meal[i];
        manager_i2[i]=meal_cost_personal[i]-manager_i[i];

        manager_get[i]=(manager_i2[i]<0) ? -1*manager_i2[i] : 0; //get

        manager_give[i]=(manager_i2[i]>0) ? manager_i2[i] : 0; //give


    }
    /////////////////// printing final result //////////////////
    print(2);
    printf("\n\nSuccessfully calculated \n\n");
    printf("\n\n\n-------------------------------------------------FINAL   RESULT-----------------------------------------------\n\n");
    printf("       Name\t\tTotal\t\tTotal\t\t manager     \t\t manager                                       \n");
    printf("            \t\tMeal             Amount            Get              \t  Give \n\n");
    for(i=0; i<member; i++)
    {
        for(l=0; l<111; l++)
            printf("_");
        printf(" \n ");
//data start
        sp=17-name_lan[i];
        printf("%d \t %s",i+1,name[i]);
        for(j=0; j<sp; j++)
            printf(" ");
        printf("%.2lf\t\t  %d \t\t %.2lf\t\t \t%.2lf\t \n",sum_of_pearsonal_meal[i],meal_cost_personal[i],manager_get[i],manager_give[i]);

    }
//data end

    printf("\n");
    for(k=0; k<111; k++)
        printf("_");
    printf(" \n");
////           additional result
    printf("\n\n\nMeal per rate is = %.2lf   and   total meal is %.2lf\n\n\n",meal_rate,mess_meal_total);
    printf("Bazaar done for this month %d days\n",bazaar_day+1); ///adding one by me
    printf("\n\nSum of daily bazaar of this month =  %d/= TK \nAnother cost per head is =  %.2lf/=TK\n\nTOTAL  COST  is = %.2lf /=TK\n",bazar_total_month,another_cost_per_head,total_cost);

    printf("\n\nManager totally got %d /= TK\n and \n Mnager  totally expensed  %.2lf /= TK\n",meal_cost_total,meal_rate*mess_meal_total);
    for(i=0; i<7; i++)
        printf("\n");
    congratulation=(int)total_cost-(int)(meal_rate*mess_meal_total)- another_cost_total;
    congratulation=(congratulation<-1) ? -1*congratulation :congratulation;
    if(congratulation<=1)
        printf("\n\n\t\t\tCongratulation Manager   !!!!!!!!!!!!!!!\n\n\t\t      There is no mistake in your Calculation\n");

    else if(congratulation<0 || congratulation>1)
        printf(" Ops !!!!!!!!     you have some mistake in your calculation \n unclear amount is %d /= TK\n", congratulation);
    for(i=0; i<7; i++)
        printf("\n");


//    getch();
    //getch();
    //getch();
    //getch();
    //getch();
    /*getch();
    getch();
    getch();
    getch();
    getch();
    getch();*/
    return 0;
}

void print(int n)
{
    int i,j,k;
    if(n==1)
    {
        printf("\t\t\t Welcome to Mess bill Calculator v2.0.1.8-0.2\n");
        printf("                                                                      by Faruk and *****\n\n");
    }
    if(n==2)
    {
        int c=0;
        printf("Please wait : ");
        for(i=-1000000; i<=19700000000; i++)
        {
            if(i%209900097==0)
            {
                if(c<18)
                    printf(".");
                c++;
                if(c==23)
                    printf("\nAlmost ready\n");
                if(c>=28)
                    break;
            }
        }
    }
}

