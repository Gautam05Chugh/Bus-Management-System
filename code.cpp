#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bus
{
    private:
        string b_no,b_name,d_name;
        int b_seat;
    public:
        void menu();
        void new_bus();
        void view_bus();
        void single_view_bus();
        void all_view_bus();
        void update_bus();
        void del_bus();
        void rout_bus();
        void detail_bus();
        void booking();
	void renew_bus();
        void search_booking();
        void update_booking();
        void del_booking();
        void show_booking();
};
    void bus:: menu()
    {
        q:
        system("cls");
        int choice;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        cout<<"\n\n 1. ADD BUS RECORD";
        cout<<"\n 2. VIEW BUSES DETAIL";
        cout<<"\n 3. UPDATE BUS DETAIL";
        cout<<"\n 4. DELETE BUS DETAIL";
        cout<<"\n 5. ROUTES OF BUSES";
        cout<<"\n 6. BUS SEATS DETAILS";
        cout<<"\n 7. BOOKING RECORD";
        cout<<"\n 8. SEATS RENEW";
        cout<<"\n 9. SEARCH BOOKING RECORD";
        cout<<"\n 10. UPDATE BOOKING RECORD";
        cout<<"\n 11. DELETE BOOKING RECORD";
        cout<<"\n 12. SHOW ALL BOOKING RECORD";
        cout<<"\n 13. EXIT";
        cout<<"\n\n ENTER YOUR CHOICE : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                new_bus();
                break;
            case 2:
                view_bus();
                break;
            case 3:
                update_bus();
                break;
            case 4:
                del_bus();
                break;
            case 5:
                rout_bus();
                break;
            case 6:
                detail_bus();
		break;
            case 7:
                booking();
                break;
            case 8:
		renew_bus();
                break;
            case 9:
		search_booking();
                break;
            case 10:
		update_booking();
                break;
            case 11:
		del_booking();
                break;
            case 12:
		show_booking();
                break;
            case 13:
                exit(0);
            default:
                cout<<"\n\n Invalid Choice... Please Try Again...";
        }
        getch();
        goto q;
    }
    void bus::new_bus()
    {
        r:
        system("cls");
        fstream file;
        string t_no,tb_name,td_name;
        int t_seats, found=0;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        cout<<"\n\n Bus No :";
        cin>>b_no;
        cout<<"\n\n Bus Name :";
        cin>>b_name;
        cout<<"\n\n Total Seats :";
        cin>>b_seat;
        cout<<"\n\n Driver Name:";
        cin>>d_name;
        file.open("bus.txt",ios::in);
        if(!file)
        {
            file.open("bus.txt",ios::app|ios::out);
            file<<b_no<<" "<<b_name<<" "<<b_seat<<" "<<d_name<<"\n";
            file.close();
        }
        else
        {
            file>>t_no>>tb_name>>t_seats>>td_name;
            while(!file.eof())
            {
                if(b_no == t_no)
                {
                    found++;
                }
                file>>t_no>>tb_name>>t_seats>>td_name;
            }
            file.close();
            if(found == 0)
            {
                file.open("bus.txt",ios::app|ios::out);
                file<<b_no<<" "<<b_name<<" "<<b_seat<<" "<<d_name<<"\n";
                file.close();
            }
            else
            {
                cout<<"\n\n Duplicate Record Found...";
                getch();
                goto r;
            }
        }
        cout<<"\n\n New Bus Inserted Successfully";
    }
    void bus::view_bus()
    {
        s:
        system("cls");
        int choice;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        cout<<"\n\n 1.Single Bus View";
        cout<<"\n 2. All Buses View";
        cout<<"\n 3. Go Back";
        cout<<"\n\n Enter Your Choice";
        cin>>choice;
        switch(choice)
        {
            case 1:
                single_view_bus();
                break;
            case 2:
                all_view_bus();
                break;
            case 3:
                menu();
            default:
                cout<<"\n\n Invalid Choice... Please Try Again...";
        }
        getch();
        goto s;
    }
    void bus::single_view_bus()
    {
        system("cls");
        string t_no;
        fstream file;
        int found=0;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File Opening Error...";
        }
        else
        {
            cout<<"\n\n Bus No :";
            cin>>t_no;
            file>>b_no>>b_name>>b_seat>>d_name;
            while(!file.eof())
            {
                if(t_no == b_no)
                {
                    cout<<"BUS NO.\tBUS NAME\tNO> OF SEATS\tDRIVER NAME";
                    cout<<"\n"<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seat<<"\t\t"<<d_name;
                    found++;
                }
                file>>b_no>>b_name>>b_seat>>d_name;
            }
            file.close();
            if(found == 0)
            {
                cout<<"\n\n Invalid Bus Number...";
            }
        }
    }
    void bus::all_view_bus()
    {
        system("cls");
        fstream file;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File Opening Error...";
        }
        else
        {
            cout<<"BUS NO.\tBUS NAME\tNO> OF SEATS\tDRIVER NAME";
            file>>b_no>>b_name>>b_seat>>d_name;
            while(!file.eof())
            {
                cout<<"\n"<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seat<<"\t\t"<<d_name;
                file>>b_no>>b_name>>b_seat>>d_name;
            }
            file.close();
        }
    }
    void bus::update_bus()
    {
        system("cls");
        fstream file,file1;
        string t_no,no,t_name,td_name;
        int t_seat,found=0;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("bus.txt,ios::in");
        if(!file)
        {
            cout<<"\n\n File Opening Error.....";
        }
        else
        {
            cout<<"\n\n Bus No. : ";
            cin>>t_no;
            file1.open("bus1.txt",ios::app|ios::out);
            file>>b_no>>b_name>>b_seat>>d_name;
            while(!file.eof())
            {
                if(t_no == b_no)
                {
                    cout<<"\n\n New Bus No. : ";
                    cin>>no;
                    cout<<"\n\n Bus Name : ";
                    cin>>t_name;
                    cout<<"\n\n No Of Seats : ";
                    cin>>t_seat;
                    cout<<"\n\n Driver Name : ";
                    cin>>td_name;
                    file1<<no<<" "<<t_name<<" "<<t_seat<<" "<<td_name<<"\n";
                    cout<<"\n\n\n Update Bus Record Successfully..........";
                    found++;

                }
                else
                {
                    file1<<b_no<<" "<<b_name<<" "<<b_seat<<" "<<d_name<<"\n";
                }
                file>>b_no>>b_name>>b_seat>>d_name;

            }
            file.close();
            file1.close();
            remove("bus.txt");
            rename("bus1.txt","bus.txt");
            if(found == 0)
            {
                cout<<"\n\n Bus No. is Invalid..........";
            }
        }

    }
    void bus::del_bus()
    {
        system("cls");
        fstream file,file1;
        string t_no;
        int found=0;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("bus.txt,ios::in");
        if(!file)
        {
            cout<<"\n\n File Opening Error.....";
        }
        else
        {
            cout<<"\n\n Bus No. : ";
            cin>>t_no;
            file1.open("bus1.txt",ios::app|ios::out);
            file>>b_no>>b_name>>b_seat>>d_name;
            while(!file.eof())
            {
                if(t_no == b_no)
                {

                    cout<<"\n\n\n Delete Bus Record Successfully..........";
                    found++;

                }
                else
                {
                    file1<<b_no<<" "<<b_name<<" "<<b_seat<<" "<<d_name<<"\n";
                }
                file>>b_no>>b_name>>b_seat>>d_name;

            }
            file.close();
            file1.close();
            remove("bus.txt");
            rename("bus1.txt","bus.txt");
            if(found == 0)
            {
                cout<<"\n\n Bus No. is Invalid..........";
            }
        }

    }
    void bus::rout_bus()
    {
        w:
        system("cls");
        int choice;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        cout<<"\n\n 1. 1st ROUT DETAILS ";
        cout<<"\n 2. 2nd ROUT DETAILS";
        cout<<"\n 3. 3rd ROUT DETAILS";
        cout<<"\n 4. 4th ROUT DETAILS";
        cout<<"\n 5. 5th ROUT DETAILS";
        cout<<"\n\n Enter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                system("cls");
                cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
                cout<<"\n\n   From Sialkot to Lahore ";
                cout<<"\n 9:00 am ................. 11:00 am";
                cout<<"\n   From Lahore to Faisalabad ";
                cout<<"\n 12:00 pm ................. 2:30 pm";
                cout<<"\n   From Sahiwaal to Bawalpur ";
                cout<<"\n 4:00 am  ................. 9:00 am";
                cout<<"\n   From Lahore to Multan ";
                cout<<"\n 7:00 am  ................. 2:00 pm";
                cout<<"\n   From Islamabad to Murree ";
                cout<<"\n 10:00 am  ................. 11:30 am";
                cout<<"\n   From Daska to Lahore ";
                cout<<"\n 8:30 am  ................. 10:00 am";
                break;
            case 2:
                system("cls");
                cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
                cout<<"\n\n   From Sialkot to Gujranwala ";
                cout<<"\n 9:00 am ................. 10:00 am";
                cout<<"\n   From Lahore to Kamoki ";
                cout<<"\n 12:00 pm ................. 1:00 pm";
                cout<<"\n   From Islamabad  to Rawalpindi ";
                cout<<"\n 10:00 pm  ................. 11:00 pm";
                break;
            case 3:
                system("cls");
                cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
                cout<<"\n\n   From Kamoki to Wazirabad ";
                cout<<"\n 8:30 am ................. 9:30 am";
                cout<<"\n   From Lahore to Gujranwala ";
                cout<<"\n 1:00 pm ................. 2:30 pm";
                cout<<"\n   From Murree to New Murree ";
                cout<<"\n 4:00 pm  ................. 4:30 pm";
                cout<<"\n   From Naran to Nathiya Gali ";
                cout<<"\n 7:00 am  ................. 12:00 pm";
                cout<<"\n   From Sialkot to Jehlum  ";
                cout<<"\n 8:00 am  ................. 10:00 am";
                break;
            case 4:
                system("cls");
                cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
                cout<<"\n\n   From Rawalpindi to Attock ";
                cout<<"\n 1:00 pm  ................. 10:00 pm";
                cout<<"\n   From Sialkot to Lahore ";
                cout<<"\n 8:00 pm ................. 10:00 pm";
                cout<<"\n   From Lahore  to Faisalabad ";
                cout<<"\n 11:00 am  ................. 1:30 pm";
                cout<<"\n   From Sialkot to Islamabad ";
                cout<<"\n 5:00 pm  ................. 10:00 pm";
                cout<<"\n   From Lahore to Multan ";
                cout<<"\n 6:00 pm  ................. 11:00 pm";
                cout<<"\n   From Multan to Gujranwala ";
                cout<<"\n 7:30 am  ................. 5:00 pm";
                cout<<"\n   From Gujranwala to Sahiwaal ";
                cout<<"\n 9:00 am  ................. 5:00 pm";
                break;
            case 5:
                system("cls");
                cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
                cout<<"\n\n  From Multan to Lahore ";
                cout<<"\n 8:00 pm  ................. 12:00 am";
                cout<<"\n   From Daska to Faisalabad ";
                cout<<"\n 11:00 pm ................. 3:30 am";
                cout<<"\n   From Sialkot  to Quetta ";
                cout<<"\n 3:00 am  ................. 3:00 am";
                cout<<"\n   From Sialkot to Islamabad ";
                cout<<"\n 7:30 am  ................. 5:00 pm";
                break;
            default:
                cout<<"\n\n Invalid Choice....Please Try Again...";
                getch();
                goto w;

        }

    }
    void bus::detail_bus()
    {
        system("cls");
        fstream file,file1;
        string t_no,s_b_no,s_no;
        int count=0,found=0;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file1.open("seat.txt",ios::app|ios::out);
        file1<<"E-101"<<" "<<5<<"\n";
        file1<<"E-101"<<" "<<10<<"\n";
        file1<<"E-101"<<" "<<15<<"\n";
        file1.close();
        file.open("bus.txt",ios::in);
        file1.open("seat.txt",ios::in);
        if(!file || !file1 )
        {
            cout<<"\n\n File Opening Error.....";
        }
        else
        {
            cout<<"\n\n BUS NO.: ";
            cin>>t_no;
            file1>>s_b_no>>s_no;
            while(!file1.eof())
            {
                if(t_no == s_b_no)
                {
                    count++;
                }
                file1>>s_b_no>>s_no;
            }
            file1.close();
            file>>b_no>>b_name>>b_seat>>d_name;
            while(!file.eof())
            {
                if(t_no == b_no)
                {
                    system("cls");
                    cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
                    cout<<"\n\n Total No. Of Seats : "<<b_seat;
                    cout<<"\n\n Reserved No. Of Seats : "<<count;
                    cout<<"\n\n Empty No. Of Seats : "<<b_seat-count;
                    found++;
                }
                file>>b_no>>b_name>>b_seat>>d_name;
            }
            file.close();
            if(found == 0)
            {
                cout<<"\n\n Bus No. is Invalid........";
            }
        }
    }
    void bus::booking()
    {
        p:
        system("cls");
        fstream file;
        int found=0,s_no,seats,count=0,s_s_no,ss_no[25],i=0,s_amount,total_amount=0,r_amount;
        char x;
        string t_no,s_b_no,customer_name,phone,from,to;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("bus.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error.....";
        }
        else
        {
          cout<<"\n\n Bus no. : ";
          cin>>t_no;
          file.close();
          file.open("seat.txt",ios::in);
          if(file)
          {
              file>>s_b_no>>s_s_no;
          while(!file.eof())
          {
              if(t_no == s_b_no)
              {
                  count++;
              }
            file>>s_b_no>>s_s_no;
          }
          file.close();
          }
          file.open("bus.txt",ios::in);
          file>>b_no>>b_name>>b_seat>>d_name;
          while(!file.eof())
          {
              if(t_no==b_no)
              {
                  seats = b_seat;
                  found++;
              }
            file>>b_no>>b_name>>b_seat>>d_name;
          }
          file.close();
          if(seats-count == 0)
          {
              cout<<"\n\n All seats are reserved ";
          }
          else if(found==1)
          {
              do{
                h:
                cout<<"\n\n Seat No. : ";
                cin>>s_no;
                if(s_no > seats)
                {
                    cout<<"\n\n Seat no. is invalid, please try again ";
                    goto h;
                }
                file.open("seat.txt",ios::in);
                if(!file)
                {
                    file.open("seat.txt",ios::app|ios::out);
                    file<<t_no<<" "<<s_no<<"\n";
                    file.close();
                }
                else
                {
                    file>>s_b_no>>s_s_no;
                    while(!file.eof())
                    {
                        if(t_no == s_b_no && s_no == s_s_no)
                        {
                            cout<<"\n\n Seat is already reserved, please try again";
                            file.close();
                            goto h;
                        }
                        file>>s_b_no>>s_s_no;
                    }
                    file.close();
                    file.open("seat.txt",ios::app|ios::out);
                    file<<t_no<<" "<<s_no<<"\n";
                    file.close();
                }
                ss_no[i] = s_no;
                i++;
                cout<<"\n\n Booking another seat (Y,N) : ";
                cin>>x;
              }while( x == 'Y' || x == 'y');
              system("cls");
              cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
              cout<<"\n\n Customer Name : ";
              cin>>customer_name;
              cout<<"\n\n Phone No. : ";
              cin>>phone;
              cout<<"\n\n From : ";
              cin>>from;
              cout<<"\n\n To : ";
              cin>>to;
              cout<<"\n\n Single seat amount : ";
              cin>>s_amount;
              total_amount = s_amount*i;
              cout<<"\n\n Total amount : "<<total_amount;
              cout<<"\n\n Received amount : ";
              cin>>r_amount;
              file.open("customer.txt",ios::app|ios::in);
              file<<customer_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<"\n";
              file.close();
              system("cls");
              cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
              cout<<"\n\n\t\t**************************************";
              cout<<"\n\n\t\t _______ Booking Information _______";
              cout<<"\n\n\t\t**************************************";
              cout<<"\n\n\t\tName :                 "<<customer_name;
              cout<<"\n\t\tFrom :                   "<<from;
              cout<<"\n\t\tTo :                     "<<to;
              cout<<"\n\t\tTotal Seats :            "<<i;
              cout<<"\n\t\tReserved Seats :         ";
              for(int a=0;a<i;a++)
              {
                  if(a != 0)
                  cout<<",";
                  cout<<ss_no[a];
              }
              cout<<"\n\t\tSingle Seat Amount :     "<<s_amount;
              cout<<"\n\t\tTotal Amount :           "<<total_amount;
              cout<<"\n\t\tAmount Received :        "<<r_amount;
              cout<<"\n\t\tReturn Amount :          "<<r_amount-total_amount;
              cout<<"\n\n\t\t**************************************";
              cout<<"\n\n\t\t    Thank You";
              cout<<"\n\n\t\t**************************************";
          }
          else{
            cout<<"\n\n Bus no. is invalid...please try again...";
            getch();
            goto p;
          }
        }
    }
	void bus::renew_bus()
    {
        system("cls");
        fstream file;
        char x;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("seat.txt,ios::in");
        if(!file)
        {
            cout<<"\n\n File opening error...";
        }
        else
        {
            cout<<"\n\n Do you want to renew all the seats? (Y,N) : ";
            cin>>x;
            if(x == 'Y' || x == 'y')
            {
                remove("seat.txt");
                cout<<"\n\n\t\t\t All seats are renewed...";
            }
            else
            {
                cout<<"\n\n\t\t\t Thank you All seats reservation saved...";
            }
        }
    }
    void bus::search_booking()
    {
        system("cls");
        fstream file;
        int t_seats,t_amo,found=0;
        string name,no,phone,t_name;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("customer.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error....";
        }
        else
        {
            cout<<"\n\n Customer name : ";
            cin>>t_name;
            file>>name>>no>>phone>>t_seats>>t_amo;
            while(!file.eof())
            {
                if(t_name == name)
                {
                    if(found ==0)
                    {
                        system("cls");
                        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
                    }
                    cout<<"\n\n\n Customer name : "<<name;
                    cout<<"\n\n Bus no. : "<<no;
                    cout<<"\n\n Phone no. : "<<phone;
                    cout<<"\n\n Reserved seats : "<<t_seats;
                    cout<<"\n\n Total amount : "<<t_amo;
                    cout<<"\n\n===============================";
                    found++;
                }
                file>>name>>no>>phone>>t_seats>>t_amo;
            }
            file.close();
            if(found == 0)
            {
                cout<<"\n\n Customer name is invalid...";
            }
        }
    }
    void bus::update_booking()
    {
        system("cls");
        fstream file,file1;
        int t_seats,t_amo,found=0,del_seats,i=0;
        string name,no,phone,t_phone,del_no;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("customer.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error...";
        }
        else
        {
            cout<<"\n\n Phone no. : ";
            cin>>t_phone;
            file>>name>>no>>phone>>t_seats>>t_amo;
            while(!file.eof())
            {
                if(t_phone == phone)
                {
                    file.close();
                    file.open("customer.txt",ios::in);
                    file1.open("customer1.txt",ios::app|ios::out);
                    file>>name>>no>>phone>>t_seats>>t_amo;
                    while(!file.eof())
                    {
                        if(t_phone == phone)
                        {
                            del_no = no;
                            del_seats = t_seats;
                        }
                        if(t_phone != phone)
                        {
                           file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
                        }
                        file>>name>>no>>phone>>t_seats>>t_amo;
                    }
                    file.close();
                    file1.close();
                    remove("customer.txt");
                    rename("customer1.txt","customer.txt");
                    file.open("seat.txt",ios::in);
                    file1.open("seat1.txt",ios::app|ios::out);
                    file>>no>>t_seats;
                    while(!file.eof())
                    {
                        if(!(del_no == no && i < del_seats))
                        {
                            file1<<no<<" "<<t_seats<<"\n";
                        }
                        file>>no>>t_seats;
                    }
                    file.close();
                    file1.close();
                    remove("seat.txt");
                    rename("seat1.txt","seat.txt");
                    booking();
                    cout<<"\n\n\t\t\t Bookings updated successfully...";
                    found++;
                    goto h;
                }
                file>>name>>no>>phone>>t_seats>>t_amo;
            }
            file.close();
            h:
            if(found == 0)
            {
                cout<<"\n\n Phone no. is invalid...";
            }
        }
    }
    void bus::del_booking()
    {
       system("cls");
        fstream file,file1;
        int t_seats,t_amo,found=0,del_seats,i=0;
        string name,no,phone,t_phone,del_no;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("customer.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error...";
        }
        else
        {
            cout<<"\n\n Phone no. : ";
            cin>>t_phone;
            file>>name>>no>>phone>>t_seats>>t_amo;
            while(!file.eof())
            {
                if(t_phone == phone)
                {
                    file.close();
                    file.open("customer.txt",ios::in);
                    file1.open("customer1.txt",ios::app|ios::out);
                    file>>name>>no>>phone>>t_seats>>t_amo;
                    while(!file.eof())
                    {
                        if(t_phone == phone)
                        {
                            del_no = no;
                            del_seats = t_seats;
                        }
                        if(t_phone != phone)
                        {
                           file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
                        }
                        file>>name>>no>>phone>>t_seats>>t_amo;
                    }
                    file.close();
                    file1.close();
                    remove("customer.txt");
                    rename("customer1.txt","customer.txt");
                    file.open("seat.txt",ios::in);
                    file1.open("seat1.txt",ios::app|ios::out);
                    file>>no>>t_seats;
                    while(!file.eof())
                    {
                        if(!(del_no == no && i < del_seats))
                        {
                            file1<<no<<" "<<t_seats<<"\n";
                        }
                        file>>no>>t_seats;
                    }
                    file.close();
                    file1.close();
                    remove("seat.txt");
                    rename("seat1.txt","seat.txt");
                    cout<<"\n\n\t\t\t Bookings deleted successfully...";
                    found++;
                    goto h;
                }
                file>>name>>no>>phone>>t_seats>>t_amo;
            }
            file.close();
            h:
            if(found == 0)
            {
                cout<<"\n\n Phone no. is invalid...";
            }
        }
    }
    void bus::show_booking()
    {
       system("cls");
        fstream file;
        int t_seats,t_amo,found=0;
        string name,no,phone;
        cout<<"\n\t\t _______ BUS MANAGEMENT SYSTEM _______";
        file.open("customer.txt",ios::in);
        if(!file)
        {
            cout<<"\n\n File opening error....";
        }
        else
        {
            file>>name>>no>>phone>>t_seats>>t_amo;
            while(!file.eof())
            {
                cout<<"\n\n\n Customer name : "<<name;
                cout<<"\n\n Bus no. : "<<no;
                cout<<"\n\n Phone no. : "<<phone;
                cout<<"\n\n Reserved seats : "<<t_seats;
                cout<<"\n\n Total amount : "<<t_amo;
                cout<<"\n\n===============================";
                found++;
                file>>name>>no>>phone>>t_seats>>t_amo;
            }
            file.close();
            if(found == 0)
            {
                cout<<"\n\n Booking record not found...";
            }
        }
    }
main()
{
    bus b;
    p:
    system("cls");
    string email,pass;
    char ch;
    cout<<"\n\n\t\t\t***** Security Are Required *****";
    cout<<"\n\n Email: ";
    cin>>email;
    cout<<"\n\n Password: ";
    for(int i=0;i<3;i++)
    {
       ch=getch();
       pass += ch;
       cout<<"*";
    }
    if(email == "abc@gmail.com" && pass == "abc")
    {
        cout<<"\n\n\n\t\t\t Loading...";
        for(int i=0;i<=2;i++)
        {
            Sleep(500);
            cout<<".";
        }
        b.menu();
    }
    else
    {
        cout<<"\n\n\t\t Your Email & Password is Wrong...";
        getch();
        goto p;
        }
}
