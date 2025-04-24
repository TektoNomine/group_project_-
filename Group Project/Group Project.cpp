#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//void InputList(void);
void ShowMenu(void);
//todo:LS:1.Display
//todo:LS:2.GetTotal
void GetAverage(void);
//todo:LS:4.GetLargest
void GetSmallest(void);
void GetNumOccurences(int);
//todo:MS:7.ScaleUp
//todo:MS:8.Reverse
//todo:MS:9.ZeroBase
//todo:MS:10.RemoveNumber
//todo:LS:11.Sort
void Quit(void);

int main()
{
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
            break;  // exit the loop
        }
    }
    infile.close();


    while (true)
    {
        ShowMenu();
        switch (option)
        {
        case 1:
            //Display
            break;
        case 2:
            //GetTotal
            break;
        case 3:
            GetAverage();
            break;
        case 4:
            //GetLargest
            break;
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
                // error checking
                if (cin.fail())
                {
                    cout << "Invalid input." << endl;
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
        case 10:
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
            //Sort
            break;
        case 12:
            Quit();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
	//Function to input integers into array for simple testing
    /*void InputList(void)
    {
        cout << "Enter 12 integers: \n";
        for (int i = 0; i < 12; i++)
        {
            cout << "Enter integer " << i + 1 << ": ";
            cin >> list[i];
            //error checking
            if (cin.fail())
            {
                cout << "Invalid input. Please enter an integer." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                i--;
            }
        }
    }*/

    void ShowMenu(void)  
       {  
           cout << endl;  
           cout << "1. Display the contents of array\n";  
           cout << "2. Get the total of the array\n";  
           cout << "3. Get the average of the array\n";  
           cout << "4. Get the largest integer in the array\n";  
           cout << "5. Get the smallest integer in the array\n";  
           cout << "6. Get the number of occurrences of an integer\n";  
           cout << "7. Update content of array based on scale factor\n";  
           cout << "8. Reverse the order of the contents in the array\n";  
           cout << "9. Zero base the array\n";  
           cout << "10. Remove an integer from the array\n";  
           cout << "11. Sort the array smallest to largest\n";  
           cout << "12. Quit\n";  
           cout << endl;  
           cout << "Enter your choice: ";  
           cin >> option;  
           cout << endl;  
       }

    void GetAverage(void)
    {
        int sum = 0;
        for (int i = 0; i < 12; i++)
        {
            sum += numbers[i];
        }
        cout << "Average: " << fixed << setprecision(2) << sum / 12.0 << endl;
        return;
    }

    void GetSmallest(void)
    {
        int smallest = numbers[0];
        for (int i = 1; i < 12; i++)
        {
            if (numbers[i] < smallest)
            {
                smallest = numbers[i];
            }
        }
        cout << "Smallest: " << smallest << endl;
        return;
    }

    void GetNumOccurences(int num)
    {
        int count = 0;
        for (int i = 0; i < 12; i++)
        {
            if (numbers[i] == num)
            {
                count++;
            }
        }
        //error checking if number is not in the list
        if (count == 0)
        {
            cout << "Number not found in list." << endl;
            return;
        }
        cout << "Number of occurences: " << count << endl;
        return;
    }

    void Quit(void)
    {
        cout << "Goodbye!" << endl;
        exit(0);
    }

    //Maksym's work
    /*do
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
            
        case 8:
            // Reverse
            
            break;
        case 9:
            // ZeroBase
        {
            
            break;
        }
        case 10:
            // RemoveNumber
            

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
    return 0;*/

