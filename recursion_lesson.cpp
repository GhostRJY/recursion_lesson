#include <iostream>
#include<string>

void recursion(int a);

std::string palindrom(const std::string & userString);
int mirrorValue(int value, int razryad);
int rightToLeftDigits(int value);
int preciseTwo(double value);
int sumOfDigit(int value);
int fibonacci(int position);


int main()
{
    setlocale(LC_ALL, "rus");
    recursion(10);

    std::cout << "\nЧисло Фибоначчи " << fibonacci(10) << '\n';

    /*4. Сумма цифр числа.
        Дано натуральное число N.Вычислите сумму его цифр.

        Ввод: 179
        Вывод : 17*/
    std::cout << "\nСумма цифр числа 179 равна " << sumOfDigit(111) << '\n';

    /*3. Точная степень двойки.
        Дано натуральное число N.Выведите слово YES, если число N является точной степенью двойки, или слово NO в противном случае.*/
    double userValue{ 0 };
    std::cout << "\nВведите число ->";
    std::cin >> userValue;

    if(preciseTwo(userValue) == 1)
        std::cout << "число является точной степенью двойки\n";
    else
        std::cout << "число не является точной степенью двойки\n";

    /*5. Цифры числа справа налево.
        Дано натуральное число N.Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами.*/

    int value = 159;
    std::cout << "Обратный порядок цифр числа " << value << " -> ";
    std::cout << rightToLeftDigits(value)<<"\n\n";

    /*7. Разворот числа.
        Дано число n, десятичная запись которого не содержит нулей.
        Получите число, записанное теми же цифрами, но в противоположном порядке.
        При решении этой задачи нельзя использовать циклы, строки, списки, массивы, разрешается только рекурсия и целочисленная арифметика.
        Функция должна возвращать целое число, являющееся результатом работы программы, выводить число по одной цифре нельзя.*/
    value = 951;
    std::cout << "Разверну число " << value<<' ';
    std::cout << mirrorValue(value, 0)<<'\n';

    /*8. Палиндром.
        Дано слово, состоящее только из строчных латинских букв.Проверьте, является ли это слово палиндромом.Выведите YES или NO.
        При решении этой задачи нельзя пользоваться циклами.*/
    
    std::string str{ "1213321" };
    std::cout << palindrom(str) << '\n';


    return 0;
}

std::string palindrom(const std::string & str)
{
    if(str.length() == 1)
        return "Yes";
    
    else {
        
        if(str.substr(0, 1)._Equal(str.substr(str.length() - 1, str.length()))) {
            
            if(str.length() == 2) {
                return "yes";
            }

            return palindrom(str.substr(1, str.length() - 2));
        } 
        
        else {
            return "NO";
        }
    }
}

int mirrorValue(int value, int razryad)
{
    if(value == 0)
        return razryad;

    else
        mirrorValue(value / 10, razryad * 10 + value % 10);
}

int rightToLeftDigits(int value)
{
    if(value < 10)
        return value;

    else {
        std::cout << value % 10 << ' ';
        return rightToLeftDigits(value / 10);
    }
}

int preciseTwo(double value)
{
    if(value == 1)
        return 1;

    else if(value > 1 && value < 2)
        return 0;

    else
        preciseTwo(value / 2);
}

int sumOfDigit(int value)
{
    if(value < 10)
        return value;

    else
        return sumOfDigit(value / 10) + value % 10;
}

int fibonacci(int position)//рекурсивный фибоначчи
{

    if(position == 0 || position == 1)
        return position;

    else
        return fibonacci(position - 1) + fibonacci(position - 2);


}

//вывожу числа в обратном ппорядке
void recursion(int a)
{
    if(a < 0) {
        return;
    }
    std::cout << a << ' ';
    recursion(~0 + a);

}