#ifndef NAMESPACE_WORD_H // replace with relevant names
#define NAMESPACE_WORD_H


	const int MAX_WORD_LEN = 21;
	const int MAX_NO_OF_WORDS = 500;

	namespace sdds {
	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};
	void programTitle();
	void title();
	void endList();
	int searchWords(const struct Word[], int, const char);
	void addWord(struct Word, int, const char);
	void totalWordsStat(int, int, int);
	void wordStats(bool);
}
#endif
