#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
void accountcreated(void);
void accountdone(void);
void dashboard();
void login(void);
void open(char input[]);
void transfer(char user[]);
void balance(char user[]);
void logout();
void gotoxy(int x, int y){
    COORD c;
    c.X= x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
//user data
struct userdata{
    char firstname[50];
    char lastname[50];
    char fathername[50];
    char mothername[50];
    int day,month,year;
    char email[200];
    int phno[12];
    char acctype[20];
    char username[20];
    char password[20];
};
//to see amount transfer
struct money{
    char usernameto[50];
    char usernamefrom[50];
    long int money1;
};


int main() {
    int choice;
    printf("\n\n");
    char* letters[]={
        "CCCC  H   H  II  LL     DDDD   BBBBB    A\n",
        "C     H H H  II  LL     D   D  B B B   A A\n",
        "CCCC  H   H  II  LLLLL  DDDD   BBBBB  AAAAA\n"
    };
    int k=2;
    int l =30 ;
    for (int i = 0; i < 3; i++) {
        gotoxy(l,k++);
        printf("%s", letters[i]);
    }



    gotoxy(20,6);
    printf("===============================================================\n");
    gotoxy(20,7);
    printf("*");
    gotoxy(35,7);
    printf("WELCOME TO CHILDREN BANK OF INDIA\n\n");
    gotoxy(82,7);
    printf("*");
    gotoxy(20,8);
    printf("===============================================================\n");
    gotoxy(30,12);
   printf("1......NAYA BANK KHATA KHOLNE KE LIYE\n");
   gotoxy(30,14);
    printf("2......PURANE GRAHAK HE TO LOGIN KE LIYE\n");
   gotoxy(30,16);
    printf("3......CHILDBA SE BAHAR NIKALNE HETU\n\n");

printf("APNA VIKALP DALE: ");
scanf("%d",&choice);
if(choice != 1 && choice != 2 && choice != 3){
    printf("GALAT VIKALP");
    exit(0);
}
switch(choice)
{
    case 1:
    system("cls");
    accountcreated();
    break;
    case 2:
    login();
    break;
    case 3:
    exit(0);
    break;
    getch();
}
}
//to create a new account
void accountcreated(void){
    struct userdata first;
    char c;
    FILE *ord;
    ord = fopen("bank.txt","a");
    gotoxy(20,2);
    printf("===============================================================\n");
    gotoxy(20,3);
    printf("*");
    gotoxy(40,3);
    printf("CHILDREN BANK OF INDIA\n\n");
    gotoxy(82,3);
    printf("*");
    gotoxy(20,4);
    printf("===============================================================\n");
    gotoxy(2,6);
printf("KRIPYA APNE KHATE KA VIVRAN BHARE\n\n");
printf("\n");
printf("NAAM KA PEHLA SHABD: ");
scanf("%s",first.firstname);
printf("NAAM KA AKHRI SHABD: ");
scanf("%s",first.lastname);


printf("PITA KA NAAM: ");
scanf(" %[^\n]", first.fathername); 

printf("MATA KA NAAM: ");
scanf(" %[^\n]", first.mothername);



printf("JANAMTITHI\n");
printf("DIN: ");
scanf("%d",&first.day);
printf("MAHINA: ");
scanf("%d",&first.month);
printf("SAAL: ");
scanf("%d",&first.year);
printf("EMAIL: ");
scanf("%s",first.email);
printf("PHONE NUMBER: ");
scanf("%d",&first.phno);
printf("ACCOUNT KA PRAKAR: ");
scanf("%s",first.acctype);
printf("USERNAME: ");
scanf("%s",first.username);
printf("PASSWORD: ");
int i;
 for (i = 0; i < 50; i++) {
        c = getch();
        if (c == 13) {
           break;
        }
        else if(c == 8){
            if(i>0){
            i--;
            printf("\b \b");
            }
        }
        else{
           first.password[i]=c;
            printf("*");
        }
    }
    first.password[i]='\0';
    fwrite(&first,sizeof(first),1,ord);
    fclose(ord);
    accountdone();

}
void accountdone(void){
    system("cls");
    gotoxy(20,2);
    printf("===============================================================\n");
    gotoxy(20,3);
    printf("*");
    gotoxy(40,3);
    printf("CHILDREN BANK OF INDIA\n\n");
    gotoxy(82,3);
    printf("*");
    gotoxy(20,4);
    printf("===============================================================\n");
    printf("\n\n");
    for(int i = 0;i<50;i++){
        if(i==25){
            printf("PROCESSING DATA");
        }
        for(int j = 0;j<2000000;j++){
            j++;
            j--;
        }
        if(i==25){
            printf("PROCESSING DATA");
        }
        printf(".");
        
    }
    printf("\n");
    printf("\n");
    for(int j = 0;j<20000000;j++){
            j++;
            j--;
        }
     for(int i = 0;i<50;i++){
        if(i==25){
            printf("PLEASE WAIT");
            }
        for(int j = 0;j<2000000;j++){
            j++;
            j--;
        }
        printf(".");
    }
    for (int j = 0;j<2000000; j++)
    {
        j++;
        j--;
    }
    gotoxy(30,15);
    printf("ACCOUNT CREATED SUCCESFULLY..........\n\n");
    for (int j = 0;j<2000000; j++)
    {
        j++;
        j--;
    }
    printf("\n\n");
    printf("Enter to login:");
    getch();
    login();
}
void login(void){
    system("cls");
    int i;
    char ch;
    struct userdata first;
char username[50];
char password[50];
 gotoxy(20,2);
    printf("===============================================================\n");
    gotoxy(20,3);
    printf("*");
    gotoxy(40,3);
    printf("CHILDREN BANK OF INDIA\n\n");
    gotoxy(82,3);
    printf("*");
    gotoxy(20,4);
    printf("===============================================================\n");
FILE* ord;
ord = fopen("bank.txt","r");
if(ord == NULL){
    printf("File not found");
}
gotoxy(3,7);
printf("ACCOUNT LOGIN KARIYE");
gotoxy(35,12);
printf("USERNAME: ");
scanf("%s",username);
gotoxy(35,14);
printf("PASSWORD: ");
for (i = 0; i < 50; i++)
{
    ch=getch();
    if(ch==13){
        break;
    }
    else if(ch==8){
        if(i>0){
            i--;
            printf("\b \b");
        }
    }
    else{
            password[i]=ch;
            printf("*");
        }
    
}
password[i]='\0';
int m = 0;
for (int i = 0; i < 100; i++)
{
    for (int j = 0; j < 1000000; j++)
    {
       j++;
       j--;
    }
     gotoxy(++m,20);
    printf(".");
    
}

while(fread(&first,sizeof(first),1,ord)){
    if(strcmp(username,first.username)==0 ){
        dashboard();
        open(username);
    }
}

fclose(ord);
}
void dashboard(){
    system("cls");
     gotoxy(20,2);
    printf("===============================================================\n");
    gotoxy(20,3);
    printf("*");
    gotoxy(40,3);
    printf("CHILDREN BANK OF INDIA\n\n");
    gotoxy(82,3);
    printf("*");
    gotoxy(20,4);
    printf("===============================================================\n");
    gotoxy(2,8);
    printf("DETAILS PRAPT KR RHE RHE");
    for (int j = 0; j < 20; j++)
    {
        for(int i = 0; i < 2000000; i++)
    {
        i++;
        i--;
    }
    printf(".");
    }
    gotoxy(30,12);
    printf("------------LOGIN SUCCESSFULL HO CHUKA E------------\n\n\n\n");
    printf("AGE BADHNE KE LIYE ENTER DABAYE: ");
    getch();
    
  
}
void open(char input[]){
    system("cls");
    int g;
    FILE* odr;
    struct userdata first;
    odr = fopen("bank.txt","r");
     gotoxy(20,2);
    printf("===============================================================\n");
    gotoxy(20,3);
    printf("*");
    gotoxy(40,3);
    printf("CHILDREN BANK OF INDIA\n\n");
    gotoxy(82,3);
    printf("*");
    gotoxy(20,4);
    printf("===============================================================\n");
    while(fread(&first,sizeof(first),1,odr));
    {
        if(strcmp(input,first.username)==0){
            gotoxy(2,6);
            printf("Hello, %s %s",first.firstname,first.lastname);
            gotoxy(65,6);
            printf("ACCOUNT DETAILS");
            gotoxy(65,8);
            printf("NAME: %s %s\n",first.firstname,first.lastname);
            gotoxy(65,10);
            printf("FATHER NAME: %s\n",first.fathername);
            gotoxy(65,12);
            printf("MOTHER NAME: %s\n",first.mothername);
            gotoxy(65,14);
            printf("Date of birth: %d-%d-%d\n",first.day,first.month,first.year);
            gotoxy(65,16);
            printf("EMAIL: %s\n",first.email);
            gotoxy(65,18);
            printf("PHONE NUMBER: %d\n",first.phno);
            gotoxy(65,20);
            printf("ACCOUNT TYPE: %s",first.acctype);
        }
        fclose(odr);
        gotoxy(20,10);
        printf("OPERATIONS KE NUMBER:-");
        gotoxy(20,12);
        printf("1...Check balance");
        gotoxy(20,14);
        printf("2....TRANSFER MONEY");
        gotoxy(20,16);
        printf("3....LOGOUT");
        gotoxy(2,30);
        printf("\n\n");
        printf("\nOPERATION KA NUMBER DALAIYE: ");
        scanf("%d",&g);
        switch(g){
            case 1:
            balance(input);
            break;
            case 2:
            transfer(input);
            break;
            case 3:
            logout();
            login();
            break;
        }
    }
}
void transfer(char user[]) {
    char usernamef[50];
    strcpy(usernamef, user);
    char usernamet[50];
    long int amount;
    FILE* odr;
    FILE* transaction;
    struct userdata first;
    struct money transfera;
    odr = fopen("bank.txt", "r");
    transaction = fopen("transact.txt", "a");
    if (odr == NULL || transaction == NULL) {
        printf("Error: Unable to access necessary files.\n");
        getch();
        return;
    }
    system("cls");
    gotoxy(20, 2);
    printf("===============================================================\n");
    gotoxy(20, 3);
    printf("*");
    gotoxy(40, 3);
    printf("CHILDREN BANK OF INDIA\n\n");
    gotoxy(82, 3);
    printf("*");
    gotoxy(20, 4);
    printf("===============================================================\n");
    gotoxy(5,6);
    printf("Namaskar, %s\n\n", user);

    printf("FROM: %s\n", user);
    gotoxy(30,10);
    printf("JISE BHEJNA HE: ");
    scanf("%s", usernamet);
    int found = 0;
    while (fread(&first, sizeof(first), 1, odr)) {
        if (strcmp(usernamet, first.username) == 0) {
            found = 1;
            break;
        }
    }
    fclose(odr);
    if (!found) {
        printf("Error: Recipient username '%s' not found.\n", usernamet);
        getch();
        exit(0);
    }
    gotoxy(30,10);
    printf("AMOUNT DALIYE: ");
    scanf("%ld", &amount);
    if (amount <= 0) {
        printf("Error: Invalid amount entered.\n");
        getch();
        return;
    }
    strcpy(transfera.usernamefrom, user);
    strcpy(transfera.usernameto, usernamet);
    transfera.money1 = amount;
    fwrite(&transfera, sizeof(transfera), 1, transaction);
    fclose(transaction);
    printf("\n\n");
    printf(".........TRANSFERRING.....please wait....\n");
    gotoxy(2, 32);
    printf("AMOUNT SUCCESSFULLY TRANSFERRED HO CHUKA HE\n");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 2000000; j++) {
            i--; i++;
        }
        printf("*");
    }
    getch();
    open(usernamef); 
}

void balance(char user[]) {
    struct userdata first;
    struct money transfera;
    FILE* transaction;
    long int sumin = 0, sumout = 0, net_balance = 0;
    transaction = fopen("transact.txt", "r");
    if (transaction == NULL) {
        printf("Error: Unable to open transactions file.\n");
        getch();
        return;
    }
    system("cls");
    gotoxy(20, 2);
    printf("===============================================================\n");
    gotoxy(20, 3);
    printf("*");
    gotoxy(40, 3);
    printf("CHILDREN BANK OF INDIA\n\n");
    gotoxy(82, 3);
    printf("*");
    gotoxy(20, 4);
    printf("===============================================================\n");
    gotoxy(5,6);
    int k = 5, l = 8, m = 30, n = 8, f = 60, g = 8;
    gotoxy(30, 6);
    printf("== BALANCE DASHBOARD ==");
    gotoxy(k, l);
    printf("Serial No.");
    gotoxy(m, n);
    printf("Transaction");
    gotoxy(f, g);
    printf("Amount");
    int serial_no = 1;
    while (fread(&transfera, sizeof(transfera), 1, transaction)) {
        if (strcmp(user, transfera.usernamefrom) == 0) {
            gotoxy(k, ++l);
            printf("%d", serial_no++);
            gotoxy(m, ++n);
            printf("To: %s", transfera.usernameto);
            gotoxy(f, ++g);
            printf("- %ld", transfera.money1);
            sumout += transfera.money1;
        } else if (strcmp(user, transfera.usernameto) == 0) {
            gotoxy(k, ++l);
            printf("%d", serial_no++);
            gotoxy(m, ++n);
            printf("From: %s", transfera.usernamefrom);
            gotoxy(f, ++g);
            printf("+ %ld", transfera.money1);
            sumin += transfera.money1;
        }
    }

    fclose(transaction);
    net_balance = sumin - sumout;
    gotoxy(80, 18);
    printf("TOTAL AMOUNT BHEJA: %ld", sumout);
    gotoxy(80, 20);
    printf("TOTAL Amount MILA: %ld", sumin);
    gotoxy(80, 22);
    printf("NET BALANCE: %ld", net_balance);

    getch();
    open(user); // Return to user's dashboard
}

void logout(){
    system("cls");
     gotoxy(20, 2);
    printf("===============================================================\n");
    gotoxy(20, 3);
    printf("*");
    gotoxy(40, 3);
    printf("CHILDREN BANK OF INDIA\n\n");
    gotoxy(82, 3);
    printf("*");
    gotoxy(20, 4);
    printf("===============================================================\n");
    gotoxy(5,6);
    printf("\n\n\n");
    printf("BAHAR NIKAL RHE HE\n\n\n");
    for (int i = 0; i < 2000000; i++)
    {
    i++;
    i--;
    }
    
    printf("CHOLDBA SE BAHAR NIKAL CHUKE HE");
    getch();
    login();
}