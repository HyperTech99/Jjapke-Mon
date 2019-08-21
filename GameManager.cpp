#include "GameManager.h"

const int OpeningScene = 0;
const int SelectGameScene = 1;
const int PokemonSelectScene = 2;
const int MainScene = 3;
const int BattleScene = 4;
const int BattleWin = 5;
const int BattleLose = 6;

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{

}

GameManager* GameManager::GetInstance()
{
	if (instance == nullptr)
		instance = new GameManager();

	return instance;
}

int GameManager::UserInput()
{
	int i;
	cin >> i;
	return i;
}

void GameManager::gotoxy(int _x, int _y)
{
	COORD pos = { _x,_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GameManager::Run()
{
	system(" mode  con lines=20   cols=45 ");
	string temp;
   bool isValid;
   int i;

   SkillManager *skillmanager = SkillManager::GetInstance();
   BattleManager *battle = BattleManager::GetInstance();
   Player *player = Player::GetInstance();
   Statistics *statistics = Statistics::GetInstance();

   SceneManager::GetInstance()->LoadScene();
   SceneManager::GetInstance()->GetSceneList()[BattleScene]->LoadData();
   Image battleImage(19, 1, "BattleImage");
   Text playerMp(13, 8, "playerMp", 0);

   SceneManager::GetInstance()->GetSceneList()[BattleScene]->AddText(&playerMp);
   SceneManager::GetInstance()->GetSceneList()[BattleScene]->AddImage(&battleImage);
   SceneManager::GetInstance()->GetSceneList()[BattleScene]->SearchText("enemyName")->SetCOORD(9, 2);
   SceneManager::GetInstance()->GetSceneList()[BattleScene]->SearchText("playerName")->SetCOORD(9, 7);

   Text exp(2, 14, "Exp", 0);
   Text totalGames(13, 15, "TotalGames", 0);
   Text winRates(11, 16, "WinRates", 0);
   Text wins(6, 17, "Wins", 0);
   Text loses(17, 17, "Loses", 0);
   SceneManager::GetInstance()->GetSceneList()[BattleWin]->AddText(&exp);
   SceneManager::GetInstance()->GetSceneList()[BattleWin]->AddText(&totalGames);
   SceneManager::GetInstance()->GetSceneList()[BattleWin]->AddText(&winRates);
   SceneManager::GetInstance()->GetSceneList()[BattleWin]->AddText(&wins);
   SceneManager::GetInstance()->GetSceneList()[BattleWin]->AddText(&loses);

   SceneManager::GetInstance()->GetSceneList()[BattleLose]->AddText(&totalGames);
   SceneManager::GetInstance()->GetSceneList()[BattleLose]->AddText(&winRates);
   SceneManager::GetInstance()->GetSceneList()[BattleLose]->AddText(&wins);
   SceneManager::GetInstance()->GetSceneList()[BattleLose]->AddText(&loses);

   //SelectGameScMenu �����
   Menu selectGameScMenu(0,1,"firstMenu");
   selectGameScMenu.AddItem("1. Load Profile");
   selectGameScMenu.AddItem("2. New Profile");
   SceneManager::GetInstance()->GetSceneList()[SelectGameScene]->AddMenu(&selectGameScMenu);
   //SelectGameScMenu ����� �Ϸ�

   //PokemonSelectScMenu �����
   Menu pokemonSelectScMenu(0, 3, "firstMenu");
   pokemonSelectScMenu.AddItem("1. �̻��ؾ�");
   pokemonSelectScMenu.AddItem("2. ���̸�");
   pokemonSelectScMenu.AddItem("3. ���α�");
   SceneManager::GetInstance()->GetSceneList()[PokemonSelectScene]->AddMenu(&pokemonSelectScMenu);
   //PokemonSelectScMenu ����� �Ϸ�

   SceneManager::GetInstance()->ChangeScene(OpeningScene);

   bool flag = true;
   bool battleFlag = true;

   SceneManager::GetInstance()->ChangeScene(3000,SelectGameScene);
   gotoxy(0, 4);//Ŀ�� ��ġ ����

   player->SetPokemon();
   switch (UserInput())
   {

   //������ �ҷ�����
   case 1:
      cout << "playername : ";
      cin >> temp;
      player->LoadProfile(temp);
      //��� �ҷ�����
      statistics->LoadStatistics(player->GetplayerName());

      break;

   //������ �����ϱ�
   case 2:
      cout << "name : ";
      cin >> temp;
      player->SetplayerName(temp);
      
      cout << "age : ";
      cin >> i;
      player->SetplayerAge(i);

      cout << "gender : ";
      cin >> isValid;
      player->SetplayerGender(isValid);

      //��� ����
      statistics->InitStatistics();

      SceneManager::GetInstance()->ChangeScene(1000, PokemonSelectScene);
      
      
      gotoxy(0, 12); //Ŀ�� ��ġ����

      /* switch �� �÷��̾� ���ϸ��� ����*/
      switch (UserInput()) {
      case 1:
         player->GetPokemon()->PokemonLoad(1);
         break;
      case 2:
         player->GetPokemon()->PokemonLoad(2);
         break;
      case 3:
         player->GetPokemon()->PokemonLoad(3);
         break;
      }
      //player->SaveProfile();
      break;
   default:
      break;
   }
   SceneManager::GetInstance()->ChangeScene(1000, MainScene);
   while (flag)
   {
      battleFlag = true;

      battle->CopyPokemon();
      Pokemon *pokemon = battle->GetPokemon();

      //Battle Scene Menu�� �����
      Menu menu1(1, 12, "firstMenu");
      menu1.AddItem("1. Attack");
      menu1.AddItem("2. Run");

      Menu menu2(1, 11, "SkillSelection");
      menu2.AddItem("1. " + pokemon->GetSkills()[0].GetskillName());
      menu2.AddItem("2. " + pokemon->GetSkills()[1].GetskillName());
      menu2.AddItem("3. " + pokemon->GetSkills()[2].GetskillName());
      menu2.AddItem("4. " + pokemon->GetSkills()[3].GetskillName());

      SceneManager::GetInstance()->GetSceneList()[BattleScene]->AddMenu(&menu1);
      SceneManager::GetInstance()->GetSceneList()[BattleScene]->AddMenu(&menu2);
      //��Ʋ�� �޴� ����� �� �߰� �Ϸ�

      battle->CreateMonster();
      Monster *monster = battle->GetMonster();
      monster->SelectSkill();

      //���� ���� ����

      switch (UserInput()) //��Ʋ�� ����
      {

      //go to fight
      case 1:

         SceneManager::GetInstance()->ChangeScene(BattleScene);
         gotoxy(1, 14);//�Է¹޴� Ŀ�� ��ġ ����
         while (battleFlag)
         {
            
            //BattleScene Text�� ������Ʈ
            switch (UserInput())
            {
            case 1:
               //�����Ѵ� ������
               //��ų �޴��� �����ش�
               SceneManager::GetInstance()->GetSceneList()[BattleScene]->Draw("SkillSelection");
               gotoxy(1, 15);//�Է¹޴� Ŀ�� ��ġ ����
                          //UserInput();

               isValid = false;
               while (!isValid) {
                  gotoxy(0, 15);
                  cout << " ";
                  gotoxy(0, 15);
                  i = UserInput();
                  i--;
                  isValid = battle->Action(i, pokemon, monster);
               }

               switch (i)
               {

               case 0:
                  gotoxy(0, 17);
                  cout << pokemon->GetName() << "�� " << pokemon->GetSkills()[0].GetskillName() << "!";
                  break;
               case 1:
                  gotoxy(0, 17);
                  cout << pokemon->GetName() << "�� " << pokemon->GetSkills()[1].GetskillName() << "!";
                  break;
               case 2:
                  gotoxy(0, 17);
                  cout << pokemon->GetName() << "�� " << pokemon->GetSkills()[2].GetskillName() << "!";
                  break;
               case 3:
                  gotoxy(0, 17);
                  cout << pokemon->GetName() << "�� " << pokemon->GetSkills()[3].GetskillName() << "!";
                  break;
               default:
                  break;
               }
               cin.get();
               cin.get();
               SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateNDisplayText("enemyHp", monster->GetHp());
               SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateNDisplayText("playerMp", pokemon->GetMp());

               if (monster->IsDeath()) {

				  player->GetPokemon()->TakeExp(monster->GetExp());

                  battleFlag = false;
				  battle->SetIsWin(true);
				  statistics->UpdateStatistics();

                  SceneManager::GetInstance()->ChangeScene(BattleWin);
                  gotoxy(0, 18);
                  cin.get();
                  break;
               }

               isValid = false;
               while (!isValid) {
                  i = monster->SelectAct();
                  isValid = battle->Action(i, monster, pokemon);
               }
            
               switch (i)
               {

               case 0:
                  gotoxy(0, 17);
                  cout << "                                     ";
                  gotoxy(0, 17);
                  cout << monster->GetName() << "�� " << monster->GetSkills()[0].GetskillName() << "!";
                  break;
               case 1:
                  gotoxy(0, 17);
                  cout << "                                     ";
                  gotoxy(0, 17);
                  cout << monster->GetName() << "�� " << monster->GetSkills()[1].GetskillName() << "!";
                  break;
               case 2:
                  gotoxy(0, 17);
                  cout << "                                     ";
                  gotoxy(0, 17);
                  cout << monster->GetName() << "�� " << monster->GetSkills()[2].GetskillName() << "!";
                  break;
               case 3:
                  gotoxy(0, 17);
                  cout << "                                     ";
                  gotoxy(0, 17);
                  cout << monster->GetName() << "�� " << monster->GetSkills()[3].GetskillName() << "!";
                  break;
               default:
                  break;
               }

               cin.get();
               SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateNDisplayText("playerHp", pokemon->GetHp());
			   SceneManager::GetInstance()->GetSceneList()[BattleScene]->UpdateNDisplayText("enemyHp", monster->GetHp());

               if (pokemon->IsDeath()) {

                  battleFlag = false;
				  battle->SetIsWin(false);
				  statistics->UpdateStatistics();

                  SceneManager::GetInstance()->ChangeScene(BattleLose);
                  gotoxy(0, 18);
                  cin.get();
                  break;
               }

               SceneManager::GetInstance()->ChangeScene(0, BattleScene);
               gotoxy(0, 15);

               break;
            case 2:       //��������
               if (battle->Run()) {
                  gotoxy(0, 17);
                  cout << "������ �����ƴ�!";
                  cin.get();
                  cin.get();
                  battleFlag = false;
               }

               else {
                  gotoxy(0, 17);
                  cout << "������ �����ߴ�!";
                  cin.get();
                  cin.get();
                  gotoxy(1, 14);
                  cout << " ";
                  gotoxy(1, 14);
               }
               
               break;
            case 0:     //������
               battleFlag = false;
               break;
            }
         }
         SceneManager::GetInstance()->ChangeScene(0, MainScene);
         break;

      //���α׷� ����
      case 0:
         flag = 0;
         player->SaveProfile();
         //��� ����
         statistics->SaveStatistics(player->GetplayerName());
         break;
      default:
         break;
      }

   }


}