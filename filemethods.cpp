#include <bits/stdc++.h>

using namespace std;


//method for printing a file--------------------------------------------------------------------------------------------------------------
void printFile(string fileName){
    ifstream file;
    file.open(fileName.c_str());
    string line;
    while(getline(file,line)){
        cout<<line<<endl;
    }
    file.close();
}



//NO OF LINES FUNCTION -----------------------------------------------------------------------------------------------------------------
int get_no_of_lines(string file_name)
{

	string line;
	int count=0;

	ifstream mFile (file_name.c_str());

	if(mFile.is_open())
	{
		while(mFile.peek()!=EOF)
		{
			getline(mFile, line);
			count++;
		}
		mFile.close();
	    return count ;
	}
	else
		cout<<"Couldn't open the file\n";

	return 0;
}


