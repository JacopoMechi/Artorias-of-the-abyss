#include <SFML/Graphics.hpp>
#include <chrono>

#include "GameCharacter.h"
#include "Inventory.h"

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
    sf::Sprite s(t);

    GameCharacter test(100, 20, 0, 1, {150.f,3.0f});

    //timepoint for delta time measurement
    auto tp = std::chrono::steady_clock::now();


    //creating GameCharacter
    sf::Texture texture;
    if(!texture.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/0x72_DungeonTilesetII_v1.4.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setTextureRect({127, 75, 16, 26});//    128, 75, 17, 28


    
    //starting the game loop
    while (window.isOpen()){
        //process event
        sf::Event event;
        while(window.pollEvent(event)){
            //close window
            if (event.type == sf::Event::Closed)
            window.close();
        }

        //get dt
        float dt;
        {
            const auto new_tp = std::chrono::steady_clock::now();
            dt = std::chrono::duration<float>(new_tp - tp).count();
            tp = new_tp;
        }

        //handel input
        sf::Vector2f dir = {0.0f, 0.0f};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){//TODO add in movements of gamecharacter
            dir.y -= 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            dir.y += 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            dir.x -= 1.0f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            dir.x += 1.0f;
        }
        test.setDirection(dir);

        //update model
        test.update(dt);

        //clear screen
        window.clear();

        //draw background
        window.draw(s);

        //draw the sprite
        test.draw(window);

        //update the window
        window.display();
    }
    return EXIT_SUCCESS;
}