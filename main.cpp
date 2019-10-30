#include <iostream>
#include "Pisano.hpp"
#include "FibMod.hpp"

using namespace std;

int main() {
    cout << "<!DOCTYPE HTML>"
         << R"(<head><meta charset="utf-8"><link rel="stylesheet" type="text/css" href="style.css"></head>)"
         << "<body>"
         << "<table>";

    cout << "<tr>"
         << "<th>M</th>";
    for (int i = 0; i < 10; ++i)
        cout << "<th>" << (i + 1) << "</th>";
    cout << "</tr>";
    cout << "<tr>";
    cout << "<td>PL</td>";
    for (int i = 0; i < 10; ++i) {
        Sequence seq(i + 1);
        int x = seq.getPeriod();
        cout << "<td>" << x << "</td>";
    }
    cout << "</tr>";
    cout << "</table>";
    cout << "</body>";
}
