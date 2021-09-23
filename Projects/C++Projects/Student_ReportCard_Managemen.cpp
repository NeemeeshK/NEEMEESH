#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include <string>
using namespace std;

class student               //class used in project
{
    int rollno;
    char name[50];
    int pm,lam,beem,fpm, csm, lrm, egmwm, ewesm;
    float per;
    char grade[20];
    int std;
    void calculate(){
        per=(pm+egmwm+lam+beem+fpm+csm+lrm+ewesm)*100/625;
        if(per>=75){
            char temp[20]="Distinction";
            for(int i=0;i<20;i++)
            grade[i]=temp[i];
        }
        else if(per>=60 && per<75){
            char temp[20]="1st Class";
            for(int i=0;i<20;i++)
            grade[i]=temp[i];
        }
        else if(per>=50 && per<60){
            char temp[20]="2nd Class";
            for(int i=0;i<20;i++)
            grade[i]=temp[i];
        }
        else if(per>=40 && per<50){
            char temp[20]="Pass";
            for(int i=0;i<20;i++)
            grade[i]=temp[i];
        }
        else{
            char temp[20]="Fail";
            for(int i=0;i<20;i++)
            grade[i]=temp[i];
        }
    }
public:
    void getdata(){
    	cout<<"\nEnter The roll number of student ";
        cin>>rollno;
        cin.ignore();
        cout<<"\nEnter The Name of student ";
        cin.getline(name,49);
        cout<<"\nEnter The marks in Physics out of 125 : ";
        cin>>pm;
        cout<<"\nEnter The marks in Linear Algebra out of 125 : ";
        cin>>lam;
        cout<<"\nEnter The marks in BEE out of 125 : ";
        cin>>beem;
        cout<<"\nEnter The marks in Fundamentals of Programming out of 125 : ";
        cin>>fpm;
        cout<<"\nEnter The marks in EGMW out of 50 : ";
        cin>>egmwm;
        cout<<"\nEnter The marks in Computational Science out of 25 : ";
        cin>>csm;
        cout<<"\nEnter The marks in EWES out of 25 : ";
        cin>>ewesm;
        cout<<"\nEnter The marks in Logical Reasoning out of 25 : ";
        cin>>lrm;
        calculate();
    }

    void showdata(){
        cout<<"\nRoll number of student : "<<rollno;
        cout<<"\nName of student : "<<name;
        cout<<"\nMarks in Physics : "<<pm;
        cout<<"\nMarks in Linear Algebra : "<<lam;
        cout<<"\nMarks in BEE : "<<beem;
        cout<<"\nMarks in Fundamentals of Programming : "<<fpm;
        cout<<"\nMarks in EGMW :"<<egmwm;
        cout<<"\nMarks in Computational Science :"<<csm;
        cout<<"\nMarks in EWES :"<<ewesm;
        cout<<"\nMarks in Logical Reasoning :"<<lrm;
        cout<<"\nPercentage of student is  :"<<setprecision(2)<<per;
        cout<<"\nGrade of student is :"<<grade;
    }

     void show_tabular(){
        cout<<setw(8)<<rollno<<setw(20)<<name<<setw(6)<<pm<<setw(6)<<lam<<setw(6)<<beem<<setw(6)<<fpm<<setw(6)<<egmwm<<setw(6)<<csm<<setw(6)<<ewesm<<setw(6)<<lrm<<setw(8)<<per<<setw(12)<<grade<<"\n";
    }

    int  retrollno(){
        return rollno;
    }
}st;

fstream fp;

void write_student(){            //to get and save data
    fp.open("student.dat",ios::out|ios::app);
    st.getdata();
    fp.write((char*)&st,sizeof(student));
    fp.close();
    cout<<"\n\nstudent record Has Been Created ";
    getch();
}

void display_sp(int n){          //read and display data
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student))){
        if(st.retrollno()==n){
            system("cls");
            st.showdata();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\n\nrecord not exist";
    getch();
}

void modify_student(){           //to modify and write updated data after deleting previous
    int no,found=0;
    system("cls");
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tPlease Enter The roll number of student";
    cin>>no;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0){
        if(st.retrollno()==no){
            st.showdata();
            cout<<"\nPlease Enter The New Details of student"<<endl;
            st.getdata();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}

void delete_student(){           /*to delete existing record*/
    int no;
    system("cls");
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The roll number of student You Want To Delete";
    cin>>no;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student))){
        if(st.retrollno()!=no){
            fp2.write((char*)&st,sizeof(student));
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
}

void class_result(){         /*to display all data in table format*/
    system("cls");
    fp.open("student.dat",ios::in);
    if(!fp){
        cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
        cout<<"\n\n\n Program is closing ....";
        getch();
        exit(0);
    }

    cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
    cout<<"===================================================================================================\n";
    cout<<setw(8)<<"Roll No."<<setw(20)<<"Name        "<<setw(6)<<"P"<<setw(6)<<"LA"<<setw(6)<<"BEE"<<setw(6)<<"FP"<<setw(6)<<"EGMW"<<setw(6)<<"CS"<<setw(6)<<"EWES"<<setw(6)<<"LR"<<setw(8)<<"%age"<<setw(12)<<"Grade\n";
    cout<<"===================================================================================================\n";

    while(fp.read((char*)&st,sizeof(student))){
        st.show_tabular();
    }
    fp.close();
    getch();
}

void result(){           /*Result Menu*/
    int ans,rno;
    char ch;
    system("cls");
    cout<<"\n\n\nRESULT MENU";
    cout<<"\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu";
    cout<<"\n\n\nEnter Choice (1/2)? ";
    cin>>ans;
    switch(ans){
    case 1 :
        class_result();
        break;
    case 2 :
        do{
            system("cls");
            int ans;
            cout<<"\n\nEnter Roll Number Of Student : ";
            cin>>rno;
            display_sp(rno);
            cout<<"\n\nDo you want to See More Result (1/0)?";
            cin>>ans;
        }
        while(ans);

        break;
    case 3:
        break;
    default:
        cout<<"\a";
    }
}

void entry_menu(){           /*Main Entry Menu*/
    system("cls");
    char ch2;
    cout<<"\n\n\n\tENTRY MENU";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.SEARCH STUDENT RECORD ";
    cout<<"\n\n\t3.MODIFY STUDENT RECORD";
    cout<<"\n\n\t4.DELETE STUDENT RECORD";
    cout<<"\n\n\t5.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-5) ";
    cin>>ch2;
    switch(ch2){
    case '1':
        system("cls");
        write_student();
        entry_menu();
        break;
    case '2':
        int num;
        system("cls");
        cout<<"\n\n\tPlease Enter The roll number ";
        cin>>num;
        display_sp(num);
        entry_menu();
        break;
    case '3':
        modify_student();
        entry_menu();
        break;
    case '4':
        delete_student();
        entry_menu();
        break;
    case '5':
        break;
    default:
        entry_menu();
    }
}

int main(){
    char ch;
    do{
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. RESULT MENU";
        cout<<"\n\n\t02. ENTRY/EDIT MENU";
        cout<<"\n\n\t03. EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-3) ";
        cin>>ch;
        switch(ch){
        case '1':
            system("cls");
            result();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            exit(0);
        default :
            continue;
        }
    }
    while(ch!='3');
    return 0;
}