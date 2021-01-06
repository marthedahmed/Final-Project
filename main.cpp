/*marthad ahmed
 * second class
 * computer */



#include<fstream>
#include<string>
#include<iostream>
using namespace std;

class contact
{
/////
	long phone;
	char FirstName[20];

	public:

	void create_contact()///function of the create
	{
		cout<<"Phone: ";
		cin>>phone;

		cout<<"First Name: ";
		cin.ignore();
		cin>>FirstName;




		cout<<"\n";
	}

	void show_contact() ////function of show
	{
		cout<<endl<<"Phone #: "<<phone;
		cout<<endl<<"First Name: "<<FirstName;

	}

	long getPhone()
	{
		return phone;
	}

	char* getFirstName()
	{
		return FirstName;
	}


};

fstream fp;
contact cont;

void save_contact()     ////function of save
{
	fp.open("contactBook.txt",ios::out|ios::app);
	cont.create_contact();
	fp.write((char*)&cont,sizeof(contact));
	fp.close();
	cout<<endl<<endl<<"the contact has been create\n\n";
	getchar();
}

void show_all_contacts()////Searching help function(checks if the name is exists)
{
	cout << "LIST OF CONTACTS";
	fp.open("contactBook.txt",ios::in);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		cont.show_contact();
	}
	fp.close();
}

void display_contact(int num) ////the function of display
{
	bool found;
	int ch;

	found=false;
	fp.open("contactBook.txt",ios::in);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		if(cont.getPhone()==num)
		{
		cont.show_contact();
		found=true;
		}
	}
	fp.close();
	if(found == false){
	cout<<"\n\nNo record found...";}
	getchar();
}

void edit_contact()    ///the function of edit
{
	int num;
	bool found=false;

	cout<<"number of contact";
	cin>>num;
	fp.open("contactBook.txt",ios::in|ios::out);
	while(fp.read((char*)&cont,sizeof(contact)) && found==false)
	{
		if(cont.getPhone()==num)
		{
			cont.show_contact();
			cout<<"\nThe New Details : "<<endl;
			cont.create_contact();
			long pos=-1*sizeof(cont);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&cont,sizeof(cont));
			cout<<endl<<endl<<"\t Contact Successfully Updated...\n\n";
			found=true;
		}
	}
	fp.close();
	if(found==false)
	cout<<endl<<endl<<"Contact Not Found...\n\n";
}

void delete_contact()     ////the function of delete
{
	int num;
	cout<<endl<<endl<<"Please Enter The contact #: ";
	cin>>num;
	fp.open("contactBook.txt",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.txt",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&cont,sizeof(contact)))
	{
		if(cont.getPhone()!=num)
		{
			fp2.write((char*)&cont,sizeof(contact));
		}
	}
	fp2.close();
	fp.close();
	remove("contactBook.txt");
	rename("Temp.txt","contactBook.txt");
	cout<<endl<<endl<<"\tContact Deleted...\n\n";
}
bool Dashboard()
{
	/*JUST DESIGN*/
	cout << "MAIN MENU\n|\t [1] Add a new Contact\n\t\t [2] List all Contacts\n\t\t [3] Search for contact\n\t\t [4] Edit a Contact\n\t\t [5] Delete a Contact\n\t\t [0] Exit\n\t";
	cout << "\n\t\t Enter the choice: ";
	return true;
}

int main()
{

	int i;

	while(Dashboard())
	{
		cin >> i;

		switch (i)
		{
		case 0:
			cout << "\n\tApp Closed :)\n\n";
			return 0;
			break;

		case 1:
			save_contact();
			break;

		case 2:
			show_all_contacts();
			break;
		case 3:
			int num;
			cout << "\n\n\tPhone: ";
			cin >> num;
			display_contact(num);
			break;
		case 4:
			edit_contact();
			break;

		case 5:
			delete_contact();
			break;
		default:
		cout<<"Try Again..\n";
			break;
		}
	}
	return 0;
}
