#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int islogin = 0; //Set to 1 if admin login succesed;

int account = 10101; //Must only be loaded once!

int olddeposit;
int newdeposit;

int objold; //
int objnew; // Used in transfer funtion. Recording recieved account's deposit.
	
int realaccount; //Used in data changing funciton.
int recieveaccount; // Account which recieving transferd money;

string adminpath = "D:\\Works\\C++\\bank\\banktest1\\admin.txt";
string userinfopath = "D:\\Works\\C++\\bank\\registertet\\Userinfo.txt";

char option[2]; 


struct User_Info{
	int account;				//账号
	string name;				//姓名
	string password;			//密码
	long id;					//身份证
	int balance = 0;				//余额
	int isnormal = 0;				//状态
};


string itos(int i) 
{
			stringstream s;
			s << i;
			return s.str();
		};
		
string ltos(long i) 
{
			stringstream s;
			s << i;
			return s.str();
		};


class System_Login{

		public:
		void AdminLogin(int &islogin)
		{
			int lefttry = 3;
			//int islogin = 0;
			
			string inputpass;
			string pass;
			char password[20] = {0} ;
			char inputpassword[20] = {0};
			int ispass = 0;
				
			string inputuname;
			string uname;
			char username[20] = {0};
			char inputusername[20] = {0};
			int isuname = 0;
			
			char readusername[20] = {0};
			char readpassword[20] = {0};
			
			
			ifstream fin(adminpath, ios::in);  
			ofstream fout(adminpath, ios::app);
			ifstream finu(adminpath, ios::in);  
			
			while(lefttry && (islogin != 1))
		 {

			
			
			cout << endl << "Enter Username: ";
			getline(cin, inputuname);
			
			strcpy(inputusername, inputuname.c_str()); 
			int unamecount = 0;
			for(int i = 0; i < 20; i++)
			{
				if((inputusername[i] >= 'a' && inputusername[i] <= 'z') || (inputusername[i] >= 'A' && inputusername[i] <= 'Z') || (inputusername[i] >= '0' && inputusername[i] <= '9'))
				{
					unamecount++;
				}
				else ;
			}
			//cin.clear();

			cout << endl << "Enter Password: ";
			getline(cin, inputpass);
			strcpy(inputpassword, inputpass.c_str()); 
			int passcount = 1;
			for(int i = 0; i < 20; i++)
			{
				if (inputpassword[i] >= '0' && inputpassword[i] <='9')
					{
						passcount++;
					}
					else ;
			}
			//cin.clear();
			
			
			//finu.open("D:\\Works\\C++\\bank\\banktest1\\admin.txt", ios::in);

			if(lefttry == 3)
			{
				while(getline(finu, uname))
			
				{
					strcpy(username, uname.c_str());
					

					if(username[0] == 'U')
					{

					 for(int i = 0; i < 19; i++)
					{
						readusername[i] = username[i];
					};
						
						for(int i = 9; i < 9 + unamecount; i++)
						{
 							//cout <<"$$$ " << username[i];
							//cout <<"***" << inputusername[i];
							//readusername[i] = username[i];
							if(readusername[i] == inputusername[i-9])
							{
								isuname = 1;
							}
							
							else 
								{
									isuname = 0;
									break;
								};
						};
					};
				};
				
			}
			else{
				for(int i = 0; i < 10; i++)
				{
					if(readusername[i+9] == inputusername[i])
						isuname = 1;
						else 
							{
								isuname = 0;
								break;
							}
				};
			};
			
			//fout.close();
			
			//fin.open("D:\\Works\\C++\\bank\\banktest1\\admin.txt", ios::in);


			if(lefttry == 3)
			{
				while(getline(fin, pass))
				{
					strcpy(password, pass.c_str());
					
					if(password[0] == 'P')
					{
						for(int i = 0; i < 19; i++)
						{
							readpassword[i] = password[i];
						};

					 for(int i = 9; i < 9 + passcount; i++)
						{
							if(readpassword[i] == inputpassword[i-9])
							{
								ispass = 1;
							}
							
							else 
								{
									ispass = 0;
									break;
								};
						};
					};
				};
			}
			else{
				for(int i = 0; i < 10; i++)
				{
					if(readpassword[i+9] == inputpassword[i])
						ispass = 1;
						else 
							{
								ispass = 0;
								break;
							}
				};
			};

				
				
				
				
				if((isuname == 1) && (ispass == 1))
				{
					cout << endl << "Login Successed!" << endl << endl;
					islogin = 1;
				}
				else{
					lefttry--;
					if(lefttry > 0)
					{
						cout << endl << "Incorrect Username or Password! " << endl
							<< endl << "You have " << lefttry << " time(s) to try." << endl;
						cout << "_____________________________________";
						 
					}
					else{
						cout << "Incorrect Username or Password! " << endl
							<< "Login Failed, Programm Exit." << endl ;
					};

				};
				
		
		 };
	fout.close();  
		};
		
};


class System_Menu{
	
public:
	int state;
	
	void Get_Feature(int state, char(& option)[2])
	{
		int isvalid = 0;
		if(state)
		{
			cout <<"Account state: Logged in" <<endl <<endl;
			cout <<"_______MAIN MENU________" << endl << endl ;
			cout <<"01. NEW ACCOUNT"<< endl << endl              //开户 1
				 <<"02. CANLE AN ACCOUNT"<< endl<< endl          //销户 1
				 <<"03. DEPOSIT"<< endl<< endl  				 //存款 1
				 <<"04. WITHDRAW"<< endl<< endl  				 //取款 1
				 <<"05. QUERY"<< endl<< endl  					 //查询 1
				 <<"06. TRANSFER"<< endl<< endl  				 //转账
				 <<"07. LOSS REGISTRATION"<< endl<< endl  		 //挂失 1
				 <<"08. HANGING SOLUTION"<< endl<< endl  		 //解挂 1
				 <<"09. CHANGE PASSWORD"<< endl<< endl  		 //改密
				 <<"00. EXIT"<<endl  ;
			
			do{
			cout << endl << "Select Your Options <0-9>: ";
			cin >> option;
			if((option[0] >= '0' && option[0] <= '9') && option[1] == '\0')
				{
					isvalid = 1;
					
				}
				else{
					cout << endl << "Invalid Order!";
					isvalid = 0;
					}
					
			}while(!isvalid);
			
		}
		
	}
};


void Newaccount(vector<User_Info> (&a), int &account){
		
		User_Info temp;
		
		string temppass1 = "1";
		string temppass2 = "2";
		
		temp.account = account;
		
		cout << endl << "***CREATING NEW ACCOUNT***" << endl;
		
		cout <<endl << "Enter Account Name: ";
		cin >> temp.name;
		
		while(temppass1 != temppass2)
		{
			cout << endl << "Enter Account Password: ";
			cin >> temppass1;
			
			cout << endl << "Confirm Account Password: ";
			cin >> temppass2;
			
			if(temppass1 == temppass2)
				{
					temp.password = temppass1; 
					break;
				}
				else 
					{
						cout << endl << "The Password You Input Was Different!" << endl << "Please Try Again!" << endl;
						continue;
					}
			
		}
		
		cout << endl << "Enter Account IDcard Number: ";
		cin >> temp.id;
		
		cout << endl << "Enter How Much To Deposit: ";
		cin >> temp.balance;
		

		a.push_back(temp);
		
		ifstream finn(userinfopath, ios::in);  
		ofstream foutn(userinfopath, ios::app);
		
		int currentaccount = account - 10101;
		
		foutn << a[currentaccount].account << "    " << a[currentaccount].name << "    " << a[currentaccount].password 
		<< "    " << a[currentaccount].id << "    " << a[currentaccount].balance << "    " << a[currentaccount].isnormal << endl;
		
		account += 1;
		
		cout << endl << "***ACCOUNT CREATED SUCCESSED!***" << endl;
		
		foutn.close();
		
		
		
	}


int BackToMenu()
{
	char LastOption ;
	while(1)
	{
		cout << endl << "Enter" << " M " << "To Back To Menu." << endl ;
	
	cin >> LastOption;
	  if((LastOption == 'M') || (LastOption == 'm'))
		{
			break;
			return 1;
		};
	};
	
}


int GetRealAccount(int account)   //Return real account used in vector.
	{
		int temp = 0;
		temp = account - 10100;
		return temp;
	}


void Query(vector<User_Info> (&a))
{
	int inputaccount;
	int realaccount;
	cout << endl << "Enter The Account You Want To Search: ";
	cin >> inputaccount;
	realaccount = GetRealAccount(inputaccount);
	if(a[realaccount-1].isnormal != 2)
	{
		cout << endl << "Account: " << inputaccount 
			 << endl << endl << "Name: " << a[realaccount-1].name
			 << endl << endl << "Passward: " << a[realaccount-1].password
			 << endl << endl << "Balance: " << a[realaccount-1].balance
			 << endl << endl << "ID: " << a[realaccount-1].id 
			 << endl << endl << "State: ";
		if(a[realaccount-1].isnormal == 0)
		{
			cout << "Normal" << endl ;
		}
		else
		{
			cout << "Reported Lossing" << endl ;
		};
		
	}
	else{
		cout << endl << "Unavialuable User Data!" << endl << endl 
				     << "Account Has Been Cancled!" << endl ;
	};
	
	

}


void CancleAccount(vector<User_Info> (&a))
{
	int inputcancleaccount;
	cout << endl << "Enter The Account You Want To Cancle: " << endl ;
	cin >> inputcancleaccount;
	//GetRealAccount(inputcancleaccount);
	inputcancleaccount = GetRealAccount(inputcancleaccount);
	a[inputcancleaccount - 1].isnormal = 2;
	cout << endl <<  "Account Cancle Succeed!" << endl << endl;
}


void LossRegistration(vector<User_Info> (&a))
{
	int inputlossaccount;
	cout << endl << "Enter The Account You Want To Loss Registration: " << endl ;
	cin >> inputlossaccount;
	inputlossaccount = GetRealAccount(inputlossaccount);
	a[inputlossaccount - 1].isnormal = 1;
	cout << endl <<  "Account Loss Registration Succeed!" << endl << endl;
}


void HangingSolution(vector<User_Info> (&a))
{
	int inputhangingaccount;
	cout << endl << "Enter Tha Account You Want To Hanging Loss: " << endl;
	cin >> inputhangingaccount;
	inputhangingaccount = GetRealAccount(inputhangingaccount);
	a[inputhangingaccount - 1].isnormal = 0;
	cout << endl << "Account Hnaging Loss Succed!" << endl << endl ;
}


void Deposit(vector<User_Info> (&a), int &olddeposit, int &newdeposit, int &realaccount) //Change depositamount in vector.
{
	int depositaccount;
	int depositmount;
	
	cout << endl << "Enter The Account You Want To Deposit: ";
	cin >> depositaccount;
	
	depositaccount = GetRealAccount(depositaccount);
	
	cout << endl;
	cout << "Account Name: " << a[depositaccount - 1].name << endl <<endl;
	cout << "Account Balance: " << a[depositaccount - 1].balance << endl;
	
	
	cout << endl << endl 
		 << "Enter Deposit Mount: ";
	cin >> depositmount;
	
	
	olddeposit = a[depositaccount - 1].balance;
	a[depositaccount - 1].balance += depositmount;
	newdeposit = a[depositaccount - 1].balance;
	
	realaccount = depositaccount;
	
	cout << endl << "Deposit Succed!";
	cout << endl << "Account Balance: " << a[depositaccount - 1].balance <<endl;
	
	
}


void ReplaceDeposit(vector<User_Info> (&a), int olddeposit, int newdeposit, int &realaccount) //Update deposit record in files.
{
		
	
	
	
		string line;
		ifstream myfile(userinfopath);

		vector<string> lines;

		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				lines.push_back(line);
			}
			myfile.close();
		}

		else
			cout << "Unable to open file";



		string origin;
		string after;
		
		string straccount = itos(a[realaccount - 1].account);
		string strid = ltos(a[realaccount - 1].id);
		string stroldbalance = itos(olddeposit);
		string strnerbalance = itos(newdeposit);
		string strisnormal = itos(a[realaccount - 1].isnormal);
		
		
		
		
		origin = straccount + "    " + a[realaccount - 1].name + "    " + a[realaccount - 1].password 
			+ "    " + strid + "    " + stroldbalance + "    " + strisnormal;
			
		after = straccount + "    " + a[realaccount - 1].name + "    " + a[realaccount - 1].password 
			+ "    " + strid + "    " + strnerbalance + "    " + strisnormal;
		
		for (vector<string>::iterator it = lines.begin(); it != lines.end(); ++it) {
			if (*it == origin)
			{
				*it = after;
			}
		}
		//cout << origin << endl <<after<<endl; 


		ofstream myfileOut(userinfopath);

		if (myfileOut.is_open())
		{
			for (vector<string>::iterator it = lines.begin(); it != lines.end(); ++it)
			{
				myfileOut << *it << endl;
			}
			myfileOut.close();
    }

		else
			cout << "Unable to open file";

	}
	
	
void Withdraw(vector<User_Info> (&a), int &olddeposit, int &newdeposit, int &realaccount)
{
	int withdrawaccount;
	int withdrawmount;
	
	int islegal = 0; // Check if the withdraw amount less than deposit.
	
	
	cout << endl << "Enter The Account You Want To Withdraw: ";
	cin >> withdrawaccount;
	
	withdrawaccount = GetRealAccount(withdrawaccount);
	
	cout << endl ;
	cout << "Account Name: " << a[withdrawaccount - 1].name << endl <<endl;
	cout << "Account Balance: " << a[withdrawaccount - 1].balance << endl;
	
	do{
	cout << endl << endl 
		 << "Enter Withdraw Mount: ";
	cin >> withdrawmount;
	
	
		if(a[withdrawaccount - 1].balance >= withdrawmount)
			{
				olddeposit = a[withdrawaccount - 1].balance;
				a[withdrawaccount - 1].balance -= withdrawmount;
				newdeposit = a[withdrawaccount - 1].balance;
				
				realaccount = withdrawaccount;
				
				islegal = 1;
				
				cout << endl << "Withdraw Succed!";
				cout << endl << "Account Balance: " << a[withdrawaccount - 1].balance;
			}
			else{
				islegal = 0;
				
				cout << endl << "****Withdraw Failed!****" << endl ;
				cout << endl << "****Withdraw Amount May Not More Than The Deposit!****" << endl << endl  ;
			}
	}while(!islegal);
}
	
	
void Transfer(vector<User_Info> (&a), int &olddeposit, int &newdeposit, int &objold, int &objnew, int &realaccount, int &recieveaccount)
{
	int transferamount;
	int t_islegal = 0;
	
	cout << "Enter The Account You Want To Transfer From: ";
	cin >> realaccount;
	
	realaccount = GetRealAccount(realaccount);
	
	cout << "Account Name: " << a[realaccount - 1].name << endl << endl;
	cout << "Account Password: " << a[realaccount - 1].password << endl << endl;
	cout << "Account Balance: " << a[realaccount - 1].balance << endl << endl;
	
	do
	{
		cout << "Enter Transfer Amount: ";
		cin >> transferamount;
		if(a[realaccount - 1].balance >= transferamount)
		{
			t_islegal = 1;
		}
		else{
			t_islegal = 0;
			cout << endl << endl << "Transfer Amount May Not More Than Deposit!" << endl;
		}
	}while(!t_islegal);
	
	olddeposit = a[realaccount - 1].balance;
	a[realaccount - 1].balance -= transferamount;
	newdeposit = a[realaccount - 1].balance;
	
	cout << endl << "Enter The Account You Want To Transfer To: ";
	cin >> recieveaccount;
	recieveaccount = GetRealAccount(recieveaccount);
	
	objold = a[recieveaccount - 1].balance;
	a[recieveaccount - 1].balance += transferamount;
	objnew = a[recieveaccount - 1].balance;
	
	cout << endl << endl << "Transfer Succed!"
		 << endl << endl << "Account Blance: " << a[realaccount - 1].balance << endl ;
	
}
	
	
	
	
	
int main()
{
	System_Login AA;
	AA.AdminLogin(islogin);
	
	vector<User_Info> a;
	
	
	System_Menu A;
	A.state = islogin;
	menu:
	A.Get_Feature(A.state, option);
	//Option save in option[0] by a number from 0 to 9;
	//vector<User_Info> Users;
	
	
	
	if(option[0] == '1')
		{
			Newaccount(a, account);
		}
		else if (option[0] == '5')
		{
			Query(a);
		}
		else if (option[0] == '2')
		{
			CancleAccount(a);
		}
		else if (option[0] == '7')
		{
			LossRegistration(a);
		}
		else if (option[0] == '8')
		{
			HangingSolution(a);
		}
		else if (option[0] == '3')
		{
			Deposit(a, olddeposit, newdeposit, realaccount);
			ReplaceDeposit(a, olddeposit, newdeposit, realaccount);
		}
		else if (option[0] == '4')
		{
			Withdraw(a, olddeposit, newdeposit, realaccount);
			ReplaceDeposit(a, olddeposit, newdeposit, realaccount);
		}
		else if (option[0] == '6')
		{
			Transfer(a, olddeposit, newdeposit, objold, objnew, realaccount, recieveaccount);
			ReplaceDeposit(a, olddeposit, newdeposit, realaccount);
			ReplaceDeposit(a, objold, objnew, recieveaccount);
		}
	
		if(BackToMenu())
		{
			goto menu;
		}
		
		
}