
#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>
#include <clocale>

#if defined(max)
#undef max
#endif

// ������� ������
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//-----------------------------------
//���� ������ �������
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];

//-----------------------------------


//�������
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void ShowStorage();
void AddEmployee();
void StaffRedact();
void RefilStorage();
void RemoveStaff();
void StorageRedact();
void CgangePrice();
void AddProduct();
void ChangeStaff();
void RemoveFromStorage();

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
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::string choose;
    std::cout << "\n\n\t\t\t������� ����\n\n\n";
    if (Login())
    {
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        if (isAdmin)
        {
            do
            {
                std::cout << "1 - ������������ ������� �����\n 2 - �������� ����� �����?\n";
                std::cout << "����: ";
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
        std::cout << "������� �����: ";
        std::getline(std::cin, login, '\n');
        std::cout << "������� ������: ";
        std::getline(std::cin, pass, '\n');

        if (login == loginArr[0] && pass == passwordArr[0])
        {
            std::cout << "����� ���������� " << loginArr[0] << '\n';
            isAdmin = true;
            return true;
        }

        for (int i = 1; i < userCount; i++)
        {
            if (login == loginArr[i] && pass == passwordArr[i])
            {
                std::cout << "����� ���������� " << loginArr[i] << '\n';
                isAdmin = false;
                return true;
            }
        }
        system("cls");
        std::cout << "������� ����� ����� ��� ������!\n\n";
    }
}
void ShopUserMenu()
{
    std::string choose;
    while (true)
    {
        do
        {

            std::cout << "1. ������ �������\n";
            std::cout << "2. �������� �����\n";
            std::cout << "3. ��������� �����\n";
            std::cout << "4. ������� �� ������\n";
            std::cout << "5. ����� � �������\n\n";
            std::cout << "0. ������� �����\n\n\n";
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
            RefilStorage();
        }
        else if (choose == "4")
        {
            RemoveFromStorage();
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
            std::cout << "1. ������ �������\n";
            std::cout << "2. �������� �����\n";
            std::cout << "3. ��������� �����\n";
            std::cout << "4. ������� �� ������\n";
            std::cout << "5. �������� ����\n";
            std::cout << "6. �������� �����\n";
            std::cout << "7. �������� ��������\n";
            std::cout << "8. ����� � �������\n\n";
            std::cout << "0. ������� �����\n\n\n";

            std::cout << "����: ";
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
            RefilStorage();
        }
        else if (choose == "4")
        {
            RemoveFromStorage();
        }
        else if (choose == "5")
        {
            CgangePrice();
        }
        else if (choose == "6")
        {
            StorageRedact();
        }
        else if (choose == "7")
        {
            ChangeStaff();
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
    void CreateStaticStorage()
    {
        const int staticSize = 10;
        int idStaticArr[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::string nameStaticArr[staticSize]
        {
         "�����", "������", "�����", "������", "��������", "��������� ������", "�����", "�������", "�����", "������"

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
        std::cout << "ID\t��������\t\t\t���-��\t����\n";
        for (int i = 0; i < size; i++)
        {
            std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
        }
        std::cout << "\n\n";
    }

    void RefilStorage()
    {
        std::string idStr;
        std::cout << "���������� ������ \n ������� id ������: ";
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

        std::cout << "������� ����� ������ ����������: ";
        std::getline(std::cin, newLogin, '\n');
        std::cout << "������� ������ ������ ����������: ";
        std::getline(std::cin, newPass, '\n');

        tempLogin[userCount - 1] = newLogin;
        tempPass[userCount - 1] = newPass;

        std::swap(loginArr, tempLogin);
        std::swap(passwordArr, tempPass);
        delete[]tempLogin;
        delete[]tempPass;
    }
    void ChangeStaff()
    {
        std::string choose;

        while (true)
        {
            std::cout << "ID\t�����\t\t������ ";
            for (int i = 0; i < userCount; i++)
            {
                std::cout << "\n" << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i];
            }


            std::cout << "\n\n1. �������� ������ ����������\n2. ��������������� ����������\n3 - ������� ����������\n0. �����\n\n����: ";
            std::getline(std::cin, choose, '\n');

            if (choose == "1")
            {
                AddEmployee();
            }
            else if (choose == "2")
            {
                StaffRedact();
            }
            else if (choose == "3")
            {
                RemoveStaff();
            }
            else if (choose == "0")
            {
                system("cls");
                break;
            }
            else
            {
                std::cout << "������ �����!!\n\n";
            }
        }
    }
    void RemoveStaff()
    {
        system("cls");

        std::string choose;
        int empId;
        while (true)
        {
            std::cout << "\nID\n";
            for (int i = 0; i < userCount; i++)
            {
                std::cout << i + 1 << "\n";
            }


            std::cout << "\n\n������� ID ���������� ��� ��������:\t0 - �����\n����: ";
            std::getline(std::cin, choose, '\n');


            if (choose == "0")
            {
                system("cls");
                break;
            }
            else if (isStringDigit(choose) && choose != "1")
            {
                empId = std::stoi(choose);


                if (empId < 1 || empId > userCount)
                {
                    std::cout << "�������� ID!!!\n\n";
                    break;
                }

                std::string* tempLogin = new std::string[userCount];
                std::string* tempPass = new std::string[userCount];

                for (int i = 0; i < userCount; i++)
                {
                    tempLogin[i] = loginArr[i];
                    tempPass[i] = passwordArr[i];
                }

                delete[]loginArr;
                delete[]passwordArr;
                userCount--;
                loginArr = new std::string[userCount];
                passwordArr = new std::string[userCount];


                for (int i = 0, j = 0; i < userCount, j < userCount; i++, j++)
                {
                    if (i == empId - 1)
                    {
                        i++;
                        loginArr[j] = tempLogin[i];
                        passwordArr[j] = tempPass[i];
                    }
                    else
                    {
                        loginArr[j] = tempLogin[i];
                        passwordArr[j] = tempPass[i];
                    }
                }

                std::cout << "\n\n��������� ������� ������!\n\n";

                break;
            }
            else
            {
                std::cout << "������ �����!!\n\n";
            }

        }
    }
    void CgangePrice()
    {
        std::string idStr, choose, newPriceStr;
        int id{}, price{};
        bool exit = false;
        double newPrice;

        while (!exit)
        {


            while (true)
            {
                std::cout << "�������� ����\n������� ID ������: ";
                std::getline(std::cin, idStr, '\n');

                if (std::isdigit(idStr[0]) && idStr.size() == 1)
                {
                    id = std::stoi(idStr);
                }
                else if (std::isdigit(idStr[1]) && idStr.size() == 2)
                {
                    id = std::stoi(idStr);
                }
                else
                {
                    std::cout << "������ �����!!\n\n";
                }
                if (id > 0 && id <= size)
                {
                    break;
                }
                else
                {
                    std::cout << "�������� ID\n\n";
                }
            }

            std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\t";

            while (true)
            {
                std::cout << "\n������� ����� ����: ";
                std::getline(std::cin, newPriceStr, '\n');

                if (isStringDigit(newPriceStr))
                {
                    newPrice = std::stod(newPriceStr);

                    if (price >= 0 && price <= 10000000)
                    {
                        break;
                    }

                    else
                    {
                        std::cout << "����������� ����!!!\n\n";
                    }
                }
            }

            while (true)
            {

                std::cout << "��������� " << nameArr[id - 1] << " ����� ���� " << std::fixed << newPrice << " ?";
                std::cout << "1 - ��\t2 - ���\t3 - ������\n\n";
                std::getline(std::cin, choose, '\n');

                if (choose == "1")
                {
                    priceArr[id - 1] = newPrice;
                    std::cout << "���� ������� ��������\n\n";
                    exit = true;
                    break;
                }
                else if (choose == "2")
                {
                    break;
                }
                else if (choose == "3")
                {
                    exit = true;
                    break;
                }
                else
                {
                    std::cout << "������ �����!!\n\n";
                }
            }
        }
    }

    void RemoveFromStorage()
    {
        std::string idStr, removeStr, choose;
        int id{}, remove;
        bool exit = false;

        while (!exit)
        {


            while (true)
            {
                std::cout << "�������� �� ������\n������� ID ������: ";
                std::getline(std::cin, idStr, '\n');

                if (std::isdigit(idStr[0]) && idStr.size() == 1)
                {
                    id = std::stoi(idStr);
                }
                else if (std::isdigit(idStr[1]) && idStr.size() == 2)
                {
                    id = std::stoi(idStr);
                }
                else
                {
                    std::cout << "������ �����!!\n";
                }
                if (id > 0 && id <= size)
                {
                    break;
                }
                else
                {
                    std::cout << "�������� ID\n";
                }
            }

            std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\t";

            while (true)
            {
                std::cout << "\n������� ���������� ������ ��� ��������: ";
                std::getline(std::cin, removeStr, '\n');

                if (isStringDigit(removeStr))
                {
                    remove = std::stoi(removeStr);

                    if (remove >= 0 && remove <= countArr[id - 1])
                    {
                        break;
                    }

                    else
                    {
                        std::cout << "������ �����!!!\n";
                    }
                }
            }

            while (true)
            {

                std::cout << "������� " << remove << " ������(��) " << nameArr[id - 1] << " ?";
                std::cout << "1 - ��\t2 - ���\t3 - ������\n\n";
                std::getline(std::cin, choose, '\n');

                if (choose == "1")
                {
                    countArr[id - 1] -= remove;
                    std::cout << "����� ������� ������\n\n";
                    exit = true;
                    break;
                }
                else if (choose == "2")
                {
                    break;
                }
                else if (choose == "3")
                {
                    exit = true;
                    break;
                }
                else
                {
                    std::cout << "������ �����!!\n";
                }
            }
        }
    }

    void StaffRedact()
    {
        std::string choose, newLogin, newPass;
        int emId;
        while (true)
        {
            std::cout << "ID\t�����\t������\n\n";
            for (int i = 0; i < userCount; i++)
            {
                std::cout << i + 1 << "\t" << std::left << std::setw(10) << loginArr[i] << "\t" << passwordArr[i] << "\n";

            }
            std::cout << "������� ID ����������\t 0 - �����\n����: ";
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
                    if (emId < 1 || emId > userCount)
                    {
                        std::cout << "��� ���������� � ����� ID\n\n";
                        break;
                    }
                    if (i == emId - 1)
                    {
                        std::cout << "�������  ����� ������ ����������: ";
                        std::getline(std::cin, newLogin, '\n');
                        std::cout << "������� ������ ������ ����������: ";
                        std::getline(std::cin, newPass, '\n');

                        loginArr[i] = newLogin;
                        passwordArr[i] = newPass;
                        break;
                    }
                    
                }

            }
            else
            {
                std::cout << "\n\n������ �����!\n\n";
            }
        }   

    }
    void StorageRedact()
    {
        std::string choose;
        std::cout << "�������� ������ ��������";
        while (true)
        {
            std::cout << "1 - �������� ����� ����� \n2 - �������� �������� ������\n3 - �������� ������\n0 - �����\n\n����: ";
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
                std::cout << "\n\n����������� ����n\n\n";
            }
        }
    }


    void AddProduct()
    {
        system("cls");
        std::string choose;
        while (true)
        {
            std::cout << "1 - �������� ����� �����\t0 - �����\n\n����: ";
            std::getline(std::cin, choose, '\n');
            if (choose == "0")
            {
                system("cls");
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
                    std::cout << "������� �������� ������ ������: ";
                    std::getline(std::cin, newName, '\n');
                }

                delete[] tempId;
                delete[]tempCount;
                delete[]tempPrice;
                delete[]tempName;
            }
            else
            {
                std::cout << "\n\n������������ ����\n\n";
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
    
