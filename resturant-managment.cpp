/*
4/29/22------------------------------------------------------>date
This resturant managment system was made by AASTU second year students to manage 
a renowned resturant called A+ lounge in AASTU
*/
#include<iostream>
#include <stdlib.h>
using namespace std;
/*defining some constants*/
#define  NEW "\n" // New Line
/*Making Array Accessible*/
/*Order List Array Column*/
#define TABLE_NUMBER   0 // Customers Table Number
#define NUMBER_OF_FOOD 1 // Total Food Ordered 
#define TOTAL_PRICE    2 // Total Price For Each Customers Orders
#define INDEX          3 // Payment Confirmation Index
/*Ordered Food List Column Index*/
#define FOOD_LIST    0 // Index For Food Code
#define AMOUNT       1 // Index For Food Amount
/*Function Declaration*/
void firstPage();
int optionPage(char opt);
int previousOrder();
int listOfFoods();
int makeOrder();
void headerLogo();
void setFoodList(int foodCode, int amount , int orderNumber, int index);
void setOrderList(int totalOrder, float totalPrice, int table_number, int orderNumber);
void show_order_detail(int total_food, float total_price, int table_number, int order_number);
float foodPrice(int order);
int getTotalOrder();
string foodName(int order);
int getOrderNumber(int table_number);
void adminLogo();
int adminDashboard();
void showAllOreder();
void  drinks(int totalOrder, float totalPrice, int table_number,int order, int amount,int orderNumber, int index);
int manegeMenu();
void deliver();
void about();

/*End Of Declaration*/
/*Initialazing Some Constants*/
const int MAX_ORDER=500; // Maximum Order The Restourant Can Take
const int TOTAL_FOOD=33; // Maximum Number Of Food That Can Be Availabe In The Resturant
const int ORDER_COLUMN=4; // Orderlist Arry Column Size
const int FOOD_COLUMN=2; // Food List And Ordered Food List Coulumn Size

/*Creating Storage Array*/
float order_list[MAX_ORDER][ORDER_COLUMN];//Order Data Array
int ordered_food_list[MAX_ORDER][TOTAL_FOOD][FOOD_COLUMN];//Ordered Food List
string food_list[TOTAL_FOOD][FOOD_COLUMN]={
/* List Of Food Served Cassualy, Some Foods Can Be Cancelled Or Added By Admin*/
{		"Name             ",	"Price"	},
{		"Enkulal Firfir   ",	"30"	},
{		"Dabo Firfir      ",	"20"	},
{		"Pasta Be Enkulal ",	"30"	},
{		"Dinich Be Enkulal",	"30"	},
{		"Pasta Be Sigo    ",	"25"	},
{		"Pasta Be Atikilt ",	"25"	},
{		"Enjera Firfir    ",	"25"	},
{		"Special Firfir   ",	"35"	},
{		"Siga Firfir      ",	"45"	},
{		"Minchet          ",	"45"	},
{		"Enkulal Be Siga  ",	"40"	},
{		"Pasta Be Siga    ",	"40"	},
{		"Tegabino         ",	"28"	},
{		"Timatim          ",	"25"	},
{		"Dinich           ",	"25"	},
{		"Misir            ",	"25"	},
{		"sandwich         ",	"20"	},
{		"0         ",	"0"	},
{		"0         ",	"0"	},
{		"0         ",	"0"	},
{		"0         ",	"0"	},
{		"0         ",	"0"	},
{		"0         ",	"0"	},
{		"0         ",	"0"	},
// List Of Availabe Drinks
{		"Shay         ",	"4"	},
{		"Buna         ",	"5"	},
{		"Spris        ",	"5"	},
{		"Wetet        ",	"10"	},
{		"Coca         ",	"15"	},
{		"Sprit        ",	"15"	},
{		"Fanta        ",	"15"	},
{		"Mirinda      ",	"15"	},

};

/* The Start Of The Main Function*/

int main(){
	system("COLOR A"); // Setting Color Of The System To Green
	
firstPage();
system("pause"); // Used To Halt The Exceution Of The Parent Cpp Program
    return 1;
}
/*function prototyping*/
void firstPage(){
// Welcome Page Menu	
	char opt; //First Page Menu Input 
cout<<NEW;
cout<<"\t\t                      ___   ___   ___  _____         \n";           
cout<<"\t\t                     |   | |   | |       |   |   |   \n";            
cout<<"\t\t                     |-+-| |-+-|  -+-    +   |   |   \n";           
cout<<"\t\t                     |   | |   |  ___|   |   |___|   \n";             
cout<<"\t                                                       \n";        
cout<<"\t\t   ___   ___   ___   ___         ___   ___   ___   ___   ___      \n";  
cout<<"\t\t  |     |   | |   |   | |       |   | |   |   | | |     |   |     \n";  
cout<<"\t\t  |-+-  |   | |   |   + |       |   | |-+-    + | |-+-  |-+-      \n";  
cout<<"\t\t  |     |___| |___|  _|_|       |___| |   \\  _|_| |___  |  \\      \n";
cout <<endl;  
cout<<"\t  ******************************!******************************************* \n";  
cout<<"\t ***************             WELCOME                     ******************** \n";  
cout<<"\t  ***************** ALWAYS HAPPY TO SERVE YOU ****************************** \n";  

cout<<"\t        1. Customer \n";
cout<<"\t        2. Admin \n";
cout<<"\t        3. About \n";
cout<<"\t        4. Exit \n";
loop1:
cout<<"\tPlease Select One: "; 
cin>>opt;
// Input Validation
if(opt=='1'||opt=='2'||opt=='3'||opt=='4'){
system("cls");
 optionPage(opt); 	

}else{
goto loop1;
}
                                                                                                                                                                                                                                                                             
}
// Logos... The Logos Will Make Sense When The Program Runs
void headerLogo(){
cout<<"\t \n";
cout<<"\t***{}*****************************************************************************************{}***\n";
cout<<"\t*  ||                                   ___   ___   ___   ___   ___                           ||  *\n";
cout<<"\t*  )(                                  |   | |   |   | | |     |   |                          )(  *\n";
cout<<"\t* |__|                -+-   -+-   -+-  |   | |-+-    + | |-+-  |-+-   -+-   -+-   -+-        |__| *\n";
cout<<"\t* |  |                                 |___| |   \\  _|_| |__   |   \\                         |  | *\n";
cout<<"\t* |__|                                                                                       |__| *\n"; 
cout<<"\t************************************ ALWAYS HAPPY TO SERVE YOU ************************************\n";                                                                               
cout<<"\t \n";	
	
}
void adminLogo(){
	
cout<<"\t \n";
cout<<"\t****************************************************************************************************\n";	
cout<<"\t*                         _______   ______    _______  _________  _                                *\n";
cout<<"\t*                        (  ___  ) (  __  \\  (       ) \\__   __/ ( (    /|                         *\n";
cout<<"\t*                        | (   ) | | (  \\  ) | () () |    ) (    |  \\  ( |                         *\n";
cout<<"\t*                        | (___) | | |   ) | | || || |    | |    |   \\ | |                         *\n";
cout<<"\t*        -+-   -+-   -+- |  ___  | | |   | | | |(_)| |    | |    | (\\ \\) | -+-   -+-   -+-         *\n";
cout<<"\t*                        | (   ) | | |   ) | | |   | |    | |    | | \\   |                         *\n";
cout<<"\t*                        | )   ( | | (__/  ) | )   ( | ___) (___ | )  \\  |                         *\n";
cout<<"\t*                        |/     \\| (______/  |/     \\| \\_______/ |/    )_)                         *\n";  
cout<<"\t*                                                                                                  *\n";                                      
cout<<"\t************************************ ALWAYS HAPPY TO SERVE YOU *************************************\n";                                                                               
cout<<"\t \n";   

}
int adminDashboard(){
	adminLogo(); // Calling The Admin Logo Function
	char opt;                                         
        cout<<"\t\t\t\t1. View All Orders\n";
		cout<<"\t\t\t\t2. Manage Menu\n";
		cout<<"\t\t\t\t3. Serve Food \n";
		cout<<"\t\t\t\t4. Exit\n";                                     
          
		cout<<"\t\t\t\tPlease Choose One Of The Three: ";                                     
               cin>>opt; 
               
			   
	switch(opt){
        case '1':{	system("cls"); // Clearing The Page 
               		showAllOreder();  
					break;
				   }
		case '2':{
				system("cls"); // Clearing The Page
				
			manegeMenu(); 
			break;
		}
		case '3':{
				system("cls"); // Clearing The Page
	deliver();
 
		
		}
		case '4':{
				system("cls");exit(1); //Exiting The Terminal
			break;
		}
		default:{
			adminDashboard();
			break;
		}
			   }
			                        
	
}
void showAllOreder(){
int total_food,table_number, orderNumber=getTotalOrder(),ticket;
 float total_price;
  system("cls");
adminLogo();
if(orderNumber!=0){
	cout<<"\t\tList Of All Orders\n";
  for(int k=0; k<orderNumber; k++){
total_food=order_list[k][NUMBER_OF_FOOD];
if(total_food==0){
orderNumber+=1;
continue;
}else{

  	table_number=order_list[k][TABLE_NUMBER];
  	 cout<<"\t+==================+\n";
  cout<<"\t| Ticket Number: "<<table_number+2<<" | ************************************************************************************"<<NEW;
  cout<<"\t+==================+\n";
   cout<<" \tITEM\t\t\t\tQUANTITY\tUNIT PRICE\tTOTAL AMOUNT OF SALE\n";
 
  total_price=order_list[k][TOTAL_PRICE];
  for(int i=0;i<total_food;i++){
  
  	  cout<<" \t["<<i+1<<"]"<<foodName(ordered_food_list[k][i][0])<<"\t\t"<<ordered_food_list[k][i][1]<<"\t\t"<<foodPrice(ordered_food_list[k][i][0])<<"\t\t"<< foodPrice(ordered_food_list[k][i][0])* ordered_food_list[k][i][1]<<"\n";
  }

  cout<<"\tTable Number: "<<table_number<<NEW;
 
  cout<<"\tTotal Price: "<<total_price<<"\t\tPayment Code: 25KX1\n"; 
cout<<"\t*********************************************************************************************************\n";	
cout<<NEW;}
}
cout<<"\t\tPress Any Key To Go Back: ";
int c; cin>>c;
system("cls");	
firstPage();
}else{
	cout<<"\t\tThere Are No Orders\n";
cout<<"\t\t\tPress Any Key To Go Back: ";
int c; cin>>c;
system("cls");	
firstPage();
}
		
}
int manegeMenu(){
	system("cls");
	adminLogo();
		cout<<"\n\t-----FOOD-------------PRICE\t\t\t-----FOOD-------------PRICE"<<endl;

for (int row = 1; row <25; row ++)

{ 
float price =atof(food_list[row][1].c_str());
if(price>0){


cout<< "\t"<<row<<":";
for (int col= 0; col<2; col++){
     if(price==1){
	if(col==1){
		cout<<"Not Available";cout<<" ";
	}
	else{
		cout<<food_list[row][col];

	cout<<"\t";	
	}
	
}
else{
	cout<<food_list[row][col];

	cout<<"\t";	
}

	
}
if ((row-1)%2!=0)
{
cout<<"\n";}
else {
	cout << '\t';
}
}}
 cout<<"\n\t**************************************************************************"<<endl;
 
	cout<<"\t\t1.Add Food\n";
	cout<<"\t\t2.Remove Food\n";
	cout<<"\t\t3.Update Price\n";
	 cout<<"\t\t4.Back to Main Menu\n";
	 cout<<"\t=>Please, Select One Of The Options ";
	 char opt;
	 cin>>opt;
	 switch(opt){
	 	case '1':{//Adding Food To The Food List
	 			system("cls");
	adminLogo();
	string name, price;
	cout<<"\n\t\tInput the Name of Food: ";
	 		cin>> name;
			 	
	cout<<"\n\t\tInput The Price Of The Food: "; 		
	 		cin>>price;
	 		
	int lastFoodIndex=0;
	
   for(int i=0; i<24;i++){
   	float price =atof(food_list[i][1].c_str());
   	if(price>0){
   		lastFoodIndex+=1;
	   }		   
   }
   lastFoodIndex+=1;
	 	
	 		
	 	food_list[lastFoodIndex][0]=name+"     ";	
	 	food_list[lastFoodIndex][1]="     "+price;
	 	
	 		cout<<	"\t\t=> Food Has Been Added\n";
	 		cout<<	"\t\t Enter Any Key To Finish";
	 			char key;
	 				cin>>key;
	 					system("cls");
	 				firstPage();
			break;
		 }
		 case '2':{
		 		system("cls");
		 		adminLogo();
	int index; 
	cout<<"\n\t\tInput Number Of The Food You Want To Remove: ";
	 		cin>>index;		

	 		food_list[index][1]="1";
	 		cout<<	"\t\t=> Food Has Been Removed\n";
	 		cout<<	"\t\t Enter Any Key To Finish ";
	 			char key;
	 				cin>>key;
	 					system("cls");
	 				firstPage();
			break;
		 }
		 case '3':{
		 		system("cls");
	adminLogo();
	int index; string nprice;
	cout<<"\n\t\tInput The Food Nunber: ";
	 		cin>>index;		
cout<<"\t\tInput The New Price: ";
cin>>nprice;
	 			food_list[index][1]=nprice;
	 		cout<<	"\t\t=> Price Has Been Updated\n";
	 		cout<<	"\t\t Enter Any Key ";
	 			char key;
	 				cin>>key;
	 					system("cls");
	 				firstPage();
			break;
		 }
		 case '4':{
		 	system("cls");
		 	firstPage();
			break;
		 }
		 default:{
			break;
			manegeMenu();
		 }
	 }
	
}
int optionPage(char opt){
headerLogo(); 
switch(opt){
	case '1'://Customer Or Admin Case 1
		{
			char main_opt;
		cout<< endl
		<<"\t\t\t\t    What You Want To Do " << endl
		<<"\t\t\t\t===========================" << endl
		<<"\t\t\t\t\tMAIN OPTIONS : There are "<< getTotalOrder()<<" Orders before you " << endl /* total orders left*/
		<<"\t\t\t\t1--> Order now " << endl
		<<"\t\t\t\t2--> View your orders " << endl
		<<"\t\t\t\t3--> Back to First Page" << endl
		<<"\t\t\t\t4--> Quit" << endl;
	cout<<"\t\t\t\tPlease choose one of the three: ";
		cin>>main_opt;
switch(main_opt){
	case '1'://customer case 1
		{
			makeOrder();
			break;
		}
	case '2'://customer case 2
		{
		previousOrder();	
			break;
		}
	case '3':{//customer case 3
		system("cls");
		firstPage();
	}
	case '4'://customer case 4
	{
	system("cls");
		exit(0);
		break;	
		
}
default://customer case  default
	{
	optionPage('1');	
	}
		break;	
		}
	case '2'://customer or admin case 2
	{system("cls");
 adminDashboard();
		break;
		}
		case '3':{
			about();
			break;
		}
	case '4'://customer or admin case 3
	{
		system("cls");
		exit(0);
		break;
		
		}	
	default:
	{	system("cls");
		firstPage();
		
		}	
	
}
	return 0;
}}
int previousOrder()// Displaying The Previous Order For The Customer
{
 int total_food,table_number, orderNumber,ticket;
 float total_price;
  system("cls");
headerLogo();
cout<<"\n\t\tPlease, Input Your Ticket Number: ";
cin>>ticket;
table_number=ticket-2;
orderNumber=getOrderNumber(table_number);//GET THE INDEX OF ROW THAT CONTAINS THE GIVEN TABLE NUMBER

 total_food=order_list[orderNumber][NUMBER_OF_FOOD];
  total_price=order_list[orderNumber][TOTAL_PRICE];
  
  
if(total_food!=0){

 cout<<" \tYou have ordered:\n\n";
   cout<<" \tITEM\t\t\t\tQUANTITY\tUNIT PRICE\tTOTAL AMOUNT OF SALE\n";
  
  for(int i=0;i<total_food;i++){
  
  	  cout<<" \t["<<i+1<<"]"<<foodName(ordered_food_list[orderNumber][i][0])<<"\t\t"<<ordered_food_list[orderNumber][i][1]<<"\t\t"<<foodPrice(ordered_food_list[orderNumber][i][0])<<"\t\t"<< foodPrice(ordered_food_list[orderNumber][i][0])* ordered_food_list[orderNumber][i][1]<<"\n";
  }
  cout<<"\tService Code: "<<order_list[orderNumber][3]<<"\n";
  cout<<"\tTable Number: "<<table_number<<NEW;
  cout<<"\t+==================+\n";
  cout<<"\t| Ticket Number: "<<table_number+2<<" |"<<NEW;
  cout<<"\t+==================+\n";
  cout<<"\tTotal Price: "<<total_price<<"\t\tPayment Code: 25KX1\n"; 
		cout<<"\n\t\tEnter Any Key To Go Back: ";
	int key;

	cin>>key;
	system("cls");
	optionPage('1');
}
else{
	cout<<"\n\t\tYou Have Not Ordered Yet! Go Back And Order";
	cout<<"\n\t\tEnter Any Key To Go Back: ";	
	int key;
	cin>>key;
	system("cls");
	optionPage('1');
}
	return 0;
}
int listOfFoods(){
	system("cls");
	headerLogo();
	
	cout<<"\t\t\t\t******HERE ARE LIST OF FOODS********"<<endl;
		cout<<"\n\t-----FOOD-------------PRICE\t\t\t-----FOOD-------------PRICE"<<endl;

for (int row = 1; row <25; row ++)

{ 
float price =atof(food_list[row][1].c_str());
if(price>0){


cout<< "\t"<<row<<":";
for (int col= 0; col<2; col++){
     if(price==1){
	if(col==1){
		cout<<"Not Available";cout<<" ";
	}
	else{
		cout<<food_list[row][col];

	cout<<"\t";	
	}
	
}
else{
	cout<<food_list[row][col];

	cout<<"\t";	
}

	
}
if ((row-1)%2!=0)
{
cout<<"\n";}
else {
	cout << '\t';
}
}}
 cout<<"\n\t**************************************************************************"<<endl;
 
}
int makeOrder(){
	int index=-1, rawr, order,amount, totalOrder=0, price=0, table_number, orderNumber=getTotalOrder();
	float totalPrice=0.0;
listOfFoods();// DISPLAY LIST OF FOODS
	cout<<"\tWhat is your table number: ";
	cin>>table_number;
loop1:
	
    cout<<"\t[+]What do you like to order from the list of foods: ";
    cin>>order;
 	int lastFoodIndex=0;
	
   for(int i=0; i<24;i++){
   	float price =atof(food_list[i][1].c_str());//changing string price to float
   	if(price>0){
   		lastFoodIndex+=1;//count the number of food on the list
	   }		   
   }
  
    
    while(order<1||order>lastFoodIndex) 	{//food code validation
    	cout<<"\t[X]Please choose a valid item from the list\n";
    	goto loop1;
	}  
	while(foodPrice(order)==1){
			cout<<"\t[X]Item Not Available \n";
    	goto loop1;
	}
	loop2:
     cout<<"\t[+]How many do you like to order : ";
     cin>>amount;
   if(amount<=0){///amount validation
   	cout<<"\t[X]Please Enter a valid Amount\n";
   	goto loop2;
   }
    
     cout<<"\t\t[1] To Update Previous Order:"<<NEW<<"\t\t[2] To Order Again:"<<NEW<<"\t\t[0] To Finish ";
   cin >> rawr;
	if(rawr==1) {
			cout<<"\t[X]Order canceled!\n";
    	goto loop1;
	}else if(rawr==2){
		totalOrder+=1;
		index+=1;
		  totalPrice+=amount*foodPrice(order);//accesing the food price from food list array
		 setFoodList(order, amount, orderNumber, index);//insert the food and amount that the user entered
			goto loop1;
	}else{
		totalOrder+=1;
	index+=1;
	  totalPrice+=amount*foodPrice(order);
    	setFoodList(order, amount, orderNumber, index);//storing the data to food list array
     drinks(totalOrder, totalPrice, table_number,order, amount, orderNumber, index);//showing the user drink options

}
}
/******storing order data to an array*******/
void setOrderList(int totalOrder, float totalPrice, int table_number, int orderNumber){ //place order data to the array

order_list[orderNumber][0]=	table_number;//Insert Table Number
		 order_list[orderNumber][1]=	totalOrder; //Insert Total Order
			 order_list[orderNumber][2]=totalPrice;//Insert Total Price
			 order_list[orderNumber][3]=table_number+1000;//Service Code

	
}
/***show the user his order**/
void show_order_detail(int total_food, float total_price, int table_number, int order_number){ //display the orders for the user and confirmation

  system("cls");
headerLogo();
int conf;
 cout<<" \tYou have ordered:\n\n";
   cout<<" \tITEM\t\t\t\tQUANTITY\tUNIT PRICE\tTOTAL AMOUNT OF SALE\n";
  
   
  for(int i=0;i<total_food;i++){//print all olders
  
  	  cout<<" \t["<<i+1<<"]"<<foodName(ordered_food_list[order_number][i][0])<<"\t\t"<<ordered_food_list[order_number][i][1]<<"\t\t"<<foodPrice(ordered_food_list[order_number][i][0])<<"\t\t"<< foodPrice(ordered_food_list[order_number][i][0])* ordered_food_list[order_number][i][1]<<"\n";
  }
  cout<<"\tService Code: "<<order_list[order_number][3]<<"\n";
  cout<<"\tTable Number: "<<table_number<<NEW;
  cout<<"                                  \t+==================+\n";
  cout<<"\tPlease hold Your Ticket No => "<<"\t| Ticket Number: "<<table_number+2<<" |"<<NEW;
  cout<<"                                  \t+==================+\n";
  cout<<"\tTotal Price: "<<total_price<<"\t\t\tPayment Code: 25KX1";
  cout<<"\n\tConfirm Your Order: Press Any Key to Confirm Execpt [0]: ";
  getTotalOrder();
  cin>>conf;
if(conf!=0){
/*  payment*/
cout<<NEW;
cout<<"\t\t\t*******************************************************\n";
cout<<"\t\t\t**   Order has been Confirmed! go back to main menu  **\n";
cout<<"\t\t\t*******************************************************\n";
int key;
	cout<<"\tInput any key to go back: ";
cin>>key;
system("cls");
optionPage('1');
}else{

	cout<<"\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	cout<<"\t\t\tXX Order canceled return to main menu XX\n";
	cout<<"\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	cout<<"\t\t\tInput any key to go back: ";

	 
	for(int j=0; j<4; j++){
   		order_list[order_number][j]=0;//Makimg The List Empty
   		
	   }
	   for(int i=0; i<total_food; i++){
	   	  for(int k=0;k<2;k++){
	   	ordered_food_list[order_number][i][k]=0;//Make The List Empty
	   }
}
	int key;cin>>key;
	system("cls");
	optionPage('1');	
}

}
	
void setFoodList(int foodCode, int amount , int orderNumber, int index){//store ordered food name and amount

 ordered_food_list[orderNumber][index][0]=foodCode;//place the food code 
  ordered_food_list[orderNumber][index][1]=amount;// place the amount of food

	
}

float foodPrice(int order){
float price =atof(food_list[order][1].c_str()); //Changing A String Data Type To Float
	
	return price;//Get Price From The Array And Retunrn It As Float
	
}
string foodName(int order){
return food_list[order][0];	// Return Food Name From The Food List Array
}
int getTotalOrder(){ //Count The Total Order And Retunn The Last Index Of The Order List Array
	int order=0;
   for(int i=0; i<500;i++){
   	
   	if(order_list[i][0]!=0){
   		order+=1; //Count Total Row Index, That Contain The Food Code
	   }	
   			   	   
   }

return order;

}
   int getOrderNumber(int table_number){ //Get The Index Of Order List Array That Has The Given Table Number To Access The Row
   		int orderNumber=-1;
   	 for(int i=0; i<500;i++){
   	
   	if(order_list[i][TABLE_NUMBER]==table_number){
   		 orderNumber=i;
	   }
}
   	return orderNumber;//Return The Index That Contain The Table Number
   
}
void about(){
	system("cls");
	system("COLOR 1");
cout<<"\t\t                      ___   ___   ___  _____         \n";           
cout<<"\t\t                     |   | |   | |       |   |   |   \n";            
cout<<"\t\t                     |-+-| |-+-|  -+-    +   |   |   \n";           
cout<<"\t\t                     |   | |   |  ___|   |   |___|   \n";             
cout<<"\t                                                       \n";        
cout<<"\t\t   ___   ___   ___   ___         ___   ___   ___   ___   ___      \n";  
cout<<"\t\t  |     |   | |   |   | |       |   | |   |   | | |     |   |     \n";  
cout<<"\t\t  |-+-  |   | |   |   + |       |   | |-+-    + | |-+-  |-+-      \n";  
cout<<"\t\t  |     |___| |___|  _|_|       |___| |   \\  _|_| |___  |  \\      \n";
cout <<endl;  
cout<<"\t  ******************************!******************************************* \n";  
cout<<"\t ***************             WELCOME                     ******************** \n";  
cout<<"\t  ***************** ALWAYS HAPPY TO SERVE YOU ****************************** \n";  
cout<<"\n";
cout<<"\t This resturant managment system was made by AASTU second year students \n"
<<"\t to manage a renowned resturant called A+ lounge in AASTU";	
cout<<"\n\t Contributers";
cout<<"\n\t\t1. Nebyat Bekele\n\t\t2. Rebuma Tadele\n\t\t3. Ruth Asmamaw\n\t\t4. Ruhama Ashenafi\n\t\t5. Sahib Getu\n\t\t6. Rediet H/Mariam";
cout<< "\n\t Contact: cty0242@gmail.com";
	cout<<"\n\t Press Any Key To Go Back: ";
int c; cin>>c;
system("cls");
	system("COLOR A");	
firstPage();
	
	
}
// THE DRINIK ORDERING OPTION 
 void drinks(int totalOrder, float totalPrice, int table_number,int order, int amount, int orderNumber, int index){
system("cls");
	headerLogo();
	int rawr;
	cout<<"\t\t\t\t******DO YOU WANT A DRINK WITH THAT********"<<endl;
		cout<<"\n\t-----DRINK-------------PRICE\t\t\t-----DRINK-------------PRICE"<<endl;

for (int row = 25; row <33; row ++)

{ 
float price =atof(food_list[row][1].c_str());//converting string price in to float price
if(price>0){


cout<< "\t"<<" "<<row-24<<":";
for (int col= 0; col<2; col++){
     if(price==1){//check weather the food is available
	if(col==1){
		cout<<"NOT AVAILABLE";cout<<" ";
	}
	else{
		cout<<food_list[row][col];//print the foods

	cout<<"\t";	
	}	
}
else{
	cout<<food_list[row][col];

	cout<<"\t";	
}	
}
if ((row-25)%2!=0)
{
cout<<"\n";}
else {
	cout << '\t';
}
}}
 cout<<"\n\t**************************************************************************"<<endl;
 char opt;
 cout<<"\t\tDo You Want Any Drink?\n\t[1]Yes\n\t[0]No: ";
 cin>>opt;
       switch(opt){
       	case'0':{
       				 setOrderList(totalOrder, totalPrice, table_number, orderNumber);//insert the data in to order list array
	 	
    show_order_detail(totalOrder, totalPrice, table_number, orderNumber);// go to order confirmation
     index=-1;
     
			break;
		   }
		   case'1':{
		   	loop1:
	
    cout<<"\t[+]Pick A Drink From The List: ";
    cin>>order;
    order=order+24;
 	int lastFoodIndex=25;
	
   for(int i=25; i<34;i++){
   	float price =atof(food_list[i][1].c_str());
   	if(price>0){
   		lastFoodIndex+=1;
	   }		    
    while(order<1||order>32) // Validation
		{
    	cout<<"\t[X]Please choose a valid item from the list\n";
    	goto loop1;
	}
	while(foodPrice(order)==1){
			cout<<"\t[X]Item is Not Available Right now \n";
    	goto loop1;
	}
	loop2:
     cout<<"\t[+]How many do you like to order : ";
     cin>>amount;
   if(amount<=0){
   	cout<<"\t[X]Please Enter a valid Amount\n";
   	goto loop2;
   }   
     cout<<"\t\t[1] To Update Previous Order:"<<NEW<<"\t\t[2] To Order Again:"<<NEW<<"\t\t[0] To Finish ";
   cin >> rawr;
	if(rawr==1) {
			cout<<"\t[X]Order canceled!\n";
    	goto loop1;
	}else if(rawr==2){
		totalOrder+=1;
		index+=1;
		  totalPrice+=amount*foodPrice(order);//get total price
		 setFoodList(order, amount, orderNumber, index);//storing the data
			goto loop1;
	}else{
		totalOrder+=1;
	index+=1;
	  totalPrice+=amount*foodPrice(order);
    	setFoodList(order, amount, orderNumber, index);
    		 setOrderList(totalOrder, totalPrice, table_number, orderNumber);
	 	
    show_order_detail(totalOrder, totalPrice, table_number, orderNumber);
     index=-1;
			break;
		   }
	   }
}}}
// serving the food 
void deliver(){
	 adminLogo();
	 int code, row, total_food;
	  loop1:
	 cout<<"\t\tPlease Input Service code: ";
	 cin>>code;
	 
	 if(code>1000){
	 	
 row=getOrderNumber(code-1000);// geting the index that contains the service code
	total_food=order_list[row][NUMBER_OF_FOOD];	
// clearing the order from the order list after its served
   	for(int j=0; j<4; j++){
   		order_list[row][j]=0;//make the list empty
   		
	   }
	   for(int i=0; i<total_food; i++){
	   	  for(int k=0;k<2;k++){
	   	ordered_food_list[row][i][k]=0;//make the list empty
	   }
	   }
	 
 
cout<<"\n\t\t**FOOD SERVED**\n";

cout<<"\t\tPress Any Key To Go Back  ";
	int key;cin>>key;
	system("cls");
adminDashboard();}
else
{
	cout<<"\t\tInvalid Service Number: \n";
	goto loop1;
}
}
