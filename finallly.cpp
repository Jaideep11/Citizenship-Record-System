#include<iostream>
#include<vector>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <string>
#include <sstream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include"FSM_header.h"

//#include <string>
#include<string.h>
using namespace std;
string cnic;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

    
   void setCNIC(string CNIC)
   {
   	   cnic=CNIC;
   }
  string getCNIC()
   {
   	   return cnic;
   }
   
   void updateFile(char*);
   void newFile(char* v,int n){
    
//    cout<<endl<<v;
//	getch();
	
	string name;
	string fname;
		string address;
		string language;
		string cast;
		string gend;
		double mnum;
		string dob;
                		cout<<"\nEnter name: ";
                		cin>>name;
                		cout<<"\nEnter father's name: ";
                		cin>>fname;
						cout<<"Enter Your Mobile Number: ";
                		cin>>mnum;
                		cout<<"Enter the current address: ";
                		cin>>address;
                		cout<<"Enter the language: ";
                		cin>>language;
                		cout<<"Enter the cast: ";
                		cin>>cast;
                		cout<<"Enter Date of Birth: ";
                		cin>>dob;
	
	
	fstream file;
    
    file.open( v ,ios::out);
    updateFile(v);
	v[n] = v[n+1] = v[n+2] = v[n+3]=' ';
	if(!file)
    {
      cout<<"Error in creating file.."<<endl;
	  return ;
    }
    
	cout<<"\nFile created successfully."<<endl;

    file<<"Name:"<<name<<endl
		<<"Father Name:"<<fname<<endl
		<<"CNIC:"<<v<<endl
		<<"Date of birth:"<<dob<<endl
		<<"Mobile Number:"<<mnum<<endl
		<<"current address:"<<address<<endl
		<<"cast:"<<cast<<endl
		<<endl<<"----"<<endl;

    file.close();
    cout<<"\nFile saved and closed succesfully."<<endl;
//    getch();
}

void updateFile(char *allfamily){
	fstream file;
    file.open("allfamily.txt", ios::app);
    if(!file)
    {
      cout<<"Error in creating file.."<<endl;
	  return ;
    }
    
	cout<<"\nFile created successfully."<<endl;
	
    file<<allfamily<<endl;
    
    file.close();
    cout<<"\nFile saved and closed succesfully."<<endl;
}


void updateFile(char *value,int n2,char *CNICno){
	fstream file;
	cout<<"Vlue =>  "<<value;
	getch();
	
	char murge[n2+4];
	
	for(int i=0;i<n2;i++){
		murge[i]=value[i];
	}
	murge[n2] ='.';
	murge[n2+1]='t';
	murge[n2+2]='x';
	murge[n2+3]='t';
	murge[n2+4]=' ';
	murge[n2+5]=' ';
    
    file.open(murge, ios::app);
    if(!file)
    {
      cout<<"Error in creating file.."<<endl;
	  return ;
    }
    
	cout<<"\nFile created successfully."<<endl;
	
    file<<CNICno<<endl;
    
    file.close();
    cout<<"\nFile saved and closed succesfully."<<endl;
}


void newFile(char* v,string pCNIC,int n){
    
   string name;
	string fname;
		string address;
		string language;
		string cast;
		string gend;
		string mnum;
		string dob;
                		cout<<"\nEnter name: ";
                		cin>>name;
                		cout<<"\nEnter father's name: ";
                		cin>>fname;
						cout<<"Enter Your Mobile Number: ";
                		cin>>mnum;
                		cout<<"Enter the current address: ";
                		cin>>address;
                		cout<<"Enter the language: ";
                		cin>>language;
                		cout<<"Enter the cast: ";
                		cin>>cast;
                		cout<<"Enter Date of Birth: ";
                		cin>>dob;
	 
    
    
    
    
    int nn = pCNIC.length();
		char key[n+3];
		
		strcpy(key, pCNIC.c_str());
		key[nn]='.';
		key[nn+1]='t';
		key[nn+2]='x';
		key[nn+3]='t';
		key[nn+4]=' ';
		key[nn+5]=' ';
		cout<<endl<<key<<endl;
		
		
//   cout<<endl<<v;
//	getch();
	
	fstream file;
	updateFile(v);
	file.open( v ,ios::out);
    v[n] = v[n+1] = v[n+2] = v[n+3]=' ';
	if(!file)
    {
      cout<<"Error in creating file.."<<endl;
	  return ;
    }
    
	cout<<"\nFile created successfully."<<endl;
 
    file<<"Name:"<<name<<endl
		<<"Father Name:"<<fname<<endl
		<<"CNIC:"<<v<<endl
		<<"Date of birth:"<<dob<<endl
		<<"Mobile Number:"<<mnum<<endl
		<<"current address:"<<address<<endl
		<<"cast:"<<cast<<endl
		<<endl<<"----"<<endl;

    file.close();
    cout<<"\nFile saved and closed succesfully."<<endl;
	
//	updateFile(pCNIC,key);
	cout<<"Update done! \n";
}


//bool updateFile(char  *value,string * childCNIC){
////	char idd[20];
////	for(int i=0;value[i]!=' ';i++){
////		idd[i]=value[i];
////	}
//	
//	
//	cout<<endl<<*value;
//	fstream file;
////	<<endl<<endl<<childCNIC<<endl;
//    getch();
//    file.open(value, ios::out);
//    if(!file)
//    {
//      cout<<"Error in creating file.."<<endl;
//	  return false;
//    }
//    
//	cout<<"\nFile created successfully."<<endl;
// 
//    file<<"\nCNIC: "<<*childCNIC<<endl;
//
//    file.close();
//    cout<<"\nFile saved and closed succesfully."<<endl;
//    
//    return true;
//}


void addChildInParentFile(char * value){
	fstream file;
    
    file.open(value ,ios::app);
    if(!file)
    {
      cout<<"Error in creating file.."<<endl;
	  return ;
    }
    
	cout<<"\nFile created successfully."<<endl;
 
    file<<"CNIC"<<endl;

    file.close();
    cout<<"\nFile saved and closed succesfully."<<endl;
}


void modifyFile(char * value){
	 fstream readFile(value);
     string readout;
     string search="Name : ";
     string Fname;
     string Lname;

     cout<<"Enter id which you want Modify: ";
//     cin>>search;
     
//     se

     while(getline(readFile,readout)){
        if(readout == search){
           /*
                id remain same (does not change)
                But First name and Last name replace with
                user Fname and Lname
           */
            cout<<"Enter new First name";
                 cin>>Fname;
            cout<<"Enter Last name";
                 cin>>Lname;  
        }
    }
	
}


void deleteFile(char *value){
	if (remove(value) == 0) 
      printf("Deleted successfully"); 
   else
      printf("Unable to delete the file");
      
    cout<<endl;
}

void readFile(char *v){
	string myText;
	ifstream MyReadFile(v);
	
	
	if(!v){
		cout<<"Invlid CNIC: "<<v;
		return;
	}
	
	int k=1;
	while (getline (MyReadFile, myText)) {
	  if(myText=="----"){
//		getch();
//		k=0;
		break;
	  }
	  cout << myText<<endl;
	}

	MyReadFile.close();
}

void readFile(char v[],int n){
	v[n]='.';
	v[n+1]='t';
	v[n+2]='x';
	v[n+3]='t';
	v[n+4]=' ';
	v[n+5]=' ';
				
	string myText;
	ifstream MyReadFile(v);
	
	v[n] = v[n+1] = v[n+2] = v[n+3]=' ';
	
	
	if(!v){
		cout<<"Invlid CNIC: "<<v;
		return;
	}
	
	bool k = true;
	while (getline (MyReadFile, myText)) {
	   if(myText == "----"){
	   	   k = false;
	   }
	   else if(myText != "----" && k){
	      cout << myText<<endl;
	      
	  }
	   else {
	   	  int n = myText.length();
	  	  char newV[n];
	  	   strcpy(newV,myText.c_str());
	  	   readFile(newV);
	   }
	}

	MyReadFile.close();
}
   
   
   
   
   
int gender()
{

int result, digitIndex, curDigit;
int resultNum;
int numResultsWanted = 10;

// init rand seed
srand(time(NULL));


result = 0;
for (digitIndex=0; digitIndex<1; digitIndex++)
{
curDigit = rand() % 10;
curDigit *= pow(10, digitIndex);
result += curDigit;
}
 return  result;
}

int random()
{

int result, digitIndex, curDigit;
int resultNum;
int numResultsWanted = 10;

// init rand seed
srand(time(NULL));


result = 0;
for (digitIndex=0; digitIndex<6; digitIndex++)
{
curDigit = rand() % 10;
curDigit *= pow(10, digitIndex);
result += curDigit;
}
 return  result;
}
int Isdigit(char a)
{
 int R=0;
	if(a=='1')
	{
		R=R*10+1;
	}
		if(a=='2')
	{
		R=R*10+2;
	}
		if(a=='3')
	{
		R=R*10+3;
	}
		if(a=='4')
	{
		R=R*10+4;
	}
		if(a=='5')
	{
		R=R*10+5;
	}
		if(a=='6')
	{
		R=R*10+6;
	}
		if(a=='7')
	{
		R=R*10+7;
	}	if(a=='8')
	{
		R=R*10+8;
	}
		if(a=='9')
	{
		R=R*10+9;
	}
		if(a=='0')
	{
		R=R*10+0;
	}
	
	return R;
}
int Tehsil(string name)
{
	if(name=="Chitral")
	{
		return 1;
	 } 
      if(name=="Mastuj")
      {
      	return 2;
	  }
	  if(name=="Dir")
	  {
	  	return 1;
	   } 
       if(name=="Shringal")
       {
       	return 2;
	   }
      if(name=="Wari")
      {
      	return 3;
	  }
	  if(name=="Temergara")
	  {
	  	return 1;
	  }
	  if(name=="Adenzai")
	  {
	  	return 2;
	   }
	   if(name=="Lal_Qilla")
	   {
	   	return 3;
		} 
		if(name=="Samarbagh")
	   {
	   	return 4;
		} 
		if(name=="Daggar")
	   {
	   	return 1;
		} 
		if(name=="Gagra")
	   {
	   	return 2;
		} 
		if(name=="Khado_Khel")
	   {
	   	return 3;
		} if(name=="Mandanr")
	   {
	   	return 4;
		} 
		if(name=="Babuzai")
	   {
	   	return 1;
		} 
		if(name=="Bari_Kot")
	   {
	   	return 2;
		} 
		if(name=="Kabal")
	   {
	   	return 3;
		} 
		if(name=="Matta")
	   {
	   	return 4;
		} 
			if(name=="Khawaza_Khela")
	   {
	   	return 5;
		} 
			if(name=="*Charbagh")
	   {
	   	return 6;
		} 
			if(name=="Behrain")
	   {
	   	return 7;
		}
			if(name=="Alpuri")
	   {
	   	return 1;
		}
			if(name=="Besham")
	   {
	   	return 2;
		}
			if(name=="Puran")
	   {
	   	return 3;
		}
			if(name=="Swat_Ranizai")
	   {
	   	return 1;
		}
			if(name=="Sam_Ranizai")
	   {
	   	return 2;
		}
			if(name=="Dassu")
	   {
	   	return 1;
		}
			if(name=="Pattan")
	   {
	   	return 2;
		}
			if(name=="Palas")
	   {
	   	return 3;
		}
			if(name=="Kandia")
	   {
	   	return 4;
		}
				if(name=="Batagram")
	   {
	   	return 1;
		}
				if(name=="Allai")
	   {
	   	return 2;
		}
					if(name=="Mansehra")
	   {
	   	return 1;
		}
					if(name=="Oghi")
	   {
	   	return 2;
		}
					if(name=="Balakot")
	   {
	   	return 3;
		}
						if(name=="Judba")
	   {
	   	return 1;
		}
						if(name=="Khande")
	   {
	   	return 2;
		}
						if(name=="Abbottabad")
	   {
	   	return 1;
		}
						if(name=="Havelian")
	   {
	   	return 1;
		}
						if(name=="Haripur")
	   {
	   	return 2;
		}
						if(name=="Ghazi")
	   {
	   	return 3;
		}
						if(name=="Mardan")
	   {
	   	return 1;
		}
						if(name=="Katlang")
	   {
	   	return 2;
		}
						if(name=="Takht_Bhai ")
	   {
	   	return 3;
		}
						if(name=="Swabi")
	   {
	   	return 1;
		}
						if(name=="Topi")
	   {
	   	return 2;
		}
						if(name=="Lahor")
	   {
	   	return 3;
		}
						if(name=="Rzzar")
	   {
	   	return 4;
		}
						if(name=="Charsadda")
	   {
	   	return 1;
		}
						if(name=="Tangi")
	   {
	   	return 2;
		}
		if(name=="Shabqadar")
	   {
	   	return 3;
		}
		if(name=="Peshawar")
	   {
	   	return 1;
		}					if(name=="Nowshera")
	   {
	   	return 1;
		}					if(name=="Jehangira")
	   {
	   	return 2;
		}					if(name=="Pabbi") 
	   	return 3;
							if(name=="Kohat")
	   {
	   	return 1;
		}
			if(name=="Lachi")
	   {
	   	return 2;
		}
			if(name=="Hangu")
	   {
	   	return 1;
		}	if(name=="Tall")
	   {
	   	return 2;
		}	if(name=="Karak")
	   {
	   	return 1;
		}	if(name=="Banda_Daud_Shah")
	   {
	   	return 2;
		}	if(name=="Takht-e-Nasriti")
	   {
	   	return 3;
		}	if(name=="Bannu")
	   {
	   	return 1;
		}	if(name=="Domel")
	   {
	   	return 1;
		}	if(name=="Lakki_Marwat")
	   {
	   	return 1;
		}
		if(name=="Naurang")
	   {
	   	return 2;
		}
		
		if(name=="D.I.Khan")
	   {
	   	return 1;
		}
		if(name=="Daraban")
	   {
	   	return 2;
		}
		if(name=="Kulachi")
	    {
	   	return 3;
		}
		if(name=="Paroa")
	    {
	   	return 4;
		}
		if(name=="Tank")
	   {
	   	return 1;
		}
		else
		{
				
		return 0;
	   }
}
int district(string name)
{
	if(name=="CHITRAL")
	{
	     return 1;	
	} 
	if(name=="UPPER_DIR")
	{
		 return 2;	
	}
	if(name=="LOWER_DIR")
	{
		 return 3;	
	}
	if(name=="BUNER")
	{
		 return 4;	
	} 
	if(name=="SWAT")
	{
		 return 5;	
	}
	if(name=="SHANGLA")
	{
		 return 6;	
	}
	if(name=="MALAKAND"||name=="11")
	{
		 return 7;	
	}
	if(name=="KOHISTAN"|| name=="12") 
	{
		 return 8;	
	}
	if(name=="BATAGRAM")
	{
		 return 9;	
	} 
	if(name=="MANSEHRA")
	{
		return 10;
	 }
	  
    if(name=="TORGHAR")
    {
    	return 11;
	}
	if(name=="ABBOTTABAD")
	{
		 return 12;	
	}
	if(name=="HARIPUR") 
	{
		 return 13;	
	}
	if(name=="MARDAN")
	{
		 return 14;	
	 } 
	if(name=="SWABI")
	{
		 return 15;	
	 } 
	 
	if(name=="CHARSADDA")
	{
		 return 16;	
	 } 
	if(name=="PESHAWAR")
	{
		 return 17;	
	 } 
	if(name=="NOWSHERA")
	{
		 return 18;	
	 }
	  
	if(name=="KOHAT")
	{
		 return 19;	
	 }
	 if(name=="HANGU")
	 {
	 	 return 20;	
	  }
	  if(name=="KARAK")
	  {
	  	  return 21;	
		}
		  
	if(name== "BANNU")
	{
		 return 22;	
	}
	if(name=="LAKKI_MARWAT")
	{
		 return 23;	
	}
	if(name=="D.I.KHAN")
	{
		 return 24;	
	}
	if(name== "TANK")
	{
		 return 25;	
	}
	else
	{
	
	return 0;
  }
}

int division( string name)
{
    if(name =="MALAKAND" || name == "11")
    { 
        string name;
    	cout<<"enter the district name: ";
    	cin>>name;
    	if(district(name)==0)
    	{
    		
    		
    		do
    		{
    			cout<<"invalid district";
    				cout<<"\nenter the district name: ";
                 	cin>>name;
                 	system("CLS");
			}
			while(district(name)==0);
		}
		
		
		
    	string tname;
    	cout<<"enter the tehsil: ";
    	cin>>tname;
    	 if(Tehsil(tname)==0)
    	 {
    	 	
    	 	do
    	 	{cout<<"invalid Tehsil";
    	 		cout<<"enter the tehsil: ";
    	        cin>>tname;
    	        system("CLS");
			 }
			 while(Tehsil(tname)==0);
		 }
		
		 
    	string gend;
    
    	  int  CNIC[13];
    	cout<<"enter the gender: ";
    	cin>>gend;
    	
    	int dis=district(name);
    	  CNIC[0]=Isdigit('1');
    	  CNIC[1]=Isdigit('1');
    	  CNIC[3]=(dis%10);
    	  CNIC[2]=(dis/10);
    	  CNIC[4]=Tehsil(tname);
	
    	 int num=random();
    	 int i=5;
    	 while (num!=0||i<=11)
       {
     	CNIC[i]=num%10;
	    num=num/10;
	    i++;
       }  
		
		 
    	if(gend=="male")
		{
			int g;
			do{
			
		      g=gender();
		     }
		     while(g!=1&&g!=3&&g!=5&&g!=7&&g!=9);
		     CNIC[12]=g;
	    }
	    else
	    {int g;
			do{
			
		      g=gender();
		     }
		     while(g!=2&&g!=4&&g!=6&&g!=8&&g!=0);
		     CNIC[12]=g;
		}
	
   
ostringstream strg;
string data;
for(int i=0;i<13;i++)
{
strg<< CNIC[i];	
string s1 = strg.str();

 data=s1;
}

setCNIC(data);

return true ;
}

	if(name=="HAZARA")
	{
		
        string name;
    	cout<<"enter the district name: ";
    	cin>>name;
    	if(district(name)==0)
    	{
    		
    		
    		do
    		{
    			cout<<"invalid district";
    				cout<<"\nenter the district name: ";
                 	cin>>name;
                 	system("CLS");
			}
			while(district(name)==0);
		}
		
		
		
    	string tname;
    	cout<<"enter the tehsil: ";
    	cin>>tname;
    	 if(Tehsil(tname)==0)
    	 {
    	 	
    	 	do
    	 	{cout<<"invalid Tehsil";
    	 		cout<<"enter the tehsil: ";
    	        cin>>tname;
    	        system("CLS");
			 }
			 while(Tehsil(tname)==0);
		 }
		
		 
    		 
    	string gend;
    
    	  int  CNIC[13];
    	cout<<"enter the gender: ";
    	cin>>gend;
    	
    	int dis=district(name);
    	  CNIC[0]=Isdigit('1');
    	  CNIC[1]=Isdigit('2');
    	  CNIC[3]=(dis%10);
    	  CNIC[2]=(dis/10);
    	  CNIC[4]=Tehsil(tname);
	
    	 int num=random();
    	 int i=5;
    	 while (num!=0||i<=11)
       {
     	CNIC[i]=num%10;
	    num=num/10;
	    i++;
       }  
		
		 
    	if(gend=="male")
		{
			int g;
			do{
			
		      g=gender();
		     }
		     while(g!=1&&g!=3&&g!=5&&g!=7&&g!=9);
		     CNIC[12]=g;
	    }
	    else
	    {int g;
			do{
			
		      g=gender();
		     }
		     while(g!=2&&g!=4&&g!=6&&g!=8&&g!=0);
		     CNIC[12]=g;
		}
	
   
   ostringstream strg;
string data;
for(int i=0;i<13;i++)
{
strg<< CNIC[i];	
string s1 = strg.str();

 data=s1;
}

setCNIC(data);


return true ;
		
	}
	if(name=="MARDAN")
	{
	
        string name;
    	cout<<"enter the district name: ";
    	cin>>name;
    	if(district(name)==0)
    	{
    		
    		
    		do
    		{
    			cout<<"invalid district";
    				cout<<"\nenter the district name: ";
                 	cin>>name;
                 	system("CLS");
			}
			while(district(name)==0);
		}
		
		
		
    	string tname;
    	cout<<"enter the tehsil: ";
    	cin>>tname;
    	 if(Tehsil(tname)==0)
    	 {
    	 	
    	 	do
    	 	{cout<<"invalid Tehsil";
    	 		cout<<"enter the tehsil: ";
    	        cin>>tname;
    	        system("CLS");
			 }
			 while(Tehsil(tname)==0);
		 }
		
		 
    	 
    	string gend;
    
    	  int  CNIC[13];
    	cout<<"enter the gender: ";
    	cin>>gend;
    	
    	int dis=district(name);
    	  CNIC[0]=Isdigit('1');
    	  CNIC[1]=Isdigit('3');
    	  CNIC[3]=(dis%10);
    	  CNIC[2]=(dis/10);
    	  CNIC[4]=Tehsil(tname);
	
    	 int num=random();
    	 int i=5;
    	 while (num!=0||i<=11)
       {
     	CNIC[i]=num%10;
	    num=num/10;
	    i++;
       }  
		
		 
    	if(gend=="male")
		{
			int g;
			do{
			
		      g=gender();
		     }
		     while(g!=1&&g!=3&&g!=5&&g!=7&&g!=9);
		     CNIC[12]=g;
	    }
	    else
	    {int g;
			do{
			
		      g=gender();
		     }
		     while(g!=2&&g!=4&&g!=6&&g!=8&&g!=0);
		     CNIC[12]=g;
		}
	
   
   ostringstream strg;
string data;
for(int i=0;i<13;i++)
{
strg<< CNIC[i];	
string s1 = strg.str();

 data=s1;
}

setCNIC(data);

return true ;	}
	if(name=="PESHAWAR")
	{

        string name;
    	cout<<"enter the district name: ";
    	cin>>name;
    	if(district(name)==0)
    	{
    		
    		
    		do
    		{
    			cout<<"invalid district";
    				cout<<"\nenter the district name: ";
                 	cin>>name;
                 	system("CLS");
			}
			while(district(name)==0);
		}
		
		
		
    	string tname;
    	cout<<"enter the tehsil: ";
    	cin>>tname;
    	 if(Tehsil(tname)==0)
    	 {
    	 	
    	 	do
    	 	{cout<<"invalid Tehsil";
    	 		cout<<"enter the tehsil: ";
    	        cin>>tname;
    	        system("CLS");
			 }
			 while(Tehsil(tname)==0);
		 }
		
		 
    	string gend;
    
    	  int  CNIC[13];
    	cout<<"enter the gender: ";
    	cin>>gend;
    	
    	int dis=district(name);
    	  CNIC[0]=Isdigit('1');
    	  CNIC[1]=Isdigit('4');
    	  CNIC[3]=(dis%10);
    	  CNIC[2]=(dis/10);
    	  CNIC[4]=Tehsil(tname);
	
    	 int num=random();
    	 int i=5;
    	 while (num!=0||i<=11)
       {
     	CNIC[i]=num%10;
	    num=num/10;
	    i++;
       }  
		
		 
    	if(gend=="male")
		{
			int g;
			do{
			
		      g=gender();
		     }
		     while(g!=1&&g!=3&&g!=5&&g!=7&&g!=9);
		     CNIC[12]=g;
	    }
	    else
	    {int g;
			do{
			
		      g=gender();
		     }
		     while(g!=2&&g!=4&&g!=6&&g!=8&&g!=0);
		     CNIC[12]=g;
		}
	
   
  ostringstream strg;
string data;
for(int i=0;i<13;i++)
{
strg<< CNIC[i];	
string s1 = strg.str();

 data=s1;
}

setCNIC(data);
return true ;
	}
	if(name=="KOHAT")
	{
	
        string name;
    	cout<<"enter the district name: ";
    	cin>>name;
    	if(district(name)==0)
    	{
    		
    		
    		do
    		{
    			cout<<"invalid district";
    				cout<<"\nenter the district name: ";
                 	cin>>name;
                 	system("CLS");
			}
			while(district(name)==0);
		}
		
		
		
    	string tname;
    	cout<<"enter the tehsil: ";
    	cin>>tname;
    	 if(Tehsil(tname)==0)
    	 {
    	 	
    	 	do
    	 	{cout<<"invalid Tehsil";
    	 		cout<<"enter the tehsil: ";
    	        cin>>tname;
    	        system("CLS");
			 }
			 while(Tehsil(tname)==0);
		 }
		
		 
    		string gend;
    
    	  int  CNIC[13];
    	cout<<"enter the gender: ";
    	cin>>gend;
    	
    	int dis=district(name);
    	  CNIC[0]=Isdigit('1');
    	  CNIC[1]=Isdigit('5');
    	  CNIC[3]=(dis%10);
    	  CNIC[2]=(dis/10);
    	  CNIC[4]=Tehsil(tname);
	
    	 int num=random();
    	 int i=5;
    	 while (num!=0||i<=11)
       {
     	CNIC[i]=num%10;
	    num=num/10;
	    i++;
       }  
		
		 
    	if(gend=="male")
		{
			int g;
			do{
			
		      g=gender();
		     }
		     while(g!=1&&g!=3&&g!=5&&g!=7&&g!=9);
		     CNIC[12]=g;
	    }
	    else
	    {int g;
			do{
			
		      g=gender();
		     }
		     while(g!=2&&g!=4&&g!=6&&g!=8&&g!=0);
		     CNIC[12]=g;
		}
	
   
    ostringstream strg;
string data;
for(int i=0;i<13;i++)
{
strg<< CNIC[i];	
string s1 = strg.str();

 data=s1;
}

setCNIC(data);

return true ;
	}
	if(name=="BANNU")
	{
	
        string name;
    	cout<<"enter the district name: ";
    	cin>>name;
    	if(district(name)==0)
    	{
    		
    		
    		do
    		{
    			cout<<"invalid district";
    				cout<<"\nenter the district name: ";
                 	cin>>name;
                 	system("CLS");
			}
			while(district(name)==0);
		}
		
		
		
    	string tname;
    	cout<<"enter the tehsil: ";
    	cin>>tname;
    	 if(Tehsil(tname)==0)
    	 {
    	 	
    	 	do
    	 	{cout<<"invalid Tehsil";
    	 		cout<<"enter the tehsil: ";
    	        cin>>tname;
    	        system("CLS");
			 }
			 while(Tehsil(tname)==0);
		 }
		
		 
    	string gend;
    
    	  int  CNIC[13];
    	cout<<"enter the gender: ";
    	cin>>gend;
    	
    	int dis=district(name);
    	  CNIC[0]=Isdigit('1');
    	  CNIC[1]=Isdigit('6');
    	  CNIC[3]=(dis%10);
    	  CNIC[2]=(dis/10);
    	  CNIC[4]=Tehsil(tname);
	
    	 int num=random();
    	 int i=5;
    	 while (num!=0||i<=11)
       {
     	CNIC[i]=num%10;
	    num=num/10;
	    i++;
       }  
		
		 
    	if(gend=="male")
		{
			int g;
			do{
			
		      g=gender();
		     }
		     while(g!=1&&g!=3&&g!=5&&g!=7&&g!=9);
		     CNIC[12]=g;
	    }
	    else
	    {int g;
			do{
			
		      g=gender();
		     }
		     while(g!=2&&g!=4&&g!=6&&g!=8&&g!=0);
		     CNIC[12]=g;
		}
	
    ostringstream strg;
string data;
for(int i=0;i<13;i++)
{
strg<< CNIC[i];	
string s1 = strg.str();

 data=s1;
}

setCNIC(data);
return true ;
    }
    if(name=="D.I.KHAN")
    {
        
        string name;
    	cout<<"enter the district name: ";
    	cin>>name;
    	if(district(name)==0)
    	{
    		
    		
    		do
    		{
    			cout<<"invalid district";
    				cout<<"\nenter the district name: ";
                 	cin>>name;
                 	system("CLS");
			}
			while(district(name)==0);
		}
		
		
		
    	string tname;
    	cout<<"enter the tehsil: ";
    	cin>>tname;
    	 if(Tehsil(tname)==0)
    	 {
    	 	
    	 	do
    	 	{cout<<"invalid Tehsil";
    	 		cout<<"enter the tehsil";
    	        cin>>tname;
    	        system("CLS");
			 }
			 while(Tehsil(tname)==0);
		 }
		
		  int  CNIC[13];
    	string gend;
    	cout<<"enter the gender: ";
    	cin>>gend;
    	
    	int dis=district(name);
    	  CNIC[0]=Isdigit('1');
    	  CNIC[1]=Isdigit('7');
    	  CNIC[3]=(dis%10);
    	  CNIC[2]=(dis/10);
    	  CNIC[4]=Tehsil(tname);
	
    	 int num=random();
    	 int i=5;
    	 while (num!=0||i<=11)
       {
     	CNIC[i]=num%10;
	    num=num/10;
	    i++;
       }  
		
		 
    	if(gend=="male")
		{
			int g;
			do{
			
		      g=gender();
		     }
		       while(g!=1&&g!=3&&g!=5&&g!=7&&g!=9);
		     CNIC[12]=g;
	    }
	    else
	    {int g;
			do{
			
		      g=gender();
		     }
		     while(g!=2&&g!=4&&g!=6&&g!=8&&g!=0);
		     CNIC[12]=g;
		}
	
   
    ostringstream strg;
string data;
for(int i=0;i<13;i++)
{
strg<< CNIC[i];	
string s1 = strg.str();

 data=s1;
}

setCNIC(data);
   
return true ;	}
	
	else
	{
		
	return 0;
	}
	
			


}

int pvo(string name)
{
//	//1 = KP, 2 = erstwhile FATA
//	if(name=="Sindh")
//	{
//		string divn;
//		cout<<"enter the Division name";
//    	cin>>divn;
//	   if(division(divn)==0)
//	   {
//	   	  cout<<"invalied  division";
//	   	  do
//	   	  {
//	   	  		system("CLS");
//	   	  	cout<<"enter the Division name";
//    	     cin>>divn;
//			 }
//			 while(division(divn)!=true);
//	   }
//	}
//	if(name=="Punjab")
//	{
//	string divn;
//		cout<<"enter the Division name";
//    	cin>>divn;
//	   if(division(divn)==0)
//	   {
//	   	  cout<<"invalied  division";
//	   	  do
//	   	  {
//	   	  		system("CLS");
//	   	  	cout<<"enter the Division name";
//    	     cin>>divn;
//			 }
//			 while(division(divn)!=true);
//	   }
//	}
//	if(name=="Balochistan")
//	{
//		string divn;
//		cout<<"enter the Division name";
//    	cin>>divn;
//	   if(division(divn)==0)
//	   {
//	   	  cout<<"invalied  division";
//	   	  do
//	   	  {
//	   	  		system("CLS");
//	   	  	cout<<"enter the Division name";
//    	     cin>>divn;
//			 }
//			 while(division(divn)!=true);
//	   }
//	}
//	if(name=="Islamanad")
//	{
//		string divn;
//		cout<<"enter the Division name";
//    	cin>>divn;
//	   if(division(divn)==0)
//	   {
//	   	  cout<<"invalied  division";
//	   	  do
//	   	  {
//	   	  		system("CLS");
//	   	  	cout<<"enter the Division name";
//    	     cin>>divn;
//			 }
//			 while(division(divn)!=true);
//	   }
//	}
	if(name=="KPK")
	{   string divn;
		cout<<"enter the Division name: ";
    	cin>>divn;
	   if(division(divn)==0)
	   {
	   	  cout<<"invalid  division";
	   	  do
	   	  {
	   	  		system("CLS");
	   	  	cout<<"enter the Division name: ";
    	     cin>>divn;
			 }
			 while(division(divn)!=true);
	   }
	   
	}
	else
	{
		return 0;
	}
	
}

void CNIC()
{
	string name,divn;
//	cout<<"enter the Province name: ";
//	cin>>name;
    int i=0;
   while( pvo(name)==0){
   	    if(i>0)
   	        cout<<"invalid Province";
   	    
		cout<<"\nEnter the Province name: ";
	    cin>>name;
	    i++;
  system("CLS");
   }
}
	
   	        	int profile()
                	{
		string name;
		string address;
		string language;
		string cast;
		string gend;
                		cout<<"Enter father's name: ";
                		cin>>name;
                		cout<<"Enter the current address: ";
                		cin>>address;
                		cout<<"Enter the language: ";
                		cin>>language;
                		cout<<"Enter the cast: ";
                		cin>>cast;
                		CNIC();  
					}
					
					
					
					
 class Tree
   {    
        
     
    class Node
	{
        string data;
        vector< Node* > child;
        friend class Tree;
        public:
            Node()
			{

            }
            Node(const string data){
                this->data = data;
                
				int n = data.length();
			    char key[n+3];
				
				strcpy(key, data.c_str());
				key[n]='.';
				key[n+1]='t';
				key[n+2]='x';
				key[n+3]='t';
				
				newFile(key,n);
			    
                
//            	newFile(this->data);
            }
    };
    Node * root=NULL;
     int Cnic[13];
	vector<Tree*> tree;	   
     
    public:
    friend class circle ;	 
        Tree()
        {
            root = NULL;
        }
        Tree(const string data)
		{
            root = new Node(data);
        }
          
                
        bool AddNode(const string  parentNodeData,string  data){
//        		
            if(root != NULL){
                if(root->data == parentNodeData){
    
                    Node* temp = new Node(data);
                    root->child.push_back(temp);
                }
                else{
                    Node* parentNode = findNode(root,parentNodeData);
                    if(parentNode)
                   {
                        Node* temp = new Node(data);
                        parentNode->child.push_back(temp);
                    }
                    else{
                         return false;
                    }
                }
            }
        }
                 	
     
void display(Node* temp)
{
           int i=0;

            if(root != NULL)
            {
                if(temp == NULL)
                {
                    return;
                }
                for(int i=0;i<temp->child.size();i++)
                {
                    display(temp->child.at(i));
                    cout << temp->child.at(i)->data << " - ";
                }
                if(temp == root){
                    cout << root->data << " ";
                }
            }
        }

Node* findNode(Node* temp,const string  data)
{
            if(temp!=NULL){
                if(temp->data == data){
                    return temp;
                }
                else{
                    for(int i=0;i<temp->child.size();i++){
                        return findNode(temp->child[i],data);
                    }
                }
            }
            return temp;
        }
      Node*  getRoot()
		{
			cout<<"\n";
            return root;
        }
        string getstring()
        {
        	return root->data;
		}
bool search( string data,Node *temp)
{ 
int i=0;

            if(root != NULL)
           {
//                if(temp== NULL)
//                {
//			          //cout<<"not found";	 
//                            return  ;
//                }
                for(int i=0;i<temp->child.size();i++)
                {
                    if(temp->child.at(i)->data==data)
					{
						cout<< "\nsearch node "<<temp->child.at(i)->data;
						return true;
					};	
                    display(temp->child.at(i));
                }
                
            }
                if(temp->data == data){
                  cout <<"\nsearch node "<<root->data << " ";
                  return true;
                }
                else
                {
                	//cout<<"\nnode is not founded";
				}
               
        }
		
   
     } ;
         
  class linklist 
   { 
      
       class node 
	   {
	   	public:
	   	Tree ptr;//data pointer 
	   	 node *next;//next node  
	   	 
		};
		  node *head=NULL;
		  public:
		  linklist()
		  {
		  	
		  } 
		void nofamily( )
		{
		    CNIC();
		 	string CNICno = getCNIC();
		    Tree f1(CNICno);
		    
//		    int n = CNICno.length();
//		    char key[n+5];
//			strcpy(key, CNICno.c_str());
//			key[n]='.';
//			key[n+1]='t';
//			key[n+2]='x';
//			key[n+3]='t';
//			cout<<endl<<key<<endl;
//		    newFile(key);
		    
		    cout<<"\nCNIC:"<<CNICno<<endl;
		 	node *temp=new node();
		 	temp->ptr=f1;
		 	temp->next=head;
		 	head=temp;
		    
			getch();
			system("cls");
		 }
		 
		 void yesfamily(string id)
		 {
		 	CNIC();
		 	string CNICno = getCNIC();
			 
			int n2 = CNICno.length();
			    char childkey[n2+3];
				
				strcpy(childkey, CNICno.c_str());
				childkey[n2]='.';
				childkey[n2+1]='t';
				childkey[n2+2]='x';
				childkey[n2+3]='t';
				childkey[n2+4]=' ';
				childkey[n2+5]=' ';
				childkey[n2+6]=' ';
				
//				rea
				int n = id.length();
			    char parent[n];
				strcpy(parent, id.c_str());
				
				
				updateFile(parent,n,childkey);
				newFile(childkey,id,n2);
				
		 	
//		 	node *temp=new node();
//		 	temp=head;
//		 	while(temp!=NULL)
//		 	{  
//			    if(temp->ptr.getstring()==id)
//		 	    { 		 	     cout<<"root is found";
//		 		   temp->ptr.AddNode(temp->ptr.getstring(),CNICno);
//		 	       break;
//		 	    }
//		 	    else
//		 	    {
//				 
//		 		temp=temp->next;
//		 	   }
//			 }
		 }
		 
		 void Search(string id)
		 {
		 	int n = id.length();
		 	char value[n+3];
		 	strcpy(value,id.c_str());
		 	value[n]='.';
		 	value[n+1]='t';
		 	value[n+2]='x';
		 	value[n+3]='t';
		 	value[n+4]=' ';
		 	value[n+5]=' ';
		 	cout<<value;
		 	readFile(value);
			getch();
		 	
		 	
			node *temp=new node();
		 	temp=head;
		 	while(temp!=NULL)
		 	{
		 		if(temp->ptr.search(id,temp->ptr.getRoot()))
				 {
				 	break;
				 }
		 		else
		 		{
		 		temp=temp->next;
				 }
			 }
		 }
		      
		  void Displayfamly()
		 {
		 	
		 	string myText;
			ifstream MyReadFile("allfamily.txt");
			
			if(!MyReadFile){
//				cout<<"Invlid CNIC: "<<;
				return;
			}
			cout<<endl;
			while (getline (MyReadFile, myText)) {
//			  cout << myText<<endl;
				int n = myText.length();
				char value[n];
				strcpy(value, myText.c_str());
				readFile(value);
			}
		
			MyReadFile.close();
		 	
		 	getch();
		 	
		 	node *temp=new node();
		 	temp=head;
		 	while(temp!=NULL)
		 	{
		 		temp->ptr.display(temp->ptr.getRoot());
		 		cout<<"\nnext family\n";
		 		temp=temp->next;
			 }
		 }
		 void Onefamily(string id)
		 {
                int n = id.length();
			    char key[n+3];
				
				strcpy(key, id.c_str());
//				key[n]='.';
//				key[n+1]='t';
//				key[n+2]='x';
//				key[n+3]='t';
				
				system("cls");
				cout<<"CNIC:"<<id<<endl;
				readFile(key,n);
				getch();
				system("cls");
						 	
						 	
						 	
						 	
		 	node *temp=new node();
		 	temp=head;
		 	while(temp!=NULL)
		 	{
		 		if(temp->ptr.getstring()==id)
		 		{
		 			temp->ptr.display(temp->ptr.getRoot());
		 			break;
				 }
				 else
				 {
				 	temp=temp->next;
				 }
			 }
		 }
		 
		 
   } ;	
   


void Color(int x)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

int main()
{
		linklist l1;
	int menu_item=0, run, x=7;
	bool running = true;
  gotoXY(10,4);cout<<"===============================================";
	gotoXY(18,5); cout << "          Main Menu";
   gotoXY(10,6);cout<<"===============================================";
	gotoXY(18,7); cout << "->";
	
	while(running)
	{
        gotoXY(20,7);  cout << "   CREATE CNIC";
		gotoXY(20,8);  cout << "   SEARCH CNIC";
		gotoXY(20,9);  cout << "   DISPLAY ALL FAMILIES";
		gotoXY(20,10); cout << "   DISPLAY ONE FAMILY";
		gotoXY(20,11); cout << "   Quit Program";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
			{
				//Color(11);
				gotoXY(18,x); cout << "  ";
				x++;
				//Color(11);
				gotoXY(18,x); cout << "->";
				menu_item++;
				//Color(11);
				continue;
				//Color(115);
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					
					gotoXY(20,16);
					char op;
					cout<<"Do you have your father CNIC: ";
					cin>>op;
					if(op=='Y' || op == 'y')
					{
						string CNIC;
						cout<<"Enter the Father CNIC: ";
						cin>>CNIC;
						cout<<"CNIC is generated: ";
						l1.yesfamily(CNIC);
						system("CLS");
					}
					else
					{
						system("CLS");
						l1.nofamily();
						
					}
					
					break;
				}
					
					
				case 1:{
					 /*system("CLS");
					gotoXY(20,16);
					string CNIC;
					cout<<"Enter the CNIC";
					cin>>CNIC;
					 l1.Search(CNIC);
					*/
					welcome_screen();
					
					break;
				}
					
				case 2:{
					    system("CLS");
					    gotoXY(20,16);
					    l1.Displayfamly();    
					   
					break;
					system("CLS");
				}
					
				case 3: {
					 system("CLS");
					gotoXY(20,16);
					   string id;
					   cout<<"Enter of Father CNIC for family search";
					   cin>>id;
					l1.Onefamily(id);
					//system("CLS");
					break;
				}
					
				case 4: {
					 system("CLS");
					gotoXY(20,16);
					cout << "The program has now terminated!!";
					running = false;
				}
				
			}
				
		}		
		
	}
	
//	gotoXY(20,21);
	return 0;
}


