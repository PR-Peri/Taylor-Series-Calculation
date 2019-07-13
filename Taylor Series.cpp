/********************************************
Name: PR
ID  : *********
Assignment: 01
Email:************@STUDENT.MMU.EDU.MY
Phone:  *************
********************************************/
/*Hastags are used for readability purpose*/


#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw
using namespace std;

void displayMenu(char radordeg,int DeciP)  // variable declaration
{
 string mode;                              // Mode switch part
  if (radordeg =='R')
    {
       mode = "Radian";
    }
    else
    {
      mode = "Degree";
    }


	system("cls"); // Menu table with choices //
	cout <<endl;

	cout <<setw(50)<< "+-----------------------------------------------------+" << endl;
  cout <<setw(45) << internal << "       T R I G O N O M E T R Y	   P R O G R A M      " << endl;
	cout <<setw(50)<< " ===================================================== " << endl;
  cout <<setw(23) << internal << "   Mode = "<< mode <<endl;
  cout <<setw(35) << internal << "   Decimal Precision: "<< DeciP << endl;
  cout <<setw(50)<< " ----------------------------------------------------- " << endl;
	cout <<setw(45) << internal << "  Select:				                               " << endl;
	cout <<setw(45) << internal << "   1 => Switch Degree/Radian Mode		                      " << endl;
	cout <<setw(45) << internal << "   2 => Set Decimal Precision	 	                  " << endl;
  cout <<setw(45) << internal << "   3 => Display Results                                " << endl;
  cout <<setw(45) << internal << "   4 => Area of circle                                 " << endl;
	cout <<setw(50)<< " ----------------------------------------------------- " << endl;
	cout <<setw(45) << internal << "  Q => Quit				                           " << endl;
	cout <<setw(50)<< "+-----------------------------------------------------+" << endl;
	cout << endl;
	cout << "Choice => ";          // Opens up based on the choices given by user //
}


/*###########################################################################*/
/*variable declaration part */
// Displays value of decimal precision based on user's input.

void displayDeciP( int DeciP)
{
  cout << endl;
  cout << "Decimal precision= " << DeciP << endl;
  system ("pause");
}


/*###########################################################################*/
//This is based on the mode switch part.

void displayData(char& radordeg)
{
  cout << endl;
  if (radordeg =='R')
  {
    radordeg='D';
  }
  else
  {
    radordeg= 'R';
  }
  system("pause");
}


/*###########################################################################*/
// The new decimal precision based on the users inputs

void setDP(int& DeciP)
{
  cout << endl;
  cout << "New Decimal Precision => ";
  cin >> DeciP;

  if (DeciP <0)
  {
    cout << setw(3) << "Unrecognized output, please insert a valid value ! " << endl;
    cout << setw(3) << "Re-Enter to set a new Decimal Precision => " << endl;
    cin >> DeciP;
  }
  system("pause");
}

/*###########################################################################*/
// Mode switch

void changeradordeg( char& radordeg, int DeciP)
{
  if (radordeg =='D')
    {
      radordeg = 'R';
    }
  else
    {
      radordeg  = 'D';
    }
 system ("pause");
}


/*###########################################################################*/


void displayV(int DeciP, char radordeg, double angle)
{

	// Initialized the value of decimal precision 2 to a double value
	double DeciPre=1.0;
  // Loop for the decimal precision 2
	for (int i = 0; i < DeciP; i++)
	{
		DeciPre = DeciPre*0.1;
	}

 cout << setw(3)  << "User, You may enter your angle value => ";
 cin >> angle;

 // If the angle is in degree then the value have to go through the if else statement. The range value is starting from 360<f(x)>0.

 if (radordeg == 'D')
 {
   // OR statement is used in the if-else statement and while loop. //
	  if ((angle <0.0 || angle <360.0))
		{
			while (angle<360.0)
			{
				angle=angle+360.0;
			}
			while (angle >0.0)
			{
				angle=angle-360.0;
			}
			 angle=angle * 3.14159265358979323846264338327950288419716 / 180;
		}
	}
		else
		{
			if (angle >(3.14159265358979323846264338327950288419716*2))

      // it is multiplied by 2 because 360 is 2pi.
			{
				while (angle > (3.14159265358979323846264338327950288419716*2))
				{
					angle=angle-3.14159265358979323846264338327950288419716*2;
				}
			}
			else
			{
				while (angle< (3.14159265358979323846264338327950288419716*2))
				{
					angle=angle+3.14159265358979323846264338327950288419716*2;
				}
			}
			}

	// Cosine Series //
  // The 'n' variable is already initialized for both cos and sine as 100.
  // The value are initialized in decimal because of the data type, if user enters value in fraction then it will be accepted in the form of decimals.

  int j, n =100;
	double sum =1.0, s =1.0,temp = 0.0, difference=0.0;

  // the decimal precision is on the first row, so that it will function for the output after it.
  cout.precision (DeciP);
	cout.setf(ios::fixed);
  cout << endl;
	cout << setw(3) << " COS SERIES : " << endl;
  cout << endl;

  // This output prints out the first value of cos.

	cout << setw(3) << right << 1 << " => " << sum << endl;

// Loop to calculate the value of Cos //

	for( j=1; j<=n; j++)
	{
		s =(s *(-1)*(angle*angle))/(2*j  *(2*j-1));

		sum =sum + s ;

// The value j+1 is used as counter for the allignment of numeric values, like 1. "calculation" and etc.
// The word 'right' , is used to set the width value for the output value.

// this output prints the remaining arrows for the values for cos.
		cout << setw(3) << right << (j+1) << " => " << sum  << endl;

    		difference = sum - temp;

  // For negative value angle
		if (difference <=0)
		{
			difference = -difference;
		}


		if (difference <= DeciPre)
		{
			break;
		}

		temp = sum ;

	}


// Sine Series //
	int i ;
 	double  t, sumS ;
  difference = 0.0, temp = 0.0 ;
	t = angle;
	sumS = angle;

 // Loop to calculate the value of Sine //

 cout.precision (DeciP);
 cout.setf(ios::fixed);
 cout << endl;
 cout << setw(3) << "SINE SERIES : " << endl;
 cout << endl;

 // This output prints out the first value of sin.
 cout << setw(3) << right << 1 << " => " << angle << endl;


 for(i =1; i <= n ; i++)

 {
  t =(t *(-1)*angle*angle)/(2*i *(2*i +1));

	sumS = sumS +t ;

 // this output prints the remaining arrows for the values for sin.

	cout << setw(3) << right << (i+1) << " : " << sumS << endl;


	difference = sumS - temp;

	if (difference <=0)
	{
		difference = -difference;
	}

	if (difference <= DeciPre)
	{
		break;
	}

	temp = sumS;
 }

  cout << endl;
  cout << setw(3) << "RESULTS : " << endl;


  cout << endl;
  cout << setw(3) <<"Cos(x) = " << sum ;

  cout << endl;
 	cout << setw(3) <<"Sin(x) = "<< sumS;
	cout << endl;


}

/*###########################################################################*/
//Area of circle

void areaCircle(int DeciP)
{
    double rad, area;

    cout << "Enter the radius of circle : ";
    cin >> rad;
    cout << endl;

    //formula to calculate area
    cout.precision(DeciP);
    cout.setf(ios::fixed);
    area = 3.14159265358979323846264338327950288419716 *rad *rad;
    cout << "Area of circle with radius " << rad << " is " << area;

    cout << endl;


system("pause");
}

/*###########################################################################*/
// Main function

int main()
{
  char radordeg;
  radordeg ='R';
  // Mode is intially in Radian mode
  double angle(0.0);
  // Angle is the output by the user which is currently set to 0.0 because double includes decimal value.
  int DeciP(10);
  // Decimal Precision is intially set to 10
  double rad;
	char choice;
	bool done = false;
	do
  {
		displayMenu(radordeg,DeciP);
		cin >> choice;
		choice = toupper(choice);
		switch (choice)
		{

      case '1' :  changeradordeg(radordeg,DeciP);
                  break;

			case '2' :  setDP (DeciP);
                  cout << DeciP << endl;

                  break;

      case '3' :  displayV(DeciP,radordeg,angle);
                  system("pause");
                  break;

      case '4'  : areaCircle(DeciP);
                  system("pause");
			            break;


			case 'Q' : done = true;
                 system("pause");     // Case Q ends the program.
			break;

			default	: cout << "Invalid selection,Please, try again!" << endl;
			system("pause");
			break;
		}
	}
	while (!done);    // Loop ends when user is done using the program.
  {

		cout << "Good Bye! Thank you for using Trigonometry Program, you may try again !" << endl;
		cout << endl;

	}
  return 0;
}

/*###########################################################################*/
