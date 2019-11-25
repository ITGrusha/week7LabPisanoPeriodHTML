#include <iostream>
#include <cmath>
#include <vector>
#include "Pisano.hpp"
#include "FibMod.hpp"

#define rows 125

using namespace std;

int main() {
//    int rows = 10;
//    clog << "Number of rows:";
//    cin >> rows;
    cout << "<!DOCTYPE HTML>"
         << R"(<head><meta charset="utf-8"><link rel="stylesheet" type="text/css" href="style.css"></head>)"
         << "<body>"
         << "<table>";

    cout << R"(<tr><th rowspan="2">M</th><th rowspan="2">PL</th><th colspan=")" << to_string(rows) << "\">S</th></tr>"
         << "<tr>";
    for (int i = 0; i < rows; ++i)
        cout << "<th>" << i << "</th>";
    cout << "</tr>";
    cout << "<tr>";
    int color = 0xFFFFFF, colorCount = sqrt(rows) + 1, delta = 0x080808;
    int colors[rows];
    for (int i = 0; i < rows; ++i) {
        colors[i] = color;
        color -= delta;
    }
    for (int i = 1; i <= rows; ++i) {
        Sequence seq(i);
        int x = seq.getPeriodLength();
        cout << "<th>" << i << "</th>" << "<th>" << x << "</th>";
        vector<int> period = seq.getPeriod(),
                repeatedNums(i, 0);
        for (int j = 0; j < x; ++j)
            repeatedNums[period[j]]++;
        for (int j = 0; j < i; ++j) {
            string dodatkoviy = "";
            if (repeatedNums[j] == 0)
                for (int k = 0; k < log(rows) / log(10); ++k)
                    dodatkoviy += "";
            else {
                for (int k = log(repeatedNums[j]) / log(10); k < log(rows) / log(10); ++k) {
//                    clog << log(repeatedNums[j]) / log(10);
                    dodatkoviy += "_";
                }
            }
            cout << "<td bgcolor=\"#" << std::hex << repeatedNums[j] * 12000 << "\">"
                 << std::dec << repeatedNums[j] << dodatkoviy << "</td>";
        }
        cout << "</tr>";
        color -= 0xFFFFFF / rows;
    }
    cout << "</table>";
    cout << "</body>";
}
