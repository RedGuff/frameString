#include <iostream>

using namespace std;
/*
Specification: function that encloses a line of text with a string, such as "*".
Console.
*/

string repeatStringInt ( string pattern = "", int n = 0 ) // As the name says: string first, int after. // https://github.com/RedGuff/repeatStringInt
{
    if ( n < 0 ) {
        cerr << "Error: repeat(" << pattern << ", " << n << " < 0)" << endl;
        return "-1";
    } else if ( n == 0 ) {
        return "";
    } else {
        return pattern + repeatStringInt ( pattern, n - 1 );
    }
}

void frame1LineOfString(string text = "", string pattern = "#", int nbEmptyLinesBefore = 2, int nbEmptyLinesAfter = 2, int nbSpacesBefore = 2, int nbSpacesAfter = 2)
{
// Sometimes, the pattern is not the perfect size. If needed, we must add some spaces after and/or before the text.
    if ((nbSpacesBefore + text.size() + nbSpacesAfter)%pattern.size()!=0) {
        nbSpacesBefore = nbSpacesBefore + pattern.size() - ((nbSpacesBefore + text.size() + nbSpacesAfter)%pattern.size())/2; // Half because spaces before and after, if needed.
    }
    if ((nbSpacesBefore + text.size() + nbSpacesAfter)%pattern.size()!=0) {
        nbSpacesAfter = nbSpacesAfter + pattern.size() - (nbSpacesBefore + text.size() + nbSpacesAfter)%pattern.size(); // The rest. Not "/2" because nbSpacesBefore is corrected.
    }
    int nbPatternsWhenFullLine = (pattern.size() + nbSpacesBefore + text.size() + nbSpacesAfter + pattern.size())/(pattern.size()) ;
// First Line:
    cout << repeatStringInt( pattern, nbPatternsWhenFullLine) << endl;
// EmptyLinesBefore:
    for (int a=1; a<nbEmptyLinesBefore+1; a++) {
        cout << pattern << repeatStringInt(" ", nbSpacesBefore + text.size() + nbSpacesAfter) << pattern << endl;
    }
// Line :
    cout << pattern << repeatStringInt(" ", nbSpacesBefore) << text << repeatStringInt(" ", nbSpacesAfter) << pattern << endl;
// EmptyLinesAfter:
    for (int a=1; a<nbEmptyLinesAfter + 1; a++) {
        cout << pattern << repeatStringInt(" ", nbSpacesBefore + text.size() + nbSpacesAfter) << pattern << endl;
    }
// LastLine:
    cout << repeatStringInt( pattern, nbPatternsWhenFullLine) << endl;
}

int main()
{
    frame1LineOfString("Hello world!", "*");
    return 0;
}
