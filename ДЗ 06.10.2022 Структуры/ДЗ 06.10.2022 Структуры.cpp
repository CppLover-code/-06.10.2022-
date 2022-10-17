/*
    Создайте структуру, которая описывает комплексное число.
    Реализуйте арифметические операции с комплексными числами:
    сложение, вычитание, умножение и деление.
*/
#include <iostream>

struct complex_number  // именованная структура для комплексных чисел
{
    float real;        // поля структуры
    float imagine;
};

int main();

void check_data(float x1, float y1, float x2, float y2, char oper)                                      // функция проверки введенных данных пользователем
{
    std::cout << "\n(" << x1 << (y1 >= 0 ? "+" : "") << y1 << "i) "                                     //вывод введенных данных в виде выражения
        << oper 
        << " " << "(" << x2 << (y2 >= 0 ? "+" : "") << y2 << "i)";

    if (x1 == 0 && y1 == 0 && (oper == '*' || oper == '/'))                                             // если два числа первого выражения равны нулю и 
    {
        std::cout << "\n The real and imaginary parts of the -first- expression are equal to zero.\n"   // знак операции '*' или '/', то выводим предупреждение
            << " Operation not possible =( Enter all data again!\n\n"; 
            main();                                                                                     // и возвращаем пользователя обратно к вводу данных
    }

    else if (x2 == 0 && y2 == 0 && (oper == '*' || oper == '/'))                                        // если два числа второго  выражения равны нулю и 
    {
        std::cout << "\n The real and imaginary parts of the -second- expression are equal to zero.\n"  // знак операции '*' или '/', то выводим предупреждение
            << " Operation not possible =( Enter all data again!\n\n";
            main();                                                                                     // и возвращаем пользователя обратно к вводу данных
    }

    else if (oper != '+' && oper != '-' && oper != '*' && oper != '/')                                  // если введенный знак операции не соответствует указаному,
    {
        std::cout << "\n You entered an invalid math symbol! Enter all data again!\n\n";                // выводим предупреждение
        main();                                                                                         // и возвращаем пользователя обратно к вводу данных
    }
}

complex_number add_sub(float n1,float n2, char oper)  // функция выполнения операций '+' '-'
{
    complex_number x;                                 // имя структуры исп для объявления объектов
    switch (oper)                                     // проверяем введенный знак операции и выполняем соответствующие действия
    {
    case '+':                                       
        x.real = n1 + n2;
        x.imagine = n1 + n2;
        return x;                                     // возвращаем результат 
        break;
    case '-':
        x.real = n1 - n2;
        x.imagine = n1 - n2;
        return x;
        break;
    }
}

complex_number mult_div(float x1, float y1, float x2, float y2, char oper)  // функция выполнения операций '*' '/'
{
    complex_number x;                                                       // имя структуры исп для объявления объектов

    float a, b, c, d, e;                                                    // переменные будут хранить результаты
    a = x1 * x2;                                                            // операций над числами
    b = y1 * y2;
    c = y1 * x2;
    d = x1 * y2;
    e = x2 * x2 + y2 * y2;

    switch (oper)                                                           // проверяем введенный знак операции и выполняем соответствующие действия
    {
    case '*':
     
        x.real = a - b;
        x.imagine = c + d;

        return x;       
        break;

    case '/':

        x.real = (a + b) / e;
        x.imagine = (c - d) / e;

        return x;
        break;
    }
}

void print_complex_number(complex_number x, complex_number y)                           // функция вывода результата в консоль
{
    std::cout << " = " << x.real << (y.imagine >= 0 ? "+" : "") << y.imagine << "i\n";  // если мнимое число больше 0, то выводим '+', иначе пустые ""
}

void operations(float x1, float y1, float x2, float y2, char oper)  // функция проверки знака операции и выполнение 
{                                                                   // соответствующих функций
    complex_number numb1, numb2;                                    // действительное и мнимое число

    switch (oper)
    {
    case '+':
        numb1 = add_sub(x1, x2, oper);
        numb2 = add_sub(y1, y2, oper);
        print_complex_number(numb1, numb2);
        break;

    case '-':
        numb1 = add_sub(x1, x2, oper);
        numb2 = add_sub(y1, y2, oper);
        print_complex_number(numb1, numb2);
        break;

    case '*':

        numb1 = mult_div(x1, y1, x2, y2, oper);
        numb2 = mult_div(x1, y1, x2, y2, oper);
        print_complex_number(numb1, numb2);
        break;

    case '/':

        numb1 = mult_div(x1, y1, x2, y2, oper);
        numb2 = mult_div(x1, y1, x2, y2, oper);
        print_complex_number(numb1, numb2);
        break;
    }
}

int main()
{
    std::cout << " Operations with complex numbers '+' '-' '*' '/')\n\n";

    float x1, y1;  // исп тип данных float, тк результаты некоторых 
    float x2, y2;  // операций могут давать вещественные числа

    char oper;

    std::cout << "Enter the real and imaginary part of the first complex number:\n";
    std::cin >> x1 >> y1;
    std::cout << "Enter the real and imaginary part of the second complex number:\n";
    std::cin >> x2 >> y2;
    std::cout << "Enter a math symbol:\n";
    std::cin >> oper;

    check_data(x1, y1, x2, y2, oper);
    operations(x1, y1, x2, y2, oper);
    
    return 0;
}

