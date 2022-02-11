#include <iostream>//Reg: 2019504
using namespace std;//Syed Nazim Shah
class String{ // creating a class String
private:
    int size;
    char* MyString = new char[100];// creating a dynamic array
public:
String(){// default constructor
    size=0;
	MyString[0]='\0';
}
String(int num){// constructor which has integer num passed in parmeter as Size 
    size=num; // setting size as num which has been passed
    for (int i=0;i<size;i++){//initializing the array uptil size
    MyString[i]='\0';
    }
}
String(char temp[100]){// constructor in which character array is passed 
	for(size=0;temp[size]!='\0';size++)
	MyString[size]=temp[size]; // writing the passed array to the dynamic array of class
}
~String(){// deleting the dynamic array in the destructor function
    delete[] MyString;
}
void setvalue(char temp[100]){ // function designed to write the dynamic array of the class  
for(size=0;temp[size]!='\0';size++)
	MyString[size]=temp[size];
}
char* getvalue(){// fucntion designed to get the value of the dynamic array 
	return MyString;
}
int getsize(){//fucntion to get the size associated with th
	return size;
}
String operator=  (String const &temp){//overloading the copy operator with retrun type of class
	this->MyString=temp.MyString; // copying the strings
	return *this;//returning the string as a pointer
}
String operator+  (String const &temp){// overloading the addtition operator with return type of class 
    String dump;// creating a temporary dump string
	int i=0, j=0; // creating  temporary variables
	while(this->MyString[i]!='\0'){
		dump.MyString[i]=this->MyString[i];// writing the values of first string in the dump variable and counting 
		i++;// counting
	}
    while (temp.MyString[j]!='\0'){
	    dump.MyString[i]=temp.MyString[j];// writing the values of the second string which was passed as perameter 
		i++;// using the value of i to continue where the dump string was left
		j++;// incrementing the position value of the passed string
	}
	dump.size=i;// because the size will be equal to the value to which the i was counted in both loop
	dump.MyString[i]='\0';// capping off the string
	return dump;// returning the dump value
}
void operator+= (String const &temp){ // overloading the += operator with retrun type void because its a string manupulation operator
    int i=0,j=0;
	while(this->MyString[i]!='\0'){i++;} // couting where the fisrt string ends
	while (temp.MyString[j]!='\0'){// writing the second string to first from where it ends 
	    this->MyString[i]=temp.MyString[j];
		i++; // counting size and incrementing the position value as well 
		j++;
	}
	this->size=i;// because the size will be equal to the value to which the i was counted in both loop
	this->MyString[i]='\0';// capping off the string
}
bool operator==(String const &temp){// overloading  the check operator to see if both strings have same values
	int count=0;// position variable
	bool condition=true;
	while(condition==true || (this->MyString[count] != '\0' && temp.MyString[count] != '\0' )) // comparing the tho strings in this loop
	{
		if(this->MyString[count]== temp.MyString[count])
		count++;// incrementing the position variable
		else
		condition=false;
		break;
	}
	return condition; // returning the bool condition	
}
bool operator!=(String const &temp){// overloading  the check operator to see if both strings do not have same values
	int count=0;// position variable
	bool condition=true;
	while(condition==true || (this->MyString[count] != '\0' && temp.MyString[count] != '\0' )) // comparing the tho strings in this loop
	{
		if(this->MyString[count]!= temp.MyString[count])
		count++;// incrementing the position variable
		else
		condition=false;
		break;
	}
	return condition;// returning the bool condition	
}
char operator[](int num){ //operator overloaded to get a specific value from a string
	char temp;
	temp= this->MyString[num];
	return temp;
}
bool operator> (String const &temp){//overloading the compare operator to check and compare the size of two strings
	if(this->size > temp.size)
	return true;
	else
	return false;
}
bool operator< (String const &temp){//overloading the compare operator to check and compare the size of two strings
	if(this->size < temp.size)
	return true;
	else 
	return false;
}
String operator()(int lbound, int ubound){//overloading the ()operator to get specific string values from parent string by using the lowerbound and upperbound values passed as peremeter
	int i=0; // declaring a counter variable whic is also a position variable
	String temp;
	for(lbound,i;lbound<ubound;lbound++,i++)//using the for loop to put the specific values in the temporary string
		temp.MyString[i]=this->MyString[lbound];
	temp.size=i;//because the size will same as the counter i is incremented 
	return temp;//returning the instance as function type
}
String operator<< (int num){// overloading the left shift operator
		String temp;// a temporary string instance
		int i = 0; // counter and a postion variable
	    for (i; i < num; i++)
		{
			temp.MyString[i] = this->MyString[i];// copying the string value to the temp instance string
		}
		temp.MyString[i] = '\0';//capping the string
		temp.size = i;// setting the size as counter variable
		for (int j = 0; j < this->size; j++)//using loop to manupulate the original string and deleting the copied values
			{
				this->MyString[j] = this->MyString[i];
				this->MyString[i] = '\0';
				i++;
			}
		this->size = this->size - num; //setting the new size
		return temp;//returning the temp variable
	}
String operator>>(int n){// overloading the right shift operator
		String temp;// a temporary string instance
		int num=0;// counter and a postion variable
	    for (int i=1; i <= n; i++)
		{
			temp.MyString[num] = this->MyString[this->size-i]; //copying the string values and deleting the copied values
			this->MyString[this->size-i]='\0';
			num++;
		}
		temp.MyString[num] = '\0';//capping the new string 
		temp.size = num; // giving the temp string new size
		this->size = this->size - n; // resetting the the size of original string
		return temp;// returning the temp instance
	}
friend istream &operator>> (istream &cin, String &temp); // friend function to overload the stream input operator as istream is another class 
friend ostream &operator<< (ostream &cout, String &temp);// friend function to overload the stream output operator as ostream is another class 
};
ostream &operator<< (ostream &cout, String &temp){  //overloading the output operator to print the string array  
    int size=temp.getsize(); // getting size of string
    cout<<"\n";
	for (int i=0;i<size;i++) // printing string value
	cout<<temp.MyString[i];
	return cout;
}
istream &operator>> (istream &cin, String &temp){ //overloading the output operator to print the string array 
    char array[100];
	cin>>array; // getting the array from user
	temp.setvalue(array);// putting it in the dynamic array using function
	return cin;
}
    
int main()// demo of a few overloaded operators below
{
    String alpha("Name: Syed Nazim Shah ");
    String beta("Reg: 2019504");
    
	cout<<alpha<<beta;
    
    if(alpha==beta)
    cout<<"\nTrue";
    else
    cout<<"\nNot True";   
    if(alpha>beta)
    cout<<"\nTrue";
    else
    cout<<"\nNot True";
	
	String test=alpha+beta;
    cout<<test;
    
	String Test ("nazim ");
	Test += beta;
	cout<< Test;  
	
	String TEST= alpha << 11;
	cout<< TEST;
	
    return 0;
}
