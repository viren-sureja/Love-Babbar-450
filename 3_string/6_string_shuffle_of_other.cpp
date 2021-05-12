/*
    link: https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
*/


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Check if a string is a valid shuffle of two other strings:
    for eg. 1XY2 is a valid shuffle of XY and 12, Y12X is not a valid shuffle of XY and 12
    as in y12x the order of string is changed.

*/

void check_shuffle_of_2_string() {
    string a = "xy", b = "12";
    /*
        if    string s2 = "1xy2"; it is valid as it has maintained order of both string
        if    string s2 = "2xy1" is invalid here "xy" is maintained but not "12"
        if    string s2 = "y1x2" is invalid here "12" is maintained but not "xy"
    */
    string s2 = "y12x";
    int i = 0;
    int j = 0;
    for (auto& x : s2) {
        if (i < a.size() && x == a[i]) {
            i++;
        }
        else if (j < b.size() && x == b[j]) {
            j++;
        }
    }
    if (s2.size() == i + j && i == a.size() && j == b.size()) cout << "yes" << endl;
    else cout << "no" << endl;
}