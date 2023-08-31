#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
/* structure to store employee salary details */ 
struct employee {
int empID; 
char name[32];
int basic, Hra, Da, Ma; 
int pf, insurance;
float gross, net;
};
/* prints payslip for the requested employee */ 
void printSalary(struct employee E1) { 
printf("Salary Slip of %s:\n", E1.name); 
printf("Employee ID: %d\n", E1.empID); 
printf("Basic Salary: %d\n", E1.basic); 
printf("House Rent Allowance: %d\n", E1.Hra); 
printf("Dearness Allowance: %d\n", E1.Da); 
printf("Medical Allowance: %d\n", E1.Ma); 
printf("Gross Salary: %.2f Rupees\n", E1.gross); 
printf("\nDeductions: \n");
printf("Provident fund: %d\n", E1.pf);
printf("Insurance: %d\n", E1.insurance); 
printf("\nNet Salary: %.2f Rupees\n\n", E1.net);
KGISL INSTITUTE OF TECHNOLOGY 
20IT54
711720205053
THEJASKUMAR.B
return;
}
int main() {
int i, ch, Num, flag, empID; 
struct employee *E1;
printf("Enter the Number of Employees:"); 
scanf("%d", &Num);
E1 = (struct employee *)malloc(sizeof(struct employee) * Num); 
printf("Enter your input for every employee:\n");
for (i = 0; i <Num; i++) { 
printf("Employee ID:"); 
scanf("%d", &(E1[i].empID)); 
getchar();
printf("Employee Name:"); 
fgets(E1[i].name, 32, stdin); 
E1[i].name[strlen(E1[i].name) - 1] = '\0'; 
printf("Basic Salary, HRA:");
scanf("%d%d", &(E1[i].basic), &(E1[i].Hra)); 
printf("DA, Medical Allowance:"); 
scanf("%d%d", &(E1[i].Da), &(E1[i].Ma)); 
printf("PF and Insurance:");
scanf("%d%d", &(E1[i].pf), &(E1[i].insurance)); 
printf("\n");
}
/* gross and net salary calculation */
KGISL INSTITUTE OF TECHNOLOGY 
20IT54
711720205053
THEJASKUMAR.B
for (i = 0; i <Num; i++) { 
E1[i].gross = E1[i].basic + 
(E1[i].Hra * E1[i].basic) / 100 + 
(E1[i].Da * E1[i].basic) / 100 + 
(E1[i].Ma * E1[i].basic) / 100;
E1[i].net = E1[i].gross - (E1[i].pf + E1[i].insurance);
}
while (1) {
printf("Enter employee ID to get payslip:"); 
scanf("%d", &empID);
flag = 0;
for (i = 0; i <Num; i++) {
if (empID == E1[i].empID) { 
printSalary(E1[i]);
flag = 1;
}
}
if (!flag) {
printf("No Record Found!!\n");
}
printf("Do You Want To Continue(1/0):"); 
scanf("%d", &ch);
if (!ch) { 
break;
}
KGISL INSTITUTE OF TECHNOLOGY 
20IT54
711720205053
THEJASKUMAR.B
} return 0;
}
