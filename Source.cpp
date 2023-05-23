#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

///  -----------------------  A D M I N I S T R A T O R ----------------------- ///
/// it can Add Edit Student and Teachers Deatils
class administrator
{
public:
	/// teacher variables 
	string tf_name, tl_name, t_id, tu_name, t_email, tr_date, t_gender, t_blood, t_contact, t_adress;

	/// student variables
	string sf_name, sl_name, s_id, su_name, s_email, sr_date, s_gender, s_contact, s_blood, s_adress;
	bool s_fee;

	int total_teacher();
	int total_student();

	void add_teacher();
	void add_student();

	void edit_teacher();
	void edit_student();

	void display_all_teachers();
	void display_all_students();

};

///  ----------------------- T O T A L __ T E A C H E R S __ S T U D E N T S  ----------------------- ///
/// check total number of registered teachers
int administrator::total_teacher()
{
	string line; int count = 0;
	fstream check("teacher.txt");
	while (getline(check, line))
		count++;
	check.close();
	return count;
}

/// check total number of registered students
int administrator::total_student()
{
	string line; int count = 0;
	fstream check("student.txt");
	while (getline(check, line))
		count++;
	check.close();
	return count;
}

///  ----------------------- A D D      T E A C H E R S     D E T A I L S  ----------------------- ///
/// collecting and adding teacher data in file
void administrator::add_teacher()
{
	cout << "Enter First Name : ";
	cin >> tf_name;
	cout << "Enter Last Name : ";
	cin >> tl_name;

	/// Adding System Generated ID 
	int temp_id = total_teacher() + 1001;

	/// converting interger to string
	t_id = to_string(temp_id);

	cout << "Enter User Name : ";
	cin >> tu_name;
	cout << "Enter Email : ";
	cin >> t_email;
	cout << "Enter Registration Date : ";
	cin >> tr_date;
	cout << "Enter Gender : ";
	cin >> t_gender;
	cout << "Enter Blood Group : ";
	cin >> t_blood;
	cout << "Entre Contact Number : ";
	cin >> t_contact;
	cout << "Enter Teacher Adress : ";
	cin >> t_adress;

	/// adding teacher collected data in file
	fstream addteacher("teacher.txt", ios::app);
	addteacher << setw(15) << tf_name << " " << setw(15) << tl_name << " " << setw(5) << t_id << " ";
	addteacher << setw(15) << tu_name << " " << setw(25) << t_email << " " << setw(15) << tr_date << " ";
	addteacher << setw(10) << t_gender << " " << setw(5) << t_blood << " " << setw(15) << t_contact << " ";
	addteacher << setw(25) << t_adress << endl;
	addteacher.close();
}

///  ----------------------- A D D      S T U D E N T S    D E T A I L S  ----------------------- ///
/// collecting and adding student data in file
void administrator::add_student()
{
	cout << "Enter First Name : ";
	cin >> sf_name;
	cout << "Enter Last Name : ";
	cin >> sl_name;

	/// Adding System Generated Student ID
	int temp_id = total_student() + 1001;
	/// Conerting Integers to Sting
	s_id = to_string(temp_id);

	cout << "Enter User Name : ";
	cin >> su_name;
	cout << "Enter Email : ";
	cin >> s_email;
	cout << "Enter Registration Date : ";
	cin >> sr_date;
	cout << "Enter Gender : ";
	cin >> s_gender;
	cout << "Entre Contact Number : ";
	cin >> s_contact;
	cout << "Enter Blood Group : ";
	cin >> s_blood;
	cout << "Enter Adress : ";
	cin >> s_adress;
	cout << "Fee is paid or not 0/1 : ";
	cin >> s_fee;

	/// adding student collected data in file
	fstream addstudent("student.txt", ios::app);
	addstudent << setw(15) << sf_name << " " << setw(15) << sl_name << " " << setw(5) << s_id << " ";
	addstudent << setw(15) << su_name << " " << setw(25) << s_email<< " ";
	addstudent << setw(15) << sr_date << " " << setw(10) << s_gender << " " << setw(15) << s_contact << " ";
	addstudent << setw(5) << s_blood << " " << setw(25) << s_adress << " " << setw(1) << s_fee << endl;
	addstudent.close();
}

///  ----------------------- E D I T     T E A C H E R S     D E T A I L S  ----------------------- ///
/// edit and display teachers details
void administrator::edit_teacher()
{
	int check = 0;
	string* tf_name, * tl_name, * t_id, * tu_name, * t_email, * tr_date, * t_gender, * t_blood, * t_contact, * t_adress;

	/// Getting the Size Of File for dynamixc Pointer Array
	int size = total_teacher() + 1;
	tf_name = new string[size]; tl_name = new string[size]; t_id = new string[size]; tu_name = new string[size];
	t_email = new string[size]; tr_date = new string[size]; t_gender = new string[size]; t_blood = new string[size];
	t_contact = new string[size]; t_adress = new string[size];
	system("cls");
	fstream getdata("teacher.txt", ios::in);

	/// reding data from file to display and edit
	for (int i = 1; i < size; i++)
	{
		getdata >> tf_name[i] >> tl_name[i] >> t_id[i] >> tu_name[i];
		getdata >> t_email[i] >> tr_date[i] >> t_gender[i];
		getdata >> t_blood[i] >> t_contact[i] >> t_adress[i];
		cout << setw(15) << tf_name[i] << " " << setw(15) << tl_name[i] << " " << setw(5) << t_id[i] << " ";
		cout << setw(15) << tu_name[i] << " " << setw(25) << t_email[i] << " " << setw(15) << tr_date[i] << " ";
		cout << setw(10) << t_gender[i] << " " << setw(5) << t_blood[i] << " " << setw(15) << t_contact[i] << " ";
		cout << setw(25) << t_adress[i] << endl;
	}
	getdata.close();
	int getid;

	/// Getting Teacer Id to edit
	cout << "\nEnter The Teacher ID to Edit The Details : ";
	cin >> getid;
	if (getid <= size + 1000 && getid > 1000)
	{
		string id = to_string(getid);
		for (int i = 1; i < size; i++)
		{
			/// Getting New Data OF Given ID
			if (id == t_id[i])
			{
				cout << "Enter New First Name : ";
				cin >> tf_name[i];
				cout << "Enter New Last Name : ";
				cin >> tl_name[i];
				cout << "Enter New Adress : ";
				cin >> t_adress[i];
				cout << "Entre New Contact Number : ";
				cin >> t_contact[i];
				cout << "Enter New Usre Name : ";
				cin >> tu_name[i];
				cout << "Enter New Email : ";
				cin >> t_email[i];
			}
		}

		/// adding the update data in file
		fstream edited_data("teacher.txt", ios::out);
		for (int i = 1; i < size; i++)
		{
			edited_data << setw(15) << tf_name[i] << " " << setw(15) << tl_name[i] << " " << setw(5) << t_id[i] << " ";
			edited_data << setw(15) << tu_name[i] << " " << setw(25) << t_email[i] << " " << setw(15) << tr_date[i] << " ";
			edited_data << setw(10) << t_gender[i] << " " << setw(5) << t_blood[i] << " " << setw(15) << t_contact[i] << " ";
			edited_data << setw(25) << t_adress[i] << endl;
		}
		edited_data.close();
	}
	else
	{
		cout << "!!! Invalid Id !!!" << endl;
	}
}

///  ----------------------- E D I T      S T U D E N T S    D E T A I L S  ----------------------- ///
/// edit and update student data in file
void administrator::edit_student()
{
	int check = 0;
	string* sf_name, * sl_name, * s_id, * sr_date, * su_name, * s_email, * s_gender, * s_contact, * s_blood, * s_adress;
	bool* s_fee;
	/// Getting the Size Of File for dynamixc Pointer Array
	int size = total_student() + 1;
	sf_name = new string[size]; sl_name = new string[size]; s_id = new string[size]; su_name = new string[size];
	s_email = new string[size]; sr_date = new string[size]; s_gender = new string[size]; s_blood = new string[size];
	s_contact = new string[size]; s_adress = new string[size]; s_fee = new bool[size];
	system("cls");
	fstream getdata("student.txt", ios::in);

	/// reding data from file to display and edit
	for (int i = 1; i < size; i++)
	{
		getdata >> sf_name[i] >> sl_name[i] >> s_id[i] >> su_name[i] >> s_email[i];
		getdata >> sr_date[i] >> s_gender[i] >> s_contact[i] >> s_blood[i] >> s_adress[i] >> s_fee[i];
		cout << setw(15) << sf_name[i] << " " << setw(15) << sl_name[i] << " " << setw(5) << s_id[i] << " ";
		cout << setw(15) << su_name[i] << " " << setw(25) << s_email[i] << " ";
		cout << setw(15) << sr_date[i] << " " << setw(10) << s_gender[i] << " " << setw(15) << s_contact[i] << " ";
		cout << setw(5) << s_blood[i] << " " << setw(25) << s_adress[i] << " " << setw(1) << s_fee[i] << endl;
	}
	getdata.close();
	int getid;

	/// Getting Student Id to edit
	cout << "\nEnter The Student ID to Edit The Details : ";
	cin >> getid;
	if (getid <= size + 1000 && getid > 1000)
	{
		string id = to_string(getid);
		for (int i = 1; i < size; i++)
		{
			/// getting new data of given id 
			if (id == s_id[i])
			{
				cout << "Enter New First Name : ";
				cin >> sf_name[i];
				cout << "Enter New Last Name : ";
				cin >> sl_name[i];
				cout << "Enter New Adress : ";
				cin >> s_adress[i];
				cout << "Entre New Contact Number : ";
				cin >> s_contact[i];
				cout << "Enter New Usre Name : ";
				cin >> su_name[i];
				cout << "Enter New Email : ";
				cin >> s_email[i];
			}
		}

		/// adding the update data in file
		fstream edited_data("student.txt", ios::out);
		for (int i = 1; i < size; i++)
		{

			edited_data << setw(15) << sf_name[i] << " " << setw(15) << sl_name[i] << " " << setw(5) << s_id[i] << " ";
			edited_data << setw(15) << su_name[i] << " " << setw(25) << s_email[i] << " ";
			edited_data << setw(15) << sr_date[i] << " " << setw(10) << s_gender[i] << " " << setw(15) << s_contact[i] << " ";
			edited_data << setw(5) << s_blood[i] << " " << setw(25) << s_adress[i] << " " << setw(1) << s_fee[i] << endl;
		}
		edited_data.close();
	}
	else
	{
		cout << "!!! Invalid Id !!!" << endl;
	}
	}

	/// displaying whole teachers data
	void administrator::display_all_teachers()
	{
		string teacher_data;
		fstream display_teacher("teacher.txt");
		while (getline(display_teacher, teacher_data))
			cout << teacher_data << endl;
		display_teacher.close();
	}

	/// displaying hole students data
	void administrator::display_all_students()
	{
		string student_data;
		fstream display_student("student.txt");
		while (getline(display_student, student_data))
			cout << student_data << endl;
		display_student.close();
	}


	///  ----------------------- M A I N   F U N C T I O N  ----------------------- ///
	void main_function()
	{
		administrator obj;
		int select;
		do
		{
			system("cls");
			/// Menu for to slect a specific Task
			cout << "Enter 0 to end the Program" << endl;
			cout << "Enter 1 to add Teacher Data" << endl;
			cout << "Enter 2 to add Student Data" << endl;
			cout << "Enter 3 to edit Teacher Data" << endl;
			cout << "Enter 4 to edit Student Data" << endl;
			cout << "Enter 5 to Display Teacher Data" << endl;
			cout << "Enter 6 to Display Student Data" << endl;
			cout << "Enter Number : ";
			cin >> select;
			if (select != 0)
			{
				switch (select)
				{
				case 1:
					do
					{
						system("cls");
						cout << "Add Teacher Data\n" << endl;
						obj.add_teacher();
						system("cls");
						cout << "Teacher Data added sucessfully" << endl;
						cout << "Enter 1 to add another teacher data or 9 for main menu" << endl;
						cout << "Enter Number : ";
						cin >> select;
					} while (select != 9);
					break;
				case 2:
					do
					{
						system("cls");
						cout << "Add Student Data\n" << endl;
						obj.add_student();
						system("cls");
						cout << "Student Data added sucessfully" << endl;
						cout << "Enter 1 to add another student data or 9 for main menu" << endl;
						cout << "Entre Number : ";
						cin >> select;
					} while (select != 9);
					break;
				case 3:
					do
					{
						obj.edit_teacher();
						system("cls");
						cout << "Teacher Data edited sucessfully" << endl;
						cout << "Enter 1 to edit another teacher data or 9 for main menu" << endl;
						cout << "Enter Number : ";
						cin >> select;
					} while (select != 9);
					break;
				case 4:
					do
					{
						obj.edit_student();
						system("cls");
						cout << "Student Data edited sucessfully" << endl;
						cout << "Enter 1 to edit another student data or 9 for main menu" << endl;
						cout << "Enter NUmber : ";
						cin >> select;
					} while (select != 9);
					break;
				case 5:
					do
					{
						system("cls");
						cout << "Toala Number of Teachers are " << obj.total_teacher() << " :\n" << endl;
						obj.display_all_teachers();
						cout << "\nEnter 9 for main menu" << endl;
						cout << "Enter NUmber : ";
						cin >> select;
					} while (select != 9);
					break;
				case 6:
					do
					{
						system("cls");
						cout << "Toala Number of Student are " << obj.total_student() << " :\n" << endl;
						obj.display_all_students();
						cout << "\nEnter 9 for main menu" << endl;
						cout << "Enter Number : ";
						cin >> select;
					} while (select != 9);
					break;
				default:
				{
					do
					{
						system("cls");
						cout << " !!! invalid choice !!!" << endl;
						cout << "\Enter 9 for main menu" << endl;
						cout << "Enter Number : ";
						cin >> select;
					} while (select != 9);
				}
				}
			}
			system("cls");
		} while (select != 0);
	}

	///  -----------------------  I N T      M A I N  ----------------------- ///

	int main()
	{
		main_function();
		return 0;
	}
