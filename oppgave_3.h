#ifndef OPPGAVE_3_H
#define OPPGAVE_3_H
#include <string>
#include <unordered_set>

using namespace std;

struct Test
{
    int key;
    std::string s;
    bool operator == (const Test& t2) const { return key == t2.key; }
};
namespace std
{
    template<>
    class hash<Test> {
    public:
        size_t operator() (const Test& t) const {
            return t.key % 7;
        }
        bool operator() (const Test& t1, const Test& t2) {
            return t1.key == t2.key;
        }
    };
};

void obg3_unordered_set();

class Oppgave_3
{
public:
    Oppgave_3();
    void Aktiver();
};

#endif // OPPGAVE_3_H
