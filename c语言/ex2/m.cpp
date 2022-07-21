#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;


int main() {
    string code;

    cout << "Please entre the secret key :" << endl;
    std::cin >> code;
    cout << code << endl;
    if (code != "42") {
        cout << "code is not good!" << endl;
        return 84;
    }
    string res("abcdefghijklmnopqrstuvwxyz\nzyxwvutsrqponmlkjihgfedcba\n"
    "0123456789\nP\nP\nN\n012, 013, 014, 015, 016, 017, 018, 019, 023, 024,"
    " 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048,"
    " 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126,"
    " 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156,"
    " 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239,"
    " 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289,"
    " 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389,"
    " 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579,"
    " 589, 678, 679, 689, 789\n0\n123520\n-10");
    ifstream afile;

    afile.open("./res.txt");
    if (afile.fail()) {
        cout << "test fail, res is not created" << endl;
        afile.close();
        return 84;
    } 
    string myres((istreambuf_iterator<char>(afile)), istreambuf_iterator<char>());


    std::vector<std::string> tokens, tokens_my;
    std::string token, my_token;
    std::stringstream ss(res);
    std::stringstream my_ss(myres);
    while (getline(ss, token, '\n')){
        tokens.push_back(token);
    }
    while (getline(my_ss, my_token, '\n')){
        tokens_my.push_back(my_token);
    }
    for (int i = 0; i <= 9; ++i) {
        if (tokens[i] != tokens_my[i]) {
            if (i == 0)
                cout << "my_print_alpha fail!" << endl;
            if (i == 1)
                cout << "my_print_revalpha fail!" << endl;
            if (i == 2)
                cout << "my_print_digits fail!" << endl;
            if (i == 3 || i == 4 || i == 5)
                cout << "my_isneg fail!" << endl;
            if (i == 6)
                cout << "my_print_comb fail!" << endl;
            if (i == 7 || i == 8 || i == 9)
                cout << "my_put_nbr fail!" << endl;
        }
    }

    if (myres == res) {
        cout << "Congratulations!\nhidden code is 'WSZGSWGNOIZYHWUSGWAA'" << endl;
        return 0;
    }
    cout << "test fail!" << endl;
    return 0;
}