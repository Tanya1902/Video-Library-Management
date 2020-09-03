/************************* VIDEO LIBRARY MANAGEMENT *************************
 *====*===*====*===*====*= BY TANYA AND PRATISHTHA =*====*===*====*===*====*/
#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
struct Date
 {
  int d,dd,mm,yy;
 } d;
 int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class CDDVD
 {
  int CDDVD_no;
  char Title[20],Singer[30],Movie[30],Type[20];
  float Price;
  int no_of_copies,no_issued;
  public:
    void VGetData()    //Member Function to get data of CD/DVD
  {
   clrscr();
   cout<<"\n\n\n\n\n\t\t\t Enter CDDVD No:";
   cin>>CDDVD_no;
   cout<<"\n\t\t\tEnter Video Title:";
   gets(Title);
   cout<<"\n\t\t\tEnter Singer's name:";
   gets(Singer);
   cout<<"\n\t\t\tEnter Movie Name:";
   gets(Movie);
   cout<<"\n\t\t\tEnter Type of Video:";
   gets(Type);
   cout<<"\n\t\t\tEnter Price Per Copy:";
   cin>>Price;
   cout<<"\n\t\t\tEnter Number of Copies:";
   cin>>no_of_copies;
   no_issued=0;
}
 void VDisplayData()    //Member function to display data of CD/DVD
  {
    clrscr();
      cout<<"\n\n\n\n\n\t\t\t CDDVD No: "<<CDDVD_no
	  <<"\n\t\t\t Title of the Video:"<<Title
	  <<"\n\t\t\t Name of the Singer:"<<Singer
	  <<"\n\t\t\t Name of the Movie:"<<Movie
	  <<"\n\t\t\t Video Type:"<<Type
	  <<"\n\t\t\t Video Price:"<<Price
	  <<"\n\t\t\t Number of Copies:"<<no_of_copies
	  <<"\n\t\t\t Number of Copies Issued:"<<no_issued;
  }
 int Return_CDDVDno()
  {
   return CDDVD_no;
  }
char *Return_Title()
  {
   return Title;
  }
int Check_CDDVD();

void Update_CDDVD()
  {
    no_issued++;
  }
void Update_CDDVD2()
{
   no_issued--;
}
}CD;
class Member
{
  int Member_no;
  char Name[20],Address[30],phone[11],pincode[10];
  int CDDVD_allowed,CDDVD_issued;
  public:
  void MGetData()       //Member Function to get data of member
  {
  clrscr();
  CDDVD_allowed=6;
  CDDVD_issued=0;
  cout<<"\n\n\n\n\n\t\t\tEnter Member number: ";
  cin>>Member_no;
  cout<<"\n\t\t\tEnter Member's Name: ";
  gets(Name);
  cout<<"\n\t\t\tEnter his/her Address: ";
  gets(Address);
  cout<<"\n\t\t\tEnter his/her Phone Number: ";
  cin>>phone;
  cout<<"\n\t\t\tEnter Pin Code: ";
  cin>>pincode;
  }
  void MDisplayData()   //Member Function to  display data of member
  {
   clrscr();
    cout<<"\n\n\n\n\n\n\t\t\tMember Number:"<<Member_no
      <<"\n\t\t\tName:"<<Name
      <<"\n\t\t\tAddress:"<<Address
      <<"\n\t\t\tPhone Number:"<<phone
      <<"\n\t\t\tPin Code:"<<pincode
      <<"\n\t\t\tNumber of Videos allowed to be Issued:"<<CDDVD_allowed
      <<"\n\t\t\tNumber of Videos Issued:"<<CDDVD_issued;
  }
  int Return_Memberno()
  {
  return Member_no;
  }
  int Check_CDDVD();
  void Update_CDDVDI()
  {
   CDDVD_issued++;
  }
  void Update_CDDVDR()
  {
    CDDVD_issued--;
  }
  }M;

 void addm()
 {
 clrscr();
 fstream fout("Member.dat",ios::app|ios::binary);
 char rep;
 do
 { clrscr();
 M.MGetData();
 fout.write((char*)&M,sizeof(M));
 cout<<"\n\t\t\t Want to add more records ? (Y or N):";
 cin>>rep;
 }while(rep=='Y');
 };
 void MDisplay()
 {
 clrscr();
 ifstream fin("Member.dat",ios::binary);
 Member M;
 while(fin.read((char*)&M,sizeof(M)))
 {
 M.MDisplayData();
 getch();
 }
 }

 void delete_mrec(int r)
 {
 clrscr();
 int flag=0;
 ifstream fin("Member.dat",ios::binary);
 ofstream fout("NewM.dat",ios::binary);
 Member M;
 while(fin.read((char*)&M,sizeof(M)))
 {
  if(M.Return_Memberno()==r)
  flag=1;
  else
  fout.write((char*)&M,sizeof(M));
 }
 if(flag==1)
 {
   gotoxy(27,12);
   cout<<"Deleted successfully.";    }
 else
 { gotoxy(27,12);
   cout<<"No such member exists.";   }
 fin.close();
 fout.close();
 remove("Member.dat");
 rename("NewM.dat","Member.dat");
 }
void modifym(int r)
 {
 int flag=0;
 ifstream fin("Member.dat",ios::binary);
 ofstream fout("NewM.dat",ios::binary);
 Member M;
 while(fin.read((char*)&M,sizeof(M)))
 {
  if(M.Return_Memberno()==r)
  {
   flag=1;
   M.MGetData();
   clrscr();
   gotoxy(27,12);
   cout<<"Member record has been successfully modified.";
  }
  else
   flag=0;
 }
  if(flag==0)
  {
   clrscr();
   gotoxy(27,12);
   cout<<"No such member exists.";
  }
  fout.write((char*)&M,sizeof(M));
 fin.close();
 fout.close();
 remove("Member.dat");
 rename("NewM.dat","Member.dat");
 };

  int Member::Check_CDDVD()
  {
   if (CDDVD_issued<CDDVD_allowed)
       return 1;
   else
       return 0;
  }
   int CDDVD::Check_CDDVD()
  {
   if (no_issued<no_of_copies)
       return 1;
   else
       return 0;
  }
class Issued
  {
  int CDDVD_no,Member_no;
  public:
  Date Issue_date,Return_date,Due_date;
  float fine_amt;
  void IGetData();
  void IDisplayData();
  int Check_issue(int cn,int m)
  {
   if(CDDVD_no==cn && Member_no ==m)
    return 1;
   else
    return 0;
  }
   int check_date(Date td)
   {
	    Return_date=td;
	    if(Due_date.dd<=td.dd && Due_date.mm<=td.mm && Due_date.yy<=td.yy)
	     return 1;
	    else
	     return 0;
   };
   }I;

   void Issued::IGetData()  //to issue CD/DVD and generate Issue and Return Dates
   {
   int flag=0;
   start:
   flag=0;
   clrscr();
   cout<<"\n\n\n\n\n\t\t\tEnter CDDVD number to be issued:";
   cin>>CDDVD_no;
   fstream fin("Videos.dat",ios::in|ios::out|ios::binary);
   while(fin.read((char *)&CD,sizeof(CD)))
   {
   if(CD.Return_CDDVDno()==CDDVD_no)
   {
   flag=1;
   break;
   }
   }
   if(flag==0)
   {
   cout<<"\n\t\t\t Invalid CDDVD number.";
   getch();
   goto start;
   }
   if(CD.Check_CDDVD()==0)
   {
   cout<<"\n\t\t\t CD/DVD is not available.";
   getch();
   goto start;
   }
   long offset=fin.tellp();
   CD.Update_CDDVD();
   fin.seekp(offset-sizeof(CD));
   fin.write((char *)&CD,sizeof(CD));
   start2:
   clrscr();
   flag=0;
   cout<<"\n\n\n\n\n\t\t\t Enter Member Number: ";
   cin>>Member_no;
   fstream fin_m("Member.dat",ios::in|ios::out|ios::binary);
   while(fin_m.read((char *)&M,sizeof(M)))
   {
   if(M.Return_Memberno()==Member_no)
   {
   flag=1;
   break;
   }
   }
   if(flag==0)
   {
   char ans;
   cout<<"\n\t\t\t Invalid Member number.";
   cout<<"\n\n\t\t\t Want to enter new member number?(Y or N)";
   cin>>ans;
   if(ans=='N')
      return;
   else
   goto start2;
   }
   if(M.Check_CDDVD()==0)
   {
   char r;
   cout<<"\n\t\t\t Maximum issue limit reached.";
   cout<<"\n\n\t\t\t Do you want to change member number?(Y or N): ";
   cin>>r;
   if(r=='N')
   return;
   goto start;
   }
   long offset1=fin_m.tellp();
   M.Update_CDDVDI();
   fin_m.seekp(offset1-sizeof(M));
   fin_m.write((char *)&M,sizeof(M));
   struct date d1;
   getdate(&d1);
   Issue_date.dd=d1.da_day;
   Issue_date.mm=d1.da_mon;
   Issue_date.yy=d1.da_year;
   cout<<"\n\t\t\t Issue date = "<<Issue_date.dd<<"/"
       <<Issue_date.mm<<"/"<<Issue_date.yy;
   Return_date=Issue_date;
   Return_date.dd+=7;
   int t=Return_date.mm;
   if(Return_date.dd>month[t])
   {
   Return_date.dd=Return_date.dd-month[t];;
   Return_date.mm++;

   }
   if(Return_date.mm>12)
   {
   Return_date.yy++;
   Return_date.mm=1;
   }
   cout<<"\n\t\t\t Return date = "<<Return_date.dd<<"/"
       <<Return_date.mm<<"/"<<Return_date.yy;
       getch();
   Due_date.dd=0;
   Due_date.mm=0;
   Due_date.yy=0;
   fine_amt=0;
  }
   void Issue_CDDVD()
 {
 clrscr();
 ofstream fout("Trans.dat",ios::app|ios::binary);
 char rep;
 do
 {
 I.IGetData();
 fout.write((char*)&I,sizeof(I));
 clrscr();
 gotoxy(27,12);
 cout<<"Want to add more records ? (Y or N):";
 cin>>rep;
 }while(rep=='Y');
 };

 void Return_of_CDDVD() //to update record when CD/DVD has been returned and generate fine
 {
 int CDDVD_no;
 long offset;
 start:
   clrscr();
   int flag=0,memno;
   cout<<"\n\n\n\n\n\t\t\tEnter CDDVD number returned:";
   cin>>CDDVD_no;
   fstream fin("Videos.dat",ios::in|ios::out|ios::binary);
   while(fin.read((char *)&CD,sizeof(CD)))
   {
     if(CD.Return_CDDVDno()==CDDVD_no)
   {
     flag=1;
     break;
   }
   }
   if(flag==0)
   {
     cout<<"\n\t\t\t No such CD/DVD has been issued.";
     getch();
     goto start;
   }
   offset=fin.tellp();
   CD.Update_CDDVD2();
   fin.seekp(offset-sizeof(CD));
   fin.write((char *)&CD,sizeof(CD));

   start2:
    clrscr();
    fstream fin1("Member.dat",ios::in|ios::out|ios::binary);
    int flag2=0;
      cout<<"\n\n\n\n\t\t\tEnter member number:";
      cin>>memno;
    while(fin1.read((char*)&M,sizeof(M)))
    {
     if(M.Return_Memberno()==memno)
      {
       flag2=1;
      }
    }
    if(flag2==0)
    {
     cout<<"\n\t\t\tNo such member number.";
     goto start2;
    }
  offset=fin1.tellp();
  M.Update_CDDVDR();
  fin1.seekp(offset-sizeof(M));
  M.MDisplayData();
  getch();
  fin1.write((char *)&M,sizeof(M));

 int flag3=0;
 fstream fissue("Trans.dat",ios::in|ios::binary);
 fstream fr("newT.dat",ios::out|ios::binary);
 while(fissue.read((char*)&I,sizeof(I)))
 {
   if (I.Check_issue(CDDVD_no,memno)==1)
    {
      flag3=1;
      goto star;
    }
   else
   fr.write((char*)&I,sizeof(I));
 }
   if(flag3==0)
   {
    cout<<"\n\t\t\t No such CD/DVD issued.";
    getch();
    return;
   }
   star:
   if(flag3==1)
   {
    int days=0;
	   if(I.Return_date.yy==I.Due_date.yy && I.Return_date.mm==I.Due_date.mm
	      && I.Return_date.dd==I.Due_date.dd)
	      {days=0;
	      }
	   else if(I.Return_date.yy==I.Due_date.yy && I.Return_date.mm==I.Due_date.mm)
	   {
		for(int i=I.Issue_date.dd;i<=I.Due_date.dd;i++)
		    days++;
	   }
	   else if(I.Return_date.yy<=I.Due_date.yy && I.Return_date.mm<I.Due_date.mm)
	   {	  for(int i=I.Issue_date.dd;i<=month[I.Issue_date.mm];i++)
		      days++;
		   for(i=0;i<I.Return_date.dd;i++)
		       days++;
	    }
	I.fine_amt=days*5;
	cout<<"\n\t\t\tFine:"<<I.fine_amt;
	}
  remove("Trans.dat");
  rename("newT.dat","Trans.dat");
}

 void query_cddvd()
 {
 ifstream fin("Videos.dat",ios::binary);
 int mvideono,flag=0;
 cout<<"\n\t\t\tEnter video number:";
 cin>>mvideono;
 while(fin.read((char*)&CD,sizeof(CD)))
 {

  if(CD.Return_CDDVDno()==mvideono)
    {
     CD.VDisplayData();
     flag=1;
    }
 };
 if(flag==0)
 { clrscr();
   gotoxy(27,12);
   cout<<"No such video exists."; }
 };

 void query_member()
 {
  ifstream fin("Member.dat",ios::binary);
  Member M;
  int memno,flag=0;
  cout<<"\n\t\t\tEnter member number:";
  cin>>memno;
 while(fin.read((char*)&M,sizeof(M)))
 {
  if(M.Return_Memberno()==memno)
    {
     M.MDisplayData();
     flag=1;
    }
 };
 if(flag==0)
 {
  clrscr();
  gotoxy(27,12);
  cout<<"No such member exists.";  }
 }

 void addv()
 {
 clrscr();
 ofstream fout("Videos.dat",ios::app|ios::binary);
 char rep;
 do
 {
 CD.VGetData();
 fout.write((char*)&CD,sizeof(CD));
 cout<<"\n\t\t Want to add more records? (Y or N):";
 cin>>rep;
 }while(rep=='Y');
 }
 void delete_vrec(int r)
 {
 clrscr();
 ifstream fin("Videos.dat",ios::binary);
 ofstream fout("NewVideos.dat",ios::binary);
 int flag=0;
 while(fin.read((char*)&CD,sizeof(CD)))
 {
  if(CD.Return_CDDVDno()!=r)
  fout.write((char*)&CD,sizeof(CD));
  flag=1;
 }
 if(flag==1)
 { clrscr();
   gotoxy(27,12);
   cout<<"Deleted Successfully."; }
 else
  {
   clrscr();
   gotoxy(27,12);
   cout<<"No such CD/DVD exists."; }
 fin.close();
 fout.close();
 remove("Videos.dat");
 rename("NewVideos.dat","Videos.dat");
 };
 void modifyv(int r)
 {
 int flag=0;
 ifstream fin("Videos.dat",ios::binary);
 ofstream fout("NewVideos.dat",ios::binary);
 while(fin.read((char*)&CD,sizeof(CD)))
 {
  if(CD.Return_CDDVDno()==r)
  {
   flag=1;
   CD.VGetData();
   clrscr();
   gotoxy(27,12);
   cout<<"CD/DVD record successfully modified.";
  }
  fout.write((char*)&CD,sizeof(CD));
 }
 if(flag==0)
 {
  clrscr();
  gotoxy(27,12);
  cout<<"CD/DVD "<<r<<" does not exist in record.";
 }
 fin.close();
 fout.close();
 remove("Videos.dat");
 rename("NewVideos.dat","Videos.dat");
 };
 void member_list()     //to display member list
 {
  clrscr();
  ifstream fin("Member.dat",ios::binary);
  Member M;
  int flag=0;
 while(fin.read((char*)&M,sizeof(M)))
 {
     flag=1;
     cout<<"\n\n ";
     M.MDisplayData();
     getch();
  }
  if(flag==0)
  { gotoxy(27,12);
    cout<<"No Members found in record."; }
 }

  void video_list()     //to generate CD/DVD list
 {
  clrscr();
  ifstream fin("Videos.dat",ios::binary);
  CDDVD M;
  int flag=0;
 while(fin.read((char*)&M,sizeof(M)))
 {
     flag=1;
     cout<<"\n\n ";
     M.VDisplayData();
     getch();
 }
 if(flag==0)
  { gotoxy(27,12);
    cout<<"No CD/DVD found in record."; }
 }

   void submenu1()
   {
   char ch;
   int r;
   do
   {
   textbackground(RED);
   textcolor(WHITE);
   clrscr();
   cout <<"\n\n\n\n\t\t\t   MEMBER MANAGEMENT"
	<<"\n\n\t\t\ta.  Display Members"
	<<"\n\t\t\tb.  Add a Member"
	<<"\n\t\t\tc.  Delete a Member"
	<<"\n\t\t\td.  Modify a Member"
	<<"\n\t\t\te.  Exit";
   cout<<"\n\n\t\t\tEnter your choice:";
   cin>>ch;
   switch(ch)
   {
   case 'a': MDisplay();
	      break;
   case 'b': addm();
	      break;
   case 'c': cout<<"\n\t\t\tEnter Member number to delete:";
	     cin>>r;
	     delete_mrec(r);
	      break;
   case 'd':
	     cout<<"\n\t\t\tEnter Member number to modify:";
	     cin>>r;
	     modifym(r);
	      break;
   case 'e':return;
   }
   getch();
   }while(ch!='e');
   };
    void submenu2()
    {
    char ch;
    int r;
    do
    {
    textcolor(BLUE);
    textbackground(MAGENTA);
    clrscr();
    cout<<"\n\n\n\n\t\t\t    CD/DVD MANAGEMENT"
	<<"\n\n\t\t\ta.  Display CD/DVD Records"
	<<"\n\t\t\tb.  Add a CD/DVD"
	<<"\n\t\t\tc.  Delete a CD/DVD"
	<<"\n\t\t\td.  Modify a CD/DVD"
	<<"\n\t\t\te.  Exit";
    cout<<"\n\n\t\t\tEnter your choice:";
    cin>>ch;
    switch(ch)
    {
     case 'a':  video_list();
		 break;
     case 'b':  addv();
		 break;

     case 'c':	cout<<"\n\t\t\tEnter CDDVD number to delete:";
		 cin>>r;
		delete_vrec(r);
		 break;

     case 'd':  cout<<"\n\t\t\tEnter CDDVD number to modify:";
		 cin>>r;
		modifyv(r);
		 break;
    }
    getch();
    }while(ch!='e');
    };
    void submenu3()
    {
    textcolor(BLACK);
    textbackground(GREEN);
    char ch;
    do
    {
    clrscr();
    cout<<"\n\n\n\n\n\n\t\t\t\t"
	<<"a. Issue"
	<<"\n\t\t\t\tb. Return"
	<<"\n\t\t\t\tc. Exit";
    cout<<"\n\n\t\t\t   Enter your choice:";
    cin>>ch;
    switch(ch)
    {
     case 'a':Issue_CDDVD();
	      break;
     case 'b':Return_of_CDDVD();
	      break;
    }
    getch();
    } while(ch!='c');
    }
    void submenu4()
    {
    textcolor(GREEN);
    textbackground(BLUE);
    char ch;
    do
    {
    clrscr();
     cout<<"\n\n\n\n\n\n\t\t\ta.  CD/DVD"
	 <<"\n\t\t\tb.  Member"
	 <<"\n\t\t\tc.  Exit";
     cout<<"\n\n\t\t\t  Enter your choice:";
     cin>>ch;
     switch(ch)
     {
     case 'a':  query_cddvd();
		 break;

     case 'b':  query_member();
		break;
     }
     getch();
    }while(ch!='c');
    }
    void submenu5()
    {
    textbackground(YELLOW);
    textcolor(RED
    );
    char ch;
    do
    {
    clrscr();
     cout<<"\n\n\n\n\n\n\t\t\t\ta.  Member List"
	 <<"\n\t\t\t\tb.  CDDVD List"
	 <<"\n\t\t\t\tc.  Exit";
     cout<<"\n\n\t\t\t\tEnter your choice:";
     cin>>ch;
     switch(ch)
     {
      case 'a':  member_list();
		  break;

      case 'b':  video_list();
		  break;
      }
      getch();
     }while(ch!='c');
    }
void main()
{
clrscr();
textcolor(MAGENTA);
textbackground(BLACK);
int c1;
do
{
clrscr();
cout<<"\n\n\n\n\t\t\t\t MAIN MENU";
cout<<"\n\n\t\t\t1.Member Management"
    <<"\n\t\t\t2.CDDVD Management"
    <<"\n\t\t\t3.Transaction"
    <<"\n\t\t\t4.Query"
    <<"\n\t\t\t5.Report"
    <<"\n\t\t\t6.Exit";
 cout<<"\n\n\t\t\tEnter Your Choice's Number:";
  cin>>c1;
switch(c1)
{
 case 1:submenu1(); break;

 case 2:submenu2(); break;

 case 3:submenu3(); break;

 case 4:submenu4(); break;

 case 5:submenu5(); break;

 case 6:cout<<"\n\n\t\t\t THANK-YOU & HAVE A GOOD DAY!";
	getch();
	exit(0);
 }
getch();
}while(c1!=6);
}







