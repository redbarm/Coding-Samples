#include "main.h"

int main()
{
    sector s1("sector1", 10, 20), s2("sector2", 15, 25), s3("sector3", 25, 35);
    cout << s1.getName() << "\n";
    cout << s1.getLength() << "\n";
    cout << s1.getWidth() << "\n";
    cout << s1.area() << "\n";

    cout << s2.getName() << "\n";
    cout << s2.getLength() << "\n";
    cout << s2.getWidth() << "\n";
    cout << s2.area() << "\n";

    cout << s3.getName() << "\n";
    cout << s3.getLength() << "\n";
    cout << s3.getWidth() << "\n";
    cout << s3.area() << "\n";

    return 0;
}
