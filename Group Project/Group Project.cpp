#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int option;
int numbers[50];
int dataCount = 0;

void ShowMenu(void);
void GetAverage(void);
void GetSmallest(void);
void GetNumOccurences(int);
void Quit(void);

int main()
{
    ifstream infile("Numbers.dat");
    for (int i = 0; i < 50; i++)
    {
        if (infile >> numbers[i])
        {
            dataCount++;
        }
        else
        {
            break;
        }
    }
    infile.close();

    while (true)
    {
        ShowMenu();

        switch (option)
        {
        case 1:
            for (int i = 0; i < dataCount; i++)
            {
                cout << numbers[i] << " ";
            }
            cout << endl;
            break;
        case 2:
        {
            int total = 0;
            for (int i = 0; i < dataCount; i++)
            {
                total += numbers[i];
            }
            cout << "Total: " << total << endl;
            break;
        }
        case 3:
            GetAverage();
            break;
        case 4:
        {
            int largest = numbers[0];
            for (int i = 1; i < dataCount; i++)
            {
                if (numbers[i] > largest)
                {
                    largest = numbers[i];
                }
            }
            cout << "Largest: " << largest << endl;
            break;
        }
        case 5:
            GetSmallest();
            break;
        case 6:
        {
            int num;
            while (true)
            {
                cout << "Enter an integer: ";
                cin >> num;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else
                {
                    break;
                }
            }
            GetNumOccurences(num);
            break;
        }
        case 7:
        {
            int sFactor;
            cin >> sFactor;
            for (int i = 0; i < dataCount; i++)
            {
                numbers[i] *= sFactor;
            }
            break;
        }
        case 8:
        {
            for (int i = 0; i < dataCount / 2; i++)
            {
                int temp = numbers[i];
                numbers[i] = numbers[dataCount - 1 - i];
                numbers[dataCount - 1 - i] = temp;
            }
            break;
        }
        case 9:
        {
            int min = numbers[0];
            for (int i = 1; i < dataCount; i++)
            {
                if (numbers[i] < min)
                    min = numbers[i];
            }
            for (int i = 0; i < dataCount; i++)
            {
                numbers[i] -= min;
            }
            break;
        }
        case 10:
        {
            int element;
            cin >> element;
            if (element >= 1 && element <= dataCount)
            {
                for (int i = element - 1; i < dataCount - 1; i++)
                {
                    numbers[i] = numbers[i + 1];
                }
                dataCount--;
            }
            break;
        }
        case 11:
        {
            for (int i = 0; i < dataCount - 1; i++)
            {
                for (int j = 0; j < dataCount - 1 - i; j++)
                {
                    if (numbers[j] > numbers[j + 1])
                    {
                        int temp = numbers[j];
                        numbers[j] = numbers[j + 1];
                        numbers[j + 1] = temp;
                    }
                }
            }
            break;
        }
        case 12:
            Quit();
            break;
        default:
            break;
        }
    }

    return 0;
}

void ShowMenu(void)
{
    cout << "\n1. Display the contents of array\n";
    cout << "2. Get the total of the array\n";
    cout << "3. Get the average of the array\n";
    cout << "4. Get the largest integer in the array\n";
    cout << "5. Get the smallest integer in the array\n";
    cout << "6. Get the number of occurrences of an integer\n";
    cout << "7. Scale the array\n";
    cout << "8. Reverse the array\n";
    cout << "9. Zero base the array\n";
    cout << "10. Remove an integer\n";
    cout << "11. Sort the array\n";
    cout << "12. Quit\n";
    cout << endl;
    cout << "Enter your choice: ";
    cin >> option;
    cout << endl;
}

void GetAverage(void)
{
    int sum = 0;
    for (int i = 0; i < dataCount; i++)
    {
        sum += numbers[i];
    }
    cout << fixed << setprecision(2) << sum / (double)dataCount << endl;
}

void GetSmallest(void)
{
    int smallest = numbers[0];
    for (int i = 1; i < dataCount; i++)
    {
        if (numbers[i] < smallest)
        {
            smallest = numbers[i];
        }
    }
    cout << smallest << endl;
}

void GetNumOccurences(int num)
{
    int found = 0;
    for (int i = 0; i < dataCount; i++)
    {
        if (numbers[i] == num)
        {
            found++;
        }
    }
    cout << found << endl;
}

void Quit(void)
{
    ofstream outfile("Numbers.dat");
    for (int i = 0; i < dataCount; i++)
    {
        outfile << numbers[i] << endl;
    }
    outfile.close();
    exit(0);
}
