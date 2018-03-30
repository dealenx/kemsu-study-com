#include "Server.h"

using namespace std;

// Клиент
int main() {
    IUnknown__ * PI = static_cast<IY*>(new CA);
    IY * PY;

    int res = PI -> QueryInterface__(1,  (void **)&PY);
    if(res !=0) {
        cout << "ERROR 1" << endl;
        system("pause");
        return 0;
    }
    PY->Fy1();
    delete PI;
    system("pause");
    return 0;
}
