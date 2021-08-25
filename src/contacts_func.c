#include "../includes/contacts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


char *getInput()
{
  char *input;
  int ch;
  size_t i;

  input = malloc(1);
  i = 0;

  while((ch = getchar()) != '\n' && ch != EOF) {
    input[i++] = ch;
    input = realloc(input,i + 1);
  }

  input[i] = '\0';

  return input;
}

int isPhoneNum(char *phoneNum)
{
  int i;

  if (strlen(phoneNum) == 0) {
    return 1;
  }
  for (i=0; i<strlen(phoneNum); i++) {
    if (!isdigit(phoneNum[i])) {
      return 1;
    }
  }
  /*if(((strlen(phoneNum))!=7)||((strlen(phoneNum))!=10))
  {


  return 1;}*/
  return 0;
}


void dispdata(char *lastname)
{
char *filename="in1.bin";
FILE *file=fopen(filename,"rb");
rewind(file);
struct contact c2;
char  c3[100],c4[100],c5[100],c6[100];
int found=0;
while(fread(&c2,sizeof(struct contact),1,file))
{

  fseek(file,c2.first_name_posn,SEEK_SET);
  fread(c3,c2.next-c2.first_name_posn,1,file);

  fseek(file,c2.last_name_posn,SEEK_SET);
  fread(c4,c2.email_posn-c2.last_name_posn,1,file);

  fseek(file,c2.email_posn,SEEK_SET);
  fread(c5,c2.next-c2.email_posn,1,file);

  fseek(file,c2.company_name_posn,SEEK_SET);
  fread(c6,c2.next-c2.company_name_posn,1,file);

  fseek(file,c2.next,SEEK_SET);


  long int phone;
  if((strlen(c4))!=0)
  {
    if(strcmp(lastname,c4)==0)
    { phone=c2.phone_number;
      printf("Contact Information-Display\n");
      printf("First Name:%s\n",c3);
      printf("Last Name:%s\n",c4);

      printf("Company Name:%s\n",c6);
      printf("Phone Number:%ld\n",phone);
      printf("Email:%s\n",c5);
      found=1;
      printf("Available Actions for Contact Display\n");
      printf("___________________________________________________________________\n");
      printf("    R    |Return to the Full Contacts List interface               |\n");
      printf("    E    |Edit this contact                                        |\n");
      printf("    D    |Delete this contact and return to Full Contacts List     |\n");
      printf("------------------------------------------------------------------\n");
      printf("Action:");



      /*printf("return to full contactlist----R\n");
      printf("Edit this-----E\n");
      printf("delete this-------D\n");*/
      fflush(stdout);
      char ch[5];
      scanf("%s",ch);
      printf("\n");
      if ((strcmp(ch,"E")==0))
      {
        editadd(c4);
        maindisp();
        mainline();
      }

      else if ((strcmp(ch,"R")==0))
      {
        maindisp();
        mainline();
      }
      else if ((strcmp(ch,"D")==0))
      {
        deletedata(c4);
        maindisp();
        mainline();

      }

    }
  }
  else
  {
    {
      if(strcmp(lastname,c6)==0)
      { phone=c2.phone_number;
        printf("Contact Information-Display\n");
        printf("First Name:%s\n",c3);
        printf("Last Name:%s\n",c4);

        printf("Company Name:%s\n",c6);
        printf("Phone Number:%lu\n",c2.phone_number);
        printf("Email:%s\n",c5);
        found=1;
        printf("Available Actions for Contact Display\n");
        printf("___________________________________________________________________\n");
        printf("    R   |Return to Full Contact List interface                    |\n");
        printf("    E   |Edit this contact                                        |\n");
        printf("    D   |Delete this contact and return to Full Contact List      |\n");
        printf("------------------------------------------------------------------\n");
        printf("Action:");



        /*printf("return to full contactlist----R\n");
        printf("Edit this-----E\n");
        printf("delete this-------D\n");*/
        fflush(stdout);
        char ch[5];
        scanf("%s",ch);
        printf("\n");
        if ((strcmp(ch,"E")==0))
        {
          editadd(c6);
          maindisp();
          mainline();
        }

        else if ((strcmp(ch,"R")==0))
        {
          maindisp();
          mainline();
        }
        else if ((strcmp(ch,"D")==0))
        {
          deletedata(c6);
          maindisp();
          mainline();

        }

      }
    }






  }

}

if(found==0)
printf("no details found");


}

void showdata()
{
  char *filename="in1.bin";
  FILE *file=fopen(filename,"rb");
  rewind(file);
  struct contact c2;
  char  c3[100],c4[100],c5[100],c6[100];

  while(fread(&c2,sizeof(struct contact),1,file))
  {

    fseek(file,c2.first_name_posn,SEEK_SET);
    fread(c3,c2.next-c2.first_name_posn,1,file);

    fseek(file,c2.last_name_posn,SEEK_SET);
    fread(c4,c2.email_posn-c2.last_name_posn,1,file);

    fseek(file,c2.email_posn,SEEK_SET);
    fread(c5,c2.next-c2.email_posn,1,file);

    fseek(file,c2.company_name_posn,SEEK_SET);
    fread(c6,c2.next-c2.company_name_posn,1,file);

    fseek(file,c2.next,SEEK_SET);


    long int phone;
    phone=c2.phone_number;

    printf("First Name:%s\n",c3);
    printf("Last name:%s\n",c4);

    printf("Company Name:%s\n",c6);
    printf("Phone Number:%lu\n",phone);
    printf("Email:%s\n",c5);




  }




}

void  maindisp()
{
  char *filename="in1.bin";
  FILE *file=fopen(filename,"rb");

  struct contact data1;
  size_t itemSize = sizeof(struct contact );


  char  c3[100][100],c4[100][100],c5[100][100],c6[100][100];
  rewind(file);
  char lastname[100][100];
  char companyname[100][100];
  int l=0;

  while(fread(&data1, itemSize, 1, file))
  {
    fseek(file,data1.first_name_posn,SEEK_SET);
    fread(c3[l],data1.next-data1.first_name_posn,1,file);
    fseek(file,data1.last_name_posn,SEEK_SET);
    fread(c4[l],data1.email_posn-data1.last_name_posn,1,file);


    fseek(file,data1.email_posn,SEEK_SET);
    fread(c5[l],data1.next-data1.email_posn,1,file);

    fseek(file,data1.company_name_posn,SEEK_SET);
    fread(c6[l],data1.next-data1.company_name_posn,1,file);

    fseek(file,data1.next,SEEK_SET);

    strcpy(lastname[l],c4[l]);
    strcpy(companyname[l],c6[l]);


    fseek(file,data1.next,SEEK_SET);
    l++;
  }
  char temp[100];
  int last_var1=0;

  int last_var2=0;

  int i;
  for ( i = 0; i < l ; i++)

  {  if ((strlen(lastname[i]))==0)
    {last_var1=1;
    }
    else
    {last_var1=0;
    }

    int j;
    for (j = i + 1; j < l; j++)

    {     if ((strlen(lastname[j]))==0)
      {last_var2=1;
      }
      else
      {last_var2=0;
        ;
      }

      if(last_var1==0 && last_var2==0)
      { if (strcmp(lastname[i], lastname[j]) > 0)


        {

          strcpy(temp, lastname[i]);

          strcpy(lastname[i], lastname[j]);

          strcpy(lastname[j], temp);

        }
      }
      else if(last_var1==0 && last_var2==1)
      {
        if (strcmp(lastname[i], companyname[j]) > 0)

        {

          strcpy(temp, lastname[i]);

          strcpy(lastname[i], companyname[j]);

          strcpy(companyname[j], temp);

        }


      }
      else if(last_var1==1 && last_var2==0)
      {
        if (strcmp(companyname[i], lastname[j]) > 0)

        {

          strcpy(temp, companyname[i]);

          strcpy(companyname[i], lastname[j]);

          strcpy(lastname[j], temp);

        }


      }
      else if(last_var1==1 && last_var2==1)
      {
        if (strcmp(companyname[i], companyname[j]) > 0)

        {

          strcpy(temp, companyname[i]);

          strcpy(companyname[i], companyname[j]);

          strcpy(companyname[j], temp);

        }


      }

    }

  }

  printf("Number of Contacts = %d\n",l);
  int z;
  for(z=0;z<l;z++)
  {if((strlen(lastname[z]))==0)
    printf("%d.%s\n",z+1,companyname[z]);
    else
    printf("%d.%s\n",z+1,lastname[z]);
  }

}
int reccount()
{


  struct contact data1;
  size_t itemSize = sizeof(struct contact );


  char *filename="in1.bin";
  FILE *file=fopen(filename,"rb");

  char  c3[100][100],c4[100][100],c5[100][100],c6[100][100];
  rewind(file);
  char lastname[100][100];
  char companyname[100][100];
  int l=0;

  while(fread(&data1, itemSize, 1, file))
  {
    fseek(file,data1.first_name_posn,SEEK_SET);
    fread(c3[l],data1.next-data1.first_name_posn,1,file);
    fseek(file,data1.last_name_posn,SEEK_SET);
    fread(c4[l],data1.email_posn-data1.last_name_posn,1,file);


    fseek(file,data1.email_posn,SEEK_SET);
    fread(c5[l],data1.next-data1.email_posn,1,file);

    fseek(file,data1.company_name_posn,SEEK_SET);
    fread(c6[l],data1.next-data1.company_name_posn,1,file);

    fseek(file,data1.next,SEEK_SET);

    strcpy(lastname[l],c4[l]);
    strcpy(companyname[l],c6[l]);


    fseek(file,data1.next,SEEK_SET);

    l++; }
    return l;

  }
  char * sort1(int n)
  {


    struct contact data1;
    size_t itemSize = sizeof(struct contact );



    char  c3[100][100],c4[100][100],c5[100][100],c6[100][100];
    char *filename="in1.bin";
    FILE *file=fopen(filename,"rb");
    rewind(file);
    static char lastname[100][100];
    static char companyname[100][100];
    int l=0;

    while(fread(&data1, itemSize, 1, file))
    {
      fseek(file,data1.first_name_posn,SEEK_SET);
      fread(c3[l],data1.next-data1.first_name_posn,1,file);
      fseek(file,data1.last_name_posn,SEEK_SET);
      fread(c4[l],data1.email_posn-data1.last_name_posn,1,file);


      fseek(file,data1.email_posn,SEEK_SET);
      fread(c5[l],data1.next-data1.email_posn,1,file);

      fseek(file,data1.company_name_posn,SEEK_SET);
      fread(c6[l],data1.next-data1.company_name_posn,1,file);

      fseek(file,data1.next,SEEK_SET);

      strcpy(lastname[l],c4[l]);
      strcpy(companyname[l],c6[l]);


      fseek(file,data1.next,SEEK_SET);
      l++;
    }
    static char str[100][100];
    static char temp[100];
    int last_var1=0;

    int last_var2=0;

    int i;
    for ( i = 0; i < l ; i++)

    {  if ((strlen(lastname[i]))==0)
      { last_var1=1;

      }
      else
      {
        last_var1=0;}
        int j;
        for ( j = i + 1; j < l; j++)

        {     if ((strlen(lastname[j]))==0)
          { last_var2=1;

          }
          else
          {
            last_var2=0;
          }
          if(last_var1==0 && last_var2==0)
          { if (strcmp(lastname[i], lastname[j]) > 0)

            {

              strcpy(temp, lastname[i]);

              strcpy(lastname[i], lastname[j]);

              strcpy(lastname[j], temp);

            }
          }
          else if(last_var1==0 && last_var2==1)
          {
            if (strcmp(lastname[i], companyname[j]) > 0)

            {

              strcpy(temp, lastname[i]);

              strcpy(lastname[i], companyname[j]);

              strcpy(companyname[j], temp);

            }


          }
          else if(last_var1==1 && last_var2==0)
          {
            if (strcmp(companyname[i], lastname[j]) > 0)

            {

              strcpy(temp, companyname[i]);

              strcpy(companyname[i], lastname[j]);

              strcpy(lastname[j], temp);

            }


          }
          else if(last_var1==1 && last_var2==1)
          {
            if (strcmp(companyname[i], companyname[j]) > 0)

            {

              strcpy(temp, companyname[i]);

              strcpy(companyname[i], companyname[j]);

              strcpy(companyname[j], temp);

            }


          }
        }

      }



      int z;
      for(z=0;z<l;z++)
      {	if(z==n)
        {
          if((strlen(lastname[z]))!=0)
          {strcpy(str[z],lastname[z]);
            return str[z];
          }
          else
          {
            strcpy(str[z],companyname[z]);
            return str[z];

          }
        }

      }
      return 0;
    }

    void sortFile() {




      struct contact data1,data2;
      size_t itemSize = sizeof(struct contact );
      int long position;
      int flag = 1;

      char  c3[100],c4[100],c5[100],c6[100],c33[100],c44[100],c55[100],c66[100];
      char *filename="in1.bin";
      FILE *file=fopen(filename,"rb");
      rewind(file);
      static int k=0;
      while(flag) {k++;
        flag = 0;
        int inter=0;
        fread(&data1, itemSize, 1, file);

        fseek(file,data1.first_name_posn,SEEK_SET);
        fread(c3,data1.next-data1.first_name_posn,1,file);
        fseek(file,data1.last_name_posn,SEEK_SET);
        fread(c4,data1.email_posn-data1.last_name_posn,1,file);


        fseek(file,data1.email_posn,SEEK_SET);
        fread(c5,data1.next-data1.email_posn,1,file);

        fseek(file,data1.company_name_posn,SEEK_SET);
        fread(c6,data1.next-data1.company_name_posn,1,file);

        fseek(file,data1.next,SEEK_SET);
        fread(&data2, itemSize, 1, file);
        fseek(file,data2.first_name_posn,SEEK_SET);
        fread(c33,data2.next-data2.first_name_posn,1,file);

        fseek(file,data2.last_name_posn,SEEK_SET);
        fread(c44,data2.email_posn-data2.last_name_posn,1,file);

        fseek(file,data2.email_posn,SEEK_SET);
        fread(c55,data2.next-data2.email_posn,1,file);

        fseek(file,data2.company_name_posn,SEEK_SET);
        fread(c66,data2.next-data2.company_name_posn,1,file);

        fseek(file,data2.next,SEEK_SET);



        while (!feof(file)) {

          if (strcmp(c33,c3)<0) {
            int calc=(itemSize*-2)-data1.next+data1.first_name_posn-data2.next+data2.first_name_posn;
            fseek(file,calc, SEEK_CUR);
            printf("%ld", ftell(file));
            int long temp=data2.next;
            data2.next=data2.next-data1.next-sizeof(struct contact);
            data1.next=temp;

            data2.first_name_posn = ftell(file)+sizeof(struct contact);
            data2.last_name_posn = data2.first_name_posn + strlen(c33) + 1;
            data2.company_name_posn = data2.last_name_posn + strlen(c44) + 1;
            data2.email_posn = data2.company_name_posn + strlen(c66) + 1;
            data2.next = data2.email_posn + strlen(c55) + 1;

            fwrite(&data2, sizeof(struct contact),1,file);
            fwrite(c33,1,strlen(c33) + 1,file);
            fwrite(c44,1,strlen(c44) + 1,file);
            fwrite(c66,1,strlen(c66) + 1,file);
            fwrite(c55,1,strlen(c55) + 1,file);
            data1.first_name_posn = sizeof(struct contact)+data2.next;
            data1.last_name_posn = data1.first_name_posn + strlen(c3) + 1;
            data1.company_name_posn = data1.last_name_posn + strlen(c4) + 1;
            data1.email_posn = data1.company_name_posn + strlen(c6) + 1;
            data1.next = data1.email_posn + strlen(c5) + 1;
            fwrite(&data1, sizeof(struct contact),1,file);

            fwrite(c3,1,strlen(c3) + 1,file);
            fwrite(c4,1,strlen(c4) + 1,file);
            fwrite(c6,1,strlen(c6) + 1,file);
            fwrite(c5,1,strlen(c5) + 1,file);
            position=data1.next;
            inter=1;
            flag = 1;
          } else {
            if(inter==1)
            {

              data1.first_name_posn = sizeof(struct contact)+position;
              data1.phone_number=data2.phone_number;
              strcpy(c3,c33);
              strcpy(c4,c44);
              strcpy(c5,c55);
              strcpy(c6,c66);
              data1.last_name_posn = data1.first_name_posn + strlen(c3) + 1;
              data1.company_name_posn = data1.last_name_posn + strlen(c4) + 1;
              data1.email_posn = data1.company_name_posn + strlen(c6) + 1;
              data1.next = data1.email_posn + strlen(c5) + 1;
              fseek(file,-sizeof(struct contact)-strlen(c33)-strlen(c44)-strlen(c55)-strlen(c66)-4,SEEK_CUR);
              fwrite(&data1, sizeof(struct contact),1,file);

              fwrite(c3,1,strlen(c3) + 1,file);
              fwrite(c4,1,strlen(c4) + 1,file);
              fwrite(c6,1,strlen(c6) + 1,file);
              fwrite(c5,1,strlen(c5) + 1,file);}
            }
            if(k>1)
            {
              data1.first_name_posn = data2.first_name_posn;
              data1.phone_number=data2.phone_number;
              strcpy(c3,c33);
              strcpy(c4,c44);
              strcpy(c5,c55);
              strcpy(c6,c66);
              data1.last_name_posn = data1.first_name_posn + strlen(c3) + 1;
              data1.company_name_posn = data1.last_name_posn + strlen(c4) + 1;
              data1.email_posn = data1.company_name_posn + strlen(c6) + 1;
              data1.next = data1.email_posn + strlen(c5) + 1;



            }
            fread(&data2, itemSize, 1, file);

            if(!feof(file))
            {
              fseek(file,data2.first_name_posn,SEEK_SET);
              fread(c33,data2.next-data2.first_name_posn,1,file);

              fseek(file,data2.last_name_posn,SEEK_SET);
              fread(c44,data2.email_posn-data2.last_name_posn,1,file);

              fseek(file,data2.email_posn,SEEK_SET);
              fread(c55,data2.next-data2.email_posn,1,file);

              fseek(file,data2.company_name_posn,SEEK_SET);
              fread(c66,data2.next-data2.company_name_posn,1,file);
              fseek(file,data2.next,SEEK_SET);
            }
          }
          if (flag) { rewind(file); }
        }

      }

      int deletedata( char *searchname) {

        FILE *fp_tmp;
        char  c33[100],c44[100],c55[100],c66[100];
        int found=0;
        struct contact data2;

        int calc1=0;
        char *filename="in1.bin";
        FILE *file=fopen(filename,"rb");
        rewind(file);


        if (!file) {
          printf("Unable to open file %s", filename);
          return -1;
        }
        fp_tmp=fopen("tmp.bin", "wb");
        if (!fp_tmp) {
          printf("Unable to open file temp file.");
          return -1;
        }

        while (fread(&data2,sizeof(struct contact),1,file) ) {
          fseek(file,data2.first_name_posn,SEEK_SET);
          fread(c33,data2.next-data2.first_name_posn,1,file);

          fseek(file,data2.last_name_posn,SEEK_SET);
          fread(c44,data2.company_name_posn-data2.last_name_posn,1,file);
          c44[data2.company_name_posn-data2.last_name_posn]='\0';
          fseek(file,data2.email_posn,SEEK_SET);
          fread(c55,data2.next-data2.email_posn,1,file);

          fseek(file,data2.company_name_posn,SEEK_SET);
          fread(c66,data2.next-data2.company_name_posn,1,file);
          fseek(file,data2.next,0);

          if((strlen(c44))!=0)
          {
            if (strcmp (searchname,c44) == 0) {
              printf("A record with requested name found and deleted.\n\n");
              found=1;

              calc1=data2.next-(strlen(c66)+strlen(c55)+strlen(c44)+strlen(c33)+sizeof(struct contact)+4);

            }
            else {
              if (found==1)
              {
                data2.first_name_posn=calc1+sizeof(struct contact);

                data2.last_name_posn=data2.first_name_posn+strlen(c33)+1;
                data2.company_name_posn=data2.last_name_posn+strlen(c44)+1;
                data2.email_posn=data2.company_name_posn+strlen(c66)+1;
                data2.next=data2.email_posn+strlen(c55)+1;
                calc1=data2.next;
              }
              else
              {

              }
              fwrite(&data2, sizeof(struct contact), 1, fp_tmp);

              fwrite(c33,1,strlen(c33) + 1,fp_tmp);
              fwrite(c44,1,strlen(c44) + 1,fp_tmp);
              fwrite(c66,1,strlen(c66) + 1,fp_tmp);
              fwrite(c55,1,strlen(c55) + 1,fp_tmp);
            }
          }
          else
          {
            if (strcmp (searchname,c66) == 0) {
              printf("A record with requested name found and deleted.\n\n");
              found=1;

              calc1=data2.next-(strlen(c66)+strlen(c55)+strlen(c44)+strlen(c33)+sizeof(struct contact)+4);

            }
            else {
              if (found==1)
              {
                data2.first_name_posn=calc1+sizeof(struct contact);
                data2.last_name_posn=data2.first_name_posn+strlen(c33)+1;
                data2.company_name_posn=data2.last_name_posn+strlen(c44)+1;
                data2.email_posn=data2.company_name_posn+strlen(c66)+1;
                data2.next=data2.email_posn+strlen(c55)+1;
                calc1=data2.next;
              }
              else
              {

              }
              fwrite(&data2, sizeof(struct contact), 1, fp_tmp);

              fwrite(c33,1,strlen(c33) + 1,fp_tmp);
              fwrite(c44,1,strlen(c44) + 1,fp_tmp);
              fwrite(c66,1,strlen(c66) + 1,fp_tmp);
              fwrite(c55,1,strlen(c55) + 1,fp_tmp);
            }
          }




        }
        if (! found) {
          printf("No record(s) found with the requested name: %s\n\n", searchname);
        }

        fclose(file);
        fclose(fp_tmp);

        remove(filename);
        rename("tmp.bin", filename);
        int file_exists;


        file=fopen(filename,"rb");
        if (file==NULL) file_exists=0;
        else {file_exists=1; fclose(file);}



        if (file_exists==1)
        {
          printf("file exists!\n");
          file=fopen(filename,"ab+");

        }
        else
        {
          printf("file does not exist!\n");

          file=fopen(filename,"wb+");

        }



        if (file!=NULL)
        {
          printf ("file opened succesfully!\n");

        }

        return 0;
      }
      void add()
      {struct contact *data;
        int g=0;

        char *firstName;
        char *lastName;
        char *companyName;


        data = malloc(sizeof(struct contact));

        printf("New Contact\n");
        printf("First Name: ");
        firstName = getInput();

        printf("Last Name: ");
        lastName = getInput();


        printf("Company Name: ");
        companyName = getInput();


        if (((strlen(lastName))==0) && (((strlen(companyName))==0)))
        {
          do{
            printf("Company Name: ");
            companyName = getInput();
          }while((strlen(companyName))==0);

        }
        char * phoneNum=malloc(sizeof(char));
        int ii;
        char *emailAdress=malloc(sizeof(char));
        do {          ii=0;

          printf("Phone Number (enter only numbers): ");
          scanf("%s",phoneNum);
          if((strlen(phoneNum))==7)
          ii++;
          if((strlen(phoneNum))==10)
          ii++;
        } while((isPhoneNum(phoneNum) != 0)||(ii<1));
        data->phone_number = strtol(phoneNum,&phoneNum,10);
        int valid=0;
        do {
          printf("Email: ");
          scanf("%s",emailAdress);

          int i=0,count1=0,count2=0;
          int d=0,l=0;

          while(emailAdress[i])
          {
            if(emailAdress[i]=='@')
            {count1++;
              d=i;
            }
            if(emailAdress[i]=='.')
            {
              count2++;
              l=i;
            }
            i++;
          }
          if((count1>0&&count1<2)&&(count2>0&&count2<2)&&l>d)
          valid=1;

          else
          {
            valid=0;
            /*printf("enter valid email id\n");*/
          }
        } while((strlen(emailAdress) <= 0)||valid==0);
        printf("Available Actions for New Contact\n");
        printf("___________________________________________________________________\n");
        printf("    R   |Return to the Full Contact List interface                 |\n");
        printf("    S   |Save this contact and return to Full Contacts List        |\n");
        printf("-------------------------------------------------------------------\n");

        char ch3[2];
        do{
          printf("Action:");


          scanf("%s",ch3);
          if((!strcmp(ch3,"S"))||(!strcmp(ch3,"R")))
          break;
        }while(1);
        printf("\n");
        char *filename="in1.bin";
        FILE *file=fopen(filename,"ab+");
        struct contact c5;
        c5.next=0;
        long q=0;
        if(g==0)
        {
          rewind(file);

          while(fread(&c5,sizeof(struct contact),1,file))
          {
            fseek(file,c5.next,SEEK_SET);
            q=c5.next;
          }
          g++;
          data->next=q;
        }


        data->first_name_posn = sizeof(struct contact)+data->next;
        data->last_name_posn = data->first_name_posn + strlen(firstName) + 1;
        data->company_name_posn = data->last_name_posn + strlen(lastName) + 1;
        data->email_posn = data->company_name_posn + strlen(companyName) + 1;
        data->next = data->email_posn + strlen(emailAdress) + 1;

        if(strcmp(ch3,"S")==0)
        {
          fwrite(data, sizeof(struct contact),1,file);
          fwrite(firstName,1,strlen(firstName) + 1,file);
          fwrite(lastName,1,strlen(lastName) + 1,file);
          fwrite(companyName,1,strlen(companyName) + 1,file);
          fwrite(emailAdress,1,strlen(emailAdress) + 1,file);

        }

        fclose(file);
      }
      void add1()
      {
        char *filename="in1.bin";
        char *firstName;
        char *lastName;
        char *companyName;
        char *phoneNum;
        char *emailAdress;


        FILE *file=fopen(filename,"rb");
        rewind(file);
        FILE *fp_tmp=fopen("tmp5.bin", "wb");
        struct contact *data=malloc(sizeof(struct contact));
        struct contact data1;
        int calc;
        char  c3[100],c4[100],c5[100],c6[100];

        printf("First Name: ");
        firstName = getInput();

        printf("Last Name: ");
        lastName = getInput();

        printf("Company Name: ");
        companyName = getInput();

        if (((strlen(lastName))==0) && (((strlen(companyName))==0)))
        {
          do{
            printf("Company Name: ");
            companyName = getInput();
          }while((strlen(companyName))==0);

        }

        int ii;
        do {          ii=0;

          printf("Phone Number (enter only numbers): ");
          scanf("%s",phoneNum);
          if((strlen(phoneNum))==7)
          ii++;
          if((strlen(phoneNum))==10)
          ii++;
        } while((isPhoneNum(phoneNum) != 0)||(ii<1));
        data1.phone_number = strtol(phoneNum,&phoneNum,10);
        int valid=0;
        do {
          printf("Email: ");
          emailAdress = getInput();
          int i=0,count1=0,count2=0;
          int d=0,l=0;

          while(emailAdress[i])
          {
            if(emailAdress[i]=='@')
            {count1++;
              d=i;
            }
            if(emailAdress[i]=='.')
            {
              count2++;
              l=i;
            }
            i++;
          }
          if((count1>0&&count1<2)&&(count2>0&&count2<2)&&l>d)
          valid=1;

          else
          {
            valid=0;
            /*printf("enter valid email id\n");*/
          }
        } while((strlen(emailAdress) <= 0)||valid==0);
        long int q=0;
        data1.next=0;
        int var_found=0;

        int jam=0;
        while(fread(&data1,sizeof(struct contact),1,file))
        {
          jam++;
          fseek(file,data1.first_name_posn,SEEK_SET);
          fread(c3,data1.next-data1.first_name_posn,1,file);
          fseek(file,data1.last_name_posn,SEEK_SET);
          fread(c4,data1.email_posn-data1.last_name_posn,1,file);


          fseek(file,data1.email_posn,SEEK_SET);
          fread(c5,data1.next-data1.email_posn,1,file);

          fseek(file,data1.company_name_posn,SEEK_SET);
          fread(c6,data1.next-data1.company_name_posn,1,file);

          fseek(file,data1.next,SEEK_SET);

          if(strcmp(firstName,c3)<0&&var_found==0)
          {  calc=-sizeof(struct contact)-strlen(c3)-strlen(c4)-strlen(c5)-strlen(c6)-4;
            q=data1.next+calc;

            data->phone_number = strtol(phoneNum,&phoneNum,10);



            data->first_name_posn = sizeof(struct contact)+q;
            data->last_name_posn = data->first_name_posn + strlen(firstName) + 1;
            data->company_name_posn = data->last_name_posn + strlen(lastName) + 1;
            data->email_posn = data->company_name_posn + strlen(companyName) + 1;
            data->next = data->email_posn + strlen(emailAdress) + 1;
            fwrite(data, sizeof(struct contact),1,fp_tmp);
            fwrite(firstName,1,strlen(firstName) + 1,fp_tmp);
            fwrite(lastName,1,strlen(lastName) + 1,fp_tmp);
            fwrite(companyName,1,strlen(companyName) + 1,fp_tmp);
            fwrite(emailAdress,1,strlen(emailAdress) + 1,fp_tmp);
            data1.first_name_posn=data->next+sizeof(struct contact);
            data1.last_name_posn=data1.first_name_posn+strlen(c3)+1;
            data1.company_name_posn = data1.last_name_posn + strlen(c4) + 1;
            data1.email_posn = data1.company_name_posn + strlen(c6) + 1;
            data1.next = data1.email_posn + strlen(c5) + 1;
            fwrite(&data1, sizeof(struct contact),1,fp_tmp);
            fwrite(c3,1,strlen(c3) + 1,fp_tmp);
            fwrite(c4,1,strlen(c4) + 1,fp_tmp);
            fwrite(c6,1,strlen(c6) + 1,fp_tmp);
            fwrite(c5,1,strlen(c5) + 1,fp_tmp);
            q=data1.next;
            var_found=1;

          }




          else
          {  	if(var_found!=1)
            {
              fwrite(&data1, sizeof(struct contact),1,fp_tmp);

              fwrite(c3,1,strlen(c3) + 1,fp_tmp);
              fwrite(c4,1,strlen(c4) + 1,fp_tmp);
              fwrite(c6,1,strlen(c6) + 1,fp_tmp);
              fwrite(c5,1,strlen(c5) + 1,fp_tmp);
            }
            else
            {
              data1.first_name_posn=q+sizeof(struct contact);
              data1.last_name_posn=data1.first_name_posn+strlen(c3)+1;
              data1.company_name_posn = data1.last_name_posn + strlen(c4) + 1;
              data1.email_posn = data1.company_name_posn + strlen(c6) + 1;
              data1.next = data1.email_posn + strlen(c5) + 1;
              q=data1.next;
              fwrite(&data1, sizeof(struct contact),1,fp_tmp);

              fwrite(c3,1,strlen(c3) + 1,fp_tmp);
              fwrite(c4,1,strlen(c4) + 1,fp_tmp);
              fwrite(c6,1,strlen(c6) + 1,fp_tmp);
              fwrite(c5,1,strlen(c5) + 1,fp_tmp);

            }
          }
        }
        if(jam==0)
        {
          data1.first_name_posn=sizeof(struct contact);
          data1.last_name_posn=data1.first_name_posn+strlen(c3)+1;
          data1.company_name_posn = data1.last_name_posn + strlen(c4) + 1;
          data1.email_posn = data1.company_name_posn + strlen(c6) + 1;
          data1.next = data1.email_posn + strlen(c5) + 1;
          q=data1.next;
          fwrite(&data1, sizeof(struct contact),1,fp_tmp);

          fwrite(c3,1,strlen(c3) + 1,fp_tmp);
          fwrite(c4,1,strlen(c4) + 1,fp_tmp);
          fwrite(c6,1,strlen(c6) + 1,fp_tmp);
          fwrite(c5,1,strlen(c5) + 1,fp_tmp);




        }
        remove(filename);
        rename("tmp5.bin", filename);
        int file_exists;
        filename="in1.bin";

        file=fopen(filename,"rb");
        if (file==NULL) file_exists=0;
        else {file_exists=1; fclose(file);}



        if (file_exists==1)
        {
          printf("file exists!\n");
          file=fopen(filename,"ab+");

        }
        else
        {
          printf("file does not exist!\n");

          file=fopen(filename,"wb+");

        }



        if (file!=NULL)
        {
          printf ("file opened succesfully!\n");

        }

      }


      int editadd2(char *lastname)
      {


        char *filename="in1.bin";
        FILE *file=fopen(filename,"rb");
        char  c33[100],c44[100],c55[100],c66[100];
        struct contact data2;
        int calc3=0;
        int  found = 0;


        rewind(file);
        FILE *fp_tmp=fopen("tmp1.bin", "wb");
        if (!fp_tmp) {
          printf("Unable to open file temp file.");
          return -1;
        }
        while ((fread(&data2, sizeof(data2), 1, file)) > 0)
        {    fseek(file,data2.first_name_posn,SEEK_SET);
          fread(c33,data2.next-data2.first_name_posn,1,file);

          fseek(file,data2.last_name_posn,SEEK_SET);
          fread(c44,data2.company_name_posn-data2.last_name_posn,1,file);
          c44[data2.company_name_posn-data2.last_name_posn]='\0';
          fseek(file,data2.email_posn,SEEK_SET);
          fread(c55,data2.next-data2.email_posn,1,file);

          fseek(file,data2.company_name_posn,SEEK_SET);
          fread(c66,data2.next-data2.company_name_posn,1,file);
          fseek(file,data2.next,0);

          if((strcmp(lastname,c44)==0))
          {
            printf("First Name:%s\n",c33);
            printf("Last Name:%s\n",c44);

            printf("Company Name:%s\n",c66);
            printf("Phone Number:%ld\n",data2.phone_number);
            printf("Email:%s\n",c55);


            calc3=data2.next-((strlen(c66)+strlen(c55)+strlen(c44)+strlen(c33)+sizeof(struct contact)))-4 ;

            char * phoneNum;
            char *emailAdress;
            int ii;
            do {          ii=0;

              printf("Phone Number (enter only numbers): ");
              scanf("%s",phoneNum);
              if((strlen(phoneNum))==7)
              ii++;
              if((strlen(phoneNum))==10)
              ii++;
            } while((isPhoneNum(phoneNum) != 0)||(ii<1));
            data2.phone_number = strtol(phoneNum,&phoneNum,10);
            int valid=0;
            do {
              printf("Email: ");
              emailAdress = getInput();
              int i=0,count1=0,count2=0;
              int d=0,l=0;

              while(emailAdress[i])
              {
                if(emailAdress[i]=='@')
                {count1++;
                  d=i;
                }
                if(emailAdress[i]=='.')
                {
                  count2++;
                  l=i;
                }
                i++;
              }
              if((count1>0&&count1<2)&&(count2>0&&count2<2)&&l>d)
              valid=1;

              else
              {
                valid=0;
                /*printf("enter valid email id");*/
              }
            } while((strlen(emailAdress) <= 0)||valid==0);
            strcpy(c55,emailAdress);
            data2.first_name_posn=calc3+sizeof(struct contact);
            data2.last_name_posn=data2.first_name_posn+strlen(c33)+1;
            data2.company_name_posn=data2.last_name_posn+strlen(c44)+1;
            data2.email_posn=data2.company_name_posn+strlen(c66)+1;
            data2.next=data2.email_posn+strlen(c55)+1;
            calc3=data2.next;


            found = 1;
          }
          else
          {   if(found==1)
            {
              data2.first_name_posn=calc3+sizeof(struct contact);

              data2.last_name_posn=data2.first_name_posn+strlen(c33)+1;
              data2.company_name_posn=data2.last_name_posn+strlen(c44)+1;
              data2.email_posn=data2.company_name_posn+strlen(c66)+1;
              data2.next=data2.email_posn+strlen(c55)+1;
              calc3=data2.next;
            }
            {


            }

          }
          fwrite(&data2, sizeof(data2), 1, fp_tmp);
          fwrite(c33,1,strlen(c33) + 1,fp_tmp);
          fwrite(c44,1,strlen(c44) + 1,fp_tmp);
          fwrite(c66,1,strlen(c66) + 1,fp_tmp);
          fwrite(c55,1,strlen(c55) + 1,fp_tmp);
        }

        if (found == 0)
        printf("\n Record Not Found ");
        char inp[2];
        printf("do you confrim to save it");
        scanf("%s",inp);
        if((strcmp(inp,"S")==0))
        {printf("\n Record Updated");
        remove(filename);
        rename("tmp1.bin", filename);
        int file_exists;


        FILE *file=fopen(filename,"rb");
        if (file==NULL) file_exists=0;
        else {file_exists=1; fclose(file);}



        if (file_exists==1)
        {
          printf("file exists!\n");
          file=fopen(filename,"ab+");

        }
        else
        {
          printf("file does not exist!\n");

          file=fopen(filename,"wb+");

        }





      }
      return 0;
    }
    int editadd(char *lastname)
    {

      char *filename="in1.bin";
      FILE *file=fopen(filename,"rb");
      char  c33[100],c44[100],c55[100],c66[100];
      struct contact data2;
      int calc3=0;
      int  found = 0;


      rewind(file);
      FILE *fp_tmp=fopen("tmp1.bin", "wb");
      if (!fp_tmp) {
        printf("Unable to open file temp file.");
        return -1;
      }

      while ((fread(&data2, sizeof(data2), 1, file)) > 0)
      {    fseek(file,data2.first_name_posn,SEEK_SET);
        fread(c33,data2.next-data2.first_name_posn,1,file);

        fseek(file,data2.last_name_posn,SEEK_SET);
        fread(c44,data2.company_name_posn-data2.last_name_posn,1,file);
        c44[data2.company_name_posn-data2.last_name_posn]='\0';
        fseek(file,data2.email_posn,SEEK_SET);
        fread(c55,data2.next-data2.email_posn,1,file);

        fseek(file,data2.company_name_posn,SEEK_SET);
        fread(c66,data2.next-data2.company_name_posn,1,file);
        fseek(file,data2.next,0);

        if((strlen(c44))!=0)
        { if((strcmp(lastname,c44)==0))
          { printf("Contact Information-Edit and Add\n");


          printf("First Name:%s\n",c33);
          printf("Last Name:%s\n",c44);

          printf("Company Name:%s\n",c66);

          calc3=data2.next-((strlen(c66)+strlen(c55)+strlen(c44)+strlen(c33)+sizeof(struct contact)))-4 ;
          char * phoneNum=malloc(sizeof(char));
          int ii;
          char *emailAdress=malloc(sizeof(char));
          do {          ii=0;

            printf("Phone Number (enter only numbers): ");
            scanf("%s",phoneNum);
            if((strlen(phoneNum))==7)
            ii++;
            if((strlen(phoneNum))==10)
            ii++;
          } while((isPhoneNum(phoneNum) != 0)||(ii<1));
          data2.phone_number = strtol(phoneNum,&phoneNum,10);
          int valid=0;
          do {
            printf("Email: ");
            scanf("%s",emailAdress);

            int i=0,count1=0,count2=0;
            int d=0,l=0;

            while(emailAdress[i])
            {
              if(emailAdress[i]=='@')
              {count1++;
                d=i;
              }
              if(emailAdress[i]=='.')
              {
                count2++;
                l=i;
              }
              i++;
            }
            if((count1>0&&count1<2)&&(count2>0&&count2<2)&&l>d)
            valid=1;

            else
            {
              valid=0;
              /*printf("enter valid email id");*/
            }
          } while((strlen(emailAdress) <= 0)||valid==0);
          strcpy(c55,emailAdress);
          data2.first_name_posn=calc3+sizeof(struct contact);
          data2.last_name_posn=data2.first_name_posn+strlen(c33)+1;
          data2.company_name_posn=data2.last_name_posn+strlen(c44)+1;
          data2.email_posn=data2.company_name_posn+strlen(c66)+1;
          data2.next=data2.email_posn+strlen(c55)+1;
          calc3=data2.next;


          found = 1;
        }
        else
        {   if(found==1)
          {
            data2.first_name_posn=calc3+sizeof(struct contact);

            data2.last_name_posn=data2.first_name_posn+strlen(c33)+1;
            data2.company_name_posn=data2.last_name_posn+strlen(c44)+1;
            data2.email_posn=data2.company_name_posn+strlen(c66)+1;
            data2.next=data2.email_posn+strlen(c55)+1;
            calc3=data2.next;
          }
        }
        fwrite(&data2, sizeof(data2), 1, fp_tmp);
        fwrite(c33,1,strlen(c33) + 1,fp_tmp);
        fwrite(c44,1,strlen(c44) + 1,fp_tmp);
        fwrite(c66,1,strlen(c66) + 1,fp_tmp);
        fwrite(c55,1,strlen(c55) + 1,fp_tmp);
      }


      else
      { if((strcmp(lastname,c66)==0))
        { printf("Contact Information-Edit and Add\n");


        printf("First Name:%s\n",c33);
        printf("Last Name:%s\n",c44);

        printf("Company Name:%s\n",c66);

        calc3=data2.next-((strlen(c66)+strlen(c55)+strlen(c44)+strlen(c33)+sizeof(struct contact)))-4 ;
        char * phoneNum=malloc(sizeof(char));
        int ii;
        char *emailAdress=malloc(sizeof(char));
        do {          ii=0;

          printf("Phone Number (enter only numbers): ");
          scanf("%s",phoneNum);
          if((strlen(phoneNum))==7)
          ii++;
          if((strlen(phoneNum))==10)
          ii++;
        } while((isPhoneNum(phoneNum) != 0)||(ii<1));
        data2.phone_number = strtol(phoneNum,&phoneNum,10);
        int valid=0;
        do {
          printf("Email: ");
          scanf("%s",emailAdress);

          int i=0,count1=0,count2=0;
          int d=0,l=0;

          while(emailAdress[i])
          {
            if(emailAdress[i]=='@')
            {count1++;
              d=i;
            }
            if(emailAdress[i]=='.')
            {
              count2++;
              l=i;
            }
            i++;
          }
          if((count1>0&&count1<2)&&(count2>0&&count2<2)&&l>d)
          valid=1;

          else
          {
            valid=0;
            printf("enter valid email id");
          }
        } while((strlen(emailAdress) <= 0)||valid==0);
        strcpy(c55,emailAdress);
        data2.first_name_posn=calc3+sizeof(struct contact);
        data2.last_name_posn=data2.first_name_posn+strlen(c33)+1;
        data2.company_name_posn=data2.last_name_posn+strlen(c44)+1;
        data2.email_posn=data2.company_name_posn+strlen(c66)+1;
        data2.next=data2.email_posn+strlen(c55)+1;
        calc3=data2.next;



        found = 1;
      }
      else
      {   if(found==1)
        {
          data2.first_name_posn=calc3+sizeof(struct contact);


          data2.last_name_posn=data2.first_name_posn+strlen(c33)+1;
          data2.company_name_posn=data2.last_name_posn+strlen(c44)+1;
          data2.email_posn=data2.company_name_posn+strlen(c66)+1;
          data2.next=data2.email_posn+strlen(c55)+1;
          calc3=data2.next;
        }


      }
      fwrite(&data2, sizeof(data2), 1, fp_tmp);
      fwrite(c33,1,strlen(c33) + 1,fp_tmp);
      fwrite(c44,1,strlen(c44) + 1,fp_tmp);
      fwrite(c66,1,strlen(c66) + 1,fp_tmp);
      fwrite(c55,1,strlen(c55) + 1,fp_tmp);
    }
  }


  if (found == 0)
  printf("\n Record Not Found ");
  fclose(file);
  fclose(fp_tmp);
  char inp[2];
  printf("Available Actions for Edit\n");
  printf("___________________________________________________________________\n");
  printf("    R   |Return to the Full Contacts List interface               |\n");
  printf("    S   |Save this contact and return to Full Contacts List       |\n");
  printf("    D   |Delete contact and return to full contact list           |\n");
  printf("------------------------------------------------------------------\n");


  do {printf("Action:");
  scanf("%s",inp);
  if((!strcmp(inp,"S"))||(!strcmp(inp,"R"))||(!strcmp(inp,"D")))
  break;
}while(1);
printf("\n");

if((strcmp(inp,"S")==0))
{printf("\n Record Updated");
remove(filename);
rename("tmp1.bin", filename);
}
int file_exists;
filename="in1.bin";

file=fopen(filename,"rb");
if (file==NULL) file_exists=0;
else {file_exists=1; fclose(file);}



if (file_exists==1)
{
  printf("file exists!\n");
  file=fopen(filename,"ab+");

}
else
{
  printf("file does not exist!\n");

  file=fopen(filename,"wb+");

}



if (file!=NULL)
{
  printf ("file opened succesfully!\n");

}


if((strcmp(inp,"D")==0))
{
  if((strlen(c44))!=0)
  {deletedata(c44);
    printf("deletion done");
  }
  else
  {
    deletedata(c66);
    printf("deletion done");
  }
}
return 0;
}



int mainline()
{
  printf("The action inputs for the main contact display are the following:\n");
  printf("___________________________________________________________________\n");
  printf("<Number>|Select this contact and display its full information     |\n");
  printf("   A    |Add a new contact                                        |\n");
  printf("   X    |Exit the program                                         |\n");
  printf("------------------------------------------------------------------\n");
  printf("Action:");

  char ch1='b';

  char *ch=&ch1;
  scanf("%s",ch);
  printf("\n");
  while((getchar())!='\n');

  int x;

  if(!strcmp(ch,"A"))
  {
    add();
    maindisp();
    mainline();

  }
  else if(!strcmp(ch,"X"))
  {

    exit(0);
  }

  else
  {


    sscanf(ch, "%d", &x);


    while(x>reccount())
    {
      printf("enter valid record number\n");
      scanf("%d",&x);
    }

    char * search=sort1(x-1);
    dispdata(search);
  }


  return 0;
}
