//
// Created by xima on 02/08/19.
//

#include "../../includes/TableItens/Table.hpp"

Table::Table(TableSize totalPlayers) {
  this->bigBlind = 0;
  this->fold = std::make_unique<Fold>(Fold());
  this->call = std::make_unique<Call>(Call());
  this->bet = std::make_unique<Bet>(Bet());
  this->user = std::make_unique<Player>(Player(P0, totalPlayers));
  this->pot = std::make_unique<Pot>(Pot());
  this->communityCards = std::make_unique<CommunityCards>(CommunityCards());

  this->raiseButtons = std::make_unique<std::vector<std::unique_ptr<RaiseButton>>>(std::vector<std::unique_ptr<RaiseButton>>());
  this->raiseButtons->push_back(std::make_unique<RaiseButton>(RaiseButton(0)));
  this->raiseButtons->push_back(std::make_unique<RaiseButton>(RaiseButton(1)));
  this->raiseButtons->push_back(std::make_unique<RaiseButton>(RaiseButton(2)));
  this->raiseButtons->push_back(std::make_unique<RaiseButton>(RaiseButton(3)));

  this->players = std::make_unique<std::vector<std::unique_ptr<Player>>>(std::vector<std::unique_ptr<Player>>());
  this->tableSize = totalPlayers;
  switch (totalPlayers) {
    case MAX_2:
      this->players->push_back(std::make_unique<Player>(Player(P1, totalPlayers)));
      break;
    case MAX_3:
      this->players->push_back(std::make_unique<Player>(Player(P1, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P2, totalPlayers)));
      break;
    case MAX_6:
      this->players->push_back(std::make_unique<Player>(Player(P1, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P2, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P3, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P4, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P5, totalPlayers)));
      break;
    case MAX_9:
      this->players->push_back(std::make_unique<Player>(Player(P1, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P2, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P3, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P4, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P5, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P6, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P7, totalPlayers)));
      this->players->push_back(std::make_unique<Player>(Player(P8, totalPlayers)));
      break;
    default:
      std::cout << "Numero de jogadores nao conhecido" << std::endl;
      throw;
  }
}

void Table::accept(AbstractVisitor &visitor) {
  this->fold->accept(visitor);
  this->call->accept(visitor);
  this->bet->accept(visitor);
  this->pot->accept(visitor);
  this->user->accept(visitor);
  this->communityCards->accept(visitor);
  for(const auto &player: *this->players) {
    player->accept(visitor);
  }
  return visitor.visit(*this);
}

void Table::setBigBlind(float bigBlindValue) {
  this->bigBlind = bigBlindValue;
}

bool Table::foldActive() {
  return this->fold->active();
}

void Table::makeAction(Actions action) {
  switch (action) {
    case FOLD_ACTION:
      if (this->fold->active())
        this->fold->click();
      else
        this->call->click();
      break;
    case CALL_ACTION:
      this->call->click();
      break;
    case RAISE_BUTTON_1_ACTION:
      this->bet->click();
      break;
    case RAISE_BUTTON_2_ACTION:
      this->raiseButtons->at(1)->click();
      this->bet->click();
      break;
    case RAISE_BUTTON_3_ACTION:
      this->raiseButtons->at(2)->click();
      this->bet->click();
      break;
    case RAISE_BUTTON_4_ACTION:
      this->raiseButtons->at(3)->click();
      this->bet->click();
      break;
  }
}

StreetEnum Table::getStreet() {
  int totalCards = this->communityCards->cardOnTable();
  switch (totalCards) {
    case 0:
      return PRE_FLOP_STREET;
    case 3:
      return FLOP_STREET;
    case 4:
      return TURN_STREET;
    case 5:
      return RIVER_STREET;
    default:
      std::cout << "Erro ao tentar encontrar street (Table::getStreet) totalCards: " << std::to_string(totalCards) << std::endl;
      throw;
  }
}

std::string Table::getHand() {
  return this->user->handValue();
}

float Table::getBigBlind() {
  return this->bigBlind;
}

std::string Table::getCommunityCards() {
  return this->communityCards->getCards();
}

int Table::getDealerPosition() {
  for (int i = 0; i < this->players->size(); ++i) {
    if (this->players->at(i)->isDealer())
      return i+1; // player 0 eh o usuario, portanto o primeiro cara do lado do usuario esta na posicao 0 e eh o player1
  }
  return 0; // caso nao seja nenhum dos meus inimigos, o dealer vai ser eu mesmo
}

TableSize Table::sizeTable() {
  return this->tableSize;
}

float Table::getCallSize() {
  return this->call->size();
}

float Table::getBetSize() {
  return this->bet->size();
}

float Table::getStackSize() {
  return this->user->stackSize();
}

float Table::getPotSize() {
  return this->pot->size();
}

std::string Table::playersPlaying() {
  std::string playing;
  for(const auto &p : *this->players) {
    if (p->playing())
      playing += "1";
    else
      playing += "0";
  }
  return playing;
}
