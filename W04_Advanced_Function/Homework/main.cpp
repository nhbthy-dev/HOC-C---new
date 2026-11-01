#include <iostream>
#include "time_utils.h"
using namespace std;

int main() {
    int h, m, s, dh, dm, ds;

    // Test 1: is_valid_time
    cin >> h >> m >> s;
    cout << (is_valid_time(h, m, s) ? "True" : "False") << endl;

    // Test 2: get_next_time
    cin >> h >> m >> s >> dh >> dm >> ds;
    get_next_time(h, m, s, dh, dm, ds);
    cout << h << " " << m << " " << s << endl;

    // Test 3: get_previous_time
    cin >> h >> m >> s >> dh >> dm >> ds;
    get_previous_time(h, m, s, dh, dm, ds);
    cout << h << " " << m << " " << s << endl;

    // Test 4: get_segment_time
    int ph, pm, ps, nh, nm, ns;
    cin >> ph >> pm >> ps >> nh >> nm >> ns;
    get_segment_time(ph, pm, ps, nh, nm, ns, dh, dm, ds);
    cout << dh << " " << dm << " " << ds << endl;

    // Test 5: convert_24_to_12
    cin >> h >> m >> s;
    cout << convert_24_to_12(h, m, s) << endl;

    // Test 6: convert_time_to_second
    cin >> h >> m >> s;
    cout << convert_time_to_second(h, m, s) << endl;

    // Test 7: convert_second_to_time
    int total;
    cin >> total;
    convert_second_to_time(total, h, m, s);
    cout << h << " " << m << " " << s << endl;

    return 0;
}