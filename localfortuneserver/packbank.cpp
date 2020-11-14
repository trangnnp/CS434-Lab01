#include "packbank.h"
#include <iostream>

using namespace std;
PackBank::PackBank()
{
    initPacks();
}

void PackBank::initPacks() {
    Pack pack;
    pack.q=(char*)"Which of the following is another name for Software Piracy?";
    pack.a=(char*)"Pirates";
    pack.b=(char*)"SOPA";
    pack.c=(char*)"Copyright Infringement of Software";
    pack.d=(char*)"SOSA";
    pack.correct=2;
    packs.push_back(pack);

    pack.q=(char*)"What is \"torrenting\"\?";
    pack.a=(char*)"The file type for programs such as Bittorrent to open to obtain illegal files";
    pack.b=(char*)"A file in which it stores your browsing history on your computer.";
    pack.c=(char*)"Visiting a piracy website";
    pack.d=(char*)"Using your computer to remotely take over another computer unwillingly.";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Which of the following is a Cyberlocker site?";
    pack.a=(char*)"PirateBay";
    pack.b=(char*)"RapidShare";
    pack.c=(char*)"Youtube";
    pack.d=(char*)"DailyMotion";
    pack.correct=1;
    packs.push_back(pack);

    pack.q=(char*)"Which of the following countries has the highest rate of piracy?";
    pack.a=(char*)"Armenia";
    pack.b=(char*)"Canada";
    pack.c=(char*)"United States";
    pack.d=(char*)"China";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Around the world, many websites are used for piracy, Which of the following is the most used?";
    pack.a=(char*)"torrent.com";
    pack.b=(char*)"IsoHunt";
    pack.c=(char*)"TorrentReactor";
    pack.d=(char*)"ThePirateBay";
    pack.correct=2;
    packs.push_back(pack);

    pack.q=(char*)"Around the world, Much of the data transfered using P2P networks are copyrighted. Which of the following percentages is the closest?";
    pack.a=(char*)"92%";
    pack.b=(char*)"52%";
    pack.c=(char*)"33%";
    pack.d=(char*)"99%";
    pack.correct=3;
    packs.push_back(pack);

    pack.q=(char*)"What is the percentage of softwares that are running worldwide and are downloaded illegally?";
    pack.a=(char*)"52%";
    pack.b=(char*)"49%";
    pack.c=(char*)"42%";
    pack.d=(char*)"73%";
    pack.correct=2;
    packs.push_back(pack);

    pack.q=(char*)"In 2010, the amount of software downloaded illegally was worth how much?";
    pack.a=(char*)"23 Million Dollars";
    pack.b=(char*)"32 Million Dollars";
    pack.c=(char*)"59 Billion Dollars";
    pack.d=(char*)"59 Million Dollars";
    pack.correct=2;
    packs.push_back(pack);

    pack.q=(char*)"In 2010, Which of the following movies was pirated the most on the internet?";
    pack.a=(char*)"Avatar";
    pack.b=(char*)"Kick-Ass";
    pack.c=(char*)"Inception";
    pack.d=(char*)"Iron Man 2";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"What is the most pirated piece of software on the Internet?";
    pack.a=(char*)"Windows Vista";
    pack.b=(char*)"Windows XP";
    pack.c=(char*)"Microsoft Office";
    pack.d=(char*)"Adobe Photoshop CS";
    pack.correct=3;
    packs.push_back(pack);

    pack.q=(char*)"In 2010, Second most popular movie was Batman: The Dark Knight. How many pirated downloads did it have?";
    pack.a=(char*)"10 Million";
    pack.b=(char*)"30 Million";
    pack.c=(char*)"19 Million";
    pack.d=(char*)"17 Million";
    pack.correct=2;
    packs.push_back(pack);

    pack.q=(char*)"In 2010, Many Video Games were pirated for use. Which of the following was the most pirated?";
    pack.a=(char*)"Tom Clancy HAWX";
    pack.b=(char*)"Call of Duty Modern Warfare 3";
    pack.c=(char*)"Call of Duty Black Ops";
    pack.d=(char*)"Battlefield 2 Bad Company";
    pack.correct=3;
    packs.push_back(pack);

    pack.q=(char*)"Which king was married to Eleanor of Aquitaine?";
    pack.a=(char*)"Henry I";
    pack.b=(char*)"Henry II";
    pack.c=(char*)"Richard I";
    pack.d=(char*)"Henry V";
    pack.correct=1;
    packs.push_back(pack);

    pack.q=(char*)"Oberon is the satellite of which planet?";
    pack.a=(char*)"Mercury";
    pack.b=(char*)"Neptune";
    pack.c=(char*)"Uranus";
    pack.d=(char*)"Mars";
    pack.correct=2;
    packs.push_back(pack);

    pack.q=(char*)"In 1912, former US President Theodore Roosevelt was a candidate for which political party?";
    pack.a=(char*)"Bull Moose";
    pack.b=(char*)"Bull Dog";
    pack.c=(char*)"Bull Elephant";
    pack.d=(char*)"Bull Frog";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Tomas Masaryk was the first president of which country?";
    pack.a=(char*)"Czechoslovakia";
    pack.b=(char*)"Poland";
    pack.c=(char*)"Hungary";
    pack.d=(char*)"Yugoslavia";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"If you planted the seeds of 'Quercus robur', what would grow?";
    pack.a=(char*)"Trees";
    pack.b=(char*)"Flowers";
    pack.c=(char*)"Vegetables";
    pack.d=(char*)"Grain";
    pack.correct=2;
    packs.push_back(pack);

    pack.q=(char*)"A number one followed by one hundred zeros is known by what name?";
    pack.a=(char*)"Googol";
    pack.b=(char*)"Megatron";
    pack.c=(char*)"Gigabit";
    pack.d=(char*)"Nanomole";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Which scientific unit is named after an Italian nobleman?";
    pack.a=(char*)"Pascal";
    pack.b=(char*)"Ohm";
    pack.c=(char*)"Volt";
    pack.d=(char*)"Hertz";
    pack.correct=2;
    packs.push_back(pack);

    pack.q=(char*)"Which of these is a butterfly, not a moth?";
    pack.a=(char*)"Mother Shipton";
    pack.b=(char*)"Red Underwing";
    pack.c=(char*)"Burnished Brass";
    pack.d=(char*)"Speckled Wood";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Which of these is not one of the American Triple Crown horse races?";
    pack.a=(char*)"Arlington Million";
    pack.b=(char*)"Belmont Stakes";
    pack.c=(char*)"Kentucky Derby";
    pack.d=(char*)"Preakness Stakes";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Translated from the Latin, what is the motto of the United States?";
    pack.a=(char*)"In God we trust";
    pack.b=(char*)"One out of many";
    pack.c=(char*)"All as one";
    pack.d=(char*)"Striving together";
    pack.correct=1;
    packs.push_back(pack);

    pack.q=(char*)"Which boxer was famous for striking the gong in the introduction to J. Arthur Rank films?";
    pack.a=(char*)"Bombardier Billy Wells";
    pack.b=(char*)"Freddie Mills";
    pack.c=(char*)"Terry Spinks";
    pack.d=(char*)"Don Cockell";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Which of these UK prime ministers never served as foreign secretary?";
    pack.a=(char*)"Winston Churchill";
    pack.b=(char*)"Alex Douglas-Home";
    pack.c=(char*)"Anthony Eden";
    pack.d=(char*)"Harold Macmillan";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Which of these people was born the same year as Queen Elizabeth II?";
    pack.a=(char*)"Audrey Hepburn";
    pack.b=(char*)"Judy Garland";
    pack.c=(char*)"Julie Andrews";
    pack.d=(char*)"Marilyn Monroe";
    pack.correct=3;
    packs.push_back(pack);

    pack.q=(char*)"In the history of motor sport, which of these iconic races was held first?";
    pack.a=(char*)"Le Mans 24 Hours";
    pack.b=(char*)"Monaco Grand Prix";
    pack.c=(char*)"Indy 500";
    pack.d=(char*)"Isle of Man TT";
    pack.correct=3;
    packs.push_back(pack);

    pack.q=(char*)"In 1718, which pirate died in battle off the coast of what is now North Carolina?";
    pack.a=(char*)"Calico Jack";
    pack.b=(char*)"Blackbeard";
    pack.c=(char*)"Bartholomew Roberts";
    pack.d=(char*)"Captain Kidd";
    pack.correct=1;
    packs.push_back(pack);

    pack.q=(char*)"Which county cricket side is based at Chester-le-Street?";
    pack.a=(char*)"Warwickshire";
    pack.b=(char*)"Durham";
    pack.c=(char*)"Northants";
    pack.d=(char*)"Leicestershire";
    pack.correct=1;
    packs.push_back(pack);

    pack.q=(char*)"Which monarch was known as \"the wisest fool in Christendom\"?";
    pack.a=(char*)"James I";
    pack.b=(char*)"Charles I";
    pack.c=(char*)"Edward I";
    pack.d=(char*)"Henry I";
    pack.correct=0;
    packs.push_back(pack);

    pack.q=(char*)"Oberon is the satellite of which planet?";
    pack.a=(char*)"Mercury";
    pack.b=(char*)"Neptune";
    pack.c=(char*)"Uranus";
    pack.d=(char*)"Mars";
    pack.correct=2;
    packs.push_back(pack);
}
