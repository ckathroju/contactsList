#ifndef contact_new
#define contact_new
int editadd(char *);
char * sort1(int n);
void sortFile();
int mainline();
void add1();
void add();
int reccount();
int deletedata( char *searchname);
char *getInput();
void sortFile();
int editadd2(char *lastname); 
int isPhoneNum(char *phoneNum);
void dispdata(char *lastname);
void showdata();
void maindisp();
struct contact {
   unsigned long phone_number;
   long first_name_posn;
   long last_name_posn;
   long company_name_posn;
   long email_posn;
   long next;
};
#endif
