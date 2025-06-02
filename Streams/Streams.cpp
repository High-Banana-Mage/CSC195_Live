#include <iostream>
#include <string>
using namespace std;

void Write(string text, ostream& ostream)
{
    //ostrean << text
}

int main()
{
    string text = "Hello World!\n";
    cout << text;

    cin >> text;

    getline(cin, text);
    /*
    cout << text;

    time_t start = time(NULL);

    for (int i = 0; i < 1'000'000; i++)
    {
        Write(text, cout);
    }

    time_t end = time(NULL);

    cout << "Total time for pass-by-value method call: " << end - start << endl;
    */
    ofstream output("data.txt");
    output << text;
    output.close();
}