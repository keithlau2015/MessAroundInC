#ifndef Decode_H
	#define Decode_H
	
	void Decoder(char option);
	
	//UI
	void DecodeUI();
	
	char MorseCode2English(char[4]);
	void English2MorseCode(char);
	void InputFile(char file_name[50], int boolean);
#endif