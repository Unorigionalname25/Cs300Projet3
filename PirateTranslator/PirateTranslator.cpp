#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


class PirateTranslator{
       
public:
//Class constructor that gets and adds words from the .csv file 
    PirateTranslator(){
        addwords();
    }
    std::vector<std::pair<std::string, std::string>> items;

//primary function for the translation 
//inputs:: the string you want to translate
//outputs:: translated string
    std::string translate(const std::string& str) {
        std::istringstream iss(str);
        std::string retString = "";
        //Used to skip the translation of "excuse" so the code can properly translate "excuse me"
        bool skipTranslation = false;

        std::string word;
            while (iss >> word) {
            std::string punctuation = "";
            while (ispunct(word.back())) {
                punctuation = word.back() + punctuation;
                word.pop_back();
            }
//when translating "excuse me" this is the loop that correctly translates it
            if (!skipTranslation) {
                std::string translation = findTranslation(word);
            

                if (word == "excuse" && iss >> word && (word == "me" || (word == "me" && ispunct(word.back())))) {
                    translation="";
                    retString += "arrrrr" + punctuation;                

                }
                retString += translation + punctuation +" ";    
            } else {
                skipTranslation = false; // Reset the flag
            }
        }
        return retString;
    }

    private:
    //compares the current word with the words in the .csv file and converts them if it finds a match
    std::string findTranslation(const std::string& word) {
        for (const auto& pair : items) {
            if (pair.first == word) {
                return pair.second;
            }
        }
        return word;
    }
    //reads the words from the .csv file and writes them into an arraylist of pairs 
    void addwords(){

        std::ifstream inputFile("Words.csv");
        if (!inputFile.is_open()){
            std::cout<<"file failed to open."<<std::endl;
            return;
        }
        std::string line;
        while(std::getline(inputFile, line)){
            std::stringstream linestream(line);
            std::string item1;
            std::string item2;
        if (std::getline(linestream, item1,',')&&std::getline(linestream,item2)){
                items.push_back(std::make_pair(item1,item2));
            }else {
                std::cout<<"Error adding pair at line"<<line<<std::endl;

            }

        }
        inputFile.close();
    }



};

int main(){
PirateTranslator test1;
std::cout<<test1.translate("Hello, madame, would you direct me to the nearest hotel?")<<std::endl;
std::cout<<test1.translate("Sir, what is the name of your best restaurant?")<<std::endl;
std::cout<<test1.translate("Excuse me, officer, my friend is lost. He is a fellow pirate looking for coins to pay the restaurant.")<<std::endl;


return 0;






}
