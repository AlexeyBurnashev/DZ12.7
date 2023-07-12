#include <iostream>
#include <string>

bool IsKPeriodic(std::string& str, int k)
{
	if (k <= 0 || str.size() % k != 0)  // проверяем, что число k больше нуля и длина строки делится на число k без остатка
	{
		return false;
	}

	int txt_size = k;                   // проверяем, что каждая подстрока длины k в строке равна первой подстроке
	int num_txt = str.size() / txt_size;
	std::string first_txt = str.substr(0, txt_size);
	for (int i = 1; i < num_txt; ++i) 
	{
		const std::string txt = str.substr(i * txt_size, txt_size);
		if (txt != first_txt) 
		{
			return false;
		}
	}

	return true;
}



int main()
{
	std::string str = "abcabcabcabc";

	int k = 3;

	if (IsKPeriodic(str, k)) 
	{
		std::cout << str  << " - the string is a multiple of " << k << std::endl;
	}
	else {
		std::cout << str << " - the string is not a multiple of " << k << std::endl;
	}

	return 0;
}
