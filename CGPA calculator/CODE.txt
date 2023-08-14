#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
template<typename T>
int integer(T a)
{
    int res;
    stringstream os(a);
    os>>res;
    return res;
}
vector<string>v1,v2;
vector<double>cr,mr;
double func(double mark);
double func_pro(string &s);
string lg(double z);
int main()
{
    string id,a,b,c,d,e,cc,year,semester;
    double course_num,gp,mark,m,x,z,sum=0,pro;
    printf("\t\t\t\tWELLCOME TO MY CGPA CALCULATOR\t\t\n");
    printf("\t\t\tYear(Case sensitive.Example:1st,2nd,3rd...):");
    cin>>year;
    printf("\t\t\tSemester(Case sensitive.Example:1st,2nd,3rd...):");
    cin>>semester;
    printf("\t\t\tEnter student id (Case sensitive.Example:IT-170...):");
    cin>>id;
    freopen("marks_sheet.txt","r",stdin);
    getline(cin,b);
    stringstream ss(b);
    int cnt=1,cn=0;
    while(ss>>c)
    {
        if(cnt>2 and cnt%2!=0)
        {
            int m=integer(c);
            cr.push_back(m);///COURSE CREDIT PUSH IN cr VECTOR///
            sum+=m;
            cn++;///HOW MANY COURSES IN THIS SEMESTER///
        }
        else if(cnt>1 and cnt%2==0)
            v2.push_back(c);///COURSE CODE PUSH IN v2 VECTOR AS STRING///
        cnt++;
    }
    course_num=cn;
    bool f=0;
    while(getline(cin,b))
    {
        stringstream ss1(b);
        while(ss1>>a)
        {
            if(a==id)
            {
                f=1;
                continue;
            }
            if(f)
                mr.push_back(integer(a));///THIS VECTOR STORE MARKS OF INPUT CORRESPOND STUDENT///
        }
        if(f)
            break;
    }
    x=0;
    vector<string>bl;
    for(int i=0; i<course_num; i++)
    {
        gp=func(mr[i]);
        if(gp==0)
            bl.push_back(v2[i]);
        x+=cr[i]*gp;
    }
    z=x/(double)sum;
    pro=func_pro(year);
    if(z>=pro)
    {
        e=lg(z);
        cout<<"\t\tThe Grade Point of "<<id<<" is "<<fixed<<setprecision(2)<<z<<".";
        if(bl.size()==0)
            cout<<endl;
        else
        {
            for(int i=0;i<bl.size();i++)
            cout<<"BL-"<<" ( "<<bl[i]<<" )";
            cout<<endl;
        }
        cout<<"\t\tThe Letter Grade of "<<id<<" is "<<e<<"."<<endl;
        cout<<"\t\t"<<id<<" is promoted to the next semester."<<endl;
    }
    else
        cout<<"\t\t\t"<<id<<" is not promoted to the next semester."<<endl;
    getchar();
    getchar();
    return 0;
}
double func(double mark)
{
    double gp;
    if(mark<40)
        gp=0;
    else if(mark>=40&&mark<45)
        gp=2.00;
    else if(mark>=45&&mark<50)
        gp=2.25;
    else if(mark>=50&&mark<55)
        gp=2.5;
    else if(mark>=55&&mark<60)
        gp=2.75;
    else if(mark>=60&&mark<65)
        gp=3.00;
    else if(mark>=65&&mark<70)
        gp=3.25;
    else if(mark>=70&&mark<75)
        gp=3.5;
    else if(mark>=75&&mark<80)
        gp=3.75;
    else if(mark>=80)
        gp=4.00;
    return gp;
}
double func_pro(string &s)
{
    double pr;
    string ss;
    ss=s;
    if((s=="1st")||(s=="1ST"))
        pr=2.00;
    else if((s=="2nd")||(s=="2ND"))
        pr=2.25;
    else if((s=="3rd")||(s=="3RD")||(s=="4th")||(s=="4TH"))
        pr=2.5;
    return pr;
}
string lg(double z)
{
    string s;
    if(z>=2.00&&z<2.25)
        s="D";
    else if(z>=2.25&&z<2.5)
        s="C";
    else  if(z>=2.5&&z<2.75)
        s="C+";
    else if(z>=2.75&&z<3.00)
        s="B-";
    else if(z>=3.00&&z<3.25)
        s="B";
    else if(z>=3.25&&z<3.5)
        s="B+";
    else if(z>=3.5&&z<3.75)
        s="A-";
    else if(z>=3.75&&z<4.00)
        s="A";
    else if(z>=4.00)
        s="A+";
    return s;
}
/*
1st
2nd
IT-17003
*/
/*
1st
2nd
IT-17001
*/
/*
1st
2nd
IT-17005
*/

