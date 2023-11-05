#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Structure
typedef struct mynode {
char name[20];
char gen[6];
int age;
struct mynode* link;
} Node;

Node* start = NULL;

// Declaring Function Used
// In This Program
void heading();
void details();
void inter();
void bangla();
void receipt();

// Global variables
int k, amount;
char type[60], place[30], date[20];

// Driver Code
void main()
{
int a;

// Calling heading() function
heading();

// Taking Choice From User
printf("\t\t\t\t1. International "
"Tour Packages\n");
printf("\t\t\t\t2. Bangladeshi Tour Packages\n");
printf("\t\t\t\tEnter Choice: ");
scanf("%d", &a);
switch (a) {
// Calling inter() function
case 1:
inter();
break;

// Calling india() function
case 2:
bangla();
break;

default:
printf("Enter Right Choice...");
break;
}

// Calling details() function
details();

// Calling receipt() function
receipt();
}

// Function To Take Package
// Choice From India
void bangla()
{
int a;

// Clearing Screen
system("cls");

// Calling heading() function
heading();
strcpy(type, "Bangladesh Tour Package");
printf("\t\t\t\t1. chittagong Tour Packages "
"6 Days 7 Nights (7000/-)\n");
printf("\t\t\t\t2. sylhet Tour Packages "
"5 Days 4 Nights (6000/-)\n");
printf("\t\t\t\t3. potuakhali Tour Packages "
"11 Days 10 Nights (10,000/-)\n");
printf("\t\t\t\tEnter Choice: ");
scanf("%d", &a);
if (a == 1) {
strcpy(place, "Chittagong Tour");
amount = 7000;
}
else if (a == 2) {
strcpy(place, "Sylhet Tour");
amount = 6000;
}
else if (a == 3) {
strcpy(place, "Potuakhali Tour");
amount = 10000;
}
else
printf("Enter Correct Choice...");
}

// Function To Take Package Choice
// From International
void inter()
{
int a;

// Clearing Screen
system("cls");

// Calling heading() function
heading();
strcpy(type, "International Tour Package");
printf("\t\t\t\t1. England Tour Packages "
"6 Days 7 Nights (70,000/-)\n");
printf("\t\t\t\t2. Thailand Tour Packages "
"5 Days 4 Nights (90,000/-)\n");
printf("\t\t\t\t3. Switzerland Packages "
"12 Days 11 Nights (2,00,000/-)\n");
printf("\t\t\t\tEnter Choice: ");
scanf("%d", &a);
if (a == 1) {
strcpy(place, "England Tour");
amount = 70000;
}
else if (a == 2) {
strcpy(place, "Thailand Tour");
amount = 90000;
}
else if (a == 3) {
strcpy(place, "Switzerland Tour");
amount = 200000;
}
else
printf("Enter Correct Choice...");
}

// Function To Take Passenger Details
void details()
{
int i, a;
char val[20], gen[6];

// Clearing Screen
system("cls");

// Calling heading() function
heading();
printf("\t\t\t\tEnter Number Of: "
"Passengers: ");
scanf("%d", &k);
printf("\t\t\t\tEnter Date: "
"(DD/MM/YY): ");
fflush(stdin);
gets(date);
for (i = 1; i <= k; i++) {
system("cls");
heading();
printf("\t\t\t\tEnter The %dth "
"Passenger Name: ",
i);
fflush(stdin);
gets(val);
printf("\t\t\t\tEnter The %dth "
"Passenger Gender: ",
i);
fflush(stdin);
gets(gen);
printf("\t\t\t\tEnter The %dth "
"Passenger Age: ",
i);
fflush(stdin);
scanf("%d", &a);

// Calling add_node() function
add_node(val, gen, a);
}
}

// Function to add details in
// node for each passengers
void add_node(char lol[20],
char der[6], int b)
{
Node *newptr = NULL, *ptr;
newptr = (Node*)malloc(sizeof(Node));
strcpy(newptr->name, lol);
strcpy(newptr->gen, der);
newptr->age = b;
newptr->link = NULL;
if (start == NULL)
start = newptr;
else {
ptr = start;
while (ptr->link != NULL)
ptr = ptr->link;
ptr->link = newptr;
}
}

// Function For Printing Receipt
void receipt()
{
int i, b;
Node* ptr = start;
system("cls");
heading();
printf("\n\t\t\t\t**Take Screenshot "
"For Further Use**\n");
for (i = 1; i <= k; i++) {
printf("\t\t\t\t%dst Passenger "
"Name: ",
i);
puts(ptr->name);
printf("\t\t\t\t%dst Passenger "
"Gender: ",
i);
puts(ptr->gen);
printf("\t\t\t\t%dst Passenger "
"Age: %d\n\n",
i, ptr->age);
ptr = ptr->link;
}
printf("\t\t\t\tSelected Type: ");
puts(type);
printf("\t\t\t\tPackage: ");
puts(place);
printf("\t\t\t\tDate: ");
puts(date);
b = amount * k;
printf("\t\t\t\tTotal Amount: %d", b);
printf("\n\t\t\t\t**Thank You For "
"registration**");
}

// Function For Printing Heading
// Of Portal
void heading()
{
printf("\t\t\t\t***Tourism Package "
"Management System***\n");
printf("\t\t\t***Vaccination Certificate "
"Is Necessary For Travel Purpose***\n\n");
}


