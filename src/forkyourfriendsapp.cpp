// © Copyright 2010 - 2016 BlackTopp Studios Inc.
/* This file is part of ForkYourFriends.

    The Mezzanine Engine is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The Mezzanine Engine is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Mezzanine Engine.  If not, see <http://www.gnu.org/licenses/>.
*/
/* The original authors have included a copy of the license specified above in the
   'Docs' folder. See 'gpl.txt'
*/
/* We welcome the use of the Mezzanine engine to anyone, including companies who wish to
   Build professional software and charge for their product.

   However there are some practical restrictions, so if your project involves
   any of the following you should contact us and we will try to work something
   out:
    - DRM or Copy Protection of any kind(except Copyrights)
    - Software Patents You Do Not Wish to Freely License
    - Any Kind of Linking to Non-GPL licensed Works
    - Are Currently In Violation of Another Copyright Holder's GPL License
    - If You want to change our code and not add a few hundred MB of stuff to
        your distribution

   These and other limitations could cause serious legal problems if you ignore
   them, so it is best to simply contact us or the Free Software Foundation, if
   you have any questions.

   Joseph Toppi - toppij@gmail.com
   John Blackwood - makoenergy02@gmail.com
*/

#include "forkyourfriendsapp.h"
#include "transitions.h"
#include "forklift.h"

ForkYourFriendsApp::ForkYourFriendsApp() :
    TheEntresol(NULL),
    TheWorld(NULL),
    PlayerOne(NULL),
    PlayerTwo(NULL)
{
    // State Setup
    GameState.AddState("Init");
    GameState.AddState("Menu");
    GameState.AddState("Game");
    GameState.AddTransition("Init","Menu",new InitToMenuTransitionAction());
    GameState.AddTransition("Menu","Game",new MenuToGameTransitionAction());
    GameState.AddTransition("Game","Game",new GameToGameTransitionAction());
    GameState.AddTransition("Game","Menu",new GameToMenuTransitionAction());
    GameState.ChangeState("Init");

    // Types Setup
    this->RegisterTypes();

    // Entresol Setup
    this->TheEntresol = new Entresol("Data/",Resource::AT_FileSystem);
    this->CreateWorld();
}

ForkYourFriendsApp::~ForkYourFriendsApp()
{
    delete this->TheEntresol;
}

void ForkYourFriendsApp::RegisterTypes()
{

}

void ForkYourFriendsApp::CreateLoadingScreen()
{

}

void ForkYourFriendsApp::CreateWorld()
{
    Physics::ManagerConstructionInfo Info;
    Info.PhysicsFlags = Physics::ManagerConstructionInfo::PCF_LimitlessWorld | Physics::ManagerConstructionInfo::PCF_Multithreaded;

    this->TheWorld = this->TheEntresol->CreateWorld("ForkingWorld",Info,"DefaultSceneManager");
}

void ForkYourFriendsApp::MakeGUI()
{

}

void ForkYourFriendsApp::Initialize()
{
    this->TheEntresol->Initialize(false);
    this->TheWorld->Initialize();
}

void ForkYourFriendsApp::CreatePlayerlessScene()
{

}

int ForkYourFriendsApp::GetForkin()
{

}
