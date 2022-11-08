class WordsFrequency {
private:
    map<string,int> wordMap;

public:
    WordsFrequency(vector<string>& book) {
        for (auto i: book) {
            if (wordMap.count(i) == 0) {
                wordMap[i] = 1;
            } else {
                wordMap[i]++;
            }
            
        }
    }
    
    int get(string word) {
        return wordMap[word];
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
