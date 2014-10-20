#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("outputacm.txt");
    ofstream outfile("sample.txt");

    int n = 0;
    string s;
    const int kmax = 10000;
    while (++n <= kmax) {
        while (getline(infile, s) && !s.empty()) {
            outfile << s << endl;
        }
        outfile << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
