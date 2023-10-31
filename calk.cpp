#include <iostream>
#include <cmath>
#include <string>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <getopt.h>

using namespace std;

void Instruction() {
    cout << "Поддерживаемые операции:" << endl;
    cout << "  -o tan 'x'   (Значение тангенса" << endl;
    cout << "  -o cot 'x'   (Значение котангенса " << endl;
}

int main(int argc, char* argv[]) {
	string operation;
    double result = 0;
 
    struct option longOptions[] = {{"операция", required_argument, nullptr, 'o'},{nullptr, 0, nullptr, 0}};
    int optionIndex;
    int option;
    while ((option = getopt_long(argc, argv, "o:", longOptions, &optionIndex)) != -1)
    {
        switch (option)
        {
        case 'o':
            operation = optarg;
            break;
        default:
            Instruction();
            return 1;
        }
    }
    if (argc - optind < 1 || operation.empty())
    {
        Instruction();
        return 1;
    }
    for (int i = optind; i < argc; i++)
    {
        double operand = stod(argv[i]);
        if (operation == "tan")
        {
            result += tan(operand * M_PI / 180.0);
        }
        else if (operation == "cot")
        {
            result += 1/(tan(operand * M_PI / 180.0));
        }
        else
        {
            cout << "Неподдерживаемая операция! \n " << operation << endl;
            Instruction();
            return 1;
        }
    }
    cout << "Результат: \n\n"<< result << endl;
    return 0;
}