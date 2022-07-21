#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream afile;

    afile.open("./test1/res1");
    if (afile.fail()) {
        cout << "test1 fail, res1 is not created" << endl;
        return 84;
    }
    afile.seekg(0, ios_base::end);
    int nFileLen = afile.tellg();
    if (nFileLen == 0) {
        cout << "test2 fail, res1 is a empty file" << endl;
        return 84;
    }
    afile.close();
    afile.open("./test3");
    if (afile.is_open()) {
        cout << "test5 fail, test3 file is not deleted" << endl;
        return 84;
    }
    cout << "Congratulations!\nhidden code is '42'" << endl;
    return 0;
}