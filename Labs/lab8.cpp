#include <iostream>
#include <string>
using namespace std;

#define BUFFER_SIZE 10000
#define SENTENCE_SEP ".!?"
#define WORD_SEP " ,-:;"

void modifyText(char*);
bool checkChar(char, char*);
void modifySentence(char*, int);


int Lab8() {
	/*	Рижков ПЗ-19-1, варіант B20
	*	Скласти і налагодити програму, яка знаходить в кожному реченні тексту найкоротше і щонайдовше слово і міняє їх місцями в цьому реченні.
	*/
	cout << "Enter text( max " << BUFFER_SIZE << " characters):" << endl;
	char text[BUFFER_SIZE + 1];
	cin.get();
	cin.getline(text, BUFFER_SIZE);

	modifyText(text);
	cout << endl << text;
	return 0;
}

void modifyText(char* text)
{
	
	int i = -1;
	char c;
	bool inSentence = false;
	int start;
	while (c = text[++i], c > 0) {

		if (checkChar(c, SENTENCE_SEP)) {
			if (!inSentence) {
				continue;
			}

			int length = i - start -1;
			
			inSentence = false;

			modifySentence(&text[start], length);
		}
		else {
			if (!inSentence) {
				inSentence = true;
				start = i;
			}
		}

	}
	if (inSentence) {
		int length = i - start -1;
		modifySentence(&text[start], length);

	}

}
void modifySentence(char* sentence, int length) {
	int j = -1;
	char c;
	int maxLen = 0, minLen = length, maxI = 0, minI = 0, start;
	bool inWord = false;
	while (c = sentence[++j], j<length) {
		if (checkChar(c, WORD_SEP)) {
			if (!inWord) {
				continue;
			}

			int length = j - start;
			if (length < minLen) {
				minLen = length;
				minI = start;
			}
			if (length > maxLen) {
				maxLen = length;
				maxI = start;
			}
			inWord = false;

		}
		else {
			if (!inWord) {
				inWord = true;
				start = j;
			}
		}
	}

	if (inWord) {
		int length = j - start;
		if (length < minLen) {
			minLen = length;
			minI = start;
		}
		else if (length > maxLen) {
			maxLen = length;
			maxI = start;
		}
	}

	if (minI > maxI) {
		int bufLen = minI - maxI + minLen;
		char* buffer = new char[bufLen];
		int bI = 0;
		for (int j = minI; j < minI + minLen; j++) {
			buffer[bI++] = sentence[j];
		}
		for (int j = maxI + maxLen; j < minI; j++) {
			buffer[bI++] = sentence[j];
		}
		for (int j = maxI; j < maxI + maxLen; j++) {
			buffer[bI++] = sentence[j];
		}

		for (int j = maxI, bI = 0; j < minI + minLen; j++, bI++) {
			sentence[j] = buffer[bI];
		}

	}
	else {
		int bufLen = maxI - minI + maxLen;
		char* buffer = new char[bufLen];
		int bI = 0;
		for (int j = maxI; j < maxI + maxLen; j++) {
			buffer[bI++] = sentence[j];
		}

		for (int j = minI + minLen; j < maxI; j++) {
			buffer[bI++] = sentence[j];
		}
		for (int j = minI; j < minI + minLen; j++) {
			buffer[bI++] = sentence[j];
		}

		for (int j = minI, bI = 0; j < maxI + maxLen; j++, bI++) {
			sentence[j] = buffer[bI];
		}
	}


}


//check if char is one of soecified
bool checkChar(char c, char* array)
{
	int j = 0;
	char a;
	while (a = array[j++], a > 0) {
		if (c == a) {
			return true;
		}
		break;
	}
	return false;
}

