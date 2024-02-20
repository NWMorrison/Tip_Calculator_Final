///-------------------------------------------------Tip-Calculator---------------------------------------------------///
///                  This program is a fully functional tip calculator that will do the following:                   ///
// 1). Accept a Subtotal Amount (Before tip adjustment)
// 2). Accept a tip (Either as a percentage or a whole dollar amount)
// 3). Print receipt to console with values for subtotal, tip percent, tip amount, and total.
// 4). Values must be fixed with a set-precision of 2 decimal places.
// 5). Calculate any missing values.


// 2/19/24 - Computer Security "Scorecard"
// I am updating my Git repository to see reflected security changes.
// Will be updating this code over the next couple of weeks to learn about security flaws and improvements.

#include <iostream> // Input/Output to our console.
#include <iomanip>  // Manipulation of our console.


int main()
{

    int choice = 0;                 // This allows for a controlled do/while loop to repeatedly run the tip-calculator.

    std::cout << "\t\t\tWelcome To My Tip Calculator\n"
                 "\nThis Program will take a subtotal amount input by the user and calculate the tip on that amount.\n"
                 "You may input either a percentage or an actual dollar amount that you would like to leave.\n"
                 "The Program will then provide a receipt with everything broken down in a neat format." << std::endl;

    do
    {
        int option = 0;             // This allows for control of our conditional-if branch.


        double subTotal = 0.00;     // This variable holds our initial subtotal value input by the user.
        double tip;                 // This variable holds our final tip amount which is completed on the back-end.
        double tip_Percent = 0.00;  // This variable holds our tip percentage value. (User Input & Back-End).

        double cash_Amount = 0.00;  // This variable holds our cash amount input by the user.
        double final_Amount;        // This variable holds our final total amount which is completed on the back-end.


        // This block asks for user input of our subtotal.
        std::cout << std::endl;
        std::cout << "Please Enter The SubTotal ($00.00) For The Item You Have Purchased: ";
        std::cin >> subTotal;
        std::cout << std::endl;


        // This block sets up our conditional if-statement for user input of either a tip percentage or a dollar amount.
        std::cout << "Would You Like To Enter The Tip Percentage (1) or An Actual Dollar Amount (2): \n"
                     "1). Tip Percentage(%)\n"
                     "2). Dollar Amount($)\n"
                     "Selection: ";
        std::cin >> option;
        std::cout << std::endl;



        if (option == 1) // Option 1: (Tip Percentage Calculation)
        {
            // This block asks for the percentage amount for the tip that the user would like to leave.
            std::cout << "Enter the Percentage (00.00)% Amount You would like to leave: ";
            std::cin >> tip_Percent;
            std::cout << std::endl;


            // This conversion takes that percentage, converts it down into a decimal number
            // We then multiply that value by our subtotal which will give us our final value of our tip.
            tip = (tip_Percent / 100.00) * subTotal;


            // This conversion takes our final amount takes our subtotal and adds our tip.
            final_Amount = (subTotal + tip);



            // This block prints a receipt with set precision to "2" decimal places for every floating point value.
            // This allows for fluidity when we print out to console.
            std::cout.precision(2);
            std::cout << "Receipt:" << std::endl;
            std::cout << "Subtotal:" << std::setw(6) << "$" << std::fixed << subTotal << std::endl;
            std::cout << "Tip (" << tip_Percent << "%): "  << "$"  << tip << std::endl;
            std::cout << std::setw(22) << "--------" << std::endl;
            std::cout << "Total:" << std::setw(9) <<  "$" << final_Amount << std::endl;
        }


        else if (option == 2) // Option 2 (Cash Amount Calculation)
        {
            // This block asks the user for the cash amount that they would like to leave as a tip.
            std::cout << "Enter The Cash Amount ($10.00, $20.00, $50.00) You Would Like To Leave:  ";
            std::cin >> cash_Amount;
            std::cout << std::endl;


            // This conversion takes our cash amount and converts it into a percentile.
            tip_Percent = (cash_Amount / subTotal) * 100;

            // This conversion takes our final amount takes our subtotal and adds our tip.
            final_Amount = (subTotal + cash_Amount);


            // This block prints a receipt with set precision to "2" decimal places for every floating point value.
            // This allows for fluidity when we print out to console.
            std::cout.precision(2);
            std::cout << "Receipt:" << std::endl;
            std::cout << "Subtotal:" << std::setw(7) << "$" << std::fixed << subTotal << std::endl;
            std::cout << "Tip ("  << tip_Percent << "%): " << std::setw(3) << "$" << cash_Amount << std::endl;
            std::cout << std::setw(22) << "--------" << std::endl;
            std::cout << "Total:" << std::setw(10) <<  "$" << final_Amount << std::endl;
        }


        // Minor error handling if user inputs anything but a 1 or a 2 as an integer input.
        else
        {
            std::cout << "Invalid Input. Please Run The Program Again." << std::endl;
        }



        std::cout << std::endl;

        // Prompts the user if they would like to run the program again.
        std::cout << "Would you like to run the Tip-Calculator again? \n"
                     "1). Yes: \n"
                     "2.) No:  \n"
                     "Selection:";

        std::cin >> choice;
        std::cout << std::endl;

    } while (choice != 2); // If our choice is 2 which is no, we exit our do/while loop.



    // Prints out a goodbye message letting the user know the program has ended.
    std::cout << "Thank You For Using The Tip Calculator\n"
                 "Have A Nice Day!" << std::endl;


    return 0;
}
