#include <iostream>

//Number Fibonachi

int Numbers_Fibonachi(int &place,const int number_stop = 233, int number1 = 0, int number2 = 1)
{ 
	int buffer{ number1 + number2 };
	place++;
	if (number_stop == buffer)
	{
		return place;
	}
	if (number_stop == 0)
	{
		return 1;
	}
	if (number_stop == 1)
	{
		return 1;
	}
	if (buffer>number_stop)
	{
		return 0;
	}
	number1 = number2;
	return Numbers_Fibonachi(place, number_stop,number1,buffer);
}
// Человек вписывает значение и нужно определить, есть ли это значение среди числе Фибоначчи. Если есть, вернуть на каком месте. Если нету, вернуть ошибку.

int main()
{
	int place{ 2 };
	std::cout << Numbers_Fibonachi(place);
	return 0;
}


