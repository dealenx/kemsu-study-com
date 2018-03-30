#include "Server.h"

using namespace std;


// Клиент
int main() {
    CA* pA = new CA;
    // Получить указатель IX
    IX* pIX = pA;

    pIX->Fx1();
    pIX->Fx2();
    // Получить указатель IY
    IY* pIY = pA;
    
    pIY->Fy1();
    pIY->Fy2();
    
    delete pA;
    system("pause");
    return 0;
}
