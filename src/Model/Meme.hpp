/*
 * Meme.hpp
 *
 *  Created on: Mar 13, 2017
 *      Author: gkun9931
 */

#ifndef MODEL_MEME_HPP_
#define MODEL_MEME_HPP_
#include <string>
class Meme
    {
private:
    std::string title;
    int dankness;
    double hipsterQuotient;
    bool mainstream;
public:
    Meme();
    Meme(std::string title);
    ~Meme();

    int getDankness();
    double getHipsterQuotient();
    bool isMainstream();
    std::string getTitle();
    void setTitle(std::string title);
    void setDankness(int dank);
    void setHipsterQuotienet(double hipsterQuotient);
    void setMainstream(bool mainstream);
    bool operator < (Meme & compare);
    bool operator > ( Meme & compare);
    bool operator == ( Meme & compare);
    };

#endif /* MODEL_MEME_HPP_ */
