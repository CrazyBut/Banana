#include <iostream>
#include <vector>

using namespace std;

// Иерархия мемов
class Meme {
public:
    virtual string info() = 0;

    virtual ~Meme() {
    }
};

class LegendaryMeme : public Meme {
public:
    string info() {
        return "LegendaryMeme";
    };
};

class AnimeMeme : public Meme {
public:
    string info() {
        return "AnimeMeme";
    };
};

class HahaMeme : public Meme {
public:
    string info() {
        return "HahaMeme";
    };
};

class PolitMeme : public Meme {
public:
    string info() {
        return "PolitMeme";
    };
};


// Фабрики объектов
class Factory {
public:
    virtual Meme *createMeme() = 0;

    virtual ~Factory() {}
};

class LegendaryFactory : public Factory {
public:
    Meme *createMeme() {
        return new LegendaryMeme;
    }
};

class AnimeFactory : public Factory {
public:
    Meme *createMeme() {
        return new AnimeMeme;
    }
};

class HahaFactory : public Factory {
public:
    Meme *createMeme() {
        return new HahaMeme;
    }
};

class PolitFactory : public Factory {
public:
    Meme *createMeme() {
        return new PolitMeme;
    }
};

class Human {
    string name;
    bool isLovingLegendary;
    bool isLovingAnime;
    bool isLovingHaha;
    bool isLovingPolit;
public:
    Human(){
        isLovingLegendary = false;
        isLovingAnime = false;
        isLovingHaha = false;
        isLovingPolit = false;
        name = "";
    }
    void setLovingAnime(bool a){
        isLovingAnime = a;
    }
    void setLovingHaha(bool b){
        isLovingHaha = b;
    }
    void setLovingPolit(bool c){
        isLovingPolit = c;
    }
    Human(bool a, bool b, bool c, string n) {
        isLovingAnime = a;
        isLovingHaha = b;
        isLovingPolit = c;
        isLovingLegendary = true;
        name = n;
    }

    string getname(){
        return name;
    }
    void setName(string NM){
        name = NM;
    }


    void review(Meme &m) {
        cout << m.info() << ": ";
        if (m.info() == "LegendaryMeme") {
            cout << " amazing";
        }

        if (m.info() == "AnimeMeme") {
            if (isLovingAnime) {
                cout << " amazing";
            } else {
                cout << "Nein";
            }
        }

        if (m.info() == "HahaMeme") {
            if (isLovingHaha) {
                cout << " amazing";
            } else {
                cout << "Nein";
            }
        }

        if (m.info() == "PolitMeme") {
            if (isLovingPolit) {
                cout << " amazing";
            } else {
                cout << "Nein";
            }
        }

        cout << endl;
    }
};


class HumanBuilder
{
protected:
    Human* p;
public:

//    HumanBuilder(): p(NULL) {}

    HumanBuilder() {
        p = new Human;
    }
    void setLovingAnime(bool a){
        p->setLovingAnime(a);
    }
    void setLovingHaha(bool b){
        p->setLovingHaha(b);
    }
    void setLovingPolit(bool c){
        p->setLovingPolit(c);
    }
    void setName (string name){
        p->setName(name);
    }
     ~HumanBuilder() {}

     void reset() { delete(p);
    p = new Human;
    }
     Human* createHuman() { return p; }

   // void reset() { p = new Human;} // метод создания 0 человека
};

int main() {
//    Human human1(true, false, false, "AnimeBoy");
//    Human human2(true, true, false, "FanBoy");
//    Human human3(false, true, false, "AverageMan");
//    Human human4(false, false, true, "Marginal");
//    Human human5(false, false, false, "Hater");

    HumanBuilder humanBuilder;

//    humanBuilder.reset();
    humanBuilder.setLovingAnime(true);
    humanBuilder.setLovingHaha(false);
    humanBuilder.setLovingPolit(false);
    humanBuilder.setName("AnimeBoy");

    Human* human1 = humanBuilder.createHuman();

    humanBuilder.reset();

//    humanBuilder.reset();
    humanBuilder.setLovingAnime(true);
    humanBuilder.setLovingHaha(true);
    humanBuilder.setLovingPolit(false);
    humanBuilder.setName("FanBoy");

    Human* human2 = humanBuilder.createHuman();

//    humanBuilder.reset();
    humanBuilder.setLovingAnime(false);
    humanBuilder.setLovingHaha(true);
    humanBuilder.setLovingPolit(false);
    humanBuilder.setName("AverageBoy");

    Human* human3 = humanBuilder.createHuman();

//    humanBuilder.reset();
    humanBuilder.setLovingAnime(false);
    humanBuilder.setLovingHaha(false);
    humanBuilder.setLovingPolit(true);
    humanBuilder.setName("Marginal");

    Human* human4 = humanBuilder.createHuman();

//    humanBuilder.reset();
    humanBuilder.setLovingAnime(false);
    humanBuilder.setLovingHaha(false);
    humanBuilder.setLovingPolit(false);
    humanBuilder.setName("Hater");

    Human* human5 = humanBuilder.createHuman();

    LegendaryFactory *legendary_factory = new LegendaryFactory;
    AnimeFactory *anime_factory = new AnimeFactory;
    HahaFactory *haha_factory = new HahaFactory;
    PolitFactory *polit_factory = new PolitFactory;

    vector<Meme *> m;
    m.push_back(legendary_factory->createMeme());
    m.push_back(anime_factory->createMeme());
    m.push_back(haha_factory->createMeme());
    m.push_back(polit_factory->createMeme());

    vector<Human> h;
    h.push_back(*human1);
    h.push_back(*human2);
    h.push_back(*human3);
    h.push_back(*human4);
    h.push_back(*human5);

    for (Human x : h) {
        cout << x.getname() << endl;
        for (Meme *y : m) {
            x.review(*y);
        }
        cout << endl;
    }
}