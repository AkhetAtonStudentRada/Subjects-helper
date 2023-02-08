  #include <iostream>
  using namespace std;

  int main(int argc, char* argv[])
{
      setlocale(LC_ALL, "UKRAINIAN");
      float l;
      cout << "Уведiть довжину в дюймах:" << endl;
      cin >> l;
      if (l >= 0)
          cout << "Довжина в мiлiметрах: " << l * 25.4 << endl;
      else
          cout << "error l<0" << endl;
      return 0;

}