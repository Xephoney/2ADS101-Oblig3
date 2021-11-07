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

    // kontroll testing //
    for(Node* n : oppg4Graf.noder){
        cout<<n->m_navn<<" kanter: "<<endl;
        for (Kant k :n->m_kanter)
            cout<<n->m_navn<<k.m_tilnode->m_navn<<" med vekt = "<<k.m_vekt<<endl;

    }
    // får ikke Dijkstras algoritme til å funke
    //cout<<endl<<"dijkstra test";
    //Veg FerdigVeg=DijkstraAlgo(oppg4Graf,'A','D');

    //for(Node* n : FerdigVeg.Noder)
      //  cout<<n->m_navn;
}

//Oppgave_4::Veg Oppgave_4::DijkstraAlgo(Graf graf, char startNavn, char sluttNavn)
//{
//    Node* start;
//    Node* slutt;
//    for(Node* n:graf.noder){
//        if(n->m_navn==startNavn)
//          start=n;
//        if(n->m_navn==sluttNavn)
//            slutt=n;

//    }

//    list<Veg> Veger;
//    list<Veg> FerdigeVeger;
//    for (Kant k : start->m_kanter)
//        Veger.emplace_back(new Veg(start,k.m_vekt));

//    for(Veg v: Veger){
//            if(v.rekkerSlutt){
//                for(Node* n: v.Noder){
//                    if(n->m_kanter.size()<1&&n->m_navn!=slutt->m_navn){
//                        v.rekkerSlutt=false;
//                    }
//                    else if(n->m_navn==slutt->m_navn){
//                        FerdigeVeger.emplace_back(v);
//                    }
//                    else
//                        for(Kant k : n->m_kanter){
//                           Veger.emplace_back(new Veg(start,v.m_prioritetsVekt+k.m_vekt));
//                        }
//                }
//            }
//        }

//        for(Veg v : FerdigeVeger){
//            for(Veg f :FerdigeVeger){
//                if(f.Noder!=v.Noder&&f.m_prioritetsVekt<v.m_prioritetsVekt){
//                    Veg TempVeg=f;
//                    f=v;
//                    v=TempVeg;
//                }
//            }
//        }

//        return FerdigeVeger.front();

//}

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
