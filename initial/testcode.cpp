#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream infile;
    infile.open("tc1_aclepius_pack");
    string r1, c1, str = "", temp = "";
    infile >> r1;
    infile >> c1;

    int arr[stoi(r1)][stoi(c1)]; // Mảng 2 chiều có r1 hàng và c1 cột
    int r1_index = 0;
    int c1_index = 0;
    getline(infile, str);
    while (!infile.eof())
    {
        getline(infile, str); // Đã có str
        for (int i = 0; i < str.length(); i++)
        {
            temp += str[i];
            if (temp == " ")
            {
                temp = "";
            }
            if ((str[i + 1] == ' ') || (str[i + 1] == '\0'))
            {
                arr[r1_index][c1_index] = stoi(temp);
                ++c1_index;
                temp = "";
            }
        }
        ++r1_index;
        c1_index = 0;
        str = "";
    }
    cout << c1_index;
    return 0;
}