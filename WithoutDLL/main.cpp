#include "Server.h"

using namespace std;

// Клиент
int main() {
    //const CLSID clsid = 1;
    //const IID_CF = 2;

    IX * PX = NULL;
     int res= CreateInstance__(0,  (void **)&PX);
    
    if(res !=0) {
        cout << "ERROR 1" << endl;
        system("pause");
        return 0;
    }
    
    PX->Fx1();

    system("pause");
    return 0;
}
