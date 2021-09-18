//Algorithm Workbench 6 Number Analysis Program
//Write a program that asks the user for a file name. Assume the file contains a 
//series of numbers, each written on a separate line.
//The program should read the contents of the file into an array and then use 
//separate array processing related functions to display the following data

#include <iostream>
#include <fstream>
using namespace std;

// function prototypes
void getFileInput(/*out*/int[], /*in*/int);
void showOutput(/*out*/int[],/*in*/int);
int getTotal(/*out*/int[], /*in*/int);
int getLeast(/*out*/int[], /*in*/int);
int getMost(/*out*/int[], /*in*/int);
int getAverage(/*out*/int numbers[], int size);

int main()
{
    const int size = 10;
    int numbers[size]; // 1D array declaration

    // array related processing done by the the following function calls
    getFileInput(numbers, size); // call function to input elements from a file
    showOutput(numbers, size); // call function to output elements
    cout << "\nTotal of all the numbers: " << getTotal(numbers, size) << endl; // call function to calculate total of all elements
    cout << "\nLowest number is : " << getLeast(numbers, size) << endl; // call function to determine least number of all elements
    cout << "\nHighest number is : " << getMost(numbers, size) << endl; // call function to determine highest number of all elements
    cout << "\nAverage of all numbers: " << getAverage(numbers, size) << endl; // call function to determine average of all elements


    return 0;
}

void getInput(/*out*/int numbers[], int size)
{
    // input elements
    cout << "Enter 10 numbers." << endl;
    for (int count = 0; count < size; count++)
    {
        cout << "Number #" << (count+1) << ": ";
        cin >> numbers[count]; // input to array a single value using the subscript or index
    }
}
void getFileInput(/*out*/int numbers[], /*in*/int size)
{
   ifstream inData;
   string fileName;

   cout << "Enter a data file name: ";
   cin >> fileName;

   inData.open(fileName.c_str()); // argument for runtime input of file name

   //inData >> numbers[count]; // priming read
   for(int count = 0; count < size; count++)
   {
       inData >> numbers[count];
   }
   inData.close();
}
void showOutput(/*out*/int numbers[], int size)
{
    // show elements
    cout << "\nList of numbers below" << endl;
    for (int count = 0; count < size; count++)
    {
        cout << "Number #" << (count+1) << ": " << numbers[count] << endl; // output a single value using the subscript or index
    }
}
int getTotal(/*out*/int numbers[], int size)
{
    int total = 0;
 // sum all the elements
    for (int count = 0; count < size; count++)
    {
        total = total + numbers[count];
    }

    return total;
}
int getLeast(/*out*/int numbers[], int size)
{
    int least = 2000;
    // find least number
    least = numbers[0]; // assign first element value to least temporary state
    for (int count = 1; count < size; count++)
    {
        if (numbers[count] < least)
        least = numbers[count]; // swap values to store a smaller element
    }

    return least;
}
int getMost(/*out*/int numbers[], int size)
{
    int most = 0;
    // find highest number
    most = numbers[0]; // assign first element value to highest temporary state
    for (int count = 1; count < size; count++)
    {
        if (numbers[count] > most)
        most = numbers[count]; // swap values to store a higher element
    }

    return most;
}
int getAverage(/*out*/int numbers[], int size)
{
    int average = 0, total = 0;
    // find highest number
    average = numbers[0]; // assign first element value to highest temporary state
    for (int count = 1; count < size; count++)
    {
        average = average + total / count;
    }

    return average;
}
