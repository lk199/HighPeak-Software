#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

string goodie[20];
int price[20], lengthOfPrice=0, no_emp=2,low_goodie[20];

void tokenize(string s, string del = " ", int i=0)
{
    int start = 0;
    int end = s.find(del); string baby;

    while (end != -1) {
        //cout << s.substr(start, end - start) << endl;
        goodie[i] = s.substr(start, end - start);

        start = end + del.size();
        end = s.find(del, start);
    }
    //cout << s.substr(start, end - start);
     baby = s.substr(start, end - start);
     stringstream geek(baby);
     price[i] = 0;
     geek >> price[i];

     lengthOfPrice++;//variable keeps count of the length of the price array
}

void file_read(){
string pnp;
int i=0;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
     while (myfile.good())
        {
            getline(myfile, pnp);
            tokenize(pnp, ": ",i);
            i++;
            //cout << " Product Name: " << pname<<endl;
            //getline(myfile, pprice);
            //cout << " Price: " << pprice<<endl;
            cout<<endl;
        }
        myfile.close();
  }

  else {cout << "Unable to open file";}}

  void read_out(){
      for(int a=0;a<=13;a++){
        cout<<"goodie["<<a<<"] = "<< goodie[a]<<endl;
        cout<<"price["<<a<<"] = "<< price[a]<<endl;
      }
  }

void sort(int n=13){
    int temp; string ttt;
    //sorting - ASCENDING ORDER
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(price[i]>price[j])
			{
				temp = price[i];
				price[i] = price[j];
				price[j] = temp;

                ttt = goodie[i];
				goodie[i] = price[j];
				goodie[j] = ttt;
			}
		}
	}
}

// Returns minimum difference between any pair
int findMinDiff(int arr[], int n)
{
// Initialize difference as infinite
int diff = 99999;

// Find the min diff by comparing difference
// of all possible pairs in given array
for (int i=4; i<n-1; i++){
    for (int j=i+1; j<n; j++){
        if (abs(arr[i] - arr[j]) < diff)
                {diff = abs(arr[i] - arr[j]);}
}}

// Return min diff
return diff;
}

int main () {
    // price[0] = no. of employees
    // price[4] = price of 1st goodie
    // price[13] = price of last goodie

  file_read(); // reads the file "input.txt" line by line and processes the goodie names and prices
  cout<<endl<<endl;
  no_emp=price[0];
  //read_out(); // prints out the current values of the goodie and price arrays.

  ofstream outdata; // outdata is like cin
  outdata.open("output.txt"); // opens the file
    if( !outdata ) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }

    outdata << "Here the goodies that are selected for distribution are: " << endl;

for (int i=4; i< (no_emp+4); ++i)
      {outdata << goodie[i] <<": "<<price[i]<< endl;}

   outdata <<endl<<"And the difference between the chosen goodie with highest price and the lowest price is "<<findMinDiff(price,lengthOfPrice-no_emp)<<endl;
outdata.close();
  //cout<<endl<<endl;
  return 0;
}
