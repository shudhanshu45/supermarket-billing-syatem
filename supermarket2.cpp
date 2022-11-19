#include<iostream>
#include<fstream>
using namespace std;

class shopping{
private:
int pcode;
float price;
float dis;
string pname;
public:
 int stock[100];

void menu();
void administrator();
void buyer();
void add();
void edit();
void rem();
void list();
void receipt();
void edit2(int a , int b);

};

void shopping :: menu(){
    m :
    int choice;
    string email;
    string password;
    cout<<"\t\t\t...............\n";
    cout<<"\t\t\t                         \n";
   cout<<"\t\t\t\tSupermarket Main Menu  ";
   cout<<"\t\t\t\t...............\n";
  
  cout<<"\t\t\t\t | 1. Adminstrator  |\n";
  cout<<"\t\t\t\t | 2. Buyer         |\n";
  cout<<"\t\t\t\t | 3. Exit          |\n";
  cout<<"\t\t\t\t  Please select";
  cin>>choice;

switch(choice){
    case 1:
    
    cout<<"\t\t\t\t please Login"<<endl;
    cout<<"\t\t\t\t Enter Email"<<endl;
    cin>>email;
    cout<<"\t\t\t\t Password  \n"<<endl;
    cin>>password;
    if(email == "shudhanshu@gmail.com" && password =="007"){
        administrator();
    }
    else{
        cout<<"Invalid email/password";
    }
    break;

case 2:
  
      buyer();
      break;

  
  case 3:
  
      exit(0);
      break;
  

  default:
  
      cout<<"please select from the given option";
      break;
}

goto m;
}

void shopping:: administrator(){
    m:
    int choice;
    cout<<"\n\t\t Adminstrator menu";
    cout<<"\n\t\t...1)Add the product ...";
    cout<<"\n\t\t...2)Modify the product...";
     cout<<"\n\t\t...3)Delete the product...";
  cout<<"\n\t\t...4)Back to main menu...";
    cout<<"\n\t\t... Please enter your choice..."<<endl;
    cin>>choice;
    switch(choice){
        case 1:
          add();
          break;
         case 2:
         edit();
         break;
         case 3:
         rem();
         break;
         case 4:
         menu();
         break;
         default:
         cout<<"Invalid option selected ";

    }
      goto m;

}

void shopping::buyer(){
    m:
    int choice;
    cout<<"\t\t\t  Buyer \n";
    cout<<"\t\t\t.........\n";
    cout<<"            \n";
    cout<<"\t\t\t 1)Buy product\n";
    cout<<"                    \n";
    cout<<"\t\t\t 2) Go back       \n";
   cout<<"\t\t\t  Enter the choice ";
   cin>>choice;
   switch(choice){
      case 1:
      receipt();
      break;
      case 2:
      menu();
      break;
      default:
      cout<<"invalid choice"; 
      break;
   }
   goto m;

}
void shopping:: add(){
    m:
  fstream data;
  int c;
  int token =0;
  float p;
  float d;
  string n;
  int ss;

   cout<<"\n\n\n\t\t Add new product";
   cout<<"\n\n\t  Product code of the product ";
   cin>>pcode;
   stock[pcode] = 100;
   cout<<"\n\n Name of the product ";
   cin>>pname;
   cout<<"\n\n\t Price of the product ";
   cin>>price;
   cout<<"\n\n\t Discount on the product ";
   cin>>dis;
   data.open("database.txt" ,ios::in);
   if(!data){
       data.open("database.txt",ios::app|ios::out);
     data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<stock[pcode]<<"\n";
     data.close();
   }
   else{
     data>>c>>n>>p>>d>>ss; 
     while(!data.eof()){
         if(c== pcode){
             token++;
         }
         data>>c>>n>>p>>d>>ss;  
     }
     data.close();
   
   if(token ==1)
   goto m;
   else{
              data.open("database.txt",ios::app|ios::out);
     data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<stock[pcode]<<"\n";
     data.close();

       
   }

}
   cout<<"\n\n\trecord inserted";
}

void shopping::edit(){
    fstream data,data1;
    int pkey;
    int token =0;
    int c;
    float p;
    float d;
    int ss;
    string n;
    cout<<"\n\t\t Modify the record ";
    cout<<"\n\t\t product code ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\t file doesnot exist";
    }
    else{
     data1.open("database1.txt",ios::app|ios::out);
      data>>pcode>>pname>>price>>dis>>stock[pcode];
      while(!data.eof()){
          if(pkey==pcode){
              cout<<"\n\n\t Productnew code: ";
              cin>>c;
              cout<<"\n\t\t Name of the product : ";
              cin>>n;
              cout<<"\n\t\t Price: ";
              cin>>p;
              cout<<"\n\n\t discount: ";
              cin>>d;
              cout<<"\n\t\t quantity in Stock :";
              cin>>ss;
              data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" "<<ss<<"\n";
              cout<<"\n\n\t\t  Record edited ";
              token++;
          }
          else{
              data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<stock[pcode]<<"\n";

          }
          data>>pcode>>pname>>price>>dis>>stock[pcode];
      }
      data.close();
      data1.close();
       remove("database.txt");
       rename("database1.txt","database.txt");
       if(token ==0){
           cout<<"\n\n Record not found";
       }
    }
}

void shopping::rem(){
    fstream data , data1;
    int pkey;
    int token =0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\n Product code :";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data){
        cout<<"file does not exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis>>stock[pcode];
        while(!data.eof()){
            if(pcode == pkey){
                cout<<"\n\n\t Product deleted sucessfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<stock[pcode]<<"\n";

            }
            data>>pcode>>pname>>price>>dis>>stock[pcode];
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token ==0){
            cout<<"\n\n Record can not found ";
        }
    }

}

void shopping::list(){
    fstream data;
    data.open("database.txt" , ios::in);
    cout<<"\n\n|..........................\n";
    cout<<"ProNo\t\tName\t\tPrice\t\tStock";
    cout<<"\n\n|......................................\n";
    data>>pcode>>pname>>price>>dis>>stock[pcode];
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<stock[pcode]<<"\n";
        data>>pcode>>pname>>price>>dis>>stock[pcode];

    }
    data.close();
}

void shopping:: receipt(){
    m:
   fstream data;
   int arrc[100];
   int arrq[100];
   char choice;
   int c =0;
   float  amount=0 ;
   float dis =0;
   float total =0;
   cout<<"\n\n\n\n\t\t RECEIPT";
   data.open("database.txt",ios::in);
   if(!data){
       cout<<"\n\n\n Empty database";
   }
   else{
       data.close();
       list();
       cout<<"\n......................\n";
       cout<<"\n Please place the order \n";

       do{
           fstream data;
            data.open("database.txt" ,ios::in);
            data>>pcode>>pname>>price>>dis>>stock[pcode];
           cout<<"\n\n Enter product code :";
           cin>>arrc[c];
           cout<<"\n\n Enter the product quantity :";
           cin>>arrq[c];
    //pcode=c
           if(arrq[c] > stock[pcode]){
               cout<<" product is out of stock";
               goto m;
           }
           for(int i =0 ;i<c;i++){
               if(arrc[c]==arrc[i]){
                   cout<<"\n\n Duplicate Product Code . Please try again";
                   goto m;
               }
           }
           c++;
           cout<<"\n\n Do you want to buy another product? if yes then press y else n  ";
           cin>>choice;
           data.close();

       }
       while(choice =='y');

       cout<<"\n\n\t\t\t..............Reciept..................\n";
       cout<<"\n Product No. \t product name \t product Quantity \t price \t amount with discount  \n";
       for(int i= 0;i<c ;i++){
           data.open("database.txt",ios::in);
           data>>pcode>>pname>>price>>dis>>stock[pcode];
           while(!data.eof()){
               if(pcode == arrc[i]){
                                 // cout<<"\n\n"<<"pcode"<<pcode<<"\n\n";

                   amount = price*arrq[i];
                   dis = amount -(amount*dis /100);
                   stock[pcode] = stock[pcode] - arrq[i];
                                      //  cout<<"\n\n"<<"pcode"<<pcode<<"\n\n";

                   
                                      //  cout<<"\n\n"<<"pcode"<<pcode<<"\n\n";

                   total = total +dis;
        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<dis;   
           edit2( pcode,stock[pcode]);
               }
               data>>pcode>>pname>>price>>dis>>stock[pcode];
               
                 
           }
           data.close();
       }
     
   }
   cout<<"\n\n..........................";
   cout<<"\n Total Amount: "<<total;
}

void shopping::edit2( int a , int b){
    fstream data,data1;
    data.open("database.txt",ios::in);
    
     data1.open("database1.txt",ios::app|ios::out);
      data>>pcode>>pname>>price>>dis>>stock[pcode];
      while(!data.eof()){
          if(a==pcode){
              data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<b<<"\n";
          }
          else{
              data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" "<<stock[pcode]<<"\n";

          }
          data>>pcode>>pname>>price>>dis>>stock[pcode];
      }
      data.close();
      data1.close();
       remove("database.txt");
       rename("database1.txt","database.txt");
    }




int main(){
    shopping s ;
    s.menu();
}

  