#include <SFML/Graphics.hpp>
#include <chrono>

#include "GameCharacter.h"//inventory included in here
#include "HUD.h"

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
    sf::RenderWindow window {sf::VideoMode(1152, 673), "Map"};
    sf::Texture t;
    sf::Sprite s(t);

    GameCharacter test(100, 20, 0, 100.0f, {150.0f,3.0f});
    //Inventory inventory(false);
    HUD hud(false, true, 0);
    //GameCharacter test1(100, 20, 0, 100.0f, {400.f,3.0f});//TODO remove

    //timepoint for delta time measurement
    auto tp = std::chrono::steady_clock::now();

    
    /*if(!texture.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/0x72_DungeonTilesetII_v1.4.png"))
        return EXIT_FAILURE;*/
   
    /*//creating GameCharacter//TODO remove
    sf::Texture texture1;
    if(!texture1.loadFromFile("/home/andrea/Documents/Exam_project/code/Artorias-of-the-abyss/0x72_DungeonTilesetII_v1.4.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite1(texture1);
    sprite1.setTextureRect({127, 75, 16, 28});//    128, 75, 17, 28*/


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

        //handle input
        test.movement(hud.getInvIsOpen());
        hud.openCloseInv();
        /*test1.animation(128, 75, 16, 28, false, true);
        if (test.isChasing(100, test1))
            std::cout<<"Success!"<<std::endl;*/

        //update model
        test.update(dt);
        //test1.update(dt);//TODO remove

        //clear screen
        window.clear();

        //draw background
        window.draw(s);

        //draw the sprite
        test.draw(window);
        if (hud.getInvIsOpen()){
            hud.drawInventory(window);
        }
        hud.draw(window); 
        hud.displayHealth(test, window);   
        //test1.draw(window);//TODO remove

        //update the window
        window.display();
    }
    return EXIT_SUCCESS;
}