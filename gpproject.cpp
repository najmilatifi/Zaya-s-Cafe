#include<iostream>
#include<unistd.h>
#include<cmath>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;

//functions
void menu(), clearoutput(), foodreceipt(string, double, int), receipt(double, double, int, double), adminreceipt(double, double, double, double);
double calcprice(double, double&), calcoverall();

int main()
{
	double price, totalprice, singleprice, receiptprice[1000], tax, totaltax, invest, profit, totalprofit, totalexpension, total, pricebefore;
	double totalincome, govtax;
	int code, counter = 0, printer = 0, login;
	char choice = 'Q', hotcold;
	string name[1000], foodname, username, password, answer[4] = {"Yes", "Yes", "Yes"};
	bool check = false;
	
	//loop to allow different users to enter without ending the program and to ask same questions when users enter invalid input
	while(answer[0] == "Yes")
	{
		system("cls");
		cout<<"Do you want to take order? [Yes/No]"<<endl;
		cin>>answer[1];
		system("cls");
		
		if(answer[1] == "Yes")
		{
			answer[2] = "Yes";
			menu();
			
			while(answer[2] == "Yes")
			{
				while(choice != 'C' and choice != 'W' and choice != 'P' and choice != 'F' and choice != 'N' and choice != 'S')
				{
					cout<<"Select variant [C]Combo [W]Western [P]Pasta [F]Coffee [N]Non Coffee [S]Snacks & Deserts: ";
					cin>>choice;

					if(choice == 'C')
					{
						cout<<"Enter Code: ";
						cin>>code;
						
						while(code < 0 or code > 9)
						{
							cout<<"Please enter valid code."<<endl;
							cout<<"Enter Code: ";
							cin>>code;
						}
						
						switch(code)
						{
							case 1:
								price = 33;
								invest = 27;
								foodname = "Chicken Chop (Combo)";
								break;
							case 2:
								price = 37;
								invest = 29;
								foodname = "Lamb Chop (Combo)";
								break;
							case 3:
								price = 28;
								invest = 21;
								foodname = "Mac & Cheese (Combo)";
								break;
							case 4:
								price = 30;
								invest = 21;
								foodname = "Spaghetti Chicken Bolognese (Combo)";
								break;
							case 5:
								price = 30;
								invest = 21;
								foodname = "Spaghetti Carbonara (Combo)";
								break;
							case 6:
								price = 29;
								invest = 20;
								foodname = "Fish & Chips (Combo)";
								break;
							case 7:
								price = 34;
								invest = 26;
								foodname = "Zaya Beef Burger (Combo)";
								break;
							case 8:
								price = 30;
								invest = 22;
								foodname = "Spaghetti Aglio Olio (Combo)";
								break;
							case 9:
								price = 32;
								invest = 23;
								foodname = "Spaghetti Salted Egg Prawn (Combo)";
								break;
							case 0:
								price = 32;
								invest = 25;
								foodname = "Lasagna (Combo)";
								break;
						}
						
						cout<<"Do you want hot or cold Signature Zaya Coffee? [H/C]: ";
						cin>>hotcold;
						
						while(hotcold != 'H' and hotcold != 'C')
						{
							cout<<"Please enter valid answer."<<endl;
							cout<<"Do you want hot or cold Signature Zaya Coffee? [H/C]: ";
							cin>>hotcold;
						}
						
						cout<<"Enter code for preferred snack or desert: ";
						cin>>code;
						
						while(code < 1 or code > 6)
						{
							cout<<"Please enter valid code."<<endl;
							cout<<"Enter code for preferred snack or desert: ";
							cin>>code;
						}
					}
					
					else if(choice == 'W')
					{
						cout<<"Enter Code: ";
						cin>>code;
						
						while(code < 1 or code > 4)
						{
							cout<<"Please enter valid code."<<endl;
							cout<<"Enter Code: ";
							cin>>code;
						}
						
						switch(code)
						{
							case 1:
								price = 18;
								invest = 13;
								foodname = "Chicken Chop";
								break;
							case 2:
								price = 22;
								invest = 15;
								foodname = "Lamb Chop";
								break;
							case 3:
								price = 14;
								invest = 6;
								foodname = "Fish & Chips";
								break;
							case 4:
								price = 19;
								invest = 12;
								foodname = "Zaya Beef Burger";
								break;
						}
					}
					
					else if(choice == 'P')
					{
						cout<<"Enter Code: ";
						cin>>code;
						
						while(code < 1 or code > 6)
						{
							cout<<"Please enter valid code."<<endl;
							cout<<"Enter Code: ";
							cin>>code;
						}
						
						switch(code)
						{
							case 1:
								price = 13;
								invest = 7;
								foodname = "Mac & Cheese";
								break;
							case 2:
								price = 15;
								invest = 7;
								foodname = "Spaghetti Chicken Bolognese";
								break;
							case 3:
								price = 15;
								invest = 7;
								foodname = "Spaghetti Carbonara";
								break;
							case 4:
								price = 15;
								invest = 8;
								foodname = "Spaghetti Aglio Olio";
								break;
							case 5:
								price = 17;
								invest = 9;
								foodname = "Spaghetti Salted Egg Prawn";
								break;
							case 6:
								price = 17;
								invest = 11;
								foodname = "Lasagna";
								break;
						}
					}
					
					else if(choice == 'F')
					{
						cout<<"Enter Code: ";
						cin>>code;
						
						while(code < 1 or code > 6)
						{
							cout<<"Please enter valid code."<<endl;
							cout<<"Enter Code: ";
							cin>>code;
						}
						
						switch(code)
						{
							case 1:
								price = 13;
								invest = 9;
								foodname = "Caramel Macchiato";
								break;
							case 2:
								price = 12;
								invest = 9;
								foodname = "Caffe Mocha / White Mocha";
								break;
							case 3:
								price = 11;
								invest = 7.5;
								foodname = "Caffe Latte";
								break;
							case 4:
								price = 12;
								invest = 8.5;
								foodname = "Cappuccino";
								break;
							case 5:
								price = 15;
								invest = 9;
								foodname = "Signature Zaya Coffee";
								break;
							case 6:
								price = 11;
								invest = 8.5;
								foodname = "Americano";
								break;
						}
						
						cout<<"Do you want hot or cold? [H/C]: ";
						cin>>hotcold;
						
						while(hotcold != 'H' and hotcold != 'C')
						{
							cout<<"Please enter valid answer."<<endl;
							cout<<"Do you want hot or cold Signature Zaya Coffee? [H/C]: ";
							cin>>hotcold;
						}
						
						if(hotcold == 'H')
						{
							price = price - 1;
						}
					}
					
					else if(choice == 'N')
					{
						cout<<"Enter Code: ";
						cin>>code;
						
						while(code < 1 or code > 7)
						{
							cout<<"Please enter valid code."<<endl;
							cout<<"Enter Code: ";
							cin>>code;
						}
						
						switch(code)
						{
							case 1:
								price = 14;
								invest = 11.5;
								foodname = "Kiwi Smoothie";
								break;
							case 2:
								price = 14;
								invest = 10.9;
								foodname = "Lemonade Smoothie";
								break;
							case 3:
								price = 14;
								invest = 11;
								foodname = "Mango Smoothie";
								break;
							case 4:
								price = 14;
								invest = 11;
								foodname = "Strawberry Smoothie";
								break;
							case 5:
								price = 15;
								invest = 12.5;
								foodname = "Cookie n Cream Smoothie";
								break;
							case 6:
								price = 7;
								invest = 6;
								foodname = "Iced Lemon Tea";
								break;
							case 7:
								price = 8;
								invest = 7;
								foodname = "Iced Chocolate";
								break;
						}
					}
					
					else if(choice == 'S')
					{
						cout<<"Enter Code: ";
						cin>>code;
						while(code < 1 or code > 6)
						{
							cout<<"Please enter valid code."<<endl;
							cout<<"Enter Code: ";
							cin>>code;
						}
						
						switch(code)
						{
							case 1:
								price = 6;
								invest = 4.5;
								foodname = "Fries";
								break;
							case 2:
								price = 6;
								invest = 4;
								foodname = "Nuggets";
								break;
							case 3:
								price = 6;
								invest = 4;
								foodname = "Chicken Popcorn";
								break;
							case 4:
								price = 6;
								invest = 5;
								foodname = "Apple Pie";
								break;
							case 5:
								price = 6;
								invest = 4.5;
								foodname = "Fried Ice Cream";
								break;
							case 6:
								price = 6;
								invest = 4.5;
								foodname = "Brownies";
								break;
						}
					}
					
					else
					{
						cout<<"Please enter valid variant."<<endl;
					}
				}
				
				//for customer receipt
				singleprice = calcprice(price, tax);
				totaltax = totaltax + tax;
				totalprice = totalprice + singleprice;
				pricebefore = pricebefore + price;
				name[counter] = foodname;
				receiptprice[counter] = price;
				counter++;
				choice = 'Q';
				
				//for admin receipt
				profit = (price * 1.03) - invest;
				govtax = govtax + (price * 0.06);
				totalprofit = totalprofit + profit;
				totalexpension = totalexpension + invest;
				totalincome = totalincome + singleprice;
				cout<<"Do you want to add order? [Yes/No]: ";
				cin>>answer[2];
				
				while(answer[2] != "Yes" and answer[2] != "No")
				{
					cout<<"Please enter valid answer."<<endl;
					cout<<"Do you want to add order? [Yes/No]: ";
					cin>>answer[2];
				}
				
				//receipt for food purchased
				if(answer[2] == "No")
				{
					cout<<fixed<<setprecision(2)<<endl<<endl;
					cout<<"-----------------------------------"<<endl;
					cout<<setw(23)<<"Zaya's Cafe"<<endl;
					cout<<"-----------------------------------"<<endl<<endl;
					cout<<setw(30)<<left<<"Name"<<setw(50)<<"Price"<<endl;
					cout<<"-----------------------------------"<<endl;
					for(int i = counter; i > 0; i--)
					{
						foodreceipt(name[printer], receiptprice[printer], counter);
						printer++;
						
					}
					
					receipt(totaltax, totalprice, counter, pricebefore);
					
					//sleep(100);
					//resetting values for next user.
					totaltax = 0;
					counter = 0;
					answer[0] = "Yes";
					printer = 0;
					totalprice = 0;
					pricebefore = 0;
					clearoutput();
					choice = 'Q';
				}
			}
		}
		
		
		//staff login for cafe related output/receipt
		else if(answer[1] == "No")
		{
			cout<<"Login [1]            Menu [0] :  ";
			cin>>login;
			
			if(login == 1)
			{
				while(check == false)
				{
					system("cls");
					cout<<"Enter username: ";
					cin>>username;
					cout<<"Enter password: ";
					cin>>password;
					
					if(username == "Zainab" and password == "Zainab123")
					{
						system("cls");
						cout<<"Hello Zainab Binti Othman"<<endl<<endl;
						check = true;
					}
					
					else if(username == "Amie" and password == "Amie123")
					{
						system("cls");
						cout<<"Hello Najmi Latifi"<<endl<<endl;
						check = true;
					}
					
					else if(username == "Raja" and password == "Raja123")
					{
						system("cls");
						cout<<"Hello Raja Muhammad Idris Bin Raja Shahrul Azlan"<<endl<<endl;
						check = true;
					}
					
					else if(username == "Arfah" and password == "Arfah123")
					{
						system("cls");
						cout<<"Hello Arfah"<<endl<<endl;
						check = true;
					}
				}
				
				adminreceipt(totalexpension, totalprofit, totalincome, govtax),
				answer[0] = "No";
			}
			
			else
			{
				answer[0] = "Yes";
			}
		}
		
		else
		{
			cout<<"Please enter valid answer."<<endl;
			sleep(1);
		}
	}
}

void menu()
{
	cout<<"\n \t\t\t\t========================= Zaya's Menu ========================= ";
	cout<<"\n";
	cout<<"\n \t\t\t\t                          == Combo ==                           ";
	cout<<"\n \t\t\t\t   (with Zaya Signature Coffee and preferred Snack or Dessert)  ";
	cout<<"\n";
	cout<<"\n [Code]                                             [Price]\t   [Code]                                  [Price]";
	cout<<"\n  [1] Chicken Chop                                   33.00\t   [6] Fish & Chips                         29.00";
	cout<<"\n  [2] Lamb Chop                                      37.00\t   [7] Zaya Beef Burger                     34.00";
	cout<<"\n  [3] Mac & Cheese                                   28.00\t   [8] Spaghetti Aglio Olio                 30.00";
	cout<<"\n  [4] Spaghetti Chicken Bolognese                    30.00\t   [9] Spaghetti Salted Egg Prawn           32.00";
	cout<<"\n  [5] Spaghetti Carbonara                            30.00\t   [0] Lasagna                              32.00";
    cout<<"\n";
	cout<<"\n \t\t\t\t                         == Western ==                            ";
	cout<<"\n";
	cout<<"\n [Code]                                             [Price]\t   [Code]                                  [Price]";
	cout<<"\n  [1] Chicken Chop                                   18.00\t   [3] Fish & Chips                         14.00";
	cout<<"\n  [2] Lamb Chop                                      22.00\t   [4] Zaya Beef Burger                     19.00";
	cout<<"\n";
	cout<<"\n \t\t\t\t                          == Pasta ==                            ";
	cout<<"\n";
	cout<<"\n [Code]                                             [Price]\t   [Code]                                  [Price]";
	cout<<"\n  [1] Mac & Cheese                                   13.00\t   [4] Spaghetti Aglio Olio                 15.00";
	cout<<"\n  [2] Spaghetti Chicken Bolognese                    15.00\t   [5] Spaghetti Salted Egg Prawn           17.00";
	cout<<"\n  [3] Spaghetti Carbonara                            15.00\t   [6] Lasagna                              17.00";
    cout<<"\n";
	cout<<"\n \t\t\t\t                         == Coffee ==                    ";
	cout<<"\n";
	cout<<"\n [Code]                                             [Price]\t   [Code]                                  [Price]";
	cout<<"\n                                                 [Iced] [Hot]\t                                        [Iced] [Hot]";
	cout<<"\n  [1] Caramel Macchiato                          13.00  12.00\t   [4] Cappuccino                       12.00  11.00";
	cout<<"\n  [2] Caffe Mocha / White Mocha                  12.00  11.00\t   [5] Signature Zaya Coffee            15.00  14.00";
	cout<<"\n  [3] Caffe Latte                                11.00  10.00\t   [6] Americano                        11.00  10.00";
    cout<<"\n";
	cout<<"\n \t\t\t\t                       == Non Coffee ==                          ";
	cout<<"\n";
	cout<<"\n [Code]                                             [Price]\t   [Code]                                  [Price]";
	cout<<"\n  [1] Kiwi Smoothie                                  14.00\t   [5] Cookie n Cream Smoothies             15.00";
	cout<<"\n  [2] Lemonade Smoothie                              14.00\t   [6] Iced Lemon Tea                       7.00";
	cout<<"\n  [3] Mango Smoothie                                 14.00\t   [7] Iced Chocolate                       8.00";
    cout<<"\n  [4] Strawberry Smoothie                            14.00";
    cout<<"\n";
	cout<<"\n \t\t\t\t                    == Snacks & Desserts ==                          ";
	cout<<"\n";
	cout<<"\n [Code]                                             [Price]\t   [Code]                                  [Price]";
	cout<<"\n  [1] Fries                                          6.00 \t   [4] Apple Pie                            6.00";
	cout<<"\n  [2] Nugget                                         6.00 \t   [5] Fried Ice Cream                      6.00";
	cout<<"\n  [3] Chicken Popcorn                                6.00 \t   [6] Brownies                             6.00";
    cout<<"\n";
    cout<<endl<<endl;
}

//countdown before clearing output
void clearoutput()
{
	for(int i = 9; i>-1; i--)
	{
		cout<<"Page will be cleared in "<<i<<"\r";
		sleep(1);
	}
	system("cls");
}

//calculating price with tax
double calcprice(double price, double& totaltax)
{
	double total, tax = 0.09;
	
	totaltax = price * tax;
	total = total + price + totaltax;
	return total;
}

//printing every name and price of food in receipt
void foodreceipt(string foodname, double foodprice, int counter)
{
	
	cout<<setw(30)<<left<<foodname;
	cout<<setw(50)<<foodprice<<endl;
}

//printing receipt
void receipt(double totaltax, double totalprice, int counter, double totalpricebeforetax)
{
	cout<<"-----------------------------------"<<endl;
	cout<<setw(6)<<left<<"Total "<<setw(1)<<left<<counter<<setw(23)<<left<<" item(s)"<<setw(50)<<totalpricebeforetax<<endl;
	cout<<setw(30)<<left<<"Tax"<<setw(50)<<totaltax<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<setw(30)<<left<<"Total"<<setw(50)<<totalprice<<endl<<endl;
	cout<<"==================================="<<endl;
	cout<<"\t     Thank you!"<<endl<<endl<<endl;
}

//receipt after staff successfully logged in
void adminreceipt(double totalexpenses, double profit, double totalincome, double government)
{
	cout<<"Total income for today is RM"<<totalincome<<endl;
	cout<<"Total expenses for today is RM"<<totalexpenses<<endl;
	cout<<"Total government tax for today is RM"<<government<<endl;
	cout<<"Total profit for today is RM"<<profit<<endl;
}
