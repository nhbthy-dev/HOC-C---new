#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <string>

using std::string;

bool is_valid_time(int hour, int minute, int second);

void get_next_time(int& hour, int& minute, int& second,
                   int dhour, int dminute, int dsecond);

void get_previous_time(int& hour, int& minute, int& second,
                       int dhour, int dminute, int dsecond);

void get_segment_time(int phour, int pminute, int psecond,
                      int nhour, int nminute, int nsecond,
                      int& dhour, int& dminute, int& dsecond);

string convert_24_to_12(int hour, int minute, int second);

int convert_time_to_second(int hour, int minute, int second);

void convert_second_to_time(int total_second,
                            int& hour, int& minute, int& second);

#endif