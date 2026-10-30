#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Đề đã cung cấp sẵn, viết lại để chạy độc lập
string format_read_number(const string& s) {
    stringstream ss(s);
    string word, result = "";
    while (ss >> word) {
        if (!result.empty()) result += " ";
        result += word;
    }
    return result;
}

string read_three(int x, bool full) {
    string d[] = {"khong", "mot", "hai", "ba", "bon",
                  "nam", "sau", "bay", "tam", "chin"};
    int h = x / 100;
    int t = (x / 10) % 10;
    int u = x % 10;
    string s = "";
    bool has_hundred = (full || h > 0);

    if (has_hundred) s += d[h] + " tram ";

    if (t == 0) {
        if (u > 0) {
            if (has_hundred) s += "le ";
            s += d[u] + " ";
        }
    } else {
        if (t == 1) s += "muoi ";
        else s += d[t] + " muoi ";
        if (u > 0) s += d[u] + " ";
    }
    return s;
}

string read_number(int n) {
    if (n == 0) return "khong";

    int trieu = n / 1000000;
    int nghin = (n / 1000) % 1000;
    int donvi = n % 1000;

    string result = "";

    if (trieu > 0) {
        result += read_three(trieu, false) + " trieu ";
    }
    if (nghin > 0 || (trieu > 0 && donvi > 0)) {
        result += read_three(nghin, trieu > 0) + " nghin ";
    }
    if (donvi > 0) {
        result += read_three(donvi, trieu > 0 || nghin > 0);
    }

    return format_read_number(result);
}

int main() {
    int n;
    cin >> n;
    cout << read_number(n) << endl;
    return 0;
}