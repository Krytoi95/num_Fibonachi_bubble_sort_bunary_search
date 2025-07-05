#include <iostream>
#include <cmath>
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
int Binary_search(const int* point_array, const int size, const int seeking_num);
int main()
{
	/*srand(time(NULL));*/
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
	std::cout << "*************************************" << std::endl;
	std::cin >> number;
	std::cout << "*************************************" << std::endl;
	//std::cout << ceil(1.5) << std::endl;
	//std::cout << floor(1.5) << std::endl;
	number_user = Binary_search(Point_Array, size, number);
	if (number_user == -1)
	{
		std::cout << "Isn't" << std::endl;
	}
	else 
	{
		std::cout << number_user << std::endl;
	}
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
			return true;
		}
	}
	return false;
}
bool Parity_check(int num) 
{
	if(num%2==0) 
	{
		return true;
	}
    return false;
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
int Binary_search(const int* point_array, const int size, const int seeking_num)
{
	if (Parity_check(size) == true)
	{
		int place{ 0 };
	    place = size / 2;
		const int iteration{ size / 2 };
		for (int i = 0; i < iteration; i++)
		{
			// 0 1 2 3 4 5 6 7 8 9
			if (point_array[place] == seeking_num)
			{
				return place;
			}
			if (point_array[place - 1] == seeking_num)
			{
				return  place -1;
			}
			if (point_array[place] < seeking_num)
			{
				//right
				place++;
				continue;
			}
			if (point_array[place] > seeking_num)
			{
				//left
				place--;
				continue;
			}
		}
	}
	if (Parity_check(size) == false)
	{
		// 0 1 2 3 4 5 6 7 8 9 10 
		int place{ 0 };
		place = floor(size/2);
		const int iteration{place+1};
		for (int i = 0; i < iteration; i++)
		{
			if (point_array[place] == seeking_num)
			{
				return place;
			}
			if (point_array[place] < seeking_num)
			{
				//right
				place++;
				continue;
			}
			if (point_array[place] > seeking_num)
			{
				//left
				place--;
				continue;
			}
		}
	}
	return -1;
	// Error
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
