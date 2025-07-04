#include <iostream>

//Numbers Fibonachi

// place in number 
int Place_number_Fibonachi(int place_U,int stop_func = 0,int number1 = 0, int number2 = 1)
{
	// place user
	if (place_U == 1)
	{
		return 0;
	}
	if(place_U == 2||place_U==3)
	{
		return 1;
	}
	int buffer{ number1 + number2 };
	stop_func++;
	if(stop_func>place_U)
	{ 
		return -1;
	}
	if (stop_func == place_U)
	{
		return buffer;
	}
	number1 = number2;
	return Place_number_Fibonachi(place_U,stop_func,number1,buffer);
}
// number in place 
int Number_Fibonachi(int& place_U, const int number_stop_func=0, int number1 = 0, int number2 = 1)
{
	if(number_stop_func==0)
	{
		place_U = 1;
		return place_U;
	}
	if(number_stop_func==1)
	{
		place_U = 2;
		return place_U;
	}
	int buffer{ number1 + number2 };
	place_U++;
	if (number_stop_func == buffer)
	{
		return place_U;
	}
	if (buffer > number_stop_func)
	{
		return -1;
	}
	number1 = number2;
	return Number_Fibonachi(place_U, number_stop_func, number1, buffer);
}
// User Fibonachi
int User_Number_Fibonachi( int number_user1, int number_user2,int stop_func = 0)
{
	int buffer = { number_user1 + number_user2 };
	if (stop_func == 0)
	{
		return buffer;
	}
	number_user1 = number_user2;
	stop_func--;
	return User_Number_Fibonachi(number_user1, buffer,stop_func);
}
int main()
{
	int place{ 0 };
	int number_user{0};
	int number{0};
	std::cout << "Enter number: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << User_Number_Fibonachi(180, 115,i) << std::endl;
	}










	
	/*while(std::cin>>number_user)
	{
		if (number_user != 0 || number_user != 1)
		{
			place += 2;
		}
		number_user = Number_Fibonachi(place, number_user);
		if (number_user == 0)
		{
			std::cout << "This number isn't range Number_Fibonachi" << std::endl;
			place = 0;
		}
		else if (number_user == 2)
		{
			std::cout << "Place: 2-3" << std::endl;
			place = 0;
		}
		else
		{
			std::cout << "Place: " << number_user << std::endl;
			place = 0;
		}
	}*/

	/*while (std::cin >> place)
	{
		number = Place_number_Fibonachi(place);
		if(number==-1)
		{
			std::cout << "Error" << std::endl;
		}
		else 
		{ 
			std::cout << "Number: " << Place_number_Fibonachi(place) << std::endl; 
		}
	}*/
	
	std::cout << "Bye!" << std::endl;
	return 0;
}


