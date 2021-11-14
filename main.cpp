#include "Graphics.hpp"

#include "GameCharacter.h"
#include "Inventory.h"

class Animation{
public:
    Animation() = default; //TODO check meaning
    Animation(int x, int y, int width, int height){
        texture.loadFromFile();//TODO add sprite
        for (int i = 0; i < nFrames; i++){
            frames[i] = {x+i*width, y, width, height};//TODO what is rectleft? i think is the image swap
        }
    }
    void applyToSprite(sf::Sprite& s) const{
        s.setTexture(texture);
        s.setTextureRect(frames[iFrame]);
    }
    void update(float dt){
        time += dt;
        while(time >= holdTime){
            time -= holdTime;
            advance();
        }
    }
private:
    void advance(){
        if (++iFrame >= nFrames)//TODO check meaning
            iFrame = 0;
    }
    static constexpr int nFrames = 5;//TODO what is constexpr?
    static constexpr float holdTime = 0.1f;// f: defined as float
    sf::Texture texture;
    sf::IntRect frames[nFrames];//TODO what is IntRect?
    int iFrame = 0;
    float time = 0.0f;
};

int main(){
    //textPool
    std::string elizabethPool[] = {"Bene bene, abbiamo un nuovo ospite. Da quale lontana era provieni?",//Elizabeth
                            "Ci sono molte cose che vorrei chiederti, ma so che non devo.",
                            "Ahh, capisco. Non sai cosa sia successo...",
                            "Vedrai più avanti. Un antica bestia è stata risvegliata "
                            "e ha generato l’Abisso, minacciando di corrompere tutta Oolacile.",
                            "Il cavaliere Artorias è venuto per fermare tutto questo, "
                            "ma un tale eroe non è abbastanza coraggioso da affrontare tale potere.",
                            "Senza dubbio è stato sconfitto, travolto dall’oscurità, "
                            "ma spero ancora che la Principessa Dusk venga salvata.",
                            "Non molto tempo fa, ho avuto un altro visitatore, un essere umano come te, "
                            "da un tempo lontano.",
                            "Solo che era terribilmente odioso… e tempo che sia ancora tra noi.",
                            "Indossava un cappello e un lungo cappotto nero…",
                            "Che le fiamme possano guidarti.",
                            "Ti ringrazio per aver salvato la principessa Dusk, te ne sarò debitrice e "
                            "ti ricorderò per sempre.",
                            "Ma terrò per me la tua storia perché una leggenda rimarrà sempre una leggenda…",
                            };
    std::string sifPool = {"(Ulula)"};//sif
    std::string chesterPool[] = {"Oh… Fammi indovinare",//chester
                            "Sei stato catapultato nel passato di un’era differente?",
                            "Come avevo sospettato. È successo anche a me: siamo entrambi degli estranea "
                            "in una terra sconosciuta.",
                            "Ma almeno adesso, siamo in due.",
                            "Beh… Errore mio.",
                            "Ma siamo entrambi avventurieri e, per questo, dobbiamo aiutarci a vicenda.",
                            "Ti è capitato di incontrare Artorias? Il leggendario camminatore degli Abissi, "
                            "secondo gli antichi racconti.",
                            "Se ancora non è successo, meglio così. Se me lo stai chiedendo, sì, è ormai corrotto.",
                            "Ahahah ah ahah !",
                            "Allora, cosa ti ha fare quel fungo gigante? Non che mi interessi. "
                            "Non fa parte del mio business.",
                            "Eheheheh  eheh…",
                            "Hm? Non ho molto da dire…",
                            "Hai veramente ucciso Artorias?",
                            "Ho sentito dire che l’Abisso lo ha trasformato in qualcosa di veramente pericoloso.",
                            "È assolutamente insidioso.",
                            "Ahahahahaha ahha!",
                            "Che tu ci creda o no, Oolacile ha portato l’Abisso con se.",
                            "Ti sei mai chiesto: Vale veramente la pena?",
                            "Eheheheh eheh eh…"};
    std::string duskPool[] = {"...Mmn...ahh…",//Princess Dusk
                            "…Aah...mmn…",
                            "Salve avventuriero. Anche tu da queste parti, non è vero? Da quale era provieni?",
                            "Sai… può sembrare strano, ma…",
                            "Sono stata assalita da una creatura dell’Abisso e ci sarei "
                            "morta se non fosse stato per il Grande Cavaliere Artorias.",
                            "In realtà, ho visto poco di quanto è accaduto durante lo scontro. Ero stordita.",
                            "Nonostante ciò, Artorias emanava un’aura particolare… In lui traspirava "
                            "un equilibrio interiore…",
                            "Che ritrovo tale e quale in te.",
                            "..."};
    std::string artoriasPool[]={"Chiunque tu sia, stai lontano!",//Artorias
                            "Presto... Sarò consumato... da loro, dall'Oscurità",
                            "REEEUUUUGHHHHHHHH!", //deve essere ripetuta anche dopo "ti prego, la..."
                            "Ti prego, la propagazione dell'Abisso... deve essere fermata"};
    std::string manusString={
                            "Restituiscimi ciò che mi appartiene!"//Manus
                            };

    //create window
    sf::RenderWindow window {sf::VideoMode(800, 600), "Map"};
    sf::Texture t;
    sf::Sprite st(t);

    //creating GameCharacter
    GameCharacter hero(100, 20, 0, 1, elizabethPool[0]);//...
}