#include <iostream>
#include <fstream>


using namespace std;

int main() 
{
    cout << "Hello, World!" << endl;

    string line;
    ofstream fout;
    fout.open("output.txt");
    while (fout)
    {
        getline(cin, line);

        if(line == "exit")
        {
            break;
        }
        else
        {
            fout << line << endl;
        }
    }
    fout.close();

    ifstream fin;
    fin.open("output.txt");
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();       

    fstream file;
    file.open("output.txt", ios::trunc | ios::in | ios::out);
    while (file)
    {
        getline(cin, line);

        if(line == "exit")
        {
            break;
        }
        else
        {
            file << line << endl;
        }
    }
    file.seekg(0, ios::beg);
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    

    return 0;
}