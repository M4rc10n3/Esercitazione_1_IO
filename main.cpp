#include <fstream> //in order to input and output on files
#include <iomanip> //in order to manipulate the inputs and outputs
#include <iostream> //in order to print on the standard error

using namespace std; //so that I don't have to write "std::" every time;

int main(void){
    ifstream data("data.txt"); //opening the input file into the variable "data"
    ofstream result("result.txt"); //opening the output file into the variable "result"

    if(data.is_open() && result.is_open()){
        unsigned long long int numbers_total = 0; /* we don't know how many numbers there are in the file, 
                                                    so we should use the greatest possible integer there is */
        double mean = 0;
        double sum = 0;
        result << "# N Mean" << endl; //printing the header of the "result.txt" file
        double value;
        while(!data.eof()){
            data >> value; /* in the data.txt file the numbers have 16 decimal digits, 
            so the type double has enough memory to store all of them without wasting any useless (and expensive) memory. */
            
            /* In order to map the values of the file inside the interval [-1; 2] we need to use a linear transformation 
            of the type x'= a + b*x , where x is a point in [1; 5] coming from the file and x' is its corresponding 
            inside the interval [-1; 2]. Solving the system given substituting the extremes of the intervals inside the equation,
            we get that a = -7/4 = -1.75 and that b = 3/4 = 0.75 */
            const double a = -(7.0/4.0); /* Even if we initialised the constants using the "float" type, 
            then they would become type "double" with the arithmetic operations for the variable "value" */
            const double b = 3.0/4.0;
            value = a + b * value;
            sum += value; //at each reading, we add a value to the sum of all of them;
            numbers_total++; //at each reading, we add one number to the total of numbers;
            mean = sum/numbers_total; //now we can calculate the mean of the values read until now;
            result << setprecision(17) << scientific << numbers_total << " " << mean << endl;
        }}
    else{
    /*If there are any errors with the opening of the files, the code will print an error message to the user, 
    so that he knows what to do to solve the problem.*/
    if(data.fail()){
        string filename = "data.txt";
        cerr << "File not found: you need a file named " << filename <<  
                "in the same directory of the executable in order to make the code work.";
    }
    else{
        string filename = "result.txt";
        cerr << "File not found: you need a file named " << filename <<  
            "in the same directory of the executable in order to make the code work.";
    }
    }
    return 0;
    }