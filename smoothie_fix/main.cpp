#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cfloat>
#include <sstream>
using namespace std;

int nthOccurrence(const string& str, const string& findMe, int nth)
{
    size_t  pos = 0;
    int     cnt = 0;

    while (cnt != nth)
    {
        pos += 1;
        pos = str.find(findMe, pos);
        if (pos == std::string::npos)
            return -1;
        cnt++;
    }
    return pos;
}

int main(int argc, char *argv[]) {
    string read;
    string out;

    getline(cin, read);
    getline(cin, read);
    getline(cin, read);

    while (!cin.eof()) {
        getline(cin, read);
        if (read[3] != '\t') {
            cout << endl;
            out = read;
            if (out[out.length() - 1] != 9) {
                getline(cin, read);
                out += read;
            }
            out = out.substr(0, nthOccurrence(out, "\t", 9));
            cout << out;
        }

        else {
            vector <string> tokens;
            stringstream check(read);
            string intermediate;

            while (getline(check, intermediate, '\t'))
            {
                tokens.push_back(intermediate);
            }

            cout << "\t" << tokens[7] << "\t" << tokens[8];
        }

        /*vector <string> tokens;
        stringstream check(read);
        string intermediate;

        while (getline(check, intermediate, '\t'))
        {
            tokens.push_back(intermediate);
        }

        if (tokens.size() < 4) {
            out = read;
            getline(cin, read);
            out += read;
            out = out.substr(0, nthOccurrence(out, "\t", 9));

            cout << "XX: " << out << endl;

            vector <string> tokens;
            stringstream check(read);
            string intermediate;

            while (getline(check, intermediate, '\t'))
            {
                tokens.push_back(intermediate);
            }
        }

        else if (tokens[3] != " ") {
            if (!out.empty()) {
                cout << out << endl;
            }
            out = read;
            out = out.substr(0, nthOccurrence(out, "\t", 9));
        }

        else {
            string add = "\t";
            add += tokens[7];
            add += "\t";
            add += tokens[8];
            out += add;
        }*/
    }

}
