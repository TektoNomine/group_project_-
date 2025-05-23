#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int option;
int numbers[50];
int dataCount = 0;

void ShowMenu(void);
double GetAverage(void);
int GetSmallest(void);
void GetNumOccurences(int);
void Quit(void);

void scaleUp(void);
void reverse(void);
void zeroBase(void);
void removeNumber(void);
void Display(int[], int);
int GetTotal(int[], int);
int GetLargest(int[], int);
void Sort(int[], int);


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
			Display(numbers, dataCount);
            break;
        case 2:
        {
            cout << "Total: " << GetTotal(numbers, dataCount) << endl;
            break;
        }
        case 3:
            GetAverage();
            break;
        case 4:
        {
            int largest = GetLargest(numbers, dataCount);
            cout << "Largest value: " << largest << endl;
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
            scaleUp();
            break;
            
        }
        case 8:
        {
            reverse();
            break;
        }
        case 9:
        {
            zeroBase();
            break;
        }
        case 10:
        {
            removeNumber();
            break;
        }
        case 11:
        {
            Sort(numbers, dataCount);
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
// Functions by Dylan
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
double GetAverage(void)
{
    int sum = 0;
    for (int i = 0; i < dataCount; i++)
    {
        sum += numbers[i];
    }
    double average = (double)sum / dataCount;
    cout << fixed << setprecision(2) << "Average: " << average << endl;
    return average;
}
int GetSmallest(void)
{
    int smallest = numbers[0];
    for (int i = 1; i < dataCount; i++)
    {
        if (numbers[i] < smallest)
        {
            smallest = numbers[i];
        }
    }
    return smallest;
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

// Functions by Maksym
void scaleUp(void)
{
    int sFactor;
    cout << "Enter the scale factor: ";
    cin >> sFactor;
    for (int i = 0; i < dataCount; i++)
    {
        numbers[i] *= sFactor;
    }
}
void reverse(void)
{
    for (int i = 0; i < dataCount / 2; i++)
    {
        int temp = numbers[i];
        numbers[i] = numbers[dataCount - 1 - i];
        numbers[dataCount - 1 - i] = temp;
    }
}
void zeroBase(void)
{
    int min = GetSmallest();
    for (int i = 0; i < dataCount; i++)
    {
        numbers[i] -= min;
    }
}
void removeNumber(void)
{
    int element;
    cout << "Enter the number of the element you want to delete: ";
    cin >> element;
    if (element >= 1 && element <= dataCount)
    {
        for (int i = element - 1; i < dataCount - 1; i++)
        {
            numbers[i] = numbers[i + 1];
        }
        dataCount--;
    }
}

// Functions by Luka(1.Display; 2.GetTotal; 4.GetLargest; 11.Short)

void Display(int numbers[], int count) {
    cout << "Array contents:\n";
    for (int i = 0; i < count; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int GetTotal(int numbers[], int count) {
    int total = 0;
    for (int i = 0; i < count; ++i) {
        total += numbers[i];
    }
    return total;
}

int GetLargest(int numbers[], int count) {
    if (count == 0) return -1; 
    int largest = numbers[0];
    for (int i = 1; i < count; ++i) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }
    return largest;
}

void Sort(int numbers[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                // Swap elements
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    std::cout << "Array sorted in ascending order.\n";
}
