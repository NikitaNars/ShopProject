
#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>
#include <clocale>

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
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];

//-----------------------------------


//Функции
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void ShowStorage();

void StorageRedact();
void AddProduct();

template <typename ArrType>
void FillStorage(ArrType staicArr[], ArrType dynamicArr[], int size);

template <typename ArrType>
void PrintStorage(ArrType dinamicArr[]);

int main()
{
    Start();
    delete[] idArr, countArr, priceArr, nameArr, passwordArr, loginArr;
    return 0;
}

void Start()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    std::setlocale(1251, "rus");
    std::string choose;
    std::cout << "\n\n\t\t\tКабанья нора\n\n\n";
    if (Login())
    {
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        if (isAdmin)
        {
            do
            {
                std::cout << "1 - Использовать готовый склад\n 2 - Созадать новый склад?\n";
                std::cout << "Ввод: ";
                std::getline(std::cin, choose, '\n');
            } while (choose.size() > 1 || choose[0] < 48 && choose[0] > 49);
            if (choose == "1")
            {
                CreateStaticStorage();
            }
            else
            {

            }

            ShopAdminMenu();

        }
        else
        {
            CreateStaticStorage();
            ShopUserMenu();
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
        } while (choose.size() > 1 && choose[0] < 48 || choose[0] > 53);
        if (choose == "1")
        {

        }
        else if (choose == "2")
        {
            ShowStorage();
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
        } while (choose.size() > 1 && choose[0] < 48 || choose[0] > 56);
        if (choose == "1")
        {

        }
        else if (choose == "2")
        {
            ShowStorage();
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
        else if (choose == "0")
        {

        }
        else
        {
            std::cout << "Error";
        }

        }

    }
    void CreateStaticStorage()
    {
        const int staticSize = 10;
        int idStaticArr[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::string nameStaticArr[staticSize]
        {
         "Ружьё", "Удочка", "Черви", "Капкан", "Поплавок", "Охотничий костюм", "Садок", "Поводок", "Леска", "Крючок"

        };
        int countStaticArr[staticSize]{ 2, 4, 100, 4, 10, 3, 5, 15, 50, 150 };
        double priceStaticArr[staticSize]{ 11000.0, 3500.0, 0.2, 2000.0, 30.0, 10000.0, 800.0, 150.0, 20.0, 5.0 };
        FillStorage(idStaticArr, idArr, staticSize);
        FillStorage(nameStaticArr, nameArr, staticSize);
        FillStorage(countStaticArr, countArr, staticSize);
        FillStorage(priceStaticArr, priceArr, staticSize);

    }

    void ShowStorage()
    {
        std::cout << "ID\tНазвание\t\t\tКол-во\tЦена\n";
        for (int i = 0; i < size; i++)
        {
            std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
        }
        std::cout << "\n\n";
    }

    void RefilStorage()
    {
        std::string idStr;
        std::cout << "Поплнение склада \n введите id товара: ";
        std::getline(std::cin, idStr, '\n');
        int id = std::stoi(idStr);
        std::cout << idArr[id - 1] << " " << nameArr[id - 1] << " ";


    }

    bool isStringDigit(std::string string) {
        for (int i = 0; i < string.size(); i++) {
            if (!std::isdigit(string[i])) {
                return false;
            }
        }
        return true;
    }
    void AddEmployee()
    {


        userCount++;
        std::string* tempLogin = new std::string[userCount];
        std::string* tempPass = new std::string[userCount];
        std::string newLogin, newPass;

        std::cout << "Введите логин нового сотрудника: ";
        std::getline(std::cin, newLogin, '\n');
        std::cout << "Введите пароль нового сотрудника: ";
        std::getline(std::cin, newPass, '\n');

        tempLogin[userCount - 1] = newLogin;
        tempPass[userCount - 1] = newPass;

        std::swap(loginArr, tempLogin);
        std::swap(passwordArr, tempPass);
        delete[]tempLogin;
        delete[]tempPass;
    }

    void StaffRedact()
    {
        std::string choose, newLogin, newPass;
        int emId;
        while (true)
        {
            std::cout << "ID\tЛОгин\tПароль\n\n";
            for (int i = 0; i < userCount; i++)
            {
                std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr << "\n";

            }
            std::cout << "Введите ID сотрудника\t 0 - Выход\nВвод: ";
            std::getline(std::cin, choose, '\n');
            if (choose == "0")
            {
                break;
            }
            else if (isStringDigit(choose))
            {
                emId = std::stoi(choose);
                for (int i = 0; i < userCount; i++)
                {
                    if (i == emId - 1)
                    {
                        std::cout << "Введите  логин нового сотрудника: ";
                        std::getline(std::cin, newLogin, '\n');
                        std::cout << "Введите пароль нового сотрудника: ";
                        std::getline(std::cin, newPass, '\n');

                        loginArr[i] = newLogin;
                        passwordArr[i] = newPass;
                        break;
                    }
                    
                }

            }
            else
            {
                std::cout << "\n\nОшибка ввода!\n\n";
            }
        }   

    }
    void StorageRedact()
    {
    std::string choose;
    std::cout << "Изменить склада магазина";
    while (true)
    {
        std::cout << "1 - Добавить новый товар \n2 - Изменить название товара\n3 - Удаление товара\n0 - Выход\n\nВвод: ";
        std::getline(std::cin, choose, '\n');
        if (choose == "0")
        {
            break;
        }
        else if (choose == "1")
        {
            AddProduct();
            break;
        }
        else if (choose == "2")
        {
            break;
        }
        else if (choose == "3")
        {
            break;
        }
        else
        {
            std::cout << "\n\nНекоректный вводn\n\n";
        }
    }
    }

    void AddProduct()
    {
        std::string choose;
        while (true)
        {
            std::cout << "1 - Добавить новый товар\t0 - Выход\n\nВвод: ";
            std::getline(std::cin, choose, '\n');
            if (choose == "0")
            {
                break;
            }
            else if (choose == "1")
            {
                int* tempId = new int[size];
                int* tempCount = new int[size];
                double* tempPrice = new double[size];
                std::string* tempName = new std::string[size];
                for (int i = 0; i < size; i++)
                {
                    tempId[i] = idArr[i];
                    tempCount[i] = countArr[i];
                    tempPrice[i] = priceArr[i];
                    tempName[i] = nameArr[i];
                }
                

                std::string newName, newCountStr, newPriseStr;

                while (true)
                {
                    std::cout << "Введите название нового товара: ";
                    std::getline(std::cin, newName, '\n');
                }

                delete[] tempId;
                delete[]tempCount;
                delete[]tempPrice;
                delete[]tempName;
            }
            else
            {
                std::cout << "\n\nНекорректный ввод\n\n";
            }
        }
    }

    template<typename ArrType>
    void FillStorage(ArrType staicArr[], ArrType dynamicArr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            dynamicArr[i] = staicArr[i];
        }
    }
    template <typename ArrType>
    void PrintStorage(ArrType dinamicArr[])
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << dinamicArr[i] << " ";
        }
        std::cout << "\n";

         
    }
    
        