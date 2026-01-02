#include "create_deck.hpp"
#include "cards.hpp"       
#include "deck.hpp"

// card2(
// 1. ÝSÝM, 
// 2. ÜCRET, 
// 3. HASAR, 
// 4. VERDÝÐÝ PARA, 
// 5. ÝYÝLEÞME, 
// 6. FLAGLAR (ÜSLERDE LAZIM), 
// 7. KOÞULLAR, 
// 8. KOÞUL PARAMETRESÝ,
// 9. FACTION KOÞULU,
// 10. FACT. KOÞUL PARAMETRESÝ,
// 11. HURDA KOÞULU,
// 12. HURDA KOÞUL PARAMETRESÝ,
// 13. FACTION);

// BLOB KARTLARI
card2 blobs[] = {
	card2("Blob Savaþçýsý", 1, 3, 0, 0, 0, 0, 0, COND_DRAW1, 0, 0, 0, FACT_BLOB),
	card2("Blob Savaþçýsý", 1, 3, 0, 0, 0, 0, 0, COND_DRAW1, 0, 0, 0, FACT_BLOB),
	card2("Blob Savaþçýsý", 1, 3, 0, 0, 0, 0, 0, COND_DRAW1, 0, 0, 0, FACT_BLOB),
	card2("Blob Yokedici", 4, 6, 0, 0, 0, 0, 0, COND_DESTROYBASEORJUNKMARKET, 0, 0, 0, FACT_BLOB),
	card2("Blob Yokedici", 4, 6, 0, 0, 0, 0, 0, COND_DESTROYBASEORJUNKMARKET, 0, 0, 0, FACT_BLOB),
	card2("Blok Çarký", 3,1,0,0,FLAG_BASE,0,0,0,0,COND_ADDMONEY,3,FACT_BLOB),
	card2("Blok Çarký", 3,1,0,0,FLAG_BASE,0,0,0,0,COND_ADDMONEY,3,FACT_BLOB),
	card2("Blok Çarký", 3,1,0,0,FLAG_BASE,0,0,0,0,COND_ADDMONEY,3,FACT_BLOB),
	card2("Tüccar Balýk",2,0,3,0,0,0,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB),
	card2("Tüccar Balýk",2,0,3,0,0,0,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB),
	card2("Tüccar Balýk",2,0,3,0,0,0,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB),
	card2("Solucan",3,5,0,0,0,0,0,COND_ADDDAMAGE,2,COND_ADDMONEY,3,FACT_BLOB),
	card2("Solucan",3,5,0,0,0,0,0,COND_ADDDAMAGE,2,COND_ADDMONEY,3,FACT_BLOB),
	card2("Larva",2,4,0,0,0,COND_JUNKMARKET,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB),
	card2("Larva",2,4,0,0,0,COND_JUNKMARKET,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB),
	card2("Ana Gemi",7,6,0,0,0,COND_DRAW1,0,COND_DRAW1,0,0,0,FACT_BLOB),
	card2("Savaþ Kuþu",6,8,0,0,0,0,0,COND_DRAW1,0,COND_ADDDAMAGE,4,FACT_BLOB),
	card2("Sürü",5,3,0,0,FLAG_BASE,0,0,COND_DRAW1,0,0,0,FACT_BLOB),
	card2("Blob Gezegeni",8,0,0,0,FLAG_BASE,COND_DRAWPERBLOB,0,0,0,0,0,FACT_BLOB),
	card2("Blob Taþýyýcý",6,7,0,0,0,0,0,COND_FREECARD_AND_TOPDECK,0,0,0,FACT_BLOB),
};
// MECH KARTLARI
card2 mechs[] = {
	card2("Ticaret Dronu",1,0,1,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Ticaret Dronu",1,0,1,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Ticaret Dronu",1,0,1,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Füze Dronu",2,2,0,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Füze Dronu",2,2,0,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Füze Dronu",2,2,0,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Ýkmal Dronu",3,0,2,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Ýkmal Dronu",3,0,2,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Ýkmal Dronu",3,0,2,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH),
	card2("Muharebe Ýstasyonu",3,0,0,0,FLAG_BASE | FLAG_PATROL,0,0,0,0,COND_ADDDAMAGE,5,FACT_MECH),
	card2("Muharebe Ýstasyonu",3,0,0,0,FLAG_PATROL | FLAG_BASE,0,0,0,0,COND_ADDDAMAGE,5,FACT_MECH),
	//card2("Kamuflaj Ajaný",4),
	card2("Devriye",4,5,3,0,0,COND_CHOICE,2,COND_JUNKOWN1,0,0,0,FACT_MECH),
	card2("Devriye",4,5,3,0,0,COND_CHOICE,2,COND_JUNKOWN1,0,0,0,FACT_MECH),
	card2("Savaþ Makinesi",5,4,0,0,0,COND_JUNKOWN1,0,COND_DRAW1,0,0,0,FACT_MECH),
	card2("Dron Dünya",5,0,0,0,FLAG_BASE | FLAG_PATROL | FLAG_GLOBAL,0,0,0,0,0,0,FACT_MECH),
	card2("Misilleme Tanký",6,6,0,0,0,COND_DESTROYBASE,0,COND_DRAW1,0,0,0,FACT_MECH),
	card2("Geri Dönüþüm Merkezi",6,0,0,0,FLAG_BASE | FLAG_PATROL,COND_JUNKOWN1,0,0,0,0,0,FACT_MECH),
	card2("Seyyar Sanayi",7,0,0,0,FLAG_BASE | FLAG_PATROL,COND_DRAWANDJUNK,0,0,0,0,0,FACT_MECH),
	card2("Ana Beyin",8,0,0,0,FLAG_BASE | FLAG_PATROL,COND_JUNK02,0,0,0,0,0,FACT_MECH),



};
// STAR KARTLARI
card2 stars[] = {
	card2("Çevik Saldýrgan",1,2,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR),
	card2("Çevik Saldýrgan",1,2,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR),
	card2("Çevik Saldýrgan",1,2,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR),
	card2("Piyade Gemisi",2,1,0,0,0,COND_DRAW1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR),
	card2("Piyade Gemisi",2,1,0,0,0,COND_DRAW1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR),
	card2("Öncü Kuvvet",3,0,1,0,0,COND_DRAW1,0,0,0,COND_DISCARD1,0,FACT_STAR),
	card2("Öncü Kuvvet",3,0,1,0,0,COND_DRAW1,0,0,0,COND_DISCARD1,0,FACT_STAR),
	card2("Öncü Kuvvet",3,0,1,0,0,COND_DRAW1,0,0,0,COND_DISCARD1,0,FACT_STAR),
	card2("Hücum Gemisi",3,4,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,COND_DRAW1,0,FACT_STAR),
	card2("Hücum Gemisi",3,4,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,COND_DRAW1,0,FACT_STAR),
	card2("Hücum Gemisi",3,4,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,COND_DRAW1,0,FACT_STAR),
	card2("Uzay Ýstasyonu",4,2,0,0,FLAG_BASE | FLAG_PATROL,0,0,COND_ADDDAMAGE,2,COND_ADDMONEY,4,FACT_STAR),
	card2("Uzay Ýstasyonu",4,2,0,0,FLAG_BASE | FLAG_PATROL,0,0,COND_ADDDAMAGE,2,COND_ADDMONEY,4,FACT_STAR),
	card2("Tersane Ýstastonu",4,0,1,0,FLAG_BASE | FLAG_PATROL,COND_DISCARD02,0,0,0,0,0,FACT_STAR),
	card2("Tersane Ýstastonu",4,0,1,0,FLAG_BASE | FLAG_PATROL,COND_DISCARD02,0,0,0,0,0,FACT_STAR),
	card2("Karargah",5,3,0,0,FLAG_BASE | FLAG_PATROL,0,0,COND_ADDDAMAGE,4,0,0,FACT_STAR),
	card2("Ýmparatorluk Sarayý",6,3,0,0,FLAG_BASE | FLAG_PATROL,0,0,COND_DISCARD1,0,0,0,FACT_STAR),
	card2("Taarruz Gemisi",5,0,0,0,0,COND_DRAW1,0,COND_DISCARD1,0,COND_DRAW1_AND_DESTROYBASE,0,FACT_STAR),
	card2("Mutlak Silah",7,7,0,0,0,COND_DRAW1,0,0,0,COND_ADDDAMAGE,5,FACT_STAR),
	card2("Donanma Komuta Merkezi",8,0,0,0,FLAG_BASE,COND_DAMAGEPERSHIP,0,0,0,0,0,FACT_STAR),
};
//FED KARTLARI
card2 feds[] = {
	card2("Federasyon Gemisi",1,0,2,0,0,0,0,COND_ADDHEALTH,4,0,0,FACT_FED),
	card2("Federasyon Gemisi",1,0,2,0,0,0,0,COND_ADDHEALTH,4,0,0,FACT_FED),
	card2("Federasyon Gemisi",1,0,2,0,0,0,0,COND_ADDHEALTH,4,0,0,FACT_FED),
	card2("Kurnaz",2,0,2,4,0,0,0,COND_ADDDAMAGE,4,0,0,FACT_FED),
	card2("Kurnaz",2,0,2,4,0,0,0,COND_ADDDAMAGE,4,0,0,FACT_FED),
	card2("Kurnaz",2,0,2,4,0,0,0,COND_ADDDAMAGE,4,0,0,FACT_FED),
	card2("Elçi",3,0,2,3,0,COND_DRAW2CARDSIF2BASES,0,0,0,0,0,FACT_FED),
	card2("Elçi",3,0,2,3,0,COND_DRAW2CARDSIF2BASES,0,0,0,0,0,FACT_FED),
	card2("Ticaret Merkezi",3,0,1,1,FLAG_BASE | FLAG_PATROL,COND_CHOICE,1,0,0,COND_ADDDAMAGE,3,FACT_FED),
	card2("Ticaret Merkezi",3,0,1,1,FLAG_BASE | FLAG_PATROL,COND_CHOICE,1,0,0,COND_ADDDAMAGE,3,FACT_FED),
	//card2("Yük Gemisi",4,0,4,0,0,0,0,COND_TOPDECK,0,0,0,FACT_FED),
	//card2("Yük Gemisi",4,0,4,0,0,0,0,COND_TOPDECK,0,0,0,FACT_FED),
	card2("Pazar Gezegeni",4,0,2,2,FLAG_BASE,COND_CHOICE,1,0,0,COND_ADDDAMAGE,5,FACT_FED),
	card2("Pazar Gezegeni",4,0,2,2,FLAG_BASE,COND_CHOICE,1,0,0,COND_ADDDAMAGE,5,FACT_FED),
	card2("Savunma Merkezi",5,2,0,3,FLAG_BASE | FLAG_PATROL,COND_CHOICE,3,COND_ADDDAMAGE,2,0,0,FACT_FED),
	card2("Koruma",5,4,0,4,0,0,0,COND_DRAW1,0,0,0,FACT_FED),
	card2("Sancak Gemisi",6,5,0,0,0,COND_DRAW1,0,COND_ADDHEALTH,5,0,0,FACT_FED),
	card2("Ticaret Limaný",6,0,3,0,FLAG_BASE | FLAG_PATROL,0,0,0,0,COND_DRAW1_AND_DESTROYBASE,0,FACT_FED),
	//card2("Merkez Ofis",7,0,2,0,FLAG_BASE,COND_TOPDECK,0,COND_DRAW1,0,0,0,FACT_FED,)
	card2("Komuta Gemisi",8,5,0,4,0,COND_DRAW2,0,COND_DESTROYBASE,0,0,0,FACT_FED)
};

std::vector<std::unique_ptr<card2>> createUniverseDeck() {

	std::vector<std::unique_ptr<card2>> deck;
	deck.reserve(100); 

	// Blob cards
	for (size_t i = 0; i < sizeof(blobs)/sizeof(card2); i++) {
		deck.push_back(std::make_unique<card2>(blobs[i]));
	}
	// Mech cards
	for (size_t i = 0; i < sizeof(mechs) / sizeof(card2); i++) {
		deck.push_back(std::make_unique<card2>(mechs[i]));
	}
	// Star cards
	for (size_t i = 0; i < sizeof(stars) / sizeof(card2); i++) {
		deck.push_back(std::make_unique<card2>(stars[i]));
	}
	// Fed cards
	for (size_t i = 0; i < sizeof(feds) / sizeof(card2); i++) {
		deck.push_back(std::make_unique<card2>(feds[i]));
	}
	
	return deck;
}

// BAÞLANGIÇ DESTESÝ OLUÞTURMA
std::vector<std::unique_ptr<card2>> createStarterDeck() {
	std::vector<std::unique_ptr<card2>> starterdeck;
	starterdeck.reserve(10);

	for(int i=0; i<8; i++){
		starterdeck.push_back(std::make_unique<card2>("Scout",0,0,1,0,0,0,0,0,0,0,0,0));
	}
	for(int i=0; i<2; i++) {
		starterdeck.push_back(std::make_unique<card2>("Viper",0,1,0,0,0,0,0,0,0,0,0,0));
	}
	return starterdeck;
}