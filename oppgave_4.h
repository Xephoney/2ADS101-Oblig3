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
    };

    // Dijkstra's //

    struct Veg{

        Node* m_start;
        float m_prioritetsVekt;
        bool rekkerSlutt;
        Veg(Node* start, float prioritetsVekt): m_start(start), m_prioritetsVekt(prioritetsVekt),
            rekkerSlutt(true){ }
        std::list<Node*> Noder;

    };

    Veg DijkstraAlgo(Graf graf, char startNavn, char sluttNavn);
};

#endif // OPPGAVE_4_H
