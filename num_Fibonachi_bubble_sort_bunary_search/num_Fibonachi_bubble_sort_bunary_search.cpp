#include <iostream>

//Numbers Fibonachi

// place in number 
int Place_number_Fibonachi(int place_U, int stop_func, int number1, int number2);
//int Place_number_Fibonachi(int place_U, int stop_func = 0, int number1 = 0, int number2 = 1);
// number in place 
int Number_Fibonachi(int& place_U, const int number_stop_func, int number1, int number2);
//int Number_Fibonachi(int& place_U, const int number_stop_func = 0, int number1 = 0, int number2 = 1);
// User Fibonachi
int User_Number_Fibonachi(int number_user1, int number_user2, int stop_func);
//int User_Number_Fibonachi(int number_user1, int number_user2, int stop_func = 0);
bool Uniqueness_number_array(const int* point_array,const int size,const int number);
void Fill_Dynamic_Array(int* point_array, const int size);
void Print_Dynamic_Array(const int* point_array, const int size);
void Bubble_sort(int* point_array, const int size);
int main()
{
	srand(time(NULL));
	int place{ 0 };
	int number_user{0};
	int number{0};
	int size{ 10 };
	int* Point_Array{ new int[size] };
	Fill_Dynamic_Array(Point_Array, size);
	Print_Dynamic_Array(Point_Array, size);
	std::cout << "*************************************"<< std::endl;
	Bubble_sort(Point_Array, size);

	Print_Dynamic_Array(Point_Array, size);
	std::cout << "\tBye!" << std::endl;
	delete[] Point_Array;
	Point_Array = nullptr;
	return 0;
}

int Place_number_Fibonachi(int place_U, int stop_func = 0, int number1 = 0, int number2 = 1)
{
	// place user
	if (place_U == 1)
	{
		return 0;
	}
	if (place_U == 2 || place_U == 3)
	{
		return 1;
	}
	int buffer{ number1 + number2 };
	stop_func++;
	if (stop_func > place_U)
	{
		return -1;
	}
	if (stop_func == place_U)
	{
		return buffer;
	}
	number1 = number2;
	return Place_number_Fibonachi(place_U, stop_func, number1, buffer);
}
int Number_Fibonachi(int& place_U, const int number_stop_func = 0, int number1 = 0, int number2 = 1)
{
	if (number_stop_func == 0)
	{
		place_U = 1;
		return place_U;
	}
	if (number_stop_func == 1)
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
int User_Number_Fibonachi(int number_user1, int number_user2, int stop_func = 0)
{
	int buffer = { number_user1 + number_user2 };
	if (stop_func == 0)
	{
		return buffer;
	}
	number_user1 = number_user2;
	stop_func--;
	return User_Number_Fibonachi(number_user1, buffer, stop_func);
}
bool Uniqueness_number_array(const int* point_array, const int size, const int number)
{
	bool uniqueness_num{ false };
	for (int i = 0; i < size; i++)
	{
		if (point_array[i] == number)
		{
			uniqueness_num = true;
			break;
		}
		else
		{
			uniqueness_num = false;
		}
	}
	return uniqueness_num;
}
void Fill_Dynamic_Array(int *point_array, const int size)
{
	int num{ 0 };
	int i{ 0 };
	do
	{
		num = rand() % 100 + 1;
		if (Uniqueness_number_array(point_array, size, num) == false)
		{
			point_array[i] = num;
			i++;
		}
	} while (i<size);
}
void Print_Dynamic_Array(const int* point_array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << point_array[i] << std::endl;
	}
}
void Bubble_sort(int *point_array, const int size)
{
	int buffer{ 0 };
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size;)
		{
			if (i < size - 1) {
				if (point_array[i] > point_array[i + 1])
				{
					buffer = point_array[i];
					point_array[i] = point_array[i + 1];
					point_array[i + 1] = buffer;
					i++;
					continue;
				}
				if (point_array[i] <= point_array[i + 1])
				{
					i++;
					continue;
				}
			}
			else
			{
				break;
			}
	}
	}
}








/*std::cout << "Enter number: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << User_Number_Fibonachi(180, 115,i) << std::endl;
	}*/
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
