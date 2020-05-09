#include<iostream>

using namespace std;
struct IndexElement {
	char* word;
	int* pages;
	int pagesCount;
};
struct IndexNode {
	IndexElement* Element;
	IndexNode* Next;
	IndexNode(IndexElement* element, IndexNode* next) {
		Element = element;
		Next = next;
	}
};

struct Index {
private: IndexNode* Head;
	   IndexNode* Tail;
public:
	Index() {
		Head = NULL;
		Tail = NULL;
	}
	void Add(IndexElement* element) {
		IndexNode *node = new IndexNode(element, NULL);
		if (Head == NULL) {
			Head = node;
			Tail = node;
		}
		else {
			Tail->Next = node;
			Tail = node;
		}
	}
	IndexElement* FindByWord(char* word) {
		if (Head == NULL) {
			return NULL;
		}

		
		IndexNode* node = Head;
		
		do{
			if ( strcmp( node->Element->word, (word))==0) {
				return node->Element;
			}
		} while (node = node->Next, node != NULL);

		return NULL;
	}
	void Print() {
		IndexNode* node = Head;
		int i = 1;
		do {
			cout << i << ") " << node->Element->word << "\t";
			for (int i = 0; i < node->Element->pagesCount; i++) {
				cout << node->Element->pages[i] << " ";
			}
			cout << endl;
		} while (node = node->Next, i++, node != NULL);
	}
};


int Lab10() {
	Index* index= new Index();
	IndexElement* element1 = new IndexElement();
	element1->word = "Index";
	element1->pages = new int[4] { 1,12,32,33};	
	element1->pagesCount=4;
	IndexElement* element2 = new IndexElement();
	element2->word = "World";
	element2->pages = new int[5] { 2,7,15,22,41 };	
	element2->pagesCount = 5;
	IndexElement* element3 = new IndexElement();
	element3->word = "Programming";
	element3->pages = new int[5] { 1,2,8,11,17 };
	element3->pagesCount = 5;

	index->Add(element1);
	index->Add(element2);
	index->Add(element3);
	do {
		cout << "Choose action:" << endl;
		cout << "\t1) Show index" << endl;
		cout << "\t2) Find word" << endl;
		cout << "\t3) Exit" << endl;
		cout << ">>";
		int x;
		cin >> x;
		switch (x) {
		case 3:return 0;
		case 1: index->Print(); break;
		case 2: {
			char* word = new char[100];
			cout << "Choose word:" << endl << ">>";
			cin >> word;
			IndexElement* found = index->FindByWord(word);
			if (found == NULL) {
				cout << "Nothing found" << endl;
				break;
			}
			cout << "Pages: ";
			for (int i = 0; i < found->pagesCount; i++) {
				cout << found->pages[i] << " ";
			}
			cout << endl;
		}; break;
		default: cout << "Unknown command" << endl;
		}
	} while (true);
	return 0;
}