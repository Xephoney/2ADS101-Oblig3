#ifndef OPPGAVE_4_H
#define OPPGAVE_4_H
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Oppgave_4
{
public:
    Oppgave_4();
    void Aktiver();

    struct Kant;
    struct Veg;
    struct Node{
        char m_navn;
        bool m_besokt;
        std::list<Kant> m_kanter;
        Node(char navn) : m_navn(navn), m_besokt(false) { }
        void settinn_kant(const Kant &kant);
    };

    struct Kant {
        float m_vekt;
        Node* m_tilnode;
        Kant(float vekt, Node* tilnode) : m_vekt(vekt), m_tilnode(tilnode){ }
        bool operator > (const Kant& k) const {return m_vekt > k.m_vekt;}
    };

    struct Graf{
        std::list<Node*> noder;
        Graf() {}
        Node* finn_node(char navn);
        void settinn_node(char navn);
        void settinn_kant(char fra_navn, char til_navn, float vekt);
        float mst();
        Veg DijkstraAlgo(char startNavn, char sluttNavn);
    };

    // Dijkstra's //

    struct Veg{

        std::vector<Kant> m_kanter;
        float m_vekt{0.f};
        void settInn_Kant(Kant &_kant)
        {
            m_kanter.push_back(_kant);
            m_vekt+=_kant.m_vekt;
        }

        Veg(){ }

        bool operator>(const Veg &v) const { return m_vekt > v.m_vekt; }
    };
};

#endif // OPPGAVE_4_H
