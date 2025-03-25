#include <fstream> //in order to input and output on files
#include <iomanip> //in order to manipulate the inputs and outputs
#include <iostream> //in order to print on the standard error
#include <limits>

using namespace std; //so that I don't have to write "std::" every time;

int main(void){
    ifstream data("data.txt"); //opening the input file into the variable <data>
    ofstream result("result.txt"); //opening (/creating) the output file into the variable <result>


    if(data.is_open() && result.is_open()){
        unsigned long long int numbers_total = 0ull; /* we don't know how many numbers there are in the file, 
                                                    so we should use the greatest possible integer there is */
        long double mean = 0l; /* in the data.txt file the numbers have 16 decimal digits, so the type double 
                                 hasn't got enough memory to store all of them without committing errors due to rounding,
                                 so we need the biggest possible floating-point literal to store every decimal digits correctly.*/

        /* In order to understand how many decimal digits our compiler and architecture give to a type, we can use the library <limits>,
        like this:*/
        cout << "The number of decimal digits for a double is: " << numeric_limits<double>::digits10 << endl;
        cout << "The number of decimal digits for a long double is: " << numeric_limits<long double>::digits10 << endl;

        long double sum = 0l;
        result << "# N Mean" << endl; //printing the header of the "result.txt" file
        long double value;
        while(!data.eof()){
            data >> value;
            
            /* In order to map the values of the file inside the interval [-1; 2] we need to use a linear transformation 
            of the type x'= a + b*x , where x is a point in [1; 5] coming from the file and x' is its corresponding 
            inside the interval [-1; 2]. Solving the system given substituting the extremes of the intervals inside the equation,
            we get that a = -7/4 = -1.75 and that b = 3/4 = 0.75 */
            const long double a = -(7.0/4.0); /* I couldn't find online if the type "double" could be promoted to "long double" 
                                                 or vice versa during arithmetic operations, so I decided not to risk it and 
                                                 initialised <a> and <b> to the type "long double" */
            const long double b = 3.0/4.0;
            value = a + b * value;
            sum += value; //at each reading, we add a value to the sum of all of them;
            numbers_total++; //at each reading, we add one number to the total of numbers;
            mean = sum/numbers_total; //now we can calculate the mean of the values read until now;
            result << setprecision(16) << scientific << numbers_total << " " << mean << endl;
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