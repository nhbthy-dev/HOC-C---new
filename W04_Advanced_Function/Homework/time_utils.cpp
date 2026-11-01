#include "time_utils.h"
#include <string>
using namespace std;

bool is_valid_time(int hour, int minute, int second) {
    if (hour < 0 || hour > 23) return false;
    if (minute < 0 || minute >= 60) return false;
    if (second < 0 || second >= 60) return false;
    return true;
}

int convert_time_to_second(int hour, int minute, int second) {
    return hour * 3600 + minute * 60 + second;
}

void convert_second_to_time(int total_second, int& hour, int& minute, int& second) {
    hour = total_second / 3600;
    minute = (total_second % 3600) / 60;
    second = total_second % 60;
}

void get_next_time(int& hour, int& minute, int& second,
                   int dhour, int dminute, int dsecond) {
    int total = convert_time_to_second(hour, minute, second)
              + convert_time_to_second(dhour, dminute, dsecond);
    total %= 86400;
    convert_second_to_time(total, hour, minute, second);
}

void get_previous_time(int& hour, int& minute, int& second,
                       int dhour, int dminute, int dsecond) {
    int total = convert_time_to_second(hour, minute, second)
              - convert_time_to_second(dhour, dminute, dsecond);
    total = ((total % 86400) + 86400) % 86400;
    convert_second_to_time(total, hour, minute, second);
}

void get_segment_time(int phour, int pminute, int psecond,
                      int nhour, int nminute, int nsecond,
                      int& dhour, int& dminute, int& dsecond) {
    int total = convert_time_to_second(nhour, nminute, nsecond)
              - convert_time_to_second(phour, pminute, psecond);
    if (total < 0) total += 86400;
    convert_second_to_time(total, dhour, dminute, dsecond);
}

string convert_24_to_12(int hour, int minute, int second) {
    string kihieu = (hour >= 12) ? "PM" : "AM";
    hour = hour % 12;
    if (hour == 0) hour = 12;

    string res = "";
    res += to_string(hour);
    res += ":";
    if (minute < 10) res += "0";
    res += to_string(minute);
    res += ":";
    if (second < 10) res += "0";
    res += to_string(second);
    res += " " + kihieu;
    return res;
}