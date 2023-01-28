#include<bits/stdc++.h>
#include<fstream>
#include<string>
using namespace std;
class Node
{
public:
    Node *next;
    Node *prev;
    Node *head = NULL;
    int seat[10][7],row,col;
    string name,pass;
    Node()
    {
        memset(seat,0,sizeof(seat));
    }
    void nodi()
    {
        memset(seat,0,sizeof(seat));
    }

    void display()
    {
        cout<<"\nFollowing are the seats"<<endl;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<7;j++)
                {if(seat[i][j]==0)
                cout<<"\t| |";
                else cout<<"\t|B| ";
                }
                cout<<endl;

        }
    }
    void book_seat()
    {
        Node *temp = new Node;
        Node *start = head;
        //cout<<"\nenter user name: and password";
        //cin>>temp->name>>temp->pass;
        cout<<"\nSelect from the given seats";
        display();
        cin>>temp->row>>temp->col;
        if(temp->row<0 || temp->row>10 || temp->col<0 || temp->col>7)
        {
            cout<<"no such seat exists";
            exit(0);
        }
        cout<<"\nDetails: \n";
        cout<<temp->name<<" "<<temp->row<<" "<<temp->col;
        seat[temp->row][temp->col]=1;
        if(head==NULL)
        {
            head = start=temp;
            start->next=NULL;
            start->prev=NULL;
        }
        cout<<"\ncheck1";
        while(start->next!=NULL)
        {
            start=start->next;
        }
        cout<<"\ncheck2";
        start->next=temp;
        temp->prev=start;
        start = temp;
        start->next=NULL;
        display();
    }
    void cancel()
    {
        /*if(head==NULL)
        {
            cout<<"no tickets booked ";
            exit(1);
        }*/
        cout<<"enter the user name and password";
        string user,pas;
        cin>>user>>pas;
        Node * start ;
        start  = head;
        if(head==NULL)

        while(start->name!=user)
        {
            start = start->next;
        }
        if(start==NULL)
        {
            cout<<"no such user exists";
            exit(0);
        }
        if(start->pass==pas)
        {
            seat[start->row][start->col] =0;
            start = NULL;
            cout<<"cancellation successful";
        }
        else cout<<"invalid user\ password";

        display();


    }

void checkout(string na)
{
    int tic =0;
    Node* start = head;

    while(start->next!=NULL)
    {
        if(start->name == na)
            tic++;
    }
    if(head->next==NULL && head->name == na)
        tic++;

    cout<<tic;
}

}obj[10];
class BookMovie
{
public:
void Insert()
{
    system("cls");
    string name;
    int id;
    cout<<"Enter Movie Name : ";
    cin>>name;
    cout<<"Enter Movie-ID : ";
    cin>>id;
    ofstream file;
    file.open("movies.txt",ios::app);
    file<<id<<"\t"<<name<<"\n";
    file.close();
    cout<<"Successfully Entered\n";
}
void Display()
{
    system("cls");
    ifstream file;
    int N=200;
    char line[N];
    file.open("movies.txt");
    while(file)
    {
        file.getline(line,N);
        cout<<line<<"\n";
    }
}
void FirstPage()
{
    system("cls");
    cout<<"\t---------WELCOME---------\n";
    cout<<"\t1.Admin Profile\n\t2.SignUp\n\t3.Login\n";
    cout<<"\tEnter your choice : ";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1: this->Admin();
            break;
        case 2: this->SignUp();
            break;
        case 3: this->Login();
            break;
        default: this->FirstPage();
            break;
    }
}
void MovieFunction()
{
    system("cls");
    cout<<"1.Insert Movie"<<endl<<"2.Exit";
    cout<<"\nEnter your choice : ";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1: this->Insert();
                system("PAUSE");
                this->MovieFunction();
            break;
        /*case 2: this->Delete();
                system("PAUSE");
                this->Admin();
            break;*/
        case 2: break;
        default:this->Admin();
            break;
    }
    system("PAUSE");
    FirstPage();
}
void Admin()
{
    system("cls");
    string  password,ps="admin";
    cout<<"Enter password : ";
    cin>>password;
    if(password==ps)
    {
        cout<<"Logged IN\n";
        system("PAUSE");
        MovieFunction();
    }
    else
    {
        cout<<"Invalid\n";
        system("PAUSE");
        FirstPage();
    }
}
void SignUp()
{
    system("cls");
    cout<<"\t---------SIGN-UP---------\n";
    string email,password,name;
    cout<<"Enter your name : ";
    cin>>name;
    cout<<"Enter your Email-ID : ";
    cin>>email;
    cout<<"Enter your password : ";
    cin>>password;
    string filename = email+".txt";
    ofstream file;
    file.open(filename.c_str());
    file<<email<<endl<<password<<endl<<name<<"\n";
    file.close();
    cout<<"Successfully Registered";
    system("PAUSE");
    FirstPage();
}
void Login()
{
    system("cls");
    cout<<"\t---------LOGIN---------\n";
    string email,password,em,ps,name;
    cout<<"Enter your Email-ID : ";
    cin>>email;
    cout<<"Enter your password : ";
    cin>>password;
    string filename = email+".txt";
    ifstream read(filename.c_str());
    getline(read,em);
    getline(read,ps);
    getline(read,name);
    if(email==em && password==ps)
    {
        cout<<"Successfully Logged In\n";
        system("PAUSE");
        this->Book(email);
    }
    else
    {
        cout<<"Invalid";
        system("PAUSE");
        this->FirstPage();
    }
}
void TicketId(int n)
{

}
void BookTicket(string email)
{
    system("cls");
    int id,n;
    cout<<"\t---------BOOK TICKET---------\n";
    cout<<"\tEnter Movie-ID : ";
    cin>>id;
    cout<<"Enter number of seats to be booked ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        obj[id].book_seat();
    }
    //Node n;
    //n.display();
    obj[id].display();
    /*cout<<"select from the given menu:\n1)show available seats\n2)book seats\n3)cancel ticket; \nCheckout";
    int choice;
    //cin>>choice;
    char more='y';
    while(more=='y')
    {   cin>>choice;
        switch(choice)
    {
        case 1: display();
        case 2: book_seat();break;
        case 3: cancel();break;
        case 4: cout<<"enter name for checkout: ";
            string name;
            cin>>name;
            checkout(name);break;
    }
    cout<<"\nWant to repeat? ";
    cin>>more;
    }*/
    //cout<<"\tEnter no. of seats : ";
    //cin>>n;
    string filename = email+".txt";
    ofstream file;
    file.open(filename.c_str(),ios::app);
    file<<n<<"\n";
    file.close();
    system("PAUSE");
}
void CancelTicket(string email, int id)
{
    obj[id].nodi();
    cout<<"Tickets cancelled for movie with id: "<<id;

}
void Book(string email)
{
    system("cls");
    cout<<"\t---------BOOK MY SHOW---------\n";
    cout<<"\t1.Show Movies\n\t2.Book Ticket\n\t3.Cancel Ticket\n\t4.Logout\n";
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1: Display();
            system("PAUSE");
            this->Book(email);
            break;
        case 2: BookTicket(email);
            system("PAUSE");
            this->Book(email);
            break;
        case 3: cout<<"\n Enter movie id ";
            int id;
            cin>>id;
            CancelTicket(email,id);
            system("PAUSE");
            this->Book(email);
        case 4:break;
        default:this->Book(email);
    }
    system("PAUSE");
    this->FirstPage();
}
};
int main()
{
    BookMovie obj;
    obj.FirstPage();
}

