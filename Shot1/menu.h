
void menu(RenderWindow & window) {
    Texture menuTexture1, menuTexture3, menuBackground;
    menuTexture1.loadFromFile("Images//Start.png");
    menuTexture3.loadFromFile("Images//Exit.png");
    menuBackground.loadFromFile("Images/Menu1.png"); // фон меню
    Sprite menu1(menuTexture1), menu3(menuTexture3), menuBg(menuBackground);
    bool isMenu = 1;
    int menuNum = 0;
    menu1.setPosition(500, 450);
    menu3.setPosition(800, 450);
    menuBg.setPosition(0, 0);

    //////////////////////////////МЕНЮ///////////////////
    while (isMenu)
    {
        menu1.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(500, 450, 100, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
        if (IntRect(800, 450, 100, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) isMenu = false;// Start
            if (menuNum == 3)  { window.close(); isMenu = false; } // Exit

        }

        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu3);


        window.display();
    }
    ////////////////////////////////////////////////////
}
