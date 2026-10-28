#include "time_utils.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

const long long SECONDS_PER_DAY = 86400;

long long normalize_day(long long s) {
    s %= SECONDS_PER_DAY;
    if (s < 0) s += SECONDS_PER_DAY;
    return s;
}

bool is_valid_time(int hour, int minute, int second) {
    return hour >= 0 && hour < 24 &&
           minute >= 0 && minute < 60 &&
           second >= 0 && second < 60;
}

int convert_time_to_second(int hour, int minute, int second) {
    return hour * 3600 + minute * 60 + second;
}

void convert_second_to_time(int total_second,
                            int& hour, int& minute, int& second) {
    hour = total_second / 3600;
    minute = (total_second % 3600) / 60;
    second = total_second % 60;
}

void get_next_time(int& hour, int& minute, int& second,
                   int dhour, int dminute, int dsecond) {
    long long total = (long long)convert_time_to_second(hour, minute, second)
                    + (long long)dhour * 3600 + (long long)dminute * 60 + dsecond;
    total = normalize_day(total);
    convert_second_to_time((int)total, hour, minute, second);
}

void get_previous_time(int& hour, int& minute, int& second,
                       int dhour, int dminute, int dsecond) {
    long long total = (long long)convert_time_to_second(hour, minute, second)
                    - (long long)dhour * 3600 - (long long)dminute * 60 - dsecond;
    total = normalize_day(total);
    convert_second_to_time((int)total, hour, minute, second);
}

void get_segment_time(int phour, int pminute, int psecond,
                      int nhour, int nminute, int nsecond,
                      int& dhour, int& dminute, int& dsecond) {
    long long p = convert_time_to_second(phour, pminute, psecond);
    long long n = convert_time_to_second(nhour, nminute, nsecond);
    long long diff = n - p;
    if (diff < 0) diff += SECONDS_PER_DAY;   // đã qua 00:00:00 ngày kế tiếp
    convert_second_to_time((int)diff, dhour, dminute, dsecond);
}

string convert_24_to_12(int hour, int minute, int second) {
    string period = (hour >= 12) ? "PM" : "AM";
    int h = hour % 12;
    if (h == 0) h = 12;

    ostringstream oss;
    oss << h << ":"
        << setw(2) << setfill('0') << minute << ":"
        << setw(2) << setfill('0') << second << " "
        << period;
    return oss.str();
}