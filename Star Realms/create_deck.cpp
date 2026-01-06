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
// 13. FACTION
// 14. ÜS CANI
// 15 16 17. CONDITION AÇIKLAMALARI);

// BLOB KARTLARI
card2 blobs[] = {
	card2("Blob Savaþçýsý", 1, 3, 0, 0, 0, 0, 0, COND_DRAW1, 0, 0, 0, FACT_BLOB,0,"-","Bir kart çekin","-"),
	card2("Blob Savaþçýsý", 1, 3, 0, 0, 0, 0, 0, COND_DRAW1, 0, 0, 0, FACT_BLOB,0,"-","Bir kart çekin","-"),
	card2("Blob Savaþçýsý", 1, 3, 0, 0, 0, 0, 0, COND_DRAW1, 0, 0, 0, FACT_BLOB,0,"-","Bir kart çekin","-"),
	card2("Blob Yokedici", 4, 6, 0, 0, 0, 0, 0, COND_DESTROYBASEORJUNKMARKET, 0, 0, 0, FACT_BLOB,0,"-","Seçtiðiniz bir üssü yok edin ve/veya ticaret alanýndaki bir kartý hurdaya çýkartýn","-"),
	card2("Blob Yokedici", 4, 6, 0, 0, 0, 0, 0, COND_DESTROYBASEORJUNKMARKET, 0, 0, 0, FACT_BLOB,0,"-","Seçtiðiniz bir üssü yok edin ve/veya ticaret alanýndaki bir kartý hurdaya çýkartýn","-"),
	card2("Blok Çarký", 3,1,0,0,FLAG_BASE,0,0,0,0,COND_ADDMONEY,3,FACT_BLOB,5,"-","-","Hurdaya atýldýðýnda 3 coin kazandýrýr"),
	card2("Blok Çarký", 3,1,0,0,FLAG_BASE,0,0,0,0,COND_ADDMONEY,3,FACT_BLOB,5,"-","-","Hurdaya atýldýðýnda 3 coin kazandýrýr"),
	card2("Blok Çarký", 3,1,0,0,FLAG_BASE,0,0,0,0,COND_ADDMONEY,3,FACT_BLOB,5,"-","-","Hurdaya atýldýðýnda 3 coin kazandýrýr"),
	card2("Tüccar Balýk",2,0,3,0,0,0,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB,0,"-","2 Hasar kazandýrýr","-"),
	card2("Tüccar Balýk",2,0,3,0,0,0,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB,0,"-","2 Hasar kazandýrýr","-"),
	card2("Tüccar Balýk",2,0,3,0,0,0,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB,0,"-","2 Hasar kazandýrýr","-"),
	card2("Solucan",3,5,0,0,0,0,0,COND_ADDDAMAGE,2,COND_ADDMONEY,3,FACT_BLOB,0,"-","2 Hasar kazandýrýr","Hurdaya atýldýðýnda 3 coin kazandýrýr"),
	card2("Solucan",3,5,0,0,0,0,0,COND_ADDDAMAGE,2,COND_ADDMONEY,3,FACT_BLOB,0,"-","2 Hasar kazandýrýr","Hurdaya atýldýðýnda 3 coin kazandýrýr"),
	card2("Larva",2,4,0,0,0,COND_JUNKMARKET,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB,0,"Ticaret alanýndaki bir kartý hurdaya çýkarabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Larva",2,4,0,0,0,COND_JUNKMARKET,0,COND_ADDDAMAGE,2,0,0,FACT_BLOB,0,"Ticaret alanýndaki bir kartý hurdaya çýkarabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Ana Gemi",7,6,0,0,0,COND_DRAW1,0,COND_DRAW1,0,0,0,FACT_BLOB,0,"Bir kart çekin","Bir kart çekin","-"),
	card2("Savaþ Kuþu",6,8,0,0,0,0,0,COND_DRAW1,0,COND_ADDDAMAGE,4,FACT_BLOB,0,"-","Bir kart çekin","Hurdaya atýldýðýnda 4 hasar kazandýrýr"),
	card2("Sürü",5,3,0,0,FLAG_BASE,0,0,COND_DRAW1,0,0,0,FACT_BLOB,5,"-","Bir kart çekin","-"),
	card2("Blob Gezegeni",8,0,0,0,FLAG_BASE,COND_DRAWPERBLOB,0,0,0,0,0,FACT_BLOB,7,"5 Hasar veya bu tur oynadýðýnýz her blob kartý için 1 kart çekin","-","-"),
	card2("Blob Taþýyýcý",6,7,0,0,0,0,0,COND_FREECARD_AND_TOPDECK,0,0,0,FACT_BLOB,0,"-","Ýstediðiniz bir gemiyi bedavaya alýn ve destenizin en üstüne koyun","-"),
};
// MECH KARTLARI
card2 mechs[] = {
	card2("Ticaret Dronu",1,0,1,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Ticaret Dronu",1,0,1,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Ticaret Dronu",1,0,1,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Füze Dronu",2,2,0,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Füze Dronu",2,2,0,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Füze Dronu",2,2,0,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Ýkmal Dronu",3,0,2,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Ýkmal Dronu",3,0,2,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Ýkmal Dronu",3,0,2,0,0,COND_JUNKOWN1,0,COND_ADDDAMAGE,2,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","2 Hasar kazandýrýr","-"),
	card2("Muharebe Ýstasyonu",3,0,0,0,FLAG_BASE | FLAG_PATROL,0,0,0,0,COND_ADDDAMAGE,5,FACT_MECH,5,"-","-","Hurdaya atýldýðýnda 5 hasar kazandýrýr"),
	card2("Muharebe Ýstasyonu",3,0,0,0,FLAG_PATROL | FLAG_BASE,0,0,0,0,COND_ADDDAMAGE,5,FACT_MECH,5,"-","-","Hurdaya atýldýðýnda 5 hasar kazandýrýr"),
	//card2("Kamuflaj Ajaný",4),
	card2("Devriye",4,5,3,0,0,COND_CHOICE,2,COND_JUNKOWN1,0,0,0,FACT_MECH,0,"3 Coin veya 5 Hasar arasýndan seçim yapýn","Elinizden veya ýskartanýzdan bir kartý hurdaya çýkarýn","-"),
	card2("Devriye",4,5,3,0,0,COND_CHOICE,2,COND_JUNKOWN1,0,0,0,FACT_MECH,0,"3 Coin veya 5 Hasar arasýndan seçim yapýn","Elinizden veya ýskartanýzdan bir kartý hurdaya çýkarýn","-"),
	card2("Savaþ Makinesi",5,4,0,0,0,COND_JUNKOWN1,0,COND_DRAW1,0,0,0,FACT_MECH,0,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkartabilirsiniz","Bir kart çekin","-"),
	card2("Dron Dünya",5,0,0,0,FLAG_BASE | FLAG_PATROL | FLAG_GLOBAL,0,0,0,0,0,0,FACT_MECH,6,"Dron Dünya tüm factionlara müttefik sayýlýr","-","-"),
	card2("Misilleme Tanký",6,6,0,0,0,COND_DESTROYBASE,0,COND_DRAW1,0,0,0,FACT_MECH,0,"Seçtiðiniz bir üssü yok edebilirsiniz","Bir kart çekin","-"),
	card2("Geri Dönüþüm Merkezi",6,0,0,0,FLAG_BASE | FLAG_PATROL,COND_JUNKOWN1,0,0,0,0,0,FACT_MECH,5,"Elinizden veya ýskartanýzdan bir kartý hurdaya çýkarýn","-","-"),
	card2("Seyyar Sanayi",7,0,0,0,FLAG_BASE | FLAG_PATROL,COND_DRAWANDJUNK,0,0,0,0,0,FACT_MECH,6,"Bir kart çekin ardýndan elinizden bir kartý hurdaya çýkarýn","-","-"),
	card2("Ana Beyin",8,0,0,0,FLAG_BASE | FLAG_PATROL,COND_JUNK02,0,0,0,0,0,FACT_MECH,6,"Elinizden veya ýskartanýzdan 1-2 kartý hurdaya çýkarýn. Hurdaya çýkardýðýnýz kart sayýsý kadar kart çekin","-","-"),



};
// STAR KARTLARI
card2 stars[] = {
	card2("Çevik Saldýrgan",1,2,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR,0,"Seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr","-","-"),
	card2("Çevik Saldýrgan",1,2,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR,0,"Seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr","-","-"),
	card2("Çevik Saldýrgan",1,2,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR,0,"Seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr","-","-"),
	card2("Piyade Gemisi",2,1,0,0,0,COND_DRAW1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR,0,"Bir kart çekin","2 Hasar kazandýrýr","-"),
	card2("Piyade Gemisi",2,1,0,0,0,COND_DRAW1,0,COND_ADDDAMAGE,2,0,0,FACT_STAR,0,"Bir kart çekin","2 Hasar kazandýrýr","-"),
	card2("Öncü Kuvvet",3,0,1,0,0,COND_DRAW1,0,0,0,COND_DISCARD1,0,FACT_STAR,0,"Bir kart çekin","-","Hurdaya atýldýðýnda seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr"),
	card2("Öncü Kuvvet",3,0,1,0,0,COND_DRAW1,0,0,0,COND_DISCARD1,0,FACT_STAR,0,"Bir kart çekin","-","Hurdaya atýldýðýnda seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr"),
	card2("Öncü Kuvvet",3,0,1,0,0,COND_DRAW1,0,0,0,COND_DISCARD1,0,FACT_STAR,0,"Bir kart çekin","-","Hurdaya atýldýðýnda seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr"),
	card2("Hücum Gemisi",3,4,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,COND_DRAW1,0,FACT_STAR,0,"Seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr","2 Hasar kazandýrýr","Hurdaya atýldýðýnda bir kart çekin"),
	card2("Hücum Gemisi",3,4,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,COND_DRAW1,0,FACT_STAR,0,"Seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr","2 Hasar kazandýrýr","Hurdaya atýldýðýnda bir kart çekin"),
	card2("Hücum Gemisi",3,4,0,0,0,COND_DISCARD1,0,COND_ADDDAMAGE,2,COND_DRAW1,0,FACT_STAR,0,"Seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr","2 Hasar kazandýrýr","Hurdaya atýldýðýnda bir kart çekin"),
	card2("Uzay Ýstasyonu",4,2,0,0,FLAG_BASE | FLAG_PATROL,0,0,COND_ADDDAMAGE,2,COND_ADDMONEY,4,FACT_STAR,4,"-","2 Hasar kazandýrýr","Hurdaya atýldýðýnda 4 coin kazandýrýr"),
	card2("Uzay Ýstasyonu",4,2,0,0,FLAG_BASE | FLAG_PATROL,0,0,COND_ADDDAMAGE,2,COND_ADDMONEY,4,FACT_STAR,4,"-","2 Hasar kazandýrýr","Hurdaya atýldýðýnda 4 coin kazandýrýr"),
	card2("Tersane Ýstastonu",4,0,1,0,FLAG_BASE | FLAG_PATROL,COND_DISCARD02,0,0,0,0,0,FACT_STAR,4,"1 Coin kazanýn veya 0-2 kart ýskartaya çýkarýn ve ayný sayýda kart çekin","-","-"),
	card2("Tersane Ýstastonu",4,0,1,0,FLAG_BASE | FLAG_PATROL,COND_DISCARD02,0,0,0,0,0,FACT_STAR,4,"1 Coin kazanýn veya 0-2 kart ýskartaya çýkarýn ve ayný sayýda kart çekin","-","-"),
	card2("Karargah",5,3,0,0,FLAG_BASE | FLAG_PATROL,0,0,COND_ADDDAMAGE,4,0,0,FACT_STAR,4,"-","4 Hasar kazandýrýr","-"),
	card2("Ýmparatorluk Sarayý",6,3,0,0,FLAG_BASE | FLAG_PATROL,0,0,COND_DISCARD1,0,0,0,FACT_STAR,6,"-","Seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr","-"),
	card2("Taarruz Gemisi",5,0,0,0,0,COND_DRAW1,0,COND_DISCARD1,0,COND_DRAW1_AND_DESTROYBASE,0,FACT_STAR,0,"Bir kart çekin","Seçtiðiniz bir rakip istediði bir kartýný ýskartaya çýkarýr","Hurdaya atýldýðýnda 1 kart çekin, Seçtiðiniz bir üssü yok edebilirsiniz"),
	card2("Mutlak Silah",7,7,0,0,0,COND_DRAW1,0,0,0,COND_ADDDAMAGE,5,FACT_STAR,0,"Bir kart çekin","-","Hurdaya atýldýðýnda 5 Hasar kazandýrýr"),
	card2("Donanma Komuta Merkezi",8,0,0,0,FLAG_BASE,COND_DAMAGEPERSHIP,0,0,0,0,0,FACT_STAR,8,"Oynadýðýnýz her gemi için 1 Hasar kazanýn","-","-"),
};
//FED KARTLARI
card2 feds[] = {
	card2("Federasyon Gemisi",1,0,2,0,0,0,0,COND_ADDHEALTH,4,0,0,FACT_FED,0,"-","2 Heal kazandýrýr","-"),
	card2("Federasyon Gemisi",1,0,2,0,0,0,0,COND_ADDHEALTH,4,0,0,FACT_FED,0,"-","2 Heal kazandýrýr","-"),
	card2("Federasyon Gemisi",1,0,2,0,0,0,0,COND_ADDHEALTH,4,0,0,FACT_FED,0,"-","2 Heal kazandýrýr","-"),
	card2("Kurnaz",2,0,2,4,0,0,0,COND_ADDDAMAGE,4,0,0,FACT_FED,0,"-","4 Damage kazandýrýr","-"),
	card2("Kurnaz",2,0,2,4,0,0,0,COND_ADDDAMAGE,4,0,0,FACT_FED,0,"-","4 Damage kazandýrýr","-"),
	card2("Kurnaz",2,0,2,4,0,0,0,COND_ADDDAMAGE,4,0,0,FACT_FED,0,"-","4 Damage kazandýrýr","-"),
	card2("Elçi",3,0,2,3,0,COND_DRAW2CARDSIF2BASES,0,0,0,0,0,FACT_FED,0,"Oyunda 2 veya daha fazla üssünüz varsa 2 Kart çekin","-","-"),
	card2("Elçi",3,0,2,3,0,COND_DRAW2CARDSIF2BASES,0,0,0,0,0,FACT_FED,0,"Oyunda 2 veya daha fazla üssünüz varsa 2 Kart çekin","-","-"),
	card2("Ticaret Merkezi",3,0,1,1,FLAG_BASE | FLAG_PATROL,COND_CHOICE,1,0,0,COND_ADDDAMAGE,3,FACT_FED,4,"1 Heal veya 1 Coin","-","Hurdaya atýldýðýnda 3 Hasar kazandýrýr"),
	card2("Ticaret Merkezi",3,0,1,1,FLAG_BASE | FLAG_PATROL,COND_CHOICE,1,0,0,COND_ADDDAMAGE,3,FACT_FED,4,"1 Heal veya 1 Coin","-","Hurdaya atýldýðýnda 3 Hasar kazandýrýr"),
	card2("Yük Gemisi",4,0,4,0,0,0,0,COND_TOPDECK,0,0,0,FACT_FED,0,"-","Bu tur alacaðýnýz ilk gemi kartýný destenin en üstüne koyun","-"),
	card2("Yük Gemisi",4,0,4,0,0,0,0,COND_TOPDECK,0,0,0,FACT_FED,0,"-","Bu tur alacaðýnýz ilk gemi kartýný destenin en üstüne koyun","-"),
	card2("Pazar Gezegeni",4,0,2,2,FLAG_BASE,COND_CHOICE,1,0,0,COND_ADDDAMAGE,5,FACT_FED,4,"2 Heal veya 2 Coin","-","Hurdaya atýldýðýnda 5 Hasar kazandýrýr"),
	card2("Pazar Gezegeni",4,0,2,2,FLAG_BASE,COND_CHOICE,1,0,0,COND_ADDDAMAGE,5,FACT_FED,4,"2 Heal veya 2 Coin","-","Hurdaya atýldýðýnda 5 Hasar kazandýrýr"),
	card2("Savunma Merkezi",5,2,0,3,FLAG_BASE | FLAG_PATROL,COND_CHOICE,3,COND_ADDDAMAGE,2,0,0,FACT_FED,5,"3 Heal veya 2 Hasar","2 Hasar kazandýrýr","-"),
	card2("Koruma",5,4,0,4,0,0,0,COND_DRAW1,0,0,0,FACT_FED,0,"-","2 Bir kart çekin","-"),
	card2("Sancak Gemisi",6,5,0,0,0,COND_DRAW1,0,COND_ADDHEALTH,5,0,0,FACT_FED,0,"Bir kart çekin","5 Heal kazandýrýr","-"),
	card2("Ticaret Limaný",6,0,3,0,FLAG_BASE | FLAG_PATROL,0,0,0,0,COND_DRAW1_AND_DESTROYBASE,0,FACT_FED,6,"-","-","Hurdaya atýldýðýnda 1 kart çekin, Seçtiðiniz bir üssü yok edebilirsiniz"),
	card2("Merkez Ofis",7,0,2,0,FLAG_BASE,COND_TOPDECK,0,COND_DRAW1,0,0,0,FACT_FED,6,"Bu tur alacaðýnýz ilk gemi kartýný destenin en üstüne koyun","Bir kart çekin","-"),
	card2("Komuta Gemisi",8,5,0,4,0,COND_DRAW2,0,COND_DESTROYBASE,0,0,0,FACT_FED,0,"Ýki kart çekin","Seçtiðiniz bir üssü yok edin","-"),
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