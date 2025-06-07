//Writing a class object to a file using ofstream class and mode ios::out

#include<iostream>
#include<fstream>
using namespace std;
class A
{
private:
char name[40];
int age;
float height;
char gender;

public:
void putdata();
void getdata();
void savedata();
void readdata();
};

//Defining the function putdata() to enter the values of data members of an object.
void A :: putdata()
{
cout<<"Enter the name : ";
cin.getline(name,40);
cout<<"Enter the age : ";
cin>>age;
cout<<"Enter the height : ";
cin>>height;
cout<<"Enter the gender : ";
cin>>gender;
}
//Defining the function getdata() to read the values of data members of an object.
void A :: getdata()
{
cout<<"The name is : " << name << "\n";
cout<<"The age is : " << age << "\n";
cout<<"The height is : " << height << "\n";
cout<<"The gender is : " << gender << "\n";
}
void A :: savedata()
{
ofstream ofstream_ob;
ofstream_ob.open("File9.txt", ios::out);
//Calling the write() function to write an object to a file.
ofstream_ob.write( (char *) this, sizeof(*this));
cout<<"Congrats! Your object is successfully written to the file \n";
ofstream_ob.close();
}
void A :: readdata()
{
//Creating an input stream
ifstream ifstream_ob;
//Calling the open function to read an object from a file
ifstream_ob.open("File9.txt", ios::in);
cout<<"\nReading the object from a file : \n";
//you can take an empty obj for reading or use already created obj
ifstream_ob.read( (char *) this, sizeof(*this));
//Closing the input stream
ifstream_ob.close();}
int main()
{
//Creating an object of A class
A ob1;
A ob2;

//Calling the functions
ob1.putdata();
ob1.savedata();
ob2.readdata();
ob2.getdata();
return 0;
}

