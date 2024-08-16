// C++ program to demonstrate structure sorting in C++
#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
    string name; // Given
    int age;
};

bool comparePerson(Person p1, Person P2){
  return (p1.age > p2.age);
}

int main()
{
  const int N = 4;
  Person a[N];

  a[0].name = "vik";  a[0].age = 21;
  a[1].name = "eli";  a[1].age = 3;
  a[2].name = "hel";  a[2].age = 35;
  a[3].name = "mom";  a[3].age = 60;

  sort(a, a+N, comparePerson);

  for(int i =0; i < N; ++i){
    cout << a[i].name << " ";
    cout << a[i].age << endl;
  }

}


















