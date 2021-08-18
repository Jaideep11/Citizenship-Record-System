#ifndef FSM_HEADER_H
#define FSM_HEADER_H
#include"LList.h"
#include<fstream>

int read_file_for_blank(string, int);
void search_by_blank(string name);
void output_any_file(string file_name);
void district_search();
void search_by_blank_pattern_1(string blank, string nm);
void search_by_blank_pattern_2(string blank, string nm);

enum state {
	Match, NotMatch, Star, Dot
};

class Finite_state_machine
{
private:
	string pattern;
	fstream myfile;
	string filename;
	SLL wordlist;
	int count;

public:


	void get_filename(string file_name)
	{
		this->filename = file_name;
		filename = filename + ".txt";
	}

	int reg1(string pattern2, int caution)
	{
		int counter = 0;
		string word_from_file, cnic_filename, str, spare_string_credentials;
		this->pattern = pattern2;
		//count = 0;
		////////////////////
		ofstream fout;
		fout.open("getdata_reg1.txt");
		ifstream inf{ "allfamily.txt" };
		ifstream inf2;
		// If we couldn't open the output file stream for reading
		if (!inf)
		{
			// Print an error and exit
			cerr << "Uh oh, allfamily.txt could not be opened for reading!" << endl;
			return 0;
		}

		//this is for name
		while (inf)
		{

			getline(inf, cnic_filename);
			//inf.ignore();
			//cnic_filename = cnic_filename + ".txt";
			inf2.open(cnic_filename);

			if (!inf2)
			{
				// Print an error and exit
				cerr << "Uh oh, cninc file could not be opened for reading!" << endl;
				exit(1);
			}

			if (caution == 1)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(5, ios::cur);
			}
			
			if (caution == 2)
			{
				inf2.seekg(5, ios::beg);
			}
			else if (caution == 3)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				inf2.seekg(12, ios::cur);
			}
			else if (caution == 4)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(14, ios::cur);


			}
			else if (caution == 5)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(14, ios::cur);


			}

			else if (caution == 6)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(16, ios::cur);
			}

			else if (caution == 7)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(5, ios::cur);
			}



			getline(inf2, str);

			int result = stringmatch(str, pattern);

			if (result == 1)
			{
				++counter;

				if (!fout)
				{
					cerr << "Uh oh, getdata.txt could not be opened for reading!" << endl;
					exit(1);
				}

				inf2.seekg(0, ios::beg);
				while (inf2)
				{
					getline(inf2, spare_string_credentials);
					//inf2.ignore();
					fout << spare_string_credentials << endl;

				}
				fout << "_____________________________________________" << endl;
			}
			inf2.close();

		}
		fout.close();
		inf.close();

		return counter;
	}

	void reg2(string pattern1)
	{
		string word_from_file;
		this->pattern = pattern1;
		count = 0;

		//FILING WORK

		myfile.open(filename.c_str(), ios::in);

		if (myfile.is_open() == 0)
		{
			cout << "FILE COULD NOT BE OPENED\n";
			exit(1);
		}

		clock_t time_req;
		time_req = clock();

		while (!myfile.eof())
		{
			getline(myfile, word_from_file);
			int result = stringmatch(word_from_file, pattern);
			if (result == 1)		//pattern founc
			{
				count++;
				wordlist.add_to_tail(word_from_file);
			}
		}
		myfile.close();
		cout << endl << "Results Found: " << count << endl;
		time_req = clock() - time_req;
		cout << "All wwords Loaded in " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl << endl;
		wordlist.print();		//print all words that matches the expression
		cout << "\nDo you want the details of these indivisuals?(y/n)\n";
		string ans;
		cin >> ans;
		if (ans == "y")
		{
			string cnic_filename;
			wordlist.print_into_file();
			ifstream inf{ "some_cnic.txt" };
			ifstream inf2;
			ofstream fout{ "get_some_cnic_data.txt" };
			// If we couldn't open the output file stream for reading
			if (!inf)
			{
				// Print an error and exit
				cerr << "Uh oh, allfamily.txt could not be opened for reading!" << endl;
			}
			while (inf)
			{

				getline(inf, cnic_filename);
				//inf.ignore();
				//cnic_filename = cnic_filename + ".txt";
				inf2.open(cnic_filename);

				if (!inf2)
				{
					// Print an error and exit
					cerr << "Uh oh, cninc file could not be opened for reading!" << endl;
					exit(1);
				}
				
				string ext;
				getline(inf2, ext);
				fout << ext;
				while (inf2)
				{
					string extra;
					getline(inf2, extra);
					fout <<'\n'<< extra;
				}

				fout << "__________________________________________________" << endl;
				inf2.close();
			}
			
			//fout.close();
			//inf.close();
		}
		//fout.close();
		//inf.close();
		
		system("pause");
		system("cls");
		output_any_file("get_some_cnic_data.txt");
	}


	//main function for solving expression matching
	void regex(string pattern1)
	{
		string word_from_file;
		this->pattern = pattern1;
		count = 0;

		//FILING WORK

		myfile.open(filename.c_str(), ios::in);

		if (myfile.is_open() == 0)
		{
			cout << "FILE COULD NOT BE OPENED\n";
			exit(1);
		}

		clock_t time_req;
		time_req = clock();

		while (!myfile.eof())
		{
			getline(myfile, word_from_file);
			int result = stringmatch(word_from_file, pattern);
			if (result == 1)		//pattern founc
			{
				count++;
				wordlist.add_to_tail(word_from_file);
			}
		}
		myfile.close();
		cout << endl << "Results Found: " << count << endl;
		time_req = clock() - time_req;
		cout << "All wwords Loaded in " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl << endl;
		wordlist.print();		//print all words that matches the expression

	}

	//function to match the string taken from file and pattern entered by user	
	int stringmatch(string a, string b) {

		state currentState = Match;				//initialise finite state machiene using enums
		int i = 0, j = 0;

		while (1)
		{
			switch (currentState)
			{


			case Match:													//if both the strings have same character
				if (i == a.length() && j == b.length()) { return 1; }
				if (a[i] == b[j]) { i++; j++; currentState = Match; }
				else if (b[j] == '*') { j++; currentState = Star; }
				else if (b[j] == '.') { i++; j++; currentState = Dot; }
				else { currentState = NotMatch; }
				break;


			case NotMatch:												//if characters dont match
				return 0;												// match not found, move to another string
				break;


			case Star:													//if pattern has star


				while (1)
				{
					if (j > b.length() - 1 && i <= a.length()) { return 1; }			//if both the strings have reached end point

					while (b[j] != a[i] && i <= a.length() - 1)						//Till string's character matches the pattern's character after *
					{
						i++;
					}

					if (i == a.length() - 1 || b[j + 1] == '*' || b[j + 1] == '.') { break; }			//if string has reached its end, or next character of pattern is * or .

					while (a[i + 1] != b[j + 1] && i <= a.length())					//till next character of string and pattern matches
					{
						i++;
					}

					if (i > a.length()) { break; }								//if string has reached its endpoint

					int  starflag = 0, lenb = 0, x;

					for (x = j; x < b.length(); x++)								//to check if pattern has any other *'s
					{
						if (b[x] == '*') { starflag = 1; break; }
						else { lenb++; }
					}
					int lena = a.length() - i - 1;

					//if pattern has star and pattern and string match and next characters of pattern and string matches
					//OR
					//if pattern has no star and length of string is greater than pattern length

					if ((starflag == 1 && a[x] == b[j] && a[x + 1] == b[j + 1]) || (starflag == 0 && lena > lenb)) { i++; continue; }
					else
					{
						break;
					}
				}

				if (i == a.length() && j == b.length()) { return 1; }
				if (a[i] == b[j]) { i++; j++; currentState = Match; }
				else { currentState = NotMatch; }
				break;



			case Dot:														//if pattern has . as its character
				if (i == a.length() && j == b.length()) { return 1; }
				if (a[i] == b[j]) { i++; j++; currentState = Match; }
				else if (b[j] == '*') { j++; currentState = Star; }
				else if (b[j] == '.') { i++; j++; currentState = Dot; }
				else { currentState = NotMatch; }
				break;

			default:
				break;
			}

		}
	}
};

void output_any_file(string file_name)
{
	ifstream fin{ file_name };
	if (!fin)
	{
		// Print an error and exit
		cerr << "Error...this file could not be opened for reading!" << endl;
		exit(1);
	}

	string str;
	while (fin)
	{
		getline(fin, str);
//		fin.ignore();
		cout << '\n' << str;
	}
	
	


}


int read_file_for_blank( string nama, int caution)
{
	
	int counter=0;
		// ifstream is used for reading files
		// We'll read from a file called Sample.dat
		string str, cnic_filename, spare_string_credentials;
		ofstream fout;
		fout.open("getdata.txt");
		//fout.close();
		ifstream inf{ "allfamily.txt" };
		ifstream inf2;
		// If we couldn't open the output file stream for reading
		if (!inf)
		{
			// Print an error and exit
			cerr << "Uh oh, allfamily.txt could not be opened for reading!" << endl;
			return 0;
		}

		//this is for name
		while (inf)
		{

			getline(inf, cnic_filename);
			//inf.ignore();
			//cnic_filename = cnic_filename + ".txt";
			inf2.open(cnic_filename);

			if (!inf2)
			{
				// Print an error and exit
				cerr << "Uh oh, cninc file could not be opened for reading!" << endl;
				exit(1);
			}

			if (caution == 1)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(5, ios::cur);
			}

			if (caution == 2)
			{
				inf2.seekg(5, ios::beg);
			}
			else if (caution == 3)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				inf2.seekg(12, ios::cur);
			}
			else if (caution == 4)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(14, ios::cur);


			}
			else if (caution == 5)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(14, ios::cur);


			}

			else if (caution == 6)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(16, ios::cur);
			}

			else if (caution == 7)
			{
				string extra;
				inf2.seekg(0, ios::beg);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				getline(inf2, extra);
				inf2.seekg(5, ios::cur);
			}



			getline(inf2, str);
			//inf2.ignore();

			if (str == nama)
			{
				//fout.open("getdata.txt", ios::app);
				++counter;
				if (!fout)
				{
					cerr << "Uh oh, getdata.txt could not be opened for reading!" << endl;
					exit(1);
				}

				inf2.seekg(0, ios::beg);
				while (inf2)
				{

					getline(inf2, spare_string_credentials);
					//inf2.ignore();
					fout << spare_string_credentials << endl;

				}
				fout << "_____________________________________________" << endl;


			}

			inf2.close();

		}
		fout.close();
		inf.close();


		return counter;
}

//    

void search_by_blank(string blank)
{
	//////////////
	
		cout << "\nPlease enter the individual's "<<blank<<" you want to search:\n";
		string nm;
		cin.ignore();

		int number = 0;
		getline(cin, nm);
		//
		if (blank == "CNIC")
		number = read_file_for_blank(nm, 1);

		else if(blank=="name")
		number=read_file_for_blank(nm, 2);
		
		else if(blank=="father's_name")
		number = read_file_for_blank(nm, 3);

		else if (blank == "Date_Of_Birth(DD/MM/YYYY)")
			number = read_file_for_blank(nm, 4);

		else if (blank == "Mobile_Number")
			number = read_file_for_blank(nm, 5);

		else if (blank == "Address")
			number = read_file_for_blank(nm, 6);

		else if (blank == "Cast")
			number = read_file_for_blank(nm, 7);


		system("pause");
		system("cls");
		cout << '\n' << number << " individuals found!\n";
		if (number > 0)
		{
			cout << "These are the individual(s) with the " << blank << ": " << nm << endl;
			output_any_file("getdata.txt");
		}
		system("pause");
	
	//////////////
	
	
}

void search_by_blank_pattern_2(string blank, string nm)
{

	//cout << "\nPlease enter the pattern you want to search for the " << blank << ":\n";
	//string nm;
	//cin.ignore();

	int number = 0;
	//getline(cin, nm);
	Finite_state_machine fsm2;

	if (blank == "CNIC")
		number = fsm2.reg1(nm, 1);
	else if (blank == "name")
		number = fsm2.reg1(nm, 2);
	else if (blank == "father's_name")
		number = fsm2.reg1(nm, 3);
	else if (blank == "Date_Of_Birth(DD/MM/YYYY)")
		number = fsm2.reg1(nm, 4);
	else if (blank == "Mobile_Number")
		number = fsm2.reg1(nm, 5);
	else if (blank == "Address")
		number = fsm2.reg1(nm, 6);
	else if (blank == "Cast")
		number = fsm2.reg1(nm, 7);

	//system("cls");
	cout << '\n' << number << " individuals found!\n";
	if (number > 0)
	{
		// cout << "These are the individuals with the " << blank << ": " << nm << endl;
		output_any_file("getdata_reg1.txt");
		system("pause");
	}
}

void search_by_blank_pattern_1(string blank, string nm )
{

	//cout << "\nPlease enter the pattern you want to search for the " << blank << ":\n";
	//string nm;
	//cin.ignore();

	int number = 0;
	//getline(cin, nm);
	Finite_state_machine fsm2;

	if (blank == "CNIC")
		number = fsm2.reg1(nm, 1);
	else if (blank == "name")
		number = fsm2.reg1(nm, 2);
	else if (blank == "father's_name")
		number = fsm2.reg1(nm, 3);
	else if (blank == "Date_Of_Birth(DD/MM/YYYY)")
		number = fsm2.reg1(nm, 4);
	else if (blank == "Mobile_Number")
		number = fsm2.reg1(nm, 5);
	else if (blank == "Address")
		number = fsm2.reg1(nm, 6);
	else if (blank == "Cast")
		number = fsm2.reg1(nm, 7);

	system("cls");
	cout << '\n' << number << " individuals found!\n";
	if (number > 0)
	{
		cout << "These are the individuals with the " << blank << ": " << nm << endl;
		output_any_file("getdata_reg1.txt");
		system("pause");
	}
}

void search_by_blank_pattern(string blank)
{
	
		cout << "\nPlease enter the pattern you want to search for the " << blank << ":\n";
		string nm;
		cin.ignore();

		int number = 0;
		getline(cin, nm);
		Finite_state_machine fsm2;
		
		if (blank == "CNIC")
			number = fsm2.reg1(nm, 1);
		else if (blank == "name")
			number = fsm2.reg1(nm, 2);
		else if (blank == "father's_name")
			number = fsm2.reg1(nm, 3);
		else if (blank == "Date_Of_Birth(DD/MM/YYYY)")
			number = fsm2.reg1(nm, 4);
		else if (blank == "Mobile_Number")
			number = fsm2.reg1(nm, 5);
		else if (blank == "Address")
			number = fsm2.reg1(nm, 6);
		else if (blank == "Cast")
			number = fsm2.reg1(nm, 7);

		system("cls");
		cout << '\n' << number << " individuals found!\n";
		if (number > 0)
		{
			cout << "These are the individuals with the " << blank << ": " << nm << endl;
			output_any_file("getdata_reg1.txt");
			system("pause");
		}
}


void indiv_search()
{
	int flag = 1, num;
	while (flag == 1)
	{
		system("cls");
		Finite_state_machine fsm1;
		fsm1.get_filename("allfamily");
		string answer;

		cout << "\nPlease enter the option no. for search filter below the following list:\n";
		cout << "\n0. Exit/ Go Back\n1. Search by CNIC\n2.Search by name\n3.Search by Father's name\n4. Search by Date of Birth\n5. Search by cellphone number\n 6. Search by Exact ADDRESS\n 7.Search by Caste\n ";  //remember to add functionality of search by childs name
		cout << "\n\n";
		cin >> num;
		system("cls");

		if (num == 1)
		{
			//fsm1.regex("11*");
			int choice;
			cout << "\nDo you want to search by:\n1. Giving a pattern\n2. By exact matching\n";
			cin >> choice;
			if (choice == 1)
				search_by_blank_pattern("CNIC");
			else if (choice == 2)
				search_by_blank("CNIC");
			else
				cout << "\nINVALID ENTRY!!\n";
		}
		else if (num == 2)
		{
			int choice;
			cout << "\nDo you want to search by:\n1. Giving a pattern\n2. By exact matching\n";
			cin >> choice;
			if (choice == 1)
				search_by_blank_pattern("name");
			else if (choice == 2)
				search_by_blank("name");
			else
				cout << "\nINVALID ENTRY!!\n";
		}
		else if (num == 3)
		{
			int choice;
			cout << "\nDo you want to search by:\n1. Giving a pattern\n2. By exact matching\n";
			cin >> choice;
			if (choice == 1)
				search_by_blank_pattern("father's_name");
			else if (choice == 2)
				search_by_blank("father's_name");
			else
				cout << "\nINVALID ENTRY!!\n";
		}
		else if (num == 4)
		{
			int choice;
			cout << "\nDo you want to search by:\n1. Giving a pattern\n2. By exact matching\n";
			cin >> choice;
			if (choice == 1)
				search_by_blank_pattern("Date_Of_Birth(DD/MM/YYYY)");
			else if (choice == 2)
				search_by_blank("Date_Of_Birth(DD/MM/YYYY)");
			else
				cout << "\nINVALID ENTRY!!\n";
		}
		else if (num == 5)
		{
			int choice;
			cout << "\nDo you want to search by:\n1. Giving a pattern\n2. By exact matching\n";
			cin >> choice;
			if (choice == 1)
				search_by_blank_pattern("Mobile_Number");
			else if (choice == 2)
				search_by_blank("Mobile_Number");
			else
				cout << "\nINVALID ENTRY!!\n";
		}
		else if (num == 6)
		{
			int choice;
			cout << "\nDo you want to search by:\n1. Giving a pattern\n2. By exact matching\n";
			cin >> choice;
			if (choice == 1)
				search_by_blank_pattern("Address");
			else if (choice == 2)
				search_by_blank("Address");
			else
				cout << "\nINVALID ENTRY!!\n";
		}
		else if (num == 7)
		{
			int choice;
			cout << "\nDo you want to search by:\n1. Giving a pattern\n2. By exact matching\n";
			cin >> choice;
			if (choice == 1)
				search_by_blank_pattern("Cast");
			else if (choice == 2)
				search_by_blank("Cast");
			else
				cout << "\nINVALID ENTRY!!\n";
		}
		
		else if (num == 0)
		{
			flag = 0;
		}

	}

}

void district_search()
{
	int flag = 1;
	while (flag == 1)
	{
		system("cls");
		Finite_state_machine fsm1;
		fsm1.get_filename("allfamily");
		string answer;
		cout << "\nPress 0 to exit\nFirst, select the Division in the province: \n";
		cout << "\n1. MALAKAND\n2. Hazara\n 3. Mardan\n 4. Peshawar\n 5. Kohat\n 6. Bannu\n 7. D.I.KHAN\n8. All the people in the division\n";
		cout << "\nPlease enter the option no. for your search filter for selecting the Division:\n";
		int num;
		cin >> num;
		system("cls");

		if (num == 0)
		{
			flag = 0;
		}
		
		else if (num == 1) 
		{
			cout << "\nThe Districts in the selected MALAKAND Division are: \n";
			cout << "\n1. CHITRAL\n2. UPPER DIR\n 3. BUNER\n 4. \n 5. SWAT\n 6. SHANGLA \n 7. D.I.KHAN\n8. All the districts in the Division\n";
			cout << "\nPlease enter the option no. to slect one option:\n";
			int op1;
			cin >> op1;
			if (op1 == 1)
			{
				search_by_blank_pattern_1("CNIC", "1101*");
			}
			if (op1 == 2)
			{
				search_by_blank_pattern_1("CNIC", "1102*");
			}
			if (op1 == 3)
			{
				search_by_blank_pattern_1("CNIC", "1103*");
			}
			if (op1 == 4)
			{
				search_by_blank_pattern_1("CNIC", "1104*");
			}
			if (op1 == 5)
			{
				search_by_blank_pattern_1("CNIC", "1105*");
			}
			if (op1 == 6)
			{
				search_by_blank_pattern_1("CNIC", "1106*");
			}
			if (op1 == 7)
			{
				search_by_blank_pattern_1("CNIC", "1107*");
			}
			if (op1 == 8)
			{
				search_by_blank_pattern_1("CNIC", "11*");
			}


		}

		else if (num == 2)
		{
			cout << "\nThe Districts in the selected HAZARA Division are: \n";
			cout << "\n1. KOSHISTAN\n2. BATAGRAM\n 3. MANSEHRA\n 4.TORGHAR \n 5. ABBOTABAD\n 6. HARIPUR \n 7. All the districts in the Division\n";
			cout << "\nPlease enter the option no. to slect one option:\n";
			int op1;
			cin >> op1;
			if (op1 == 1)
			{
				search_by_blank_pattern_1("CNIC", "1208*");
			}
			if (op1 == 2)
			{
				search_by_blank_pattern_1("CNIC", "1209*");
			}
			if (op1 == 3)
			{
				search_by_blank_pattern_1("CNIC", "1210*");
			}
			if (op1 == 4)
			{
				search_by_blank_pattern_1("CNIC", "1211*");
			}
			if (op1 == 5)
			{
				search_by_blank_pattern_1("CNIC", "1212*");
			}
			if (op1 == 6)
			{
				search_by_blank_pattern_1("CNIC", "1213*");
			}
			if (op1 == 7)
			{
				search_by_blank_pattern_1("CNIC", "12*");
			}

		}

		else if (num == 3)
		{
			cout << "\nThe Districts in the selected MARDAN Division are: \n";
			cout << "\n1. SWABI\n2. MARDAN\n 3.All the districts in the Division\n";
			cout << "\nPlease enter the option no. to select one option:\n";
			int op1;
			cin >> op1;
			if (op1 == 1)
			{
				search_by_blank_pattern_1("CNIC", "1214*");
			}
			if (op1 == 2)
			{
				search_by_blank_pattern_1("CNIC", "1315*");
			}
			if (op1 == 3)
			{
				search_by_blank_pattern_1("CNIC", "13*");
			}

		}

		else if (num == 4)
		{
			cout << "\nThe Districts in the selected PESHAWAR Division are: \n";
			cout << "\n1. CHARSADDA\n2. PESHAWAR\n 3. NOWSHERA\n 4. All the districts in the Division\n";
			cout << "\nPlease enter the option no. to sElect one option:\n";
			int op1;
			cin >> op1;

			if (op1 == 1)
			{
				search_by_blank_pattern_1("CNIC", "1416*");
			}
			if (op1 == 2)
			{
				search_by_blank_pattern_1("CNIC", "1417*");
			}
			if (op1 == 3)
			{
				search_by_blank_pattern_1("CNIC", "1418*");
			}
			if (op1 == 4)
			{
				search_by_blank_pattern_1("CNIC", "14*");
			}


		}

		else if (num == 5)
		{
		cout << "\nThe Districts in the selected KOHAT Division are: \n";
		cout << "\n1. KOHAT\n2. HANGU\n 3. KARAK\n 4. All the districts in the Division\n";
		cout << "\nPlease enter the option no. to slect one option:\n";
		int op1;
		cin >> op1;
		if (op1 == 1)
		{
			search_by_blank_pattern_1("CNIC", "1519*");
		}
		if (op1 == 2)
		{
			search_by_blank_pattern_1("CNIC", "1520*");
		}
		if (op1 == 3)
		{
			search_by_blank_pattern_1("CNIC", "1521*");
		}
		if (op1 == 4)
		{
			search_by_blank_pattern_1("CNIC", "15*");
		}
		

		}

		else if (num == 6)
		{
		cout << "\nThe Districts in the selected BANNU Division are: \n";
		cout << "\n1. BANNU\n2. LAKKI MARWAT\n 3. All the districts in the Division\n";
		cout << "\nPlease enter the option no. to select one option:\n";
		int op1;
		cin >> op1;

		if (op1 == 1)
		{
			search_by_blank_pattern_1("CNIC", "1622*");
		}
		if (op1 == 2)
		{
			search_by_blank_pattern_1("CNIC", "1623*");
		}
		if (op1 == 3)
		{
			search_by_blank_pattern_1("CNIC", "16*");
		}

		}


		else if (num == 7)
		{
		cout << "\nThe Districts in the selected D.I. KHAN Division are: \n";
		cout << "\n1. D.I.KHAN\n2. TANK\n 3. All the districts in the Division\n";
		cout << "\nPlease enter the option no. to select one option:\n";
		int op1;
		cin >> op1;

		if (op1 == 1)
		{
			search_by_blank_pattern_1("CNIC", "1724*");
		}
		if (op1 == 2)
		{
			search_by_blank_pattern_1("CNIC", "1725*");
		}
		if (op1 == 3)
		{
			search_by_blank_pattern_1("CNIC", "17*");
		}

		}

		else
		{
		cout << "\nINVALID ENTRY!!\n";
		system("pause");
		continue;
        }
	}
}


void division_search()
{
	int flag = 1;
	while (flag == 1)
	{

		system("cls");
		Finite_state_machine fsm1;
		fsm1.get_filename("allfamily");
		string answer;

		cout << "\n1. MALAKAND\n2. Hazara\n 3. Mardan\n 4. Peshawar\n 5. Kohat\n 6. Bannu\n 7. D.I.KHAN\n8. All the people in the KPK\n";
		cout << "\nPlease enter the option no. for your search filter:\n";
		int num;
		cin >> num;

		if (num == 1)
		{
			search_by_blank_pattern_1("CNIC", "11*");
		}
		else if (num == 2)
		{
			search_by_blank_pattern_1("CNIC", "12*");
		}
		else if (num == 3)
		{
			search_by_blank_pattern_1("CNIC", "13*");
		}
		else if (num == 4)
		{
			search_by_blank_pattern_1("CNIC", "14*");
		}
		else if (num == 5)
		{
			search_by_blank_pattern_1("CNIC", "15*");
		}
		else if (num == 6)
		{
			search_by_blank_pattern_1("CNIC", "16*");
		}
		else if (num == 7)
		{
			search_by_blank_pattern_1("CNIC", "17*");
		}
		else if (num == 8)
		{
			search_by_blank_pattern_1("CNIC", "1*");
		}

		else
		{
			std::cout << "\nERROR! PLEASE ENTER VALID OPTION!\n";
			system("pause");
			continue;
		}

		cout << endl << endl << "\nDo you want to search again ? (y/n)\n";
		cin >> answer;
		if (answer == "yes")
		{
			flag = 1;
			system("CLS");
		}
		else if (answer == "no")
		{
			flag = 0;
		}

	}
}

void gender_search()
{
	system("cls");
	int gen;
	cout << "\nPlease enter the option number by which you want to search:\n1. Male\n2. Female\n";
	cin >> gen;
	
	if (gen == 1)
	{
		search_by_blank_pattern_2("CNIC", "*1");
		search_by_blank_pattern_2("CNIC", "*3");
		search_by_blank_pattern_2("CNIC", "*5");
		search_by_blank_pattern_2("CNIC", "*7");
		search_by_blank_pattern_2("CNIC", "*9");
	}

	else if (gen == 2)
	{
		search_by_blank_pattern_2("CNIC", "*2");
		search_by_blank_pattern_2("CNIC", "*4");
		search_by_blank_pattern_2("CNIC", "*6");
		search_by_blank_pattern_2("CNIC", "*8");
		search_by_blank_pattern_2("CNIC", "*0");
	}

	else
		cout << "\nINVALID OPTION!!!\n";

}


void welcome_screen()
{
	int num, flag = 1;
	string pattern;
	string answer;
	cout << "\nWelcome!\n";
	while (flag == 1)
	{

		cout << "\nPlease enter the option no. ('1','2' or '3') for your search filter:\n";
		cout << "1.Search for an individual \n2.Search by Division\n3. Search by District\n";


		cin >> num;
		// Finite_state_machine fsm;

		if (num == 1)
		{
			indiv_search();

		}

		else if (num == 2)
		{
			division_search();
		}
		else if (num == 3)
		{
			district_search();
		}
		/*
		else if (num == 5)
		{
			gender_search();
		}
		*/
		else
		{
			std::cout << "Error! Please enter valid option!";
			flag = 1;
			continue;
		}

		/*
		cout << "\nPlease enter the string pattern:\n'*' Indicates String Of Any Length\n'.' Indicates A Single Character\n";
		cin >> pattern;
		fsm.regex(pattern);
		*/
		cout << endl << endl << "\nDo you want to search again ? (y/n)\n";
		cin >> answer;
		if (answer == "y")
		{
			flag = 1;
			system("CLS");
		}
		else if (answer == "n")
		{
			flag = 0;
		}

	
	}
}

#endif
