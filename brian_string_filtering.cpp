#include <string>
#include <iostream>
#include <Stack>

using namespace std;

const short ALP = 26;
const char SMALL = 'a';

const string INVALID = "invalid";

string solution(string sentence)
{
    string answer = "";
    bool usedAlphabet[ALP];

    for (short i = 0; i < ALP; i++)
    {
        usedAlphabet[i] = false;
    }

    string word = "";

    char bfDefilter = 0;
    char bwDefilter = 0;

    char c;

    for (int i = 0; i < sentence.length(); i++)
    {
        c = sentence[i];

        if (isCapital(c))
        {
            // word
            if (answer.length() > 0 || word.length == 0)
            {
                answer.push_back(' ');
            }
            
            word.push_back(c);
        }
        else
        {
            // defilter
            if (word.length() == 0)
            {
                bfDefilter = c;
            }
            else
            {
                if (word.length() > 1 && bwDefilter == 0)
                {
                    answer.append(word);
                    answer.pop_back();
                    answer.push_back(' ');
                    word = word[word.length() - 1];
                }
                
                if (c == bfDefilter)
                {
                    // word end
                    bfDefilter = 0;
                    bwDefilter = 0;

                    answer.append(word);
                    word = "";
                }
                else
                {
                    if (bwDefilter == 0)
                    {
                        bwDefilter = c;
                    }
                    else if(bwDefilter == c) 
                    {
                        
                    }
                    else
                    {
                        // invalid
                        return INVALID;
                    }
                }
            }
        }
    }

    return answer;
}

bool isCapital(char c)
{
    return (c - SMALL) < 0;
}

short charToIdx(char c)
{
    return c - SMALL;
}