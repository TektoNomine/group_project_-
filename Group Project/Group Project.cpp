#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // hello
    int option;
    int numbers[50];
    int count = 0;

    ifstream infile("Numbers.dat");
    for (int i = 0; i < 50; i++)
    {
        if (infile >> numbers[i]) {
            count++;  // count how many numbers were actually read
        }
        else {
            break; // if the file has ended or an error occurred — exit the loop
        }
    }
    infile.close();

    

    do
    {
        cout << "\n\t=== Main Menu ===\n";
        cout << "\t1. Option 1\n";
        cout << "\t2. Option 2\n";
        cout << "\t3. Option 3\n";
        cout << "\t4. Option 4\n";
        cout << "\t5. Option 5\n";
        cout << "\t6. Option 6\n";
        cout << "\t7. ScaleUp\n";
        cout << "\t8. Reverse:\n";
        cout << "\t9. ZeroBase:\n";
        cout << "\t10. RemoveNumber\n";
        cout << "\t11. Option 11\n";
        cout << "\t12. Exit\n";

        cout << "\n\tSelect an option (1-12): ";
        cin >> option;

        cout << endl;

        switch (option)
        {
        case 1:
            cout << "\t\tExecuting functionality associated with Option 1\n";
            break;
        case 2:
            cout << "\t\tExecuting functionality associated with Option 2\n";
            break;
        case 3:
            cout << "\t\tExecuting functionality associated with Option 3\n";
            break;
        case 4:
            cout << "\t\tExecuting functionality associated with Option 4\n";
            break;
        case 5:
            cout << "\t\tExecuting functionality associated with Option 5\n";
            break;
        case 6:
            cout << "\t\tExecuting functionality associated with Option 6\n";
            break;
        case 7:
            //ScaleUp
            int sFactor;

            cout << "Enter scale factor : ";
            cin >> sFactor;

            for (int i = 0; i < count; i++)
            {
                numbers[i] = numbers[i] * sFactor;
            }
            cout << "\t\tAll numbers multiplied by " << sFactor << endl;
            break;
        case 8:
            // Reverse
            int reversed[50];

            for (int i = 0; i < count; i++)
            {
                reversed[i] = numbers[count - 1 - i];
            }
            for (int i = 0; i < count; i++)
            {
                numbers[i] = reversed[i];
            }
            cout << "\t\tArray reversed successfully (using temp array)." << endl;
            break;
        case 9:
            // ZeroBase
        {
            int min = numbers[0];
            for (int i = 0; i < count; i++)
            {
                if (min > numbers[i])
                {
                    min = numbers[i];
                }
            }

            for (int i = 0; i < count; i++)
            {
                numbers[i] = numbers[i] - min;
            }
            cout << "Updated the content of the array" << endl;
            break;
        }
        case 10:
            // RemoveNumber
            int element;
            cout << "Enter the element number to remove (1 to " << count << "): ";
            cin >> element;

            if (element < 1 || element > count)
            {
                cout << "Invalid element number" << endl;
            }
            else
            {
                for (int i = element - 1; i < count - 1; i++)
                {
                    numbers[i] = numbers[i + 1];
                }
                count--;
                cout << "Element removed successfully." << endl;
            }

            break;
        case 11:
            cout << "\t\tExecuting functionality associated with Option 11\n";
            break;
        case 12:
        {
            ofstream outfile("Numbers.dat");
            for (int i = 0; i < count; i++)
            {
                outfile << numbers[i] << endl;
            }
            outfile.close();
            cout << "\t\tExiting program...\n";
            break;
        }
        default:
            cout << "\t\tInvalid option. Please choose between 1 and 12.\n";
        }
    } while (option != 12);
    return 0;
}
