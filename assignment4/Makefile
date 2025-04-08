Decks_game: main.o Bow_man.o Card.o Characters.o Deck.o Dragon.o Enemies.o Fighter.o Game.o Ghost.o Set_card.o Troll.o Wizard.o
	g++ main.o Bow_man.o Card.o Characters.o Deck.o Dragon.o Enemies.o Fighter.o Game.o Ghost.o Set_card.o Troll.o Wizard.o -o Decks_game

main.o: main.cpp Card.h Deck.h Characters.h Enemies.h Set_card.h Game.h Fighter.h Wizard.h Bow_man.h Troll.h Ghost.h Dragon.h Memory_Error.h
	g++ -c main.cpp

Bow_man.o: Bow_man.cpp Bow_man.h Characters.h Card.h Deck.h Enemies.h Memory_Error.h
	g++ -c Bow_man.cpp

Card.o: Card.cpp Card.h Memory_Error.h
	g++ -c Card.cpp

Characters.o: Characters.cpp Characters.h Card.h Deck.h Memory_Error.h
	g++ -c Characters.cpp

Deck.o: Deck.cpp Deck.h Card.h Memory_Error.h
	g++ -c Deck.cpp

Dragon.o: Dragon.cpp Dragon.h Enemies.h Card.h Characters.h Deck.h Set_card.h Memory_Error.h
	g++ -c Dragon.cpp

Enemies.o: Enemies.cpp Enemies.h Card.h Memory_Error.h
	g++ -c Enemies.cpp

Fighter.o: Fighter.cpp Fighter.h Characters.h Card.h Deck.h Enemies.h Memory_Error.h
	g++ -c Fighter.cpp

Game.o: Game.cpp Game.h Set_card.h Card.h Characters.h Deck.h Fighter.h Wizard.h Bow_man.h Enemies.h Troll.h Ghost.h Dragon.h Memory_Error.h
	g++ -c Game.cpp

Ghost.o: Ghost.cpp Ghost.h Enemies.h Card.h Characters.h Deck.h Set_card.h Memory_Error.h
	g++ -c Ghost.cpp

Set_card.o: Set_card.cpp Set_card.h Card.h Memory_Error.h
	g++ -c Set_card.cpp

Troll.o: Troll.cpp Troll.h Enemies.h Card.h Characters.h Deck.h Set_card.h Memory_Error.h
	g++ -c Troll.cpp

Wizard.o: Wizard.cpp Wizard.h Characters.h Card.h Deck.h Enemies.h Memory_Error.h
	g++ -c Wizard.cpp

clean:
	rm -f *.o Decks_game
