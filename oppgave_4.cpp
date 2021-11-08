#include "oppgave_4.h"

Oppgave_4::Oppgave_4()
{

}

void Oppgave_4::Aktiver()
{
    cout<<"oppg 4: "<<endl;
    Graf oppg4Graf;
    oppg4Graf.settinn_node('A');
    oppg4Graf.settinn_node('B');
    oppg4Graf.settinn_node('C');
    oppg4Graf.settinn_node('D');
    oppg4Graf.settinn_node('E');

    oppg4Graf.settinn_kant('A','B',1.0);
    oppg4Graf.settinn_kant('A','C',2.0);
    oppg4Graf.settinn_kant('B','C',2.0);
    oppg4Graf.settinn_kant('C','D',3.0);
    oppg4Graf.settinn_kant('D','E',1.0);
    oppg4Graf.settinn_kant('A','E',5.0);
    oppg4Graf.settinn_kant('C','E',4.0);

    Veg veg = oppg4Graf.DijkstraAlgo('A', 'E');

    std::cout << "Veien fra A til E gå slik:\n";
    for(Kant k : veg.m_kanter)
    {
        std::cout << k.m_tilnode->m_navn << "";
    }
    std::cout << "\n Vekt = " << veg.m_vekt << std::endl;
}

Oppgave_4::Veg Oppgave_4::Graf::DijkstraAlgo(char startNavn, char sluttNavn)
{
    std::priority_queue<Veg, std::vector<Veg>, std::greater<Veg>> pq;

    Node* startNode = finn_node(startNavn);
    Node* sluttNode = finn_node(sluttNavn);
    Veg startVeg;
    Kant startKant (0,startNode);
    startVeg.settInn_Kant(startKant);

    pq.push(startVeg);

    while(!pq.empty() && !sluttNode->m_besokt)
    {
        Veg top = pq.top();
        pq.pop();

        if(top.m_kanter.back().m_tilnode == sluttNode)
            return top;
        for(auto kant : top.m_kanter.back().m_tilnode ->m_kanter)
        {
            if(kant.m_tilnode->m_besokt != true)
            {
                Veg nyVeg = top;
                nyVeg.settInn_Kant(kant);
                pq.push(nyVeg);
            }
        }
        top.m_kanter.back().m_tilnode->m_besokt = true;

    }
    return pq.top();
}

void Oppgave_4::Node::settinn_kant(const Kant &kant)
{
    Node::m_kanter.push_back(kant);
}

Oppgave_4::Node *Oppgave_4::Graf::finn_node(char navn)
{
    for(Node* n : noder){
        if(n->m_navn==navn)
            return n;
    }
    return nullptr;
}

void Oppgave_4::Graf::settinn_node(char navn)
{
    Node* nyNode= new Node(navn);
    Graf::noder.emplace_back(nyNode);
}

void Oppgave_4::Graf::settinn_kant(char fra_navn, char til_navn, float vekt)
{
    for(Node* n : noder){
        if(n->m_navn==fra_navn){
            for (Node* m : noder){
                if(m->m_navn==til_navn){
                    Kant nyKant(vekt,m);
                    n->m_kanter.emplace_back(nyKant);
                }
            }
        }
    }
}
