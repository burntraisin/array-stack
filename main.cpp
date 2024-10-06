#include <iostream>

using namespace std;

void pop();
void push(int element);
void top();
void size();
void empty();
void displayStack();

int currentPointer = -1;
int stack[15];

int main()
{
    int userChoice = 0, element = -1, restartProgram = 0;

    do 
    {
        currentPointer = -1;
        do 
        {
            cout << "-----------------------------------------------------------"
            << '\n' << "Enter a number to perform one of the following on the stack: "
            << '\n' << "1. Pop"
            << '\n' << "2. Push"
            << '\n' << "3. Top"
            << '\n' << "4. Size"
            << '\n' << "5. Empty"
            << '\n' << "0. Quit"
            << '\n' << "-----------------------------------------------------------"
            << endl;
            cin >> userChoice;

            switch (userChoice) 
            {
                case 0:
                    break;
                case 1:
                    pop();
                    displayStack();
                    break;
                case 2:
                    cout << "Enter a number between 0 and 99 to push onto the stack: ";
                    cin >> element;
                    while (!(element >= 0 && element <= 99)) 
                    {
                        cout << "ERROR: Invalid input. Try again: ";
                        cin >> element;
                    }
                    push(element);
                    displayStack();
                    break;
                case 3:
                    top();
                    displayStack();
                    break;
                case 4:
                    size();
                    displayStack();
                    break;
                case 5:
                    empty();
                    displayStack();
                    break;
                default:
                    break;
            }
        } while (userChoice != 0);

        cout << "Would you like to restart this program?"
        << '\n' << "0. No"
        << '\n' << "1. Yes"
        << endl;
        cin >> restartProgram;
    } while (restartProgram == 1);

    return 0;
}

void push(int element) 
{
    if (currentPointer > 13) 
    {
        cout << "ERROR: Stack overflow. Item cannot be pushed." << endl;
    }
    else 
    {
        currentPointer += 1;
        stack[currentPointer] = element;
    }
}

void pop() 
{
    if (currentPointer < 0) 
    {
        cout << "ERROR: Stack underflow. Stack is empty." << endl;
    }
    else 
    {
        cout << stack[currentPointer] << " is popped." << endl;
        currentPointer -= 1;
    }
}

void top() 
{
    if (currentPointer < 0) 
    {
        cout << "ERROR: Stack underflow. Stack is empty." << endl;
    }
    else 
    {
        cout << "Top of the stack: " << stack[currentPointer] << endl;
    }
}

void size() 
{
    cout << "Size of the stack: " << (currentPointer + 1) << endl;
}

void empty() 
{
    if (currentPointer < 0) 
    {
        cout << "The stack is empty." << endl;
    }
    else 
    {
        cout << "The stack is NOT empty." << endl;
    }
}

void displayStack() 
{
    cout << "Stack: ";
    for (int i = 0; i <= currentPointer; i++) 
    {
        cout << "  " << stack[i] << "  ";
    }
    cout << endl;
}