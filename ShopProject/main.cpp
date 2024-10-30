#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>

#if defined(max)
#undef max
#endif

// Учётные записи
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//-----------------------------------
//База данных товаров
int size = 10;
int* idArr = new int[size];
int* coutArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];

//-----------------------------------


//Функции
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
int main()
{
	Start();
	return 0;
}

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\t\tКабанья нора\n\n\n";
	if (Login())
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin)
		{
			ShopAdminMenu();
		}
	}
	
}
bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');

		if (login == loginArr[0] && pass == passwordArr[0])
		{
			std::cout << "Добро пожаловать " << loginArr[0] << '\n';
			isAdmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << "Добро пожаловать " << loginArr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "Неверно введён логин или пароль!\n\n";
	}
}
void ShopUserMenu()
{
	std::string choose;
	while (true)
	{
		do
		{

			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Отчёт о прибыли\n\n";
			std::cout << "0. Закрыть смену\n\n\n";
			std::getline(std::cin, choose, '\n');
			system("cls");
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else
		{
			std::cout << "Error";
		}
	}
}


void ShopAdminMenu()
{
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Изменить цену\n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. Изменить персонад\n";
			std::cout << "8. Отчёт о прибыли\n\n";
			std::cout << "0. Закрыть смену\n\n\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			system("cls");
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			std::cout << "Error";
		}
			


	}
}