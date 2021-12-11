#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include "Movie.h"
#include "EdgeList.h"
#include "AdjList.h"

using namespace std;

class MovieGraph {
public:
    int genre = 0;//1-8 representing action-thriller
    int type = 0;//1-3 representing doc-anim
    int rating = 0;//1-5 stars
    sf::Vector2i date;
    sf::Vector2i runtime;
    string getGenreString() {
        switch (genre) {
        case 1: {
            return "Action";
        }break;
        case 2: {
            return "Comedy";
        }break;
        case 3: {
            return "Drama";
        }break;
        case 4: {
            return "Fantasy";
        }break;
        case 5: {
            return "Horror";
        }break;
        case 6: {
            return "Mystery";
        }break;
        case 7: {
            return "Romance";
        }break;
        case 8: {
            return "Thriller";
        }break;
        }
        return "";
    }
    string getTypeString() {
        switch (genre) {
        case 1: {
            return "Documentary";
        }break;
        case 2: {
            return "Feature";
        }break;
        case 3: {
            return "Animation";
        }break;
        }
        return "";
    };

};

void newGraph(MovieGraph& graph, EdgeList& edge, AdjList& adj) {
    Movie add;
    ifstream data("data.txt");
    string line;
    if (data) {
        getline(data, line);//header
        while (getline(data, line)) {
            add = Movie(line);
            for (string& a : add.genre) {
                if (a.compare(graph.getGenreString()) == 0) {
                    for (string& b : add.type) {
                        if (b.compare(graph.getTypeString()) == 0) {
                            if (add.rating / 2.0f >= graph.rating) {
                                if (add.date >= graph.date.x && add.date <= graph.date.y) {
                                    if (add.runtime >= graph.runtime.x && add.runtime <= graph.runtime.y) {
                                        edge.insert(add);
                                        adj.insert(add);
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
    }
}


void print(sf::RenderWindow& window, int page) {//prints "quiz" pages
    sf::Texture back, go, UIT;
    sf::Sprite UIS;

    switch (page) {
    case 1: {
        go.loadFromFile("images/title.png");
    }break;

    case 2: {
        go.loadFromFile("images/genre.png");
    }break;

    case 3: {
        go.loadFromFile("images/genre_action.png");
    }break;

    case 4: {
        go.loadFromFile("images/genre_comedy.png");
    }break;

    case 5: {
        go.loadFromFile("images/genre_drama.png");
    }break;

    case 6: {
        go.loadFromFile("images/genre_fantasy.png");
    }break;

    case 7: {
        go.loadFromFile("images/genre_horror.png");
    }break;

    case 8: {
        go.loadFromFile("images/genre_mystery.png");
    }break;

    case 9: {
        go.loadFromFile("images/genre_romance.png");
    }break;

    case 10: {
        go.loadFromFile("images/genre_thriller.png");
    }break;

    case 11: {
        go.loadFromFile("images/type.png");
    }break;

    case 12: {
        go.loadFromFile("images/type_doc.png");
    }break;

    case 13: {
        go.loadFromFile("images/type_feature.png");
    }break;

    case 14: {
        go.loadFromFile("images/type_ani.png");
    }break;

    case 15: {
        go.loadFromFile("images/date.png");
    }break;

    case 16: {
        go.loadFromFile("images/runtime.png");
    }break;

    case 17: {
        go.loadFromFile("images/rating.png");
    }break;

    case 18: {
        go.loadFromFile("images/rating_one.png");
    }break;

    case 19: {
        go.loadFromFile("images/rating_two.png");
    }break;

    case 20: {
        go.loadFromFile("images/rating_three.png");
    }break;

    case 21: {
        go.loadFromFile("images/rating_four.png");
    }break;

    case 22: {
        go.loadFromFile("images/rating_five.png");
    }break;

    case 23: {
        go.loadFromFile("images/results.png");
    }break;

    }
    back.loadFromFile("images/back.png");//background fix (for slightly smaller images)
    window.clear();
    window.draw(sf::Sprite(back));
    window.draw(sf::Sprite(go));

    if (page < 23) {
        if (page > 1) {
            if (page > 10) {
                if (page > 16) {
                    UIT.loadFromFile("images/prev_done.png");
                }
                else {
                    UIT.loadFromFile("images/prev_next.png");
                }
            }
            else {
                UIT.loadFromFile("images/next.png");
            }
            UIS.setTexture(UIT);
            UIS.setPosition(sf::Vector2f(0, 650));
        }
        else {
            UIT.loadFromFile("images/start.png");
            UIS.setTexture(UIT);
            UIS.setPosition(sf::Vector2f(462, 475));
        }
        window.draw(UIS);
    }
}

void UI(sf::RenderWindow& window, tgui::Gui& gui, tgui::EditBox::Ptr& dMin, tgui::EditBox::Ptr& dMax, tgui::EditBox::Ptr& rMin, tgui::EditBox::Ptr& rMax) {
    tgui::Theme::setDefault("Black.txt");

    auto dateMin = tgui::EditBox::create();
    dateMin->setPosition(350, 300);
    dateMin->setSize(200, 30);
    dateMin->setVisible(false);
    dateMin->setDefaultText("YYYY");
    dateMin->setMaximumCharacters(4);
    dateMin->setInputValidator(tgui::EditBox::Validator::UInt);
    //dateMin->setInputValidator("[0-9]/");
    gui.add(dateMin, "DateMin");
    dMin = gui.get<tgui::EditBox>("DateMin");

    auto dateMax = tgui::EditBox::create();
    dateMax->setPosition(740, 300);
    dateMax->setSize(200, 30);
    dateMax->setVisible(false);
    dateMax->setDefaultText("YYYY");
    dateMax->setMaximumCharacters(4);
    dateMax->setInputValidator(tgui::EditBox::Validator::UInt);
    gui.add(dateMax, "DateMax");
    dMax = gui.get<tgui::EditBox>("DateMax");

    auto runtimeMin = tgui::EditBox::create();
    runtimeMin->setPosition(350, 280);
    runtimeMin->setSize(200, 30);
    runtimeMin->setVisible(false);
    runtimeMin->setDefaultText("time in minutes");
    runtimeMin->setMaximumCharacters(3);
    runtimeMin->setInputValidator(tgui::EditBox::Validator::UInt);
    gui.add(runtimeMin, "runtimeMin");
    rMin = gui.get<tgui::EditBox>("runtimeMin");

    auto runtimeMax = tgui::EditBox::create();
    runtimeMax->setPosition(740, 280);
    runtimeMax->setSize(200, 30);
    runtimeMax->setVisible(false);
    runtimeMax->setDefaultText("time in minutes");
    runtimeMax->setMaximumCharacters(3);
    runtimeMax->setInputValidator(tgui::EditBox::Validator::UInt);
    gui.add(runtimeMax, "runtimeMax");
    rMax = gui.get<tgui::EditBox>("runtimeMax");

    gui.draw();
}

void setVals(sf::RenderWindow& window, sf::Vector2i mousePosition, int& page, int& genre, int& type, int& rating) {

    if (page > 1 && page < 23) {
        if (page < 11) {
            if ((mousePosition.y >= 449) && (mousePosition.y <= 534)) {
                if ((mousePosition.x >= 924) && (mousePosition.x <= 1127)) {
                    genre = 8;
                    page = 10;
                    print(window, 10);
                }
                else if ((mousePosition.x >= 632) && (mousePosition.x <= 888)) {
                    genre = 7;
                    page = 9;
                    print(window, 9);
                }
                else if ((mousePosition.x >= 391) && (mousePosition.x <= 598)) {
                    genre = 6;
                    page = 8;
                    print(window, 8);
                }
                else if ((mousePosition.x >= 134) && (mousePosition.x <= 311)) {
                    genre = 5;
                    page = 7;
                    print(window, 7);
                }
            }
            else if ((mousePosition.y >= 273) && (mousePosition.y <= 362)) {
                if ((mousePosition.x >= 917) && (mousePosition.x <= 1145)) {
                    genre = 4;
                    page = 6;
                    print(window, 6);
                }
                else if ((mousePosition.x >= 652) && (mousePosition.x <= 854)) {
                    genre = 3;
                    page = 5;
                    print(window, 5);
                }
                else if ((mousePosition.x >= 380) && (mousePosition.x <= 597)) {
                    genre = 2;
                    page = 4;
                    print(window, 4);
                }
                else if ((mousePosition.x >= 127) && (mousePosition.x <= 322)) {
                    genre = 1;
                    page = 3;
                    print(window, 3);
                }
            }
        }

        else if (page < 15) {
            if ((mousePosition.y >= 271) && (mousePosition.y <= 441)) {
                if ((mousePosition.x >= 848) && (mousePosition.x <= 1151)) {
                    type = 3;
                    page = 14;
                    print(window, 14);
                }
                else if ((mousePosition.x >= 561) && (mousePosition.x <= 772)) {
                    type = 2;
                    page = 13;
                    print(window, 13);
                }
                else if ((mousePosition.x >= 141) && (mousePosition.x <= 512)) {
                    type = 1;
                    page = 12;
                    print(window, 12);
                }
            }
        }

        else {
            if ((mousePosition.y >= 219) && (mousePosition.y <= 288)) {
                if ((mousePosition.x >= 875) && (mousePosition.x <= 1146)) {
                    rating = 5;
                    page = 22;
                    print(window, 22);
                }
                else if ((mousePosition.x >= 610) && (mousePosition.x <= 830)) {
                    rating = 4;
                    page = 21;
                    print(window, 21);
                }
                else if ((mousePosition.x >= 397) && (mousePosition.x <= 562)) {
                    rating = 3;
                    page = 20;
                    print(window, 20);
                }
                else if ((mousePosition.x >= 237) && (mousePosition.x <= 349)) {
                    rating = 2;
                    page = 19;
                    print(window, 19);
                }
                else if ((mousePosition.x >= 123) && (mousePosition.x <= 191)) {
                    rating = 1;
                    page = 18;
                    print(window, 18);
                }
            }
        }
    }

    window.display();
}

void setUIVals(tgui::EditBox::Ptr Min, tgui::EditBox::Ptr Max, sf::Vector2i& data) {
    stringstream fix;
    fix << Min->getText() << ' ' << Max->getText();
    string t1, t2;
    fix >> t1 >> t2;
    std::cout << t1 << std::endl;
    if (t1.compare("") != 0) {
        if (t2.compare("") != 0) {
            data = sf::Vector2i(stoi(t1), stoi(t2));
        }
    }
}

void buttonPic(sf::RenderWindow& window, int picVal) {
    sf::Texture go;
    sf::Sprite lo;
    if (picVal == 0) {
        go.loadFromFile("images/next_clicked.png");
        lo.setTexture(go);
        lo.setPosition(sf::Vector2f(1026, 650));
    }
    else if (picVal == 1) {
        go.loadFromFile("images/prev_clicked.png");
        lo.setTexture(go);
        lo.setPosition(sf::Vector2f(66, 650));
    }
    else if (picVal == 2) {
        go.loadFromFile("images/done_clicked.png");
        lo.setTexture(go);
        lo.setPosition(sf::Vector2f(1026, 650));
    }
    window.draw(sf::Sprite(lo));
    window.display();
}

void pageChange(sf::RenderWindow& window, sf::Vector2i mousePosition, int& page, int genre, int type, int rating) {
    int picVal = -1;
    if (page == 1) {
        if ((mousePosition.y >= 505) && (mousePosition.y <= 601)) {
            if ((mousePosition.x >= 489) && (mousePosition.x <= 802)) {
                page += 1;
            }
        }
    }
    else if (page > 1 && page < 23) {
        if ((mousePosition.y >= 671) && (mousePosition.y <= 733)) {
            if ((mousePosition.x >= 1049) && (mousePosition.x <= 1193)) {
                if (page == 2 || page == 11 || page == 15 || page == 16) {
                    picVal = 0;
                }
                else if (page == 17) {
                    picVal = 2;
                }
                if (page < 17) {
                    if (page < 11) { page = 11 + type; }
                    else if (page < 15) { page = 15; }
                    else if (page == 16) { page = 17 + rating; }
                    else { page += 1; }
                }
                else {page = 23;}
            }
            else if ((mousePosition.x >= 89) && (mousePosition.x <= 224)) {
                if (page == 2 || page == 11 || page == 15 || page == 16 || picVal == 17) {
                    picVal = 1;
                }
                if (page > 10) {
                    if (page < 15) { page = 2 + genre; }//go back to the selected genre page
                    else if (page == 15) { page = 11 + type; }//go back to the selected type page
                    else if (page > 16) { page = 16; }
                    else { page -= 1; }//set saved UI values
                }
            }
        }
        buttonPic(window, picVal);

    }
}

void results(sf::RenderWindow& window, tgui::Gui& gui, EdgeList& edge, AdjList& adj) {
    auto panel = tgui::ScrollablePanel::create();
    panel->setPosition(15, 132);
    panel->setSize(1250, 650);
    gui.add(panel);

    auto list = tgui::ListBox::create();
    list->setSize(1250, 650);
    list->setItemHeight(25);//26 per page
    panel->setPosition(15, 132);
    list->addItem("   TITLE      GENRE        TYPE      DATE      runtime      RATING");

    vector<pair<Movie, Movie>> d = edge.getEdgeList();
    int i = 1;
    for(pair<Movie, Movie>& a : d) {
        string out = to_string(i++) + ". " + a.second.title + "\t";
        for (string& b : a.second.genre) {
            out += b + "\t";
        }
        for (string& c : a.second.type) {
            out += c + "\t";
        }
        out += "\t" + to_string(a.second.date) + "\t" + to_string(a.second.runtime)
             + "\t" + to_string(a.second.rating);
        list->addItem(out);
    }
    panel->add(list);

    gui.draw();
}


int main() {
    //SET UP
    sf::RenderWindow window{ sf::VideoMode(1280, 800), "Movie Finder" };
    tgui::GuiSFML gui{ window };
    //NAVIGATION
    int page = 1;
    //DATA
    MovieGraph graph;
    EdgeList edge;
    AdjList adj;
    //UI
    bool res = false;

    tgui::EditBox::Ptr dMin, dMax, rMin, rMax;

    UI(window, gui, dMin, dMax, rMin, rMax);


    while (window.isOpen()) {

        print(window, page);
        if (page == 23) {
            if (!res) {
                newGraph(graph, edge, adj);
                results(window, gui, edge, adj);
                res = true;
            }
        }
        else if (page == 15) {
            dMin->setVisible(true);
            dMax->setVisible(true);
            rMin->setVisible(false);
            rMax->setVisible(false);
        }
        else if (page == 16) {
            rMin->setVisible(true);
            rMax->setVisible(true);
            dMin->setVisible(false);
            dMax->setVisible(false);
        }
        else {
            dMin->setVisible(false);
            dMax->setVisible(false);
            rMin->setVisible(false);
            rMax->setVisible(false);
        }
        gui.draw();
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            gui.handleEvent(event);

            switch (event.type) {
            case sf::Event::Closed: {
                window.close();
            }break;
            case sf::Event::MouseButtonPressed: {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                if (event.mouseButton.button == sf::Mouse::Left) {
                    setVals(window, mousePosition, page, graph.genre, graph.type, graph.rating);
                    if (page == 15) {
                        setUIVals(dMin, dMax, graph.date);
                    }
                    else if (page == 16) {
                        setUIVals(rMin, rMax, graph.runtime);
                    }
                    pageChange(window, mousePosition, page, graph.genre, graph.type, graph.rating);
                }
            }break;
            }
        }
    }
    return 0;
}