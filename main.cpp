#include <iostream>
#include <vector>

using namespace std;

// Иерархия мемов
class Meme
{
public:
    virtual string info() = 0;
    virtual ~Meme() {
    }
};

class LegendaryMeme: public Meme
{
public:
    string info() {
        return  "LegendaryMeme" ;
    };
};

class AnimeMeme: public Meme
{
public:
    string info() {
        return  "AnimeMeme" ;
    };
};

class HahaMeme: public Meme
{
public:
    string info() {
        return  "HahaMeme" ;
    };
};

class PolitMeme: public Meme
{
public:
    string info() {
        return "PolitMeme" ;
    };
};


// Фабрики объектов
class Factory
{
public:
    virtual Meme* createMeme() = 0;
    virtual ~Factory() {}
};

class LegendaryFactory: public Factory
{
public:
    Meme* createMeme() {
        return new LegendaryMeme;
    }
};

class AnimeFactory: public Factory
{
public:
    Meme* createMeme() {
        return new AnimeMeme;
    }
};

class HahaFactory: public Factory
{
public:
    Meme* createMeme() {
        return new HahaMeme;
    }
};

class PolitFactory: public Factory
{
public:
    Meme* createMeme() {
        return new PolitMeme;
    }
};

class Human
{
    string name;
    bool isLovingLegendary;
    bool isLovingAnime;
    bool isLovingHaha;
    bool isLovingPolit;
public:
    Human(bool a, bool b, bool c, string n){
        isLovingAnime = a;
        isLovingHaha = b;
        isLovingPolit = c;
        isLovingLegendary = true;
        name = n;
    }

    string getname(){
        return name;
    }

    void review (Meme & m){
        cout<<m.info() << ": " ;
        if(m.info()=="LegendaryMeme"){
            cout<<"perfect";
        }

        if(m.info()=="AnimeMeme"){
            if (isLovingAnime) {
                cout << " perfect";
            } else{
                cout<<"worse";
            }
        }

        if(m.info()=="HahaMeme"){
            if (isLovingHaha) {
                cout << " perfect";
            } else{
                cout<<"worse";
            }
        }

        if(m.info()=="PolitMeme"){
            if (isLovingPolit) {
                cout << " perfect";
            } else{
                cout<<"worse";
            }
        }

        cout << endl;
    }
};


int main() {
    Human human1(true, false, false, "AnimeBoy");
    Human human2(true, true, false, "FanBoy");
    Human human3(false, true, false, "AverageMan");
    Human human4(false, false, true, "Marginal");
    Human human5(false, false, false, "Hater");

    LegendaryFactory *legendary_factory = new LegendaryFactory;
    AnimeFactory *anime_factory = new AnimeFactory;
    HahaFactory *haha_factory = new HahaFactory;
    PolitFactory *polit_factory = new PolitFactory;

    vector<Meme*> m;
    m.push_back(legendary_factory->createMeme());
    m.push_back(anime_factory->createMeme());
    m.push_back(haha_factory->createMeme());
    m.push_back(polit_factory->createMeme());

    vector<Human> h;
    h.push_back(human1);
    h.push_back(human2);
    h.push_back(human3);
    h.push_back(human4);
    h.push_back(human5);

    for (Human x : h) {
        cout << x.getname() << endl;
        for (Meme  *y : m) {
        x.review(*y);
        }
        cout << endl;
    }
}

